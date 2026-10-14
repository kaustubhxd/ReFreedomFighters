"""specs_s37021.py - cascade s6 batch 37021: 0x531070 (octree cursor step). No callees: tree = depth at +0x38, 0x16-byte nodes at +0x54, 12-byte table at +0x5a;
all child indices are valid; modes 1 and 2 only (the original dereferences a null node otherwise)."""
from pilot import S
from recruits_util import rnd


def _w(c, a, nbytes, v):
    c.emu.wbytes(a, (v & ((1 << (8 * nbytes)) - 1)).to_bytes(nbytes, 'little'))


def _g531070(c):
    r = c.rng
    e = c.emu
    N = 24
    M = 12
    nodes = e.alloc(N * 0x16 + 16, 2)
    for i in range(N):
        a = nodes + 0x16 * i
        e.wbytes(a, bytes(r.getrandbits(8) for _ in range(4)))
        for k in range(9):
            _w(c, a + 4 + 2 * k, 2, r.randrange(N))
    tab = e.alloc(M * 12 + 16, 2)
    for i in range(M):
        e.wbytes(tab + 12 * i, bytes(r.getrandbits(8) for _ in range(12)))
        _w(c, tab + 12 * i + 4, 2, r.randrange(N))
    T = rnd(c, 0x70)
    depth = r.randint(0, 10)
    _w(c, T + 0x38, 4, depth)
    _w(c, T + 0x54, 4, nodes)
    _w(c, T + 0x5a, 4, tab)
    mode = r.choice([1, 2])
    me = rnd(c, 0x40)
    e.w32(me, T)
    _w(c, me + 0x12, 4, r.randint(0, 5))
    _w(c, me + 0x16, 2, r.randrange(N if mode == 1 else M))
    for off in (0x18, 0x1a, 0x1c):
        _w(c, me + off, 2, r.choice([r.getrandbits(16), r.getrandbits(8), 0, 0xffff]))
    _w(c, me + 0x20, 1, mode)
    for off in (0x21, 0x25, 0x29):
        _w(c, me + off, 2, r.choice([r.getrandbits(16), 1, 2, 0xffff, 0]))
    d = e.alloc(8, 2)
    for k in range(3):
        _w(c, d + 2 * k, 2, r.choice([0, 1, 2, 3, 0xffff, 0x7fff, r.getrandbits(16), r.getrandbits(4)]))
    return [me, d]


S(0x531070, 'GUESS octree cursor step', 'thiscall', None, ret='eax', gen=_g531070, note='batch37021')
