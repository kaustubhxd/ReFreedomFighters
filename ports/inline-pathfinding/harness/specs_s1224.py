"""specs_s1224.py - pathfinding batch 1224: ZPathfinder3 constructor (0x52a370).

Real exe code: ZSTDOBJ base constructor, the time-slice, CContext and CFindPathContext constructors, the allocator. Stubbed
the same way in both builds: the engine object at 0x70039c (clock 0x1c8, message table at +0x9b), the message table
(RegisterZMsg 0x114, scene 0x138, 0x4c), and the scene object (0x4c).
"""
from pilot import S
from pfspec import rnd, reporter, allocator, vtable, RET


def _zpf(c):
    r = c.rng
    e = c.emu
    reporter(c, 0.0)
    allocator(c)
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, rr: em.ret()))
    # engine object: clock and message table
    now = [r.randint(0, 5000)]
    def clock(em, args):
        now[0] += r.choice([1, 7, 50])
        return now[0]
    ids = [r.randrange(1, 300)]
    def reg(em, args):
        ids[0] += 1
        return ids[0]
    scene_ref = r.getrandbits(32)
    scene = e.alloc(16, 4)
    e.w32(scene, vtable(c, 'scene', 0x60, impl={0x4c: lambda em, args: 0}, argwords={0x4c: 2}))
    msgs = e.alloc(0x2000, 4)
    e.wbytes(msgs, bytes(0x2000))           # the ZSTDOBJ path reads a field at +0x1c5d
    e.w32(msgs, vtable(c, 'msgs', 0x140, impl={0x114: reg, 0x130: lambda em, args: 0,
                                                 0x138: lambda em, args: scene,
                                                 0x4c: lambda em, args: scene_ref},
                       argwords={0x114: 4, 0x130: 1, 0x138: 0, 0x4c: 1}))
    rm = e.alloc(0x200, 4)
    e.w32(rm + 0x9b, msgs)
    e.w32(rm, vtable(c, 'sysi', 0x1d0, impl={0x1c8: clock}, argwords={0x1c8: 2}))
    e.w32(0x70039c, rm)
    cls = e.alloc(0x100, 4)
    e.wbytes(cls, bytes(0x100))
    name = e.cstr('ZPathfinder3')
    geom = e.alloc(0x100, 4)
    e.wbytes(geom, bytes(0x100))
    self_ = e.alloc(0x1000, 4)
    e.wbytes(self_, bytes(0x1000))
    return [self_, cls, name, geom]


S(0x52a370, 'ZPathfinder3::ZPathfinder3', 'thiscall', None, gen=_zpf, n=100)
