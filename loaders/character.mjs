// Skinned-character runtime core: PRM skin chain + ANM sampler + palette.
// Pure module (no DOM, no WebGL) so Node tests can check it against the
// reference decoder decoders/skin.py. Every step follows
// decoders/skinning-format.md; native addresses are quoted inline.
//
// Matrix convention used in this file: ordinary column-vector rotations
// (p' = R p), stored as 9 numbers row-major. The engine's stored 3x3 `m`
// relates to R by m = S * R^T, R = m^T * S, S = [[0,0,1],[0,1,0],[1,0,0]]
// (FUN_004df1e0, PROVEN). All positions stay in the file's native
// (left-handed, +Y up, character faces -Z) space; renderers reflect Z later.

import { interpolateQuaternion } from "./animation.mjs";

export class SkinFormatError extends Error {}

const SKIN_ENTRY_TYPE = 0x00010100;
const VERTEX_STRIDE = 52;
const MAX_BONES = 128;
const MAX_CHAIN_PARTS = 16;
export const MAX_LOCAL_PALETTE = 32; // largest C01A/C05A part uses 26 slots

function bounds(dataView, offset, length, what) {
  if (!Number.isInteger(offset) || offset < 0 || offset + length > dataView.byteLength) {
    throw new SkinFormatError(`${what} out of bounds at 0x${Number(offset).toString(16)}`);
  }
}

// ---------------------------------------------------------------------------
// small math
export function quatToMat3(q) {
  // Hamilton xyzw, scaled by 2/|q|^2 like FUN_004df1e0 (unnormalised keys ok).
  const [x, y, z, w] = q;
  const n = x * x + y * y + z * z + w * w;
  const s = n ? 2 / n : 0;
  return [
    1 - s * (y * y + z * z), s * (x * y - w * z), s * (x * z + w * y),
    s * (x * y + w * z), 1 - s * (x * x + z * z), s * (y * z - w * x),
    s * (x * z - w * y), s * (y * z + w * x), 1 - s * (x * x + y * y),
  ];
}

function mul3(a, b) {
  const r = new Array(9);
  for (let i = 0; i < 3; i += 1) {
    for (let j = 0; j < 3; j += 1) {
      r[i * 3 + j] = a[i * 3] * b[j] + a[i * 3 + 1] * b[3 + j] + a[i * 3 + 2] * b[6 + j];
    }
  }
  return r;
}

function mulABt(a, b) { // a * b^T
  const r = new Array(9);
  for (let i = 0; i < 3; i += 1) {
    for (let j = 0; j < 3; j += 1) {
      r[i * 3 + j] = a[i * 3] * b[j * 3] + a[i * 3 + 1] * b[j * 3 + 1] + a[i * 3 + 2] * b[j * 3 + 2];
    }
  }
  return r;
}

function mulVec(a, v) {
  return [
    a[0] * v[0] + a[1] * v[1] + a[2] * v[2],
    a[3] * v[0] + a[4] * v[1] + a[5] * v[2],
    a[6] * v[0] + a[7] * v[1] + a[8] * v[2],
  ];
}

/** Engine-stored 3x3 (row-major m) -> column-vector R = m^T S, i.e.
 * R = [[m6,m3,m0],[m7,m4,m1],[m8,m5,m2]] (skinning-format.md section 7). */
export function storedToReal(m) {
  return [m[6], m[3], m[0], m[7], m[4], m[1], m[8], m[5], m[2]];
}

function qmul(a, b) { // Hamilton a*b, xyzw (FUN_004def50)
  const [ax, ay, az, aw] = a;
  const [bx, by, bz, bw] = b;
  return [
    aw * bx + ax * bw + ay * bz - az * by,
    aw * by + ay * bw + az * bx - ax * bz,
    aw * bz + az * bw + ax * by - ay * bx,
    aw * bw - ax * bx - ay * by - az * bz,
  ];
}

