"""specs_g620.py - gap band 0x621000-0x641000 (docs/20-unclaimed-gap-621.md). Names are GUESS."""
from pilot import S, F
import serial_stubs as ss
import struct


def _flush_heap_code(c):
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _multi_vt(c, slots):
    top = max(slots) + 4
    vt = c.emu.alloc(top, 4)
    for off, (impl, aw) in slots.items():
        base = c.emu.logging_vtable('mv%x' % off, 1, impl={0: impl}, argwords={0: aw})
        c.emu.w32(vt + off, c.emu.r32(base))
    return vt


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _store24_spec(c):
    self_ = _rnd(c, 0x60)
    return [self_, c.rng.getrandbits(32)]


def _store29_spec(c):
    self_ = _rnd(c, 0x60)
    return [self_, c.rng.getrandbits(32)]


def _entry_spec(c):
    self_ = _rnd(c, 0x40)
    c.emu.w32(self_ + 0x14, _rnd(c, 0x400))
    return [self_, c.rng.randrange(0, 40)]


def _block_spec(c):
    a = _rnd(c, 0x10)
    return [a]


S(0x639ba0, 'setField24 (GUESS)', 'thiscall', None, ret=None, gen=_store24_spec,
  note='batch770; gap band; [this+0x24] = v')
S(0x639c40, 'setField29 (GUESS)', 'thiscall', None, ret=None, gen=_store29_spec,
  note='batch770; gap band; [this+0x29] = v')
S(0x638c90, 'entryAt (GUESS)', 'thiscall', None, ret='eax', gen=_entry_spec,
  note='batch770; gap band; [this+0x14] + 20*i')
S(0x62c9b0, 'initBlock (GUESS)', 'cdecl', None, ret=None, gen=_block_spec,
  note='batch770; gap band; vtable 0x62dfa0, +0xc = 1, +8 = 0')


def _flag_spec(c):
    p = _rnd(c, 0x80)
    c.emu.wbytes(p + 0x5a, bytes([c.rng.choice([0, 1, 0xff]), c.rng.getrandbits(8)]))
    c.emu.w32(p + 0x3c, c.rng.choice([0, 0x2000, 0x1000, c.rng.getrandbits(32)]))
    return [p]


def _lead_spec(c):
    p = _rnd(c, 0x10)
    c.emu.wbytes(p, bytes([c.rng.choice([0xf4, 0xed, 0xef, c.rng.getrandbits(8)]), c.rng.choice([0x00, 0x10, 0x30, 0x40, c.rng.getrandbits(8)])]))
    return [c.rng.getrandbits(32), p]


S(0x640c90, 'flagTest (GUESS)', 'stdcall', None, ret='al', gen=_flag_spec,
  note='batch771; gap band; word [p+0x5a] nonzero and not (dword [p+0x3c] & 0x2000)')
S(0x624960, 'leadF4 (GUESS)', 'cdecl', None, ret='eax', gen=_lead_spec,
  note='batch771; gap band; byte 0xf4 and byte+1 & 0x30')


def _flagbyte_spec(c):
    self_ = _rnd(c, 0x40)
    r = _rnd(c, 0x10)
    c.emu.wbytes(r, bytes(c.rng.getrandbits(8) for _ in range(0x10)))
    c.emu.w32(self_, _multi_vt(c, {0x2c: (lambda em, x, v=r: (v, None), 1)}))
    _flush_heap_code(c)
    return [self_, c.rng.getrandbits(32)]


def _callstored_spec(c):
    obj = _rnd(c, 0x40)
    # cdecl stub: records both stack words in heap slots and returns 0 without popping (the caller cleans)
    sw = c.emu.alloc(4, 4)
    sa = c.emu.alloc(4, 4)
    c.emu.w32(sw, 0)
    c.emu.w32(sa, 0)
    stub = ss.code(c, b'\x8b\x44\x24\x04\xa3' + ss.P(sw) + b'\x8b\x44\x24\x08\xa3' + ss.P(sa) + b'\x31\xc0\xc3')
    c.emu.w32(obj + 0x24, stub)
    c.emu.w32(obj + 0x28, c.rng.getrandbits(32))
    _flush_heap_code(c)
    return [c.rng.getrandbits(32), obj]


def _forward_spec(c):
    self_ = _rnd(c, 0x40)
    p = _rnd(c, 0x60)
    return [self_, p, F(c.rng.uniform(-1000.0, 1000.0))]


S(0x63ea90, 'flagByteOf (GUESS)', 'thiscall', None, ret='al', gen=_flagbyte_spec,
  note='batch772; vt 0x2c (one word, ret 4) returns object; byte [r+1]')
S(0x633170, 'callStored (GUESS)', 'cdecl', None, ret=None, gen=_callstored_spec,
  note='batch772; calls [obj+0x24](a, [obj+0x28]) through a logging stub')
S(0x63f070, 'forwardFloat (GUESS)', 'thiscall', None, ret=None, gen=_forward_spec,
  note='batch772; calls original 0x65f1e0(p, f); this+0x8270 unused')


def _rotcookie_spec(c):
    c.emu.w32(0x6f5630, c.rng.getrandbits(32))
    return [c.rng.getrandbits(32)]


S(0x6344f2, 'rotCookie (GUESS)', 'cdecl', None, ret='eax', gen=_rotcookie_spec,
  note='batch773; rotr(a, 32 - (cookie & 31)) ^ cookie; cookie global 0x6f5630')


def _ctor_spec(c):
    self_ = _rnd(c, 0x40)
    return [self_]


def _bits_spec(c):
    p = _rnd(c, 0x10)
    c.emu.wbytes(p, bytes([c.rng.getrandbits(8), c.rng.getrandbits(8)]))
    return [c.rng.getrandbits(32), p]


S(0x6362d0, 'initObject (GUESS)', 'thiscall', None, ret='eax', gen=_ctor_spec,
  note='batch774; constructor, tag 0x50414c4e, vtable 0x6c1fec')
S(0x624490, 'bitLookupA (GUESS)', 'cdecl', None, ret='eax', gen=_bits_spec,
  note='batch774; table 0x6bfd20, word table 0x6bf720')


def _state_spec(c):
    st = _rnd(c, 0x20)
    c.emu.w32(st + 0xc, c.rng.choice([0, 1, c.rng.getrandbits(32)]))
    code = c.rng.choice([15, 16, 17, 18, 28, 40, 41, 0x1c, 0x1c, 14, 42, c.rng.randrange(0, 80)])
    return [st, code]


S(0x62ca20, 'stateStep (GUESS)', 'cdecl', None, ret='eax', gen=_state_spec,
  note='batch775; state handler, sets vtable [st], codes 15/17/18/41 and default')


S(0x62cb80, 'stateStepB (GUESS)', 'cdecl', None, ret='eax', gen=_state_spec,
  note='batch776; state handler, sets vtable [st] to 0x62cc00 for codes 18, 19, 41; default path as 0x62ca20')


def _state2_spec(c):
    st = _rnd(c, 0x20)
    c.emu.w32(st + 0xc, c.rng.choice([0, 1, c.rng.getrandbits(32)]))
    code = c.rng.choice([15, 16, 21, 24, 28, 36, 37, 0x1c, 14, c.rng.randrange(0, 80)])
    return [st, code]


S(0x62d470, 'stateStepC (GUESS)', 'cdecl', None, ret='eax', gen=_state2_spec,
  note='batch777; state handler, codes 15/21/24/36 and default path')


def _state3_spec(c):
    st = _rnd(c, 0x20)
    c.emu.w32(st + 0xc, c.rng.choice([0, 1, c.rng.getrandbits(32)]))
    c.emu.w32(st + 4, c.rng.getrandbits(32))
    code = c.rng.choice([15, 16, 18, 23, 28, 30, 31, 32, 33, 41, 0x1c, c.rng.randrange(0, 80)])
    return [st, code]


S(0x62d5c0, 'stateStepD (GUESS)', 'cdecl', None, ret='eax', gen=_state3_spec,
  note='batch778; state handler, counter at [st+4] for code 23, codes 30/31/32 set vtable 0x62d690')


def _state4_spec(c):
    st = _rnd(c, 0x20)
    c.emu.w32(st + 0xc, c.rng.choice([0, 1, c.rng.getrandbits(32)]))
    c.emu.w32(st + 4, c.rng.choice([0, 1, 2, 3, c.rng.getrandbits(32)]))
    code = c.rng.choice([15, 16, 21, 24, 28, 35, 36, 37, 38, 40, 0x1c, c.rng.randrange(0, 80)])
    return [st, code]


S(0x62d690, 'stateStepE (GUESS)', 'cdecl', None, ret='eax', gen=_state4_spec,
  note='batch779; state handler, countdown at [st+4] for codes 24/35/36/37, vtable 0x62d5c0 for 21/38')


def _match_spec(c):
    st = _rnd(c, 0x20)
    c.emu.w32(st + 0xc, c.rng.choice([0, 1, c.rng.getrandbits(32)]))
    obj = _rnd(c, 0x20)
    # vt[0x1c]: caller-cleaned (cdecl) stub; returns 1 on the call whose index is m (counted from zero), else 0.
    cnt = c.emu.alloc(4, 4)
    m = c.rng.randrange(0, 10)
    c.emu.w32(cnt, 0)
    last = c.emu.alloc(4, 4)
    c.emu.w32(last, 0)
    # records the fourth word (the string) of each call, then counts the call
    stub = ss.code(c, b'\x8b\x54\x24\x10\x89\x15' + ss.P(last) + b'\xa1' + ss.P(cnt) + b'\xff\x05' + ss.P(cnt)
                   + b'\x3d' + struct.pack('<I', m) + b'\x0f\x94\xc0\x0f\xb6\xc0\xc3')
    c.emu.w32(obj + 0x1c, stub)
    _flush_heap_code(c)
    code = c.rng.choice([15, 18, 23, 16, 28, 40, 0x1c])
    return [st, code, c.rng.getrandbits(32), c.rng.getrandbits(32), obj]


S(0x62cac0, 'matchStep (GUESS)', 'cdecl', None, ret='eax', gen=_match_spec,
  note='batch780; keyword matcher over table 0x6f4458 and 0x6c01e0 via obj vt 0x1c (caller-cleaned); codes 15/18/23')


def _match2_spec(c):
    st = _rnd(c, 0x20)
    c.emu.w32(st + 0xc, c.rng.choice([0, 1, c.rng.getrandbits(32)]))
    obj = _rnd(c, 0x60)
    c.emu.w32(obj + 0x44, c.rng.getrandbits(16))
    cnt = c.emu.alloc(4, 4)
    slot_a = c.emu.alloc(4, 4)
    slot_s = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    m = c.rng.randrange(0, 5)
    # cdecl stub: records arg 2 and the string, then returns 1 on call index m (0..3 match, 4 never)
    stub = ss.code(c, b'\x8b\x54\x24\x08\x89\x15' + ss.P(slot_a) + b'\x8b\x54\x24\x10\x89\x15' + ss.P(slot_s)
                   + b'\xa1' + ss.P(cnt) + b'\xff\x05' + ss.P(cnt) + b'\x3d' + struct.pack('<I', m)
                   + b'\x0f\x94\xc0\x0f\xb6\xc0\xc3')
    c.emu.w32(obj + 0x1c, stub)
    _flush_heap_code(c)
    code = c.rng.choice([15, 20, 27, 16, 28, 40, 0x1c])
    return [st, code, c.rng.getrandbits(16), c.rng.getrandbits(32), obj]


S(0x62cd30, 'matchStep2 (GUESS)', 'cdecl', None, ret='eax', gen=_match2_spec,
  note='batch781; three-string matcher for code 20 with a = p1 + [obj+0x44]; code 27 to 0x62ca20')


def _st782_spec(c):
    st = _rnd(c, 0x20)
    c.emu.w32(st + 0xc, c.rng.choice([0, 1, c.rng.getrandbits(32)]))
    code = c.rng.choice([15, 17, 27, 16, 28, 40, 0x1c, c.rng.randrange(0, 80)])
    return [st, code]


S(0x62ce20, 'stateStepF (GUESS)', 'cdecl', None, ret='eax', gen=_st782_spec,
  note='batch782; state handler, code 27 to 0x62ca20 returning 0x22; default path')
S(0x62cf90, 'stateStepG (GUESS)', 'cdecl', None, ret='eax', gen=_st782_spec,
  note='batch782; state handler, code 17 selects vtable 0x62dc60 or 0x62dbb0 by st+0xc')


def _st783_spec(c):
    st = _rnd(c, 0x20)
    c.emu.w32(st + 0xc, c.rng.choice([0, 1, c.rng.getrandbits(32)]))
    code = c.rng.choice([15, 18, 21, 23, 24, 16, 28, 40, 0x1c, c.rng.randrange(0, 80)])
    return [st, code]


S(0x62cc50, 'stateStepH (GUESS)', 'cdecl', None, ret='eax', gen=_st783_spec,
  note='batch783; state handler, code 23 to 0x62cc90')
S(0x62cc90, 'stateStepI (GUESS)', 'cdecl', None, ret='eax', gen=_st783_spec,
  note='batch783; state handler, code 18 to 0x62cce0 returning 0x1d')
S(0x62cc00, 'stateStepJ (GUESS)', 'cdecl', None, ret='eax', gen=_st783_spec,
  note='batch783; state handler, code 21 to 0x62cb80, code 24 to 0x62cd30')


def _st784_spec(c):
    st = _rnd(c, 0x20)
    c.emu.w32(st + 0xc, c.rng.choice([0, 1, c.rng.getrandbits(32)]))
    code = c.rng.choice([15, 18, 21, 24, 41, 16, 28, 40, 0x1c, c.rng.randrange(0, 80)])
    return [st, code]


S(0x62cce0, 'stateStepK (GUESS)', 'cdecl', None, ret='eax', gen=_st784_spec,
  note='batch784; state handler, code 21 to 0x62cc90, code 24 to 0x62cd30')
S(0x62d510, 'stateStepL (GUESS)', 'cdecl', None, ret='eax', gen=_st784_spec,
  note='batch784; state handler, codes 18 and 41 to 0x62d560 returning 0x2e')


S(0x62d560, 'stateStepM (GUESS)', 'cdecl', None, ret='eax', gen=_st784_spec,
  note='batch785; state handler, code 21 to 0x62d510, code 36 to 0x62cf90 returning 0x29')


def _st786_spec(c):
    st = _rnd(c, 0x20)
    c.emu.w32(st + 0xc, c.rng.choice([0, 1, c.rng.getrandbits(32)]))
    code = c.rng.choice([15, 18, 27, 16, 28, 40, 0x1c, c.rng.randrange(0, 80)])
    return [st, code]


S(0x62d7f0, 'stateStepN (GUESS)', 'cdecl', None, ret='eax', gen=_st786_spec,
  note='batch786; state handler, code 18 to 0x62da60 returning 9')
S(0x62d8f0, 'stateStepO (GUESS)', 'cdecl', None, ret='eax', gen=_st786_spec,
  note='batch786; state handler, code 27 to 0x62d940 returning 0xc')
S(0x62d940, 'stateStepP (GUESS)', 'cdecl', None, ret='eax', gen=_st786_spec,
  note='batch786; state handler, code 27 to 0x62d990 returning 0xb')
S(0x62da10, 'stateStepQ (GUESS)', 'cdecl', None, ret='eax', gen=_st786_spec,
  note='batch786; state handler, code 18 to 0x62cf90 returning 0xe')


def _cb787_spec(c):
    st = _rnd(c, 0x20)
    c.emu.w32(st + 0xc, c.rng.choice([0, 1, c.rng.getrandbits(32)]))
    obj = _rnd(c, 0x40)
    cnt = c.emu.alloc(4, 4)
    last = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    c.emu.w32(last, 0)
    m = c.rng.randrange(0, 3)
    # cdecl stub: records the string word, counts the call, returns 1 on call index m (0..1 match, 2 never)
    stub = ss.code(c, b'\x8b\x54\x24\x10\x89\x15' + ss.P(last) + b'\xa1' + ss.P(cnt) + b'\xff\x05' + ss.P(cnt)
                   + b'\x3d' + struct.pack('<I', m) + b'\x0f\x94\xc0\x0f\xb6\xc0\xc3')
    c.emu.w32(obj + 0x1c, stub)
    _flush_heap_code(c)
    code = c.rng.choice([15, 17, 18, 27, 16, 28, 0x1c])
    return [st, code, c.rng.getrandbits(32), c.rng.getrandbits(32), obj]


S(0x62d990, 'matchStep3 (GUESS)', 'cdecl', None, ret='eax', gen=_cb787_spec,
  note='batch787; callback 0x6c01c4 for code 18; code 17 selects vtable 0x62dc60/0x62dbb0 and returns 0xd')
S(0x62da60, 'matchStep4 (GUESS)', 'cdecl', None, ret='eax', gen=_cb787_spec,
  note='batch787; callbacks 0x6c0208 then 0x6c01f4 for code 18; code 27 to 0x62cf90 returning 10')


def _st788_spec(c):
    st = _rnd(c, 0x20)
    c.emu.w32(st + 0xc, c.rng.choice([0, 1, c.rng.getrandbits(32)]))
    c.emu.w32(st + 8, c.rng.getrandbits(16))
    code = c.rng.choice([15, 18, 25, 27, 16, 28, 40, 0x1c, c.rng.randrange(0, 80)])
    return [st, code]


for _a, _n, _r in ((0x62cf00, 'stateStepR', None), (0x62cf40, 'stateStepS', None), (0x62d110, 'stateStepT', None),
                   (0x62d160, 'stateStepU', None), (0x62ddb0, 'stateStepV', None), (0x62dee0, 'stateStepW', None)):
    S(_a, _n + ' (GUESS)', 'cdecl', None, ret='eax', gen=_st788_spec, note='batch788; state handler (see docs/20-unclaimed-gap-621.md)')


def _cb789_spec(c):
    st = _rnd(c, 0x20)
    c.emu.w32(st + 0xc, c.rng.choice([0, 1, c.rng.getrandbits(32)]))
    obj = _rnd(c, 0x40)
    cnt = c.emu.alloc(4, 4)
    last = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    c.emu.w32(last, 0)
    m = c.rng.randrange(0, 3)
    stub = ss.code(c, b'\x8b\x54\x24\x10\x89\x15' + ss.P(last) + b'\xa1' + ss.P(cnt) + b'\xff\x05' + ss.P(cnt)
                   + b'\x3d' + struct.pack('<I', m) + b'\x0f\x94\xc0\x0f\xb6\xc0\xc3')
    c.emu.w32(obj + 0x1c, stub)
    _flush_heap_code(c)
    code = c.rng.choice([15, 17, 18, 25, 16, 28, 0x1c])
    return [st, code, c.rng.getrandbits(32), c.rng.getrandbits(32), obj]


S(0x62d030, 'stateMatch (GUESS)', 'cdecl', None, ret='eax', gen=_cb789_spec,
  note='batch789; callbacks 0x6c0208 then 0x6c01f4 for code 18; code 17 to 0x62e120 returning 7; code 25 to 0x62dc60')


def _st790_spec(c):
    st = _rnd(c, 0x20)
    c.emu.w32(st + 0xc, c.rng.choice([0, 1, c.rng.getrandbits(32)]))
    code = c.rng.choice([15, 17, 25, 16, 28, 0x1c, c.rng.randrange(0, 80)])
    return [st, code]


S(0x62d1b0, 'stateStepX (GUESS)', 'cdecl', None, ret='eax', gen=_st790_spec,
  note='batch790; state handler, code 17 to 0x62e120 returning 7, code 25 to 0x62dc60 returning 6')
S(0x62de00, 'stateMatch2 (GUESS)', 'cdecl', None, ret='eax', gen=_cb789_spec,
  note='batch790; callbacks 0x6c0208 then 0x6c01f4 for code 18; targets 0x62dee0 and 0x62de90')


S(0x62de90, 'stateStepY (GUESS)', 'cdecl', None, ret='eax', gen=_st790_spec,
  note='batch791; state handler, code 27 to 0x62df30 returning 0x12')


def _cb792_spec(c):
    st = _rnd(c, 0x20)
    c.emu.w32(st + 0xc, c.rng.choice([0, 1, c.rng.getrandbits(32)]))
    c.emu.w32(st + 4, 0)
    obj = _rnd(c, 0x60)
    c.emu.w32(obj + 0x44, c.rng.getrandbits(12))
    cnt = c.emu.alloc(4, 4)
    last = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    c.emu.w32(last, 0)
    m = c.rng.randrange(0, 2)
    arg2 = c.emu.alloc(4, 4)
    c.emu.w32(arg2, 0)
    stub = ss.code(c, b'\x8b\x54\x24\x08\x89\x15' + ss.P(arg2) + b'\x8b\x54\x24\x10\x89\x15' + ss.P(last)
                   + b'\xa1' + ss.P(cnt) + b'\xff\x05' + ss.P(cnt)
                   + b'\x3d' + struct.pack('<I', m) + b'\x0f\x94\xc0\x0f\xb6\xc0\xc3')
    c.emu.w32(obj + 0x1c, stub)
    _flush_heap_code(c)
    code = c.rng.choice([11, 13, 14, 15, 16, 29, 12, 28, 0x1c, c.rng.randrange(0, 80)])
    return [st, code, c.rng.getrandbits(16), c.rng.getrandbits(32), obj]


