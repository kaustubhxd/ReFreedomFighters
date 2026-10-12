// PRM (mesh) parser for Freedom Fighters. Pure module: no DOM, no WebGL.
// Layout and evidence: formats/skinning-format.md; reference decoder: decoders/skin.py.

// The extra rest-pose check below only runs for the first level's scene label.
const C01A_SCENE_LABEL = "Singleplayer/C01A/FF-C01A_MAIN";
let currentSceneLabel = null;
function setSceneLabel(label) { currentSceneLabel = label; }

const PRM_POINTER_MASK = 0x01ffffff;
const PRM_ENTRY_BYTES = 0x7c;
const PRM_STANDARD_VERTEX_BYTES = 36;
const PRM_EXTENDED_VERTEX_BYTES = 52;
const PRM_EXTENDED_VERTEX_FLAGS = 0x00010100;
const PRM_EXTENDED_WEIGHT_OFFSET = 12;
const PRM_EXTENDED_SELECTOR_OFFSET = 24;
const PRM_EXTENDED_SELECTOR_DIVISOR = 3;
const PRM_EXTENDED_SKIN_HEADER_BYTES = 0x98;
const PRM_EXTENDED_BONE_COUNT_OFFSET = 0x7c;
const PRM_EXTENDED_LOCAL_REST_MATRICES_OFFSET = 0x80;
const PRM_EXTENDED_LOCAL_RIGID_TRANSFORMS_OFFSET = 0x84;
const PRM_EXTENDED_GLOBAL_REST_MATRICES_OFFSET = 0x88;
const PRM_EXTENDED_UNRESOLVED_BASIS_OFFSET = 0x8c;
const PRM_EXTENDED_BONE_DESCRIPTORS_OFFSET = 0x90;
const PRM_EXTENDED_GLOBAL_TO_LOCAL_MAP_OFFSET = 0x94;
const PRM_EXTENDED_GLOBAL_JOINT_MAP_BYTES = 96;
const PRM_UNMAPPED_JOINT = 0xff;
const PRM_EXTENDED_RIGID_TRANSFORM_FLOATS = 7;
const PRM_EXTENDED_MATRIX_FLOATS = 12;
const PRM_EXTENDED_UNRESOLVED_BASIS_FLOATS = 9;
const PRM_EXTENDED_BONE_DESCRIPTOR_BYTES = 48;
// These C01A residual limits are deliberately much looser than the observed
// float32 round-off (at most about 1.3e-5 in the global translation), while
// still rejecting a swapped convention or unrelated data block outright.
const PRM_C01A_REST_MATRIX_RESIDUAL_LIMIT = 1e-3;
const PRM_C01A_REST_AXIS_SWAP = [
  0, 0, 1,
  0, 1, 0,
  1, 0, 0,
];
// Valid campaign geometry spans tens of thousands of world units.  A much
// larger coordinate is a non-mesh table record being interpreted as a PRM
// vertex block, and would make the complete scene's bounds unusable.
const PRM_MAX_COORDINATE = 1_000_000;
function assertRange(view, offset, length, label) {
  if (!Number.isInteger(offset) || !Number.isInteger(length) || offset < 0 || length < 0 || offset + length > view.byteLength) {
    throw new Error(`${label} falls outside the PRM file.`);
  }
}

function prmVertexLayout(entryFlags) {
  // Some C01A skinned-character resources use a shipped extended vertex
  // record. The original BonesSW construction path proves that its three
  // floats are weights and each raw selector byte maps to a local palette row
  // by dividing it by three. The extended entry's 96-byte global-ANM-ID to
  // local-row map resolves that row back to an ANM joint ID. The actor's
  // matrix palette / pose is still unknown, so this renderer retains the
  // inputs but does not skin.
  // Position, normal, diffuse colour, and UV locations are verified against
  // all 38 referenced extended parts.
  // Keep this an explicit flag switch so unknown formats cannot silently be
  // treated as ordinary 36-byte vertices.
  if (entryFlags === PRM_EXTENDED_VERTEX_FLAGS) {
    return {
      stride: PRM_EXTENDED_VERTEX_BYTES,
      weightOffset: PRM_EXTENDED_WEIGHT_OFFSET,
      selectorOffset: PRM_EXTENDED_SELECTOR_OFFSET,
      normalOffset: 28,
      diffuseOffset: 40,
      uvOffset: 44,
      label: "extended 52-byte",
    };
  }
  return {
    stride: PRM_STANDARD_VERTEX_BYTES,
    normalOffset: 12,
    diffuseOffset: 24,
    uvOffset: 28,
    label: "standard 36-byte",
  };
}

