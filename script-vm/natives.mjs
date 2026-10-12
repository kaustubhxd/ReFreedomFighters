// Native-binding registry for the SDL script VM.
//
// Every CALL_NATIVE / CALL_METHOD goes through NativeRegistry.invoke(). A binding is
// looked up, case-insensitively, as "<Class>.<method>" (class = the object's class:
// FFActor_If, Engine_If, Scene_If, FFTools_If, Item_If, List_If, Position, String, ...)
// and then as "*.<method>". Unbound natives log once and return typed defaults (int 0
// per return slot), so scripts keep running.
//
// Adding a native:
//   registry.bind('FFActor_If.PlayAnim', (c) => I(animId), { quiet: false });
//   c = { world, proc, self (target object), cls, method, hint, nargs, nret, args: [typed slots], isStatic }
//   helpers: c.int(i) c.float(i) c.obj(i) c.str(i) read argument i; return a typed slot
//   (I(n), F(x), O(obj), S(str), B(bool)), a plain value (number -> FLOAT, boolean -> INT,
//   string -> String object, ScriptObject -> object), or an array of those for nret > 1.
import { NATIVE_CATALOG } from './natives-catalog.mjs';
import {
  T, I, F, O, S, B, toSlot, slotInt, slotFloat, slotObj, plain, showSlot,
  StringObject, StructObject, HostObject, ScriptObject,
} from './values.mjs';

export { I, F, O, S, B };

function lc(s) { return String(s ?? '').toLowerCase(); }

/** String form of a slot, as the engine's String '=##Str' would print it. */
export function slotText(s) {
  if (!s) return '';
  if (s.t === T.PTR) return String(s.v);
  if (s.t === T.OBJ) return s.v instanceof StringObject ? s.v.value : (s.v ? String(s.v) : 'none');
  if (s.t === T.FLOAT) return String(+s.v.toPrecision(7));
  return String(s.v | 0);
}

export class NativeRegistry {
  constructor({ catalog = NATIVE_CATALOG, log = null, core = true } = {}) {
    this.bindings = new Map();
    this.quiet = new Set();
    this.catalog = new Map();
    for (const e of catalog) {
      const k = `${lc(e.cls)}.${lc(e.method)}`;
      if (!this.catalog.has(k)) this.catalog.set(k, e);
      if (!this.catalog.has(`*.${lc(e.method)}`)) this.catalog.set(`*.${lc(e.method)}`, e);
    }
    this.missing = new Map();   // key -> call count
    this.logFn = log;
    this.converters = new Map();
    if (core) bindCore(this);
  }
  log(world, s) { (this.logFn ?? world?.logFn ?? console.log)(s); }

  /** Bind "<Class>.<method>" or "*.<method>" (or a bare method name, same as "*.<method>"). */
  bind(pattern, fn, { quiet = false } = {}) {
    const dot = pattern.indexOf('.');
    const key = dot >= 0 ? lc(pattern) : `*.${lc(pattern)}`;
    this.bindings.set(key, fn);
    if (quiet) this.quiet.add(key);
    return this;
  }
  bindAll(map, opts) { for (const [k, fn] of Object.entries(map)) this.bind(k, fn, opts); return this; }
  has(cls, method) { return !!this._find(cls, method, null).fn; }

  _find(cls, method, staticCls) {
    const m = lc(method);
    for (const k of [`${lc(cls)}.${m}`, staticCls ? `${lc(staticCls)}.${m}` : null, `*.${m}`]) {
      if (k && this.bindings.has(k)) return { key: k, fn: this.bindings.get(k) };
    }
    return { key: null, fn: null };
  }
  isQuiet(call) { return call.quietKey ? this.quiet.has(call.quietKey) : false; }

  invoke(call) {
    const { key, fn } = this._find(call.cls, call.method, call.staticCls);
    call.quietKey = key;
    call.int = (i) => slotInt(call.args[i]?.t ?? T.INT, call.args[i]?.v ?? 0);
    call.float = (i) => slotFloat(call.args[i]?.t ?? T.INT, call.args[i]?.v ?? 0);
    call.obj = (i) => slotObj(call.args[i]?.t ?? T.INT, call.args[i]?.v ?? 0);
    call.str = (i) => slotText(call.args[i]);
    let out;
    if (fn) {
      call.implemented = true;
      out = fn(call);
    } else {
      call.implemented = false;
      const mk = `${call.cls}.${call.method}`;
      const n = this.missing.get(mk) ?? 0;
      this.missing.set(mk, n + 1);
      if (n === 0) {
        const cat = this.catalog.get(`${lc(call.cls)}.${lc(call.method)}`) ?? this.catalog.get(`*.${lc(call.method)}`);
        this.log(call.world, `[natives] unimplemented ${mk}(${call.args.map(showSlot).join(', ')}) args=${call.nargs} ret=${call.nret}${cat ? '' : ' (not in catalog)'} -> default`);
      }
      out = undefined;
    }
    const arr = Array.isArray(out) ? out : (out === undefined ? [] : [out]);
    const rets = [];
    for (let k = 0; k < call.nret; k++) rets.push(k < arr.length ? toSlot(arr[k]) : { t: T.INT, v: 0 });
    return rets;
  }

  /** CAST of an object, or to an object type (e.g. String). */
  bindConverter(typeName, fn) { this.converters.set(lc(typeName), fn); return this; }
  convert(world, proc, slot, typeName) {
    const fn = this.converters.get(lc(typeName));
    if (fn) return fn(slot, world, proc);
    world.warnOnce(`cast:${typeName}`, `[natives] no converter for CAST '${typeName}' from ${showSlot(slot)}; passing value through`);
    return slot;
  }

