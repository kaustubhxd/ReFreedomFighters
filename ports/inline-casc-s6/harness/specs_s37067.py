"""specs_s37067.py - cascade s6 batch 37067 (0x4010c0, state destructor). Free (0x634d52), 0x405670 and 0x4024a0 are recording hooks. The class tables at 0x6f1dc0..0x6f1e20
(overlapping, indexed by small values) hold objects whose slot 0x10 is a recording stub; each table entry points at one of several distinct objects."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g4010c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x634d52, 1, pop=0)
    hook_rec(c, 0x405670, 1, pop=0)
    hook_rec(c, 0x4024a0, 1, pop=0)
    objs = []
    for _ in range(4):
        o = rnd(c, 0x20)
        _w(c, o + 0x10, pystub(c, 1, pop=0))
        objs.append(o)
    for i in range(24):
        _w(c, 0x6f1dc0 + 4 * i, r.choice(objs))
    p = rnd(c, 0x30)
    if r.random() < 0.12:
        _w(c, p + 0x1c, 0)
        return [p]
    st = e.alloc(0xe40, 4)
    e.wbytes(st, bytes(r.getrandbits(8) for _ in range(0xe40)))
    for off, mx in ((8, 6), (0xc, 4), (0x10, 4), (0x14, 4), (0x18, 4), (0x1c, 6), (0x20, 5)):
        _w(c, st + off, r.choice([0, 1, 2, mx, 0xffffffff]) if r.random() < 0.9 else r.randrange(mx + 1))
    for off in (0x124, 0x324, 0x524, 0x724):
        for i in range(8):
            _w(c, st + off + 4 * i, r.randrange(0, 3))
    for i in range(8):
        if r.random() < 0.4:
            _w(c, st + 0x24 + 4 * i, 0)
            _w(c, st + 0x924 + 4 * i, 0)
    _w(c, p + 0x1c, st)
    return [p]


S(0x4010c0, 'GUESS state_destroy', 'cdecl', None, ret=None, gen=_g4010c0, note='batch37067')
