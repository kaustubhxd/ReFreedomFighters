"""specs_s38019.py - cascade s8 batch 38019: 0x50c030. 0x5003d0 is a custom hook: req[8] -> an object, req[4] with arg 0 / 1 -> pointers to two key dwords. Table slot 0x58 maps the keys to
the first / second object (or 0). First object: slots 0x1e0 (flag test), 0x20 (returns D), 0x520, field +4; second: 0x1e0, 0x2f4 (returns D, the first object or something else), 0x2e8 (returns an
object with +4). The logger stream printer arity follows the line (0x358 / 0x365: 2 args, 0x35f / 0x36a: 3, 0x370: 4). 0x5002f0 hooked."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g50c030(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    sts = {n: obj(c, 0x20, {0x2c: pystub(c, n, pop=0)}) for n in (2, 3, 4)}
    arity = {0x358: 2, 0x365: 2, 0x35f: 3, 0x36a: 3, 0x370: 4}

    def lg(em, res_):
        line = em.arg32(1)
        em.calllog.append(('logger', em.reg('ecx') != 0, em.arg32(0), line))
        em.ret(eax=sts[arity.get(line, 2)], argbytes=8)
    e.w32(0x700390, obj(c, 0x40, {0x20: e.stub_fn('logger', lg)}))

    def fl():
        return lambda em, k: r.choice([1, 1, 1, 0x100, 0x101, 0])
    D = rnd(c, 0x20)
    X = rnd(c, 0x20)
    first = obj(c, 0x40, {0x1e0: pystub(c, 1, this=True, ret=lambda em, k: r.choice([1, 1, 1, 1, 0x100, 0])),
                          0x20: pystub(c, 0, this=True, ret=D), 0x520: pystub(c, 1, this=True)})
    e.w32(first + 4, r.getrandbits(32))
    other = rnd(c, 0x20)
    mode = r.choice([D, 'first', other])
    cres = first if mode == 'first' else mode
    second = obj(c, 0x40, {0x1e0: pystub(c, 1, this=True, ret=lambda em, k: r.choice([1, 1, 1, 1, 0x100, 0])),
                           0x2f4: pystub(c, 0, this=True, ret=cres), 0x2e8: pystub(c, 0, this=True, ret=X)})
    e.w32(second + 4, r.getrandbits(32))
    k1, k2 = r.sample(range(1, 1000), 2)
    p1 = e.alloc(4, 4)
    e.w32(p1, k1)
    p2 = e.alloc(4, 4)
    e.w32(p2, k2)
    o8 = rnd(c, 0x20)
    req = rnd(c, 0x20)
    q4 = rnd(c, 0x20)
    e.w32(req + 4, q4)
    e.w32(req + 8, o8)

    def h3d0(em, res_):
        ecx, a = em.reg('ecx'), em.arg32(0)
        em.calllog.append(('h5003d0', ecx, a))
        em.ret(eax=o8 if ecx == o8 else (p1 if a == 0 else p2), argbytes=4)
    e.hook(0x5003d0, h3d0)
    hook_rec(c, 0x5002f0, 1, this=True, pop=4)
    pf = r.choice([0.1, 0.3])

    def s58(em, res_):
        a = em.arg32(0)
        em.calllog.append(('s58', em.reg('ecx'), a))
        v = {k1: first, k2: second}.get(a, 0)
        if r.random() < pf:
            v = 0
        em.ret(eax=v, argbytes=4)
    sysobj(c, {}, table_slots={0x58: e.stub_fn('s58', s58)})
    e.w32(first + 8, 0)
    return [req]


S(0x50c030, 'GUESS validate named objects and bind', 'stdcall', None, ret=None, gen=_g50c030, note='batch38019')
