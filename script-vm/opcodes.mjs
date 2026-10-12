// Opcode table of the SDL script VM (Process_t::runProcess, PC 0x5f56f0 / GC 801bcdc8).
// Same table as decoders/ppo_dis.py; semantics and confidence: decoders/opcodes.md.
// Operand codes: V u16 var, S u16 string id, F u16 function (vtable) index, H u16,
// I u32, T u32 absolute code address, i i32, f f32, z inline C string, * switch table.

export const OPS = {
  0x00: ['NOP', ''], 0x01: ['INC_I', 'V'], 0x02: ['DEC_I', 'V'],
  0x03: ['LNOT', ''], 0x04: ['LAND_I', ''], 0x05: ['LOR_I', ''], 0x06: ['LOR_F', ''], 0x07: ['LAND_F', ''],
  0x08: ['BNOT', ''], 0x09: ['BAND', ''], 0x0a: ['BOR', ''], 0x0b: ['NEG_I', ''], 0x0c: ['NEG_F', ''],
  0x0d: ['FNOT', ''], 0x0e: ['ADD_F', ''], 0x0f: ['ADD_I', ''], 0x10: ['SUB_F', ''], 0x11: ['SUB_I', ''],
  0x12: ['MUL_F', ''], 0x13: ['MUL_I', ''], 0x14: ['DIV_F', ''], 0x15: ['DIV_I', ''],
  0x16: ['ADDV_F_IMM', 'Vf'], 0x17: ['ADDV_I_IMM', 'Vi'], 0x18: ['SUBV_F_IMM', 'Vf'], 0x19: ['SUBV_I_IMM', 'Vi'],
  0x1a: ['MULV_F_IMM', 'Vf'], 0x1b: ['MULV_I_IMM', 'Vi'], 0x1c: ['DIVV_F_IMM', 'Vf'], 0x1d: ['DIVV_I_IMM', 'Vi'],
  0x1e: ['ADDX_I_IMM', 'i'], 0x1f: ['ADDX_F_IMM', 'f'], 0x20: ['SUBX_I_IMM', 'i'], 0x21: ['SUBX_F_IMM', 'f'],
  0x22: ['MULX_I_IMM', 'i'], 0x23: ['MULX_F_IMM', 'f'], 0x24: ['DIVX_I_IMM', 'i'], 0x25: ['DIVX_F_IMM', 'f'],
  0x26: ['MAX_F', ''], 0x27: ['MIN_F', ''], 0x28: ['MAXV_F_IMM', 'Vf'], 0x29: ['MINV_F_IMM', 'Vf'],
  0x2a: ['PUSH_F', 'f'], 0x2b: ['PUSH_I', 'i'], 0x2c: ['LOADX_I', ''], 0x2d: ['LOADX_F', ''],
  0x2e: ['LOAD_F', 'V'], 0x2f: ['LOAD_I', 'V'], 0x30: ['LOAD_F2I', 'V'], 0x31: ['LOAD_I2F', 'V'],
  0x32: ['STORE_F', 'V'], 0x33: ['STORE_I', 'V'], 0x34: ['STORE_F2I', 'V'], 0x35: ['STORE_I2F', 'V'],
  0x36: ['ADDV_F', 'V'], 0x37: ['ADDV_I', 'V'], 0x38: ['SUBV_F', 'V'], 0x39: ['SUBV_I', 'V'],
  0x3a: ['MULV_F', 'V'], 0x3b: ['MULV_I', 'V'], 0x3c: ['DIVV_F', 'V'], 0x3d: ['DIVV_I', 'V'],
  0x3e: ['MINV_F', 'V'], 0x3f: ['MAXV_F', 'V'],
  0x40: ['ADDX_I', ''], 0x41: ['ADDX_F', ''], 0x42: ['SUBX_I', ''], 0x43: ['SUBX_F', ''],
  0x44: ['MULX_I', ''], 0x45: ['MULX_F', ''], 0x46: ['DIVX_I', ''], 0x47: ['DIVX_F', ''],
  0x48: ['MINX_F', ''], 0x49: ['MAXX_F', ''],
  0x4a: ['CALL', 'F'], 0x4b: ['RET', ''], 0x4c: ['POPN', 'I'], 0x4d: ['JMP', 'T'],
  0x4e: ['JNZ', 'TI'], 0x4f: ['JZ', 'TI'], 0x50: ['JZ_YIELD', 'T'],
  0x51: ['SETSTATE', 'T'], 0x52: ['SETSTATE_V', 'I'], 0x53: ['SETSTATE_FN', 'F'],
  0x54: ['LT_I', ''], 0x55: ['GT_I', ''], 0x56: ['LE_I', ''], 0x57: ['GE_I', ''], 0x58: ['EQ_I', ''], 0x59: ['NE_I', ''],
  0x5a: ['LT_F', ''], 0x5b: ['GT_F', ''], 0x5c: ['LE_F', ''], 0x5d: ['GE_F', ''], 0x5e: ['EQ_F', ''], 0x5f: ['NE_F', ''],
  0x60: ['STOREX_I_IMM', 'i'], 0x61: ['STOREX_F_IMM', 'f'], 0x62: ['STOREX_I', ''], 0x63: ['STOREX_F', ''],
  0x64: ['SETV_F', 'Vf'], 0x65: ['SETV_I', 'Vi'], 0x66: ['MOVV_F', 'VV'], 0x67: ['MOVV_I', 'VV'],
  0x68: ['BREAK', ''], 0x69: ['I2F', 'I'], 0x6a: ['SWAP', ''],
  0x6b: ['SWITCH_I', '*'], 0x6c: ['SWITCH_FRANGE', '*'],
  0x6d: ['SLEEP', ''], 0x6e: ['SLEEP_IMM', 'If'], 0x6f: ['WAITFOREVENT', ''], 0x70: ['WAITFORNAMEDEVENT', 'z'],
  0x71: ['ATOMIC_N', 'I'], 0x72: ['JMP_SETSV', 'Ti'], 0x73: ['SETSTARTSTATE', 'T'],
  0x74: ['JSV1', 'T'], 0x75: ['JNSV1', 'T'], 0x76: ['CALLA', 'T'], 0x77: ['CTOR_END', ''],
  0x78: ['HANDLER_JMP', 'Ti'], 0x79: ['HANDLER_JMP_FN', 'Fi'], 0x7a: ['TERMINATE', ''], 0x7b: ['YIELD', ''],
  0x7c: ['OP7C', 'I'], 0x7d: ['ARRAY_REF', 'III'], 0x7e: ['PUSH_STATE', ''],
  0x7f: ['STORE_O', 'V'], 0x80: ['STOREX_O', ''], 0x81: ['LOAD_O', 'V'], 0x82: ['NEWDEFAULT', 'z'],
  0x85: ['CAST', 'z'], 0x86: ['SAT_F', ''], 0x87: ['LOAD_I2', 'V'],
  0x88: ['ADDVV_I', 'VV'], 0x89: ['SUBVV_I', 'VV'], 0x8a: ['MULVV_I', 'VV'], 0x8b: ['DIVVV_I', 'VV'],
  0x8c: ['ADDVV_F', 'VV'], 0x8d: ['SUBVV_F', 'VV'], 0x8e: ['MULVV_F', 'VV'], 0x8f: ['DIVVV_F', 'VV'],
  0x90: ['FRAME', 'i'], 0x91: ['DUMPSTATE', ''], 0x92: ['SET_QUOTA', ''], 0x93: ['SET_BUDGET', 'I'],
  0x94: ['PUSH_I2', 'i'], 0x95: ['CALL_NATIVE', 'SSHI'], 0x96: ['CALL_METHOD', 'VSHI'], 0x97: ['PUSH_STR', 'S'],
  0x98: ['LOADX_O', ''], 0x99: ['PUSH_STATENAME', ''], 0x9a: ['PUSH_EVENTNAME', ''], 0x9b: ['EVLOCK', ''], 0x9c: ['EVUNLOCK', ''],
  0x9d: ['NOP2', ''], 0x9e: ['YIELD2', ''],
};

