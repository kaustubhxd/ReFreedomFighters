"""specs_s508.py - weapons batch 508: ZItemWeapon::ClassFrameUpdate (per-frame fire loop)."""
from pilot import S
from wkit import rnd, stub, obj, b, fedge, sysobj


def _cfu(c):
    r = c.rng
    g = obj(c, 0x40, {0x28: stub(c, 0)})
    c.emu.w32(g + 8, rnd(c, 0x40))
    rm = sysobj(c, {0x58: stub(c, 1, ret=g if r.random() < 0.8 else 0)})
    so = c.emu.r32(0x70039c)
    now = r.randint(0, 1 << 20)
    c.emu.w32(so + 0x40, now)
    c.emu.w32(so + 0x44, now - r.randint(0, 40))
    c.emu.w32(so + 0x3c, r.choice((5, 6)))
    c.emu.w32(0x6ff98c, r.choice((5, 7)))
    c.emu.w32(0x6ff990, r.choice((0, 2, 3, 4)))
    c.emu.w32(0x6ff998, r.getrandbits(32))
    tbs = r.choice((0.0, 0.1, 0.25, 1.0, r.uniform(0, 1)))
    t = obj(c, 0x40, {0x338: stub(c, 0, fldv=tbs)})
    own = 0 if r.random() < 0.2 else obj(c, 0x40, {0x1e0: stub(c, 1, ret=b(c, 0.5))})
    w = obj(c, 0x200, {0x2f4: stub(c, 0, ret=own), 0x350: stub(c, 0, ret=t), 0x370: stub(c, 0),
                       0x390: stub(c, 0), 0x114: stub(c, 1)})
    c.emu.w32(w + 0xc4, r.choice((0, 0, 1, 3, 30)))
    c.emu.w8(w + 0xbf, 0 if r.random() < 0.3 else r.randint(1, 255))
    c.emu.w32(w + 0xba, r.choice((0, 1, 5)))
    c.emu.w32(w + 0xd5, r.choice((0, 1, 2, 3)))
    x = r.random()
    if x < 0.4:   # last shot exactly tbs before now (boundary) or around it
        c.emu.wf32(w + 0xd1, (now + r.randint(-1, 1)) / 1024.0 - tbs)
    elif x < 0.8:
        c.emu.wf32(w + 0xd1, (now - r.randint(-50, 400)) / 1024.0)
    else:
        c.emu.wf32(w + 0xd1, fedge(c))
    return [w]


S(0x46bae0, 'ZItemWeapon::ClassFrameUpdate', 'thiscall', None, ret=None, gen=_cfu)