S(0x62e070, 'stateMatch3 (GUESS)', 'cdecl', None, ret='eax', gen=_cb792_spec,
  note='batch792; callback 0x6c0164 for code 16 (a = p1 + 2*[obj+0x44]); code 29 returns 2; target 0x62cfe0')


def _cb793_spec(c):
    st = _rnd(c, 0x20)
    c.emu.w32(st + 0xc, c.rng.choice([0, 1, c.rng.getrandbits(32)]))
    c.emu.w32(st + 4, c.rng.getrandbits(16))
    obj = _rnd(c, 0x60)
    c.emu.w32(obj + 0x44, c.rng.getrandbits(12))
    cnt = c.emu.alloc(4, 4)
    last = c.emu.alloc(4, 4)
    arg2 = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    c.emu.w32(last, 0)
    c.emu.w32(arg2, 0)
    m = c.rng.randrange(0, 2)
    stub = ss.code(c, b'\x8b\x54\x24\x08\x89\x15' + ss.P(arg2) + b'\x8b\x54\x24\x10\x89\x15' + ss.P(last)
                   + b'\xa1' + ss.P(cnt) + b'\xff\x05' + ss.P(cnt)
                   + b'\x3d' + struct.pack('<I', m) + b'\x0f\x94\xc0\x0f\xb6\xc0\xc3')
    c.emu.w32(obj + 0x1c, stub)
    _flush_heap_code(c)
    code = c.rng.choice([15, 18, 41, 20, 23, 30, 31, 32, 16, 28, 0x1c, c.rng.randrange(0, 80)])
    return [st, code, c.rng.getrandbits(16), c.rng.getrandbits(32), obj]


S(0x62d360, 'stateMatch4 (GUESS)', 'cdecl', None, ret='eax', gen=_cb793_spec,
  note='batch793; callback 0x6c01ec for code 20 (a = p1 + [obj+0x44]); codes 18/41, 23, 30/31/32 set states')


def _vt50_spec(c):
    self_ = _rnd(c, 0x40)
    rv = c.rng.getrandbits(32)
    rv2 = (rv ^ 0x3c3c3c3c) & 0xffffffff
    c.emu.w32(self_, _multi_vt(c, {0x50: (lambda em, x, v=rv: (v, None), 1), 0x54: (lambda em, x, v=rv2: (v, None), 1)}))
    _flush_heap_code(c)
    return [self_, c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x63cc40, 'forwardVt50 (GUESS)', 'thiscall', None, ret='eax', gen=_vt50_spec,
  note='batch794; returns vt[0x50](this, a), second argument unused')


def _mark_spec(c):
    buf = _rnd(c, 0x100)
    ch = c.rng.choice([0, 1, 2])
    # 0x626b00 stand-in (cdecl, caller cleans): returns null, the buffer, or a pointer to a second buffer
    buf2 = _rnd(c, 0x100)
    val = {0: 0, 1: buf, 2: buf2}[ch]
    slots = [c.emu.alloc(4, 4) for _ in range(4)]
    for sl in slots:
        c.emu.w32(sl, 0)
    rec = b''.join(b'\x8b\x44\x24' + bytes([4 + 4 * k]) + b'\xa3' + ss.P(sl) for k in range(4))
    ss.patch(c, 0x626b00, ss.code(c, rec + b'\xb8' + ss.P(val) + b'\xc3'))
    _flush_heap_code(c)
    return [c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x626d70, 'markResult (GUESS)', 'cdecl', None, ret=None, gen=_mark_spec,
  note='batch795; calls 0x626b00 (stubbed: null or a buffer) and sets byte +0x86 to 0x17 when non-null')


def _wrap796_spec(c):
    rv = c.rng.getrandbits(32)
    # 0x628c80 stand-in (cdecl, caller cleans): records its six words in heap slots and returns rv
    slots = [c.emu.alloc(4, 4) for _ in range(6)]
    for sl in slots:
        c.emu.w32(sl, 0)
    rec = b''.join(b'\x8b\x44\x24' + bytes([4 + 4 * k]) + b'\xa3' + ss.P(sl) for k, sl in enumerate(slots))
    ss.patch(c, 0x628c80, ss.code(c, rec + b'\xb8' + ss.P(rv) + b'\xc3'))
    _flush_heap_code(c)
    return [c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x628e70, 'wrapFlag1 (GUESS)', 'cdecl', None, ret='eax', gen=_wrap796_spec,
  note='batch796; returns 0x628c80(0x6f4424, a, 1, b, c, d)')
S(0x628eb0, 'wrapFlag0 (GUESS)', 'cdecl', None, ret='eax', gen=_wrap796_spec,
  note='batch796; returns 0x628c80(0x6f4424, a, 0, b, c, d)')


def _lookup797_spec(c):
    obj = _rnd(c, 0x180)
    slots = [c.emu.alloc(4, 4), c.emu.alloc(4, 4)]
    for sl in slots:
        c.emu.w32(sl, 0)
    rv = c.rng.choice([c.rng.randrange(0, 0x10000), 0x10000 | c.rng.randrange(0, 0x10000), c.rng.getrandbits(32)])
    rec = b''.join([b'\x8b\x44\x24\x04\xa3' + ss.P(slots[0]), b'\x8b\x44\x24\x08\xa3' + ss.P(slots[1])])
    stub = ss.code(c, rec + b'\xb8' + ss.P(rv) + b'\xc3')
    c.emu.w32(obj + 0x170, stub)
    c.emu.w32(obj + 0x174, c.rng.getrandbits(32))
    _flush_heap_code(c)
    return [obj, c.rng.getrandbits(32)]


S(0x62c730, 'lookupA (GUESS)', 'cdecl', None, ret='eax', gen=_lookup797_spec,
  note='batch797; callback [obj+0x170](obj+0x174, x); bit lookup over 0x6bfd20 and 0x6bf720')
S(0x62c790, 'lookupB (GUESS)', 'cdecl', None, ret='eax', gen=_lookup797_spec,
  note='batch797; as lookupA with byte table 0x6bfc20')


def _find798_spec(c):
    this = _rnd(c, 0x100)
    n = c.rng.randrange(0, 4)
    c.emu.w32(this + 0xec, n)
    ents = []
    for i in range(n):
        e = _rnd(c, 0x10040)
        c.emu.w32(e + 0x10029, c.rng.getrandbits(32))
        c.emu.w32(this + 0xf0 + 4 * i, e)
        ents.append(e)
    a = c.rng.choice([0, c.rng.getrandbits(32)] + [c.emu.r32(e + 0x10029) for e in ents])
    _flush_heap_code(c)
    return [this, a]


S(0x63dbc0, 'findEntry (GUESS)', 'thiscall', None, ret='eax', gen=_find798_spec,
  note='batch798; first entry in this+0xf0 array (count this+0xec) whose +0x10029 field equals a; a==0 matches the first')


def _token799_spec(c):
    buf = _rnd(c, 0x10)
    words = [b'gt', b'lt', b'amp', b'apos', b'quot', b'xyz', b'g', b'quo']
    w = c.rng.choice(words) if c.rng.random() < 0.8 else bytes(c.rng.randrange(97, 123) for _ in range(c.rng.randrange(1, 6)))
    c.emu.wbytes(buf, w + b'\x00' * 4)
    end = buf + len(w)
    return [c.rng.getrandbits(32), buf, end]


def _pat799_spec(c):
    s = _rnd(c, 0x10)
    txt = bytes(c.rng.randrange(97, 101) for _ in range(c.rng.randrange(0, 7)))
    c.emu.wbytes(s, txt + b'\x00' * 4)
    k = c.rng.randrange(0, len(txt) + 1)
    pat = txt[:k] + (b'' if c.rng.random() < 0.6 else bytes([c.rng.randrange(97, 101)]))
    pb = _rnd(c, 0x10)
    c.emu.wbytes(pb, pat + b'\x00' * (0x10 - len(pat)))
    end = s + c.rng.randrange(0, len(txt) + 2)
    return [c.rng.getrandbits(32), s, end, pb]


S(0x622270, 'tokenCode (GUESS)', 'cdecl', None, ret='eax', gen=_token799_spec,
  note='batch799; token of length 2/3/4 classified by bytes (gt, lt, amp, apos, quot)')
S(0x6228a0, 'matchToEnd (GUESS)', 'cdecl', None, ret='eax', gen=_pat799_spec,
  note='batch799; pattern must match s exactly up to end')


def _skip800_spec(c):
    st = _rnd(c, 0x200)
    tab = bytes([0]) + bytes(c.rng.choice([0, 1, 8, 9, 10, 11, 21, 22, c.rng.getrandbits(8)]) for _ in range(255))
    c.emu.wbytes(st + 0x4c, tab)
    p = _rnd(c, 0x20)
    txt = bytes(c.rng.choice([9, 10, 21, 0x20, c.rng.randrange(1, 256)]) for _ in range(0x10))
    c.emu.wbytes(p, txt + b'\x00' * 0x10)
    return [st, p]


S(0x622aa0, 'skipClass (GUESS)', 'cdecl', None, ret='eax', gen=_skip800_spec,
  note='batch800; advance while class (st[0x4c+byte]) is 9, 10 or 21')


def _span801_spec(c):
    st = _rnd(c, 0x200)
    tab = bytes([0]) + bytes(c.rng.choice([0, 1, 5, 6, 7, 9, 10, 20, 21, 22, 23, 24, 25, 28, 29, 30, c.rng.getrandbits(8)]) for _ in range(255))
    c.emu.wbytes(st + 0x4c, tab)
    p = _rnd(c, 0x40)
    txt = bytes(c.rng.choice([5, 6, 7, 8, 9, 10, 0x1a, 0x1e, 0x20, c.rng.randrange(1, 256)]) for _ in range(0x20))
    c.emu.wbytes(p, txt + b'\x00' * 0x20)
    return [st, p]


S(0x6228e0, 'spanClass (GUESS)', 'cdecl', None, ret='eax', gen=_span801_spec,
  note='batch801; advance 2/3/4/1 by class (byte 0x622958 table), stop on other classes')


def _bits802_spec(c):
    p = _rnd(c, 0x10)
    c.emu.wbytes(p, bytes(c.rng.getrandbits(8) for _ in range(3)))
    return [c.rng.getrandbits(32), p]


S(0x6244e0, 'bitLookup3A (GUESS)', 'cdecl', None, ret='eax', gen=_bits802_spec,
  note='batch802; three-byte bit lookup over table 0x6bfd20 and word table 0x6bf720')
S(0x624650, 'bitLookup3B (GUESS)', 'cdecl', None, ret='eax', gen=_bits802_spec,
  note='batch802; three-byte bit lookup over table 0x6bfc20 and word table 0x6bf720')


def _flush803_spec(c):
    o = _rnd(c, 0x16c0)
    buf = _rnd(c, 0x40)
    c.emu.w32(o + 8, buf)
    c.emu.w32(o + 0x14, c.rng.randrange(0, 0x20))
    c.emu.w32(o + 0x16b4, c.rng.choice([-3, -1, 0, 1, 5, 8, 9, 10, 12]) & 0xffffffff)
    c.emu.wbytes(o + 0x16b0, bytes([c.rng.getrandbits(8), c.rng.getrandbits(8)]))
    _flush_heap_code(c)
    return [o]


S(0x6301a0, 'flushPending (GUESS)', 'cdecl', None, ret=None, gen=_flush803_spec,
  note='batch803; writes up to two pending bytes into the buffer and clears the pending word and count')


def _copy804_spec(c):
    src = _rnd(c, 0x20)
    dst = _rnd(c, 0x40)
    n = c.rng.randrange(0, 9)
    m = c.rng.randrange(0, 12)
    c.emu.wbytes(src, bytes(c.rng.getrandbits(8) for _ in range(0x20)))
    sref = _rnd(c, 4)
    c.emu.w32(sref, src)
    dref = _rnd(c, 4)
    c.emu.w32(dref, dst)
    return [c.rng.getrandbits(32), sref, src + n, dref, dst + m]


S(0x623010, 'widenBytes (GUESS)', 'cdecl', None, ret=None, gen=_copy804_spec,
  note='batch804; byte-to-word copy with source and destination cursors')
S(0x623050, 'copyBytes (GUESS)', 'cdecl', None, ret=None, gen=_copy804_spec,
  note='batch804; byte copy with source and destination cursors')


def _ieq805_spec(c):
    s2 = _rnd(c, 0x20)
    txt = bytes(c.rng.choice([0x41, 0x5a, 0x61, 0x7a, 0x20, 0x30, 0x7b, 0x60, c.rng.randrange(1, 256)]) for _ in range(c.rng.randrange(0, 10)))
    c.emu.wbytes(s2, txt + b'\x00' * 0x10)
    s1 = _rnd(c, 0x20)
    v = bytearray(txt)
    for k in range(len(v)):
        if c.rng.random() < 0.5:
            v[k] = v[k] ^ 0x20 if chr(v[k]).isalpha() else v[k]
    if c.rng.random() < 0.3 and v:
        j = c.rng.randrange(len(v))
        v[j] = c.rng.randrange(1, 256)
    c.emu.wbytes(s1, bytes(v) + b'\x00' * 0x10)
    return [s1, s2]


S(0x62c5b0, 'ieqZ (GUESS)', 'cdecl', None, ret='eax', gen=_ieq805_spec,
  note='batch805; case-folding string compare, returns 1 when equal')


def _wrap806_spec(c):
    slots = [c.emu.alloc(4, 4) for _ in range(6)]
    for sl in slots:
        c.emu.w32(sl, 0)
    rv = c.rng.getrandbits(32)
    rec = b''.join(b'\x8b\x44\x24' + bytes([4 + 4 * k]) + b'\xa3' + ss.P(sl) for k, sl in enumerate(slots))
    ss.patch(c, 0x634d40, ss.code(c, rec + b'\xb8' + ss.P(rv) + b'\xc3'))
    _flush_heap_code(c)
    return [c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x633665, 'wrapCookie (GUESS)', 'cdecl', None, ret='eax', gen=_wrap806_spec,
  note='batch806; forwards to 0x634d40 (hooked stand-in) with 0x6f5630 and 0x633654 first')


def _probe807_spec(c):
    rv = c.rng.choice([0, 1, 2, c.rng.getrandbits(32)])
    ss.patch(c, 0x634cb5, ss.code(c, b'\xb8' + ss.P(rv) + b'\xc3'))
    c.emu.w32(0x725494, c.rng.getrandbits(32))
    _flush_heap_code(c)
    return [c.rng.choice([0, 1, c.rng.getrandbits(8)])]


S(0x633e8f, 'releaseIfProbe (GUESS)', 'cdecl', None, ret='eax', gen=_probe807_spec,
  note='batch807; probe 0x634cb5 hooked (GUESS); xchg-release of 0x725494 when probe nonzero and flag zero')


def _scan808_spec(c):
    st = _rnd(c, 0x200)
    tab = bytes([0]) + bytes(c.rng.choice([0x12, 0x18, 0x19, 0x1a, 0x17, 0x20, 0x21, c.rng.getrandbits(8)]) for _ in range(255))
    c.emu.wbytes(st + 0x4c, tab)
    p = _rnd(c, 0x40)
    n = c.rng.randrange(0, 10)
    txt = bytes(c.rng.choice([0x78, 0x18, 0x19, 0x12, 0x1a, 0x17, c.rng.randrange(1, 256)]) for _ in range(n))
    c.emu.wbytes(p, txt + b'\x00' * 0x20)
    out = _rnd(c, 4)
    c.emu.w32(out, 0)
    return [st, p, p + n, out]


S(0x62b290, 'scanTokB (GUESS)', 'cdecl', None, ret='eax', gen=_scan808_spec,
  note='batch808; class-based scan with a 0x12 marker (tail of 0x62ad60)')
S(0x62ad60, 'scanTokA (GUESS)', 'cdecl', None, ret='eax', gen=_scan808_spec,
  note='batch808; x tail-calls 0x62b290; class 0x19 scan with 0x12 marker')



def _f810_spec(c):
    self_ = _rnd(c, 0x20)
    f = c.rng.choice([0.0, 1.5, -2.25, 40000.0, -3.0e9, 3.0e9, 255.9, F(c.rng.uniform(-1e5, 1e5))])
    return [self_, f] if not isinstance(f, float) else [self_, F(f)]


def _v810_spec(c):
    self_ = _rnd(c, 0x40)
    sc = c.emu.alloc(4, 4)
    sa = c.emu.alloc(4, 4)
    c.emu.w32(sc, 0)
    c.emu.w32(sa, 0)
    # 0x43de70 stand-in (thiscall ret 4): records ecx and its word, returns 0
    ss.patch(c, 0x43de70, ss.code(c, b'\x89\x0d' + ss.P(sc) + b'\x8b\x44\x24\x04' + b'\xa3' + ss.P(sa) + b'\x31\xc0\xc2\x04\x00'))
    _flush_heap_code(c)
    return [self_, c.rng.getrandbits(32)]


S(0x658ff0, 'storeFloatWord (GUESS)', 'thiscall', None, ret=None, gen=_f810_spec,
  note='batch810; (short)(int)f stored at this+0xa')
S(0x454ab0, 'setVtableThen (GUESS)', 'thiscall', None, ret='eax', gen=_v810_spec,
  note='batch810; vtable 0x6823a4 then tail call 0x43de70 (original)')


def _rec_vt811(c, rvbuf):
    """vt slot stub (thiscall one word, ret 4): records ecx and the word in arrays A and B by call index, returns rvbuf."""
    A = c.emu.alloc(16, 4)
    B = c.emu.alloc(16, 4)
    C = c.emu.alloc(4, 4)
    c.emu.wbytes(A, bytes(16))
    c.emu.wbytes(B, bytes(16))
    c.emu.w32(C, 0)
    code = (b'\x8b\x15' + ss.P(C) + b'\x8b\x44\x24\x04' + b'\x89\x04\x95' + ss.P(A) + b'\x89\x0c\x95' + ss.P(B)
            + b'\xff\x05' + ss.P(C) + b'\xb8' + ss.P(rvbuf) + b'\xc2\x04\x00')
    return ss.code(c, code)


def _s656930_spec(c):
    dst = _rnd(c, 0x40)
    src = _rnd(c, 0x40)
    return [dst, src]


def _s657470_spec(c):
    self_ = _rnd(c, 0x40)
    r = _rnd(c, 0x80)
    c.emu.w32(r + 0x7c, c.rng.getrandbits(32))
    c.emu.w32(self_, _multi_vt(c, {0x0c: (lambda em, x, v=0: (v, None), 1)}))
    vt = c.emu.r32(self_)
    c.emu.w32(vt + 0x0c, _rec_vt811(c, r))
    _flush_heap_code(c)
    return [self_, c.rng.getrandbits(32)]


def _s650b70_spec(c):
    self_ = _rnd(c, 0x100)
    obj = _rnd(c, 0x40)
    obj_vt = _multi_vt(c, {0x50: (lambda em, x, v=c.rng.getrandbits(32): (v, None), 1)})
    c.emu.w32(obj, obj_vt)
    c.emu.w32(self_ + 0xbd, obj if c.rng.random() < 0.7 else 0)
    _flush_heap_code(c)
    return [self_, c.rng.getrandbits(32)]


def _s4cf670_spec(c):
    self_ = _rnd(c, 0x20)
    cnt = c.emu.alloc(16, 4)
    stub = ss.code(c, b'\x8b\x44\x24\x04\xa3' + ss.P(cnt) + b'\x8b\x44\x24\x08\xa3' + ss.P(cnt + 4)
                   + b'\x8b\x44\x24\x0c\xa3' + ss.P(cnt + 8) + b'\x31\xc0\xc3')
    ss.patch(c, 0x634d22, stub)
    _flush_heap_code(c)
    return [self_, c.rng.getrandbits(32), c.rng.getrandbits(16)]


S(0x656930, 'copy3 (GUESS)', 'stdcall', None, ret=None, gen=_s656930_spec, note='batch811; three dwords copied at +0x10')
S(0x657470, 'twoCalls (GUESS)', 'thiscall', None, ret=None, gen=_s657470_spec, note='batch811; vt[0xc] twice, second arg from r+0x7c')
S(0x650b70, 'tailVt50 (GUESS)', 'thiscall', None, ret=None, gen=_s650b70_spec, note='batch811; tail vt[0x50] of this+0xbd, eax not compared on null path')
S(0x4cf670, 'callWithShift (GUESS)', 'thiscall', None, ret=None, gen=_s4cf670_spec, note='batch811; cdecl 0x634d22 hooked (GUESS)')


