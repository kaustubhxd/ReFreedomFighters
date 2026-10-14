"""specs_s35137.py - 0x655ab0 (stdcall(src, n) ret 8, ret='eax'). Engine (sysobj, 0x2000 bytes) with the unaligned pointer at +0x1aa3 -> X (base [X+0x20] zero in 1/4; cursor [X+0x28] and limit [X+0x24] around each other so the limit is exceeded in a third of the cases); n 0..40;
0x42ab62 (cdecl, 4 args) and 0x634d22 (cdecl, 3 args) recorders; the assert hook at 0x7003b0 always set (random EAX)."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec, sysobj


def _g655ab0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    hook_rec(c, 0x42ab62, 4, pop=0)
    hook_rec(c, 0x634d22, 3, pop=0)
    so = sysobj(c)
    X = rnd(c, 0x40)
    base = 0 if r.random() < 0.25 else r.getrandbits(32) | 0x1000
    cur = r.getrandbits(32) & 0xffffff
    n = r.randint(0, 40)
    lim = (cur + n + r.randint(0, 10)) if r.random() < 2 / 3 else max(0, cur + n - r.randint(1, 10))
    e.w32(X + 0x20, base)
    e.w32(X + 0x28, cur)
    e.w32(X + 0x24, lim)
    e.wbytes(so + 0x1aa3, X.to_bytes(4, 'little'))
    return [rnd(c, 0x40), n]


S(0x655ab0, 'GUESS append bytes to scratch buffer', 'stdcall', None, ret='eax', gen=_g655ab0, note='batch35137')