// ---------------------------------------------------------------------------
// PRM skinned chain
function readSkeleton(view, entry) {
  const n = view.getUint32(entry + 0x7c, true);
  if (!(n > 0 && n <= MAX_BONES)) throw new SkinFormatError(`bone count ${n}`);
  const q84 = view.getUint32(entry + 0x84, true);
  const g88 = view.getUint32(entry + 0x88, true);
  const d90 = view.getUint32(entry + 0x90, true);
  const m94 = view.getUint32(entry + 0x94, true);
  const b8c = view.getUint32(entry + 0x8c, true); // n x 36 B "basis" block: the attach frame of each bone (ZBoneModifyBase::GetIKBone)
  bounds(view, q84, 28 * n, "rest locals +0x84");
  bounds(view, b8c, 36 * n, "bone basis +0x8c");
  bounds(view, g88, 48 * n, "rest globals +0x88");
  bounds(view, d90, 48 * n, "bone descriptors +0x90");
  bounds(view, m94, 96, "joint map +0x94");
  const bones = [];
  for (let i = 0; i < n; i += 1) {
    const f = (o, k) => Array.from({ length: k }, (_, j) => view.getFloat32(o + 4 * j, true));
    const qt = f(q84 + 28 * i, 7);
    const g = f(g88 + 48 * i, 12);
    const parent = view.getInt32(d90 + 48 * i + 12, true);
    if (parent >= i || parent < -1) throw new SkinFormatError(`bone ${i} parent ${parent} not before it`);
    let name = "";
    for (let k = 0; k < 16; k += 1) {
      const c = view.getUint8(d90 + 48 * i + 28 + k);
      if (!c) break;
      name += String.fromCharCode(c);
    }
    bones.push({
      name, parent, q: qt.slice(0, 4), t: qt.slice(4, 7),
      restR: storedToReal(g.slice(0, 9)), restT: g.slice(9, 12),
      basisR: storedToReal(f(b8c + 36 * i, 9)),
    });
  }
  const gid2row = new Map();
  for (let gid = 0; gid < 96; gid += 1) {
    const row = view.getUint8(m94 + gid);
    if (row !== 0xff) {
      if (row >= n) throw new SkinFormatError(`joint map row ${row} >= ${n}`);
      gid2row.set(gid, row);
    }
  }
  return { bones, gid2row };
}

function readStrips(view, io, iw, vc) {
  bounds(view, io, 2 * iw, "index block");
  const tris = [];
  if (!iw) return tris;
  let k = io + 2;
  const end = io + 2 * iw;
  const strips = view.getUint16(io, true);
  for (let s = 0; s < strips; s += 1) {
    if (k + 2 > end) throw new SkinFormatError("strip overrun");
    const n = view.getUint16(k, true);
    k += 2;
    if (k + 2 * n > end) throw new SkinFormatError("strip overrun");
    const strip = [];
    for (let j = 0; j < n; j += 1, k += 2) {
      const x = view.getUint16(k, true);
      if (x >= vc) throw new SkinFormatError("strip index beyond vertex count");
      strip.push(x);
    }
    for (let j = 0; j + 2 < n; j += 1) {
      const a = strip[j]; const b = strip[j + 1]; const c = strip[j + 2];
      if (a === b || b === c || a === c) continue;
      if (j & 1) tris.push(b, a, c); else tris.push(a, b, c);
    }
  }
  return tris;
}