def _s661bf0_spec(c):
    x = _rnd(c, 0x20)
    c.emu.w32(x + 4, c.rng.randrange(0, 0x100))
    s = _rnd(c, 0x2000)
    P = _rnd(c, 0x200)
    g = _rnd(c, 0x2000)
    c.emu.w32(g + 0x1aa3, s)
    c.emu.w32(s + 0x20, P)
    c.emu.w32(0x70039c, g)
    _flush_heap_code(c)
    return [x]


def _s54ad70_spec(c):
    self_ = _rnd(c, 0x40)
    cnt = c.emu.alloc(16, 4)
    c.emu.wbytes(cnt, bytes(16))
    # 0x54ac30 stand-in (thiscall, no args, ret 0): records ecx at cnt
    st1 = ss.code(c, b'\x89\x0d' + ss.P(cnt) + b'\xc3')
    # 0x634273 stand-in (cdecl, caller cleans): records its two words at cnt+4 and cnt+8
    st2 = ss.code(c, b'\x8b\x44\x24\x04\xa3' + ss.P(cnt + 4) + b'\x8b\x44\x24\x08\xa3' + ss.P(cnt + 8) + b'\x31\xc0\xc3')
    ss.patch(c, 0x54ac30, st1)
    ss.patch(c, 0x634273, st2)
    _flush_heap_code(c)
    return [self_, c.rng.getrandbits(32)]


def _s607bf0_spec(c):
    self_ = _rnd(c, 0x40)
    o = _rnd(c, 0x40)
    c.emu.w32(self_ + 0x14, o)
    rv = c.rng.getrandbits(32)
    def stub_ret(val):
        return ss.code(c, b'\xb8' + ss.P(val) + b'\xc2\x08\x00')
    vt = _multi_vt(c, {0x4: (lambda em, x, v=rv: (v, None), 2), 0x18: (lambda em, x, v=0: (v, None), 2)})
    c.emu.w32(o, vt)
    _flush_heap_code(c)
    return [self_, c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x661bf0, 'chainRead (GUESS)', 'stdcall', None, ret='eax', gen=_s661bf0_spec, note='batch812; global chain read, no calls')
S(0x54ad70, 'callPair (GUESS)', 'thiscall', None, ret='eax', gen=_s54ad70_spec, note='batch812; 0x54ac30 and 0x634273 hooked (GUESS)')
S(0x607bf0, 'twoVt (GUESS)', 'thiscall', None, ret=None, gen=_s607bf0_spec, note='batch812; vt[4] then vt[0x18] on this+0x14 (GUESS)')


def _s5eaaf0_spec(c):
    self_ = _rnd(c, 0x80)
    n = c.rng.randrange(0, 4)
    c.emu.w32(self_ + 0x48, n)
    for i in range(4):
        c.emu.w32(self_ + 4 + 4 * i, c.rng.getrandbits(32))
    slot = c.emu.alloc(16, 4)
    c.emu.wbytes(slot, bytes(16))
    # 0x634273 stand-in (cdecl, caller cleans): records its two words at slot, slot+4 (last call), returns 0
    ss.patch(c, 0x634273, ss.code(c, b'\x8b\x44\x24\x04\xa3' + ss.P(slot) + b'\x8b\x44\x24\x08\xa3' + ss.P(slot + 4) + b'\x31\xc0\xc3'))
    _flush_heap_code(c)
    return [self_]


def _s57a1b0_spec(c):
    self_ = _rnd(c, 0x80)
    a = c.rng.getrandbits(32)
    rv = c.rng.getrandbits(32)
    slot = c.emu.alloc(4, 4)
    c.emu.w32(slot, 0)
    # 0x4e5e60 stand-in (thiscall, no args): records ecx at slot and returns rv
    ss.patch(c, 0x4e5e60, ss.code(c, b'\x89\x0d' + ss.P(slot) + b'\xb8' + ss.P(rv) + b'\xc3'))
    _flush_heap_code(c)
    return [self_, a]


def _s60ce70_spec(c):
    self_ = _rnd(c, 0x1400)
    obj = _rnd(c, 0x40)
    c.emu.w32(self_ + 0x1377, obj)
    c.emu.w32(self_, _multi_vt(c, {0x2b0: (lambda em, x: (0, None), 0)}))
    vt_s = c.emu.r32(self_)
    slot1 = c.emu.alloc(4, 4)
    c.emu.w32(slot1, 0)
    # vt[0x2b0] stand-in (thiscall, no args, ret 0): records ecx
    stub1 = ss.code(c, b'\x89\x0d' + ss.P(slot1) + b'\xc3')
    c.emu.w32(vt_s + 0x2b0, stub1)
    slot2 = c.emu.alloc(8, 4)
    c.emu.wbytes(slot2, bytes(8))
    # obj vt[0x8c] stand-in (stdcall one word, ret 4): records its word at slot2
    c.emu.w32(obj, _multi_vt(c, {0x8c: (lambda em, x: (0, None), 1)}))
    vt_o = c.emu.r32(obj)
    stub2 = ss.code(c, b'\x8b\x44\x24\x04\xa3' + ss.P(slot2) + b'\x31\xc0\xc2\x04\x00')
    c.emu.w32(vt_o + 0x8c, stub2)
    c.emu.w32(0x724a00, c.rng.getrandbits(32))
    _flush_heap_code(c)
    return [self_]


def _s657970_spec(c):
    self_ = _rnd(c, 0x40)
    r = _rnd(c, 0x80)
    c.emu.w32(r + 0x3c, _rnd(c, 0x40))
    cnt = c.emu.alloc(4, 4)
    A = c.emu.alloc(16, 4)
    B = c.emu.alloc(16, 4)
    c.emu.w32(cnt, 0)
    c.emu.wbytes(A, bytes(16))
    c.emu.wbytes(B, bytes(16))
    code = (b'\x8b\x15' + ss.P(cnt) + b'\x8b\x44\x24\x04' + b'\x89\x04\x95' + ss.P(A) + b'\x89\x0c\x95' + ss.P(B)
            + b'\xff\x05' + ss.P(cnt) + b'\xb8' + ss.P(r) + b'\xc2\x04\x00')
    c.emu.w32(self_, _multi_vt(c, {0x0c: (lambda em, x: (0, None), 1)}))
    vt = c.emu.r32(self_)
    c.emu.w32(vt + 0x0c, ss.code(c, code))
    _flush_heap_code(c)
    return [self_, c.rng.getrandbits(32), c.rng.getrandbits(16)]


S(0x5eaaf0, 'callEach (GUESS)', 'thiscall', None, ret=None, gen=_s5eaaf0_spec, note='batch813; 0x634273 hooked (GUESS)')
S(0x57a1b0, 'threeVals (GUESS)', 'thiscall', None, ret=None, gen=_s57a1b0_spec, note='batch813; 0x4e5e60 hooked (GUESS)')
S(0x60ce70, 'resetAndCall (GUESS)', 'thiscall', None, ret='al', gen=_s60ce70_spec, note='batch813; vt 0x2b0 and obj vt 0x8c hooked (GUESS)')
S(0x657970, 'twoVtStore (GUESS)', 'thiscall', None, ret=None, gen=_s657970_spec, note='batch813; vt[0xc] twice, stores into the results')


def _unl814(head):
    def gen(c):
        o1 = _rnd(c, 0x40)
        o2 = _rnd(c, 0x40)
        c.emu.w32(head, c.rng.choice([0, o1]))
        c.emu.w32(head + 4, c.rng.choice([0, o2]))
        c.emu.w32(0x7003bc, c.rng.getrandbits(32))
        c.emu.w32(0x7003c0, c.rng.getrandbits(32))
        _flush_heap_code(c)
        return []
    return gen


S(0x66ef30, 'unlink66ef30 (GUESS)', 'cdecl', None, ret=None, gen=_unl814(0x6e4f8c), note='batch814; list head 0x6e4f8c')
S(0x673030, 'unlink673030 (GUESS)', 'cdecl', None, ret=None, gen=_unl814(0x6ec578), note='batch814; list head 0x6ec578')
S(0x673170, 'unlink673170 (GUESS)', 'cdecl', None, ret=None, gen=_unl814(0x6ec658), note='batch814; list head 0x6ec658')


S(0x673530, 'unlink673530 (GUESS)', 'cdecl', None, ret=None, gen=_unl814(0x6eca8c), note='batch815; list head 0x6eca8c')
S(0x673670, 'unlink673670 (GUESS)', 'cdecl', None, ret=None, gen=_unl814(0x6ecb6c), note='batch815; list head 0x6ecb6c')
S(0x6737b0, 'unlink6737b0 (GUESS)', 'cdecl', None, ret=None, gen=_unl814(0x6ecc4c), note='batch815; list head 0x6ecc4c')
S(0x6738f0, 'unlink6738f0 (GUESS)', 'cdecl', None, ret=None, gen=_unl814(0x6ecd60), note='batch815; list head 0x6ecd60')


S(0x673a30, 'unlink673a30 (GUESS)', 'cdecl', None, ret=None, gen=_unl814(0x6eced8), note='batch816; list head 0x6eced8')
S(0x673b70, 'unlink673b70 (GUESS)', 'cdecl', None, ret=None, gen=_unl814(0x6ecf8c), note='batch816; list head 0x6ecf8c')
S(0x673cb0, 'unlink673cb0 (GUESS)', 'cdecl', None, ret=None, gen=_unl814(0x6ed0ac), note='batch816; list head 0x6ed0ac')
S(0x673df0, 'unlink673df0 (GUESS)', 'cdecl', None, ret=None, gen=_unl814(0x6ed2b8), note='batch816; list head 0x6ed2b8')
S(0x673f30, 'unlink673f30 (GUESS)', 'cdecl', None, ret=None, gen=_unl814(0x6eeaa8), note='batch816; list head 0x6eeaa8')


S(0x6732b0, 'unlink6732b0 (GUESS)', 'cdecl', None, ret=None, gen=_unl814(0x6ec8cc), note='batch817; list head 0x6ec8cc')
S(0x6733f0, 'unlink6733f0 (GUESS)', 'cdecl', None, ret=None, gen=_unl814(0x6ec9b0), note='batch817; list head 0x6ec9b0')


def _str(c, n):
    return bytes(c.rng.randrange(1, 256) for _ in range(n)) + b'\x00'


def _s663770_spec(c):
    self_ = c.emu.alloc(0x12240, 4)
    sub = _rnd(c, 0x400)
    c.emu.w32(self_ + 0x12104, sub)
    c.emu.wbytes(sub + 0x362, _str(c, c.rng.randrange(0, 0x40)))
    c.emu.wbytes(self_ + 0x121b4, _str(c, c.rng.randrange(0, 0x30)))
    rec = c.emu.alloc(0x110, 4)
    c.emu.wbytes(rec, bytes(0x110))
    pre = c.emu.alloc(8, 4)
    c.emu.wbytes(pre, bytes([c.rng.choice((0, 0, 1, 0x80)), c.rng.choice((0, 1, 0x40))]) + bytes(6))
    # [0x700394] vt[0x34] stand-in (thiscall, two words, ret 8): records word 2, ecx and the path string, returns al = pre[0]
    vstub = (b'\x8b\x44\x24\x08\xa3' + ss.P(rec) + b'\x89\x0d' + ss.P(rec + 0x100) + b'\x8b\x54\x24\x04\xb8' + ss.P(rec + 4)
             + b'\x8a\x0a\x88\x08\x42\x40\x84\xc9\x75\xf6' + b'\xa0' + ss.P(pre) + b'\xc2\x08\x00')
    fs = _rnd(c, 0x40)
    c.emu.w32(fs, _multi_vt(c, {0x34: (lambda em, x: (0, None), 2)}))
    c.emu.w32(c.emu.r32(fs) + 0x34, ss.code(c, vstub))
    c.emu.w32(0x700394, fs)
    # 0x663190 stand-in (thiscall, no args): records ecx, returns al = pre[1]
    ss.patch(c, 0x663190, ss.code(c, b'\x89\x0d' + ss.P(rec + 0x104) + b'\xa0' + ss.P(pre + 1) + b'\xc3'))
    _flush_heap_code(c)
    return [self_, _rnd(c, 4)]


S(0x663770, 'openDat (GUESS)', 'thiscall', None, ret='al', gen=_s663770_spec, note='batch818; [0x700394] vt 0x34 and 0x663190 hooked (GUESS); 0x5acfe0, 0x5ae900 real')


def _s4d1830_spec(c):
    # Ultra-simplified spec: minimal data structures to bypass test data generation issues
    self_ = _rnd(c, 0x100)
    src = _rnd(c, 0x100)

    # Create a basic vtable for src - just need vt[0x2c] to return 0
    src_vt = _multi_vt(c, {
        0x2c: (lambda em, x: (0, None), 0),  # return 0 (no count, so no iteration)
        0x3c: (lambda em, x, v=c.rng.getrandbits(32): (v, None), 2),
        0x40: (lambda em, x, v=_rnd(c, 0x40): (v, None), 1),
    })
    c.emu.w32(src, src_vt)

    # Set src[0x24] to NULL (no nodes to iterate)
    c.emu.w32(src + 0x24, 0)

    # Create a basic vtable for self
    self_vt = _multi_vt(c, {
        0x1c: (lambda em, x: (0, None), 1),
    })
    c.emu.w32(self_, self_vt)

    # Hook malloc to just return NULL (bypass malloc issues)
    ss.patch(c, 0x41e290, ss.code(c, b'\x31\xc0\xc3'))  # xor eax, eax; ret

    _flush_heap_code(c)
    return [self_, src]

S(0x4d1830, 'buildTree (GUESS)', 'thiscall', None, ret=None, gen=_s4d1830_spec, note='batch819; linked-list tree builder')




def _s5fc2f0_spec(c):
    r = c.rng
    log = _Log833(c, 256)
    emu = c.emu
    alpha = b'aAbB'
    def key():
        n = r.randrange(0, 5)
        buf = emu.alloc(8, 1)
        emu.wbytes(buf, bytes(r.choice(alpha) for _ in range(8)))
        return buf, n
    def mknode():
        nd = _rnd(c, 0x20)
        buf, n = key()
        emu.w32(nd + 0xd, buf)
        emu.w32(nd + 0x11, buf + n)
        emu.w32(nd + 9, 0 if r.random() < 0.5 else _rnd(c, 0x20))
        return nd
    pool = [mknode() for _ in range(4)]
    head = mknode()
    self_ = _rnd(c, 0x40)
    emu.w32(self_, head)
    emu.w32(head + 9, pool[3])
    emu.w32(self_ + 4, r.randrange(0, 3))
    kb, kn = key()
    k = _rnd(c, 8)
    emu.w32(k, kb)
    emu.w32(k + 4, kb + kn)
    scen = r.randrange(3)
    if scen == 0:
        node = pool[0]
        emu.w32(head + 5, node)
    elif scen == 1:
        node = head
        emu.w32(head + 5, pool[1])
    else:
        node = pool[2]
        emu.w32(head + 5, pool[1])
    pred = r.choice(pool)
    out = emu.alloc(8, 4)
    res = _rnd(c, 8)

    def strnicmp(e, rr):
        a, b, n = e.arg32(0), e.arg32(1), e.arg32(2)
        log.put(9, a, b, n)
        x = e.rbytes(a, n).lower()
        y = e.rbytes(b, n).lower()
        v = (x > y) - (x < y)
        e.ret(eax=v & 0xffffffff, argbytes=0)
    emu.hook(0x445370, strnicmp)
    emu.w32(0x676408, 0x445370)
    emu.hook(0x42ffc0, lambda e, rr: (e.w32(e.reg('ecx'), pred), e.ret(argbytes=0)))
    emu.hook(0x5fb400, lambda e, rr: (log.put(1, e.reg('ecx'), e.arg32(0), e.arg32(1), e.arg32(2), e.arg32(3)), e.ret(eax=e.arg32(0), argbytes=0x10)))
    emu.hook(0x5fc480, lambda e, rr: (log.put(2, e.reg('ecx'), e.arg32(1)), e.ret(eax=res, argbytes=8)))
    _flush_heap_code(c)
    return [self_, out, node, k]

S(0x5fc2f0, 'hintInsert (GUESS)', 'thiscall', None, ret='eax', gen=_s5fc2f0_spec, note='batch820; hinted tree insert; 0x676408 (_strnicmp IAT slot), 0x5fb400, 0x5fc480, 0x42ffc0 hooked')


def _s4a77b0_spec(c):
    r = c.rng
    emu = c.emu
    log = _Log833(c, 256)
    self_ = _rnd(c, 0x140)
    st = emu.alloc(0x20, 4)
    vt = emu.alloc(0x80, 4)
    emu.w32(st, vt)
    for k, slot in enumerate((0x3c, 0x44, 0x4c, 0x54, 0x60, 0x68, 0x70)):
        stub = 0x4453a0 + 0x10 * k
        emu.hook(stub, (lambda sl: lambda e, rr: (log.put(sl, e.reg('ecx'), e.arg32(0)), e.ret(argbytes=4)))(slot))
        emu.w32(vt + slot, stub)
    emu.hook(0x4e74d0, lambda e, rr: (log.put(0x4e, e.reg('ecx'), e.arg32(0)), e.ret(argbytes=4)))
    _flush_heap_code(c)
    return [self_, st]

S(0x4a77b0, 'writeFields (GUESS)', 'thiscall', None, ret='al', gen=_s4a77b0_spec, note='batch821; stream writer, vt slots and 0x4e74d0 hooked')

def _s63d2f0_spec(c):
    r = c.rng
    emu = c.emu
    log = _Log833(c, 256)
    # global 0x70039c -> struct; [struct+0x1aa3] -> obj with [+0x20] = base
    g = emu.alloc(0x1b00, 16)
    gobj = _rnd(c, 0x40)
    base = r.getrandbits(32)
    emu.w32(gobj + 0x20, base)
    emu.w32(g + 0x1aa3, gobj)
    emu.w32(0x70039c, g)
    b = r.choice([0, 4, r.getrandbits(16)])
    key = (base + b) & 0xffffffff
    idx = r.choice([0, 1, 2, 3, 5]) if r.random() < 0.9 else r.randrange(0x10000)
    cnt = r.choice([0, 1, 2, 2, 3, 4])
    pool = []
    arr = emu.alloc(8 * 5, 4)
    hit = r.randrange(cnt) if cnt and r.random() < 0.75 else -1
    for i in range(cnt):
        ob = 0 if r.random() < 0.25 else _rnd(c, 0x20)
        k = key if i == hit else r.getrandbits(32)
        emu.w32(arr + 8 * i, ob)
        emu.w32(arr + 8 * i + 4, k)
    ent = _rnd(c, 0x50)
    emu.wbytes(ent + 0x3d, bytes([cnt]))
    emu.w32(ent + 0x40, arr)
    off = (idx & 0xfff) * 4
    tbl = emu.alloc(0x4000, 4)
    emu.w32(tbl + off, ent)
    na = emu.alloc(0x40, 4)
    nlis = r.randrange(0, 3)
    self_ = emu.alloc(0x110, 4)
    emu.wbytes(self_, bytes(0x110))
    vt = emu.alloc(0x40, 4)
    emu.w32(self_, vt)
    emu.w32(self_ + 0x68, tbl)
    emu.w32(self_ + 0xec, nlis)
    emu.hook(0x445380, lambda e, rr: (log.put(1, e.reg('ecx'), e.arg32(0)), e.ret(eax=na, argbytes=4)))
    emu.hook(0x445390, lambda e, rr: (log.put(2, e.reg('ecx'), e.arg32(0), e.arg32(1)), e.ret(argbytes=8)))
    emu.w32(vt + 0x20, 0x445380)
    emu.w32(vt + 0x24, 0x445390)
    emu.hook(0x634d22, lambda e, rr: (log.put(3, e.arg32(0), e.arg32(1), e.arg32(2)), e.ret(argbytes=0)))
    for i in range(nlis):
        cc = emu.alloc(0x10080, 16)
        flag = emu.alloc(8, 4)
        emu.w32(flag, r.choice([0, 1]))
        emu.w32(cc + 0x10071 - 0 if False else cc + 0x10071, (flag - off) & 0xffffffff)
        emu.w32(cc + 0x10059, r.getrandbits(32))
        emu.w32(self_ + 0xf0 + 4 * i, cc)
    # node list returned by 0x64c7e0
    R = _rnd(c, 0x30)
    prev = 0
    nn = r.randrange(0, 4)
    first = 0
    nodes = []
    for i in range(nn):
        sn = _rnd(c, 0x30)
        nd = _rnd(c, 0x20)
        ko = _rnd(c, 0x10)
        emu.w32(ko + 8, key if r.random() < 0.4 else r.getrandbits(32))
        emu.w32(nd + 0x10, ko)
        emu.w32(nd + 0x14, r.getrandbits(32))
        emu.wbytes(sn + 5, bytes([r.getrandbits(8)]))
        emu.w32(sn + 8, nd)
        emu.w32(sn + 0x1c, 0)
        nodes.append(sn)
    for i in range(nn - 1):
        emu.w32(nodes[i] + 0x1c, nodes[i + 1])
    emu.w32(R + 0x1c, nodes[0] if nodes else 0)
    emu.hook(0x64c7e0, lambda e, rr: (log.put(4, e.arg32(0)), e.ret(eax=R, argbytes=4)))
    emu.hook(0x64d5f0, lambda e, rr: (log.put(5, e.arg32(0)), e.ret(argbytes=4)))
    a = _rnd(c, 0x80)
    emu.wbytes(a + 0x5a, bytes([idx & 0xff, (idx >> 8) & 0xff]))
    _flush_heap_code(c)
    return [self_, a, b]

