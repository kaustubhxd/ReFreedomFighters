"""specs_s2760.py - unclaimed-27 batch 60: 0x4f2be0 (GUESS). thiscall, no stack args, plain ret (void).
Global 0x70039c -> fake object with +0x1907 = object O (80%) or 0; O's vtable slot +0x14 is a HOOK (stub, NOT verified) that
records ecx and its one stack argument (callee pops 4) and counts calls."""
from pilot import S
import struct


def _gen(c):
    p = lambda v: struct.pack('<I', v)
    rec = c.emu.alloc(0x10, 4)
    code = (b'\x89\x0d' + p(rec) + b'\x8b\x44\x24\x04\xa3' + p(rec + 4) + b'\xff\x05' + p(rec + 8) + b'\xc2\x04\x00')
    st = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(st, code)
    vt = c.emu.alloc(0x100, 4)
    c.emu.wbytes(vt, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    c.emu.w32(vt + 0x14, st)
    o = c.emu.alloc(0x40, 4)
    c.emu.w32(o, vt)
    g = c.emu.alloc(0x1a00, 4)
    c.emu.wbytes(g, bytes(c.rng.getrandbits(8) for _ in range(0x1a00)))
    c.emu.w32(g + 0x1907, o if c.rng.getrandbits(32) % 5 else 0)
    c.emu.w32(0x70039c, g)
    obj = c.emu.alloc(0x700, 4)
    c.emu.wbytes(obj, bytes(c.rng.getrandbits(8) for _ in range(0x700)))
    if c.rng.getrandbits(32) % 6:
        c.emu.wbytes(obj + 0x5fd, bytes([c.rng.randint(1, 255), c.rng.randint(1, 255)]))
    r = c.rng.getrandbits(32) % 10
    if r < 8:
        c.emu.wbytes(obj + 0x5ff, p(r))        # 0 and 6, 7 are out of range; 1..5 hit the five cases
    c.emu.mu.ctl_flush_tb()
    return [obj]


S(0x4f2be0, 'FUN_4f2be0 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-27 batch 60; global 0x70039c object and vtable slot +0x14 are hooks (stub)')
