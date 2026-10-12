// SDL script VM: runs the game's compiled .ppo scripts.
//
// Model (evidence in README.md; decompile notes in decoders/re/vm_fixed.c):
//   Process        = Process_t (one script instance), runProcess = PC 0x5f56f0
//   switchContext  = PC 0x5f9130 / GC Process_t::switchContext
//   handleEvents   = PC 0x5f4ac0 / GC Process_t::handleEventsForProcess
//   World.tick     = FreedomScriptScheduler_t::scheduleProcesses (PC 0x550f30): every live
//                    process runs once per frame with an instruction quota of 50.
import { lookupHandler } from './loader.mjs';
import {
  T, f2i, i2f, fround, slotInt, slotFloat, slotObj, toSlot, showSlot, plain,
  ScriptObject, StringObject, StructObject, HostObject, objectFromHandle, isFloatType, isIntType,
} from './values.mjs';
import { decodeAt } from './opcodes.mjs';

// ctx+0xac run flags
export const FL = Object.freeze({ NESTED: 0x0800, LOCKED: 0x1000, RUNNING: 0x2000, TERMINATED: 0x4000, EVENT: 0x8000 });
// low nibble run states
export const RS = Object.freeze({ CTOR: 0, RUN: 1, SLEEP: 2, SLEEP_CONT: 3, WAIT: 4, WAIT_TIMEOUT: 5 });

const DEFAULT_QUOTA = 50;

export class VMError extends Error {}

export class Process {
  constructor(world, prog, opts = {}) {
    this.world = world;
    this.prog = prog;
    this.id = opts.id ?? 0;
    this.name = opts.name ?? prog.name;
    this.ref = opts.ref ?? null;
    // instance data block (untyped 4-byte cells addressed by byte offset)
    const size = Math.max(16, (prog.dataSize + 3) & ~3);
    this.dataBytes = new Uint8Array(size);
    for (const f of prog.files) this.dataBytes.set(f.dataInit, f.dataStart);
    this.data = new DataView(this.dataBytes.buffer);
    this.dataObj = new Map();
    // stacks
    this.st = []; this.sv = [];       // data stack: types / values
    this.cs = [];                     // call stack: return ips and saved fps
    this.fp = 0;
    this.ip = prog.file.codeBase;     // constructor = first byte of the most-derived file's code
    // state-local typed slots
    this.gt = []; this.gv = [];
    this.stateChain = [];
    // run control
    this.flags = 0;
    this.runState = RS.CTOR;
    this.wake = 0;
    this.quota = opts.quota ?? world.quota ?? DEFAULT_QUOTA;
    this.startState = -1;             // ctx+0x12: start state, and pending state during event handling
    this.state = -1; this.entry = -1; this.exit = -1;
    this.handlers = null; this.unknownAddr = -1;
    this.queue = [];
    this.curEvent = null; this.curEventId = 0;
    this.namedWait = null;
    this.instructions = 0;
    this.lastError = null;
    this._initObjects(opts);
  }

  _initObjects(opts) {
    const w = this.world;
    // o80 host interfaces (Engine_If, FFActor_If, ...)
    for (const h of this.prog.hostObjects) {
      const obj = h.type === 'String'
        ? new StringObject(opts.strings?.[h.offset] ?? '')
        : w.makeHostObject(h.type, this, { offset: h.offset });
      this.storeObjData(h.offset, obj);
    }
    // o84 value objects (Position, PosDir, sCoverInfo ...)
    for (const v of this.prog.valueObjects) this.storeObjData(v.offset, w.makeObject(this.prog, v.type));
    // exported variables: lists are List_If host objects; others are ints/floats set by the level (GMS)
    for (const v of this.prog.vars) {
      if (v.listType) {
        const items = opts.lists?.[v.name] ?? [];
        this.storeObjData(v.offset, w.makeHostObject(v.listType, this, { name: v.name, items: [...items] }));
      }
    }
    for (const [name, value] of Object.entries(opts.vars ?? {})) this.setVar(name, value);
  }

  /** Set an exported script variable by name (e.g. rCareTaker) to a number (int unless FLOAT). */
  setVar(name, value) {
    const v = this.prog.vars.find(x => x.name.toLowerCase() === String(name).toLowerCase());
    if (!v) throw new VMError(`${this.name}: no exported variable ${name}`);
    if (value instanceof ScriptObject) this.storeObjData(v.offset, value);
    else if (/float/i.test(v.type)) this.data.setFloat32(v.offset, value, true);
    else this.data.setInt32(v.offset, value | 0, true);
  }
  getVar(name) {
    const v = this.prog.vars.find(x => x.name.toLowerCase() === String(name).toLowerCase());
    if (!v) return undefined;
    if (this.dataObj.has(v.offset)) return this.dataObj.get(v.offset);
    return /float/i.test(v.type) ? this.data.getFloat32(v.offset, true) : this.data.getInt32(v.offset, true);
  }

  get stateName() { return this.state === -1 ? null : this.prog.stateName(this.state); }
  get terminated() { return (this.flags & FL.TERMINATED) !== 0; }

  // ---- data stack ------------------------------------------------------------------
  push(t, v) { this.st.push(t); this.sv.push(v); }
  pushI(v) { this.st.push(T.INT); this.sv.push(v | 0); }
  pushF(v) { this.st.push(T.FLOAT); this.sv.push(fround(v)); }
  pushO(o) { this.st.push(T.OBJ); this.sv.push(o ?? null); }
  popSlot() {
    if (!this.st.length) throw new VMError('data stack underflow');
    return { t: this.st.pop(), v: this.sv.pop() };
  }
  popI() { if (!this.st.length) throw new VMError('data stack underflow'); return slotInt(this.st.pop(), this.sv.pop()); }
  popF() { if (!this.st.length) throw new VMError('data stack underflow'); return slotFloat(this.st.pop(), this.sv.pop()); }
  popO() { if (!this.st.length) throw new VMError('data stack underflow'); return slotObj(this.st.pop(), this.sv.pop()); }
  peekType() { return this.st.length ? this.st[this.st.length - 1] : T.EMPTY; }

