"""specs_s381.py - area 76, residue 17, batch 381: four cdecl list moves (no arguments, plain ret; GUESS), see batch381.cpp.
Each global pair holds two objects (or zero); the objects' +0x10 and +0x14 are written. Random values sit in the list-head globals."""
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


S(0x6710d0, 'list6710d0 (GUESS)', 'cdecl', None, ret=None, gen=_gen_for(0x6e69ec, 0x6e69f0), note='area 76 batch 381; residue 17')
S(0x671210, 'list671210 (GUESS)', 'cdecl', None, ret=None, gen=_gen_for(0x6e6828, 0x6e682c), note='area 76 batch 381; residue 17')
S(0x671350, 'list671350 (GUESS)', 'cdecl', None, ret=None, gen=_gen_for(0x6e6c90, 0x6e6c94), note='area 76 batch 381; residue 17')
S(0x671490, 'list671490 (GUESS)', 'cdecl', None, ret=None, gen=_gen_for(0x6e6da8, 0x6e6dac), note='area 76 batch 381; residue 17')
