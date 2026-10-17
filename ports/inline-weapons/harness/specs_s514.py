"""specs_s514.py - weapons batch 514: ZItemWeapon::SetState."""
from pilot import S
from wkit import rnd, stub, obj, b, sysobj, patch_jmp


def _ss(c):
    r = c.rng
    patch_jmp(c, 0x4711f0, stub(c, 2, rec_ecx=True, ret=r.getrandbits(32)))
    c.emu.w32(0x7003b0, stub(c, 0))
    g = obj(c, 0x40, {0x28: stub(c, 0)})
    sysobj(c, {0x58: stub(c, 1, ret=g if r.random() < 0.7 else 0)})
    t = obj(c, 0x40, {0x32c: stub(c, 0, ret=b(c, 0.5))})
    w = obj(c, 0x200, {0x36c: stub(c, 0, ret=b(c, 0.4)), 0x350: stub(c, 0, ret=t),
                       0x388: stub(c, 0), 0x38c: stub(c, 0), 0x378: stub(c, 0), 0x37c: stub(c, 0),
                       0x380: stub(c, 0), 0x384: stub(c, 0), 0x28: stub(c, 0), 0x2c: stub(c, 0)})
    gf = rnd(c, 0x40)
    c.emu.w32(w + 8, gf)
    s = r.choice((0, 1, 2, 3, 4, 5, 6, 7, 0xffffffff))
    c.emu.w32(w + 0x5c, s if r.random() < 0.15 else r.choice((0, 3, 5, 6)))
    for off in (0xc8, 0xc9, 0xca, 0xcb):
        c.emu.w8(w + off, 0 if r.random() < 0.5 else r.randint(1, 255))
    return [w, s, r.getrandbits(32)]


S(0x471300, 'ZItemWeapon::SetState', 'thiscall', None, ret='al', gen=_ss)
