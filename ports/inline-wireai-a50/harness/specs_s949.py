"""specs_s949.py - area 50 batch 949: 0x51b120 (thiscall, one pointer arg, ret 4, void). Stand-in (logged): 0x5003d0 (thiscall, one index arg; returns
one of three drawn blocks chosen by the index: 2, 1, 0). The manager at this+0x1c has slot +0x38c (thiscall, three words: float, float, dword; ret 0xc)
which logs its words. The argument's object is at p+4."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen(c):
    e, r = c.emu, c.rng
    blk = {}
    for idx in (2, 1, 0):
        b = rnd(c, 0x10)
        e.w32(b, r.getrandbits(32))
        blk[idx] = b

    def h5003(e, rr):
        e.calllog.append(('5003d0', e.reg('ecx'), e.arg32(0)))
        e.ret(eax=blk[e.arg32(0)], argbytes=4)

    only_hooks(c, {0x5003d0: h5003})

    def h38c(e, rr):
        e.calllog.append(('mgr.38c', e.reg('ecx'), e.arg32(0), e.arg32(1), e.arg32(2)))
        e.ret(eax=0, argbytes=12)

    mgr = vt_object(c, 0x40, {0x38c: h38c}, nslots=0x100, name='mgr')
    self = rnd(c, 0x40)
    e.w32(self + 0x1c, mgr)
    p = rnd(c, 0x20)
    e.w32(p + 4, rnd(c, 0x20))
    return [self, p]


S(0x51b120, 'three accessor reads then manager call (no name in map; 5003d0 stood in)', 'thiscall', None, gen=_gen, note='area50 batch949 (label D)')
