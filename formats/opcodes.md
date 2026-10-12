# Freedom Fighters (Glacier) SDL script VM: opcode table

Source: interpreter `FUN_005f56f0` in Freedom.Exe (jump table at 0x5f8bf8, 0x9f entries, opcode > 0x9e means invalid). Helpers were identified from the x86.
Reference disassembler: `freedom-fighters-re/decoders/ppo_dis.py` (labelled listings: `ppo_list.py`). Run `python3 -I ppo_dis.py f.ppo ...` for a decode check, or `python3 -I ppo_dis.py -l child.ppo parent.ppo ...` for a listing with string names resolved.

**Validation:** linear decode of all 49 .ppo files from the C01A and C05A ZGFs uses up each code region exactly, with no unknown opcodes. Every jump, call and switch target that falls inside a file's own code range lands on an instruction start. The only out-of-range targets are `CALLA` to a parent class's constructor (offset 0, 0x308e, 0x568f, ...).

## 1. Opcode table

The length column includes the opcode byte. Stack notation: `a` = first value popped (top of stack), `b` = second value popped. "var" = a u16 variable operand (see §2.3). "varref" = a variable reference popped from the stack as an int, with the same encoding as a u16 var.

| dec | hex | mnemonic | operands (after opcode) | len | semantics | conf |
|---|---|---|---|---|---|---|
| 0 | 0x00 | NOP | — | 1 | NOP | high |
| 1 | 0x01 | INC_I | u16 var | 3 | var(int) += 1 | high |
| 2 | 0x02 | DEC_I | u16 var | 3 | var(int) -= 1 | high |
| 3 | 0x03 | LNOT | — | 1 | pop a; push int(a==0) (int or float a) | high |
| 4 | 0x04 | LAND_I | — | 1 | pop a,b (int); push int(b&&a) | high |
| 5 | 0x05 | LOR_I | — | 1 | pop a,b (int); push int(b\|\|a) | high |
| 6 | 0x06 | LOR_F | — | 1 | pop a,b (float); push int(b!=0 \|\| a!=0) | high |
| 7 | 0x07 | LAND_F | — | 1 | pop a,b (float); push int(b!=0 && a!=0) | high |
| 8 | 0x08 | BNOT | — | 1 | pop a; push ~a | high |
| 9 | 0x09 | BAND | — | 1 | pop a,b; push b&a | high |
| 10 | 0x0a | BOR | — | 1 | pop a,b; push b\|a | high |
| 11 | 0x0b | NEG_I | — | 1 | pop a; push -a (int) | high |
| 12 | 0x0c | NEG_F | — | 1 | pop a; push -a (float) | high |
| 13 | 0x0d | FNOT | — | 1 | pop a; a=clamp(a,0,1); push float 1-a (fuzzy NOT) | high |
| 14 | 0x0e | ADD_F | — | 1 | pop a,b; push float b+a | high |
| 15 | 0x0f | ADD_I | — | 1 | pop a,b; push int b+a | high |
| 16 | 0x10 | SUB_F | — | 1 | pop a,b; push float b-a | high |
| 17 | 0x11 | SUB_I | — | 1 | pop a,b; push int b-a | high |
| 18 | 0x12 | MUL_F | — | 1 | pop a,b; push float b*a | high |
| 19 | 0x13 | MUL_I | — | 1 | pop a,b; push int b*a | high |
| 20 | 0x14 | DIV_F | — | 1 | pop a,b; push float b/a (a==0 -> script error) | high |
| 21 | 0x15 | DIV_I | — | 1 | pop a,b; push int b/a | high |
| 22 | 0x16 | ADDV_F_IMM | u16 var, f32 | 7 | var(float) += imm | high |
| 23 | 0x17 | ADDV_I_IMM | u16 var, i32 | 7 | var(int) += imm | high |
| 24 | 0x18 | SUBV_F_IMM | u16 var, f32 | 7 | var(float) -= imm | high |
| 25 | 0x19 | SUBV_I_IMM | u16 var, i32 | 7 | var(int) -= imm | high |
| 26 | 0x1a | MULV_F_IMM | u16 var, f32 | 7 | var(float) *= imm | high |
| 27 | 0x1b | MULV_I_IMM | u16 var, i32 | 7 | var(int) *= imm | high |
| 28 | 0x1c | DIVV_F_IMM | u16 var, f32 | 7 | var(float) /= imm | high |
| 29 | 0x1d | DIVV_I_IMM | u16 var, i32 | 7 | var(int) /= imm | high |
| 30 | 0x1e | ADDX_I_IMM | i32 | 5 | pop varref; [varref](int) += imm | high |
| 31 | 0x1f | ADDX_F_IMM | f32 | 5 | pop varref; [varref](float) += imm | high |
| 32 | 0x20 | SUBX_I_IMM | i32 | 5 | pop varref; [varref](int) -= imm | high |
| 33 | 0x21 | SUBX_F_IMM | f32 | 5 | pop varref; [varref](float) -= imm | high |
| 34 | 0x22 | MULX_I_IMM | i32 | 5 | pop varref; [varref](int) *= imm | high |
| 35 | 0x23 | MULX_F_IMM | f32 | 5 | pop varref; [varref](float) *= imm | high |
| 36 | 0x24 | DIVX_I_IMM | i32 | 5 | pop varref; [varref](int) /= imm | high |
| 37 | 0x25 | DIVX_F_IMM | f32 | 5 | pop varref; [varref](float) /= imm | high |
| 38 | 0x26 | MAX_F | — | 1 | pop a; if a > top: replace top with float a (max) | high |
| 39 | 0x27 | MIN_F | — | 1 | pop a; if a < top: replace top (min) | high |
| 40 | 0x28 | MAXV_F_IMM | u16 var, f32 | 7 | var(float) = max(var, imm) | high |
| 41 | 0x29 | MINV_F_IMM | u16 var, f32 | 7 | var(float) = min(var, imm) | high |
| 42 | 0x2a | PUSH_F | f32 | 5 | push float imm | high |
| 43 | 0x2b | PUSH_I | i32 | 5 | push int imm | high |
| 44 | 0x2c | LOADX_I | — | 1 | pop varref; push int [varref] | high |
| 45 | 0x2d | LOADX_F | — | 1 | pop varref; push float [varref] | high |
| 46 | 0x2e | LOAD_F | u16 var | 3 | push float var | high |
| 47 | 0x2f | LOAD_I | u16 var | 3 | push int var | high |
| 48 | 0x30 | LOAD_F2I | u16 var | 3 | push int((int)float var) | high |
| 49 | 0x31 | LOAD_I2F | u16 var | 3 | push float((float)int var) | high |
| 50 | 0x32 | STORE_F | u16 var | 3 | pop float -> var | high |
| 51 | 0x33 | STORE_I | u16 var | 3 | pop int -> var (also used to discard into a temp) | high |
| 52 | 0x34 | STORE_F2I | u16 var | 3 | pop float -> var as int (ftol) | high |
| 53 | 0x35 | STORE_I2F | u16 var | 3 | pop int -> var as float | high |
| 54 | 0x36 | ADDV_F | u16 var | 3 | var(float) += pop | high |
| 55 | 0x37 | ADDV_I | u16 var | 3 | var(int) += pop | high |
| 56 | 0x38 | SUBV_F | u16 var | 3 | var(float) -= pop | high |
| 57 | 0x39 | SUBV_I | u16 var | 3 | var(int) -= pop | high |
| 58 | 0x3a | MULV_F | u16 var | 3 | var(float) *= pop | high |
| 59 | 0x3b | MULV_I | u16 var | 3 | var(int) *= pop | high |
| 60 | 0x3c | DIVV_F | u16 var | 3 | var(float) /= pop | high |
| 61 | 0x3d | DIVV_I | u16 var | 3 | var(int) /= pop | high |
| 62 | 0x3e | MINV_F | u16 var | 3 | pop a; var(float) = min(var,a) | high |
| 63 | 0x3f | MAXV_F | u16 var | 3 | pop a; var(float) = max(var,a) | high |
| 64 | 0x40 | ADDX_I | — | 1 | pop a, pop varref; [varref](int) += a | high |
| 65 | 0x41 | ADDX_F | — | 1 | pop a, pop varref; [varref](float) += a | high |
| 66 | 0x42 | SUBX_I | — | 1 | ... -= a (int) | high |
| 67 | 0x43 | SUBX_F | — | 1 | ... -= a (float) | high |
| 68 | 0x44 | MULX_I | — | 1 | ... *= a (int) | high |
| 69 | 0x45 | MULX_F | — | 1 | ... *= a (float) | high |
| 70 | 0x46 | DIVX_I | — | 1 | ... /= a (int) | high |
| 71 | 0x47 | DIVX_F | — | 1 | ... /= a (float) | high |
| 72 | 0x48 | MINX_F | — | 1 | pop a, pop varref; [varref] = min([varref],a) (float) | high |
| 73 | 0x49 | MAXX_F | — | 1 | pop a, pop varref; [varref] = max(...) | high |
| 74 | 0x4a | CALL | u16 fn | 3 | call script function #idx (program fn table +0x104/+0x108); push return ip (ip+3) on call stack | high |
| 75 | 0x4b | RET | — | 1 | pop return ip from call stack; jump | high |
| 76 | 0x4c | POPN | u32 n | 5 | drop n values from data stack | high |
| 77 | 0x4d | JMP | u32 target | 5 | jump to absolute code offset | high |
| 78 | 0x4e | JNZ | u32 target, u32 pop_flag | 9 | cond = (pop? pop int : peek top); if cond!=0 jump | high |
| 79 | 0x4f | JZ | u32 target, u32 pop_flag | 9 | cond = (pop? pop : peek); if cond==0 jump | high |
| 80 | 0x50 | JZ_YIELD | u32 target | 5 | pop int; if 0: ip=target and suspend (yield) else continue | high |
| 81 | 0x51 | SETSTATE | u32 state | 5 | change state to imm (state id = code offset); see notes | high |
| 82 | 0x52 | SETSTATE_V | u32 dataoff | 5 | change state to int at d[off] (raw data offset u32) | high |
| 83 | 0x53 | SETSTATE_FN | u16 fn | 3 | change state to fn-table entry #idx | high |
| 84 | 0x54 | LT_I | — | 1 | pop a,b; push int b<a | high |
| 85 | 0x55 | GT_I | — | 1 | push b>a | high |
| 86 | 0x56 | LE_I | — | 1 | push b<=a | high |
| 87 | 0x57 | GE_I | — | 1 | push b>=a | high |
| 88 | 0x58 | EQ_I | — | 1 | push b==a | high |
| 89 | 0x59 | NE_I | — | 1 | push b!=a | high |
| 90 | 0x5a | LT_F | — | 1 | float b<a | high |
| 91 | 0x5b | GT_F | — | 1 | float b>a | high |
| 92 | 0x5c | LE_F | — | 1 | float b<=a | high |
| 93 | 0x5d | GE_F | — | 1 | float b>=a | high |
| 94 | 0x5e | EQ_F | — | 1 | float b==a | high |
| 95 | 0x5f | NE_F | — | 1 | float b!=a | high |
| 96 | 0x60 | STOREX_I_IMM | i32 | 5 | pop varref; [varref] = imm (int) | high |
| 97 | 0x61 | STOREX_F_IMM | f32 | 5 | pop varref; [varref] = imm (float) | high |
| 98 | 0x62 | STOREX_I | — | 1 | pop a, pop varref; [varref]=a (int) | high |
| 99 | 0x63 | STOREX_F | — | 1 | pop a, pop varref; [varref]=a (float) | high |
| 100 | 0x64 | SETV_F | u16 var, f32 | 7 | var = imm (float) | high |
| 101 | 0x65 | SETV_I | u16 var, i32 | 7 | var = imm (int) | high |
| 102 | 0x66 | MOVV_F | u16 var dst, u16 var src | 5 | dst = src (float) | high |
| 103 | 0x67 | MOVV_I | u16 var dst, u16 var src | 5 | dst = src (int) | high |
| 104 | 0x68 | BREAK | — | 1 | debug break / assert trap | high |
| 105 | 0x69 | I2F | u32 unused | 5 | pop int; push float(int); ALSO skips 4 operand bytes (VM does ip+=4) | med |
| 106 | 0x6a | SWAP | — | 1 | swap top two stack values | high |
| 107 | 0x6b | SWITCH_I | u32 n, u32 default, n×(i32 value, u32 target) [+8 dead bytes if default!=0xFFFFFFFF] | 9+8n(+8) | switch on int: pop v; table of n (i32 value,u32 target); match->jump; else default (if != -1) else fall through after table | high |
| 108 | 0x6c | SWITCH_FRANGE | u32 n, u32 default, n×(f32 value, u32 target) [+8 dead bytes if default!=0xFFFFFFFF] | 9+8n(+8) | range switch on float: pop v; first entry with v < threshold -> jump; none -> jump to LAST entry target; default field unused | high |
| 109 | 0x6d | SLEEP | — | 1 | pop int flag, pop float secs: sleep (flag!=0 -> state 2, else 3); error inside event handler | med |
| 110 | 0x6e | SLEEP_IMM | u32 flag, f32 secs | 9 | sleep imm secs (flag like 0x6d); yields | high |
| 111 | 0x6f | WAITFOREVENT | — | 1 | waitforevent: suspend until event | high |
| 112 | 0x70 | WAITFORNAMEDEVENT | cstring (NUL-terminated) | 2+strlen | waitfornamedevent("name"): stores name ptr at ctx+0x16, suspends | high |
| 113 | 0x71 | ATOMIC_N | u32 n | 5 | run next n+1 instructions without preemption (atomic block) | med |
| 114 | 0x72 | JMP_SETSV | u32 target, i32 v | 9 | if v>=0: d[prog+0x40] = v; jump target | med |
| 115 | 0x73 | SETSTARTSTATE | u32 state | 5 | constructor: record start state (ctx+0x12) | high |
| 116 | 0x74 | JSV1 | u32 target | 5 | if d[prog+0x40]==1 jump else continue | med |
| 117 | 0x75 | JNSV1 | u32 target | 5 | if d[prog+0x40]!=1 jump else continue | med |
| 118 | 0x76 | CALLA | u32 target | 5 | call absolute code offset (used for base-class ctor: target 0/parent base); return ip=ip+5 on call stack | high |
| 119 | 0x77 | CTOR_END | — | 1 | end of constructor: if not nested, go to start state (error if none); else behaves as RET | med |
| 120 | 0x78 | HANDLER_JMP | u32 key, i32 v | 9 | if v>=0 d[prog+0x40]=v; look up handler for current event id (ctx+0x1e) under key; found->jump, else ip+=8 (continue) | med |
| 121 | 0x79 | HANDLER_JMP_FN | u16 fn, i32 v | 7 | same but key = fn-table[idx]; not found -> yield | med |
| 122 | 0x7a | TERMINATE | — | 1 | terminate script (sets flag 0x4000), then stop | high |
| 123 | 0x7b | YIELD | — | 1 | stop executing this tick (end of handler/state body) | high |
| 124 | 0x7c | OP7C | u32 imm | 5 | FUN_005fbb00(ctx, imm) (unknown engine hook) | low |
| 125 | 0x7d | ARRAY_REF | u32 elemsize, u32 base, u32 countvar | 13 | pop idx; operands elemsize,base,countVar; bounds-check idx < d[countVar]; push varref = elemsize*idx+base+countVar | med |
| 126 | 0x7e | PUSH_STATE | — | 1 | push int current state (ctx+0x64) | high |
| 127 | 0x7f | STORE_O | u16 var | 3 | pop object -> var (refcounted) | high |
| 128 | 0x80 | STOREX_O | — | 1 | pop object, pop varref; store | high |
| 129 | 0x81 | LOAD_O | u16 var | 3 | push object var | high |
| 130 | 0x82 | NEWDEFAULT | cstring (NUL-terminated) | 2+strlen | push default value of named type ("int"->0,"float"->0.0, else construct object) | high |
| 133 | 0x85 | CAST | cstring (NUL-terminated) | 2+strlen | cast top of stack to named type (Fuzzy/Float/Bool/Int/... or object conversion) | med |
| 134 | 0x86 | SAT_F | — | 1 | pop float; push clamp(x,0,1) | high |
| 135 | 0x87 | LOAD_I2 | u16 var | 3 | push int var (alias of 0x2f) | high |
| 136 | 0x88 | ADDVV_I | u16 var dst, u16 var src | 5 | dst(int) += src | high |
| 137 | 0x89 | SUBVV_I | u16 var dst, u16 var src | 5 | dst(int) -= src | high |
| 138 | 0x8a | MULVV_I | u16 var dst, u16 var src | 5 | dst(int) *= src | high |
| 139 | 0x8b | DIVVV_I | u16 var dst, u16 var src | 5 | dst(int) /= src | high |
| 140 | 0x8c | ADDVV_F | u16 var dst, u16 var src | 5 | dst(float) += src | high |
| 141 | 0x8d | SUBVV_F | u16 var dst, u16 var src | 5 | -= | high |
| 142 | 0x8e | MULVV_F | u16 var dst, u16 var src | 5 | *= | high |
| 143 | 0x8f | DIVVV_F | u16 var dst, u16 var src | 5 | /= | high |
| 144 | 0x90 | FRAME | i32 n | 5 | n>=0: ENTER (push fp on call stack; fp = data-stack depth). n<0: LEAVE (erase -n slots below fp i.e. args; restore fp) | high |
| 145 | 0x91 | DUMPSTATE | — | 1 | dump VM state to log (debug) | high |
| 146 | 0x92 | SET_QUOTA | — | 1 | pop n; if n>=1 set per-tick instruction quota (ctx+8) else unlimited | med |
| 147 | 0x93 | SET_BUDGET | u32 n | 5 | set remaining-instruction counter for this tick | med |
| 148 | 0x94 | PUSH_I2 | i32 | 5 | push int imm (alias of 0x2b) | high |
| 149 | 0x95 | CALL_NATIVE | u16 str class, u16 str method, u16 hint, u32 flags | 11 | static/native call: class=str, method=str, hint u16, flags (see notes) | high |
| 150 | 0x96 | CALL_METHOD | u16 var obj, u16 str method, u16 hint, u32 flags | 11 | method call on object var: var, method=str, hint u16, flags | high |
| 151 | 0x97 | PUSH_STR | u16 str | 3 | push string literal (type 3 ptr); next instruction is not preempted | high |
| 152 | 0x98 | LOADX_O | — | 1 | pop varref; push object [varref] | high |
| 153 | 0x99 | PUSH_OBJ_82 | — | 1 | push engine object from ctx+0x82 (via factory 0x67a14c) | low |
| 154 | 0x9a | PUSH_OBJ_1A | — | 1 | push engine object from ctx+0x1a (current event object?) | low |
| 155 | 0x9b | EVLOCK | — | 1 | enter exclusive/locked mode (flags\|=0x9000) | low |
| 156 | 0x9c | EVUNLOCK | — | 1 | leave locked mode; may run pending events | low |
| 157 | 0x9d | NOP2 | — | 1 | NOP (alias of 0x00) | high |
| 158 | 0x9e | YIELD2 | — | 1 | alias of 0x7b | high |
| 131 | 0x83 | (invalid) | — | — | "Invalid script opcode" error | high |
| 132 | 0x84 | (invalid) | — | — | "Invalid script opcode" error | high |

