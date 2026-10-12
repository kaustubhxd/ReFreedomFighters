"""specs_s507.py - weapons batch 507: ZItemWeapon::FireRound. Vector/matrix helpers and GetMatPos/GetPos run as
exe code; every engine object is a recording stub; stack buffers passed to stubs are logged by content (lcopy)."""
from pilot import S
from wkit import rnd, stub, obj, b, fedge, vec, seq_stub


def _geomref(c):
    g = rnd(c, 0x200)
    for o in range(0, 0x200, 4):   # plausible floats so the matrix math stays finite most of the time
        c.emu.wf32(g + o, c.rng.uniform(-2, 2))
    h = rnd(c, 0x20)
    c.emu.w32(h + 8, g)
    return h


def _fr(c):
    r = c.rng
    c.emu.w8(0x6ff988, 0 if r.random() < 0.95 else 1)
    # engine object with the random-float slot, ticks, render manager and sound table
    rv = r.choice((0.0, 0.5, 0.999, r.random()))
    so = obj(c, 0x1b00, {0x1c0: stub(c, 2, fldv=rv)})
    c.emu.w32(so + 0x40, r.randint(0, 1 << 22))
    c.emu.w32(0x70039c, so)
    tab = obj(c, 0x40, {0x5c: stub(c, 1, ret=r.getrandbits(32)),
                        0x58: stub(c, 2, ret=0 if r.random() < 0.2 else r.getrandbits(32))})
    c.emu.w32(so + 0x1a9f, 0 if r.random() < 0.3 else tab)
    # emitter, flash, hand geom
    em = obj(c, 0x40, {0x218: stub(c, 4, skip=(1, 2), lcopy=((1, 3), (2, 3)))})
    fl = obj(c, 0x40, {0x7c: stub(c, 2, skip=(0, 1), lcopy=((0, 9), (1, 3))), 0x2c: stub(c, 0)})
    c.emu.w32(fl + 8, rnd(c, 0x40))
    hg = obj(c, 0x40, {0x128: stub(c, 3)})
    tw = obj(c, 0x200, {0x330: stub(c, 0, ret=r.choice((0, 2, 3, 4, 5, 0xb, 0xc, 1))),
                        0x350: stub(c, 0, fldv=fedge(c)), 0x344: stub(c, 0, fldv=r.uniform(0, 3000)),
                        0x34c: stub(c, 0, fldv=r.uniform(0, 5000))})
    has_muzzle = r.random() < 0.8
    for off, pr in ((0x11b, 1.0), (0x127, 0.7), (0x11f, 0.7), (0x123, 0.6)):
        c.emu.w32(tw + off, _geomref(c) if r.random() < pr else 0)
    if not has_muzzle:
        c.emu.w32(tw + 0x11b, 0)
    snd = rnd(c, 0x100)
    rm_vt = {0x58: seq_stub(c, 1, [em if has_muzzle and r.random() < 0.8 else 0,
                                   fl if r.random() < 0.7 else 0, hg if r.random() < 0.7 else 0]),
             0x4c: stub(c, 1, ret=r.getrandbits(32)),
             0x60: stub(c, 1, ret=snd if r.random() < 0.8 else 0)}
    rm = obj(c, 0x100, rm_vt)
    c.emu.w32(so + 0x9b, rm)
    # ammo template with its projectile pool
    insts = []
    for _ in range(4):
        insts.append(0 if r.random() < 0.15 else obj(c, 0x40, {
            0x74: stub(c, 2, skip=(0, 1), lcopy=((0, 9), (1, 3))),
            0x138: stub(c, 3, skip=(1,), lcopy=((1, 8), (1, 1, 0x1e)))}))
    ammo = obj(c, 0x40, {0x320: stub(c, 0, ret=r.choice((0, 1, 1, 2, 3))), 0x33c: seq_stub(c, 0, insts)})
    owner = 0 if r.random() < 0.15 else obj(c, 0x200, {0x1e0: stub(c, 1, ret=b(c, 0.3)), 0x128: stub(c, 3)})
    if owner and r.random() < 0.5:
        c.emu.w32(owner + 0x14b, 0)
    tgt = vec(c, 3, -100, 100)
    w = obj(c, 0x200, {0x328: stub(c, 0, ret=ammo),
                       0x2c4: stub(c, 2, skip=(0, 1), fills=((0, vec(c, 9, -1, 1), 9), (1, vec(c, 3, -100, 100), 3))),
                       0x350: stub(c, 0, ret=tw), 0x2f4: stub(c, 0, ret=owner), 0x334: stub(c, 0, ret=tgt),
                       0x304: stub(c, 1, ret=r.getrandbits(32))})
    kick = r.random()
    for j in range(3):
        c.emu.wf32(w + 0x109 + 4 * j, 0.0 if kick < 0.6 else (fedge(c) if r.random() < 0.7 else 0.0))
    for off in (0x8e, 0x9a, 0xe1, 0xe5, 0xe9):
        if r.random() < 0.25:
            c.emu.w32(w + off, 0)
    c.emu.w32(w + 0xba, r.choice((0, 1, 2, 30)))
    for j in range(3):
        c.emu.wf32(w + 0xf1 + 4 * j, r.uniform(-5, 5))
    c.emu.wf32(w + 0xcd, r.choice((0.5, 1.0, r.uniform(0.3, 1.7))))
    return [w]


S(0x46d8e0, 'ZItemWeapon::FireRound', 'thiscall', None, ret=None, gen=_fr, max_insns=2000000)