  // ---- variables (u16 operand encoding, opcodes.md 2.3) ------------------------------
  // <0x8000 data offset; 0xC000+ stack slot fp+(int16)v; 0x8000-0xBFFF state-local g[0x3fff-(v&0x3fff)]
  _slot(v) {
    if (v & 0x4000) {
      const i = this.fp + (v - 0x10000);
      if (i < 0 || i >= this.st.length) throw new VMError(`frame slot fp${v - 0x10000} out of range`);
      return [this.st, this.sv, i];
    }
    const i = 0x3fff - (v & 0x3fff);
    while (this.gt.length <= i) { this.gt.push(T.INT); this.gv.push(0); }
    return [this.gt, this.gv, i];
  }
  rI(v) {
    if (v < 0x8000) return this.data.getInt32(v, true);
    const [ta, va, i] = this._slot(v); return slotInt(ta[i], va[i]);
  }
  rF(v) {
    if (v < 0x8000) return this.data.getFloat32(v, true);
    const [ta, va, i] = this._slot(v); return slotFloat(ta[i], va[i]);
  }
  rO(v) {
    if (v < 0x8000) return this.loadObjData(v);
    const [ta, va, i] = this._slot(v); return slotObj(ta[i], va[i]);
  }
  wI(v, x) {
    if (v < 0x8000) { this.data.setInt32(v, x | 0, true); this.dataObj.delete(v); return; }
    const [ta, va, i] = this._slot(v); ta[i] = T.INT; va[i] = x | 0;
  }
  wF(v, x) {
    if (v < 0x8000) { this.data.setFloat32(v, x, true); this.dataObj.delete(v); return; }
    const [ta, va, i] = this._slot(v); ta[i] = T.FLOAT; va[i] = fround(x);
  }
  wO(v, o) {
    if (v < 0x8000) { this.storeObjData(v, o); return; }
    const [ta, va, i] = this._slot(v); ta[i] = T.OBJ; va[i] = o ?? null;
  }
  storeObjData(off, o) {
    this.data.setInt32(off, o ? o.handle : 0, true);
    if (o) this.dataObj.set(off, o); else this.dataObj.delete(off);
  }
  loadObjData(off) {
    const h = this.data.getInt32(off, true);
    const o = this.dataObj.get(off);
    if (o && o.handle === h) return o;
    return h ? objectFromHandle(h) : null;
  }

  // ---- state contexts -----------------------------------------------------------------
  _chainOf(s) {
    const out = [];
    for (let c = s; c; c = c.parentState) out.unshift(c);
    return out;
  }
  /** VMImageInfo_t::initNewStateContext + MasterStateRecord_t::updateStateVars (see README: inferred). */
  _initState(addr) {
    const s = this.prog.stateByAddr.get(addr);
    if (!s) {
      this.world.warnOnce(`state@${addr}`, `${this.name}: SETSTATE to unknown state address 0x${addr.toString(16)}`);
      this.state = addr; this.entry = -1; this.exit = -1; this.handlers = null; this.unknownAddr = -1;
      this.stateChain = []; this.gt = []; this.gv = [];
      return;
    }
    const newChain = this._chainOf(s);
    let k = 0;
    while (k < newChain.length && k < this.stateChain.length && newChain[k] === this.stateChain[k]) k++;
    let keep = 0;
    for (let i = 0; i < k; i++) keep += newChain[i].varTypeNames.length;
    this.gt.length = Math.min(this.gt.length, keep); this.gv.length = this.gt.length;
    while (this.gt.length < keep) { this.gt.push(T.INT); this.gv.push(0); }
    for (let i = k; i < newChain.length; i++) {
      for (const tn of newChain[i].varTypeNames) {
        const lt = tn.toLowerCase();
        if (isFloatType(lt)) { this.gt.push(T.FLOAT); this.gv.push(0); }
        else if (this.world.isScalarType(lt)) { this.gt.push(T.INT); this.gv.push(0); }
        else { this.gt.push(T.OBJ); this.gv.push(this.world.makeObject(this.prog, tn)); }
      }
    }
    this.stateChain = newChain;
    this.state = addr; this.entry = s.entry; this.exit = s.exit;
    this.handlers = s.handlers ?? null;
    this.unknownAddr = lookupHandler(this.handlers, 0, this.prog.unknownEventIds);
  }

  /** Process_t::switchContext(state, run). */
  switchContext(addr, run) {
    if (this.flags & FL.NESTED) this.world.warnOnce(`nested-switch:${this.name}`, `${this.name}: state switch inside an entry/exit block`);
    if (this.flags & (FL.EVENT | FL.NESTED)) { this.startState = addr; return; }
    const from = this.state;
    if (this.exit !== -1) {
      this.ip = this.exit;
      if (run) this._runNested();
    }
    this.st.length = 0; this.sv.length = 0; this.cs.length = 0; this.fp = 0;
    if (addr !== this.state) this._initState(addr);
    this.world.trace('state', this, { from: from === -1 ? null : this.prog.stateName(from), to: this.prog.stateName(addr), addr });
    if (this.entry !== -1) {
      this.ip = this.entry;
      if (run) this._runNested();
    } else {
      this.ip = addr;
    }
  }
  _runNested() {
    this.flags |= FL.NESTED;
    try { this.run(); } finally { this.flags &= ~FL.NESTED; }
  }

  // ---- events -------------------------------------------------------------------------
  /** Queue an event (message) and deliver it now unless the process is busy (ScriptEventManager_t::sendEvent). */
  post(name, args = [], from = null) {
    const obj = this.world.makeEventObject(this.prog, name, args);
    this.queue.push({ name: String(name), id: this.prog.eventId(name), obj, from });
    this.world.trace('event', this, { name: String(name), args: obj.t.map((t, i) => plain({ t, v: obj.v[i] })), from: from?.name ?? from ?? null });
    this.handleEvents();
  }