## 2. VM model

### 2.1 Context and dispatch
* `ctx` = `in_ECX`, the script instance. `ctx+0xa6` = ip (byte pointer). Each step reads `op = *ip++`, so ip already points at the operands when the handler runs.
* **There is no common "advance by length" path.** Every handler adds its own operand size (`ip += 2/4/6/8/...`) or sets ip outright. The shared loop label (`switchD_005f6e22_default`, 0x5f57e7/0x5f57f3) only handles the tick/quota counters before the next fetch. `LAB_005f57e0` is just a shared `ip += 2` tail. A plain `break` from a case means "push int `local_70`" (the compare and logic ops), then loop. The lengths in the table come from those per-case adjustments.
* `ctx+0x34` = **data stack**: {ptr, cap, count@+0x3c} of 8-byte **typed slots** `{u32 value; u8 type}`. The types are 0 = empty, 1 = int, 2 = float, 3 = raw pointer (string literal / return address), 4 = refcounted engine object (vtbl+0x24 AddRef, +0x28 Release). Helpers:
 * `5f4f00` pop typed value
 * `5f4ff0` pop as int (raw)
 * `5f5020` pop as float
 * `5f4f70` drop
 * `5f4ec0(k)` peek
 * `5f5250` push int
 * `5f52f0` push float
 * `5f53f0` push ptr (type 3)
 * `5f5390` push object
 * `5f51e0` push typed value
 * `5f4fb0(n)`/`5f5050` drop n
 * `5f5520` erase a range
