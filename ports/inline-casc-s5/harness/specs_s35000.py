"""specs_s35000.py - 0x63faa0. 0x658e00 hooked (thiscall, 2 args: buffer (flag only) and 8; writes 0..8 node pointers into the buffer).
Each node has +0x54 = res (null in 1/5) with res+0xc -> block whose unaligned dword at +0x23 holds the flags (bit 0x100000 set in half); res+8 = first
chain element (null sometimes); res slot 0x50 rewrites *arg (the local cursor) with a non-zero heap word for the first few calls, then 0; this slot 0x50 recorded."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g63faa0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 2, 3, 5, 8, 8])
    nodes = []
    for _ in range(n):
        node = rnd(c, 0x60)
        if r.random() < 0.2:
            e.w32(node + 0x54, 0)
        else:
            cnt = [0]
            lim = r.choice([0, 1, 2, 3])

            def side(em, k, cnt=cnt, lim=lim):
                cnt[0] += 1
                em.w32(em.arg32(0), 0x1000 * cnt[0] if cnt[0] <= lim else 0)
            vt = {0x50: pystub(c, 1, this=True, nullflag=(0,), side=side)}
            res = obj(c, 0x20, vt)
            blk = rnd(c, 0x30)
            fl = r.getrandbits(32)
            fl = (fl | 0x100000) if r.random() < 0.6 else (fl & ~0x100000)
            e.wbytes(blk + 0x23, fl.to_bytes(4, 'little'))
            e.w32(res + 0xc, blk)
            if r.random() < 0.15:
                e.w32(res + 8, 0)
            e.w32(node + 0x54, res)
        nodes.append(node)

    def fill(em, k):
        buf = em.arg32(0)
        for i, nd in enumerate(nodes):
            em.w32(buf + 4 * i, nd)
    hook_rec(c, 0x658e00, 2, this=True, nullflag=(0,), ret=n, side=fill)
    me = obj(c, 0x20, {0x50: pystub(c, 1, this=True)})
    return [me, rnd(c, 0x10)]


S(0x63faa0, 'GUESS walk nodes, flagged chain relink', 'thiscall', None, ret=None, gen=_g63faa0, note='batch35000')