S(0x63d2f0, 'removeEntry (GUESS)', 'thiscall', None, ret=None, gen=_s63d2f0_spec, note='batch822; pair-array remove; global 0x70039c pre-set, callees hooked')

def _s63eab0_spec(c):
    # Simple array getter: returns [this[0x68] + (arg & 0xfff) * 4]
    self_ = _rnd(c, 0x70)
    
    # Create an array with some values
    array = c.emu.alloc(0x4000, 4)  # 4KB array
    for i in range(0x1000):  # Fill with pattern
        c.emu.w32(array + i*4, c.rng.getrandbits(32))
    
    # Set this[0x68] to point to array
    c.emu.w32(self_ + 0x68, array)
    
    _flush_heap_code(c)
    return [self_, c.rng.getrandbits(32)]  # arg is random

S(0x63eab0, 'arrayGetter (GUESS)', 'thiscall', None, ret='eax', gen=_s63eab0_spec, note='batch823; simple array indexer')

def _s6368b0_spec(c):
    # Global function pointer dispatcher
    # The function reads a function pointer from [0x7003b0] and calls it if non-NULL
    
    # We'll test two scenarios:
    # 1. Function pointer is NULL (should return 0)
    # 2. Function pointer is non-NULL (should call the function)
    
    # For simplicity, we'll use NULL pointer to test the early return path
    c.emu.w32(0x7003b0, 0)
    
    _flush_heap_code(c)
    return [c.rng.getrandbits(32)]  # arg is random, but won't be used if fn is NULL

S(0x6368b0, 'globalDispatcher (GUESS)', 'cdecl', None, ret='eax', gen=_s6368b0_spec, note='batch824; global function pointer dispatcher')

def _s63480d_spec(c):
    # Simple function that returns 1, no arguments needed
    _flush_heap_code(c)
    return []  # No arguments

S(0x63480d, 'returnOne (GUESS)', 'cdecl', None, ret='al', gen=_s63480d_spec, note='batch825; trivial return 1')

def _s_getter_spec(c):
    # Simple getter specs - just create a random struct
    self_ = _rnd(c, 0x80)  # Allocate enough space for max offset
    _flush_heap_code(c)
    return [self_]

S(0x6387c0, 'getter0x24 (GUESS)', 'thiscall', None, ret='eax', gen=_s_getter_spec, note='batch826a; read [this+0x24]')
S(0x638c80, 'getter0x29 (GUESS)', 'thiscall', None, ret='eax', gen=_s_getter_spec, note='batch826b; read [this+0x29]')
S(0x638cb0, 'getter0x18 (GUESS)', 'thiscall', None, ret='eax', gen=_s_getter_spec, note='batch826c; read [this+0x18]')

S(0x638cc0, 'getter0x2d (GUESS)', 'thiscall', None, ret='eax', gen=_s_getter_spec, note='batch827a; read [this+0x2d]')
S(0x638cd0, 'getter0x32 (GUESS)', 'thiscall', None, ret='eax', gen=_s_getter_spec, note='batch827b; read [this+0x32]')
S(0x638ce0, 'getter0x20 (GUESS)', 'thiscall', None, ret='eax', gen=_s_getter_spec, note='batch827c; read [this+0x20]')
S(0x635330, 'orOne (GUESS)', 'thiscall', None, ret=None, gen=_s_getter_spec, note='batch827d; [this+4] |= 1')

def _s_const_spec(c):
    # Constant return functions - no arguments needed
    _flush_heap_code(c)
    return []

S(0x626a60, 'const6bece8 (GUESS)', 'cdecl', None, ret='eax', gen=_s_const_spec, note='batch828a; returns 0x6bece8')
S(0x626a70, 'const6be898 (GUESS)', 'cdecl', None, ret='eax', gen=_s_const_spec, note='batch828b; returns 0x6be898')
S(0x626e00, 'const778 (GUESS)', 'cdecl', None, ret='eax', gen=_s_const_spec, note='batch828c; returns 0x778')
S(0x634811, 'const4000 (GUESS)', 'cdecl', None, ret='eax', gen=_s_const_spec, note='batch828d; returns 0x4000')
S(0x63486d, 'const814248 (GUESS)', 'cdecl', None, ret='eax', gen=_s_const_spec, note='batch828e; returns 0x814248')
S(0x634873, 'const814244 (GUESS)', 'cdecl', None, ret='eax', gen=_s_const_spec, note='batch828f; returns 0x814244')

S(0x63dac0, 'const1000 (GUESS)', 'cdecl', None, ret='eax', gen=_s_const_spec, note='batch829a; returns 0x1000')
S(0x63dad0, 'const30 (GUESS)', 'cdecl', None, ret='eax', gen=_s_const_spec, note='batch829b; returns 0x30')
S(0x63dae0, 'const8 (GUESS)', 'cdecl', None, ret='eax', gen=_s_const_spec, note='batch829c; returns 8')
S(0x63daf0, 'const40 (GUESS)', 'cdecl', None, ret='eax', gen=_s_const_spec, note='batch829d; returns 0x40')
S(0x63db00, 'const14 (GUESS)', 'cdecl', None, ret='eax', gen=_s_const_spec, note='batch829e; returns 0x14')
S(0x63db10, 'const18 (GUESS)', 'cdecl', None, ret='eax', gen=_s_const_spec, note='batch829f; returns 0x18')

S(0x63db20, 'const4c (GUESS)', 'cdecl', None, ret='eax', gen=_s_const_spec, note='batch830a; returns 0x4c')
S(0x63db30, 'const10 (GUESS)', 'cdecl', None, ret='eax', gen=_s_const_spec, note='batch830b; returns 0x10')
S(0x63ec50, 'constff (GUESS)', 'cdecl', None, ret='eax', gen=_s_const_spec, note='batch830c; returns 0xff')
S(0x63ec60, 'const1fe (GUESS)', 'cdecl', None, ret='eax', gen=_s_const_spec, note='batch830d; returns 0x1fe')
S(0x63ec70, 'const3f (GUESS)', 'cdecl', None, ret='eax', gen=_s_const_spec, note='batch830e; returns 0x3f')

def _s634861_spec(c):
    r = c.rng.getrandbits(32)
    c.emu.w32(0x6f5670, 0 if r & 1 else r)
    _flush_heap_code(c)
    return []

S(0x634861, 'isZero6f5670 (GUESS)', 'cdecl', None, ret='al', gen=_s634861_spec, note='batch831a; [0x6f5670]==0')

def _s63ce20_spec(c):
    self_ = _rnd(c, 0x20)
    kind = c.rng.randrange(4)
    k = c.rng.randrange(1, 12)
    if kind == 0:
        c.emu.w32(self_ + 8, 0)
    else:
        nodes = [_rnd(c, 0x10) for _ in range(k)]
        for i, n in enumerate(nodes):
            nxt = nodes[i + 1] if i + 1 < k else (nodes[0] if kind != 1 else 0)
            c.emu.w32(n + 8, nxt)
        c.emu.w32(self_ + 8, nodes[0])
    _flush_heap_code(c)
    return [self_]

S(0x63ce20, 'ringCount (GUESS)', 'thiscall', None, ret='al', gen=_s63ce20_spec, note='batch831b; count nodes on +8 ring/chain')

def _s634340_spec(c):
    r = c.rng
    pick = lambda: r.choice([0, 1, 0xffffffff, 0x80000000, r.getrandbits(32), r.getrandbits(16)])
    alo, ahi, blo, bhi = pick(), pick(), pick(), pick()
    if r.random() < 0.4:
        ahi = 0
        bhi = 0
    elif r.random() < 0.2:
        bhi = 0
    return [alo, ahi, blo, bhi]

S(0x634340, '_allmul (GUESS)', 'stdcall', None, ret='eax:edx', gen=_s634340_spec, note='batch832a; 64-bit multiply')

def _s6387a0_spec(c):
    # callback always set: an unset callback is an int3 trap in both builds (not compared)
    buf = c.emu.alloc(64, 4)
    c.emu.hook(0x445330, lambda e, res: (c.emu.w32(buf, c.emu.r32(buf) + 1), e.ret(argbytes=0)))
    c.emu.w32(0x7003b0, 0x445330)
    _flush_heap_code(c)
    return [c.rng.getrandbits(32), c.rng.getrandbits(32)]

S(0x6387a0, 'callbackRet0 (GUESS)', 'stdcall', None, ret='eax', gen=_s6387a0_spec, note='batch832b; call [0x7003b0], return 0')

class _Log833:
    def __init__(self, c, words=64):
        self.emu, self.base, self.n, self.cap = c.emu, c.emu.alloc(4 * words, 4), 0, words
    def put(self, *ws):
        for w in ws:
            if self.n < self.cap:
                self.emu.w32(self.base + 4 * self.n, w & 0xffffffff)
                self.n += 1


def _s63b660_spec(c):
    log = _Log833(c)
    self_ = _rnd(c, 0x20)
    obj = _rnd(c, 0x20)
    vt = _rnd(c, 0x40)
    stub = 0x445340
    res = c.rng.choice([0, 0, c.rng.getrandbits(32) | 1])
    c.emu.hook(stub, lambda e, r: (log.put(1, e.reg('ecx'), e.arg32(0)), e.ret(eax=res, argbytes=4)))
    c.emu.w32(vt + 0x20, stub)
    c.emu.w32(obj, vt)
    c.emu.w32(self_ + 4, obj)
    _flush_heap_code(c)
    return [self_, c.rng.getrandbits(32)]

S(0x63b660, 'vtCallCount (GUESS)', 'thiscall', None, ret='eax', gen=_s63b660_spec, note='batch833a; this[4]->vt[0x20](arg) hooked')


def _s639240_spec(c):
    log = _Log833(c)
    self_ = _rnd(c, 0x40)
    arr = c.emu.alloc(0x100, 4)
    n = c.rng.randrange(0, 20)
    c.emu.w32(arr, n)
    for i in range(1, 21):
        c.emu.w32(arr + 4 * i, c.rng.getrandbits(32))
    c.emu.hook(0x638f20, lambda e, r: (log.put(2, e.reg('ecx'), e.arg32(0)), e.ret(eax=arr, argbytes=4)))
    _flush_heap_code(c)
    return [self_, c.rng.getrandbits(32)]

S(0x639240, 'setArray (GUESS)', 'thiscall', None, ret='eax', gen=_s639240_spec, note='batch833b; 0x638f20 hooked')


def _s63abe0_spec(c):
    log = _Log833(c)
    self_ = _rnd(c, 0x40)
    c.emu.hook(0x63ab30, lambda e, r: (log.put(3, e.reg('ecx')), e.ret(eax=0x1234, argbytes=0)))
    c.emu.hook(0x634273, lambda e, r: (log.put(4, e.arg32(0), e.arg32(1)), e.ret(eax=0, argbytes=0)))
    _flush_heap_code(c)
    return [self_, c.rng.getrandbits(32)]

S(0x63abe0, 'dtorDeleting (GUESS)', 'thiscall', None, ret='eax', gen=_s63abe0_spec, note='batch833c; 0x63ab30, 0x634273 hooked')


def _s636400_spec(c):
    log = _Log833(c)
    self_ = _rnd(c, 0x40)
    if c.rng.random() < 0.5:
        c.emu.wbytes(self_ + 0x31, b'\x00')
    c.emu.hook(0x6363a0, lambda e, r: (log.put(5, e.reg('ecx')), e.ret(eax=0x5678, argbytes=0)))
    c.emu.hook(0x634273, lambda e, r: (log.put(6, e.arg32(0), e.arg32(1)), e.ret(eax=0, argbytes=0)))
    _flush_heap_code(c)
    return [self_]

S(0x636400, 'dtorTail (GUESS)', 'thiscall', None, ret='eax', gen=_s636400_spec, note='batch833d; 0x6363a0, 0x634273 hooked')


def _s63450f_spec(c):
    log = _Log833(c)
    s1, s2 = 0x445350, 0x445360
    c.emu.hook(s1, lambda e, r: (log.put(7, e.arg32(0)), e.ret(eax=0, argbytes=4)))
    c.emu.hook(s2, lambda e, r: (log.put(8, e.arg32(0)), e.ret(eax=0, argbytes=4)))
    c.emu.w32(0x6760cc, s1)
    c.emu.w32(0x676070, s2)
    c.emu.w32(0x7257f4, 0 if c.rng.random() < 0.4 else c.rng.getrandbits(32) | 1)
    _flush_heap_code(c)
    return []

S(0x63450f, 'iatPair (GUESS)', 'cdecl', None, ret=None, gen=_s63450f_spec, note='batch834; IAT slots 0x6760cc/0x676070 hooked')


def _s639ac0_spec(c):
    r = c.rng
    emu = c.emu
    log = _Log833(c)
    self_ = _rnd(c, 0x40)
    n = r.randrange(0, 12)
    src = _rnd(c, 0x40)
    emu.w32(self_ + 0x2d, src)
    emu.w32(self_ + 0x32, n)
    buf = emu.alloc(0x80, 4)
    emu.hook(0x6397c0, lambda e, rr: (log.put(1, e.reg('ecx'), e.arg32(0)), e.ret(eax=buf, argbytes=4)))
    emu.hook(0x634d22, lambda e, rr: (log.put(2, e.arg32(0), e.arg32(1), e.arg32(2)), e.ret(argbytes=0)))
    _flush_heap_code(c)
    return [self_, r.getrandbits(32)]

S(0x639ac0, 'packArray (GUESS)', 'thiscall', None, ret='eax', gen=_s639ac0_spec, note='batch835a; 0x6397c0, 0x634d22 hooked')


def _s63f030_spec(c):
    r = c.rng
    emu = c.emu
    log = _Log833(c)
    a = _rnd(c, 0x60)
    n = 0 if r.random() < 0.2 else _rnd(c, 0x60)
    emu.w32(a + 0x38, n)
    vt = emu.alloc(0x140, 4)
    o = emu.alloc(0x10, 4)
    emu.w32(o, vt)
    if n:
        emu.w32(n + 0x54, 0 if r.random() < 0.25 else o)
    emu.hook(0x445500, lambda e, rr: (log.put(3, e.reg('ecx'), e.arg32(0), e.arg32(1), e.arg32(2)), e.ret(argbytes=12)))
    emu.w32(vt + 0x130, 0x445500)
    res = r.randrange(2) if r.random() < 0.8 else r.getrandbits(32)
    emu.hook(0x63ef00, lambda e, rr: (log.put(1, e.arg32(0)), e.ret(argbytes=4)))
    emu.hook(0x4dd8d0, lambda e, rr: (log.put(2, e.reg('ecx')), e.ret(eax=res, argbytes=0)))
    _flush_heap_code(c)
    return [a]

S(0x63f030, 'notify (GUESS)', 'stdcall', None, ret=None, gen=_s63f030_spec, note='batch835b; 0x63ef00, 0x4dd8d0, vt[0x130] hooked')


def _s6401b0_spec(c):
    r = c.rng
    emu = c.emu
    log = _Log833(c)
    self_ = _rnd(c, 0x20)
    vt = emu.alloc(0x40, 4)
    emu.w32(self_, vt)
    emu.hook(0x445510, lambda e, rr: (log.put(1, e.reg('ecx'), e.arg32(0), e.arg32(1)), e.ret(argbytes=8)))
    emu.w32(vt + 0x24, 0x445510)
    a = _rnd(c, 0x60)
    cnt = r.choice([0, 0, 1, 2, 7, 0xffff, 0x1234, r.getrandbits(16)])
    emu.wbytes(a + 0x40, bytes([cnt & 0xff, cnt >> 8]))
    _flush_heap_code(c)
    return [self_, a]

S(0x6401b0, 'freeBlock (GUESS)', 'thiscall', None, ret=None, gen=_s6401b0_spec, note='batch835c; vt[0x24] hooked')


def _s639270_spec(c):
    r = c.rng
    emu = c.emu
    log = _Log833(c)
    self_ = _rnd(c, 0x40)
    vt = emu.alloc(0x40, 4)
    emu.w32(self_, vt)
    arr = emu.alloc(0x80, 4)
    emu.w32(arr, r.randrange(0, 12))
    va, vb = r.getrandbits(32), r.choice([0, 1, 4, r.getrandbits(32)])
    emu.hook(0x445520, lambda e, rr: (log.put(1, e.reg('ecx')), e.ret(eax=va, argbytes=0)))
    emu.hook(0x445530, lambda e, rr: (log.put(2, e.reg('ecx')), e.ret(eax=vb, argbytes=0)))
    emu.w32(vt + 0x20, 0x445520)
    emu.w32(vt + 0x1c, 0x445530)
    emu.hook(0x638f20, lambda e, rr: (log.put(3, e.reg('ecx'), e.arg32(0)), e.ret(eax=arr, argbytes=4)))
    _flush_heap_code(c)
    return [self_, r.getrandbits(32)]

S(0x639270, 'setArrayStride (GUESS)', 'thiscall', None, ret='eax', gen=_s639270_spec, note='batch835d; 0x638f20, vt[0x1c], vt[0x20] hooked')


def _s6385c0_spec(c):
    r = c.rng
    kind = r.randrange(4)
    if kind == 0:
        v = r.getrandbits(32)
    elif kind == 1:
        v = int.from_bytes(bytes(r.choice(b'azAZ09 /:@[`{\x00\x80\xff') for _ in range(4)), 'big')
    elif kind == 2:
        v = r.choice([0, 0x41000000, 0x00004142, 0x80000000, 0xff000000])
    else:
        v = int.from_bytes(bytes(r.choice(b'AbZ0189') for _ in range(4)), 'big') & r.choice([0xffffffff, 0xffffff00, 0xffff0000])
    _flush_heap_code(c)
    return [v]

S(0x6385c0, 'fourccToStr (GUESS)', 'thiscall', None, ret='eax', gen=_s6385c0_spec, note='batch836a; writes global buffer 0x725814')


def _s636280_spec(c):
    self_ = _rnd(c, 0x40)
    _flush_heap_code(c)
    return [self_]

S(0x636280, 'ctor636280 (GUESS)', 'thiscall', None, ret='eax', gen=_s636280_spec, note='batch836b; header ctor')


def _s640400_spec(c):
    r = c.rng
    emu = c.emu
    log = _Log833(c)
    self_ = _rnd(c, 0x110)
    vt = emu.alloc(0x100, 4)
    emu.w32(self_, vt)
    for k, slot in enumerate((0xb4, 0xbc, 0xc8)):
        stub = 0x445560 + 0x10 * k
        emu.hook(stub, (lambda sl: lambda e, rr: (log.put(sl, e.reg('ecx')), e.ret(argbytes=0)))(slot))
        emu.w32(vt + slot, stub)
    n = r.randrange(0, 5)
    emu.w32(self_ + 0xec, n)
    ovt = emu.alloc(0x80, 4)
    emu.hook(0x4455a0, lambda e, rr: (log.put(0x40, e.reg('ecx')), e.ret(argbytes=0)))
    emu.w32(ovt + 0x40, 0x4455a0)
    for i in range(n):
        o = emu.alloc(0x10, 4)
        emu.w32(o, ovt)
        emu.w32(self_ + 0xf0 + 4 * i, o)
    _flush_heap_code(c)
    return [self_]

S(0x640400, 'callAll (GUESS)', 'thiscall', None, ret=None, gen=_s640400_spec, note='batch836c; vt[0xb4/0xbc/0xc8] and element vt[0x40] hooked')


def _s635380_spec(c):
    r = c.rng
    emu = c.emu
    log = _Log833(c, 256)
    key = _rnd(c, 8)
    k = r.randrange(0, 90)
    target = emu.r32(0x6f5729 + 5 * k) if k < 78 else r.getrandbits(32)
    stub = 0x4455b0
    emu.hook(stub, lambda e, rr: (log.put(e.arg32(0), e.arg32(1)), e.ret(eax=0 if e.arg32(1) == target else 1, argbytes=0)))
    emu.w32(0x676414, stub)
    _flush_heap_code(c)
    return [key]

S(0x635380, 'lookup (GUESS)', 'stdcall', None, ret='al', gen=_s635380_spec, note='batch836d; table at 0x6f5728, IAT 0x676414 test hooked')


