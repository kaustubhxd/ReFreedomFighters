"""specs_s42016.py - Sonnet t3 batch 42016. 0x4dfa30: fastcall(out, q, n, p, d) ret 0xc, bool in al; 0x441940 (vec3 add) runs for real. Vectors with zeros, tiny and NaN components so the |denom| < K test is hit both ways."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _fv(r):
    return r.choice([0.0, r.uniform(-10, 10), r.uniform(-1e3, 1e3), r.uniform(-1e-3, 1e-3), 1.0, -1.0, 1e-8, float('nan')])


def _vec(c, r, small=False):
    a = rnd(c, 0x10)
    c.emu.wbytes(a, struct.pack('<fff', *[_fv(r) if not small else r.choice([0.0, 1e-9, -1e-9, r.uniform(-1, 1)]) for _ in range(3)]))
    return a


def g4dfa30(c):
    clear_hooks(c)
    r = c.rng
    return [rnd(c, 0x10), _vec(c, r), _vec(c, r, small=r.random() < 0.3), _vec(c, r), _vec(c, r)]


S(0x4dfa30, 'GUESS ray/plane intersection point', 'fastcall', None, ret='al', gen=g4dfa30, note='batch42016')
