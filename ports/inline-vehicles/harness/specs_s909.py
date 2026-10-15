"""specs_s909.py - vehicles batch 909: ZHeli::UpdateDeltaPos and ZHeli::UpdateDir."""
from pilot import S
from vh import _rnd, _stub, obj, r32, rf, fconst


def g_dp(c):
    s = _rnd(c, 0x100)
    rv = fconst(c, c.rng.uniform(-1, 1))
    c.emu.w32(s, c.emu.r32(obj(c, 4, {0x1c4: _stub(c, 2, fld=rv)})))
    c.emu.w32(0x70039c, s)
    h = _rnd(c, 0x400)
    for i, g in enumerate((0x2c3, 0x2ec, 0x315)):
        val = c.emu.alloc(4, 4)
        c.emu.w32(val, rf(c, -50, 50))
        vt = c.emu.alloc(0x40, 4)
        c.emu.w32(vt + 8, _stub(c, 1, fills=((0, val, 1),)))
        c.emu.w32(vt + 0x20, _stub(c, 0, ret=c.rng.choice([0, 1])))
        c.emu.w32(vt + 4, _stub(c, 3))
        c.emu.w32(h + g, vt)
        c.emu.w32(h + 0x28e + 4 * i, rf(c, 0, 100))
    return [h]


S(0x51d8f0, 'ZHeli::UpdateDeltaPos', 'thiscall', gen=g_dp)


def g_dir(c):
    s = _rnd(c, 0x100)
    c.emu.w32(s + 0x48, rf(c, 0, 0.1))
    c.emu.w32(0x70039c, s)
    h = obj(c, 0x400, {0x378: _stub(c, 0)})
    for o in range(0x216, 0x22e, 4):
        c.emu.w32(h + o, rf(c, -1, 1) if c.rng.random() > 0.05 else 0)
    return [h]


S(0x51da80, 'ZHeli::UpdateDir', 'thiscall', gen=g_dir)