function multiplyRowMatrices3(left, right) {
  return [
    left[0] * right[0] + left[1] * right[3] + left[2] * right[6],
    left[0] * right[1] + left[1] * right[4] + left[2] * right[7],
    left[0] * right[2] + left[1] * right[5] + left[2] * right[8],
    left[3] * right[0] + left[4] * right[3] + left[5] * right[6],
    left[3] * right[1] + left[4] * right[4] + left[5] * right[7],
    left[3] * right[2] + left[4] * right[5] + left[5] * right[8],
    left[6] * right[0] + left[7] * right[3] + left[8] * right[6],
    left[6] * right[1] + left[7] * right[4] + left[8] * right[7],
    left[6] * right[2] + left[7] * right[5] + left[8] * right[8],
  ];
}

function transformRowVector3(vector, matrix) {
  return [
    vector[0] * matrix[0] + vector[1] * matrix[3] + vector[2] * matrix[6],
    vector[0] * matrix[1] + vector[1] * matrix[4] + vector[2] * matrix[7],
    vector[0] * matrix[2] + vector[1] * matrix[5] + vector[2] * matrix[8],
  ];
}

function rowQuaternionMatrix(quaternion) {
  const [x, y, z, w] = quaternion;
  // The serialized local quaternion is xyzw. Its rest matrices use the
  // transpose of the usual column-vector quaternion convention, because
  // this hierarchy composes row vectors from child to parent.
  return [
    1 - 2 * (y * y + z * z), 2 * (x * y + z * w), 2 * (x * z - y * w),
    2 * (x * y - z * w), 1 - 2 * (x * x + z * z), 2 * (y * z + x * w),
    2 * (x * z + y * w), 2 * (y * z - x * w), 1 - 2 * (x * x + y * y),
  ];
}

function maxRestMatrixResidual(stored, offset, rotation, translation) {
  let maximum = 0;
  for (let component = 0; component < 9; component += 1) {
    maximum = Math.max(maximum, Math.abs(stored[offset + component] - rotation[component]));
  }
  for (let component = 0; component < 3; component += 1) {
    maximum = Math.max(maximum, Math.abs(stored[offset + 9 + component] - translation[component]));
  }
  return maximum;
}

function verifyC01ARestSkeleton(bones, localRestMatrices, globalRestMatrices) {
  const resolved = new Array(bones.length);
  const resolving = new Uint8Array(bones.length);
  function resolve(localRow) {
    if (resolved[localRow]) return resolved[localRow];
    if (resolving[localRow]) throw new Error("C01A rest skeleton contains a parent cycle.");
    resolving[localRow] = 1;
    const bone = bones[localRow];
    const localRotation = rowQuaternionMatrix(bone.quaternion);
    let globalRotation = localRotation;
    let globalTranslation = bone.translation;
    if (bone.parentLocalRow !== -1) {
      const parent = resolve(bone.parentLocalRow);
      globalRotation = multiplyRowMatrices3(localRotation, parent.rotation);
      const rotatedTranslation = transformRowVector3(bone.translation, parent.rotation);
      globalTranslation = rotatedTranslation.map((value, axis) => value + parent.translation[axis]);
    }
    resolving[localRow] = 0;
    const result = { rotation: globalRotation, translation: globalTranslation };
    resolved[localRow] = result;
    return result;
  }

  let localMaximumResidual = 0;
  let globalMaximumResidual = 0;
  for (const bone of bones) {
    const localRotation = rowQuaternionMatrix(bone.quaternion);
    const global = resolve(bone.localRow);
    const localSerializedRotation = multiplyRowMatrices3(PRM_C01A_REST_AXIS_SWAP, localRotation);
    const globalSerializedRotation = multiplyRowMatrices3(PRM_C01A_REST_AXIS_SWAP, global.rotation);
    localMaximumResidual = Math.max(
      localMaximumResidual,
      maxRestMatrixResidual(
        localRestMatrices,
        bone.localRow * PRM_EXTENDED_MATRIX_FLOATS,
        localSerializedRotation,
        bone.translation,
      ),
    );
    globalMaximumResidual = Math.max(
      globalMaximumResidual,
      maxRestMatrixResidual(
        globalRestMatrices,
        bone.localRow * PRM_EXTENDED_MATRIX_FLOATS,
        globalSerializedRotation,
        global.translation,
      ),
    );
  }
  if (localMaximumResidual > PRM_C01A_REST_MATRIX_RESIDUAL_LIMIT
    || globalMaximumResidual > PRM_C01A_REST_MATRIX_RESIDUAL_LIMIT) {
    throw new Error("C01A rest skeleton does not match its verified row-vector transform convention.");
  }
  return { localMaximumResidual, globalMaximumResidual };
}