function readPart(view, e, boneCount) {
  const vc = view.getUint16(e + 0x0e, true);
  const vo = view.getUint32(e + 0x14, true);
  const io = view.getUint32(e + 0x3c, true);
  const iw = view.getUint32(e + 0x40, true);
  // Index blocks are not always directly after the vertices (C01A 0x5652d6),
  // so vertices and indices are bounds-checked independently.
  bounds(view, vo, VERTEX_STRIDE * vc, "vertex block");
  const positions = new Float32Array(vc * 3);
  const normals = new Float32Array(vc * 3);
  const weights = new Float32Array(vc * 4);
  const selectors = new Uint8Array(vc * 4);
  const colors = new Uint8Array(vc * 4);
  const uvs = new Float32Array(vc * 2);
  // Palette runs (FUN_00617400 0x6175ec..0x617649): local slot -> bone row.
  const runCount = view.getUint32(e + 0x98, true);
  const runs = view.getUint32(e + 0x9c, true);
  if (runCount > 64) throw new SkinFormatError("too many palette runs");
  bounds(view, runs, 8 * runCount, "palette runs +0x9c");
  const remap = [];
  for (let i = 0; i < runCount; i += 1) {
    const cnt = view.getUint32(runs + 8 * i, true);
    const start = view.getUint32(runs + 8 * i + 4, true);
    if (cnt % 12 || start % 12) throw new SkinFormatError("palette run not a multiple of 12 floats");
    for (let b = start / 12; b < (start + cnt) / 12; b += 1) remap.push(b);
  }
  if (remap.length > MAX_LOCAL_PALETTE || remap.some((b) => b >= boneCount)) {
    throw new SkinFormatError(`local palette (${remap.length} slots) invalid`);
  }
  for (let i = 0; i < vc; i += 1) {
    const o = vo + VERTEX_STRIDE * i;
    for (let k = 0; k < 3; k += 1) {
      positions[3 * i + k] = view.getFloat32(o + 4 * k, true);
      normals[3 * i + k] = view.getFloat32(o + 28 + 4 * k, true);
    }
    const w0 = view.getFloat32(o + 12, true);
    const w1 = view.getFloat32(o + 16, true);
    const w2 = view.getFloat32(o + 20, true);
    weights.set([w0, w1, w2, 1 - w0 - w1 - w2], 4 * i); // 0x617a03
    for (let k = 0; k < 4; k += 1) {
      const sel = view.getUint8(o + 24 + k);
      if (sel % 3 || sel / 3 >= remap.length) {
        // A zero-weight lane may still carry selector 0; only reject used lanes.
        if (weights[4 * i + k] !== 0) throw new SkinFormatError(`vertex ${i} lane ${k} selector ${sel} invalid`);
        selectors[4 * i + k] = 0; // unused lane: keep the GPU index in range
      } else {
        selectors[4 * i + k] = sel;
      }
    }
    const diffuse = view.getUint32(o + 40, true);
    // D3DCOLOR 0xAARRGGBB (see app.js readPrmEntry, fixed 2026-10-08).
    colors.set([(diffuse >>> 16) & 0xff, (diffuse >>> 8) & 0xff, diffuse & 0xff, diffuse >>> 24], 4 * i);
    uvs[2 * i] = view.getFloat32(o + 44, true);
    uvs[2 * i + 1] = view.getFloat32(o + 48, true);
  }
  const indices = new Uint16Array(readStrips(view, io, iw, vc));
  return {
    entry: e, materialId: view.getUint32(e + 0x04, true), vertexCount: vc,
    positions, normals, weights, selectors, colors, uvs, indices, remap,
  };
}

export function isSkinnedEntry(view, e) {
  if (e < 0 || e + 0xa0 > view.byteLength) return false;
  return view.getUint32(e, true) === SKIN_ENTRY_TYPE
    && view.getUint32(e + 0x7c, true) > 0 && view.getUint32(e + 0x7c, true) <= MAX_BONES
    && view.getUint32(e + 0x98, true) < 64;
}

/** Load the character whose LAST part is `entry` (tag-14 prmEntry). Parts are
 * linked backwards through entry +0x08 (VERIFIED) and share one skeleton. */
