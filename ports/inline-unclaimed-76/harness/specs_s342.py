"""specs_s342.py - gap band, batch 342: 0x60ffe0 (thiscall, ten float arguments, void). The exe helper 0x610250 runs as exe code (pure: it
writes an object at ECX and makes no calls). The incoming ECX is a random 0x80-byte object; the floats are random, with nonzero divisors
a8 and a9."""
from pilot import S, F
import random


def _gen(c):
    e = c.emu
    rng = c.rng
    obj = e.alloc(0x80, 4)
    e.wbytes(obj, bytes(rng.getrandbits(8) for _ in range(0x80)))

    def val():
        return rng.uniform(-100.0, 100.0)

    def div():
        v = rng.uniform(0.5, 20.0)
        return -v if rng.random() < 0.5 else v

    args = [F(val()) for _ in range(6)] + [F(div()), F(val()), F(div()), F(val())]
    return [obj] + args


S(0x60ffe0, 'frame60ffe0 (GUESS)', 'thiscall', None, ret=None, gen=_gen, note='batch342; ret 0x28; helper 0x610250 (exe, pure)')
