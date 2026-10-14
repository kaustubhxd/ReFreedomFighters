"""specs_s245.py - ladder thread batch 245: ZFFHERO::PlayCommandAnim (throttled command -> action 0x1a/0x1b/0x1c)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import ladder_kit as K


def _pca(c):
    e, r = c.emu, c.rng
    eng = K.engine(c)
    now = r.randint(0, 1 << 20)
    e.w32(eng + 0x40, now)
    hero = K.rnd(c, 0x1000)
    e.w32(hero + 0x417, r.getrandbits(32) & (0xffffffff if r.random() < 0.7 else 0xf7ffffff))
    e.w32(hero + 0x94f, (now - r.choice([0, 100, 199, 200, 201, 300, 400, 511, 512, 5000, r.randint(0, 1 << 20)])) & 0xffffffff)
    busy = r.choice([0, 0, 1])
    act = r.getrandbits(32)
    e.w32(hero, K.vt(c, 'hero', {0x3f0: (0, lambda e2, a: (busy, None, None)),
                                 0x3ec: (1, lambda e2, a: (act, None, None)),
                                 0x3d8: (1, lambda e2, a: (0, None, (K.nostack(a[0]),)))}, nslots=0x400))
    return [hero, r.choice([0, 1, 2, 3, 0xffffffff])]


S(0x593f40, 'ZFFHERO::PlayCommandAnim', 'thiscall', None, ret=None, gen=_pca, note='batch245')