* `ctx+0x40` = **call stack**, a second typed stack with the same layout. It holds return addresses (type 3, pushed by `CALL`/`CALLA`, popped by `RET`) and saved frame pointers (`FRAME`).
* `ctx+0xaa` (u16) = frame pointer `fp`, the data-stack depth at function entry.
* `ctx+0x96` = program (class) object.
 * `prog+0x48` = global code offset of this program's first byte; `prog+0x54` = code pointer.
 * `prog+0x9c` = parent program. Inheritance chain: code offsets, strings and function indices are global across the chain.
 * `prog+0x104/+0x108` = function table (count, u32 code offsets).
 * `prog+0xa0..` = string table: {u16 first_id, count, u32 offs[], chars}.
 * `prog+0x40` = data offset of a "handler state" int, used by 0x72/0x74/0x75/0x78/0x79.
* `ctx+0x9e` = pointer to the instance **data block**: raw untyped 4-byte ints/floats/object handles, addressed by byte offset.
* `ctx+0x28` = array of **typed state-local slots** (8 bytes each, count at +0x30). These are re-initialised on state change (`FUN_006001e0` in `FUN_005f9130`).
* `ctx+0xac` (u16) = run flags. Low nibble = run state: 1 run, 2/3 sleeping, 4/5 waitforevent. 0x0800/0x8000 = inside event/nested execution, 0x4000 = terminate, 0x1000 = locked, 0x2000 = running. `ctx+0x0a` = wake time. `ctx+0x12` = start state. `ctx+0x64` = current state. `ctx+0x1e` (u16) = current event id. `ctx+0xaca` = callback/env object passed to native calls.
* Preemption: `local_74` (instruction budget, from `ctx+8` or op 0x93) and `local_78` (op 0x71) let a sleeping/event context run N more instructions. `PUSH_STR` adds 1 to the budget so that it stays bound to the following call.