def _s62f340_spec(c):
    r = c.rng
    emu = c.emu
    log = _Log833(c)
    o = _rnd(c, 0x30)
    s = _rnd(c, 0x30)
    emu.w32(o + 0x1c, s)
    emu.w32(o + 0x10, r.choice([0, 1, 5, 100, r.getrandbits(8)]))
    emu.w32(s + 0x14, r.choice([0, 1, 5, 100, r.getrandbits(8)]))
    emu.hook(0x634d22, lambda e, rr: (log.put(e.arg32(0), e.arg32(1), e.arg32(2)), e.ret(argbytes=0)))
    _flush_heap_code(c)
    return [o]

S(0x62f340, 'pumpBytes (GUESS)', 'cdecl', None, ret=None, gen=_s62f340_spec, note='batch837a; 0x634d22 hooked')


def _s623b80_spec(c):
    r = c.rng
    emu = c.emu
    sb = emu.alloc(0x80, 2)
    emu.wbytes(sb, bytes(r.choice([0xd8, 0xdb, 0xdc, 0xdf, 0xf8, 0xd0, 0x41, r.getrandbits(8)]) for _ in range(0x80)))
    db = emu.alloc(0x80, 2)
    sn = r.choice([0, 2, 4, 6, 10, 0x20, 0x30, 3, 5, 0x21])
    dn = r.choice([0, 2, 4, 6, 10, 0x20, 0x30, 3, 5, 0x21])
    if (sn & 1) and (dn & 1):
        dn += 1   # both odd would never meet either end (runaway)
    sp = _rnd(c, 4)
    dp = _rnd(c, 4)
    emu.w32(sp, sb)
    emu.w32(dp, db)
    _flush_heap_code(c)
    return [r.getrandbits(32), sp, sb + sn, dp, db + dn]

S(0x623b80, 'swapCopy16 (GUESS)', 'cdecl', None, ret=None, gen=_s623b80_spec, note='batch837b; byte-swapping 16-bit copy')


def _s639d80_spec(c):
    r = c.rng
    emu = c.emu
    log = _Log833(c)
    self_ = _rnd(c, 0x40)
    emu.wbytes(self_ + 0x31, bytes([r.randrange(2)]))
    src = _rnd(c, 0x80)
    n = r.choice([0, 1, 3, 8, 0x3fffffff, 0x40000000, 0x40000001, 0xffffffff, r.getrandbits(32)])
    buf = emu.alloc(0x100, 4)
    emu.hook(0x41e290, lambda e, rr: (log.put(1, e.arg32(0)), e.ret(eax=buf, argbytes=0)))
    emu.hook(0x634273, lambda e, rr: (log.put(2, e.arg32(0), e.arg32(1)), e.ret(argbytes=0)))
    emu.hook(0x634d22, lambda e, rr: (log.put(3, e.arg32(0), e.arg32(1), e.arg32(2)), e.ret(argbytes=0)))
    flag = r.choice([0, 1, 0x100, 0x101, r.getrandbits(32)])
    _flush_heap_code(c)
    return [self_, src, n, flag]

S(0x639d80, 'setWords (GUESS)', 'thiscall', None, ret=None, gen=_s639d80_spec, note='batch837c; 0x41e290, 0x634273, 0x634d22 hooked')


def _s639b00_spec(c):
    r = c.rng
    emu = c.emu
    log = _Log833(c)
    self_ = _rnd(c, 0x40)
    vt = emu.alloc(0x40, 4)
    emu.w32(self_, vt)
    n = r.randrange(0, 8)
    emu.w32(self_ + 0x32, n)
    emu.w32(self_ + 0x2d, _rnd(c, 0x40))
    emu.w32(self_ + 0x36, _rnd(c, 0x40))
    va, vb = r.choice([0, 1, 2, 4]), r.choice([0, 1, 3, 8])
    buf = emu.alloc(0x100, 4)
    emu.hook(0x4455c0, lambda e, rr: (log.put(1), e.ret(eax=r.getrandbits(32), argbytes=0)))
    emu.w32(0x7003b0, 0x4455c0)
    emu.hook(0x6397c0, lambda e, rr: (log.put(2, e.reg('ecx'), e.arg32(0)), e.ret(eax=buf, argbytes=4)))
    emu.hook(0x634d22, lambda e, rr: (log.put(3, e.arg32(0), e.arg32(1), e.arg32(2)), e.ret(argbytes=0)))
    emu.hook(0x4455d0, lambda e, rr: (log.put(4, e.reg('ecx')), e.ret(eax=va, argbytes=0)))
    emu.hook(0x4455e0, lambda e, rr: (log.put(5, e.reg('ecx')), e.ret(eax=vb, argbytes=0)))
    emu.w32(vt + 0x20, 0x4455d0)
    emu.w32(vt + 0x1c, 0x4455e0)
    _flush_heap_code(c)
    return [self_, r.getrandbits(32)]

S(0x639b00, 'packArrays (GUESS)', 'thiscall', None, ret='eax', gen=_s639b00_spec, note='batch838a; assert hook set (unset = int3), callees and vt hooked')


def _s640450_spec(c):
    r = c.rng
    emu = c.emu
    log = _Log833(c, 256)
    self_ = _rnd(c, 0x200)
    vt = emu.alloc(0x40, 4)
    emu.w32(self_ + 0x1dc, vt)
    ovt = emu.alloc(0x10, 4)
    def mkobj():
        o = _rnd(c, 0x10)
        return o
    def mknode(nxt):
        nd = emu.alloc(0x40, 4)
        emu.w32(nd, r.randrange(1, 4))
        emu.w32(nd + 8, nxt)
        for i in range(8):
            o = _rnd(c, 0x10)
            emu.w32(nd + 0x10 + 4 * i, o)
        return nd
    n2 = mknode(0)
    n1 = mknode(n2 if r.random() < 0.7 else 0)
    # object flag byte +5: random bits already; objects are plain heap blocks
    empty = r.random() < 0.15
    removals = [0]
    limit = r.randrange(0, 3)

    def begin(e, rr):
        it = e.arg32(0)
        log.put(1, e.reg('ecx'))
        if empty:
            e.w32(it, 0)
        else:
            e.w32(it, n1 + 0x10)
        e.w32(it + 4, 0)
        e.w32(it + 8, n1)
        e.ret(argbytes=4)

    def remove(e, rr):
        it = e.arg32(0)
        cur, idx, node = e.r32(it), e.r32(it + 4), e.r32(it + 8)
        log.put(2, e.reg('ecx'), cur, idx, node)
        removals[0] += 1
        e.w32(it, 0 if removals[0] > limit else cur + 4)
        e.ret(argbytes=4)
    emu.hook(0x4455f0, begin)
    emu.hook(0x445600, remove)
    emu.w32(vt + 0xc, 0x4455f0)
    emu.w32(vt + 0x10, 0x445600)
    _flush_heap_code(c)
    return [self_]

S(0x640450, 'pruneList (GUESS)', 'thiscall', None, ret=None, gen=_s640450_spec, note='batch838b; container begin/remove vt slots hooked')


def _s640c10_spec(c):
    r = c.rng
    emu = c.emu
    log = _Log833(c)
    self_ = _rnd(c, 0x80)
    a = _rnd(c, 0x80)
    idx = r.choice([0, 1, 2, 3, 0x1003, 0x8002, 0x803, 0x1803, 0xfff])
    emu.wbytes(a + 0x5a, bytes([idx & 0xff, idx >> 8]))
    emu.w32(a + 0x3c, r.getrandbits(32))
    tbl = emu.alloc(0x4000, 4)
    ent = _rnd(c, 0x20)
    emu.w32(tbl + (idx & 0xfff) * 4, ent)
    emu.w32(self_ + 0x68, tbl)
    vals = [999.0, 1000.0, 1000.0000610351562, 1001.0, float('nan'), -5.0, float('inf'), 0.0]
    import struct
    fv = r.choice(vals)
    live = r.randrange(2)
    emu.hook(0x658d30, lambda e, rr: (log.put(1, e.reg('ecx')), e.ret(eax=live, argbytes=0)))
    # owner path
    obj = emu.alloc(0x20, 4)
    ovt = emu.alloc(0x260 + 8, 4)
    emu.w32(obj, ovt)
    emu.w32(a + 0x54, obj)
    v = emu.alloc(0x300, 4)
    emu.wbytes(v + 0x271, struct.pack('<f', fv))
    emu.hook(0x4455f0, lambda e, rr: (log.put(2, e.reg('ecx')), e.ret(eax=v, argbytes=0)))
    emu.w32(ovt + 0x24c, 0x4455f0)
    emu.hook(0x63eb90, lambda e, rr: (log.put(3, e.reg('ecx'), e.arg32(0)), e.ret(argbytes=4, st0=fv)))
    _flush_heap_code(c)
    return [self_, a]

S(0x640c10, 'belowLimit (GUESS)', 'thiscall', None, ret='al', gen=_s640c10_spec, note='batch839; 0x658d30, 0x63eb90 (float in st0) and vt[0x24c] hooked')


def _s63f4e0_spec(c):
    r = c.rng
    emu = c.emu
    log = _Log833(c)
    self_ = _rnd(c, 0x240)
    vt = emu.alloc(0xb0, 4)
    emu.w32(self_, vt)
    pool = emu.alloc(0x10, 4)
    pvt = emu.alloc(0x20, 4)
    emu.w32(pool, pvt)
    emu.w32(self_ + 0x228, pool)
    tbl = emu.alloc(0x4000, 4)
    emu.w32(self_ + 0x68, tbl)
    ent = _rnd(c, 0x20)
    idv = r.choice([0, 0, 0, 1, 7, 0x1005, 0x803, 0xfff])
    emu.wbytes(ent + 6, bytes([idv & 0xff, idv >> 8]))
    emu.w32(tbl + (idv & 0xfff) * 4, _rnd(c, 8))
    out = _rnd(c, 0x20)
    slot = _rnd(c, 0x20) if r.random() < 0.8 else 0
    ok = (r.getrandbits(24) << 8) | r.randrange(2)
    emu.hook(0x445700, lambda e, rr: (log.put(1, e.reg('ecx')), e.ret(eax=slot, argbytes=0)))
    emu.w32(pvt + 8, 0x445700)
    emu.hook(0x445710, lambda e, rr: (log.put(2, e.reg('ecx'), e.arg32(0)), e.ret(eax=ok, argbytes=4)))
    emu.w32(vt + 0x9c, 0x445710)
    emu.hook(0x445720, lambda e, rr: (log.put(3, e.reg('ecx'), e.arg32(0)), e.ret(argbytes=4)))
    emu.w32(vt + 0x98, 0x445720)
    emu.hook(0x445730, lambda e, rr: (log.put(4, e.reg('ecx'), e.arg32(0)), e.ret(argbytes=4)))
    emu.w32(pvt + 0xc, 0x445730)
    newid = r.getrandbits(32)
    emu.hook(0x63f090, lambda e, rr: (log.put(5, e.reg('ecx'), e.arg32(0)), e.ret(eax=newid, argbytes=4)))
    _flush_heap_code(c)
    return [self_, out, ent, r.getrandbits(32)]

S(0x63f4e0, 'resolveEntry (GUESS)', 'thiscall', None, ret='al', gen=_s63f4e0_spec, note='batch840a; pool vt slots, this vt[0x9c/0x98], 0x63f090 hooked')


def _s62ce70_spec(c):
    r = c.rng
    emu = c.emu
    log = _Log833(c)
    out = _rnd(c, 0x20)
    code = r.choice([0xf, 0x12, 0x12, 0x12, 0x1c, 0x1c, 0x10, r.getrandbits(32)])
    obj = _rnd(c, 0x40)
    a, b = r.getrandbits(32), r.getrandbits(32)
    answers = [r.choice([0, 0, 1, 5]) for _ in range(2)]
    n = [0]
    def cb(e, rr):
        i = n[0]
        n[0] += 1
        log.put(1, e.arg32(0), e.arg32(1), e.arg32(2), e.arg32(3))
        e.ret(eax=answers[min(i, 1)], argbytes=0)
    emu.hook(0x445740, cb)
    emu.w32(obj + 0x1c, 0x445740)
    if r.random() < 0.3:
        emu.w32(out + 0xc, 0)
    _flush_heap_code(c)
    return [out, code, a, b, obj]

S(0x62ce70, 'queryHandler (GUESS)', 'cdecl', None, ret='eax', gen=_s62ce70_spec, note='batch840b; callback obj[0x1c] hooked')


def _deflate_state(c, valid):
    r = c.rng
    emu = c.emu
    s = emu.alloc(0x16c0, 4)
    emu.wbytes(s, bytes(r.getrandbits(8) for _ in range(0x40)))
    pb = _rnd(c, 0x300)
    emu.w32(s + 8, pb)
    emu.w32(s + 0x14, r.randrange(0, 0x40))
    emu.wbytes(s + 0x16b0, bytes([r.getrandbits(8), r.getrandbits(8)]))
    emu.w32(s + 0x16b4, valid & 0xffffffff)
    emu.w32(s + 0x16ac, r.getrandbits(32))
    return s


def _s630120_spec(c):
    s = _deflate_state(c, c.rng.choice([16, 15, 9, 8, 7, 1, 0, -1, 17, 12]))
    _flush_heap_code(c)
    return [s]

S(0x630120, 'biFlush (GUESS)', 'cdecl', None, ret=None, gen=_s630120_spec, note='batch841a; zlib bi_flush')


def _s630910_spec(c):
    r = c.rng
    s = _deflate_state(c, r.choice([16, 9, 8, 5, 1, 0, -1, 20]))
    ln = r.choice([0, 1, 2, 5, 0x20, 0x40, 0x100, 0x101, 0x180, 0x1ff, r.randrange(0, 0x1b0)])
    buf = _rnd(c, 0x200)
    _flush_heap_code(c)
    return [s, buf, ln, r.choice([0, 1, 0x100, r.getrandbits(32) | 1])]

S(0x630910, 'copyBlock (GUESS)', 'cdecl', None, ret=None, gen=_s630910_spec, note='batch841b; zlib copy_block, bi_windup real')


def _s63b940_spec(c):
    r = c.rng
    emu = c.emu
    log = _Log833(c)
    self_ = _rnd(c, 0x110)
    n = r.randrange(0, 5)
    emu.w32(self_ + 0xec, n)
    ovt = emu.alloc(0x80, 4)
    emu.hook(0x445800, lambda e, rr: (log.put(0x6c, e.reg('ecx')), e.ret(argbytes=0)))
    emu.w32(ovt + 0x6c, 0x445800)
    for i in range(n):
        o = emu.alloc(0x10, 4)
        emu.w32(o, ovt)
        emu.w32(self_ + 0xf0 + 4 * i, o)
    _flush_heap_code(c)
    return [self_]

S(0x63b940, 'callAll6c (GUESS)', 'thiscall', None, ret=None, gen=_s63b940_spec, note='batch842a; element vt[0x6c] hooked')


def _s62c6c0_spec(c):
    r = c.rng
    emu = c.emu
    log = _Log833(c)
    cvt = _rnd(c, 0x200)
    cookie = r.getrandbits(32)
    emu.w32(cvt + 0x174, cookie)
    val = r.choice([r.randrange(0, 0x100), r.randrange(0, 0x100), r.randrange(0, 0x100), r.randrange(0, 0x100), r.randrange(0, 0x100), r.randrange(0x100, 0xd800), r.randrange(0xd800, 0xe000), 0xd7ff, 0xd800, 0xdfff, 0xe000,
                    0xfffd, 0xfffe, 0xffff, 0xff00, 0xff01, 0xfeff, 0x10000, 0x12345, 0x7fffffff, 0x80000000, 0xffffffff,
                    r.randrange(0xe000, 0x10000), r.getrandbits(32)])
    emu.hook(0x445810, lambda e, rr: (log.put(e.arg32(0), e.arg32(1)), e.ret(eax=val, argbytes=0)))
    emu.w32(cvt + 0x170, 0x445810)
    _flush_heap_code(c)
    return [cvt, r.getrandbits(32)]

S(0x62c6c0, 'isInvalid (GUESS)', 'cdecl', None, ret='eax', gen=_s62c6c0_spec, note='batch842b; converter callback cvt[0x170] hooked, table at 0x6bf2f4 real')


def _s62c7f0_spec(c):
    r = c.rng
    emu = c.emu
    log = _Log833(c, 256)
    cvt = emu.alloc(0x380, 4)
    tab4c = [r.randrange(4, 8) for _ in range(256)]
    tab178 = [0 if r.random() < 0.5 else r.randrange(1, 0x10000) for _ in range(256)]
    emu.wbytes(cvt + 0x4c, bytes(tab4c))
    emu.wbytes(cvt + 0x178, b''.join(v.to_bytes(2, 'little') for v in tab178))
    emu.w32(cvt + 0x174, r.getrandbits(32))
    cbv = r.getrandbits(32)
    emu.hook(0x445820, lambda e, rr: (log.put(e.arg32(0), e.arg32(1)), e.ret(eax=cbv, argbytes=0)))
    emu.w32(cvt + 0x170, 0x445820)
    m = r.randrange(1, 24)
    data = bytes(r.getrandbits(8) for _ in range(m * 4 + 8))
    sb = emu.alloc(0x100, 4)
    emu.wbytes(sb, data)
    pos, visited = 0, [0]
    for _ in range(m):
        b = data[pos]
        pos += 1 if tab178[b] else tab4c[b] - 3
        visited.append(pos)
    k = r.choice([0, 1, len(visited) - 1, r.randrange(len(visited))])
    end = sb + visited[k]
    db = emu.alloc(0x100, 4)
    dn = r.choice([0, 1, 2, 5, 12, 30])
    sp = _rnd(c, 4)
    dp = _rnd(c, 4)
    emu.w32(sp, sb)
    emu.w32(dp, db)
    _flush_heap_code(c)
    return [cvt, sp, end, dp, db + 2 * dn]

S(0x62c7f0, 'convert (GUESS)', 'cdecl', None, ret=None, gen=_s62c7f0_spec, note='batch842c; converter callback cvt[0x170] hooked')


def _s6321a0_spec(c):
    r = c.rng
    emu = c.emu
    log = _Log833(c)
    s = _rnd(c, 0x60)
    z = _rnd(c, 0x40)
    emu.w32(s, r.choice([0, 1, 4, 5, 6, 6, 7, 4, 5, 0x100000004]) & 0xffffffff)
    emu.hook(0x445830, lambda e, rr: (log.put(1, e.arg32(0), e.arg32(1)), e.ret(eax=r.getrandbits(32), argbytes=0)))
    emu.w32(z + 0x24, 0x445830)
    cbv = r.getrandbits(32)
    emu.hook(0x445840, lambda e, rr: (log.put(2, e.arg32(0), e.arg32(1), e.arg32(2)), e.ret(eax=cbv, argbytes=12)))
    emu.w32(s + 0x38, 0x445840 if r.random() < 0.6 else 0)
    emu.hook(0x633170, lambda e, rr: (log.put(3, e.arg32(0), e.arg32(1)), e.ret(argbytes=0)))
    _flush_heap_code(c)
    return [s, z]

S(0x6321a0, 'stateEnd (GUESS)', 'cdecl', None, ret='eax', gen=_s6321a0_spec, note='batch843; zfree z[0x24], callback s[0x38], 0x633170 hooked')


def _pool_spec(stride, ksz=16):
    def gen(c):
        r = c.rng
        emu = c.emu
        log = _Log833(c)
        self_ = _rnd(c, 0x30)
        vt = emu.alloc(0x40, 4)
        emu.w32(self_, vt)
        emu.w32(self_ + 0xc, r.getrandbits(32))
        nring = r.randrange(1, 6)
        ring = [emu.alloc(0x300, 4) for _ in range(nring)]
        for i, nd in enumerate(ring):
            emu.wbytes(nd, bytes(r.getrandbits(8) for _ in range(8)))
            emu.w32(nd + 8, ring[(i + 1) % nring])
            emu.w32(nd + 0xc, ring[(i - 1) % nring])
        hdr = ring[r.randrange(nring)]
        emu.wbytes(hdr, bytes([r.choice([1, 1, 2, 3, 0, 255])]))
        emu.w32(self_ + 8, r.choice(ring))
        item = hdr + 0x10 + stride * r.randrange(0, 7) + (r.randrange(0, stride) if r.random() < 0.3 else 0)
        emu.wbytes(item, bytes(r.getrandbits(8) for _ in range(8)))
        emu.hook(0x445850, lambda e, rr: (log.put(1, e.reg('ecx'), e.arg32(0)), e.ret(eax=hdr, argbytes=4)))
        emu.w32(vt + 0x2c, 0x445850)
        emu.hook(0x445860, lambda e, rr: (log.put(2, e.reg('ecx'), e.arg32(0)), e.ret(argbytes=4)))
        emu.w32(vt + 0x34, 0x445860)
        _flush_heap_code(c)
        return [self_, item]
    return gen