  /** Process_t::handleEventsForProcess (PC 0x5f4ac0). */
  handleEvents() {
    if (this.flags & (FL.EVENT | FL.RUNNING | FL.NESTED)) return;
    if (this.runState === RS.CTOR || this.terminated) return;
    while (this.queue.length) {
      const batch = this.queue.splice(0, this.queue.length);
      for (const ev of batch) {
        let addr = ev.id ? (this.handlers?.get(ev.id) ?? -1) : -1;
        if (addr === -1) addr = this.unknownAddr;
        if (addr !== -1) {
          this.storeObjData(this.prog.eventDataOff, ev.obj);
          this.data.setInt32(this.prog.handlerFlagOff, 0, true);
          this.dataObj.delete(this.prog.handlerFlagOff);
          this.curEvent = ev; this.curEventId = ev.id;
          const saveIp = this.ip; const saveFp = this.fp;
          this.ip = addr; this.startState = -1;
          this.flags |= FL.EVENT;
          try { this.run(); } finally { this.flags &= ~FL.EVENT; }
          this.ip = saveIp; this.fp = saveFp;
          this.curEvent = null; this.curEventId = 0;
          if (this.startState !== -1) {
            const target = this.startState;
            this.switchContext(target, true);
            this.runState = RS.RUN; this.wake = 0; this.namedWait = null;
          }
        }
        if (this.runState === RS.WAIT || this.runState === RS.WAIT_TIMEOUT) {
          if (this.namedWait) {
            if (this.namedWait.toLowerCase() === ev.name.toLowerCase()) { this.runState = RS.RUN; this.namedWait = null; this.wake = 0; }
          } else { this.runState = RS.RUN; this.wake = 0; }
        }
        if (this.terminated) return;
      }
    }
  }

