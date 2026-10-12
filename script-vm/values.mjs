// Typed values and script objects shared by the VM and the native bindings.
//
// Stack / state-local slots are typed 8-byte cells in the original
// (Process_t data stack: {u32 value; u8 type}): 0 empty, 1 int, 2 float,
// 3 raw pointer (string literal / return address), 4 refcounted object.
// "Pop as int" / "pop as float" read the raw 32 bits (PC 0x5f4ff0 / 0x5f5020),
// so an int slot read as float is a bit reinterpretation, not a conversion.

export const T = Object.freeze({ EMPTY: 0, INT: 1, FLOAT: 2, PTR: 3, OBJ: 4 });

const cvb = new ArrayBuffer(4);
const cvi = new Int32Array(cvb);
const cvf = new Float32Array(cvb);
/** float -> raw int bits */
export function f2i(f) { cvf[0] = f; return cvi[0]; }
/** raw int bits -> float */
export function i2f(i) { cvi[0] = i; return cvf[0]; }
export const fround = Math.fround;

// Object handles: objects stored in the untyped instance data block are kept as
// 32-bit handles (the original stores the refcounted pointer). Handles start high
// so they do not collide with scene geom refs (small ints).
let nextHandle = 0x40000001;
const handles = new Map();
const finalizer = typeof FinalizationRegistry === 'function'
  ? new FinalizationRegistry(h => handles.delete(h)) : null;

export function objectFromHandle(h) {
  const r = handles.get(h | 0);
  return r ? (r.deref ? r.deref() : r) : null;
}

export class ScriptObject {
  constructor(cls) {
    this.cls = cls;
    this.handle = nextHandle++ | 0;
    handles.set(this.handle, typeof WeakRef === 'function' ? new WeakRef(this) : this);
    finalizer?.register(this, this.handle);
  }
  toString() { return `<${this.cls}#${(this.handle >>> 0).toString(16)}>`; }
}

export class StringObject extends ScriptObject {
  constructor(s = '') { super('String'); this.value = String(s); }
  toString() { return this.value; }
}

/** Value type (Position, Vector, PosDir, sCoverInfo, event payloads "UserType", ...): typed fields. */
export class StructObject extends ScriptObject {
  constructor(cls, fieldTypes = []) {
    super(cls);
    this.fieldTypes = fieldTypes;
    this.t = fieldTypes.map(ft => defaultSlotFor(ft).t);
    this.v = fieldTypes.map(ft => defaultSlotFor(ft).v);
  }
  get(i) {
    if (i < 0 || i >= this.t.length) return { t: T.INT, v: 0 };
    return { t: this.t[i], v: this.v[i] };
  }
  set(i, slot) {
    if (i < 0) return;
    while (this.t.length <= i) { this.t.push(T.INT); this.v.push(0); }
    this.t[i] = slot.t; this.v[i] = slot.v;
  }
  toString() {
    return `${this.cls}(${this.t.map((t, i) => showSlot({ t, v: this.v[i] })).join(', ')})`;
  }
}

/** Engine-side object: *_If interfaces (Engine_If, FFActor_If, ...), List_If, unknown statics. */
export class HostObject extends ScriptObject {
  constructor(cls, props = {}) { super(cls); Object.assign(this, props); }
}

const INTLIKE = new Set(['int', 'bool', 'long', 'sceneref', 'actorref', 'soundref', 'soundsetref', 'stateref', 'zgeomref', 'enum', 'animhandle']);
export function isIntType(name) { return INTLIKE.has(String(name).toLowerCase()); }
export function isFloatType(name) { const n = String(name).toLowerCase(); return n === 'float' || n === 'fuzzy'; }

export function defaultSlotFor(typeName) {
  if (isFloatType(typeName)) return { t: T.FLOAT, v: 0 };
  return { t: T.INT, v: 0 };
}

// Slot constructors for native return values
export const I = (n) => ({ t: T.INT, v: n | 0 });
export const F = (x) => ({ t: T.FLOAT, v: fround(x) });
export const O = (o) => ({ t: T.OBJ, v: o ?? null });
export const S = (s) => ({ t: T.OBJ, v: new StringObject(s) });
export const B = (b) => ({ t: T.INT, v: b ? 1 : 0 });

/** Raw int view of a slot. */
export function slotInt(t, v) {
  switch (t) {
    case T.INT: return v | 0;
    case T.FLOAT: return f2i(v);
    case T.OBJ: return v ? v.handle : 0;
    default: return typeof v === 'number' ? v | 0 : 0;
  }
}
/** Raw float view of a slot. */
export function slotFloat(t, v) {
  switch (t) {
    case T.FLOAT: return v;
    case T.INT: return i2f(v | 0);
    case T.OBJ: return i2f(v ? v.handle : 0);
    default: return typeof v === 'number' ? fround(v) : 0;
  }
}
export function slotObj(t, v) {
  if (t === T.OBJ) return v;
  if (t === T.INT) return objectFromHandle(v);
  if (t === T.PTR && typeof v === 'string') return new StringObject(v);
  return null;
}

/** Normalise a JS value returned by a native into a typed slot. */
export function toSlot(x) {
  if (x && typeof x === 'object' && 't' in x && 'v' in x && Object.keys(x).length === 2) return x;
  if (x instanceof ScriptObject) return O(x);
  if (typeof x === 'boolean') return B(x);
  if (typeof x === 'number') return F(x);
  if (typeof x === 'string') return S(x);
  if (x === null || x === undefined) return I(0);
  return I(0);
}

/** Human-readable form of a typed slot (for logs / traces). */
export function showSlot(s) {
  switch (s.t) {
    case T.INT: return String(s.v | 0);
    case T.FLOAT: return Number.isInteger(s.v) ? s.v.toFixed(1) : String(+s.v.toPrecision(7));
    case T.PTR: return JSON.stringify(String(s.v));
    case T.OBJ: return s.v === null ? 'null' : (s.v instanceof StringObject ? JSON.stringify(s.v.value) : String(s.v));
    default: return '-';
  }
}

/** Plain JS value of a slot (ints/floats as numbers, strings as strings, objects as objects). */
export function plain(s) {
  if (!s) return undefined;
  if (s.t === T.OBJ) return s.v instanceof StringObject ? s.v.value : s.v;
  if (s.t === T.PTR) return String(s.v);
  return s.v;
}
