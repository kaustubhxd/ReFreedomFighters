"""specs_s9003.py - wire-ai batch 9003: 0x547430 (random unit vector). The engine's random slot 0x1c0 is a fake returning values in ST0:
ordinary [0, 1), exactly 0.5 (a zero lane), triples of 0.5 (length 0: the loop runs again, up to 3 times), values 0.5 +- 1e-7 (length
around the 1e-6 cut). The emulator hands ST0 a float (pe_emu ret(st0=)), so the long double read is exercised with float inputs only.
Each call logs its file / line arguments. vscalar 0x4e0d00 runs as exe code."""
import struct
from pilot import S
from specs_s701 import _rnd


def _ruv(c):
    e = c.emu
    eng = _rnd(c, 0x200)
    seq = []
    for _ in range(c.rng.choice([0, 0, 1, 3])):
        seq += [0.5, 0.5, 0.5]
    if c.rng.random() < 0.2:
        d = c.rng.choice([1e-7, 4e-7, 5.7735e-7, 6e-7, 1e-6])
        seq += [0.5 + d, 0.5 + d * c.rng.choice([1, -1]), 0.5 + d]
    def draw(em, r):
        em.calllog.append(('rand', 0x1c0, None, (em.arg32(0), em.arg32(1))))
        if seq:
            x = seq.pop(0)
        else:
            k = c.rng.random()
            x = 0.5 if k < 0.1 else c.rng.random()
        em.ret(argbytes=8, st0=x)
    e.w32(eng, e.fake_vtable('engine', 0x80, {0x1c0: draw}))
    e.w32(0x70039c, eng)
    v = _rnd(c, 16)
    return [v]


S(0x547430, 'random unit vector (particle3)', 'thiscall', None, ret=None, gen=_ruv, note='b9003; vscalar as exe code')
