// Freedom Fighters .ppo (compiled SDL script) loader.
//
// Pure parsing: works in the browser and in Node (no fs here; see fsload.mjs).
// Format reference: notes/ppo-scripts.md, formats/opcodes.md, and the
// evidence records in script-vm/README.md (state table, handler records,
// host/value object tables, data init image, type definitions).
//
// Layout of one file:
//   prefix   : decl line\0, 1-2 "*.sdl"\0 paths (parent first), u32 nVars,
//              nVars x {u32 kind, u32 x, u32 dataOffset, name\0, type\0, u8, extra\0, u32}
//   header   : u32 A, f32 1.0, u32, u32, 4 x u16, 16 bytes, 16 bytes,
//              6 x u32 h38 (codeBase, eventDataOff, handlerFlagOff, ?, codeBase, dataStart),
//              12 x u32 table offsets into the blob (o68 .. o90, blobSize)
//   blob     : regions addressed by the table offsets
//   trailer  : u32 nTypeDefs, i32 typeBase, nTypeDefs x {u32 size, u32 n, n x u32 fieldTypeStrId}

const TAB_NAMES = ['o68', 'o6c', 'o70', 'o74', 'o78', 'o7c', 'o80', 'o84', 'o88', 'o8c', 'o90', 'size'];

/** Little-endian reader that returns 0 for bytes past the end (zgf.py strips trailing NULs). */
class Reader {
  constructor(bytes, pos = 0) {
    this.b = bytes;
    this.p = pos;
  }
  byte(at) { return at < this.b.length ? this.b[at] : 0; }
  u8() { return this.byte(this.p++); }
  u16() { const v = this.byte(this.p) | (this.byte(this.p + 1) << 8); this.p += 2; return v; }
  i16() { const v = this.u16(); return v & 0x8000 ? v - 0x10000 : v; }
  u32() { const v = (this.byte(this.p) | (this.byte(this.p + 1) << 8) | (this.byte(this.p + 2) << 16) | (this.byte(this.p + 3) << 24)) >>> 0; this.p += 4; return v; }
  i32() { return this.u32() | 0; }
  f32() { const u = this.u32(); F32_U32[0] = u; return F32[0]; }
  cstr() {
    let e = this.p;
    while (e < this.b.length && this.b[e] !== 0) e++;
    const s = latin1(this.b, this.p, e);
    this.p = e + 1;
    return s;
  }
}
const F32_BUF = new ArrayBuffer(4);
const F32 = new Float32Array(F32_BUF);
const F32_U32 = new Uint32Array(F32_BUF);

function latin1(b, s, e) {
  let out = '';
  for (let i = s; i < e; i++) out += String.fromCharCode(b[i]);
  return out;
}

export function baseName(p) {
  const s = String(p).replace(/\\/g, '/');
  const f = s.slice(s.lastIndexOf('/') + 1);
  return f.replace(/\.(ppo|sdl)$/i, '');
}

function findHeader(b) {
  // The header is located by the 1.0f version float; validate the blob size so a
  // stray 0x3f800000 in the prefix is skipped (same rule as decoders/ppo_dis.py).
  for (let k = 4; k + 200 < b.length; k++) {
    if (b[k] !== 0 || b[k + 1] !== 0 || b[k + 2] !== 0x80 || b[k + 3] !== 0x3f) continue;
    const o = k - 4;
    const r = new Reader(b, o + 4 + 4 + 4 + 4 + 8 + 32 + 24 + 44);
    const size = r.u32();
    const blob = o + 0x80;
    if (size > 0 && blob + size <= b.length) return o;
  }
  throw new Error('ppo: version header (1.0f) not found');
}

