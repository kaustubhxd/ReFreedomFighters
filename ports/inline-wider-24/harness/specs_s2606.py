"""specs_s2606.py - wider batch 2606. 0x4d50d0: thiscall(p), ret 4. p == this+4 in ~half the cases; this+4 holds a heap pointer or 0 (about 70/30); 0x634273 hooked
(cdecl, 2 args). The hook at 0x7003b0 is a recorder with plain ret, always set."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _gen(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x634273, 2, pop=0)

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret()
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    me = rnd(c, 0x20)
    e.w32(me + 4, rnd(c, 0x20) if r.random() < 0.7 else 0)
    p = (me + 4) if r.random() < 0.5 else r.choice([0, me, me + 8, r.getrandbits(32)])
    return [me, p]


S(0x4d50d0, 'GUESS FUN_004d50d0 (pointer equal/free path)', 'thiscall', None, ret='eax', gen=_gen, note='batch2606')