### 2.2 Code addressing and jumps
* All branch targets (`JMP`, `JZ`, `JNZ`, `JZ_YIELD`, `CALLA`, `JMP_SETSV`, `JSV1/JNSV1`, switch entries) are **absolute u32 code offsets in the global code space**. `FUN_005f5620(off)` walks the program chain to find the program whose `[+0x48, +0x48+len)` contains `off`, then returns `prog.code + off - prog+0x48`.
* A file's own base is header dword `hdr+0x38` (the first of the six `h38` dwords in ppo_probe). Examples: Generic.sdl = 0; children of Generic = 12430 (0x308e) = Generic's code length. So `target - base` = offset into this file's code region. Targets below the base go to parent code (for example, `CALLA @0x0` = call the base-class constructor).
* `CALL fn#k` / `SETSTATE_FN` / `HANDLER_JMP_FN` index the function table (`prog+0x108[k]`, which holds code offsets).
* `JZ/JNZ` second operand: 1 = pop the condition, 0 = only peek (keeps the value for short-circuit `&&`/`||`).
* The switch table is laid out as described in the table. When `SWITCH_I` has a real default (≠0xFFFFFFFF), the compiler emits **8 dead bytes** after the table, which the VM never reads; the disassembler must skip them (seen in EnemySoldier.ppo). `SWITCH_FRANGE` ignores its default field and falls back to the last entry. No sample has a non-(-1) default for `SWITCH_FRANGE`, so whether it has the same padding is unverified.
* States: `SETSTATE x` (`FUN_005f9130`) takes a code offset. It runs the old state's exit handler (`ctx+0x6c`) and the new state's entry handler (`ctx+0x68`), clears both stacks, resets state-local slots and sets ip. Inside event handling (flags & 0x8800) it only records the state, and the VM skips the operand.