  // ---- interpreter --------------------------------------------------------------------
  /** Process_t::runProcess: one time slice (or a nested entry/exit/event run). */
  run() {
    const w = this.world;
    const nested = () => (this.flags & (FL.EVENT | FL.NESTED)) !== 0;
    if (!nested()) {
      if (this.terminated) return;
      if (this.runState === RS.WAIT) return;
      if (w.time < this.wake) return;
      if (this.runState === RS.WAIT_TIMEOUT) this.runState = RS.RUN;
      if (this.queue.length) this.handleEvents();
      if (this.terminated) return;
      this.flags |= FL.RUNNING;
    }
    let budget = this.runState !== RS.CTOR ? this.quota : 0;
    let atomic = 0;
    const prog = this.prog; const code = prog.code; const dv = prog.codeView;
    const stop = () => {
      if (this.runState === RS.CTOR) return;
      if (nested()) return;
      this.flags &= ~FL.RUNNING;
      if (this.queue.length) this.handleEvents();
    };
    for (;;) {
      if (this.runState !== RS.CTOR && !nested()) {
        if (budget < 1) { if (atomic < 1) return stop(); } else budget--;
        if (atomic) atomic--;
      }
      if (w.maxInstructions && ++w.instructionCount > w.maxInstructions) throw new VMError('instruction limit reached');
      const ip0 = this.ip;
      if (ip0 < 0 || ip0 >= prog.codeEnd) throw new VMError(`${this.name}: ip 0x${ip0.toString(16)} outside code`);
      const op = code[ip0];
      this.instructions++;
      if (w.traceOps) w.trace('op', this, { ip: ip0, text: decodeAt(prog, ip0).text, depth: this.st.length });
      let ip = ip0 + 1;
      try {
        switch (op) {
          case 0x00: case 0x9d: break; // NOP
          case 0x01: { const v = dv.getUint16(ip, true); this.wI(v, this.rI(v) + 1); ip += 2; break; }
          case 0x02: { const v = dv.getUint16(ip, true); this.wI(v, this.rI(v) - 1); ip += 2; break; }
          case 0x03: { // LNOT (typed)
            const a = this.popSlot();
            this.pushI(a.t === T.FLOAT ? (a.v === 0 ? 1 : 0) : a.t === T.OBJ ? (a.v ? 0 : 1) : ((a.v | 0) === 0 ? 1 : 0));
            break;
          }
          case 0x04: { const a = this.popI(); const b = this.popI(); this.pushI(b && a ? 1 : 0); break; }
          case 0x05: { const a = this.popI(); const b = this.popI(); this.pushI(b || a ? 1 : 0); break; }
          case 0x06: { const a = this.popF(); const b = this.popF(); this.pushI(b !== 0 || a !== 0 ? 1 : 0); break; }
          case 0x07: { const a = this.popF(); const b = this.popF(); this.pushI(b !== 0 && a !== 0 ? 1 : 0); break; }
          case 0x08: this.pushI(~this.popI()); break;
          case 0x09: { const a = this.popI(); const b = this.popI(); this.pushI(b & a); break; }
          case 0x0a: { const a = this.popI(); const b = this.popI(); this.pushI(b | a); break; }
          case 0x0b: this.pushI(-this.popI()); break;
          case 0x0c: this.pushF(-this.popF()); break;
          case 0x0d: { let a = this.popF(); a = Math.min(1, Math.max(0, a)); this.pushF(1 - a); break; }
          case 0x0e: { const a = this.popF(); const b = this.popF(); this.pushF(b + a); break; }
          case 0x0f: { const a = this.popI(); const b = this.popI(); this.pushI(b + a); break; }
          case 0x10: { const a = this.popF(); const b = this.popF(); this.pushF(b - a); break; }
          case 0x11: { const a = this.popI(); const b = this.popI(); this.pushI(b - a); break; }
          case 0x12: { const a = this.popF(); const b = this.popF(); this.pushF(b * a); break; }
          case 0x13: { const a = this.popI(); const b = this.popI(); this.pushI(Math.imul(b, a)); break; }
          case 0x14: { const a = this.popF(); const b = this.popF(); if (a === 0) { this._scriptError('float divide by zero'); this.pushF(0); } else this.pushF(b / a); break; }
          case 0x15: { const a = this.popI(); const b = this.popI(); if (a === 0) { this._scriptError('int divide by zero'); this.pushI(0); } else this.pushI((b / a) | 0); break; }
          // var op= imm
          case 0x16: case 0x18: case 0x1a: case 0x1c: {
            const v = dv.getUint16(ip, true); const k = dv.getFloat32(ip + 2, true); ip += 6;
            this.wF(v, fop(op, this.rF(v), k, this)); break;
          }
          case 0x17: case 0x19: case 0x1b: case 0x1d: {
            const v = dv.getUint16(ip, true); const k = dv.getInt32(ip + 2, true); ip += 6;
            this.wI(v, iop(op, this.rI(v), k, this)); break;
          }
          // [varref] op= imm
          case 0x1e: case 0x20: case 0x22: case 0x24: {
            const k = dv.getInt32(ip, true); ip += 4; const r = this.popI() & 0xffff;
            this.wI(r, iop({ 0x1e: 0x17, 0x20: 0x19, 0x22: 0x1b, 0x24: 0x1d }[op], this.rI(r), k, this)); break;
          }
          case 0x1f: case 0x21: case 0x23: case 0x25: {
            const k = dv.getFloat32(ip, true); ip += 4; const r = this.popI() & 0xffff;
            this.wF(r, fop({ 0x1f: 0x16, 0x21: 0x18, 0x23: 0x1a, 0x25: 0x1c }[op], this.rF(r), k, this)); break;
          }
          case 0x26: case 0x27: { // MAX_F / MIN_F: pop a; replace top if a is larger/smaller
            const a = this.popF(); const n = this.st.length - 1;
            const top = slotFloat(this.st[n], this.sv[n]);
            if (op === 0x26 ? a > top : a < top) { this.st[n] = T.FLOAT; this.sv[n] = fround(a); }
            break;
          }
          case 0x28: case 0x29: {
            const v = dv.getUint16(ip, true); const k = dv.getFloat32(ip + 2, true); ip += 6;
            const cur = this.rF(v); this.wF(v, op === 0x28 ? Math.max(cur, k) : Math.min(cur, k)); break;
          }
          case 0x2a: this.pushF(dv.getFloat32(ip, true)); ip += 4; break;
          case 0x2b: case 0x94: this.pushI(dv.getInt32(ip, true)); ip += 4; break;
          case 0x2c: this.pushI(this.rI(this.popI() & 0xffff)); break;
          case 0x2d: this.pushF(this.rF(this.popI() & 0xffff)); break;
          case 0x2e: this.pushF(this.rF(dv.getUint16(ip, true))); ip += 2; break;
          case 0x2f: case 0x87: this.pushI(this.rI(dv.getUint16(ip, true))); ip += 2; break;
          case 0x30: this.pushI(Math.trunc(this.rF(dv.getUint16(ip, true)))); ip += 2; break;
          case 0x31: this.pushF(this.rI(dv.getUint16(ip, true))); ip += 2; break;
          case 0x32: this.wF(dv.getUint16(ip, true), this.popF()); ip += 2; break;
          case 0x33: this.wI(dv.getUint16(ip, true), this.popI()); ip += 2; break;
          case 0x34: this.wI(dv.getUint16(ip, true), Math.trunc(this.popF())); ip += 2; break;
          case 0x35: this.wF(dv.getUint16(ip, true), this.popI()); ip += 2; break;
          case 0x36: case 0x38: case 0x3a: case 0x3c: {
            const v = dv.getUint16(ip, true); ip += 2; const a = this.popF();
            this.wF(v, fop({ 0x36: 0x16, 0x38: 0x18, 0x3a: 0x1a, 0x3c: 0x1c }[op], this.rF(v), a, this)); break;
          }
          case 0x37: case 0x39: case 0x3b: case 0x3d: {
            const v = dv.getUint16(ip, true); ip += 2; const a = this.popI();
            this.wI(v, iop({ 0x37: 0x17, 0x39: 0x19, 0x3b: 0x1b, 0x3d: 0x1d }[op], this.rI(v), a, this)); break;
          }
          case 0x3e: case 0x3f: {
            const v = dv.getUint16(ip, true); ip += 2; const a = this.popF(); const cur = this.rF(v);
            this.wF(v, op === 0x3e ? Math.min(cur, a) : Math.max(cur, a)); break;
          }
          case 0x40: case 0x42: case 0x44: case 0x46: {
            const a = this.popI(); const r = this.popI() & 0xffff;
            this.wI(r, iop({ 0x40: 0x17, 0x42: 0x19, 0x44: 0x1b, 0x46: 0x1d }[op], this.rI(r), a, this)); break;
          }
          case 0x41: case 0x43: case 0x45: case 0x47: {
            const a = this.popF(); const r = this.popI() & 0xffff;
            this.wF(r, fop({ 0x41: 0x16, 0x43: 0x18, 0x45: 0x1a, 0x47: 0x1c }[op], this.rF(r), a, this)); break;
          }
          case 0x48: case 0x49: {
            const a = this.popF(); const r = this.popI() & 0xffff; const cur = this.rF(r);
            this.wF(r, op === 0x48 ? Math.min(cur, a) : Math.max(cur, a)); break;
          }
          case 0x4a: { // CALL fn#k (virtual: most-derived vtable)
            const k = dv.getUint16(ip, true);
            this.cs.push(ip0 + 3);
            const target = prog.vtable[k];
            if (target === undefined) throw new VMError(`CALL fn#${k} outside vtable`);
            ip = target; break;
          }
          case 0x4b: { // RET
            if (!this.cs.length) throw new VMError('RET with empty call stack');
            ip = this.cs.pop(); break;
          }
          case 0x4c: { const n = dv.getUint32(ip, true); ip += 4; this.st.length -= n; this.sv.length -= n; if (this.st.length < 0) throw new VMError('POPN underflow'); break; }
          case 0x4d: ip = dv.getUint32(ip, true); break;
          case 0x4e: case 0x4f: { // JNZ / JZ target, popFlag
            const t = dv.getUint32(ip, true); const pop = dv.getUint32(ip + 4, true);
            let c;
            if (pop) c = this.popI(); else { const n = this.st.length - 1; c = slotInt(this.st[n], this.sv[n]); }
            if ((op === 0x4e) === (c !== 0)) ip = t; else ip += 8;
            break;
          }
          case 0x50: { // JZ_YIELD
            const t = dv.getUint32(ip, true);
            if (this.popI() === 0) { this.ip = t; return stop(); }
            ip += 4; break;
          }
          case 0x51: case 0x52: case 0x53: { // SETSTATE / SETSTATE_V / SETSTATE_FN
            let target; let len;
            if (op === 0x51) { target = dv.getUint32(ip, true); len = 4; }
            else if (op === 0x52) { target = this.data.getInt32(dv.getUint32(ip, true), true) >>> 0; len = 4; }
            else { target = prog.vtable[dv.getUint16(ip, true)]; len = 2; }
            this.ip = ip;
            this.switchContext(target, true);
            if (this.flags & (FL.EVENT | FL.NESTED)) ip += len; else ip = this.ip;
            if (this.terminated) { this.ip = ip; return stop(); }
            break;
          }
          case 0x54: { const a = this.popI(); const b = this.popI(); this.pushI(b < a ? 1 : 0); break; }
          case 0x55: { const a = this.popI(); const b = this.popI(); this.pushI(b > a ? 1 : 0); break; }
          case 0x56: { const a = this.popI(); const b = this.popI(); this.pushI(b <= a ? 1 : 0); break; }
          case 0x57: { const a = this.popI(); const b = this.popI(); this.pushI(b >= a ? 1 : 0); break; }
          case 0x58: { const a = this.popI(); const b = this.popI(); this.pushI(b === a ? 1 : 0); break; }
          case 0x59: { const a = this.popI(); const b = this.popI(); this.pushI(b !== a ? 1 : 0); break; }
          case 0x5a: { const a = this.popF(); const b = this.popF(); this.pushI(b < a ? 1 : 0); break; }
          case 0x5b: { const a = this.popF(); const b = this.popF(); this.pushI(b > a ? 1 : 0); break; }
          case 0x5c: { const a = this.popF(); const b = this.popF(); this.pushI(b <= a ? 1 : 0); break; }
          case 0x5d: { const a = this.popF(); const b = this.popF(); this.pushI(b >= a ? 1 : 0); break; }
          case 0x5e: { const a = this.popF(); const b = this.popF(); this.pushI(b === a ? 1 : 0); break; }
          case 0x5f: { const a = this.popF(); const b = this.popF(); this.pushI(b !== a ? 1 : 0); break; }
          case 0x60: { const k = dv.getInt32(ip, true); ip += 4; this.wI(this.popI() & 0xffff, k); break; }
          case 0x61: { const k = dv.getFloat32(ip, true); ip += 4; this.wF(this.popI() & 0xffff, k); break; }
          case 0x62: { const a = this.popSlot(); const r = this.popI() & 0xffff; this.wI(r, slotInt(a.t, a.v)); break; }
          case 0x63: { const a = this.popSlot(); const r = this.popI() & 0xffff; this.wF(r, slotFloat(a.t, a.v)); break; }
          case 0x64: this.wF(dv.getUint16(ip, true), dv.getFloat32(ip + 2, true)); ip += 6; break;
          case 0x65: this.wI(dv.getUint16(ip, true), dv.getInt32(ip + 2, true)); ip += 6; break;
          case 0x66: this.wF(dv.getUint16(ip, true), this.rF(dv.getUint16(ip + 2, true))); ip += 4; break;
          case 0x67: this.wI(dv.getUint16(ip, true), this.rI(dv.getUint16(ip + 2, true))); ip += 4; break;
          case 0x68: w.warnOnce(`break:${this.name}:${ip0}`, `${this.name}: BREAK at 0x${ip0.toString(16)}`); break;
          case 0x69: this.pushF(this.popI()); ip += 4; break; // I2F (skips 4 operand bytes)
          case 0x6a: { // SWAP
            const n = this.st.length - 1;
            [this.st[n], this.st[n - 1]] = [this.st[n - 1], this.st[n]];
            [this.sv[n], this.sv[n - 1]] = [this.sv[n - 1], this.sv[n]];
            break;
          }
          case 0x6b: { // SWITCH_I
            const n = dv.getUint32(ip, true); const dflt = dv.getInt32(ip + 4, true); ip += 8;
            const v = this.popI(); let hit = -1;
            for (let k = 0; k < n; k++) if (dv.getInt32(ip + 8 * k, true) === v) { hit = dv.getUint32(ip + 8 * k + 4, true); break; }
            if (hit !== -1) ip = hit;
            else if (dflt !== -1) ip = dflt >>> 0;
            else ip += 8 * n;
            break;
          }
          case 0x6c: { // SWITCH_FRANGE: first entry with v < threshold, else the last entry
            const n = dv.getUint32(ip, true); ip += 8;
            const v = this.popF(); let hit = -1;
            for (let k = 0; k < n; k++) if (v < dv.getFloat32(ip + 8 * k, true)) { hit = dv.getUint32(ip + 8 * k + 4, true); break; }
            ip = hit !== -1 ? hit : dv.getUint32(ip + 8 * (n - 1) + 4, true);
            break;
          }
          case 0x6d: { // SLEEP (stack: secs, flag)
            if (nested()) { this.popSlot(); this.popSlot(); this._scriptError("sleep() during event handling"); break; }
            const flag = this.popI(); const secs = this.popF();
            this.wake = w.time + secs;
            if (flag) { this.runState = RS.SLEEP; this.ip = ip; return stop(); }
            this.runState = RS.SLEEP_CONT; break;
          }
          case 0x6e: { // SLEEP_IMM flag, secs
            const flag = dv.getUint32(ip, true); const secs = dv.getFloat32(ip + 4, true); ip += 8;
            if (nested()) { this._scriptError("sleep() during event handling"); break; }
            this.wake = w.time + secs;
            if (flag) { this.runState = RS.SLEEP; this.ip = ip; return stop(); }
            this.runState = RS.SLEEP_CONT; break;
          }
          case 0x6f: { // WAITFOREVENT
            if (nested()) { this._scriptError('waitforevent() during event handling'); break; }
            this.runState = this.runState === RS.SLEEP_CONT ? RS.WAIT_TIMEOUT : RS.WAIT;
            this.ip = ip; return stop();
          }
          case 0x70: { // WAITFORNAMEDEVENT "name": records the name, keeps running
            let q = ip; while (code[q] !== 0) q++;
            let s = ''; for (let k = ip; k < q; k++) s += String.fromCharCode(code[k]);
            ip = q + 1;
            if (nested()) this._scriptError('waitfornamedevent() during event handling');
            this.namedWait = s; budget = 0x7fffffff; break;
          }
          case 0x71: atomic = dv.getUint32(ip, true) + 1; ip += 4; break;
          case 0x72: { // JMP_SETSV target, v
            const t = dv.getUint32(ip, true); const v = dv.getInt32(ip + 4, true);
            if (v >= 0) this._setHandlerFlag(v);
            ip = t; break;
          }
          case 0x73: this.startState = dv.getUint32(ip, true); ip += 4; break; // SETSTARTSTATE
          case 0x74: ip = this._handlerFlag() === 1 ? dv.getUint32(ip, true) : ip + 4; break; // JSV1
          case 0x75: ip = this._handlerFlag() !== 1 ? dv.getUint32(ip, true) : ip + 4; break; // JNSV1
          case 0x76: this.cs.push(ip0 + 5); ip = dv.getUint32(ip, true); break; // CALLA
          case 0x77: { // CTOR_END
            if (this.cs.length === 0) {
              this.runState = RS.RUN;
              if (this.startState === -1) {
                w.log(`ERROR: no setStartState during constructor of ${this.name}; terminating`);
                this.flags |= FL.TERMINATED; this.ip = ip; return stop();
              }
              this.ip = ip;
              const start = this.startState;
              w.trace('ctor-end', this, { start: prog.stateName(start) });
              this.switchContext(start, true);
              ip = this.ip;
              budget = 0; // the constructor slice ends here (runProcess entered with quota 0)
            } else ip = this.cs.pop();
            break;
          }
          case 0x78: { // HANDLER_JMP key, v
            const key = dv.getUint32(ip, true); const v = dv.getInt32(ip + 4, true);
            if (v >= 0) this._setHandlerFlag(v);
            const a = prog.handlerFor(key, this.curEventId);
            ip = a !== -1 ? a : ip + 8;
            break;
          }
          case 0x79: { // HANDLER_JMP_FN fn, v
            const k = dv.getUint16(ip, true); const v = dv.getInt32(ip + 2, true);
            if (v >= 0) this._setHandlerFlag(v);
            const a = prog.handlerFor(prog.vtable[k], this.curEventId);
            if (a === -1) { this.ip = ip + 6; return stop(); }
            ip = a; break;
          }
          case 0x7a: { this.flags |= FL.TERMINATED; w.trace('terminate', this, {}); this.ip = ip; return stop(); }
          case 0x7b: case 0x9e: this.ip = ip; return stop(); // YIELD
          case 0x7c: { // OP7C imm: FUN_005fbb00(ctx, imm), unknown engine hook (unused in C01A/C05A)
            const k = dv.getUint32(ip, true); ip += 4;
            w.warnOnce('op7c', `${this.name}: OP7C ${k} (unknown hook, ignored)`); break;
          }
          case 0x7d: { // ARRAY_REF elemSize, base, countVar
            const es = dv.getUint32(ip, true); const base = dv.getUint32(ip + 4, true); const cv = dv.getUint32(ip + 8, true); ip += 12;
            const idx = this.popI(); const cnt = this.data.getInt32(cv, true);
            if (idx < 0 || idx >= cnt) { this._scriptError(`invalid array index ${idx} (valid 0-${cnt})`); break; }
            this.pushI(es * idx + base + cv); break;
          }
          case 0x7e: this.pushI(this.state); break; // PUSH_STATE
          case 0x7f: this.wO(dv.getUint16(ip, true), this.popO()); ip += 2; break;
          case 0x80: { const o = this.popO(); const r = this.popI() & 0xffff; this.wO(r, o); break; }
          case 0x81: this.pushO(this.rO(dv.getUint16(ip, true))); ip += 2; break;
          case 0x82: { // NEWDEFAULT "type"
            let q = ip; while (code[q] !== 0) q++;
            let s = ''; for (let k = ip; k < q; k++) s += String.fromCharCode(code[k]);
            ip = q + 1;
            if (s.toLowerCase() === 'int') this.pushI(0);
            else if (s.toLowerCase() === 'float') this.pushF(0);
            else this.pushO(w.makeObject(prog, s));
            break;
          }
          case 0x85: { // CAST "type"
            let q = ip; while (code[q] !== 0) q++;
            let s = ''; for (let k = ip; k < q; k++) s += String.fromCharCode(code[k]);
            ip = q + 1;
            this._cast(s);
            break;
          }
          case 0x86: { const x = this.popF(); this.pushF(x >= 1 ? 1 : x <= 0 ? 0 : x); break; }
          case 0x88: case 0x89: case 0x8a: case 0x8b: {
            const d = dv.getUint16(ip, true); const s = dv.getUint16(ip + 2, true); ip += 4;
            this.wI(d, iop({ 0x88: 0x17, 0x89: 0x19, 0x8a: 0x1b, 0x8b: 0x1d }[op], this.rI(d), this.rI(s), this)); break;
          }
          case 0x8c: case 0x8d: case 0x8e: case 0x8f: {
            const d = dv.getUint16(ip, true); const s = dv.getUint16(ip + 2, true); ip += 4;
            this.wF(d, fop({ 0x8c: 0x16, 0x8d: 0x18, 0x8e: 0x1a, 0x8f: 0x1c }[op], this.rF(d), this.rF(s), this)); break;
          }
          case 0x90: { // FRAME n: ENTER (n>=0) / LEAVE (n<0)
            const n = dv.getInt32(ip, true); ip += 4;
            if (n >= 0) { this.cs.push(this.fp); this.fp = this.st.length; }
            else {
              const start = this.fp + n;
              if (start < 0) throw new VMError('FRAME leave underflow');
              this.st.splice(start, -n); this.sv.splice(start, -n);
              this.fp = this.cs.pop();
            }
            break;
          }
          case 0x91: w.log(this.dump()); break;
          case 0x92: { const n = this.popI(); if (n >= 1) this.quota = n & 0xffff; else budget = 0x7fffffff; break; }
          case 0x93: budget = dv.getInt32(ip, true); ip += 4; break;
          case 0x95: { // CALL_NATIVE classStr, methodStr, hint, flags
            const cls = prog.string(dv.getUint16(ip, true)); const method = prog.string(dv.getUint16(ip + 2, true));
            const hint = dv.getUint16(ip + 4, true); const flags = dv.getUint32(ip + 6, true); ip += 10;
            const isStatic = ((flags >>> 16) & 2) !== 0;
            let obj;
            if (isStatic) obj = w.makeStatic(prog, cls);
            else obj = this.popO();
            this.ip = ip;
            this._native(obj, isStatic ? cls : (obj?.cls ?? cls), method, hint, flags, isStatic, cls);
            ip = this.ip;
            if (this.terminated) return stop();
            if (this.runState !== RS.CTOR && !nested() && this.queue.length) return stop();
            break;
          }
          case 0x96: { // CALL_METHOD objVar, methodStr, hint, flags
            const ov = dv.getUint16(ip, true); const method = prog.string(dv.getUint16(ip + 2, true));
            const hint = dv.getUint16(ip + 4, true); const flags = dv.getUint32(ip + 6, true); ip += 10;
            const obj = this.rO(ov);
            this.ip = ip;
            this._native(obj, obj?.cls ?? w.varClass(prog, ov), method, hint, flags, false, null, ov);
            ip = this.ip;
            if (this.terminated) return stop();
            if (this.runState !== RS.CTOR && !nested() && this.queue.length) return stop();
            break;
          }
          case 0x97: { // PUSH_STR
            const id = dv.getUint16(ip, true); ip += 2;
            this.push(T.PTR, prog.string(id) ?? '');
            budget++; break;
          }
          case 0x98: this.pushO(this.rO(this.popI() & 0xffff)); break;
          case 0x99: this.pushO(new StringObject(this.stateName ?? '<NoCurrentState>')); break;   // stackCurrentStateName (PC 0x5f90a0)
          case 0x9a: this.pushO(new StringObject(this.curEvent?.name ?? '<NoCurrentEventName>')); break; // stackCurrentEventName (PC 0x5f9010)
          case 0x9b: // EVLOCK
            if (!nested()) { if (!(this.flags & FL.LOCKED)) this.flags |= FL.EVENT | FL.LOCKED; }
            break;
          case 0x9c: // EVUNLOCK
            if (this.flags & FL.LOCKED) {
              this.flags &= ~(FL.EVENT | FL.LOCKED);
              if (this.queue.length) { this.ip = ip; return stop(); }
            }
            break;
          default:
            throw new VMError(`invalid opcode 0x${op.toString(16)} at 0x${ip0.toString(16)}`);
        }
      } catch (e) {
        if (!(e instanceof VMError)) throw e;
        this.lastError = e;
        w.log(`SCRIPT ERROR ${this.name} @0x${ip0.toString(16)} (${this.stateName ?? '-'}): ${e.message}; terminating`);
        w.trace('error', this, { ip: ip0, message: e.message });
        this.flags |= FL.TERMINATED;
        this.ip = ip0;
        return stop();
      }
      this.ip = ip;
    }
  }