export function loadCharacter(prmBuffer, entry) {
  const view = prmBuffer instanceof DataView ? prmBuffer : new DataView(prmBuffer);
  const chain = [];
  const seen = new Set();
  let e = entry;
  while (e && !seen.has(e)) {
    if (!isSkinnedEntry(view, e)) throw new SkinFormatError(`0x${e.toString(16)} is not a skinned PRM entry`);
    if (chain.length >= MAX_CHAIN_PARTS) throw new SkinFormatError("chain too long");
    seen.add(e);
    chain.push(e);
    e = view.getUint32(e + 0x08, true);
  }
  chain.reverse();
  const last = chain[chain.length - 1];
  for (const p of chain) {
    for (const k of [0x7c, 0x80, 0x84, 0x88]) {
      if (view.getUint32(p + k, true) !== view.getUint32(last + k, true)) {
        throw new SkinFormatError(`parts of 0x${entry.toString(16)} do not share one skeleton`);
      }
    }
  }
  const skeleton = readSkeleton(view, last);
  const parts = chain.map((p) => readPart(view, p, skeleton.bones.length));
  return { entry, chain, skeleton, parts };
}

// ---------------------------------------------------------------------------
// ANM (MNA) container, generic tag walk (FUN_004e5a10 / FUN_004e5140)
export function parseAnm(buffer) {
  const view = new DataView(buffer);
  const bytes = new Uint8Array(buffer);
  if (view.byteLength < 16 || String.fromCharCode(...bytes.subarray(0, 4)) !== "MNA\0") {
    throw new SkinFormatError("not an MNA file");
  }
  const u32 = (o) => { bounds(view, o, 4, "ANM read"); return view.getUint32(o, true); };
  const first = (h) => {
    const ln = u32(h + 4);
    if (!(ln & 0x80000000)) return null;
    return ln & 0x40000000 ? h + 0x14 + 4 * u32(h + 0x10) : h + 0x10;
  };
  const payload = (h) => h + ((u32(h + 4) & 0xc0000000) ? u32(h + 8) : 8);
  const tagHeaders = new Map();
  const groups = [];
  {
    const end = (u32(4) & 0x3fffffff);
    let c = first(0);
    let guard = 0;
    while (c !== null && c < end) {
      const ln = u32(c + 4) & 0x3fffffff;
      if (ln < 8 || ++guard > 100000) throw new SkinFormatError(`bad tag length at 0x${c.toString(16)}`);
      const t = u32(c);
      if (t === 10) groups.push(c);
      if (!tagHeaders.has(t)) tagHeaders.set(t, c);
      c += ln;
    }
  }
  for (const t of [4, 5, 6, 7, 8, 11, 13]) if (!tagHeaders.has(t)) throw new SkinFormatError(`ANM tag ${t} missing`);
  const pl = new Map([...tagHeaders].map(([t, h]) => [t, payload(h)]));
  const cstr = (o, lim) => {
    let s = "";
    for (let k = 0; k < lim && o + k < bytes.length && bytes[o + k]; k += 1) s += String.fromCharCode(bytes[o + k]);
    return s;
  };

  function bindings() {
    if (!tagHeaders.has(14)) return [];
    const h = tagHeaders.get(14);
    const n = Math.floor(((u32(h + 4) & 0x3fffffff) - (pl.get(14) - h)) / 12);
    return Array.from({ length: n }, (_, i) => {
      const o = pl.get(14) + 12 * i;
      return { group: u32(o), entry: u32(o + 4), fit1: u32(o + 8) };
    });
  }

  function groupSource(g) { return cstr(payload(groups[g]), 128); }

  function clips(g) {
    const h = groups[g];
    if (h === undefined) throw new SkinFormatError(`no ANM group ${g}`);
    const sub = first(h);
    const n = u32(sub);
    if (n > 4096) throw new SkinFormatError("too many clips");
    const base = sub + ((u32(sub + 4) & 0xc0000000) ? u32(sub + 8) : 8);
    return Array.from({ length: n }, (_, i) => {
      const p = pl.get(5) + u32(base + 4 * i);
      return {
        rec: p, name: cstr(p, 0x20), id: u32(p + 0x44), start: u32(p + 0x60), end: u32(p + 0x64),
        tracklist: pl.get(5) + u32(p + 0x80),
        // +0x5c blend-in frames, +0x6c frames per second (GC ZMovementBase::BlendInSpeed
        // 8014b368 = +0x5c / +0x6c), +0x70 total root (GROUND) translation (GC
        // ZPlayer::GetSettingsFromAnim 8014fbf4). Playtest fixes 2026-10-09.
        blendFrames: u32(p + 0x5c), fps: u32(p + 0x6c),
        flags: u32(p + 0x7c), // & 0x80: the clip has an AnimSound group (ZActor anim start)
        rootDelta: [view.getFloat32(p + 0x70, true), view.getFloat32(p + 0x74, true), view.getFloat32(p + 0x78, true)],
      };
    });
  }

  function tracks(clip) {
    if (clip._tracks) return clip._tracks;
    const tl = clip.tracklist;
    const count = u32(tl);
    if (count > 128) throw new SkinFormatError("too many tracks");
    const out = [];
    for (let i = 0; i < count; i += 1) {
      const t = pl.get(5) + u32(tl + 4 + 4 * i);
      const j = pl.get(4) + u32(t);
      bounds(view, t, 0x24, "track");
      const flags = view.getUint16(t + 10, true);
      const tk = {
        joint: bytes[j], jname: cstr(j + 1, 32),
        sT: view.getUint16(t + 4, true), sQ: view.getUint16(t + 6, true),
        dur: view.getUint16(t + 8, true), flags,
      };
      if (!(flags & 0x10)) tk.q = [u32(t + 0x0c), u32(t + 0x10), u32(t + 0x14)];
      if (!(flags & 0x08)) tk.t = [u32(t + 0x18), u32(t + 0x1c), u32(t + 0x20)];
      out.push(tk);
    }
    clip._tracks = out;
    return out;
  }

  function look(off, idx) { // FUN_004e5de0
    if (idx === 0) return 0;
    const b = pl.get(6) + off;
    bounds(view, b, 1, "packed array");
    const w = view.getInt8(b);
    if (!(w > 0 && w <= 24)) throw new SkinFormatError(`bad packed width ${w}`);
    const bit = (idx - 1) * w;
    const o = b + 1 + (bit >> 3);
    bounds(view, o, 3, "packed array");
    const v = ((bytes[o] << 16) | (bytes[o + 1] << 8) | bytes[o + 2]) * 256; // <<8 as unsigned
    return Math.floor(v / 2 ** (32 - (bit & 7) - w)) % (2 ** w);
  }

  const f3 = (o) => { bounds(view, o, 12, "float3"); return [view.getFloat32(o, true), view.getFloat32(o + 4, true), view.getFloat32(o + 8, true)]; };
  const f4 = (o) => { bounds(view, o, 16, "float4"); return [0, 4, 8, 12].map((k) => view.getFloat32(o + k, true)); };

  /** FUN_004e54c0: returns {T (or null), Q} at local tick `time`. */
  function sample(tk, time, loop = false) {
    const dur = tk.dur;
    time = Math.max(0, Number(time));
    time = loop && dur ? time % dur : Math.min(dur, time);
    const fi = Math.trunc(time);
    let T = null;
    if (tk.flags & 0x08) {
      T = f3(pl.get(11) + 12 * tk.sT);
    } else if (tk.flags & 0x04) {
      const [data, lk, tm] = tk.t;
      const k = look(lk, fi);
      const t0 = look(tm, k);
      T = f3(pl.get(8) + data + 12 * k);
      if (t0 !== dur) {
        const t1 = look(tm, k + 1);
        const T1 = f3(pl.get(8) + data + 12 * (k + 1));
        const u = (time - t0) / (t1 - t0);
        T = T.map((a, i) => a + (T1[i] - a) * u);
      }
    }
    let Q;
    if (tk.flags & 0x10) {
      Q = f4(pl.get(13) + 16 * tk.sQ);
    } else {
      const [data, lk, tm] = tk.q;
      const k = look(lk, fi);
      const t0 = look(tm, k);
      let rd;
      if (tk.flags & 0x01) {
        rd = (kk) => { const o = pl.get(7) + data + 8 * kk; bounds(view, o, 8, "Q16"); return [0, 2, 4, 6].map((x) => view.getInt16(o + x, true) / 32512); };
      } else if (tk.flags & 0x02) {
        rd = (kk) => { const o = pl.get(7) + data + 4 * kk; bounds(view, o, 4, "Q8"); return [0, 1, 2, 3].map((x) => view.getInt8(o + x) / 127); };
      } else {
        throw new SkinFormatError("track without Q encoding");
      }
      Q = rd(k);
      if (t0 !== dur) {
        const t1 = look(tm, k + 1);
        Q = interpolateQuaternion(Q, rd(k + 1), (time - t0) / (t1 - t0));
      }
    }
    return { T, Q };
  }

  function fit(fit1, row) { // tag-15 record, 28 bytes per PRM bone row
    if (!fit1 || !pl.has(15)) return null;
    const o = pl.get(15) + fit1 - 1 + 28 * row;
    bounds(view, o, 28, "fit record");
    const v = Array.from({ length: 7 }, (_, k) => view.getFloat32(o + 4 * k, true));
    return { q: v.slice(0, 4), t: v.slice(4, 7) };
  }

  return { groups, bindings, groupSource, clips, tracks, sample, fit, look };
}