### 2.3 Variable operand encoding (u16 `var`, also the int `varref` popped by the `*X*` ops)
* `0x0000–0x7FFF`: byte offset into the instance data block `ctx+0x9e` (raw int/float/object handle). Shown as `d[0x..]`. A child class's own vars start at the parent's data size (Troy: 0x268 = 616 = `h38[5]`).
* `0xC000–0xFFFF` (bits 15 and 14 set): **stack-relative**, data-stack slot `fp + (int16)v`. 0xFFFF = fp-1 = last pushed argument, 0xFFFE = fp-2, and so on. Shown as `fp[-n]`.
* `0x8000–0xBFFF` (bit 15 set, bit 14 clear): **state-local typed slot** `ctx+0x28[ (~(v|0x4000)) & 0xFFFF ]` = `0x3FFF - (v & 0x3FFF)`. 0xBFFF = slot 0, 0xBFFE = slot 1. Shown as `g[n]`.
* Typed-slot writes go through helpers instead of raw stores: `00602cd0` set float, `0050d7b0` set int, `005002f0`/`00500360` int/float conversions, `3d40/3db0` add int/float, `4e00/4e60` mul, `40b0/4110` div, `3fc0` set object. This is the only difference between the two paths.

### 2.4 Calls
* **Script functions:** the caller pushes the args. `CALL fn#k` (or `CALLA off`) pushes the return ip on the call stack. The callee starts with `FRAME n` (ENTER: push fp on the call stack, fp = stack depth) and reads args as `fp[-1]` (last arg) ... `fp[-n]`. It ends with `FRAME -n` (LEAVE: erase the n arg slots, restore fp) and then `RET`. Return values are left on the data stack.
* **Native/engine calls:**
 * `CALL_NATIVE` (0x95): `u16 class_str, u16 method_str, u16 hint, u32 flags`. `CALL_METHOD` (0x96): `u16 objvar, u16 method_str, u16 hint, u32 flags`.
 * `flags & 0xFF` = number of return values (slots pushed). `(flags>>8) & 0xFF` = number of args taken from the stack top. `flags & 0x20000` = static call: the object is created by name from `class_str` via `ctx->vtbl[0](name)`. Otherwise the target object is popped from the stack top for 0x95, or read from `objvar` for 0x96.
 * The engine side is `obj->vtbl[0x14](&{method_name, args_view, rets_view, ctx+0xaca, hint})`. `hint` (u16) is passed through, probably a cached method/dispatch index. Its meaning is unconfirmed.
 * Example: `PUSH_STR "Troy"; CALL_NATIVE "String" "=CStr" 4, 0x20101` builds a String object from the literal.