function parsePrefix(b, end) {
  const r = new Reader(b, 0);
  // decl line, parent .sdl path (empty for base scripts), own .sdl path
  const decl = r.cstr();
  const parentSdl = r.cstr();
  const ownSdl = r.cstr();
  const sdlPaths = [parentSdl, ownSdl];
  const vars = [];
  let ok = true;
  const n = r.u32();
  for (let i = 0; i < n && ok; i++) {
    const kind = r.u32();
    const x = r.u32();
    const offset = r.u32();
    const name = r.cstr();
    const type = r.cstr();
    const flag = r.u8();
    const extra = r.cstr();
    const tail = r.u32();
    vars.push({ name, type, offset, kind, x, flag, listType: extra || null, tail });
    if (r.p > end) ok = false;
  }
  // a u32 equal to header field A follows the records (serialized size)
  const sizeField = r.u32();
  const prefixOk = ok && r.p === end;
  return { decl, sdlPaths, vars: prefixOk ? vars : vars.filter(v => v.offset < 0x8000), prefixOk, sizeField };
}

function parseStateTable(b, at, sizeLimit) {
  // VMImageInfo_t::MasterStateRecord_t::initializeFromBlock (GC 801c9510):
  // u32 size, u32 a, u32 nStates, u32 firstStateId, u32 nRecords, u32 recordsSize, u32 varBlobSize,
  // addrs[n] u32, ids[n] u32, recordOffs[nRecords] u32, (entry,exit)[n] i32 pairs,
  // nameStrId[n] u16, varInitOff[n] u16, parentIdx[n] i16, varBlob, handler records.
  const r = new Reader(b, at);
  const size = r.u32();
  const a = r.u32();
  const n = r.u32();
  const firstStateId = r.u32();
  const nRecords = r.u32();
  const recordsSize = r.u32();
  const varBlobSize = r.u32();
  if (n > 4096 || nRecords > 4096) throw new Error('ppo: implausible state table');
  const addrs = []; for (let i = 0; i < n; i++) addrs.push(r.u32());
  const ids = []; for (let i = 0; i < n; i++) ids.push(r.u32());
  const recOffs = []; for (let i = 0; i < nRecords; i++) recOffs.push(r.u32());
  const pairs = []; for (let i = 0; i < n; i++) pairs.push([r.i32(), r.i32()]);
  const nameIds = []; for (let i = 0; i < n; i++) nameIds.push(r.u16());
  const varOffs = []; for (let i = 0; i < n; i++) varOffs.push(r.u16());
  const parents = []; for (let i = 0; i < n; i++) parents.push(r.i16());
  const varBlob = r.p;
  const recBase = varBlob + varBlobSize;
  const records = recOffs.map((off) => {
    const rr = new Reader(b, recBase + off);
    const key = rr.u32();
    const cnt = rr.u16();
    const evIds = [];
    for (let i = 0; i < cnt; i++) evIds.push(rr.u16());
    rr.p = recBase + off + ((6 + 2 * cnt + 3) & ~3);
    const events = evIds.map(id => [id, rr.u32()]);
    return { key, events };
  });
  const states = addrs.map((addr, i) => {
    const vr = new Reader(b, varBlob + varOffs[i]);
    const nv = vr.u16();
    const varTypes = [];
    for (let k = 0; k < nv; k++) varTypes.push(vr.u16());
    return {
      index: i, addr, id: ids[i], nameId: nameIds[i], parent: parents[i],
      entry: pairs[i][0], exit: pairs[i][1], varTypes, record: i < records.length ? i : -1,
    };
  });
  return { size, a, firstStateId, states, records, recordsSize, sizeOk: size <= sizeLimit };
}

/**
 * Parse one .ppo file.
 * @param {Uint8Array} bytes
 * @param {string} relPath path relative to the scripts dir (for names / diagnostics)
 */