// ---------------------------------------------------------------------------
// pose -> palette

/** Local (q, t) per bone row. Rows without a track keep the PRM +0x84 rest
 * local (INFERRED default). Tracked rows: sample, then q*fitQ, t+fitT
 * (FUN_00645c90). */
export function localPose(character, anm = null, clip = null, tick = 0, { loop = false, fit1 = 0 } = {}) {
  const { bones, gid2row } = character.skeleton;
  const loc = bones.map((b) => ({ q: b.q, t: b.t }));
  if (!anm || !clip) return loc;
  for (const tk of anm.tracks(clip)) {
    const row = gid2row.get(tk.joint);
    if (row === undefined) continue;
    if (bones[row].name !== tk.jname) throw new SkinFormatError(`track ${tk.jname} maps to bone ${bones[row].name}`);
    let { T, Q } = anm.sample(tk, tick, loop);
    if (!T) T = bones[row].t;
    const f = anm.fit(fit1, row);
    if (f) {
      Q = qmul(Q, f.q);
      T = T.map((a, i) => a + f.t[i]);
    }
    loc[row] = { q: Q, t: T };
  }
  return loc;
}

/** FUN_00659c40 hierarchy: G = Gp*R(q), T = Gp*t + Tp. Root rows (parent -1,
 * GROUND) are identity unless root=true (sampled GROUND = root motion). */
