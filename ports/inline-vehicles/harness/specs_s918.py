"""specs_s918.py - vehicles batch 918: ZTank::UpdateSound."""
from pilot import S
from vh import _rnd, _stub, obj, r32, rf, idstub, fconst


def g(c):
    s = _rnd(c, 0x1b00)
    node = _rnd(c, 0x90)
    c.emu.w32(s + 0x9b, obj(c, 0x40, {0x60: idstub(c, [c.rng.choice([0, node]), node, 0, node])}))
    c.emu.w32(s + 0x1a9f, c.rng.choice([0, obj(c, 0x10, {0x60: _stub(c, 2, ret=r32(c))})]) if c.rng.random() < 0.1
              else obj(c, 0x10, {0x60: _stub(c, 2, ret=r32(c))}))
    c.emu.w32(s, c.emu.r32(obj(c, 4, {0x1c0: _stub(c, 2, fld=fconst(c, c.rng.random()))})))
    c.emu.w32(0x70039c, s)
    t = obj(c, 0x2800, {0x2e8: _stub(c, 1, ret=c.rng.choice([0, 1, 2, 3])), 0x2ec: _stub(c, 1)})
    p = _rnd(c, 0x40)
    c.emu.w32(p + 0x24, rf(c, 0, 100))
    c.emu.w32(p + 0x28, rf(c, -20, 100))
    c.emu.w32(t + 0x5c, p)
    c.emu.w32(t + 0x371, rf(c, -1, 1))
    c.emu.w32(t + 0x1e1, rf(c, 0, 50))
    c.emu.w8(t + 0x2706, c.rng.choice([0, 1]))
    c.emu.w32(t + 0x26ea, c.rng.choice([0, r32(c)]))
    return [t]


S(0x522250, 'ZTank::UpdateSound', 'thiscall', gen=g)