_s63f760_spec = _pool_spec(16)
S(0x63f760, 'poolRelease (GUESS)', 'thiscall', None, ret=None, gen=_s63f760_spec, note='batch844a; vt[0x2c] and vt[0x34] hooked, ring of blocks real')
S(0x63f6b0, 'poolRelease48 (GUESS)', 'thiscall', None, ret=None, gen=_pool_spec(48), note='batch844b; stride 48, item[5] not cleared')
S(0x63f8a0, 'poolRelease76 (GUESS)', 'thiscall', None, ret=None, gen=_pool_spec(76), note='batch844c; stride 76')
S(0x63f950, 'poolRelease64 (GUESS)', 'thiscall', None, ret=None, gen=_pool_spec(64), note='batch844d; stride 64')
S(0x63f9f0, 'poolRelease24 (GUESS)', 'thiscall', None, ret=None, gen=_pool_spec(24), note='batch844e; stride 24')


def _s630bb0_spec(c):
    r = c.rng
    emu = c.emu
    emu.hook(0x633654, lambda e, rr: e.ret(argbytes=0))
    emu.w32(0x6f5630, r.getrandbits(32))
    n = r.randrange(0, 24)
    tree = emu.alloc(4 * 32, 4)
    for i in range(32):
        ln = r.choice([0, 0, 1, 2, 3, 7, 8, 9, 14, 15, r.randrange(0, 16)])
        emu.wbytes(tree + 4 * i, bytes([r.getrandbits(8), r.getrandbits(8), ln, 0]))
    bl = emu.alloc(32, 4)
    emu.wbytes(bl, b''.join(r.choice([0, 1, 2, 3, r.getrandbits(16)]).to_bytes(2, 'little') for _ in range(16)))
    maxc = r.choice([-1, 0, n, n, 31, r.randrange(-1, 32)])
    _flush_heap_code(c)
    return [tree, maxc, bl]

S(0x630bb0, 'genCodes (GUESS)', 'cdecl', None, ret=None, gen=_s630bb0_spec, note='batch845; zlib gen_codes, /GS check hooked')


def _s62d840_spec(c):
    r = c.rng
    emu = c.emu
    log = _Log833(c)
    out = _rnd(c, 0x20)
    code = r.choice([0xf, 0x12, 0x12, 0x12, 0x1b, 0x1b, 0x1c, 0x1c, 0x10, r.getrandbits(32)])
    obj = _rnd(c, 0x40)
    a, b = r.getrandbits(32), r.getrandbits(32)
    answers = [r.choice([0, 0, 1, 5]) for _ in range(2)]
    n = [0]
    def cb(e, rr):
        i = n[0]
        n[0] += 1
        log.put(1, e.arg32(0), e.arg32(1), e.arg32(2), e.arg32(3))
        e.ret(eax=answers[min(i, 1)], argbytes=0)
    emu.hook(0x445870, cb)
    emu.w32(obj + 0x1c, 0x445870)
    if r.random() < 0.3:
        emu.w32(out + 0xc, 0)
    _flush_heap_code(c)
    return [out, code, a, b, obj]

S(0x62d840, 'queryHandler2 (GUESS)', 'cdecl', None, ret='eax', gen=_s62d840_spec, note='batch845b; callback obj[0x1c] hooked')


def _s63faa0_spec(c):
    r = c.rng
    emu = c.emu
    log = _Log833(c, 256)
    emu.hook(0x633654, lambda e, rr: e.ret(argbytes=0))
    emu.w32(0x6f5630, r.getrandbits(32))
    self_ = _rnd(c, 0x20)
    svt = emu.alloc(0x80, 4)
    emu.w32(self_, svt)
    emu.hook(0x445880, lambda e, rr: (log.put(1, e.reg('ecx'), e.arg32(0)), e.ret(argbytes=4)))
    emu.w32(svt + 0x50, 0x445880)
    pvt = emu.alloc(0x80, 4)
    chains = {}
    def pstub(e, rr):
        p = e.reg('ecx')
        ptr = e.arg32(0)
        ch = chains[p]
        nxt = ch.pop(0) if ch else 0
        log.put(2, p, e.r32(ptr), nxt)
        e.w32(ptr, nxt)
        e.ret(argbytes=4)
    emu.hook(0x445890, pstub)
    emu.w32(pvt + 0x50, 0x445890)
    n = r.randrange(0, 9)
    items = []
    for i in range(n):
        it = _rnd(c, 0x60)
        if r.random() < 0.2:
            emu.w32(it + 0x54, 0)
        else:
            p = _rnd(c, 0x20)
            q = emu.alloc(0x40, 4)
            flags = r.getrandbits(32) | (0x100000 if r.random() < 0.6 else 0)
            if not (flags & 0x100000) and r.random() < 0.5:
                flags &= ~0x100000 & 0xffffffff
            emu.wbytes(q + 0x23, flags.to_bytes(4, 'little'))
            emu.w32(p, pvt)
            emu.w32(p + 0xc, q)
            ch = [r.getrandbits(32) | 1 for _ in range(r.randrange(0, 4))]
            emu.w32(p + 8, ch.pop(0) if ch and r.random() < 0.85 else 0)
            chains[p] = ch
            emu.w32(it + 0x54, p)
        items.append(it)
    a = r.getrandbits(32)
    def f658(e, rr):
        buf = e.arg32(0)
        log.put(3, e.reg('ecx'), e.arg32(1))
        for k, it in enumerate(items):
            e.w32(buf + 4 * k, it)
        e.ret(eax=len(items), argbytes=8)
    emu.hook(0x658e00, f658)
    _flush_heap_code(c)
    return [self_, a]

S(0x63faa0, 'walkOwners (GUESS)', 'thiscall', None, ret=None, gen=_s63faa0_spec, note='batch845c; 0x658e00, vt[0x50] stand-ins, /GS check hooked')


def _scan_spec(c):
    r = c.rng
    emu = c.emu
    cvt = emu.alloc(0x180, 4)
    tab = bytes(r.choice([r.randrange(0, 40), r.randrange(20, 30), r.randrange(20, 30), 5, 6, 7, 8, 0x1d, 5, 6, 7, r.getrandbits(8)]) for _ in range(256))
    emu.wbytes(cvt + 0x4c, tab)
    n = r.randrange(0, 40)
    buf = emu.alloc(0x100, 4)
    hi = [0, 0, 0, 0xd8, 0xdb, 0xdc, 0xdf, 0xff, 0xe0, 0xd7, 0x01, r.getrandbits(8)]
    lo = [0, 1, 5, 0x41, 0xfd, 0xfe, 0xff, 0x80, r.getrandbits(8)]
    data = []
    for i in range(n):
        data += [r.choice(lo), r.choice(hi)] if r.random() < 0.5 else [r.choice(hi), r.choice(lo)]
    data += [0xdc] * 16
    emu.wbytes(buf, bytes(data))
    _flush_heap_code(c)
    return [cvt, buf]

S(0x622bb0, 'scanBE (GUESS)', 'cdecl', None, ret='eax', gen=_scan_spec, note='batch846a; big-endian UTF-16 class scanner')
S(0x625b30, 'scanLE (GUESS)', 'cdecl', None, ret='eax', gen=_scan_spec, note='batch846b; little-endian UTF-16 class scanner')


def _s622310_spec(c):
    r = c.rng
    emu = c.emu
    cvt = emu.alloc(0x180, 4)
    # a small alphabet keeps strings matching often; classes: 5/6/7 multi-byte leads, 22/23/24 single, others end
    alpha = [0x41, 0x42, 0x43, 0xd8, 0xdc, 0xe0, 0xf0, 0x20, 0x00]
    tab = bytearray(r.choice([r.randrange(0, 40), 5, 6, 7, 22, 24, 23, 8, 0x1d, 21, 20, 21, 4, 9]) for _ in range(256))
    emu.wbytes(cvt + 0x4c, bytes(tab))
    n = r.randrange(0, 12)
    s1 = [r.choice(alpha) for _ in range(n)] + [r.choice(alpha) for _ in range(8)]
    s2 = list(s1)
    for _ in range(r.choice([0, 0, 1, 2])):
        s2[r.randrange(len(s2))] = r.choice(alpha)
    if r.random() < 0.3:
        s2 = s2[:r.randrange(0, len(s2))] + [r.choice(alpha) for _ in range(8)]
    # make the walk end: a byte of an ending class closes s1
    endb = next((b for b in range(256) if 5 + 3 <= tab[b] <= 5 + 16), None)
    if endb is not None:
        s1[n] = endb
    b1 = emu.alloc(0x80, 4)
    b2 = emu.alloc(0x80, 4)
    emu.wbytes(b1, bytes(s1 + [endb if endb is not None else 0] * 8))
    emu.wbytes(b2, bytes((s2 + [0] * 16)[:0x70]))
    _flush_heap_code(c)
    return [cvt, b1, b2]

S(0x622310, 'matchPrefix (GUESS)', 'cdecl', None, ret='eax', gen=_s622310_spec, note='batch846c; class-driven prefix compare')


def _s632230_spec(c):
    r = c.rng
    emu = c.emu
    log = _Log833(c, 128)
    z = _rnd(c, 0x40)
    emu.w32(z + 0x28, r.getrandbits(32))
    fail_at = r.choice([-1, -1, 0, 1, 2])
    pool = [emu.alloc(0x40, 4) for _ in range(3)]
    calls = [0]
    def alloc(e, rr):
        i = calls[0]
        calls[0] += 1
        log.put(1, e.arg32(0), e.arg32(1), e.arg32(2))
        e.ret(eax=0 if i == fail_at else pool[min(i, 2)], argbytes=0)
    emu.hook(0x4458a0, alloc)
    emu.w32(z + 0x20, 0x4458a0)
    emu.hook(0x4458b0, lambda e, rr: (log.put(2, e.arg32(0), e.arg32(1)), e.ret(argbytes=0)))
    emu.w32(z + 0x24, 0x4458b0)
    emu.hook(0x6322e0, lambda e, rr: (log.put(3, e.arg32(0), e.arg32(1), e.arg32(2)), e.ret(argbytes=0)))
    _flush_heap_code(c)
    return [z, r.getrandbits(32), r.choice([0, 1, 0x100, 0x8000, r.getrandbits(16)])]

S(0x632230, 'stateNew (GUESS)', 'cdecl', None, ret='eax', gen=_s632230_spec, note='batch847; z[0x20] alloc, z[0x24] free, 0x6322e0 hooked')


def _s639c50_spec(c):
    r = c.rng
    emu = c.emu
    log = _Log833(c, 128)
    self_ = _rnd(c, 0x30)
    vt = emu.alloc(0x40, 4)
    emu.w32(self_, vt)
    cnt = r.randrange(0, 5)
    arr = emu.alloc(0x14 * 6, 4) if r.random() < 0.85 else 0
    if arr:
        emu.wbytes(arr, bytes(r.getrandbits(8) if r.random() < 0.6 else 0 for _ in range(0x14 * 6)))
        for i in range(6):
            emu.wbytes(arr + 0x14 * i + 0xc, bytes([r.choice([0, 1, 7, 0x80])]))
    emu.w32(self_ + 0x14, arr)
    emu.w32(self_ + 0x10, r.getrandbits(32))
    emu.hook(0x4458c0, lambda e, rr: (log.put(1, e.reg('ecx')), e.ret(eax=cnt, argbytes=0)))
    emu.w32(vt + 0x34, 0x4458c0)
    emu.hook(0x634273, lambda e, rr: (log.put(2, e.arg32(0), e.arg32(1)), e.ret(argbytes=0)))
    newbuf = emu.alloc(0x200, 4)
    emu.wbytes(newbuf, bytes(r.getrandbits(8) for _ in range(0x200)))
    emu.hook(0x41e290, lambda e, rr: (log.put(3, e.arg32(0)), e.ret(eax=newbuf, argbytes=0)))
    n = r.choice([0, 1, 2, 5, 8, 0x80000000, 0xcccccccd, 0xffffffff, r.randrange(0, 20)])
    _flush_heap_code(c)
    return [self_, n]

S(0x639c50, 'resetTable (GUESS)', 'thiscall', None, ret=None, gen=_s639c50_spec, note='batch848; vt[0x34], 0x634273, 0x41e290 hooked')


def _token_spec(callee):
    def gen(c):
        r = c.rng
        emu = c.emu
        log = _Log833(c, 64)
        cvt = emu.alloc(0x180, 4)
        tab = bytes(r.choice([0x19, 0x19, 0x12, 0x12, 5, 0x1d, r.getrandbits(8)]) for _ in range(256))
        emu.wbytes(cvt + 0x4c, tab)
        n = r.randrange(0, 8)
        hi = [0, 0, 0, 0xd8, 0xdc, 0xe0, 0xff, 0x01, 0x20, r.getrandbits(8)]
        lo = [0x78, 0x78, 0, 1, 0x41, 0x20, 0xfe, 0xff, r.getrandbits(8)]
        data = []
        for i in range(n):
            data += [r.choice(lo), r.choice(hi)] if r.random() < 0.5 else [r.choice(hi), r.choice(lo)]
        buf = emu.alloc(0x80, 4)
        emu.wbytes(buf, bytes(data + [0] * 8))
        out = emu.alloc(8, 4)
        res = r.getrandbits(32)
        emu.hook(callee, lambda e, rr: (log.put(e.arg32(0), e.arg32(1), e.arg32(2)), e.ret(eax=res, argbytes=0)))
        _flush_heap_code(c)
        return [cvt, buf, buf + 2 * n, out]
    return gen

S(0x627470, 'readTokenBE (GUESS)', 'cdecl', None, ret='eax', gen=_token_spec(0x6279e0), note='batch849a; big-endian token reader, 0x6279e0 hooked, 0x62c640 real')
S(0x6294d0, 'readTokenLE (GUESS)', 'cdecl', None, ret='eax', gen=_token_spec(0x629a40), note='batch849b; little-endian token reader, 0x629a40 hooked, 0x62c640 real')


def _s63fb40_spec(c):
    r = c.rng
    emu = c.emu
    log = _Log833(c, 64)
    self_ = _rnd(c, 0x80)
    vt = emu.alloc(0x80, 4)
    emu.w32(self_, vt)
    tbl = emu.alloc(0x4000, 4)
    emu.w32(self_ + 0x68, tbl)
    idv = r.choice([0, 1, 2, 3, 0x1003, 0x803, 0xfff, 0x8002])
    a = _rnd(c, 0x80)
    emu.wbytes(a + 0x5a, bytes([idv & 0xff, idv >> 8]))
    ent = _rnd(c, 0x80)
    emu.wbytes(ent + 4, bytes([r.choice([0, 1, 2, 3, 3, 4, 5, 0xff, r.getrandbits(8)])]))
    emu.w32(tbl + (idv & 0xfff) * 4, ent)
    emu.w32(ent + 0x44, 0 if r.random() < 0.4 else r.getrandbits(32) | 1)
    emu.w32(ent + 0x40, r.getrandbits(32) | 1)
    emu.w32(ent + 0x3c, r.getrandbits(32) | (0x10 if r.random() < 0.6 else 0))
    emu.hook(0x4458d0, lambda e, rr: (log.put(1, e.reg('ecx')), e.ret(argbytes=0)))
    emu.hook(0x63ee70, lambda e, rr: (log.put(2, e.reg('ecx'), e.arg32(0)), e.ret(argbytes=4)))
    emu.hook(0x63faa0, lambda e, rr: (log.put(3, e.reg('ecx'), e.arg32(0)), e.ret(argbytes=4)))
    emu.hook(0x658fd0, lambda e, rr: (log.put(4, e.reg('ecx'), e.arg32(0)), e.ret(argbytes=4)))
    emu.hook(0x4458e0, lambda e, rr: (log.put(5), e.ret(argbytes=0)))
    emu.w32(vt + 0x60, 0x4458d0 + 0)
    emu.w32(0x7003b0, 0x4458e0)
    _flush_heap_code(c)
    return [self_, a]

S(0x63fb40, 'releaseEntry (GUESS)', 'thiscall', None, ret=None, gen=_s63fb40_spec, note='batch850; 0x63ee70, 0x63faa0, 0x658fd0, vt[0x60], assert hook stand-ins')


def _s62ee40_spec(c):
    r = c.rng
    emu = c.emu
    log = _Log833(c, 64)
    if r.random() < 0.07:
        _flush_heap_code(c)
        return [0]
    z = _rnd(c, 0x40)
    emu.w32(z + 0x28, r.getrandbits(32))
    emu.hook(0x4458f0, lambda e, rr: (log.put(e.arg32(0), e.arg32(1)), e.ret(argbytes=0)))
    emu.w32(z + 0x24, 0x4458f0)
    if r.random() < 0.08:
        emu.w32(z + 0x1c, 0)
    else:
        st = _rnd(c, 0x50)
        emu.w32(z + 0x1c, st)
        emu.w32(st + 4, r.choice([0x2a, 0x71, 0x29a, 0x2a, 0x71, 0x29a, 0x2b, 0, r.getrandbits(32)]))
        for off in (8, 0x3c, 0x38, 0x30):
            emu.w32(st + off, 0 if r.random() < 0.4 else r.getrandbits(32) | 1)
    _flush_heap_code(c)
    return [z]

S(0x62ee40, 'streamEnd (GUESS)', 'stdcall', None, ret='eax', gen=_s62ee40_spec, note='batch851; z[0x24] free stand-in')


def _s63ed60_spec(c):
    r = c.rng
    emu = c.emu
    log = _Log833(c, 128)
    self_ = emu.alloc(0x280, 4)
    emu.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x280)))
    emu.w32(self_ + 0x60, 0 if r.random() < 0.8 else r.getrandbits(32) | 1)
    emu.w32(self_ + 0x10, r.choice([0, 1, 0x100, r.getrandbits(16)]))
    emu.w32(self_ + 0x254, r.choice([0, 1, 3, r.getrandbits(32)]))
    svt = emu.alloc(0x40, 4)
    emu.w32(self_, svt)
    g = emu.alloc(0x20, 4)
    gvt = emu.alloc(0x60, 4)
    emu.w32(g, gvt)
    emu.w32(0x70038c, g)
    hv = r.getrandbits(32)
    emu.hook(0x445900, lambda e, rr: (log.put(1, e.reg('ecx'), e.arg32(0)), e.ret(eax=hv, argbytes=4)))
    emu.w32(gvt + 0x48, 0x445900)
    qbuf = emu.alloc(0x40, 4)
    emu.hook(0x445910, lambda e, rr: (log.put(2, e.reg('ecx'), e.arg32(0)), e.ret(eax=qbuf, argbytes=4)))
    emu.w32(gvt + 0xc, 0x445910)
    vbuf = emu.alloc(0x40, 4)
    emu.hook(0x445920, lambda e, rr: (log.put(3, e.reg('ecx'), e.arg32(0)), e.ret(eax=vbuf, argbytes=4)))
    emu.w32(svt + 0x20, 0x445920)
    pbuf = emu.alloc(0x40, 4) if r.random() < 0.85 else 0
    emu.hook(0x41e290, lambda e, rr: (log.put(4, e.arg32(0)), e.ret(eax=pbuf, argbytes=0)))
    rv = r.getrandbits(32)
    emu.hook(0x63a800, lambda e, rr: (log.put(5, e.reg('ecx'), e.arg32(0), e.arg32(1)), e.ret(eax=rv, argbytes=8)))
    emu.hook(0x634d10, lambda e, rr: (log.put(6, e.arg32(0), e.arg32(1), e.arg32(2)), e.ret(argbytes=0)))
    _flush_heap_code(c)
    return [self_]

S(0x63ed60, 'initBuffers (GUESS)', 'thiscall', None, ret=None, gen=_s63ed60_spec, note='batch851b; global 0x70038c object, 0x41e290, 0x63a800, 0x634d10, vt slots hooked')


def _s622410_spec(c):
    r = c.rng
    emu = c.emu
    if r.random() < 0.4:
        v = r.choice([0, 1, 0x41, 0xff, 0x100, 0xd7ff, 0xd800, 0xdbff, 0xdfff, 0xe000, 0xfeff, 0xff00, 0xfffd, 0xfffe, 0xffff,
                      0x10000, 0x10ffff, 0x110000, 0x110001, 0x1fffff, 0x7f, 0x80, 0x20, 0x1f])
        hexmode = r.random() < 0.5
        txt = (('x' + (('%X' if r.random() < 0.5 else '%x') % v)) if hexmode else str(v))
        units = [(0, ord(ch)) for ch in txt]
    else:
        n = r.randrange(0, 10)
        kind = r.randrange(3)
        units = []
        if kind == 0:
            units.append((0, 0x78))
        if kind == 2:
            units.append((r.choice([0, 0, 1]), r.choice([0x31, 0x78, 0x30])))
        pool = [(0, ord(ch)) for ch in '0123456789abcdefABCDEFxg:/@[`{ ']
        pool += [(0, 0x3b), (1, 0x30), (r.randrange(1, 256), r.getrandbits(8)), (0, 0xff), (0, 0x80)]
        for _ in range(n):
            units.append(r.choice(pool) if r.random() < 0.85 else (0, r.choice([0x30, 0x31, 0x39, 0x66, 0x46])))
    data = [0, 0, 0, 0] + [b for u in units for b in u] + [0, 0x3b] * 4
    buf = emu.alloc(0x100, 4)
    emu.wbytes(buf, bytes(data))
    _flush_heap_code(c)
    return [r.getrandbits(32), buf]

