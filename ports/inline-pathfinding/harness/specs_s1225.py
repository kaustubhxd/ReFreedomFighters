"""specs_s1225.py - pathfinding batch 1225: ZPathfinder3::ClassFrameUpdate (0x52ab00) and ZPFOctree_packed ctor (0x52cfd0).

ClassFrameUpdate: the engine object at 0x70039c (clock 0x1c8 returns 64 bits: eax low, edx high = 0; profiler slots 0x178
and 0x17c logged), the frame-time floats +0x9c3 / +0x9c7, and ProcessQueue (0x52c000, verified in batch 1217) stubbed
the same way in both builds (returns, flag argument logged through a stub).
"""
import struct
from unicorn.x86_const import UC_X86_REG_EDX
from pilot import S
from pfspec import rnd, reporter, vtable
import pilot

P = lambda v: struct.pack('<I', v & 0xffffffff)


def code(c, b):
    a = c.emu.alloc(len(b) + 16, 16)
    c.emu.wbytes(a, b)
    return a


def _cfu(c):
    r = c.rng
    e = c.emu
    reporter(c, 0.0)
    now = [r.randint(1, 1 << 20)]

    def clock(em, args):
        now[0] += r.choice([1, 9, 64])
        em.mu.reg_write(UC_X86_REG_EDX, 0)          # 64-bit result: high word zero
        return now[0]

    eng = e.alloc(0xa00, 4)
    e.wbytes(eng, bytes(0xa00))
    e.w32(eng, vtable(c, 'engine', 0x200, impl={0x1c8: clock, 0x178: lambda em, a: 0, 0x17c: lambda em, a: 0},
                      argwords={0x1c8: 2, 0x178: 3, 0x17c: 3}))
    k = r.random()
    if k < 0.3:
        e.wf32(eng + 0x9c3, 0.0)
        e.wf32(eng + 0x9c7, 0.0)
    elif k < 0.6:
        e.wf32(eng + 0x9c3, 1.5)
        e.wf32(eng + 0x9c7, 0.25)
    elif k < 0.8:
        e.wf32(eng + 0x9c3, 0.5)
        e.wf32(eng + 0x9c7, 0.0)
    else:
        e.wf32(eng + 0x9c3, 0.0)
        e.wf32(eng + 0x9c7, 2.0)
    e.w32(0x70039c, eng)
    e.wbytes(0x52c000, b'\xb8' + P(code(c, b'\x31\xc0\xc2\x04\x00')) + b'\xff\xe0')   # ProcessQueue: stub, ret 4
    e.c = None
    self_ = e.alloc(0x100, 4)
    e.wbytes(self_, bytes(0x100))
    return [self_]


S(0x52ab00, 'ZPathfinder3::ClassFrameUpdate', 'thiscall', None, gen=_cfu, n=200)


def _oct(c):
    r = c.rng
    e = c.emu
    o = e.alloc(0xd20, 4)
    e.wbytes(o, bytes(r.getrandbits(8) for _ in range(0xd20)))
    return [o]


S(0x52cfd0, 'ZPFOctree_packed::ZPFOctree_packed', 'thiscall', None, ret='eax', gen=_oct, n=200)