function readExtendedPrmJointMap(view, entryOffset) {
  assertRange(view, entryOffset, PRM_EXTENDED_SKIN_HEADER_BYTES, "extended PRM skin header");
  const boneCount = view.getUint32(entryOffset + PRM_EXTENDED_BONE_COUNT_OFFSET, true);
  if (!boneCount || boneCount > PRM_EXTENDED_GLOBAL_JOINT_MAP_BYTES) {
    throw new Error("Extended PRM bone count is outside the verified joint-map range.");
  }
  const globalToLocalPaletteOffset = view.getUint32(entryOffset + PRM_EXTENDED_GLOBAL_TO_LOCAL_MAP_OFFSET, true);
  assertRange(view, globalToLocalPaletteOffset, PRM_EXTENDED_GLOBAL_JOINT_MAP_BYTES, "extended PRM global joint map");
  const globalToLocalPaletteRows = new Uint8Array(
    view.buffer,
    view.byteOffset + globalToLocalPaletteOffset,
    PRM_EXTENDED_GLOBAL_JOINT_MAP_BYTES,
  );
  const localPaletteToGlobalJointIds = new Uint8Array(boneCount).fill(PRM_UNMAPPED_JOINT);
  let mappedRows = 0;
  for (let globalJointId = 0; globalJointId < globalToLocalPaletteRows.length; globalJointId += 1) {
    const localRow = globalToLocalPaletteRows[globalJointId];
    if (localRow === PRM_UNMAPPED_JOINT) continue;
    if (localRow >= boneCount || localPaletteToGlobalJointIds[localRow] !== PRM_UNMAPPED_JOINT) {
      throw new Error("Extended PRM global joint map is not a one-to-one local palette map.");
    }
    localPaletteToGlobalJointIds[localRow] = globalJointId;
    mappedRows += 1;
  }
  if (mappedRows !== boneCount || localPaletteToGlobalJointIds.some((jointId) => jointId === PRM_UNMAPPED_JOINT)) {
    throw new Error("Extended PRM global joint map does not cover its declared local palette.");
  }
  const localRigidTransformsOffset = view.getUint32(entryOffset + PRM_EXTENDED_LOCAL_RIGID_TRANSFORMS_OFFSET, true);
  const localRestMatricesOffset = view.getUint32(entryOffset + PRM_EXTENDED_LOCAL_REST_MATRICES_OFFSET, true);
  const globalRestMatricesOffset = view.getUint32(entryOffset + PRM_EXTENDED_GLOBAL_REST_MATRICES_OFFSET, true);
  const unresolvedBasisOffset = view.getUint32(entryOffset + PRM_EXTENDED_UNRESOLVED_BASIS_OFFSET, true);
  const boneDescriptorsOffset = view.getUint32(entryOffset + PRM_EXTENDED_BONE_DESCRIPTORS_OFFSET, true);
  assertRange(view, localRigidTransformsOffset, boneCount * PRM_EXTENDED_RIGID_TRANSFORM_FLOATS * 4, "extended PRM local rigid transforms");
  assertRange(view, localRestMatricesOffset, boneCount * PRM_EXTENDED_MATRIX_FLOATS * 4, "extended PRM local rest matrices");
  assertRange(view, globalRestMatricesOffset, boneCount * PRM_EXTENDED_MATRIX_FLOATS * 4, "extended PRM global rest matrices");
  assertRange(view, unresolvedBasisOffset, boneCount * PRM_EXTENDED_UNRESOLVED_BASIS_FLOATS * 4, "extended PRM unresolved basis");
  assertRange(view, boneDescriptorsOffset, boneCount * PRM_EXTENDED_BONE_DESCRIPTOR_BYTES, "extended PRM bone descriptors");
  const localRigidTransforms = new Float32Array(boneCount * PRM_EXTENDED_RIGID_TRANSFORM_FLOATS);
  const localRestMatrices = new Float32Array(boneCount * PRM_EXTENDED_MATRIX_FLOATS);
  const globalRestMatrices = new Float32Array(boneCount * PRM_EXTENDED_MATRIX_FLOATS);
  const bones = [];
  for (let localRow = 0; localRow < boneCount; localRow += 1) {
    const transformOffset = localRigidTransformsOffset + localRow * PRM_EXTENDED_RIGID_TRANSFORM_FLOATS * 4;
    const quaternion = [
      view.getFloat32(transformOffset, true),
      view.getFloat32(transformOffset + 4, true),
      view.getFloat32(transformOffset + 8, true),
      view.getFloat32(transformOffset + 12, true),
    ];
    const translation = [
      view.getFloat32(transformOffset + 16, true),
      view.getFloat32(transformOffset + 20, true),
      view.getFloat32(transformOffset + 24, true),
    ];
    if (![...quaternion, ...translation].every(Number.isFinite) || Math.hypot(...quaternion) < 1e-5) {
      throw new Error("Extended PRM local rest transform is invalid.");
    }
    localRigidTransforms.set([...quaternion, ...translation], localRow * PRM_EXTENDED_RIGID_TRANSFORM_FLOATS);
    const localMatrixOffset = localRestMatricesOffset + localRow * PRM_EXTENDED_MATRIX_FLOATS * 4;
    const globalMatrixOffset = globalRestMatricesOffset + localRow * PRM_EXTENDED_MATRIX_FLOATS * 4;
    for (let component = 0; component < PRM_EXTENDED_MATRIX_FLOATS; component += 1) {
      const localValue = view.getFloat32(localMatrixOffset + component * 4, true);
      const globalValue = view.getFloat32(globalMatrixOffset + component * 4, true);
      if (!Number.isFinite(localValue) || !Number.isFinite(globalValue)) {
        throw new Error("Extended PRM rest matrix is non-finite.");
      }
      localRestMatrices[localRow * PRM_EXTENDED_MATRIX_FLOATS + component] = localValue;
      globalRestMatrices[localRow * PRM_EXTENDED_MATRIX_FLOATS + component] = globalValue;
    }
    const descriptorOffset = boneDescriptorsOffset + localRow * PRM_EXTENDED_BONE_DESCRIPTOR_BYTES;
    const parentLocalRow = view.getInt32(descriptorOffset + 12, true);
    if (parentLocalRow < -1 || parentLocalRow >= boneCount) {
      throw new Error("Extended PRM bone parent is outside its declared local skeleton.");
    }
    const nameBytes = new Uint8Array(view.buffer, view.byteOffset + descriptorOffset + 28, 16);
    const nameEnd = nameBytes.indexOf(0);
    const name = new TextDecoder("latin1").decode(nameBytes.subarray(0, nameEnd === -1 ? nameBytes.length : nameEnd));
    bones.push({
      localRow,
      globalJointId: localPaletteToGlobalJointIds[localRow],
      parentLocalRow,
      name,
      descriptorTag: view.getUint32(descriptorOffset + 44, true),
      quaternion,
      translation,
    });
  }
  const restPoseValidation = currentSceneLabel === C01A_SCENE_LABEL
    ? verifyC01ARestSkeleton(bones, localRestMatrices, globalRestMatrices)
    : null;
  return {
    boneCount,
    globalToLocalPaletteOffset,
    localPaletteToGlobalJointIds,
    localRigidTransformsOffset,
    localRestMatricesOffset,
    globalRestMatricesOffset,
    unresolvedBasisOffset,
    boneDescriptorsOffset,
    localRigidTransforms,
    localRestMatrices,
    globalRestMatrices,
    bones,
    restPoseValidation,
  };
}