export function parsePpo(bytes, relPath = '') {
  const b = bytes instanceof Uint8Array ? bytes : new Uint8Array(bytes);
  const o = findHeader(b);
  const pre = parsePrefix(b, o);
  const r = new Reader(b, o);
  const header = {
    a: r.u32(), version: r.f32(), u2: r.u32(), u3: r.u32(),
    w: [r.u16(), r.u16(), r.u16(), r.u16()],
  };
  header.blob16a = Array.from(b.subarray(r.p, r.p + 16)); r.p += 16;
  header.blob16b = Array.from(b.subarray(r.p, r.p + 16)); r.p += 16;
  const h38 = []; for (let i = 0; i < 6; i++) h38.push(r.u32());
  const tabs = {}; for (const t of TAB_NAMES) tabs[t] = r.u32();
  header.h38 = h38; header.tabs = tabs;
  const blobStart = o + 0x80;
  if (r.p !== blobStart) throw new Error('ppo: header size mismatch');
  const blob = b.subarray(blobStart, blobStart + tabs.size);
  const B = (off) => new Reader(blob, off);

  const ownPath = B(tabs.o68).cstr();
  // vtable (o6c): u32 count, count x absolute code offsets (Process_t::resolveVirtualTableIndex)
  const vr = B(tabs.o6c); const nv = vr.u32();
  const vtable = []; for (let i = 0; i < nv; i++) vtable.push(vr.u32());
  const stateTable = parseStateTable(blob, tabs.o70, tabs.size);
  // o74 / o78: u32 first, u32 count, count x {u16 strId, u16 typeIndex}
  const pairTable = (off) => {
    const t = B(off); const first = t.u32(); const count = t.u32();
    const entries = []; for (let i = 0; i < count; i++) entries.push({ strId: t.u16(), typeIndex: t.u16() });
    return { first, entries };
  };
  const eventDecls = pairTable(tabs.o74);
  const typeNames = pairTable(tabs.o78);
  // o7c strings: u32 firstId, u32 count, u32 offs[count], chars
  const sr = B(tabs.o7c); const firstId = sr.u32(); const count = sr.u32();
  const offs = []; for (let i = 0; i < count; i++) offs.push(sr.u32());
  const chars = sr.p;
  const strings = offs.map(x => B(chars + x).cstr());
  // o80 host interface objects / o84 value objects: u32 count, (u32 dataOffset, u16 typeStrId) records
  const objTable = (off) => {
    const t = B(off); const n = t.u32(); const out = [];
    if (n > 4096) return out;
    for (let i = 0; i < n; i++) out.push({ offset: t.u32(), typeId: t.u16() });
    return out;
  };
  const hostObjects = objTable(tabs.o80);
  const valueObjects = objTable(tabs.o84);
  // o8c: u32 size, initial image of this file's slice of the instance data block
  const dr = B(tabs.o8c); const dsz = dr.u32();
  const dataInit = blob.slice(dr.p, dr.p + dsz);
  // o90: u32 size, code
  const cr = B(tabs.o90); const csz = cr.u32();
  const code = blob.slice(cr.p, cr.p + csz);
  // trailer: type definitions (VMImageInfo_t::fromDisk reads +0x12e count, +0x12a base)
  const tr = new Reader(b, blobStart + tabs.size);
  const nTypes = tr.u32(); const typeBase = tr.i32();
  const typeDefs = [];
  if (nTypes < 1024) {
    for (let i = 0; i < nTypes; i++) {
      const size = tr.u32(); const n = tr.u32(); const fields = [];
      for (let k = 0; k < n && k < 256; k++) fields.push(tr.u32() & 0xffff);
      typeDefs.push({ size, fields });
    }
  }

  const name = baseName(relPath || ownPath);
  const parentName = pre.sdlPaths[0] ? baseName(pre.sdlPaths[0]) : null;
  return {
    relPath, name, ownPath, decl: pre.decl, sdlPaths: pre.sdlPaths, parentName,
    vars: pre.vars, prefixOk: pre.prefixOk,
    header, codeBase: h38[0], eventDataOff: h38[1], handlerFlagOff: h38[2], dataStart: h38[5],
    vtable, stateTable, eventDecls, typeNames,
    strings: { first: firstId, list: strings },
    hostObjects, valueObjects, dataInit, code,
    typeDefs: { base: typeBase, defs: typeDefs },
  };
}

/**
 * A linked program: one script plus its parent chain, with global strings,
 * code addresses, states and handler records resolved across the chain.
 */
