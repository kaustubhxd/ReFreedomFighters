"""specs_s240.py - ladder thread batch 240: ZFFHERO::GetFocalPoint (camera focus point)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
from pe_emu import f32
import ladder_kit as K


def _gfp(c):
    e, r = c.emu, c.rng
    hero = K.rnd(c, 0x900)
    e.w32(hero + 0x417, r.getrandbits(32) & (0xffffffff if r.random() < 0.6 else 0xffff0f00))
    e.wf32(hero + 0x81f, f32(r.uniform(-100, 260)))
    e.wf32(hero + 0x823, c.fv(-300.0, 300.0))
    cam = K.rnd(c, 0xc00)
    e.w8(cam + 0xb45, r.choice([0, 1]))
    e.w32(hero + 0x85a, cam)
    eng = K.engine(c)
    e.wf32(eng + 0x48, f32(r.choice([0.0, 1.0 / 60.0, 1.0 / 25.0, r.uniform(0, 0.1)])))
    s_ret = r.getrandbits(32)

    def h438(e2, a):
        return (1 if r.random() < 0.2 else 0), None, None

    def h3a8(e2, a):
        vals = [f32(r.uniform(-50, 50)) for _ in range(3)]
        K.wv3(e2, a[0], vals)
        return s_ret, None, (K.bits3(e2, a[1]),)

    def h390(e2, a):
        return 0, None, (a[0],)

    def h4d0(e2, a):
        return (1 if r.random() < 0.5 else 0), None, None
    e.w32(hero, K.vt(c, 'hero', {0x438: (0, h438), 0x3a8: (2, h3a8), 0x390: (1, h390), 0x4d0: (0, h4d0)}, nslots=0x500))
    out = K.rnd(c, 0x20)
    return [hero, out]


S(0x591bb0, 'ZFFHERO::GetFocalPoint', 'thiscall', None, ret=None, gen=_gfp, note='batch240')