* **Strings:** `u16` string ids are global across the inheritance chain. Per file, the table at blob offset `o7c` is `u32 first_id, u32 count, u32 offs[count]`, followed by NUL-terminated chars. `id - first_id` indexes `offs`. Generic: ids 0–319; C01A_Troy: 320–328. Inline C strings are used only by `WAITFORNAMEDEVENT`, `NEWDEFAULT` and `CAST`.
* **Events:** `HANDLER_JMP key, v` / `HANDLER_JMP_FN fn, v` optionally set the handler-state int (`d[prog+0x40]`) and look up the handler for the current event id `ctx+0x1e` under `key` (`FUN_005ffd70`). If found, they jump to it. If not found, HANDLER_JMP continues (ip+8) and HANDLER_JMP_FN stops the tick. `WAITFOREVENT`/`WAITFORNAMEDEVENT`/`SLEEP*` suspend. `YIELD` (0x7b/0x9e) ends the current run.

## 3. Python OPS dict

`*` = variable-length switch table: `u32 n, u32 default`, then `n × (value[i32 for 0x6b | f32 for 0x6c], u32 target)`, plus 8 skipped bytes if `default != 0xFFFFFFFF` (seen for 0x6b). `z` = inline NUL-terminated C string.

```python
OPS = {
    0x00: ('NOP', ''),
    0x01: ('INC_I', 'H'),
    0x02: ('DEC_I', 'H'),
    0x03: ('LNOT', ''),
    0x04: ('LAND_I', ''),
    0x05: ('LOR_I', ''),
    0x06: ('LOR_F', ''),
    0x07: ('LAND_F', ''),
    0x08: ('BNOT', ''),
    0x09: ('BAND', ''),
    0x0a: ('BOR', ''),
    0x0b: ('NEG_I', ''),
    0x0c: ('NEG_F', ''),
    0x0d: ('FNOT', ''),
    0x0e: ('ADD_F', ''),
    0x0f: ('ADD_I', ''),
    0x10: ('SUB_F', ''),
    0x11: ('SUB_I', ''),
    0x12: ('MUL_F', ''),
    0x13: ('MUL_I', ''),
    0x14: ('DIV_F', ''),
    0x15: ('DIV_I', ''),
    0x16: ('ADDV_F_IMM', 'Hf'),
    0x17: ('ADDV_I_IMM', 'Hi'),
    0x18: ('SUBV_F_IMM', 'Hf'),
    0x19: ('SUBV_I_IMM', 'Hi'),
    0x1a: ('MULV_F_IMM', 'Hf'),
    0x1b: ('MULV_I_IMM', 'Hi'),
    0x1c: ('DIVV_F_IMM', 'Hf'),
    0x1d: ('DIVV_I_IMM', 'Hi'),
    0x1e: ('ADDX_I_IMM', 'i'),
    0x1f: ('ADDX_F_IMM', 'f'),
    0x20: ('SUBX_I_IMM', 'i'),
    0x21: ('SUBX_F_IMM', 'f'),
    0x22: ('MULX_I_IMM', 'i'),
    0x23: ('MULX_F_IMM', 'f'),
    0x24: ('DIVX_I_IMM', 'i'),
    0x25: ('DIVX_F_IMM', 'f'),
    0x26: ('MAX_F', ''),
    0x27: ('MIN_F', ''),
    0x28: ('MAXV_F_IMM', 'Hf'),
    0x29: ('MINV_F_IMM', 'Hf'),
    0x2a: ('PUSH_F', 'f'),
    0x2b: ('PUSH_I', 'i'),
    0x2c: ('LOADX_I', ''),
    0x2d: ('LOADX_F', ''),
    0x2e: ('LOAD_F', 'H'),
    0x2f: ('LOAD_I', 'H'),
    0x30: ('LOAD_F2I', 'H'),
    0x31: ('LOAD_I2F', 'H'),
    0x32: ('STORE_F', 'H'),
    0x33: ('STORE_I', 'H'),
    0x34: ('STORE_F2I', 'H'),
    0x35: ('STORE_I2F', 'H'),
    0x36: ('ADDV_F', 'H'),
    0x37: ('ADDV_I', 'H'),
    0x38: ('SUBV_F', 'H'),
    0x39: ('SUBV_I', 'H'),
    0x3a: ('MULV_F', 'H'),
    0x3b: ('MULV_I', 'H'),
    0x3c: ('DIVV_F', 'H'),
    0x3d: ('DIVV_I', 'H'),
    0x3e: ('MINV_F', 'H'),
    0x3f: ('MAXV_F', 'H'),
    0x40: ('ADDX_I', ''),
    0x41: ('ADDX_F', ''),
    0x42: ('SUBX_I', ''),
    0x43: ('SUBX_F', ''),
    0x44: ('MULX_I', ''),
    0x45: ('MULX_F', ''),
    0x46: ('DIVX_I', ''),
    0x47: ('DIVX_F', ''),
    0x48: ('MINX_F', ''),
    0x49: ('MAXX_F', ''),
    0x4a: ('CALL', 'H'),
    0x4b: ('RET', ''),
    0x4c: ('POPN', 'I'),
    0x4d: ('JMP', 'I'),
    0x4e: ('JNZ', 'II'),
    0x4f: ('JZ', 'II'),
    0x50: ('JZ_YIELD', 'I'),
    0x51: ('SETSTATE', 'I'),
    0x52: ('SETSTATE_V', 'I'),
    0x53: ('SETSTATE_FN', 'H'),
    0x54: ('LT_I', ''),
    0x55: ('GT_I', ''),
    0x56: ('LE_I', ''),
    0x57: ('GE_I', ''),
    0x58: ('EQ_I', ''),
    0x59: ('NE_I', ''),
    0x5a: ('LT_F', ''),
    0x5b: ('GT_F', ''),
    0x5c: ('LE_F', ''),
    0x5d: ('GE_F', ''),
    0x5e: ('EQ_F', ''),
    0x5f: ('NE_F', ''),
    0x60: ('STOREX_I_IMM', 'i'),
    0x61: ('STOREX_F_IMM', 'f'),
    0x62: ('STOREX_I', ''),
    0x63: ('STOREX_F', ''),
    0x64: ('SETV_F', 'Hf'),
    0x65: ('SETV_I', 'Hi'),
    0x66: ('MOVV_F', 'HH'),
    0x67: ('MOVV_I', 'HH'),
    0x68: ('BREAK', ''),
    0x69: ('I2F', 'I'),
    0x6a: ('SWAP', ''),
    0x6b: ('SWITCH_I', '*'),
    0x6c: ('SWITCH_FRANGE', '*'),
    0x6d: ('SLEEP', ''),
    0x6e: ('SLEEP_IMM', 'If'),
    0x6f: ('WAITFOREVENT', ''),
    0x70: ('WAITFORNAMEDEVENT', 'z'),
    0x71: ('ATOMIC_N', 'I'),
    0x72: ('JMP_SETSV', 'Ii'),
    0x73: ('SETSTARTSTATE', 'I'),
    0x74: ('JSV1', 'I'),
    0x75: ('JNSV1', 'I'),
    0x76: ('CALLA', 'I'),
    0x77: ('CTOR_END', ''),
    0x78: ('HANDLER_JMP', 'Ii'),
    0x79: ('HANDLER_JMP_FN', 'Hi'),
    0x7a: ('TERMINATE', ''),
    0x7b: ('YIELD', ''),
    0x7c: ('OP7C', 'I'),
    0x7d: ('ARRAY_REF', 'III'),
    0x7e: ('PUSH_STATE', ''),
    0x7f: ('STORE_O', 'H'),
    0x80: ('STOREX_O', ''),
    0x81: ('LOAD_O', 'H'),
    0x82: ('NEWDEFAULT', 'z'),
    0x85: ('CAST', 'z'),
    0x86: ('SAT_F', ''),
    0x87: ('LOAD_I2', 'H'),
    0x88: ('ADDVV_I', 'HH'),
    0x89: ('SUBVV_I', 'HH'),
    0x8a: ('MULVV_I', 'HH'),
    0x8b: ('DIVVV_I', 'HH'),
    0x8c: ('ADDVV_F', 'HH'),
    0x8d: ('SUBVV_F', 'HH'),
    0x8e: ('MULVV_F', 'HH'),
    0x8f: ('DIVVV_F', 'HH'),
    0x90: ('FRAME', 'i'),
    0x91: ('DUMPSTATE', ''),
    0x92: ('SET_QUOTA', ''),
    0x93: ('SET_BUDGET', 'I'),
    0x94: ('PUSH_I2', 'i'),
    0x95: ('CALL_NATIVE', 'HHHI'),
    0x96: ('CALL_METHOD', 'HHHI'),
    0x97: ('PUSH_STR', 'H'),
    0x98: ('LOADX_O', ''),
    0x99: ('PUSH_OBJ_82', ''),
    0x9a: ('PUSH_OBJ_1A', ''),
    0x9b: ('EVLOCK', ''),
    0x9c: ('EVUNLOCK', ''),
    0x9d: ('NOP2', ''),
    0x9e: ('YIELD2', ''),
}

OPERAND_ROLES = { # same order as OPS format; V=var ref (u16), S=string id, F=function index, T=absolute code offset
    0x01: 'V',
    0x02: 'V',
    0x16: 'Vf',
    0x17: 'Vi',
    0x18: 'Vf',
    0x19: 'Vi',
    0x1a: 'Vf',
    0x1b: 'Vi',
    0x1c: 'Vf',
    0x1d: 'Vi',
    0x28: 'Vf',
    0x29: 'Vf',
    0x2e: 'V',
    0x2f: 'V',
    0x30: 'V',
    0x31: 'V',
    0x32: 'V',
    0x33: 'V',
    0x34: 'V',
    0x35: 'V',
    0x36: 'V',
    0x37: 'V',
    0x38: 'V',
    0x39: 'V',
    0x3a: 'V',
    0x3b: 'V',
    0x3c: 'V',
    0x3d: 'V',
    0x3e: 'V',
    0x3f: 'V',
    0x4a: 'F',
    0x4d: 'T',
    0x4e: 'TI',
    0x4f: 'TI',
    0x50: 'T',
    0x53: 'F',
    0x64: 'Vf',
    0x65: 'Vi',
    0x66: 'VV',
    0x67: 'VV',
    0x72: 'Ti',
    0x74: 'T',
    0x75: 'T',
    0x76: 'T',
    0x79: 'Fi',
    0x7f: 'V',
    0x81: 'V',
    0x87: 'V',
    0x88: 'VV',
    0x89: 'VV',
    0x8a: 'VV',
    0x8b: 'VV',
    0x8c: 'VV',
    0x8d: 'VV',
    0x8e: 'VV',
    0x8f: 'VV',
    0x95: 'SSHI',
    0x96: 'VSHI',
    0x97: 'S',
}
```

