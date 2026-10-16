"""specs_s382.py - area 76, residue 17, batch 382: three cdecl list moves (no arguments, plain ret; GUESS), see batch382.cpp. Same fixture as
specs_s381: each global pair holds two objects or zero, the objects' +0x10 and +0x14 are written, the list-head globals are random."""
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


S(0x6715d0, 'list6715d0 (GUESS)', 'cdecl', None, ret=None, gen=_gen_for(0x6e6f30, 0x6e6f34), note='area 76 batch 382; residue 17')
S(0x671710, 'list671710 (GUESS)', 'cdecl', None, ret=None, gen=_gen_for(0x6e7010, 0x6e7014), note='area 76 batch 382; residue 17')
S(0x671850, 'list671850 (GUESS)', 'cdecl', None, ret=None, gen=_gen_for(0x6e7208, 0x6e720c), note='area 76 batch 382; residue 17')
