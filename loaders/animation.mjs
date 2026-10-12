// Local animation math only: this module does not infer a skeleton, palette,
// coordinate conversion, clip selection, or actor behavior. Quaternions are xyzw.
// Evidence: FUN_004e54c0 (sampling), FUN_004df040/FUN_004dfb10
// (interpolation), FUN_00645c90/FUN_004def50/FUN_00441940 (fitting).
// JavaScript arithmetic is double precision, so this is not a bit-exact float32
// emulator. Preserve the observed branches without normalization or sign flips.

const ANTIPARALLEL_EPSILON = 1 / 8192;

function assertFiniteNumber(value, label) {
  if (!Number.isFinite(value)) throw new TypeError(`${label} must be finite.`);
}

function copyVector(value, size, label) {
  if ((!Array.isArray(value) && !ArrayBuffer.isView(value)) || value.length !== size) {
    throw new TypeError(`${label} must contain ${size} components.`);
  }
  const result = Array.from(value);
  for (const component of result) assertFiniteNumber(component, label);
  if (size === 4) {
    const squaredLength = result.reduce((sum, component) => sum + component * component, 0);
    if (!Number.isFinite(squaredLength) || squaredLength === 0) {
      throw new RangeError(`${label} must have a finite, nonzero squared length.`);
    }
  }
  return result;
}

function interpolateTranslationUnchecked(a, b, t) {
  return a.map((component, index) => component + (b[index] - component) * t);
}

function interpolateQuaternionUnchecked(a, b, t) {
  const dot = a[0] * b[0] + a[1] * b[1] + a[2] * b[2] + a[3] * b[3];
  if (dot > 0.9) return interpolateTranslationUnchecked(a, b, t);

  if (1 + dot <= ANTIPARALLEL_EPSILON) {
    // FUN_004dfb10 writes four perpendicular components, but its following
    // loop blends only xyz (three iterations). w remains a.z. This unusual
    // native result is intentional; do not replace it with standard slerp.
    const aWeight = Math.sin((1 - t) * Math.PI / 2);
    const perpendicularWeight = Math.sin(t * Math.PI / 2);
    return [
      a[0] * aWeight - a[1] * perpendicularWeight,
      a[1] * aWeight + a[0] * perpendicularWeight,
      a[2] * aWeight - a[3] * perpendicularWeight,
      a[2],
    ];
  }

  const angle = Math.acos(Math.max(-1, Math.min(1, dot)));
  const denominator = Math.sin(angle);
  const aWeight = Math.sin((1 - t) * angle) / denominator;
  const bWeight = Math.sin(t * angle) / denominator;
  return a.map((component, index) => component * aWeight + b[index] * bWeight);
}

/**
 * Interpolate xyzw rotations using the observed native branches. Inputs are
 * copied and validated; quantized rotations are not normalized. t must be in
 * [0, 1]. The antiparallel branch deliberately retains the native oddity even
 * at t=0/1; prepareKeyframes().sample() separately preserves exact stored keys.
 */
export function interpolateQuaternion(a, b, t) {
  assertFiniteNumber(t, "Interpolation fraction");
  if (t < 0 || t > 1) throw new RangeError("Interpolation fraction must be between zero and one.");
  return interpolateQuaternionUnchecked(copyVector(a, 4, "First quaternion"), copyVector(b, 4, "Second quaternion"), t);
}

/**
 * Validate/copy one nonempty channel once, then sample in O(log keyCount).
 * Keys are {tick, value}; ticks must be finite, nonnegative, and strictly
 * increasing. kind is "quaternion" (xyzw) or "translation" (xyz).
 * Sampling clamps to the channel endpoints and returns a new array. Exact
 * key times return their stored values, including quantization error. One key
 * represents a static channel. No looping or time-unit conversion is inferred.
 */
export function prepareKeyframes(keys, { kind } = {}) {
  if (kind !== "quaternion" && kind !== "translation") {
    throw new TypeError('Channel kind must be "quaternion" or "translation".');
  }
  if (!Array.isArray(keys) || keys.length === 0) throw new TypeError("A channel must contain at least one key.");
  const size = kind === "quaternion" ? 4 : 3;
  let previousTick = -1;
  const prepared = keys.map((key, index) => {
    if (!key || typeof key !== "object") throw new TypeError(`Key ${index} must be an object.`);
    assertFiniteNumber(key.tick, `Key ${index} tick`);
    if (key.tick < 0 || key.tick <= previousTick) {
      throw new RangeError("Key ticks must be nonnegative and strictly increasing.");
    }
    previousTick = key.tick;
    return { tick: key.tick, value: copyVector(key.value, size, `Key ${index} ${kind}`) };
  });
  const first = prepared[0];
  const last = prepared[prepared.length - 1];
  const interpolate = kind === "quaternion" ? interpolateQuaternionUnchecked : interpolateTranslationUnchecked;
  return Object.freeze({
    kind,
    keyCount: prepared.length,
    startTick: first.tick,
    endTick: last.tick,
    sample(time) {
      assertFiniteNumber(time, "Sample time");
      if (time <= first.tick) return first.value.slice();
      if (time >= last.tick) return last.value.slice();
      let lower = 0;
      let upper = prepared.length - 1;
      while (upper - lower > 1) {
        const middle = Math.floor((lower + upper) / 2);
        if (prepared[middle].tick <= time) lower = middle;
        else upper = middle;
      }
      const a = prepared[lower];
      if (time === a.tick) return a.value.slice();
      const b = prepared[upper];
      return interpolate(a.value, b.value, (time - a.tick) / (b.tick - a.tick));
    },
  });
}