function readPrmStrips(view, indicesOffset, indexWords, vertexCount) {
  const byteLength = indexWords * 2;
  assertRange(view, indicesOffset, byteLength, "PRM index block");
  if (indexWords < 1) return [];
  let cursor = indicesOffset;
  const end = indicesOffset + byteLength;
  const primitiveCount = view.getUint16(cursor, true);
  cursor += 2;
  const triangles = [];
  for (let primitive = 0; primitive < primitiveCount; primitive += 1) {
    if (cursor + 2 > end) throw new Error("Truncated PRM primitive header.");
    const stripCount = view.getUint16(cursor, true);
    cursor += 2;
    if (cursor + stripCount * 2 > end) throw new Error("Truncated PRM triangle strip.");
    const strip = [];
    for (let index = 0; index < stripCount; index += 1) {
      const vertex = view.getUint16(cursor, true);
      cursor += 2;
      if (vertex >= vertexCount) throw new Error("PRM index points beyond its vertex list.");
      strip.push(vertex);
    }
    for (let index = 2; index < strip.length; index += 1) {
      const triangle = index % 2 === 0
        ? [strip[index - 2], strip[index - 1], strip[index]]
        : [strip[index - 1], strip[index - 2], strip[index]];
      if (triangle[0] !== triangle[1] && triangle[1] !== triangle[2] && triangle[0] !== triangle[2]) {
        triangles.push(...triangle);
      }
    }
  }
  if (cursor !== end) throw new Error("PRM index block did not consume its declared word count.");
  return triangles;
}

