"""specs_s607.py - damage batch 607: ZFFHERO::PerformDie (PC 0x593cc0). ZIKLNKOBJ::PlaySound 0x466f60 patched to a stub;
the global item list at [0x7003b8] is a heap object."""
import struct
from pilot import S
from wkit import rnd, stub, obj
from dkit import patch_jmp


def _gen(c):
    r = c.rng
    emu = c.emu
    patch_jmp(c, 0x466f60, stub(c, 1))
    o2 = obj(c, 0x10, {0x2c: stub(c, 2, cdecl=True)})
    emu.w32(0x700390, obj(c, 0x10, {0x20: stub(c, 2, ret=o2)}))
    item = r.choice((0, r.getrandbits(32), r.getrandbits(32)))
    holder = obj(c, 0x20, {0x10: stub(c, 0, ret=item)})
    hero = obj(c, 0x1000, {0x12c: stub(c, 3), 0x130: stub(c, 3), 0x584: stub(c, 0), 0x4f8: stub(c, 0, ret=holder),
                           0x520: stub(c, 1), 0x4f4: stub(c, 1), 0x518: stub(c, 1), 0x51c: stub(c, 1)})
    emu.w32(hero + 0x846, r.choice((0, r.getrandbits(32))))
    emu.w8(hero + 0x9e7, r.getrandbits(1))
    g = rnd(c, 0x900 + 0x40)
    n = r.randrange(0, 8)
    emu.w32(g + 0x8b4, n)
    for i in range(n):
        emu.w32(g + 0x8b8 + 4 * i, item if r.random() < 0.2 else r.getrandbits(32))
    emu.w32(0x7003b8, g)
    ctrl = emu.alloc(4, 4)
    emu.w32(ctrl, r.getrandbits(32))
    scene = obj(c, 0x20, {0x88: stub(c, 2, skip=(1,), ofills=[(1, 0, ctrl, 1)])})
    rm = obj(c, 0x200, {0x138: stub(c, 0, ret=scene), 0x114: stub(c, 4, ret=r.getrandbits(32))})
    eng = rnd(c, 0x200)
    emu.w32(eng + 0x9b, rm)
    emu.w32(eng + 0x40, r.getrandbits(31))
    emu.w32(0x70039c, eng)
    return [hero]


S(0x593cc0, 'ZFFHERO::PerformDie', 'thiscall', ret=None, gen=_gen)
