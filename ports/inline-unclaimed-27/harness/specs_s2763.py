"""specs_s2763.py - unclaimed-27 batch 63: 0x5bc4e0 (GUESS). thiscall, one stack arg (flags), ret 4, returns this (EAX).
HOOKED (NOT verified): vtable slot +0x34 of the object at [[0x70039c]+0x9b] (stub that records ecx and its arg, ret 4);
0x4690b0 (cdecl, Python hook that records both args); the function pointer at 0x7003b0 (stub that counts calls, always non-null,
because a null pointer makes the exe run int3). Flags are random, so all three exits are covered."""
from pilot import S
import struct


def _gen(c):
    p = lambda v: struct.pack('<I', v)
    rec = c.emu.alloc(0x30, 4)
    code = b'\x89\x0d' + p(rec) + b'\x8b\x44\x24\x04\xa3' + p(rec + 4) + b'\xc2\x04\x00'
    st = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(st, code)
    vt = c.emu.alloc(0x100, 4)
    c.emu.wbytes(vt, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    c.emu.w32(vt + 0x34, st)
    o = c.emu.alloc(0x40, 4)
    c.emu.w32(o, vt)
    g = c.emu.alloc(0x100, 4)
    c.emu.wbytes(g, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    c.emu.wbytes(g + 0x9b, p(o))
    c.emu.w32(0x70039c, g)
    hk = b'\xff\x05' + p(rec + 8) + b'\xc3'
    hs = c.emu.alloc(len(hk) + 16, 16)
    c.emu.wbytes(hs, hk)
    c.emu.w32(0x7003b0, hs)

    def h469(e, r):
        e.w32(rec + 0xc, (e.r32(rec + 0xc) + 1) & 0xffffffff)
        e.w32(rec + 0x10, e.arg32(0)); e.w32(rec + 0x14, e.arg32(1))
        e.ret(eax=c.rng.getrandbits(32), argbytes=0)

    c.emu.hook(0x4690b0, h469)
    obj = c.emu.alloc(0x80, 4)
    c.emu.wbytes(obj, bytes(c.rng.getrandbits(8) for _ in range(0x80)))
    c.emu.mu.ctl_flush_tb()
    return [obj, c.rng.getrandbits(32)]


S(0x5bc4e0, 'FUN_5bc4e0 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-27 batch 63; vslot +0x34, 0x4690b0 and the pointer at 0x7003b0 are hooks; SEH frame not reproduced')
