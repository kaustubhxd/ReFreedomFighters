"""specs_s1105.py - unclaimed-11 batch 5 (docs/20-unclaimed-11.md): ZCollisionBase::FreeSceneMemory at 0x4ecaa0, thiscall,
no arguments. Two objects at +0x19d and +0x1a1 are released through their vtable slot 0x28 (scalar deleting dtor, stubbed:
each stub writes its this into its own heap ring and returns), and the block at +0x1a5 is freed with a cdecl free(ptr, 0x14)
(0x634273, stubbed: writes ptr to a heap ring). Each pointer field is null in about a quarter of the cases. The stubs are
unverified callees (no GC names), so they are stubs and not exe code. Fields are cleared to 0 after each release."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S


def _ring(c, n=4):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(n))
    return a


def _del_stub(c, ring):
    # thiscall, one argument (the flag): stores ecx (this) into ring, returns 0.
    b = b'\xb8' + ss.P(ring) + b'\x89\x08' + b'\x31\xc0' + b'\xc2\x04\x00'
    return ss.code(c, b)


def _free_stub(c, ring):
    # cdecl free(ptr, size): stores the first argument into ring, returns (caller cleans).
    b = b'\xb8' + ss.P(ring) + b'\x8b\x4c\x24\x04' + b'\x89\x08' + b'\xc3'
    return ss.code(c, b)


def _fsm(c):
    o = c.emu.alloc(0x400, 4)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x400)))
    ra, rb, rf = _ring(c), _ring(c), _ring(c)
    sa = _del_stub(c, ra)
    sb = _del_stub(c, rb)
    objs = []
    for field, stub in ((0x19d, sa), (0x1a1, sb)):
        if c.rng.random() < 0.25:
            c.emu.w32(o + field, 0)
        else:
            ob = ss.mkobj(c, {0x28: stub}, size=0x40)
            c.emu.w32(o + field, ob)
    if c.rng.random() < 0.25:
        c.emu.w32(o + 0x1a5, 0)
    else:
        c.emu.w32(o + 0x1a5, c.emu.alloc(0x20, 4))
    ss.patch(c, 0x634273, _free_stub(c, rf))
    return [o]


S(0x4ecaa0, 'ZCollisionBase::FreeSceneMemory (unknown) thiscall', 'thiscall', None, ret=None, gen=_fsm,
  note='unclaimed-11 batch 5; vtable slot 0x28 and free 0x634273 stubbed')
