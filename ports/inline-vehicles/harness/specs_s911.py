"""specs_s911.py - vehicles batch 911: ZHeli::UpdatePos."""
from pilot import S
from vh import _rnd, _stub, obj, r32, rf

PT = [(0, 'd'), (4, 'd'), (8, 'd')]


def vec(c, lo, hi):
    v = c.emu.alloc(12, 4)
    for k in range(3):
        c.emu.w32(v + 4 * k, rf(c, lo, hi))
    return v


def g_up(c):
    s = _rnd(c, 0x200)
    c.emu.w32(s + 0x48, rf(c, 0, 0.1) if c.rng.random() > 0.05 else 0)
    p = _rnd(c, 0xb00)
    dbg = obj(c, 0x40, {0x218: _stub(c, 3, ret=r32(c)), 0x21c: _stub(c, 4)})
    c.emu.w32(p + 0xadc, dbg)
    c.emu.w32(s + 0x9b, p)
    c.emu.w32(0x70039c, s)
    c.emu.w32(0x7018d0, c.rng.choice([0, r32(c)]))
    off = vec(c, -0.2, 0.2)
    h = obj(c, 0x600, {0x88: _stub(c, 1, skip=(0,), copy=(0, PT), adds=((0, off, 3),)),
                       0x90: _stub(c, 1, skip=(0,), copy=(0, PT), adds=((0, off, 3),))})
    for o in list(range(0x216, 0x26e, 4)) + [0x60, 0x64, 0x68, 0x90, 0x94, 0x98, 0x3f1, 0x3f5, 0x3f9]:
        c.emu.w32(h + o, rf(c, -1, 1))
    for o in (0x60, 0x64, 0x68, 0x90, 0x94, 0x98, 0x24a, 0x24e, 0x252):
        c.emu.w32(h + o, rf(c, -500, 500))
    c.emu.w32(h + 0x597, rf(c, 0, 2000))
    c.emu.w32(h + 0x469, c.rng.choice([0, 1]))
    return [h]


S(0x51ddc0, 'ZHeli::UpdatePos', 'thiscall', gen=g_up)