  _handlerFlag() { return this.data.getInt32(this.prog.handlerFlagOff, true); }
  _setHandlerFlag(v) { this.data.setInt32(this.prog.handlerFlagOff, v, true); this.dataObj.delete(this.prog.handlerFlagOff); }
  _scriptError(msg) { this.world.log(`script warning ${this.name} (${this.stateName ?? '-'}): ${msg}`); }

  _cast(name) {
    const lname = name.toLowerCase();
    const t = this.peekType();
    if (t === T.INT) {
      if (lname === 'fuzzy') { const i = this.popI(); this.pushF(i ? 1 : 0); return; }
      if (lname === 'float') { const i = this.popI(); this.pushF(i); return; }
      if (lname === 'bool') { const i = this.popI(); this.pushI(i !== 0 ? 1 : 0); return; }
      if (lname === 'stateref' || lname === 'int') return;
    }
    if (t === T.INT || t === T.FLOAT) {
      if (lname === 'int' || lname === 'bool') { const f = this.popF(); this.pushI(Math.trunc(f)); return; }
      if (['fuzzy', 'float', 'sceneref', 'actorref', 'soundref', 'soundsetref'].includes(lname)) return;
      // object conversion (e.g. 'String'): construct and convert through the type's '=Type' method
      const a = this.popSlot();
      this.pushO(this.world.convert(this, a, name));
      return;
    }
    if (t === T.OBJ || t === T.PTR) {
      const a = this.popSlot();
      const r = this.world.convert(this, a, name);
      if (r && typeof r === 'object' && 't' in r) this.push(r.t, r.v); else this.pushO(r);
    }
  }