function readPrmEntry(view, rawOffset, withPositions = false) {
  const offset = rawOffset & PRM_POINTER_MASK;
  assertRange(view, offset, PRM_ENTRY_BYTES, "PRM entry");
  const entryFlags = view.getUint32(offset, true);
  const vertexLayout = prmVertexLayout(entryFlags);
  const materialId = view.getUint32(offset + 0x04, true);
  const childOffset = view.getUint32(offset + 0x08, true);
  const vertexCount = view.getUint16(offset + 0x0e, true);
  const boundsOffset = view.getUint32(offset + 0x10, true);
  const verticesOffset = view.getUint32(offset + 0x14, true);
  const indicesOffset = view.getUint32(offset + 0x3c, true);
  const indexWords = view.getUint32(offset + 0x40, true);
  const jointMap = entryFlags === PRM_EXTENDED_VERTEX_FLAGS
    ? readExtendedPrmJointMap(view, offset)
    : null;
  assertRange(view, verticesOffset, vertexCount * vertexLayout.stride, "PRM vertex block");
  const triangles = readPrmStrips(view, indicesOffset, indexWords, vertexCount);
  let positions = null;
  let normals = null;
  let uvs = null;
  let colors = null;
  let skinWeights = null;
  let skinPaletteIndices = null;
  let skinGlobalJointIds = null;
  if (withPositions) {
    positions = new Float32Array(vertexCount * 3);
    normals = new Float32Array(vertexCount * 3);
    uvs = new Float32Array(vertexCount * 2);
    colors = new Uint8Array(vertexCount * 4);
    if (entryFlags === PRM_EXTENDED_VERTEX_FLAGS) {
      skinWeights = new Float32Array(vertexCount * 4);
      skinPaletteIndices = new Uint8Array(vertexCount * 4);
      skinGlobalJointIds = new Uint8Array(vertexCount * 4);
    }
    for (let vertex = 0; vertex < vertexCount; vertex += 1) {
      const source = verticesOffset + vertex * vertexLayout.stride;
      const x = view.getFloat32(source, true);
      const y = view.getFloat32(source + 4, true);
      const z = view.getFloat32(source + 8, true);
      const normalX = view.getFloat32(source + vertexLayout.normalOffset, true);
      const normalY = view.getFloat32(source + vertexLayout.normalOffset + 4, true);
      const normalZ = view.getFloat32(source + vertexLayout.normalOffset + 8, true);
      const u = view.getFloat32(source + vertexLayout.uvOffset, true);
      const v = view.getFloat32(source + vertexLayout.uvOffset + 4, true);
      if (![x, y, z, normalX, normalY, normalZ, u, v].every(Number.isFinite)) {
        throw new Error("PRM vertex data is non-finite.");
      }
      if ([x, y, z].some((value) => Math.abs(value) > PRM_MAX_COORDINATE)) {
        throw new Error("PRM vertex position exceeds the safe scene range.");
      }
      positions[vertex * 3] = x;
      positions[vertex * 3 + 1] = y;
      // PRM meshes use the original renderer's left-handed coordinates.
      // Reflect Z once here so the expanded triangle winding and normals agree
      // with the ordinary right-handed WebGL camera used by this viewer.
      positions[vertex * 3 + 2] = -z;
      normals[vertex * 3] = normalX;
      normals[vertex * 3 + 1] = normalY;
      normals[vertex * 3 + 2] = -normalZ;
      uvs[vertex * 2] = u;
      uvs[vertex * 2 + 1] = v;
      const diffuse = view.getUint32(source + vertexLayout.diffuseOffset, true);
      // the diffuse word is a D3DCOLOR,
      // 0xAARRGGBB (bytes B,G,R,A). It was read as ABGR, which swapped red
      // and blue: the C01A Ford pickup's paint tint 0xffd03723 (red-orange)
      // drew as blue stripes and pale-blue patches.
      colors[vertex * 4] = (diffuse >>> 16) & 0xff;
      colors[vertex * 4 + 1] = (diffuse >>> 8) & 0xff;
      colors[vertex * 4 + 2] = diffuse & 0xff;
      colors[vertex * 4 + 3] = diffuse >>> 24;
      if (skinWeights && skinPaletteIndices && skinGlobalJointIds && jointMap) {
        // The original ZRObjectBonesSWD3D constructor copies the first three
        // weights and derives the fourth as 1 - w0 - w1 - w2. It divides each
        // raw selector byte by three before the BonesSW renderer consumes the
        // corresponding 3×4 local-palette matrix. The entry's verified
        // global-ID-to-local-row table below resolves each row to an ANM ID,
        // but not to a pose matrix, so rendering remains unskinned.
        const weight0 = view.getFloat32(source + vertexLayout.weightOffset, true);
        const weight1 = view.getFloat32(source + vertexLayout.weightOffset + 4, true);
        const weight2 = view.getFloat32(source + vertexLayout.weightOffset + 8, true);
        if (![weight0, weight1, weight2].every(Number.isFinite)) {
          throw new Error("Extended PRM skin weights are non-finite.");
        }
        const selectorWord = view.getUint32(source + vertexLayout.selectorOffset, true);
        const skinBase = vertex * 4;
        skinWeights[skinBase] = weight0;
        skinWeights[skinBase + 1] = weight1;
        skinWeights[skinBase + 2] = weight2;
        skinWeights[skinBase + 3] = 1 - weight0 - weight1 - weight2;
        for (let lane = 0; lane < 4; lane += 1) {
          const rawSelector = (selectorWord >>> (lane * 8)) & 0xff;
          if (rawSelector % PRM_EXTENDED_SELECTOR_DIVISOR !== 0) {
            throw new Error("Extended PRM selector is not aligned to a verified local-palette row.");
          }
          const localPaletteRow = rawSelector / PRM_EXTENDED_SELECTOR_DIVISOR;
          if (localPaletteRow >= jointMap.boneCount) {
            throw new Error("Extended PRM selector exceeds its declared local palette.");
          }
          skinPaletteIndices[skinBase + lane] = localPaletteRow;
          skinGlobalJointIds[skinBase + lane] = jointMap.localPaletteToGlobalJointIds[localPaletteRow];
        }
      }
    }
  }
  return {
    offset, entryFlags, vertexLayout, materialId, childOffset, vertexCount,
    boundsOffset, verticesOffset, indicesOffset, indexWords, triangles,
    positions, normals, uvs, colors, skinWeights, skinPaletteIndices, skinGlobalJointIds,
    boneCount: jointMap?.boneCount ?? null,
    globalToLocalPaletteOffset: jointMap?.globalToLocalPaletteOffset ?? null,
    localPaletteToGlobalJointIds: jointMap?.localPaletteToGlobalJointIds ?? null,
    skeleton: jointMap ? {
      localRigidTransformsOffset: jointMap.localRigidTransformsOffset,
      localRestMatricesOffset: jointMap.localRestMatricesOffset,
      globalRestMatricesOffset: jointMap.globalRestMatricesOffset,
      unresolvedBasisOffset: jointMap.unresolvedBasisOffset,
      boneDescriptorsOffset: jointMap.boneDescriptorsOffset,
      localRigidTransforms: jointMap.localRigidTransforms,
      localRestMatrices: jointMap.localRestMatrices,
      globalRestMatrices: jointMap.globalRestMatrices,
      bones: jointMap.bones,
      restPoseValidation: jointMap.restPoseValidation,
    } : null,
  };
}

