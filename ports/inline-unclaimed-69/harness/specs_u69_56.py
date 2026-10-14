"""specs_u69_56.py - area 69, group 56 (slice 8): 0x457840, the 3x3x3 neighbour mask. Callee 0x459b90 is a GUESS stub: it logs its four
args (small values only; the first is a 16-bit word) and returns 0, p, or a pointer into the cell array, chosen by its first arg."""
from pilot import S
from ckit import rnd


def _gen(c):
    e = c.emu
    r = c.rng
    self_ = rnd(c, 0x100)
    arr = rnd(c, 0x7c * 9 + 0x40)
    e.w32(self_ + 0x3c, arr)
    p = rnd(c, 0x10)
    w0 = r.choice([0, 1, 2, 3, 4, 5, 6, 7, 8, r.randrange(1, 9)])
    e.w16(p, w0) if hasattr(e, 'w16') else e.wbytes(p, bytes([w0 & 0xff, (w0 >> 8) & 0xff]))

    def stub(e, res):
        a1 = e.arg32(0) & 0xffff
        a2, a3, a4 = e.arg32(1), e.arg32(2), e.arg32(3)
        e.calllog.append(('t459b90', a1 & 0xff, a2, a3, a4))
        m = a1 % 4
        if m == 0:
            ret = 0
        elif m == 1:
            ret = p
        else:
            ret = arr + (a1 % 9) * 0x7c
        e.ret(eax=ret & 0xffffffff, argbytes=0x10)

    e.hook(0x459b90, stub)
    return [self_, p]


S(0x457840, 'neighbourMask457840 (thiscall, one arg, ret 4)', 'thiscall', None, ret='eax', gen=_gen,
  note='u69 group 56; 0x459b90 is a GUESS stub (other area)')