## 4. Linear decode of C01A_Troy code region

Code region: blob offset `o90`=580 → u32 size 220, then 220 bytes. File offsets 0x365–0x441; the addresses below are global code offsets (base 0x308e). The table produced **41 instructions and consumed exactly 220/220 bytes, with no unknown opcodes**. (Troy has only 41 instructions in total, so all of them are shown.) String names are resolved through Generic.ppo.

```
0308e 76 00 00 00 00 CALLA @0x0
03093 97 44 01 PUSH_STR str#324"Troy"
03096 95 77 00 76 00 04 00 01 01 0 CALL_NATIVE str#119"String", str#118"=CStr", 0x4, 0x20101
030a1 7f 70 02 STORE_O d[0x270]
030a4 97 45 01 PUSH_STR str#325"Troy_Chopper"
030a7 95 77 00 76 00 04 00 01 01 0 CALL_NATIVE str#119"String", str#118"=CStr", 0x4, 0x20101
030b2 96 18 00 7f 00 a1 00 01 01 0 CALL_METHOD d[0x18], str#127"getAnimHandle", 0xa1, 0x101
030bd 33 74 02 STORE_I d[0x274]
030c0 65 78 02 00 00 00 00 SETV_I d[0x278], 0
030c7 73 cd 30 00 00 SETSTARTSTATE 0x30cd
030cc 77 CTOR_END 
030cd 2f 68 02 LOAD_I d[0x268]
030d0 2f 6c 02 LOAD_I d[0x26c]
030d3 2b 01 00 00 00 PUSH_I 1
030d8 96 18 00 46 01 96 00 01 03 0 CALL_METHOD d[0x18], str#326"PlaceInMovingGroup", 0x96, 0x301
030e3 33 ff bf STORE_I g[0]
030e6 6e 01 00 00 00 00 00 20 41 SLEEP_IMM 0x1, 10
030ef 4d e6 30 00 00 JMP @0x30e6
030f4 4d cd 30 00 00 JMP @0x30cd
030f9 79 0d 00 00 00 00 00 HANDLER_JMP_FN fn#13, 0
03100 65 78 02 01 00 00 00 SETV_I d[0x278], 1
03107 2f 74 02 LOAD_I d[0x274]
0310a 4a 0c 00 CALL fn#12
0310d 6e 01 00 00 00 00 00 a0 40 SLEEP_IMM 0x1, 5
03116 2b 61 00 00 00 PUSH_I 97
0311b 81 70 02 LOAD_O d[0x270]
0311e 2b 01 00 00 00 PUSH_I 1
03123 96 18 00 2f 01 4b 00 01 03 0 CALL_METHOD d[0x18], str#303"PlaySound_Enum_On_Screen", 0x4b, 0x301
0312e 4c 01 00 00 00 POPN 0x1
03133 6e 01 00 00 00 00 00 20 41 SLEEP_IMM 0x1, 10
0313c 4d 33 31 00 00 JMP @0x3133
03141 4d 00 31 00 00 JMP @0x3100
03146 79 0d 00 00 00 00 00 HANDLER_JMP_FN fn#13, 0
0314d 2f 78 02 LOAD_I d[0x278]
03150 03 LNOT 
03151 4f 5f 31 00 00 01 00 00 00 JZ @0x315f, 0x1
0315a 51 00 31 00 00 SETSTATE 0x3100
0315f 7b YIELD 
03160 78 37 29 00 00 ff ff ff ff HANDLER_JMP 0x2937, -1
03169 7b YIELD 
consumed 220/220 clean
```
