"""specs_s613.py - damage batch 613: ZKillBox::Kill (PC 0x5b1ce0). Patched to stubs: ZBaseGeom::GetCen 0x4daf90 and
ZCamHelper::MoveBackward 0x5d0ba0. The object list iterator is a heap stub (dkit.iter_stub)."""
import struct
from pilot import S
from wkit import rnd, stub, obj, b
from dkit import seq_rec_stub, patch_jmp, iter_stub


def _gen(c):
    r = c.rng
    emu = c.emu
    cen = emu.alloc(16, 4)
    for i in range(3):
        emu.wf32(cen + 4 * i, r.uniform(-100, 100))
    patch_jmp(c, 0x4daf90, stub(c, 1, skip=(0,), ofills=[(0, 0, cen, 3)]))
    patch_jmp(c, 0x5d0ba0, stub(c, 1))
    n = r.randrange(0, 5)
    actors = []
    for _ in range(n):
        a = obj(c, 0x900, {0x84: stub(c, 1, skip=(0,)), 0x1e0: stub(c, 1, ret=b(c, 0.4)), 0x6e0: stub(c, 0),
                           0x438: stub(c, 0, ret=b(c, 0.5)), 0x28: stub(c, 0), 0x128: stub(c, 3, skip=(1,))})
        emu.w32(a + 0x54, r.choice((0, 1, r.getrandbits(32))))
        emu.w32(a + 8, rnd(c, 0x40))
        actors.append(a)
    box = obj(c, 0x40, {0x8c: stub(c, 1, skip=(0,)), 0x180: stub(c, 2, skip=(0,), ret=b(c, 0.4))})
    cam = rnd(c, 0x20)
    hero = obj(c, 0x900, {0x84: stub(c, 1, skip=(0,)), 0x128: stub(c, 3, skip=(1,)), 0x100: stub(c, 1, ret=cam)})
    emu.w32(hero + 8, rnd(c, 0x40))
    emu.w32(hero + 0x85a, r.choice((0, cam)))
    handles = [r.getrandbits(32) for _ in actors]
    lst = obj(c, 0x80, {0x4c: stub(c, 1, skip=(0,)), 0x5c: iter_stub(c, handles)})
    holder = rnd(c, 0x40)
    emu.w32(holder + 0x18, lst if r.random() < 0.9 else 0)
    kb = rnd(c, 0x100)
    emu.w32(kb + 0x4a, holder)
    emu.w32(kb + 0x83, hero)
    emu.w8(kb + 0x87, r.choice((0, 0, 1)))
    emu.w8(kb + 0x8c, r.getrandbits(1))
    rm = obj(c, 0x200, {0x58: seq_rec_stub(c, 1, [box] + actors + [box]), 0x114: stub(c, 4, ret=r.getrandbits(16))})
    eng = rnd(c, 0x200)
    emu.w32(eng + 0x9b, rm)
    emu.w32(0x70039c, eng)
    return [kb]


S(0x5b1ce0, 'ZKillBox::Kill', 'thiscall', ret=None, gen=_gen)
