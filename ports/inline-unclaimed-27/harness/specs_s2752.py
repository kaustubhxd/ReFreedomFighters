"""specs_s2752.py - unclaimed-27 batch 52: 0x4f3fe0 (GUESS). thiscall, two stack args, ret 8, returns bool (AL).
HOOKED (stub, NOT verified): vtable slot +0xbc (thiscall, one arg, callee pops 4); it records ecx and the arg and returns a random eax."""
from pilot import S
import struct


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    p = lambda v: struct.pack('<I', v)
    rec = c.emu.alloc(0x10, 4)
    code = (b'\x89\x0d' + p(rec) + b'\x8b\x44\x24\x04\xa3' + p(rec + 4) + b'\xb8' + p(c.rng.getrandbits(32) | 0x01010101) +
            b'\xc2\x04\x00')
    st = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(st, code)
    vt = _rnd(c, 0x200)
    c.emu.w32(vt + 0xbc, st)
    obj = _rnd(c, 0x40)
    c.emu.w32(obj, vt)
    c.emu.mu.ctl_flush_tb()
    return [obj, c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x4f3fe0, 'FUN_4f3fe0 (GUESS) thiscall', 'thiscall', None, ret='al', gen=_gen,
  note='unclaimed-27 batch 52; vtable slot +0xbc is a hook (stub); returns bool in AL')
