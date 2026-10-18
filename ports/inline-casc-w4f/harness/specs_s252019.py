"""specs_s252019.py - hand specs (Sonnet-w4f): 0x6388e0 / 0x638a30 texture block conversion."""
from pilot import S, F
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, seh_record, seh_chain


def _g(fill):
    def g(c):
        clear_hooks(c); r = c.rng; em = c.emu
        R32 = lambda emu, k: r.getrandbits(32)
        T = rnd(c, 0x40); VT = rnd(c, 0x100); em.w32(T, VT)
        REC = rnd(c, 0x20)
        W = r.choice([1, 2, 3, 4, 5, 8]); H = r.choice([1, 2, 3, 4, 7, 8])
        em.w32(REC + 4, W); em.w32(REC + 8, H)
        em.w32(VT + 0x38, pystub(c, 1, this=True, ret=REC, side=lambda emu, k: emu.calllog.append(('t38', emu.arg32(0)))))
        w = (W + 3) & ~3; h = (H + 3) & ~3
        BUF = rnd(c, 0x400); em.wbytes(BUF, bytes(r.getrandbits(8) for _ in range(w * h * 4 + 64)))
        data = bytes(r.getrandbits(8) for _ in range(w * h * 4))
        A = rnd(c, 0x40)
        cols = r.choice([0, 1, 2, 3, 5, -1]); rows = r.choice([0, 1, 2, 3, 4, -2])
        x0 = r.choice([0, 1, 2]); y0 = r.choice([0, 1, 2])
        cols = min(cols, w - x0) if cols > 0 else cols; rows = min(rows, h - y0) if rows > 0 else rows
        DST = rnd(c, 0x400)
        FMT = r.choice([(0xf800, 0x7e0, 0x1f, 0), (0x7c00, 0x3e0, 0x1f, 0x8000), (0xf00, 0xf0, 0xf, 0xf000), (0xff0000, 0xff00, 0xff, 0xff000000), (0xff, 0xff00, 0xff0000, 0), (0xff0000, 0xff00, 0xff, 0)])
        for o, v in ((0, x0), (4, y0), (8, cols & 0xffffffff), (0xc, rows & 0xffffffff), (0x10, r.choice([0x20, 0x40, 8])), (0x14, FMT[0]), (0x18, FMT[1]), (0x1c, FMT[2]), (0x20, FMT[3]), (0x24, r.choice([0x10, 0x20, 0x18])), (0x2c, DST)):
            em.w32(A + o, v)
        em.wbytes(A + 0x28, bytes([r.getrandbits(8)]))
        def fillcb(emu, k):
            emu.wbytes(emu.arg32(0), data)
            emu.calllog.append(('fill', emu.arg32(0) == BUF, emu.arg32(1), emu.reg('ecx') == T))
        hook_rec(c, 0x41e290, 1, ret=BUF, pop=0, side=lambda emu, k: emu.calllog.append(('alloc', emu.arg32(0))))
        hook_rec(c, fill, 2, ret=R32, pop=8, this=True, side=fillcb)
        hook_rec(c, 0x634273, 2, ret=R32, pop=0, side=lambda emu, k: emu.calllog.append(('free', emu.arg32(0) == BUF, emu.arg32(1))))
        return [T, A, r.choice([0, 1, 2, 3])]
    return g


S(0x6388e0, 'GUESS hand port 0x6388e0', 'thiscall', None, ret=None, gen=_g(0x637e10), note='batch252019')
S(0x638a30, 'GUESS hand port 0x638a30', 'thiscall', None, ret=None, gen=_g(0x6380e0), note='batch252019')