export function globalPose(character, loc, { root = false } = {}) {
  const { bones } = character.skeleton;
  const G = [];
  const T = [];
  bones.forEach((b, i) => {
    const R = quatToMat3(loc[i].q);
    if (b.parent < 0) {
      G.push(root ? R : [1, 0, 0, 0, 1, 0, 0, 0, 1]);
      T.push(root ? loc[i].t.slice() : [0, 0, 0]);
    } else {
      const p = b.parent;
      G.push(mul3(G[p], R));
      const v = mulVec(G[p], loc[i].t);
      T.push([v[0] + T[p][0], v[1] + T[p][1], v[2] + T[p][2]]);
    }
  });
  return { G, T };
}

/** Closed form of FUN_0065be00: M = G * Rrest^T, t = T - M*Trest.
 * Returns Float32Array(n*12): per bone three rows [M_r0 M_r1 M_r2 t_r]. */
export function bonePalette(character, { G, T }) {
  const { bones } = character.skeleton;
  const out = new Float64Array(bones.length * 12);
  bones.forEach((b, i) => {
    const M = mulABt(G[i], b.restR);
    const mt = mulVec(M, b.restT);
    for (let r = 0; r < 3; r += 1) {
      out.set([M[r * 3], M[r * 3 + 1], M[r * 3 + 2], T[i][r] - mt[r]], i * 12 + r * 4);
    }
  });
  return out;
}