const SZ = { V: 2, S: 2, F: 2, H: 2, I: 4, T: 4, i: 4, f: 4 };

export function varName(v) {
  if (v < 0x8000) return `d[0x${v.toString(16)}]`;
  if (v & 0x4000) return `fp[${v - 0x10000}]`;
  return `g[${0x3fff - (v & 0x3fff)}]`;
}

/**
 * Decode one instruction at absolute address `ip` of a linked Program.
 * Returns { ip, op, name, args: [raw values], len, text }.
 */
export function decodeAt(prog, ip) {
  const code = prog.code; const dv = prog.codeView;
  const op = code[ip];
  const e = OPS[op];
  if (!e) return { ip, op, name: `INVALID_${op.toString(16)}`, args: [], len: 1, text: `INVALID 0x${op.toString(16)}` };
  const [name, fmt] = e;
  let p = ip + 1; const args = []; const parts = [];
  if (fmt === '*') {
    const n = dv.getUint32(p, true); const dflt = dv.getInt32(p + 4, true); p += 8;
    const ents = [];
    for (let k = 0; k < n; k++) {
      const v = op === 0x6b ? dv.getInt32(p, true) : dv.getFloat32(p, true);
      ents.push([v, dv.getUint32(p + 4, true)]); p += 8;
    }
    if (op === 0x6b && dflt !== -1) p += 8; // dead bytes after a table with a real default
    args.push(n, dflt, ents);
    parts.push(`n=${n}`, `def=${dflt === -1 ? -1 : '0x' + (dflt >>> 0).toString(16)}`, ...ents.map(([v, t]) => `${v}->0x${t.toString(16)}`));
  } else {
    for (const c of fmt) {
      if (c === 'z') {
        let q = p; while (code[q] !== 0) q++;
        let s = ''; for (let k = p; k < q; k++) s += String.fromCharCode(code[k]);
        args.push(s); parts.push(JSON.stringify(s)); p = q + 1; continue;
      }
      let v;
      if ('VSFH'.includes(c)) v = dv.getUint16(p, true);
      else if (c === 'I' || c === 'T') v = dv.getUint32(p, true);
      else if (c === 'i') v = dv.getInt32(p, true);
      else if (c === 'f') v = dv.getFloat32(p, true);
      p += SZ[c];
      args.push(v);
      if (c === 'V') parts.push(varName(v));
      else if (c === 'S') parts.push(JSON.stringify(prog.string(v) ?? `str#${v}`));
      else if (c === 'F') parts.push(`fn#${v}`);
      else if (c === 'T') parts.push(prog.stateByAddr.has(v) ? prog.stateName(v) : `@0x${v.toString(16)}`);
      else if (c === 'f') parts.push(String(v));
      else if (c === 'I' || c === 'H') parts.push(`0x${v.toString(16)}`);
      else parts.push(String(v));
    }
  }
  return { ip, op, name, args, len: p - ip, text: `${name} ${parts.join(', ')}`.trim() };
}

/** Linear disassembly of one file's own code range. */
export function disassembleFile(prog, file) {
  const out = [];
  let ip = file.codeBase; const end = file.codeBase + file.code.length;
  while (ip < end) {
    const ins = decodeAt(prog, ip);
    out.push(ins);
    if (ins.name.startsWith('INVALID')) break;
    ip += ins.len;
  }
  return { ins: out, end: ip, clean: ip === end };
}