function parsePrmCatalog(buffer) {
  if (buffer.byteLength < 16) throw new Error("File is too small to be a PRM resource.");
  const view = new DataView(buffer);
  const entryTableOffset = view.getUint32(4, true);
  const entryCount = view.getUint32(12, true);
  assertRange(view, entryTableOffset, entryCount * 4, "PRM entry table");
  const catalog = [];
  for (let entryIndex = 0; entryIndex < entryCount; entryIndex += 1) {
    const rawOffset = view.getUint32(entryTableOffset + entryIndex * 4, true);
    try {
      const entry = readPrmEntry(view, rawOffset);
      if (entry.triangles.length) {
        catalog.push({ entryIndex, rawOffset, vertexCount: entry.vertexCount, triangleCount: entry.triangles.length / 3 });
      }
    } catch (_) {
      // The table includes non-drawable entries. They are deliberately omitted
      // from this exploratory model picker until their formats are understood.
    }
  }
  return { view, entryCount, catalog };
}

function parsePrmModel(view, rawOffset) {
  const parts = [];
  const visited = new Set();
  let hasExtendedVertexLayout = false;
  function visit(pointer, depth = 0) {
    if (depth > 64) throw new Error("PRM child hierarchy exceeds the safe preview depth.");
    const offset = pointer & PRM_POINTER_MASK;
    if (!offset || visited.has(offset)) return;
    visited.add(offset);
    const entry = readPrmEntry(view, pointer, true);
    if (entry.entryFlags === PRM_EXTENDED_VERTEX_FLAGS) hasExtendedVertexLayout = true;
    if (entry.triangles.length) parts.push(entry);
    if (entry.childOffset) visit(entry.childOffset, depth + 1);
  }
  visit(rawOffset);
  if (!parts.length) throw new Error("This PRM entry has no drawable triangle strips.");
  const totalVertices = parts.reduce((total, part) => total + part.vertexCount, 0);
  const totalIndices = parts.reduce((total, part) => total + part.triangles.length, 0);
  const positions = new Float32Array(totalVertices * 3);
  const normals = new Float32Array(totalVertices * 3);
  const uvs = new Float32Array(totalVertices * 2);
  const colors = new Uint8Array(totalVertices * 4);
  const indices = new Uint32Array(totalIndices);
  const skinWeights = hasExtendedVertexLayout ? new Float32Array(totalVertices * 4) : null;
  const skinPaletteIndices = hasExtendedVertexLayout ? new Uint8Array(totalVertices * 4) : null;
  const skinGlobalJointIds = hasExtendedVertexLayout ? new Uint8Array(totalVertices * 4).fill(PRM_UNMAPPED_JOINT) : null;
  const skinnedVertexMask = hasExtendedVertexLayout ? new Uint8Array(totalVertices) : null;
  const paletteIndices = new Set();
  const globalJointIds = new Set();
  const paletteGlobalJointIds = new Set();
  const boneCounts = new Set();
  const skeletons = new Map();
  let skinnedVertices = 0;
  let skinnedParts = 0;
  const drawGroups = [];
  let vertexBase = 0;
  let indexCursor = 0;
  for (const part of parts) {
    positions.set(part.positions, vertexBase * 3);
    normals.set(part.normals, vertexBase * 3);
    uvs.set(part.uvs, vertexBase * 2);
    colors.set(part.colors, vertexBase * 4);
    if (part.skinWeights && part.skinPaletteIndices && part.skinGlobalJointIds && part.localPaletteToGlobalJointIds
      && skinWeights && skinPaletteIndices && skinGlobalJointIds && skinnedVertexMask) {
      skinWeights.set(part.skinWeights, vertexBase * 4);
      skinPaletteIndices.set(part.skinPaletteIndices, vertexBase * 4);
      skinGlobalJointIds.set(part.skinGlobalJointIds, vertexBase * 4);
      skinnedVertexMask.fill(1, vertexBase, vertexBase + part.vertexCount);
      skinnedVertices += part.vertexCount;
      skinnedParts += 1;
      part.skinPaletteIndices.forEach((paletteIndex) => paletteIndices.add(paletteIndex));
      part.skinGlobalJointIds.forEach((jointId) => {
        if (jointId !== PRM_UNMAPPED_JOINT) globalJointIds.add(jointId);
      });
      part.localPaletteToGlobalJointIds.forEach((jointId) => {
        if (jointId !== PRM_UNMAPPED_JOINT) paletteGlobalJointIds.add(jointId);
      });
      if (part.boneCount !== null) boneCounts.add(part.boneCount);
      if (part.skeleton) {
        const signature = `${part.boneCount}:${part.globalToLocalPaletteOffset}`;
        skeletons.set(signature, {
          signature,
          boneCount: part.boneCount,
          globalToLocalPaletteOffset: part.globalToLocalPaletteOffset,
          bones: part.skeleton.bones,
          restPoseValidation: part.skeleton.restPoseValidation,
        });
      }
    }
    const indexStart = indexCursor;
    for (const index of part.triangles) indices[indexCursor++] = index + vertexBase;
    drawGroups.push({
      indexStart, indexCount: part.triangles.length, materialId: part.materialId,
      // PRM render state (tex-format.md section 5): +0x20 flags, +0x44 alphaRef.
      prmEntry: part.offset, renderFlags: view.getUint32(part.offset + 0x20, true), alphaRef: view.getUint32(part.offset + 0x44, true),
    });
    vertexBase += part.vertexCount;
  }
  const localPaletteIndices = [...paletteIndices].sort((left, right) => left - right);
  const mappedGlobalJointIds = [...globalJointIds].sort((left, right) => left - right);
  return {
    positions, normals, uvs, colors, indices, drawGroups, parts: parts.length,
    hasExtendedVertexLayout, skinWeights, skinPaletteIndices, skinGlobalJointIds, skinnedVertexMask,
    skinData: skinnedVertices ? {
      vertices: skinnedVertices,
      parts: skinnedParts,
      localPaletteIndices,
      maxLocalPaletteIndex: localPaletteIndices.at(-1) ?? null,
      globalJointIds: mappedGlobalJointIds,
      paletteGlobalJointIds: [...paletteGlobalJointIds].sort((left, right) => left - right),
      boneCounts: [...boneCounts].sort((left, right) => left - right),
      skeletons: [...skeletons.values()],
    } : null,
  };
}


export { setSceneLabel, prmVertexLayout, readExtendedPrmJointMap, readPrmStrips, readPrmEntry, parsePrmCatalog, parsePrmModel, verifyC01ARestSkeleton, multiplyRowMatrices3, transformRowVector3, rowQuaternionMatrix };