  _native(obj, cls, method, hint, flags, isStatic, staticCls, objVar) {
    const nargs = (flags >>> 8) & 0xff; const nret = flags & 0xff;
    const base = this.st.length - nargs;
    if (base < 0) throw new VMError(`native ${cls}.${method}: needs ${nargs} args, stack has ${this.st.length}`);
    const args = [];
    for (let k = base; k < this.st.length; k++) args.push({ t: this.st[k], v: this.sv[k] });
    this.st.length = base; this.sv.length = base;
    const rets = this.world.callNative({
      proc: this, self: obj, cls, method, hint, nargs, nret, args, isStatic, staticCls, objVar,
    });
    for (let k = 0; k < nret; k++) {
      const r = rets[k] ?? { t: T.INT, v: 0 };
      this.push(r.t, r.v);
    }
  }

  dump() {
    const top = this.st.slice(-6).map((t, i) => showSlot({ t, v: this.sv[this.sv.length - Math.min(6, this.st.length) + i] }));
    return `[${this.name}] state=${this.stateName} ip=0x${this.ip.toString(16)} run=${this.runState} flags=0x${this.flags.toString(16)} wake=${this.wake.toFixed(2)} stack(${this.st.length})=[${top.join(', ')}] cs=${this.cs.length}`;
  }
}

