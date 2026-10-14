"""specs_s37106.py - cascade s6 batch 37106 (0x60d990, thiscall(out) ret 4, returns out). The device object at [0x724b38] has a callee-pops slot 0x2c taking 6 arguments (itself,
two ids, 1, 0, channel) and returning signed results; the state object at +0x13e7 has slots 0x28 / 0x20 (bool); the engine global +0x1aa3 holds the verbose byte at +0x76; the
logger at 0x700390 logs each line."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g60d990(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def lg(em, res_):
        em.calllog.append(('log', em.arg32(0), em.arg32(1)))
        em.ret(eax=0, argbytes=0)
    Lg = obj(c, 0x20, {0x2c: e.stub_fn('log', lg)})
    e.w32(0x700390, obj(c, 0x20, {0x20: pystub(c, 2, this=True, ret=Lg)}))
    so = sysobj(c)
    g = rnd(c, 0x100)
    e.wbytes(g + 0x76, bytes([r.choice([0, 1, 1, 7])]))
    _w(c, so + 0x1aa3, g)
    mode = r.choice(['mix', 'allneg', 'allpos', 'mix'])

    def probe(em, k):
        em.calllog.append(('probe', tuple(em.arg32(i) for i in range(1, 6))))
        if mode == 'allneg':
            return 0xffffffff
        if mode == 'allpos':
            return r.choice([0, 1, 5])
        return r.choice([0xffffffff, 0, 3, 0x80000000, 0x7fffffff])
    dev = obj(c, 0x20, {0x2c: pystub(c, 6, ret=probe)})
    _w(c, 0x724b38, dev)
    st = obj(c, 0x20, {0x28: pystub(c, 0, this=True, ret=lambda em, k: r.choice([0, 1, 0x100, 0x101])),
                       0x20: pystub(c, 0, this=True, ret=lambda em, k: r.choice([0, 1, 0x100, 0x101]))})
    t = rnd(c, 0x1400)
    _w(c, t + 0x13e7, st)
    _w(c, t + 0x12c7, r.choice([0, 0x20000, 0x1ffff, 0x120000, r.getrandbits(32)]))
    _w(c, t + 0x12e3, r.choice([0, 0x20000, 0x1ffff, 0x120000, r.getrandbits(32)]))
    out = rnd(c, 0x10)
    return [t, out]


S(0x60d990, 'GUESS probe_channels', 'thiscall', None, ret='eax', gen=_g60d990, note='batch37106')
