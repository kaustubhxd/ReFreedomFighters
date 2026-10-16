"""specs_s210053.py - Sonnet-w3a: 0x450ef0. Stream slot 0x40 writes a distinct tag per call (by call index) into its pointer argument; slot 0x58 and 0x18 are recorders; the allocator and 0x45f3c0 are hooked."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def g450ef0(c):
    clear_hooks(c)
    e = c.emu
    vals = [_r(c), c.rng.choice([1, 2, 5, 0x7fffffff, 0x80000000, 0x80000001, 0xffffffff, 0x40000000, 0, 100]), _r(c), _r(c), _r(c)]
    n = c.rng.choice([0, 1, 7, 0x7fffffff, 0x80000000, 0xffffffff, 0x40000000, 0x3fffffff, 0x1234])
    seq = [vals[0], vals[1], vals[2], n, vals[4]]
    # call order of slot 0x40: 0:+0x94  1:id1  2:id2  3:+0x88 (n)  4:+0xa8

    def s40(emu, k):
        emu.w32(emu.arg32(0), seq[k % 5] if k < 5 else 0)
        emu.calllog.append(('s40', k))
    st = obj(c, 0x40, {0x40: pystub(c, 1, ret=0, pop=None, this=True, stackmark=(0,), side=s40), 0x18: pystub(c, 2, ret=_r(c), this=True)}, nslots=0x20)
    hook_rec(c, 0x45f3c0, 1, ret=c.rng.choice([0, 1, 1, 1, 0x100, 0x101]), this=True)
    hook_rec(c, 0x41e290, 1, ret=lambda emu, k: rnd(c, 0x20), pop=0)
    mg = obj(c, 0x40, {0x58: pystub(c, 1, ret=lambda emu, k: _r(c) | 1, this=True)}, nslots=0x30)
    so = rnd(c, 0x200)
    e.wbytes(so + 0x9b, mg.to_bytes(4, 'little'))
    e.w32(0x70039c, so)
    return [rnd(c, 0xe0), st]


S(0x450ef0, 'load_record_from_stream', 'thiscall', None, ret='al', gen=g450ef0, note='batch210053')