function iop(op, a, b, p) {
  switch (op) {
    case 0x17: return (a + b) | 0;
    case 0x19: return (a - b) | 0;
    case 0x1b: return Math.imul(a, b);
    case 0x1d: if (b === 0) { p._scriptError('int divide by zero'); return a; } return (a / b) | 0;
    default: throw new VMError('bad int op');
  }
}
function fop(op, a, b, p) {
  switch (op) {
    case 0x16: return a + b;
    case 0x18: return a - b;
    case 0x1a: return a * b;
    case 0x1c: if (b === 0) { p._scriptError('float divide by zero'); return a; } return a / b;
    default: throw new VMError('bad float op');
  }
}

/**
 * The script world: clock, scheduler, object factory, message routing and the native registry.
 */
export class World {
  constructor({ natives, quota = DEFAULT_QUOTA, log = (s) => console.log(s), trace = null, maxInstructions = 0 } = {}) {
    if (!natives) throw new Error('World needs a NativeRegistry (natives.mjs)');
    this.natives = natives;
    this.quota = quota;
    this.time = 0;
    this.frame = 0;
    this.processes = [];
    this.byRef = new Map();
    this.nativeLog = [];
    this.maxNativeLog = 100000;
    this.externalCommands = [];
    this.timers = [];
    this.logFn = log;
    this.traceFn = trace;
    this.traceOps = false;
    this.warned = new Set();
    this.maxInstructions = maxInstructions;
    this.instructionCount = 0;
    this.nextId = 1;
    this.commandHandlers = new Map(); // ref -> fn(cmd) for refs not backed by a script (e.g. native caretaker)
  }
  log(s) { this.logFn?.(s); }
  warnOnce(key, s) { if (!this.warned.has(key)) { this.warned.add(key); this.log(s); } }
  trace(kind, proc, data) { this.traceFn?.({ kind, t: this.time, frame: this.frame, proc: proc?.name ?? null, ...data }); }

