"""specs_s213095.py - batch 213095: three-entry column layout from a widget pool, Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g570040(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    sl = lambda n, ret=None, **kw: pystub(c, n, ret=(r.getrandbits(32) if ret is None else ret), this=True, **kw)

    def widget():
        return obj(c, 0x20, {0x260: sl(1), 0x70: sl(1, deref={0: 3}), 0xbc: sl(1), 0x284: sl(1)}, nslots=0x100)
    this = rnd(c, 0x250)
    pool_n = r.choice([0, 1, 2, 3, 4, 6])
    for i in range(14):
        e.w32(this + 0x1cc + 4 * i, 0 if (r.random() < 0.15 or i >= pool_n) else widget())
    e.w32(this + 0x22c, pool_n if r.random() < 0.7 else r.choice([0, 1, 2, 3, 5, 0xffffffff, 0x80000000, 0x80000001]))
    e.w32(this + 0x230, r.choice([0, 0, 0, 1, 2, 3, 4, 5]))
    e.w32(this + 0x234, r.choice([0, 1, 2, 5, 100, 0x7fffffff, 0x80000000, 0xffffffff, 0x0ccccccc, 0x0cccccce, r.getrandbits(32)]))
    e.wbytes(this + 0x1a3, bytes([r.choice([0, 0, 0, 1, 0xff])]))
    e.w32(this + 0x1c4, 0 if r.random() < 0.25 else widget())
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)
    def v():
        return r.choice([0, 0, r.getrandbits(32)])
    return [this, v(), v(), v()]


S(0x570040, 'column_layout', 'thiscall', None, ret=None, gen=g570040)