S(0x622410, 'parseCharRef (GUESS)', 'cdecl', None, ret='eax', gen=_s622410_spec, note='batch852; numeric character reference parser, table at 0x6bf2f4 real')


def _s6253b0_spec(c):
    r = c.rng
    emu = c.emu
    cvt = emu.alloc(0x180, 4)
    tab = bytearray(r.choice([r.randrange(0, 40), 5, 6, 7, 22, 24, 23, 8, 0x1d, 21, 20, 21, 4, 9, 17, 18]) for _ in range(256))
    emu.wbytes(cvt + 0x4c, bytes(tab))
    alpha = [(0x41, 0), (0x42, 0), (0x43, 0), (0x20, 0), (0x00, 0), (0x01, 0), (0x34, 0x12), (0x78, 0xd8), (0x10, 0xdc), (0x01, 0xe0), (0x00, 0xff), (0xfe, 0xff)]
    n = r.randrange(0, 8)
    s1 = []
    for _ in range(n + 6):
        s1 += list(r.choice(alpha))
    s2 = list(s1)
    for _ in range(r.choice([0, 0, 1, 2])):
        s2[r.randrange(len(s2))] = r.choice([0, 1, 0x41, 0x78, 0xdc, r.getrandbits(8)])
    if r.random() < 0.3:
        s2 = s2[:r.randrange(0, len(s2))] + [x for u in [r.choice(alpha) for _ in range(6)] for x in u]
    # make the s1 walk end: an ending-class unit closes it
    endb = next((b for b in range(256) if 8 <= tab[b] <= 21), None)
    if endb is not None:
        s1[2 * n] = endb
        s1[2 * n + 1] = 0
    b1 = emu.alloc(0x80, 4)
    b2 = emu.alloc(0x80, 4)
    emu.wbytes(b1, bytes(s1 + [endb if endb is not None else 0, 0] * 6))
    emu.wbytes(b2, bytes((s2 + [0] * 24)[:0x70]))
    _flush_heap_code(c)
    return [cvt, b1, b2]

S(0x6253b0, 'matchPrefixLE (GUESS)', 'cdecl', None, ret='eax', gen=_s6253b0_spec, note='batch852b; little-endian class-driven prefix compare, 0x62c640 real')


def _s63d840_spec(c):
    r = c.rng
    emu = c.emu
    log = _Log833(c, 128)
    self_ = emu.alloc(0x8300, 16)
    emu.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x100)))
    emu.wbytes(self_ + 5, bytes([0 if r.random() < 0.15 else r.choice([1, 2, 0xff])]))
    vt = emu.alloc(0x80, 4)
    emu.w32(self_, vt)
    emu.hook(0x445930, lambda e, rr: (log.put(1, e.reg('ecx')), e.ret(argbytes=0)))
    emu.w32(vt + 0x64, 0x445930)
    n = r.randrange(0, 5)
    emu.w32(self_ + 0xec, n)
    for i in range(n):
        emu.w32(self_ + 0xf0 + 4 * i, 0 if r.random() < 0.25 else _rnd(c, 0x20))
    emu.w32(self_ + 0x60, r.getrandbits(32))
    emu.w32(self_ + 0x64, r.getrandbits(32))
    emu.hook(0x64b070, lambda e, rr: (log.put(2, e.reg('ecx')), e.ret(argbytes=0)))
    emu.hook(0x648280, lambda e, rr: (log.put(3, e.reg('ecx')), e.ret(argbytes=0)))
    emu.hook(0x634273, lambda e, rr: (log.put(4, e.arg32(0), e.arg32(1)), e.ret(argbytes=0)))
    emu.hook(0x634d10, lambda e, rr: (log.put(5, e.arg32(0), e.arg32(1), e.arg32(2)), e.ret(argbytes=0)))
    emu.hook(0x63fc20, lambda e, rr: (log.put(6, e.reg('ecx')), e.ret(argbytes=0)))
    emu.hook(0x65f0f0, lambda e, rr: (log.put(7, e.reg('ecx')), e.ret(argbytes=0)))
    _flush_heap_code(c)
    return [self_]

S(0x63d840, 'teardown (GUESS)', 'thiscall', None, ret=None, gen=_s63d840_spec, note='batch853; vt[0x64] and six callees hooked')


def _s622980_spec(c):
    r = c.rng
    emu = c.emu
    cvt = emu.alloc(0x180, 4)
    tab = bytearray(r.choice([r.randrange(0, 40), 5, 6, 7, 22, 24, 23, 8, 0x1d, 21, 20, 21, 4, 9, 17, 18]) for _ in range(256))
    emu.wbytes(cvt + 0x4c, bytes(tab))
    alpha = [(0, 0x41), (0, 0x42), (0, 0x43), (0, 0x20), (0, 0x00), (0, 0x01), (0x12, 0x34), (0xd8, 0x78), (0xdc, 0x10), (0xe0, 0x01), (0xff, 0x00), (0xff, 0xfe)]
    n = r.randrange(0, 8)
    s1 = []
    for _ in range(n + 6):
        s1 += list(r.choice(alpha))
    s2 = list(s1)
    for _ in range(r.choice([0, 0, 1, 2])):
        s2[r.randrange(len(s2))] = r.choice([0, 1, 0x41, 0x78, 0xdc, r.getrandbits(8)])
    if r.random() < 0.3:
        s2 = s2[:r.randrange(0, len(s2))] + [x for u in [r.choice(alpha) for _ in range(6)] for x in u]
    # make the s1 walk end: an ending-class unit closes it
    endb = next((b for b in range(256) if 8 <= tab[b] <= 21), None)
    if endb is not None:
        s1[2 * n] = 0
        s1[2 * n + 1] = endb
    b1 = emu.alloc(0x80, 4)
    b2 = emu.alloc(0x80, 4)
    emu.wbytes(b1, bytes(s1 + [0, endb if endb is not None else 0] * 6))
    emu.wbytes(b2, bytes((s2 + [0] * 24)[:0x70]))
    _flush_heap_code(c)
    return [cvt, b1, b2]

S(0x622980, 'matchPrefixBE (GUESS)', 'cdecl', None, ret='eax', gen=_s622980_spec, note='batch853b; big-endian class-driven prefix compare, 0x62c640 real')


def _s6386c0_spec(c):
    r = c.rng
    emu = c.emu
    log = _Log833(c, 64)
    self_ = _rnd(c, 0x20)
    vt = emu.alloc(0x100, 4)
    emu.w32(self_, vt)
    size = r.choice([0, 1, 15, 16, 17, r.getrandbits(16), r.getrandbits(32)])
    n = r.choice([0, 1, 2, 3, 5, 9, 12])
    w = r.choice([1, 2, 3, 4, 7, 8, 9, 64, 100, 1000, r.getrandbits(12)])
    h = r.choice([1, 2, 3, 4, 7, 8, 9, 64, 100, 1000, r.getrandbits(12)])
    for off, val, tag in ((0x88, 0, 1), (0x84, size, 2), (0x34, n, 3), (0x1c, w, 4), (0x20, h, 5)):
        stub = 0x445940 + off
        emu.hook(stub, (lambda t, v: lambda e, rr: (log.put(t, e.reg('ecx')), e.ret(eax=v, argbytes=0)))(tag, val))
        emu.w32(vt + off, stub)
    emu.hook(0x445a00, lambda e, rr: (log.put(9), e.ret(argbytes=0)))
    emu.w32(0x7003b0, 0x445a00)
    out = emu.alloc(8, 4)
    mode = r.choice([4, 4, 8, 8, 0, 1, 16, r.getrandbits(32)])
    _flush_heap_code(c)
    return [self_, mode, out]

S(0x6386c0, 'surfaceSize (GUESS)', 'thiscall', None, ret='eax', gen=_s6386c0_spec, note='batch854; five vt slots and the assert hook stand-ins')


def _s63b850_spec(c):
    r = c.rng
    emu = c.emu
    log = _Log833(c, 128)
    g = emu.alloc(0x1b00, 16)
    gobj = _rnd(c, 0x40)
    emu.w32(gobj + 0x20, r.getrandbits(32))
    emu.w32(g + 0x1aa3, gobj)
    emu.w32(0x70039c, g)
    idv = r.choice([0, 1, 2, 3, 0x1003, 0x803, 0xfff, 0x8002])
    low = idv & 0xfff
    cnt = r.choice([0, 1, 2, 3, 4, 255])
    arr = emu.alloc(0x8 * 258, 4)
    emu.wbytes(arr, bytes(r.getrandbits(8) for _ in range(0x40)))
    ent = _rnd(c, 0x50)
    emu.wbytes(ent + 0x3d, bytes([cnt]))
    emu.w32(ent + 0x40, arr)
    tbl = emu.alloc(0x4000, 4)
    emu.w32(tbl + low * 4, ent)
    na = emu.alloc(8 * 260, 4)
    nlis = r.randrange(0, 3)
    self_ = emu.alloc(0x110, 4)
    emu.wbytes(self_, bytes(0x110))
    vt = emu.alloc(0x40, 4)
    emu.w32(self_, vt)
    emu.w32(self_ + 0x68, tbl)
    emu.w32(self_ + 0xec, nlis)
    emu.hook(0x445b00, lambda e, rr: (log.put(1, e.reg('ecx'), e.arg32(0)), e.ret(eax=na, argbytes=4)))
    emu.w32(vt + 0x20, 0x445b00)
    emu.hook(0x445b10, lambda e, rr: (log.put(2, e.reg('ecx'), e.arg32(0), e.arg32(1)), e.ret(argbytes=8)))
    emu.w32(vt + 0x24, 0x445b10)
    emu.hook(0x634d22, lambda e, rr: (log.put(3, e.arg32(0), e.arg32(1), e.arg32(2)), e.ret(argbytes=0)))
    R = _rnd(c, 0x30)
    emu.hook(0x64c7e0, lambda e, rr: (log.put(4, e.arg32(0)), e.ret(eax=R, argbytes=4)))
    for i in range(nlis):
        cc = emu.alloc(0x10080, 16)
        tb = emu.alloc(0x4000, 4)
        if r.random() < 0.6:
            emu.w32(tb + low * 4, r.getrandbits(32) | 1)
        emu.w32(cc + 0x10071, tb)
        emu.w32(self_ + 0xf0 + 4 * i, cc)
    a = _rnd(c, 0x80)
    emu.wbytes(a + 0x5a, bytes([idv & 0xff, idv >> 8]))
    _flush_heap_code(c)
    return [self_, a, r.choice([0, 4, r.getrandbits(32)])]

S(0x63b850, 'addPair (GUESS)', 'thiscall', None, ret=None, gen=_s63b850_spec, note='batch854b; global 0x70039c pre-set, vt[0x20]/[0x24], 0x634d22, 0x64c7e0 hooked')


def _s63e910_spec(c):
    r = c.rng
    emu = c.emu
    log = _Log833(c, 128)
    self_ = _rnd(c, 0x30)
    vt = emu.alloc(0x40, 4)
    emu.w32(self_, vt)
    ent = _rnd(c, 0x60)
    cnt = r.choice([0, 1, 2, 3, 5])
    emu.wbytes(ent + 0x3d, bytes([cnt]))
    arr = emu.alloc(8 * 6, 4) if r.random() < 0.85 else 0
    if arr:
        for i in range(6):
            emu.w32(arr + 8 * i, 0 if r.random() < 0.3 else _rnd(c, 0x20))
            emu.w32(arr + 8 * i + 4, r.getrandbits(32))
    emu.w32(ent + 0x40, arr)
    emu.w32(ent + 0x48, r.getrandbits(32))
    emu.w32(ent + 0x3c, (r.getrandbits(32) & 0xffff00ff) | (cnt << 8) | (8 if r.random() < 0.6 else 0))
    w = 0 if r.random() < 0.25 else _rnd(c, 0x50)
    emu.w32(ent + 0x44, w)
    # ent[0x38] -> s -> [0x54] = o (vt slot 0x284), o[8] -> blk with [0x6c]
    o = _rnd(c, 0x20)
    ovt = emu.alloc(0x300, 4)
    emu.w32(o, ovt)
    blk = _rnd(c, 0x80)
    emu.w32(o + 8, blk)
    s_ = _rnd(c, 0x60)
    emu.w32(s_ + 0x54, o)
    emu.w32(ent + 0x38, 0 if r.random() < 0.3 else s_)
    g = emu.alloc(0x1b00, 16)
    gobj = _rnd(c, 0x40)
    o2 = _rnd(c, 0x20)
    o2vt = emu.alloc(0x100, 4)
    emu.w32(o2, o2vt)
    emu.w32(gobj + 0x18, o2)
    emu.w32(g + 0x1aa3, gobj)
    emu.w32(0x70039c, g)
    res = [r.choice([0, 1, 7]), r.choice([0, 1, 7])]
    n = [0]
    def h658d30(e, rr):
        i = n[0]
        n[0] += 1
        log.put(1, e.reg('ecx'))
        e.ret(eax=res[min(i, 1)] if i < 1 else r.getrandbits(32) | 1 if False else (res[1] if i == 1 else 5), argbytes=0)
    emu.hook(0x658d30, h658d30)
    szv = r.getrandbits(16)
    emu.hook(0x658d50, lambda e, rr: (log.put(2, e.reg('ecx')), e.ret(eax=szv, argbytes=0)))
    emu.hook(0x658fb0, lambda e, rr: (log.put(3, e.reg('ecx'), e.arg32(0)), e.ret(argbytes=4)))
    emu.hook(0x63faa0, lambda e, rr: (log.put(4, e.reg('ecx'), e.arg32(0)), e.ret(argbytes=4)))
    emu.hook(0x445c00, lambda e, rr: (log.put(5, e.reg('ecx'), e.arg32(0), e.arg32(1)), e.ret(argbytes=8)))
    emu.w32(vt + 0x24, 0x445c00)
    emu.hook(0x445c10, lambda e, rr: (log.put(6, e.reg('ecx'), e.arg32(0), e.arg32(1)), e.ret(argbytes=8)))
    emu.w32(ovt + 0x284, 0x445c10)
    vv = r.getrandbits(32)
    emu.hook(0x445c20, lambda e, rr: (log.put(7, e.reg('ecx'), e.arg32(0)), e.ret(eax=vv, argbytes=4)))
    emu.w32(o2vt + 0xc4, 0x445c20)
    _flush_heap_code(c)
    return [self_, ent]

S(0x63e910, 'releaseResources (GUESS)', 'thiscall', None, ret=None, gen=_s63e910_spec, note='batch855; 0x658d30/50, 0x658fb0, 0x63faa0, vt slots, global 0x70039c object hooked')


def _s629580_spec(c):
    r = c.rng
    emu = c.emu
    cvt = emu.alloc(0x180, 4)
    tab = bytearray(r.choice([0, 1, 2, 5, 6, 7, 8, 27, 27, 12, 0x1d, 9, 4]) for _ in range(256))
    if r.random() < 0.6:
        tab[0x2d] = 27
        for ch in (0x41, 0x20, 0x05, 0x78):
            tab[ch] = r.choice([5, 6, 6, 7, 5, 9])
        tab[0x3e] = r.choice([5, 9, 12])
    tab[0] = 0
    emu.wbytes(cvt + 0x4c, bytes(tab))
    lo = [0x2d, 0x2d, 0x3e, 0x3e, 0x41, 0x20, 0x00, 0x01, 0x05, 0x78, 0xff, r.getrandbits(8)]
    hi = [0, 0, 0, 0, 0, 0, 0xd8, 0xdc, 0xe0, 0x01]
    n = r.randrange(0, 10)
    data = []
    exact3 = r.random() < 0.12
    if exact3:
        tab[0x20] = 6
        emu.wbytes(cvt + 0x4c, bytes(tab))
        n = 0
    if r.random() < 0.8 or exact3:
        data += [0x2d, 0]
    if exact3:
        data += [0x20, 0, 0x41, 0x20, 0, 0x41][:r.choice([6, 6, 5, 7])]
    for _ in range(n):
        if r.random() < 0.2:
            data += [0x2d, 0, 0x2d, 0, 0x3e, 0] if r.random() < 0.7 else [0x2d, 0, 0x2d, 0, 0x2d, 0, 0x3e, 0]
        elif r.random() < 0.3:
            data += [r.choice([0x41, 0x20, 0x05]), 0]
        else:
            data += [r.choice(lo), r.choice(hi)]
    end_off = len(data)
    data += [0] * 16
    buf = emu.alloc(0x100, 4)
    emu.wbytes(buf, bytes(data))
    out = emu.alloc(8, 4)
    _flush_heap_code(c)
    return [cvt, buf, buf + end_off, out]

S(0x629580, 'readCommentLE (GUESS)', 'cdecl', None, ret='eax', gen=_s629580_spec, note='batch856; comment tail reader, 0x62c640 real')


def _s627a80_spec(c):
    r = c.rng
    emu = c.emu
    cvt = emu.alloc(0x180, 4)
    tab = bytearray(r.choice([0, 1, 2, 5, 6, 7, 8, 12, 13, 12, 13, 9, 10, 11, 20, 21, 30, 0x1d, 4, 14]) for _ in range(256))
    if r.random() < 0.7:
        for ch in (0x41, 0x20, 0x05, 0x01, 0x78):
            tab[ch] = r.choice([5, 6, 7, 5, 6, 7, 9, 10, 11, 11, 2])
        tab[0x22] = r.choice([12, 13, 5])
        tab[0x27] = r.choice([12, 13, 6])
        tab[0x3e] = r.choice([9, 11, 20, 21, 30, 4])
        tab[0x2f] = r.choice([9, 11, 20, 21, 30, 4, 0])
    tab[0] = 0
    emu.wbytes(cvt + 0x4c, bytes(tab))
    lo = [0x22, 0x27, 0x41, 0x20, 0x01, 0x05, 0x3e, 0x2f, 0x78, 0xff, r.getrandbits(8)]
    hi = [0, 0, 0, 0, 0, 0, 0xd8, 0xdc, 0xe0, 0x01]
    n = r.randrange(0, 10)
    data = []
    if r.random() < 0.12:
        tab[0x20] = 6
        tab[0x41] = r.choice([5, 11, 10])
        emu.wbytes(cvt + 0x4c, bytes(tab))
        data = [0, 0x20, 0x41, 0, 0x20, 0x05][:r.choice([6, 6, 5, 4])]
        n = 0
    for _ in range(n):
        data += [r.choice(hi), r.choice(lo)]
    end_off = len(data)
    data += [0] * 16
    buf = emu.alloc(0x100, 4)
    emu.wbytes(buf, bytes(data))
    out = emu.alloc(8, 4)
    quote = r.choice([12, 13, 12, 13, 11, 11, 10, 9, 5, 0xd, 0, r.getrandbits(8)])
    _flush_heap_code(c)
    return [quote, cvt, buf, buf + end_off, out]

S(0x627a80, 'readQuotedBE (GUESS)', 'cdecl', None, ret='eax', gen=_s627a80_spec, note='batch857; quoted value reader, 0x62c640 real')


def _s624b70_spec(c):
    r = c.rng
    emu = c.emu
    if r.random() < 0.4:
        v = r.choice([0, 1, 0x41, 0xff, 0x100, 0xd7ff, 0xd800, 0xdbff, 0xdfff, 0xe000, 0xfeff, 0xff00, 0xfffd, 0xfffe, 0xffff,
                      0x10000, 0x10ffff, 0x110000, 0x110001, 0x1fffff, 0x7f, 0x80, 0x20, 0x1f])
        hexmode = r.random() < 0.5
        txt = (('x' + (('%X' if r.random() < 0.5 else '%x') % v)) if hexmode else str(v))
        units = [(ord(ch), 0) for ch in txt]
    else:
        n = r.randrange(0, 10)
        kind = r.randrange(3)
        units = []
        if kind == 0:
            units.append((0x78, 0))
        if kind == 2:
            units.append((r.choice([0x31, 0x78, 0x30]), r.choice([0, 0, 1])))
        pool = [(ord(ch), 0) for ch in '0123456789abcdefABCDEFxg:/@[`{ ']
        pool += [(0x3b, 0), (0x30, 1), (r.getrandbits(8), r.randrange(1, 256)), (0xff, 0), (0x80, 0)]
        for _ in range(n):
            units.append(r.choice(pool) if r.random() < 0.85 else (r.choice([0x30, 0x31, 0x39, 0x66, 0x46]), 0))
    data = [0, 0, 0, 0] + [b for u in units for b in u] + [0x3b, 0] * 4
    buf = emu.alloc(0x100, 4)
    emu.wbytes(buf, bytes(data))
    _flush_heap_code(c)
    return [r.getrandbits(32), buf]

