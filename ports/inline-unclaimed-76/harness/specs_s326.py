"""specs_s326.py - gap band, batch 326: 0x615090 (stdcall, one argument). The object is random; 0x610100 and 0x60f040 run as exe code."""
from pilot import S


def _gen(c):
    e = c.emu
    obj = e.alloc(0x80, 4)
    e.wbytes(obj, bytes(c.rng.getrandbits(8) for _ in range(0x80)))
    return [obj]


S(0x615090, 'build615090 (GUESS)', 'stdcall', None, ret=None, gen=_gen, note='batch326; ret 4; calls 0x610100 and 0x60f040 (exe)')