  /** Summary of unbound natives seen so far (name -> calls). */
  missingReport() { return [...this.missing.entries()].sort((a, b) => b[1] - a[1]); }
}

// ---- core bindings: value types, strings, clock, randomness, debug, messaging ----------------

function msgArgs(c, from, letters) {
  const out = [];
  for (let i = 0; i < letters.length; i++) {
    const a = c.args[from + i];
    if (!a) break;
    out.push(letters[i] === 'f' ? F(slotFloat(a.t, a.v)) : (a.t === T.OBJ ? a : I(slotInt(a.t, a.v))));
  }
  return out;
}

export function bindCore(r) {
  // value types (Position, Vector, PosDir, sCoverInfo, DieByForceInfo, UserType event payloads ...)
  r.bind('*.stackIdx', (c) => (c.self instanceof StructObject ? c.self.get(c.int(0)) : I(0)), { quiet: true });
  r.bind('*.=IdxConst', (c) => { if (c.self instanceof StructObject) c.self.set(c.int(1), c.args[0]); }, { quiet: true });
  r.bind('*.explodedAssignIO', (c) => {
    const o = c.self;
    if (o instanceof StructObject) c.args.forEach((a, i) => o.set(i, a));
    return O(o);
  }, { quiet: true });

  // String
  r.bind('String.=CStr', (c) => S(c.str(0)), { quiet: true });
  r.bind('String.=##Str', (c) => S(c.str(0) + c.str(1)), { quiet: true });
  r.bind('String.=Type', (c) => S(c.str(0)), { quiet: true });
  r.bind('String.!=', (c) => B(c.str(0).toLowerCase() !== c.str(1).toLowerCase()), { quiet: true });
  r.bind('String.==', (c) => B(c.str(0).toLowerCase() === c.str(1).toLowerCase()), { quiet: true });
  r.bindConverter('String', (s) => new StringObject(slotText(s)));
  r.bindConverter('Bool', (s) => I(s.t === T.OBJ ? (s.v instanceof StringObject ? (s.v.value !== '' ? 1 : 0) : (s.v ? 1 : 0)) : (slotInt(s.t, s.v) ? 1 : 0)));
  r.bindConverter('Int', (s) => I(s.t === T.OBJ && s.v instanceof StringObject ? parseInt(s.v.value, 10) || 0 : slotInt(s.t, s.v)));
  r.bindConverter('Float', (s) => F(s.t === T.OBJ && s.v instanceof StringObject ? parseFloat(s.v.value) || 0 : slotFloat(s.t, s.v)));

  // Engine_If: clock, randomness, debug output
  const now = (c) => F(c.world.time);
  r.bind('*.GetTime', now, { quiet: true });
  const rnd = (c) => (c.world.random ?? Math.random)();
  r.bind('*.random', (c) => F(rnd(c)), { quiet: true });       // Engine_If.random (hint 2): [0,1)
  r.bind('*.Random11', (c) => F(rnd(c) * 2 - 1), { quiet: true });
  r.bind('*.print', (c) => { c.world.log(`[print ${c.proc.name}] ${c.str(0)}`); });

  // List_If (ZGEOMREF lists wired by the level, e.g. zlFirstSoldiers)
  r.bind('List_If.GetCount', (c) => I(c.self?.items?.length ?? 0), { quiet: true });
  r.bind('List_If.GetRefNr', (c) => I(c.self?.items?.[c.int(0)] ?? 0), { quiet: true });

  // Messages between scene objects: SendCommand(target, "Msg"[, payload...]); suffix = payload types
  for (const [name, letters] of Object.entries({ SendCommand: '', SendCommand_i: 'i', SendCommand_r: 'r', SendCommand_ri: 'ri', SendCommand_rf: 'rf', SendCommand_rff: 'rff' })) {
    r.bind(`*.${name}`, (c) => {
      const target = c.int(0);
      c.world.send(target, c.str(1), msgArgs(c, 2, letters), c.proc);
    });
  }
}

/**
 * Optional simulation bindings for running scripts without the game engine:
 * movement natives finish after `pathTime` seconds by posting PATHFINISHED to the caller,
 * animations report as finished, and sounds report a fixed duration.
 */
export function bindActorSimulation(r, { pathTime = 1.0, soundTime = 2.0, animTime = 1.0 } = {}) {
  const move = (c) => { c.world.after(pathTime, () => { if (!c.proc.terminated) c.proc.post('PATHFINISHED', [0]); }); };
  for (const m of ['MoveToLocation', 'MoveToPosition', 'MoveToPositionDir', 'MoveToPositionDirPitched', 'MoveToPositionPitched', 'MoveToRef']) r.bind(`FFActor_If.${m}`, move);
  // Animations get increasing ids; the engine reports the end with LNKANIMEND(id) (Generic keeps the
  // highest finished id in d[0x50] and waits with "PlayAnim id <= lastFinished").
  const anim = (ends) => (c) => {
    const p = c.proc; p.simAnimId = (p.simAnimId ?? 0) + 1; const id = p.simAnimId;
    if (ends) c.world.after(animTime, () => { if (!p.terminated) p.post('LNKANIMEND', [id]); });
    return I(id);
  };
  for (const m of ['PlayAnim', 'PlayAnimInterpolated', 'StopRagdollPlayAnim']) r.bind(`FFActor_If.${m}`, anim(true));
  r.bind('FFActor_If.PlayAnimLoop', anim(false));
  r.bind('FFActor_If.PlaySound_Enum_On_Screen', () => F(soundTime));
  r.bind('FFActor_If.PlaySound_Enum_GetTime', () => F(soundTime));
  return r;
}

export { NATIVE_CATALOG, plain, HostObject, ScriptObject };
