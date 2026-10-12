// GMS geom hierarchy and world transforms (pure module, no DOM).
// JS port of decoders/gms_world.py (see rooms-sgp-format.md section 6):
//
// * The instance table (GMS u32 @0 -> u32 count, count x {u32 w, u32 aux}) is
//   walked in order by ZEngineDataBase::CreateGeoms (GC 801fd9f8). For each entry
//     pop  = w >> 25                  go up `pop` parents first
//     rec  = (w << 2) & 0x03fffffc    SCompiledGeom record offset
//     push = w & 0x01000000           the new geom becomes the parent
//   Every entry creates one geom; aliased records are instantiated again.
// * rec+4 -> 9 floats m, rec+8 -> 3 floats p are parent-relative
//   (ZBaseGeom::GetLocalPoint recurses into the parent first).
// * world = R * local + p with R[i][j] = m[3*(2-j)+i] (column vectors), and a
//   geom's world transform is parent_world o local. The GMS identity is stored
//   as 0,0,1, 0,1,0, 1,0,0.
//
// Coordinates stay in the file's native (left-handed, +Y up) space. Renderers
// reflect Z themselves.

export class GmsFormatError extends Error {}

export const GMS_ROOT = -1;
export const GMS_CLASS_GROUP_BIT = 0x100000;
export const GMS_CLASS_ROOM = 0x100021;

/** GMS 9 floats -> column-vector R, stored row-major: R = [[m6,m3,m0],[m7,m4,m1],[m8,m5,m2]]. */
export function gmsMatrix(m) {
  return [m[6], m[3], m[0], m[7], m[4], m[1], m[8], m[5], m[2]];
}

export function mul3(a, b) {
  const r = new Array(9);
  for (let i = 0; i < 3; i += 1) {
    for (let j = 0; j < 3; j += 1) r[i * 3 + j] = a[i * 3] * b[j] + a[i * 3 + 1] * b[3 + j] + a[i * 3 + 2] * b[6 + j];
  }
  return r;
}

export function mulVec3(a, v) {
  return [
    a[0] * v[0] + a[1] * v[1] + a[2] * v[2],
    a[3] * v[0] + a[4] * v[1] + a[5] * v[2],
    a[6] * v[0] + a[7] * v[1] + a[8] * v[2],
  ];
}

function readName(bufBytes, offset) {
  if (!bufBytes || !Number.isInteger(offset) || offset < 0 || offset >= bufBytes.length) return "";
  let s = "";
  for (let k = offset; k < bufBytes.length && k < offset + 512; k += 1) {
    const c = bufBytes[k];
    if (!c) break;
    s += String.fromCharCode(c); // latin-1, like gms_world.py
  }
  return s;
}

/**
 * Rebuild the geom hierarchy from a decompressed GMS body.
 * Returns { geoms, roots } where geoms[i] = { index, rec, cls, parent, children,
 * depth, name, prm, matrix, position, R, p } and (R, p) is the world transform.
 */
export function parseGmsHierarchy(rawBuffer, bufBuffer = null) {
  const view = rawBuffer instanceof DataView ? rawBuffer : new DataView(rawBuffer);
  const bufBytes = bufBuffer ? new Uint8Array(bufBuffer instanceof DataView ? bufBuffer.buffer : bufBuffer) : null;
  const n = view.byteLength;
  const u32 = (o) => {
    if (o < 0 || o + 4 > n) throw new GmsFormatError(`read beyond GMS body at 0x${o.toString(16)}`);
    return view.getUint32(o, true);
  };
  const floats = (o, k) => {
    if (o < 0 || o + 4 * k > n) throw new GmsFormatError(`read beyond GMS body at 0x${o.toString(16)}`);
    return Array.from({ length: k }, (_, i) => view.getFloat32(o + 4 * i, true));
  };
  const table = u32(0);
  const count = u32(table);
  if (count > (n - table) / 8) throw new GmsFormatError(`instance count ${count} too large`);
  const geoms = [];
  const parents = [];
  let current = GMS_ROOT;
  for (let i = 0; i < count; i += 1) {
    const w = u32(table + 4 + 8 * i);
    const pop = w >>> 25;
    for (let k = 0; k < pop; k += 1) {
      if (!parents.length) throw new GmsFormatError(`entry ${i} pops above the root`);
      current = parents.pop();
    }
    const rec = (w << 2) & 0x03fffffc;
    if (rec + 0x30 > n) throw new GmsFormatError(`entry ${i}: record 0x${rec.toString(16)} out of range`);
    const matrix = floats(u32(rec + 4), 9);
    const position = floats(u32(rec + 8), 3);
    const local = gmsMatrix(matrix);
    const g = {
      index: i, rec, cls: u32(rec + 0x10), parent: current, children: [], depth: parents.length,
      name: readName(bufBytes, u32(rec)), prm: u32(rec + 0x0c) & 0x01ffffff, matrix, position,
    };
    if (current === GMS_ROOT) {
      g.R = local;
      g.p = position.slice();
    } else {
      const parent = geoms[current];
      parent.children.push(i);
      g.R = mul3(parent.R, local);
      const v = mulVec3(parent.R, position);
      g.p = [v[0] + parent.p[0], v[1] + parent.p[1], v[2] + parent.p[2]];
    }
    geoms.push(g);
    if (w & 0x01000000) {
      parents.push(current);
      current = i;
    }
  }
  return { geoms };
}

/** Backslash-joined names from the top-level geom down (SGP name-table form). */
export function geomPath(hierarchy, index) {
  const names = [];
  for (let i = index; i !== GMS_ROOT; i = hierarchy.geoms[i].parent) names.push(hierarchy.geoms[i].name);
  return names.reverse().join("\\");
}

export function ancestors(hierarchy, index) {
  const out = [];
  for (let i = hierarchy.geoms[index].parent; i !== GMS_ROOT; i = hierarchy.geoms[i].parent) out.push(i);
  return out;
}

/** World point for geom i: R * local + p (native space). */
export function worldPoint(geom, v) {
  const r = mulVec3(geom.R, v);
  return [r[0] + geom.p[0], r[1] + geom.p[1], r[2] + geom.p[2]];
}
