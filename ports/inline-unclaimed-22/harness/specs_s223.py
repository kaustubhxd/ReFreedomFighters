"""specs_s223.py - unclaimed area 22, batch223 (src/batch223.cpp): 0x524410, 0x4e3190, 0x43ee10.

0x4e3330 (xor eax, eax; ret 0x10) is stubbed with a recorder of its ecx and four stack words. The vtable callees are logged sparse slots
(helpers22._multi_vt). 0x524410's slot returns a different value on each call (a per-run sequence).
"""
from pilot import S
import serial_stubs as ss
from helpers22 import _rnd, _multi_vt, _ret_const, _flush_heap_code, jmp_patch


def _seq_fn(vals):
    it = iter(vals)
    return lambda em, args: (next(it), None)


def _g_524410(c):
    self_ = _rnd(c, 0x40)
    a = _rnd(c, 0x40)
    vals = [c.rng.getrandbits(32) for _ in range(5)]
    c.emu.w32(a, _multi_vt(c, {0x50: (_seq_fn(vals), 1)}))
    return [self_, a]


def _g_4e3190(c):
    n = c.rng.choice([-2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, c.rng.randrange(0, 12)])
    base = c.emu.alloc(0x200, 16)
    c.emu.wbytes(base, bytes(c.rng.getrandbits(8) for _ in range(0x200)))
    arr = base + 0x80
    for i in range(0, 12):
        c.emu.wf32(arr + 9 * i, c.rng.uniform(-50.0, 50.0))
    key = _rnd(c, 9)
    # sometimes the key equals a record's key (the comparison must treat equal keys as stop)
    c.emu.wf32(key, c.emu.rf32(arr + 9 * c.rng.randrange(0, 12)) if c.rng.random() < 0.3 else c.rng.uniform(-50.0, 50.0))
    return [arr, n & 0xffffffff, key]


def _g_43ee10(c):
    rm = _rnd(c, 0x100)
    obj = _rnd(c, 0xb00)
    v58 = c.rng.choice([0, c.rng.getrandbits(32)])
    buf = _rnd(c, 0x40)
    o2 = _rnd(c, 0x40)
    c.emu.w32(obj + 0xadc, o2)
    c.emu.w32(o2, _multi_vt(c, {0x294: (lambda em, args, b=buf: (b, None), 4)}))
    c.emu.w32(obj, _multi_vt(c, {0x58: (lambda em, args, v=v58: (v, None), 1),
                                 0x4c: (lambda em, args: (c.rng.getrandbits(32), None), 1)}))
    c.emu.w32(rm + 0x9b, obj)
    c.emu.w32(0x70039c, rm)
    c.emu.mu.ctl_flush_tb()
    # 0x4e3330 stand-in (same ret 0x10, returns 0): stores ecx and its four stack words, so the argument order is compared
    slots = [c.emu.alloc(4, 4) for _ in range(5)]
    for sl in slots:
        c.emu.w32(sl, 0)
    code = b'\x89\x0d' + ss.P(slots[0])
    for i in range(4):
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i]) + b'\xa3' + ss.P(slots[1 + i])
    code += b'\x31\xc0\xc2\x10\x00'
    jmp_patch(c, 0x4e3330, ss.code(c, code))
    _flush_heap_code(c)
    return [c.rng.getrandbits(32) for _ in range(4)]


S(0x524410, 'slot50Five (GUESS)', 'thiscall', None, ret='eax', gen=_g_524410,
  note='batch223; five vtable 0x50 calls on the argument, returns (last & ~0xff) | 1')
S(0x4e3190, 'binInsert9 (GUESS)', 'fastcall', None, ret=None, gen=_g_4e3190,
  note='batch223; binary-search insert of a 9-byte record')
S(0x43ee10, 'vtGetFill (GUESS)', 'stdcall', None, ret='eax', gen=_g_43ee10,
  note='batch223; global 0x70039c, vtable 0x58, then 0x294 and 0x4c on the null path; calls 0x4e3330')
