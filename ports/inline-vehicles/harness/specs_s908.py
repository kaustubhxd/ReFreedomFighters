"""specs_s908.py - vehicles batch 908: heli dust emitter and emitter leaves. ParticleEmitter::FrameUpdate
(0x5168b0) and the emitter set-up 0x516b60 are stood in for by vh.hookrec (both runs)."""
from pilot import S
from vh import _rnd, _stub, obj, r32, rf, idstub, fconst, hookrec

PT = [(0, 'd'), (4, 'd'), (8, 'd')]


def vec(c, lo=-100, hi=100, zero=0.0):
    v = c.emu.alloc(12, 4)
    for k in range(3):
        c.emu.w32(v + 4 * k, 0 if c.rng.random() < zero else rf(c, lo, hi))
    return v


S(0x516f40, 'ParticleEmitter::SetEmitDir', 'thiscall', gen=lambda c: [_rnd(c, 0x60), vec(c, zero=0.3)])


def g_es(c):
    hookrec(c, 0x516b60, 3)
    return [_rnd(c, 0x60), r32(c), r32(c)]


S(0x517030, 'ParticleEmitter set-up wrapper (inferred)', 'thiscall', gen=g_es)


def g_dust(c):
    hookrec(c, 0x516b60, 3)
    hookrec(c, 0x5168b0, 0)
    s = _rnd(c, 0x1b00)
    p = _rnd(c, 0xb00)
    c.emu.w32(p + 0xadc, obj(c, 0x40, {0x2e0: _stub(c, 6, ret=c.rng.getrandbits(8))}))
    q = _rnd(c, 0x50)
    mt = _rnd(c, 8)
    wd = obj(c, 0xb00, {0x58: idstub(c, [0, 0, 0, 0]), 0x160: idstub(c, [q, 0, q, q])})
    c.emu.wbytes(wd + 4, c.emu.rbytes(p + 4, 0xafc))
    c.emu.w32(s + 0x9b, wd)
    eng = _rnd(c, 0x20)
    c.emu.w32(eng + 0x1c, obj(c, 8, {0x74: _stub(c, 1, ret=r32(c))}))
    c.emu.w32(eng + 0x18, obj(c, 8, {0xf8: _stub(c, 1, ret=c.rng.choice([0, mt]))}))
    c.emu.w32(s + 0x1aa3, eng)
    rv = fconst(c, c.rng.choice([c.rng.random() * 0.2, c.rng.random()]))
    c.emu.w32(s, c.emu.r32(obj(c, 4, {0x1c0: _stub(c, 2, fld=rv)})))
    c.emu.w32(0x70039c, s)
    g = _rnd(c, 0xb00)
    c.emu.w8(g + 0xab8, c.rng.choice([0, 0, 0, 1]))
    c.emu.w32(0x7003b8, g)
    off = vec(c, -5, 5)
    dv = vec(c, -1, 1)
    h = obj(c, 0x600, {0x8c: _stub(c, 1, skip=(0,), copy=(0, PT), adds=((0, off, 3),)),
                       0x90: _stub(c, 1, skip=(0,), fills=((0, dv, 3),))})
    for o in (0x60, 0x64, 0x68, 0x54e, 0x552, 0x556):
        c.emu.w32(h + o, rf(c, -1000, 1000))
    c.emu.w32(h + 0x597, rf(c, 0, 2000))
    return [h]


S(0x51db60, 'ZHeli::UpdateDustEmitter', 'thiscall', gen=g_dust)
