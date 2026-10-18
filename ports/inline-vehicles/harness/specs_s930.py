"""specs_s930.py - vehicles batch 930: ZCar::UpdateSound."""
from pilot import S
from vh import _rnd, _stub, obj, r32, rf, idstub, fconst, hookrec


def g(c):
    s = _rnd(c, 0x1b00)
    node = _rnd(c, 0x90)
    c.emu.w32(s + 0x9b, obj(c, 0x40, {0x60: idstub(c, [c.rng.choice([0, node]), node, 0, node])}))
    c.emu.w32(s + 0x1a9f, 0 if c.rng.random() < 0.05 else obj(c, 0x10, {0x60: _stub(c, 2, ret=r32(c))}))
    c.emu.w32(s, c.emu.r32(obj(c, 4, {0x1c0: _stub(c, 2, fld=fconst(c, c.rng.random()))})))
    c.emu.w32(0x70039c, s)
    hookrec(c, 0x441890, 1)
    t = obj(c, 0x1700, {0x2e8: _stub(c, 1, ret=c.rng.choice([0, 1, 2, 3])), 0x2ec: _stub(c, 1)})
    p = _rnd(c, 0x60)
    c.emu.w32(p + 0x24, c.rng.choice([0, rf(c, 0, 2000)]))
    c.emu.w32(p + 0x28, rf(c, -50, 300))
    c.emu.w32(p + 0x35, c.rng.choice([3, 3, 0]))
    c.emu.w32(t + 0x5c, p)
    for o in (0x1e1, 0x1f1, 0x1641):
        c.emu.w32(t + o, rf(c, 0, 50))
    c.emu.w32(t + 0x2bf, rf(c, 0, 2000))
    c.emu.w8(t + 0x1649, c.rng.choice([0, 1]))
    c.emu.w8(t + 0x160b, c.rng.choice([0, 1]))
    c.emu.w32(t + 0x163d, c.rng.choice([0, rf(c, 0, 2)]))
    c.emu.w32(t + 0x1639, c.rng.randint(0, 4))
    c.emu.w32(t + 0x1645, c.rng.randint(0, 4))
    c.emu.w32(t + 0x1603, c.rng.choice([0, 1, 2, 3]))
    for o in (0x1621, 0x1625, 0x1629, 0x162d):
        c.emu.w32(t + o, c.rng.choice([0, r32(c)]))
    c.emu.w32(t + 0x1635, r32(c))
    c.emu.w32(p + 0x4b, 0)   # CalcTurnAngle without a shape returns 0 (it runs as exe code)
    return [t]


S(0x518bc0, 'ZCar::UpdateSound', 'thiscall', gen=g)
