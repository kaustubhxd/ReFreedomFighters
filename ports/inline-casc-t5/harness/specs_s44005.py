"""specs_s44005.py - t5 (Sonnet) batch 44005: 0x6106e0."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def g6106e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    hook_rec(c, 0x633654, 0, pop=0, this=True)
    hook_rec(c, 0x6107e0, 1, this=True, pop=4, deref={0: 16}, ret=r.getrandbits(32))

    def fv():
        return r.choice([r.uniform(-100, 100), r.uniform(0.01, 5), 0.0, 1.0, r.uniform(-1e4, 1e4), float('nan'), r.uniform(0.1, 1000)])
    me = rnd(c, 0x20)
    flag = r.choice([0, 0, 0, 1, 0x100, 0xffffff00 | r.getrandbits(8)])
    return [me] + [F(fv()) for _ in range(6)] + [flag]


S(0x6106e0, 'GUESS build frustum matrix', 'thiscall', None, ret=None, gen=g6106e0, nan_heap=True, note='batch44005')
