"""specs_s222.py - unclaimed area 22, batch222 (src/batch222.cpp): 0x45ee90, 0x4d3dd0, 0x440e90.

0x4d2700 is stubbed with a 5-word recorder (ret 0x14): it stores ecx, the four stack words and the dword behind the
pointer argument (the byte flag the caller wrote). The pointer itself is not logged (it is a stack address).
0x4de520 runs as the real exe code on both sides. 0x65f530 (the no-op) is stubbed with a six-word recorder, so a
skipped or reordered call is visible.
"""
from pilot import S, F
import serial_stubs as ss
from helpers22 import _rnd, _flush_heap_code, _sparse_vt, _ret_const, jmp_patch


def _g_45ee90(c):
    a = _rnd(c, 0x100)
    b = _rnd(c, 0x40)
    d = F(c.rng.uniform(-50.0, 50.0))
    # the third argument is a pointer to a 0x40-byte record (0x4de520 reads it on two of its three paths)
    return [a, b, _rnd(c, 0x40), d]


def _g_4d3dd0(c):
    slots = {k: c.emu.alloc(4, 4) for k in ('ecx', 'a', 'one', 'c', 'v', 'zero')}
    for s in slots.values():
        c.emu.w32(s, 0)
    code = (b'\x89\x0d' + ss.P(slots['ecx'])
            + b'\x8b\x44\x24\x04\xa3' + ss.P(slots['a'])
            + b'\x8b\x44\x24\x08\xa3' + ss.P(slots['one'])
            + b'\x8b\x44\x24\x0c\xa3' + ss.P(slots['c'])
            + b'\x8b\x44\x24\x10\x8b\x00\xa3' + ss.P(slots['v'])
            + b'\x8b\x44\x24\x14\xa3' + ss.P(slots['zero'])
            + b'\xb8\x00\x00\x00\x00' + b'\xc2\x14\x00')
    ss.patch(c, 0x4d2700, ss.code(c, code))
    _flush_heap_code(c)
    self_ = _rnd(c, 0x40)
    return [self_, c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _g_440e90(c):
    rm = _rnd(c, 0x100)
    obj = _rnd(c, 0x40)
    r = c.rng.choice([0, 0, c.rng.getrandbits(32), 0xffffff00 | c.rng.getrandbits(8), 0x100])
    c.emu.w32(obj, _sparse_vt(c, 0x58, _ret_const(c) if r == 0 else (lambda em, args, v=r: (v, None)), 1))
    c.emu.w32(obj + 0x14, c.rng.getrandbits(32))
    c.emu.w32(rm + 0x9b, obj)
    c.emu.w32(0x70039c, rm)
    c.emu.mu.ctl_flush_tb()
    # 0x65f530 stand-in (same ret 0x18): stores its six stack words, so a skipped or reordered call shows in the memory compare
    # eax is saved and restored: the real no-op leaves eax alone, and the caller's result is eax
    code = b'\x50'
    for i in range(6):
        slot = c.emu.alloc(4, 4)
        c.emu.w32(slot, 0)
        code += b'\x8b\x44\x24' + bytes([8 + 4 * i]) + b'\xa3' + ss.P(slot)
    jmp_patch(c, 0x65f530, ss.code(c, code + b'\x58\xc2\x18\x00'))
    _flush_heap_code(c)
    return [c.rng.getrandbits(32) for _ in range(6)]


S(0x45ee90, 'forwardFloat (GUESS)', 'stdcall', None, ret='eax', gen=_g_45ee90,
  note='batch222; forwards a, b, c and a float to 0x4de520 (fastcall)')
S(0x4d3dd0, 'flagCall (GUESS)', 'thiscall', None, ret=None, gen=_g_4d3dd0,
  note='batch222; byte flag by pointer to 0x4d2700 (stubbed, five words)')
S(0x440e90, 'vtCheckNoop (GUESS)', 'stdcall', None, ret='eax', gen=_g_440e90,
  note='batch222; global 0x70039c, vtable 0x58, then 0x65f530 when nonzero')