/** Convenience for one-off sampling; use prepareKeyframes once for playback. */
export function sampleKeyframes(keys, time, options) {
  return prepareKeyframes(keys, options).sample(time);
}

/**
 * Apply the sampled local fit: qRaw Hamilton-multiplied by qFit, and tRaw+tFit.
 * The fit translation is added directly, not rotated by either quaternion.
 * Inputs/results are {quaternion: [x,y,z,w], translation: [x,y,z]}.
 * Fitting precedes skeleton propagation through resolveSkeletonPose.
 */
export function fitLocalTransform(raw, fit) {
  const a = copyVector(raw?.quaternion, 4, "Raw quaternion");
  const b = copyVector(fit?.quaternion, 4, "Fit quaternion");
  const rawTranslation = copyVector(raw?.translation, 3, "Raw translation");
  const fitTranslation = copyVector(fit?.translation, 3, "Fit translation");
  return {
    quaternion: [
      a[3] * b[0] + a[0] * b[3] + a[1] * b[2] - a[2] * b[1],
      a[3] * b[1] - a[0] * b[2] + a[1] * b[3] + a[2] * b[0],
      a[3] * b[2] + a[0] * b[1] - a[1] * b[0] + a[2] * b[3],
      a[3] * b[3] - a[0] * b[0] - a[1] * b[1] - a[2] * b[2],
    ],
    translation: rawTranslation.map((component, index) => component + fitTranslation[index]),
  };
}

function quaternionRowMatrix(quaternion) {
  // FUN_004df1e0 divides by squared quaternion length. Express that as
  // normalization here; the returned rows omit PRM's serialized axis swap.
  const length = Math.hypot(...quaternion);
  const [x, y, z, w] = quaternion.map((component) => component / length);
  return [
    1 - 2 * (y * y + z * z), 2 * (x * y + z * w), 2 * (x * z - y * w),
    2 * (x * y - z * w), 1 - 2 * (x * x + z * z), 2 * (y * z + x * w),
    2 * (x * z + y * w), 2 * (y * z - x * w), 1 - 2 * (x * x + y * y),
  ];
}

function multiplyRowMatrices(a, b) {
  const result = new Array(9);
  for (let row = 0; row < 3; row += 1) {
    for (let column = 0; column < 3; column += 1) {
      result[row * 3 + column] = a[row * 3] * b[column]
        + a[row * 3 + 1] * b[column + 3] + a[row * 3 + 2] * b[column + 6];
    }
  }
  return result;
}

/**
 * Propagate local transforms using the row-vector convention confirmed by
 * FUN_00659c40: child.R=local.R*parent.R, child.T=local.T*parent.R+parent.T.
 * bones[i].parentLocalRow is an array index, or -1 for a root. localTransforms
 * has one {quaternion,translation} per bone. Roots use the supplied transform;
 * actor/root-motion policy is the caller's responsibility.
 * Returns an array in input order of {rotation: [9 row-major], translation:[3]}.
 * This is an ordinary mathematical rotation; no serialized PRM axis swap,
 * inverse bind matrix, or skinning palette is applied.
 */
export function resolveSkeletonPose(bones, localTransforms) {
  if (!Array.isArray(bones) || !Array.isArray(localTransforms) || bones.length !== localTransforms.length) {
    throw new TypeError("Bones and local transforms must be arrays of equal length.");
  }
  const count = bones.length;
  const parents = Array.from({ length: count }, (_, index) => {
    const parent = bones[index]?.parentLocalRow;
    if (!Number.isInteger(parent) || parent < -1 || parent >= count) {
      throw new RangeError(`Bone ${index} has an invalid parent index.`);
    }
    return parent;
  });
  const local = Array.from({ length: count }, (_, index) => ({
    rotation: quaternionRowMatrix(copyVector(localTransforms[index]?.quaternion, 4, `Bone ${index} quaternion`)),
    translation: copyVector(localTransforms[index]?.translation, 3, `Bone ${index} translation`),
  }));
  const result = new Array(count);
  const state = new Uint8Array(count);
  for (let index = 0; index < count; index += 1) {
    const path = [];
    let cursor = index;
    while (cursor !== -1 && state[cursor] !== 2) {
      if (state[cursor] === 1) throw new Error("Skeleton contains a parent cycle.");
      state[cursor] = 1;
      path.push(cursor);
      cursor = parents[cursor];
    }
    while (path.length) {
      const boneIndex = path.pop();
      const child = local[boneIndex];
      const parentIndex = parents[boneIndex];
      if (parentIndex === -1) {
        result[boneIndex] = child;
      } else {
        const parent = result[parentIndex];
        const [x, y, z] = child.translation;
        const matrix = parent.rotation;
        result[boneIndex] = {
          rotation: multiplyRowMatrices(child.rotation, matrix),
          translation: [
            x * matrix[0] + y * matrix[3] + z * matrix[6] + parent.translation[0],
            x * matrix[1] + y * matrix[4] + z * matrix[7] + parent.translation[1],
            x * matrix[2] + y * matrix[5] + z * matrix[8] + parent.translation[2],
          ],
        };
      }
      state[boneIndex] = 2;
    }
  }
  return result;
}