export class Program {
  constructor(files) {
    // files: root first ... most-derived last
    this.files = files;
    this.file = files[files.length - 1];
    this.name = this.file.name;
    this.chainNames = files.map(f => f.name);
    // Global code space: files are contiguous (child codeBase == parent codeBase + parent code length).
    let end = 0;
    for (const f of files) end = Math.max(end, f.codeBase + f.code.length);
    this.code = new Uint8Array(end);
    this.codeView = new DataView(this.code.buffer);
    for (const f of files) this.code.set(f.code, f.codeBase);
    this.codeEnd = end;
    // Strings (global ids)
    this.strings = new Map();
    this.stringIds = new Map(); // lowercase name -> id (most-derived wins)
    for (const f of files) {
      f.strings.list.forEach((s, i) => {
        const id = f.strings.first + i;
        this.strings.set(id, s);
        this.stringIds.set(s.toLowerCase(), id);
      });
    }
    // vtable: the most-derived file's table (CALL fn#k is virtual)
    this.vtable = this.file.vtable;
    // States across the chain, by absolute address
    this.states = [];
    this.stateByAddr = new Map();
    this.handlerKeys = new Map(); // record key address -> Map(eventId -> addr)
    this.unknownEventIds = new Set();
    for (const f of files) {
      const prefix = f.name + '.';
      const names = [...f.strings.list.entries()]
        .filter(([, s]) => s.startsWith(prefix)).map(([i]) => f.strings.first + i);
      for (const st of f.stateTable.states) {
        const nm = this.strings.get(st.nameId) ?? null;
        const s = {
          ...st, file: f.name, name: nm, globalIndex: this.states.length,
          localBase: this.states.length - st.index, varTypeNames: [],
        };
        s.varTypeNames = st.varTypes.map(t => this.strings.get(t) ?? `type#${t}`);
        this.states.push(s);
        this.stateByAddr.set(st.addr, s);
      }
      void names;
      const uk = f.strings.list.findIndex(s => s === 'UnknownEvent');
      if (uk >= 0) this.unknownEventIds.add(f.strings.first + uk);
      f.stateTable.records.forEach((rec, i) => {
        const m = new Map();
        for (const [id, addr] of rec.events) m.set(id, addr);
        this.handlerKeys.set(rec.key, m);
        if (i < f.stateTable.states.length) {
          const s = this.stateByAddr.get(f.stateTable.states[i].addr);
          if (s) s.handlers = m;
        }
      });
    }
    for (const s of this.states) {
      if (s.parent >= 0) s.parentState = this.states[s.localBase + s.parent] ?? null;
    }
    // Instance data layout
    let dataSize = 0;
    for (const f of files) dataSize = Math.max(dataSize, f.dataStart + f.dataInit.length);
    this.dataSize = dataSize;
    this.eventDataOff = this.file.eventDataOff;
    this.handlerFlagOff = this.file.handlerFlagOff;
    this.hostObjects = files.flatMap(f => f.hostObjects.map(o => ({ ...o, type: this.strings.get(o.typeId) ?? `type#${o.typeId}` })));
    this.valueObjects = files.flatMap(f => f.valueObjects.map(o => ({ ...o, type: this.strings.get(o.typeId) ?? `type#${o.typeId}` })));
    this.vars = files.flatMap(f => f.vars);
    // Type definitions (event payloads / user types), global index across the chain
    this.typeDefs = [];
    for (const f of files) {
      const base = f.typeDefs.base < 0 ? this.typeDefs.length : f.typeDefs.base;
      f.typeDefs.defs.forEach((d, i) => {
        this.typeDefs[base + i] = { ...d, fieldTypes: d.fields.map(t => this.strings.get(t) ?? `type#${t}`) };
      });
    }
    this.typeIndexByName = new Map();
    for (const f of files) for (const e of f.typeNames.entries) {
      const n = this.strings.get(e.strId);
      if (n) this.typeIndexByName.set(n.toLowerCase(), e.typeIndex);
    }
    this.eventTypeByName = new Map();
    for (const f of files) for (const e of f.eventDecls.entries) {
      const n = this.strings.get(e.strId);
      if (n) this.eventTypeByName.set(n.toLowerCase(), e.typeIndex);
    }
  }
  string(id) { return this.strings.get(id); }
  stringId(name) { return this.stringIds.get(String(name).toLowerCase()); }
  /** Event id used by handler records: string id of the name; 0 when the chain does not know it. */
  eventId(name) { return this.stringId(name) ?? 0; }
  /** Field type names of the payload struct for an event name, or null. */
  eventFields(name) {
    const ti = this.eventTypeByName.get(String(name).toLowerCase());
    if (ti === undefined) return null;
    return this.typeDefs[ti]?.fieldTypes ?? null;
  }
  typeFields(typeName) {
    const ti = this.typeIndexByName.get(String(typeName).toLowerCase());
    if (ti === undefined) return null;
    return this.typeDefs[ti]?.fieldTypes ?? null;
  }
  fileForAddr(addr) {
    for (let i = this.files.length - 1; i >= 0; i--) {
      const f = this.files[i];
      if (addr >= f.codeBase && addr < f.codeBase + f.code.length) return f;
    }
    return null;
  }
  stateName(addr) {
    const s = this.stateByAddr.get(addr);
    return s ? (s.name ?? `${s.file}.state${s.index}`) : `@0x${(addr >>> 0).toString(16)}`;
  }
  /** Look up a handler under a record key (HANDLER_JMP); falls back to the UnknownEvent entry. */
  handlerFor(key, eventId) {
    const m = this.handlerKeys.get(key);
    if (!m) return -1;
    return lookupHandler(m, eventId, this.unknownEventIds);
  }
}