  /** Create a script instance and run its constructor (Process_t ctor + bootstrap). */
  spawn(prog, opts = {}) {
    const p = new Process(this, prog, { ...opts, id: this.nextId++ });
    this.processes.push(p);
    if (p.ref !== null && p.ref !== undefined) this.byRef.set(p.ref, p);
    this.trace('spawn', p, { script: prog.name, chain: prog.chainNames.join('<-') });
    if (opts.construct !== false) p.run();
    return p;
  }

  /** One scheduler frame: advance the clock, fire timers, run each live process once. */
  tick(dt = 1 / 30) {
    this.time += dt;
    this.frame++;
    if (this.timers.length) {
      const due = this.timers.filter(t => t.at <= this.time);
      this.timers = this.timers.filter(t => t.at > this.time);
      for (const t of due) t.fn();
    }
    for (const p of [...this.processes]) if (!p.terminated) p.run();
    this.processes = this.processes.filter(p => !p.terminated);
  }
  runFor(seconds, dt = 1 / 30) { const end = this.time + seconds; while (this.time < end - 1e-9) this.tick(dt); }
  /** Call fn after `delay` seconds of game time (used by simulated natives). */
  after(delay, fn) { this.timers.push({ at: this.time + delay, fn }); }

  /** Resolve a message target: Process, scene ref (int), or script/instance name. */
  resolve(target) {
    if (target instanceof Process) return target;
    if (typeof target === 'number') return this.byRef.get(target) ?? null;
    if (typeof target === 'string') return this.processes.find(p => p.name === target) ?? null;
    return null;
  }
  /** Send a message (SendCommand*): to a script instance, or to an external handler for the ref. */
  send(target, name, args = [], from = null) {
    const p = this.resolve(target);
    const rec = { t: this.time, frame: this.frame, from: from?.name ?? from ?? null, to: p ? p.name : target, name: String(name), args: args.map(a => (a && typeof a === 'object' && 't' in a) ? plain(a) : a) };
    this.trace('send', from instanceof Process ? from : null, rec);
    if (p) { p.post(name, args, from); return true; }
    this.externalCommands.push(rec);
    const h = this.commandHandlers.get(target);
    if (h) h(rec);
    return false;
  }

  // ---- objects ---------------------------------------------------------------------
  isScalarType(lname) { return isIntType(lname); }
  makeObject(prog, typeName) {
    const n = String(typeName);
    if (n.toLowerCase() === 'string') return new StringObject('');
    const fields = prog.typeFields(n);
    if (fields) return new StructObject(n, fields);
    if (/_if$/i.test(n)) return this.makeHostObject(n, null, {});
    return new StructObject(n, []);
  }
  makeHostObject(cls, proc, props) { return new HostObject(cls, { proc, ...props }); }
  /** Static call target (`ctx->vtbl[0](className)`). */
  makeStatic(prog, cls) {
    if (cls === 'String') return null;
    return this.makeObject(prog, cls);
  }
  makeEventObject(prog, name, args) {
    const fields = prog.eventFields(name) ?? [];
    const obj = new StructObject('UserType', fields);
    args.forEach((a, i) => {
      let s;
      if (a && typeof a === 'object' && 't' in a && 'v' in a) s = a;
      else if (a instanceof ScriptObject) s = { t: T.OBJ, v: a };
      else if (typeof a === 'string') s = { t: T.OBJ, v: new StringObject(a) };
      else if (typeof a === 'number') s = isFloatType(fields[i] ?? (Number.isInteger(a) ? 'Int' : 'Float')) ? { t: T.FLOAT, v: fround(a) } : { t: T.INT, v: a | 0 };
      else s = { t: T.INT, v: a ? 1 : 0 };
      obj.set(i, s);
    });
    return obj;
  }
  /** Class name for a CALL_METHOD object variable that holds no object (diagnostics only). */
  varClass(prog, v) {
    if (v < 0x8000) {
      const h = prog.hostObjects.find(o => o.offset === v) ?? prog.valueObjects.find(o => o.offset === v);
      if (h) return h.type;
      const x = prog.vars.find(o => o.offset === v);
      if (x) return x.listType ?? x.type;
    }
    return 'null';
  }
  /** CAST to a non-scalar type, or of an object: delegated to natives ('<Type>.=Type' / '<Class>.cast'). */
  convert(proc, slot, typeName) {
    return this.natives.convert(this, proc, slot, typeName);
  }

  callNative(call) {
    call.world = this;
    const rets = this.natives.invoke(call);
    if (this.nativeLog.length < this.maxNativeLog) {
      this.nativeLog.push({
        t: this.time, frame: this.frame, proc: call.proc.name, state: call.proc.stateName,
        cls: call.cls, method: call.method, args: call.args.map(plain), rets: rets.map(plain),
        implemented: call.implemented,
      });
    }
    if (!this.natives.isQuiet(call)) this.trace('native', call.proc, { cls: call.cls, method: call.method, args: call.args.map(showSlot), rets: rets.map(showSlot), implemented: call.implemented });
    return rets;
  }
}

export { toSlot };