/** Per-part local palette (concatenated runs), ready for a vec4[3*slots] uniform. */
export function partPalette(part, palette, out = new Float32Array(MAX_LOCAL_PALETTE * 12)) {
  part.remap.forEach((bone, slot) => {
    for (let k = 0; k < 12; k += 1) out[slot * 12 + k] = palette[bone * 12 + k];
  });
  return out;
}

export function poseCharacter(character, anm = null, clip = null, tick = 0, options = {}) {
  const loc = localPose(character, anm, clip, tick, options);
  if (options.root && options.rootFromStart && anm && clip) {
    // cutscene actors (opt-in): root (GROUND) motion relative to the clip's first frame, so the actor starts on its position marker
    const l0 = localPose(character, anm, clip, 0, options);
    const bones = character.skeleton.bones;
    bones.forEach((b, i) => { if (b.parent < 0) loc[i] = { ...loc[i], t: loc[i].t.map((v, k) => v - l0[i].t[k]) }; });
    // MC07: the clips keep GROUND at zero and carry the actor's absolute authoring position on the pelvis (root child), ~(1120, 3647, 330) for
    // every actor, so the markers' placement was lost and the actors drew thousands of units away. Take the frame-0 horizontal offset (and the
    // authoring floor height, options.originY = the markers' floor, else the clip's own) off such bones so the clip is relative to the marker.
    // INFERRED from the numbers: offset > 300 only occurs in MC07; every other scene keeps pelvis translations near the rest pose.
    bones.forEach((b, i) => {
      if (b.parent < 0 || bones[b.parent].parent >= 0) return;
      const rest = b.restT; const d = [l0[i].t[0] - rest[0], l0[i].t[1] - rest[1], l0[i].t[2] - rest[2]];
      if (Math.abs(d[0]) < 300 && Math.abs(d[2]) < 300) return;
      const dy = options.originY != null ? options.originY : d[1];
      loc[i] = { ...loc[i], t: [loc[i].t[0] - d[0], loc[i].t[1] - dy, loc[i].t[2] - d[2]] };
    });
  }
  const global = globalPose(character, loc, options);
  return { ...global, palette: bonePalette(character, global) };
}

/** CPU reference of FUN_00617400 / the vertex shader: p' = sum w_k (M_k p + t_k);
 * zero-weight lanes skipped. Returns {positions, normals} (Float64Array). */
export function skinPartCPU(part, palette) {
  const n = part.vertexCount;
  const P = new Float64Array(n * 3);
  const N = new Float64Array(n * 3);
  for (let i = 0; i < n; i += 1) {
    const p = [part.positions[3 * i], part.positions[3 * i + 1], part.positions[3 * i + 2]];
    const nn = [part.normals[3 * i], part.normals[3 * i + 1], part.normals[3 * i + 2]];
    for (let k = 0; k < 4; k += 1) {
      const w = part.weights[4 * i + k];
      if (w === 0) continue;
      const base = part.remap[part.selectors[4 * i + k] / 3] * 12;
      for (let r = 0; r < 3; r += 1) {
        const m = base + r * 4;
        P[3 * i + r] += w * (palette[m] * p[0] + palette[m + 1] * p[1] + palette[m + 2] * p[2] + palette[m + 3]);
        N[3 * i + r] += w * (palette[m] * nn[0] + palette[m + 1] * nn[1] + palette[m + 2] * nn[2]);
      }
    }
  }
  return { positions: P, normals: N };
}

/** Characters bound in this ANM (tag 14), one row per binding. */
export function listBoundCharacters(anm, prmBuffer) {
  const view = prmBuffer instanceof DataView ? prmBuffer : new DataView(prmBuffer);
  return anm.bindings().map((b) => ({
    ...b, skinned: isSkinnedEntry(view, b.entry), source: b.group < anm.groups.length ? anm.groupSource(b.group) : "?",
  }));
}
