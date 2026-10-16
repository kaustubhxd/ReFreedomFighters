"""specs_s385.py - area 76, residue 17, batch 385: cdecl list move (no arguments, plain ret; GUESS), see batch385.cpp. Same fixture as specs_s381."""
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


S(0x671e90, 'list671e90 (GUESS)', 'cdecl', None, ret=None, gen=_gen_for(0x6e771c, 0x6e7720), note='area 76 batch 385; residue 17')
