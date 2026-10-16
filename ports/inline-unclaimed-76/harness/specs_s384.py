"""specs_s384.py - area 76, residue 17, batch 384: two cdecl list moves (no arguments, plain ret; GUESS), see batch384.cpp. Same fixture as specs_s381."""
from pilot import S


def _gen_for(ga, gb):
    def _gen(c):
        e = c.emu
        rng = c.rng
        objs = [e.alloc(0x40, 4) for _ in range(2)]
        for o in objs:
            e.wbytes(o, rng.randbytes(0x40))
        a = objs[0] if rng.random() < 0.6 else 0
        b = objs[1] if rng.random() < 0.6 else 0
        e.w32(ga, a)
        e.w32(gb, b)
        e.w32(0x7003bc, rng.getrandbits(32))
        e.w32(0x7003c0, rng.getrandbits(32))
        return []
    return _gen


S(0x671c10, 'list671c10 (GUESS)', 'cdecl', None, ret=None, gen=_gen_for(0x6e7320, 0x6e7324), note='area 76 batch 384; residue 17')
S(0x671d50, 'list671d50 (GUESS)', 'cdecl', None, ret=None, gen=_gen_for(0x6e75c8, 0x6e75cc), note='area 76 batch 384; residue 17')
