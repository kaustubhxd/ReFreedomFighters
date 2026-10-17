"""specs_s515.py - weapons batch 515: ZTARGET blend completion and release-with-callback."""
from pilot import S
from pe_emu import F
from wkit import rnd, stub, obj, sysobj, fedge


def _t(c):
    r = c.rng
    sysobj(c, {})
    so = c.emu.r32(0x70039c)
    now = r.randint(0, 1 << 20)
    c.emu.w32(so + 0x40, now)
    t = rnd(c, 0x80)
    x = r.random()
    if x < 0.7:
        el = r.choice((0, 0, 1, 100, 256, 1024, r.randint(0, 3000)))
        st = (now - el) / 1024.0
        c.emu.wf32(t + 0x35, st if r.random() < 0.5 else -st)
        c.emu.wf32(t + 0x31, r.choice((0.0, el / 1024.0, 0.25, 1.0, r.uniform(0, 3))))
    else:
        c.emu.wf32(t + 0x35, fedge(c))
        c.emu.wf32(t + 0x31, fedge(c))
    c.emu.w32(t + 0x3d, 0 if r.random() < 0.3 else stub(c, 0, rec_ecx=True))
    c.emu.w32(t + 0x41, r.choice((0, 4, 8)))
    return t


def _done(c):
    return [_t(c), rnd(c, 0x40)]


def _rel(c):
    r = c.rng
    t = _t(c)
    cb = 0 if r.random() < 0.3 else stub(c, 0, rec_ecx=True)
    return [t, rnd(c, 0x40), F(r.choice((0.0, 0.0, -0.0, 0.3, 1.0, fedge(c)))), cb, r.choice((0, 4)), 0, 0xffffffff]


S(0x465930, 'ZTARGET blend done (Update body)', 'thiscall', None, ret=None, gen=_done)
S(0x467410, 'ZTARGET release with callback', 'thiscall', None, ret=None, gen=_rel)