export function lookupHandler(m, eventId, unknownIds) {
  if (!m) return -1;
  if (eventId && m.has(eventId)) return m.get(eventId);
  for (const u of unknownIds) if (m.has(u)) return m.get(u);
  if (m.has(0)) return m.get(0);
  return -1;
}

/**
 * Script library: a set of parsed .ppo files looked up case-insensitively by base name
 * (ZGFs mix AllLevels/Alllevels/alllevels folders).
 */
export class ScriptLibrary {
  constructor() {
    this.byName = new Map();
    this.byPath = new Map();
    this.programs = new Map();
    this.errors = [];
  }
  /** Add one file; relPath like "C01A/C01A_Jones.ppo". Returns the parsed file. */
  add(relPath, bytes) {
    const f = parsePpo(bytes, relPath);
    const key = f.name.toLowerCase();
    if (!this.byName.has(key)) this.byName.set(key, f);
    this.byPath.set(relPath.replace(/\\/g, '/').toLowerCase(), f);
    return f;
  }
  get(nameOrPath) {
    const s = String(nameOrPath).replace(/\\/g, '/').toLowerCase();
    return this.byPath.get(s) ?? this.byName.get(baseName(s).toLowerCase()) ?? null;
  }
  /** Linked program for a script name or relative path; resolves the parent chain. */
  program(nameOrPath) {
    const leaf = this.get(nameOrPath);
    if (!leaf) throw new Error(`ppo: script not found: ${nameOrPath}`);
    const key = leaf.relPath.toLowerCase();
    if (this.programs.has(key)) return this.programs.get(key);
    const chain = [leaf];
    const seen = new Set([leaf.name.toLowerCase()]);
    let p = leaf.parentName;
    while (p) {
      const pf = this.byName.get(p.toLowerCase());
      if (!pf) throw new Error(`ppo: parent ${p} of ${chain[0].name} not found`);
      if (seen.has(pf.name.toLowerCase())) throw new Error(`ppo: inheritance cycle at ${p}`);
      seen.add(pf.name.toLowerCase());
      chain.unshift(pf);
      p = pf.parentName;
    }
    const prog = new Program(chain);
    this.programs.set(key, prog);
    return prog;
  }
}
