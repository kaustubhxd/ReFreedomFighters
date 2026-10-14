"""specs_s37110.py - cascade s6 batch 37110 (0x58c150, stdcall(a, p1, p2) ret 0xc, returns bool). O = a+0x44 is an object with slots 0x1e0, 0x20 (delegate, thrice), 0x2e0, 0x98,
0x3a8, 0x390; the delegate has slot 0x1e0 and also the apply slots; the global at 0x70038c has slot 0xcc (looked up twice, results chosen per call); logger at 0x700390 for
error 0x377; 0x4de7a0 is a recording hook."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g58c150(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def lg(em, res_):
        em.calllog.append(('log', em.arg32(0), em.arg32(1)))
        em.ret(eax=0, argbytes=0)
    Lg = obj(c, 0x20, {0x2c: e.stub_fn('log', lg)})
    e.w32(0x700390, obj(c, 0x20, {0x20: pystub(c, 2, this=True, ret=Lg)}))
    hook_rec(c, 0x4de7a0, 0, this=True)
    g = obj(c, 0x20, {0xcc: pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, 0x1000, 0x2000]))})
    e.w32(0x70038c, g)
    yes = lambda em, k: r.choice([0, 1, 1, 0x100, 0x101])
    delegate = obj(c, 0x20, {0x1e0: pystub(c, 1, this=True, ret=yes), 0x2e0: pystub(c, 2, this=True), 0x98: pystub(c, 2, this=True)})
    dg = delegate if r.random() < 0.8 else 0
    O = obj(c, 0x40, {0x1e0: pystub(c, 1, this=True, ret=yes), 0x20: pystub(c, 0, this=True, ret=dg),
                      0x2e0: pystub(c, 2, this=True), 0x98: pystub(c, 2, this=True), 0x3a8: pystub(c, 2, this=True, nullflag=(), ret=lambda em, k: r.getrandbits(32)),
                      0x390: pystub(c, 1, this=True)})
    a = rnd(c, 0x120)
    _w(c, a + 0x44, O)
    _w(c, a + 0x106, r.getrandbits(32))
    p1 = rnd(c, 0x40)
    p2 = rnd(c, 0x10)
    return [a, p1, p2]


S(0x58c150, 'GUESS apply_pair', 'stdcall', None, ret='al', gen=_g58c150, note='batch37110')