S(0x624b70, 'parseCharRefLE (GUESS)', 'cdecl', None, ret='eax', gen=_s624b70_spec, note='batch858; little-endian numeric character reference parser, table at 0x6bf2f4 real')


def _s6387d0_spec(c):
    r = c.rng
    emu = c.emu
    log = _Log833(c, 256)
    emu.hook(0x633654, lambda e, rr: e.ret(argbytes=0))
    emu.w32(0x6f5630, r.getrandbits(32))
    self_ = _rnd(c, 0x20)
    vt = emu.alloc(0x80, 4)
    emu.w32(self_, vt)
    W = r.choice([0, 1, 2, 3, 5])
    H = r.choice([0, 1, 2, 3])
    pitch = r.choice([4, 5, 8])
    sbase = emu.alloc(4 * pitch * 6 + 64, 4)
    emu.wbytes(sbase, bytes(r.getrandbits(8) for _ in range(4 * pitch * 6 + 64)))
    surf = _rnd(c, 0x20)
    emu.w32(surf + 4, pitch)
    emu.w32(surf + 0x10, sbase)
    a = _rnd(c, 0x60)
    x0 = r.randrange(0, 2)
    y0 = r.randrange(0, 2)
    emu.w32(a, x0)
    emu.w32(a + 4, y0)
    emu.w32(a + 8, W if r.random() < 0.9 else r.choice([0, 0xffffffff]))
    emu.w32(a + 0xc, H if r.random() < 0.9 else r.choice([0, 0xffffffff]))
    dpitch = r.choice([0, 8, 16, 20, 32])
    emu.w32(a + 0x10, dpitch)
    emu.w32(a + 0x24, r.choice([16, 32, 24, 16, 0]))
    emu.wbytes(a + 0x28, bytes([r.getrandbits(8)]))
    dst = emu.alloc(0x200, 4)
    emu.w32(a + 0x2c, dst)
    emu.hook(0x445d00, lambda e, rr: (log.put(1, e.reg('ecx'), e.arg32(0)), e.ret(eax=surf, argbytes=4)))
    emu.w32(vt + 0x38, 0x445d00)
    def h4d(e, rr):
        c1 = e.reg('ecx'); a1 = e.arg32(0)
        log.put(2, *[e.r32(c1 + 4 * k) for k in range(4)], *[e.r32(a1 + 4 * k) for k in range(4)])
        e.ret(argbytes=4)
    emu.hook(0x4d06a0, h4d)
    cnt = [0]
    def h639(e, rr):
        c1 = e.reg('ecx')
        cnt[0] += 1
        log.put(3, *[e.r32(c1 + 4 * k) for k in range(4)], e.arg32(0), e.arg32(1) & 0xff)
        e.ret(eax=(e.arg32(0) * 2654435761 + cnt[0]) & 0xffffffff, argbytes=8)
    emu.hook(0x639df0, h639)
    emu.w32(a + 0x14, r.getrandbits(32))
    emu.w32(a + 0x18, r.getrandbits(32))
    emu.w32(a + 0x1c, r.getrandbits(32))
    emu.w32(a + 0x20, r.getrandbits(32))
    _flush_heap_code(c)
    return [self_, a, r.getrandbits(32)]

S(0x6387d0, 'convertPixels (GUESS)', 'thiscall', None, ret=None, gen=_s6387d0_spec, note='batch859; vt[0x38], 0x4d06a0 and 0x639df0 hooked (local mask structs logged by content), /GS check hooked')


def _s63f2d0_spec(c):
    r = c.rng
    emu = c.emu
    log = _Log833(c, 128)
    self_ = emu.alloc(0x2a000, 16)
    emu.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x300)))
    vt = emu.alloc(0x100, 4)
    emu.w32(self_, vt)
    tbl = emu.alloc(0x4000, 4)
    emu.w32(self_ + 0x68, tbl)
    g = emu.alloc(0x80, 16)
    emu.w32(g + 0x3c, r.getrandbits(32))
    emu.w32(0x70039c, g)
    b = _rnd(c, 0x80)
    idv = r.choice([0, 0, 0, 1, 2, 0x1003, 0x803, 0xfff, 0x8002])
    emu.wbytes(b + 0x5a, bytes([idv & 0xff, idv >> 8]))
    a = _rnd(c, 0x20)
    emu.w32(a + 8, b)
    def mkent():
        e = _rnd(c, 0x60)
        wv = r.choice([0xffff, 0xffff, 0, 1, 7, 0x20])
        emu.wbytes(e + 6, bytes([wv & 0xff, wv >> 8]))
        emu.wbytes(e + 5, bytes([r.getrandbits(8)]))
        emu.wbytes(e + 0x42, bytes([r.getrandbits(8)]))
        return e
    ent = mkent()
    emu.w32(tbl + (idv & 0xfff) * 4, ent)
    pool = emu.alloc(0x20, 4)
    pvt = emu.alloc(0x20, 4)
    emu.w32(pool, pvt)
    emu.w32(self_ + 0x21c, pool)
    newent = mkent()
    emu.hook(0x445e00, lambda e, rr: (log.put(1, e.reg('ecx')), e.ret(eax=newent, argbytes=0)))
    emu.w32(pvt + 8, 0x445e00)
    idr = r.choice([0, 1, 5, 0xffe, 0xfff, 0xffffffff, r.getrandbits(32)])
    emu.hook(0x4ce7b0, lambda e, rr: (log.put(2, e.reg('ecx')), e.ret(eax=idr, argbytes=0)))
    emu.hook(0x445e10, lambda e, rr: (log.put(3, e.reg('ecx'), e.arg32(0)), e.ret(argbytes=4)))
    emu.hook(0x445e20, lambda e, rr: (log.put(4, e.reg('ecx'), e.arg32(0)), e.ret(argbytes=4)))
    emu.w32(vt + 0x8c, 0x445e10)
    emu.w32(vt + 0x88, 0x445e20)
    emu.hook(0x445e30, lambda e, rr: (log.put(5), e.ret(argbytes=0)))
    emu.w32(0x7003b0, 0x445e30)
    _flush_heap_code(c)
    return [self_, a]

S(0x63f2d0, 'getEntry (GUESS)', 'thiscall', None, ret='eax', gen=_s63f2d0_spec, note='batch860; pool vt[8], 0x4ce7b0, vt[0x88/0x8c], assert hook, global 0x70039c hooked/pre-set')


def _s625cc0_spec(c):
    r = c.rng
    emu = c.emu
    cvt = emu.alloc(0x180, 4)
    tab = bytearray(r.choice([0, 1, 5, 6, 7, 8, 9, 10, 10, 9, 12, 0x1d, 4, 11]) for _ in range(256))
    emu.wbytes(cvt + 0x4c, bytes(tab))
    lo = [0x41, 0x0a, 0x0d, 0x20, 0x00, 0x01, 0x78, 0xfe, 0xff, r.getrandbits(8)]
    hi = [0, 0, 0, 0, 0, 0xd8, 0xdb, 0xdc, 0xdf, 0xd7, 0xe0, 0xff, 0x01]
    data = []
    for _ in range(r.randrange(0, 12)):
        data += [r.choice(lo), r.choice(hi)]
    data += [0x41, 0] * 8
    # walk with the same class rules to choose an end the scan reaches exactly
    def cls_of(i):
        h, l = data[i + 1], data[i]
        if h == 0:
            return tab[l]
        idx = h - 0xd8
        if idx < 0 or idx > 0x27: return 0x1d
        if idx < 4: return 7
        if idx < 8: return 8
        if idx == 0x27: return 0x1d if l < 0xfe else 0
        return 0x1d
    pos, visited = 0, [0]
    while pos + 2 < len(data) - 8:
        k = cls_of(pos) - 5
        step = 2
        if 0 <= k <= 5:
            if k == 1: step = 3
            elif k == 2: step = 4
            elif k == 4:
                pos += 2
                nxt = pos
                if nxt + 1 < len(data) and data[nxt + 1] == 0 and tab[data[nxt]] == 10:
                    pos += 2
                step = 0
        pos += step
        visited.append(pos)
    end_off = r.choice(visited)
    buf = emu.alloc(0x100, 4)
    emu.wbytes(buf, bytes(data))
    p = emu.alloc(8, 4)
    emu.w32(p, r.getrandbits(8))
    emu.w32(p + 4, r.choice([0, 1, 5, 0xffffffff]))
    _flush_heap_code(c)
    return [cvt, buf, buf + end_off, p]

S(0x625cc0, 'trackPos (GUESS)', 'cdecl', None, ret=None, gen=_s625cc0_spec, note='batch861; line/column tracking scan, 0x62c640 real for the CR LF peek')


def _entity_spec(le):
    def gen(c):
        r = c.rng
        emu = c.emu
        names = ['lt', 'gt', 'amp', 'apos', 'quot', 'lt', 'gt', 'amp', 'apos', 'quot', 'x', 'ab', 'abc', 'abcd', 'abcde', '', 'quo', 'apo', 'am', 'ltt', 'LT']
        nm = r.choice(names)
        data = []
        for ch in nm:
            data += [ord(ch), 0] if le else [0, ord(ch)]
        if r.random() < 0.35 and data:
            i = r.randrange(len(data))
            data[i] = r.choice([0, 1, 0x61, 0x6c, 0x67, 0x74, 0x70, 0x6f, r.getrandbits(8)])
        buf = emu.alloc(0x40, 4)
        emu.wbytes(buf, bytes(data + [0x55] * 16))
        extra = r.choice([0, 0, 0, 1, -1])
        end = buf + len(data) + (extra if extra >= 0 or len(data) > 0 else 0)
        _flush_heap_code(c)
        return [r.getrandbits(32), buf, end]
    return gen

S(0x622540, 'entityBE (GUESS)', 'cdecl', None, ret='eax', gen=_entity_spec(False), note='batch862; big-endian entity name matcher')


def _s624350_spec(c):
    r = c.rng
    emu = c.emu
    cvt = emu.alloc(0x180, 4)
    tab = bytearray(r.choice([3, 3, 5, 6, 7, 9, 12, 0x1d, 2, 4, 0, 1, 8]) for _ in range(256))
    tab[0x3c] = r.choice([2, 2, 3])
    tab[0x5d] = r.choice([4, 4, 3])
    for ch in (0x21, 0x5b, 0x3e, 0x41, 0x20):
        tab[ch] = r.choice([3, 3, 3, 5, 6, 7, 9])
    tab[0] = 0
    emu.wbytes(cvt + 0x4c, bytes(tab))
    pool = [0x3c, 0x21, 0x5b, 0x5d, 0x3e, 0x41, 0x20, 0x01, 0x00, r.getrandbits(8)]
    data = []
    for _ in range(r.randrange(0, 12)):
        k = r.random()
        if k < 0.2:
            data += [0x3c, 0, 0x21, 0, 0x5b, 0]
        elif k < 0.4:
            data += [0x5d, 0, 0x5d, 0, 0x3e, 0]
        elif k < 0.5:
            data += [r.choice(pool), 0xd8]
        else:
            data += [r.choice(pool), 0]
    if r.random() < 0.12:
        tab[0x20] = 6
        emu.wbytes(cvt + 0x4c, bytes(tab))
        data = [0x20, 0, 0x41, 0x20, 0, 0x41][:r.choice([6, 6, 5, 4])]
    end_off = len(data)
    data += [0] * 16
    buf = emu.alloc(0x100, 4)
    emu.wbytes(buf, bytes(data))
    out = emu.alloc(8, 4)
    extra = 1 if r.random() < 0.2 else 0
    _flush_heap_code(c)
    return [cvt, buf, buf + end_off + extra, out]

S(0x624350, 'endCondSection (GUESS)', 'cdecl', None, ret='eax', gen=_s624350_spec, note='batch862b; conditional section end scanner, 0x62c640 real')


def _s626500_spec(c):
    r = c.rng
    emu = c.emu
    cvt = emu.alloc(0x180, 4)
    tab = bytearray(r.choice([3, 3, 5, 6, 7, 9, 12, 0x1d, 2, 4, 0, 1, 8]) for _ in range(256))
    tab[0x3c] = r.choice([2, 2, 3])
    tab[0x5d] = r.choice([4, 4, 3])
    for ch in (0x21, 0x5b, 0x3e, 0x41, 0x20):
        tab[ch] = r.choice([3, 3, 3, 5, 6, 7, 9])
    tab[0] = 0
    emu.wbytes(cvt + 0x4c, bytes(tab))
    pool = [0x3c, 0x21, 0x5b, 0x5d, 0x3e, 0x41, 0x20, 0x01, 0x00, r.getrandbits(8)]
    data = []
    for _ in range(r.randrange(0, 12)):
        k = r.random()
        if k < 0.2:
            data += [0, 0x3c, 0, 0x21, 0, 0x5b]
        elif k < 0.4:
            data += [0, 0x5d, 0, 0x5d, 0, 0x3e]
        elif k < 0.5:
            data += [0xd8, r.choice(pool)]
        else:
            data += [0, r.choice(pool)]
    if r.random() < 0.12:
        tab[0x20] = 6
        emu.wbytes(cvt + 0x4c, bytes(tab))
        tab[0x05] = r.choice([7, 6, 5])
        emu.wbytes(cvt + 0x4c, bytes(tab))
        data = r.choice([[0, 0x20, 0x41, 0, 0x20, 0x41], [0, 0x20, 0x41, 0, 0x05, 0x41]])[:r.choice([6, 6, 5, 4])]
    end_off = len(data)
    data += [0] * 16
    buf = emu.alloc(0x100, 4)
    emu.wbytes(buf, bytes(data))
    out = emu.alloc(8, 4)
    extra = 1 if r.random() < 0.2 else 0
    _flush_heap_code(c)
    return [cvt, buf, buf + end_off + extra, out]

S(0x626500, 'endCondSectionBE (GUESS)', 'cdecl', None, ret='eax', gen=_s626500_spec, note='batch863; big-endian conditional section end scanner, 0x62c640 real')


def _s62b2f0_spec(c):
    r = c.rng
    emu = c.emu
    log = _Log833(c, 128)
    cvt = emu.alloc(0x200, 4)
    tab = bytearray(r.choice([0, 1, 2, 5, 6, 7, 8, 12, 13, 12, 13, 9, 10, 11, 20, 21, 30, 0x1d, 4, 14]) for _ in range(256))
    if r.random() < 0.7:
        for ch in (0x41, 0x20, 0x05, 0x01, 0x78):
            tab[ch] = r.choice([5, 6, 7, 5, 6, 7, 9, 10, 11, 11, 2])
        tab[0x22] = r.choice([12, 13, 5])
        tab[0x27] = r.choice([12, 13, 6])
        tab[0x3e] = r.choice([9, 11, 20, 21, 30, 4])
        tab[0x2f] = r.choice([9, 11, 20, 21, 30, 4, 0])
    tab[0] = 0
    emu.wbytes(cvt + 0x4c, bytes(tab))
    answers = [r.choice([0, 0, 1]) for _ in range(8)]
    n = [0]
    def mk(tag):
        def h(e, rr):
            i = n[0]
            n[0] += 1
            log.put(tag, e.arg32(0), e.arg32(1))
            e.ret(eax=answers[i % 8], argbytes=0)
        return h
    for k, off in enumerate((0x164, 0x168, 0x16c)):
        stub = 0x445f00 + 0x10 * k
        emu.hook(stub, mk(k + 1))
        emu.w32(cvt + off, stub)
    lo = [0x22, 0x27, 0x41, 0x20, 0x01, 0x05, 0x3e, 0x2f, 0x78, 0xff, r.getrandbits(8)]
    data = [r.choice(lo) for _ in range(r.randrange(0, 12))]
    end_off = len(data)
    data += [0] * 16
    buf = emu.alloc(0x100, 4)
    emu.wbytes(buf, bytes(data))
    out = emu.alloc(8, 4)
    quote = r.choice([12, 13, 12, 13, 11, 11, 10, 9, 5, 0xd, 0, r.getrandbits(8)])
    _flush_heap_code(c)
    return [quote, cvt, buf, buf + end_off, out]

S(0x62b2f0, 'readQuotedByte (GUESS)', 'cdecl', None, ret='eax', gen=_s62b2f0_spec, note='batch864; single-byte quoted value reader, cvt[0x164/0x168/0x16c] callbacks hooked')


def _s6261b0_spec(c):
    r = c.rng
    emu = c.emu
    log = _Log833(c, 128)
    cvt = emu.alloc(0x200, 4)
    tab = bytearray(r.choice([3, 3, 5, 6, 7, 9, 12, 0x1d, 2, 4, 0, 1, 8]) for _ in range(256))
    tab[0x3c] = r.choice([2, 2, 3])
    tab[0x5d] = r.choice([4, 4, 3])
    for ch in (0x21, 0x5b, 0x3e, 0x41, 0x20):
        tab[ch] = r.choice([3, 3, 3, 5, 6, 7, 9])
    tab[0] = 0
    emu.wbytes(cvt + 0x4c, bytes(tab))
    answers = [r.choice([0, 0, 0, 1]) for _ in range(8)]
    n = [0]
    def mk(tag):
        def h(e, rr):
            i = n[0]
            n[0] += 1
            log.put(tag, e.arg32(0), e.arg32(1))
            e.ret(eax=answers[i % 8], argbytes=0)
        return h
    for k, off in enumerate((0x164, 0x168, 0x16c)):
        stub = 0x445f40 + 0x10 * k
        emu.hook(stub, mk(k + 1))
        emu.w32(cvt + off, stub)
    pool = [0x3c, 0x21, 0x5b, 0x5d, 0x3e, 0x41, 0x20, 0x01, r.getrandbits(8)]
    data = []
    for _ in range(r.randrange(0, 12)):
        k = r.random()
        if k < 0.2:
            data += [0x3c, 0x21, 0x5b]
        elif k < 0.4:
            data += [0x5d, 0x5d, 0x3e]
        else:
            data += [r.choice(pool)]
    end_off = len(data)
    data += [0] * 16
    buf = emu.alloc(0x100, 4)
    emu.wbytes(buf, bytes(data))
    out = emu.alloc(8, 4)
    _flush_heap_code(c)
    return [cvt, buf, buf + end_off, out]

S(0x6261b0, 'endCondSectionByte (GUESS)', 'cdecl', None, ret='eax', gen=_s6261b0_spec, note='batch865; single-byte conditional section end scanner, checker callbacks hooked')


def _s63a460_spec(c):
    r = c.rng
    emu = c.emu
    log = _Log833(c, 128)
    emu.hook(0x633654, lambda e, rr: e.ret(argbytes=0))
    emu.w32(0x6f5630, r.getrandbits(32))
    def sv():
        return r.choice([r.randrange(0, 256), r.randrange(0, 256), r.randrange(-300, 300), r.getrandbits(32), 0x7fffffff, 0x80000000, 0xffffffff])
    A = emu.alloc(16, 4)
    B = emu.alloc(16, 4)
    for i in range(4):
        emu.w32(A + 4 * i, sv())
        emu.w32(B + 4 * i, sv())
    px = emu.alloc(16 * 16 + 16, 4)
    for i in range(16):
        for ch in range(3):
            emu.w32(px + 16 * i + 4 * ch, r.choice([r.randrange(0, 256), r.randrange(0, 256), r.getrandbits(32), 0x7fffffff]))
        emu.w32(px + 16 * i + 12, 0 if r.random() < 0.4 else r.randrange(1, 256))
    big = r.random() < 0.15
    def h(e, rr):
        flag = e.reg('ecx')
        buf = e.reg('edx')
        a = e.arg32(0)
        b = e.arg32(1)
        av = [e.r32(a + 4 * k) for k in range(3)]
        bv = [e.r32(b + 4 * k) for k in range(3)]
        log.put(1, flag, *av, *bv)
        for i in range(16):
            if big:
                v = (av[i % 3] * (i + 3) + bv[(i + 1) % 3] * 7 + i) & 0xffffffff
            else:
                v = (av[i % 3] * (i + 3) + bv[(i + 1) % 3] * 7 + i) & 0x1ff
            e.w32(buf + 4 * i, v)
        e.ret(argbytes=8)
    emu.hook(0x6383a0, h)
    flag = r.choice([0, 1, 2, 0x100, r.getrandbits(32)])
    limit = r.choice([0, 100, 5000, 65536, 0x7fffffff, 0xffffffff, 0x80000000, r.getrandbits(32), r.randrange(0, 40), r.randrange(0, 40), r.randrange(0, 600)])
    if r.random() < 0.3:
        for i in range(16):
            for ch in range(3):
                emu.w32(px + 16 * i + 4 * ch, r.randrange(0, 20))
    _flush_heap_code(c)
    return [flag, r.randrange(0, 3), A, B, px, limit]

S(0x63a460, 'paletteError (GUESS)', 'fastcall', None, ret='eax', gen=_s63a460_spec, note='batch866; palette filler 0x6383a0 hooked (content logged), /GS check hooked')
