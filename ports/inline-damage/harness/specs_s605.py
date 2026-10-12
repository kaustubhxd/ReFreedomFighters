"""specs_s605.py - damage batch 605: ZFFHERO::OnDamageInfo (PC 0x593220). Real: GetDamageMultForBone.
Patched to stubs: ZIKLNKOBJ::PlaySound 0x466f60, ZBaseGeom::GetOwnerRoom 0x4db3b0, AdjustHitPoints 0x58b9c0.
Type 2 (close combat) passes an uninitialised bone id in the original, so the bone-lookup stub does not record its
argument for type 2."""
import struct
from pilot import S
from wkit import rnd, stub, obj, fedge, b
from dkit import coll_stub, seq_rec_stub, patch_jmp


def _gen(c):
    r = c.rng
    emu = c.emu
    typ = r.choice((0, 0, 1, 2, 3, 4, 4, 5, 6))
    zone = r.choice((1, 1, 2, 2, 3, 0, 5, 6, 9))
    patch_jmp(c, 0x466f60, stub(c, 1))
    room = obj(c, 0x40, {0x94: stub(c, 2, skip=(0, 1))})
    patch_jmp(c, 0x4db3b0, stub(c, 0, ret=room if r.random() < 0.8 else 0))
    hpv = emu.alloc(4, 4)
    emu.wf32(hpv, r.choice((50.0, 0.0, -1.0, 99.0, float('nan'), r.uniform(-50, 200))))
    patch_jmp(c, 0x58b9c0, stub(c, 3, fld=hpv))
    emu.w32(0x7003b0, stub(c, 0, cdecl=True))
    emu.wf32(0x6ffa60, r.choice((0.0, 0.0, 1.0)))
    t_h = rnd(c, 8)
    t_a = rnd(c, 8)
    if r.random() < 0.3:
        emu.w32(t_a + 4, struct.unpack('<I', emu.rbytes(t_h + 4, 4))[0])
    ci = rnd(c, 0x40)
    emu.w32(ci + 0x23, r.choice((0x2003e8, 0x2007f9)))
    att = obj(c, 0x200, {0x1e0: stub(c, 1, ret=b(c, 0.3))})
    emu.w32(att + 0x54, t_a)
    emu.w32(att + 0xc, ci)
    mpos = emu.alloc(0x40, 4)
    for i in range(12):
        emu.wf32(mpos + 4 * i, r.uniform(-500, 500))
    hero = obj(c, 0x1000, {
        0x1e0: stub(c, 1, ret=b(c, 0.3)),
        0x2b4: stub(c, 1, skip=((0,) if typ == 2 else ()), ret=r.randrange(0, 40)),
        0x390: stub(c, 3, skip=(1, 2), ofills=[(1, 0, mpos, 9), (2, 0, mpos + 0x24, 3)]),
        0x98: stub(c, 2, skip=(0, 1), copy=(1, [(0, 'd'), (4, 'd'), (8, 'd')])),
        0x388: coll_stub(c, zone, r.getrandbits(1)),
        0x5d4: stub(c, 3, skip=(0,), copy=(0, [(0, 'b'), (1, 'b')]), ret=r.getrandbits(32)),
        0x4d8: stub(c, 1),
        0x21c: stub(c, 1, ret=r.choice((0, r.getrandbits(32)))),
        0x230: stub(c, 2),
        0x5bc: stub(c, 3),
    })
    emu.w32(hero + 0x54, t_h)
    emu.w32(hero + 8, rnd(c, 0x80))
    hci = rnd(c, 0x40)
    emu.w32(hci + 0x23, 0x2003e8)
    emu.w32(hero + 0xc, hci)
    for off in range(0x3ea, 0x412, 4):
        emu.wf32(hero + off, r.choice((1.0, 1.0, 5.0, fedge(c))))
    emu.w32(hero + 0x1e6, r.choice((0, r.getrandbits(32))))
    emu.w8(hero + 0x9f4, r.getrandbits(1))
    fxci = rnd(c, 0x40)
    emu.w32(fxci + 0x23, r.getrandbits(32) | (0x100000 if r.random() < 0.8 else 0))
    fx = obj(c, 0x200, {0x1bc: stub(c, 7, skip=(1, 2), copy=(2, [(0, 'd'), (4, 'd'), (8, 'd')]))})
    emu.w32(fx + 0xc, fxci)
    tmpl = rnd(c, 0x20)
    eng = obj(c, 0x1c00, {0x1c0: stub(c, 2, fldv=r.random())})
    emu.w32(eng + 0x40, r.choice((r.randrange(0, 1 << 20), 0)))
    emu.w32(hero + 0x694, (struct.unpack('<I', emu.rbytes(eng + 0x40, 4))[0] - r.choice((0, 0x200, 0x201, 5000))) & 0xffffffff)
    emu.w32(eng + 0x1b5d, r.choice((1, 0, 0)))
    k = r.random()
    first = 0 if k < 0.2 else (hero if k < 0.3 else att)
    rm = obj(c, 0x200, {0x58: seq_rec_stub(c, 1, [first, fx if r.random() < 0.9 else 0]),
                        0x160: stub(c, 1, ret=tmpl if r.random() < 0.9 else 0)})
    emu.w32(eng + 0x9b, rm)
    emu.w32(0x70039c, eng)
    info = rnd(c, 0x30)
    emu.w32(info + 4, r.choice((0, 1)))
    emu.w32(info + 8, typ)
    emu.w32(info + 0xc, r.choice((1, 0, 2)))
    for off in range(0x10, 0x28, 4):
        emu.wf32(info + off, r.uniform(-3000, 3000))
    emu.wf32(info + 0x28, r.choice((0.0, -0.0, 35.0, 100.0, r.uniform(0, 500), fedge(c))))
    return [hero, info]


S(0x593220, 'ZFFHERO::OnDamageInfo', 'thiscall', ret=None, gen=_gen)
