"""specs_s37118.py - cascade s6 batch 37118 (0x54be40, thiscall(), plain ret). The device object at +0xa274 has a callee-pops slot 0x10 (itself and a stack descriptor) that fills the
0x60-byte descriptor with random data and returns zero or non-zero; 0x54f2b0 is a fastcall hook logging ecx / edx; the logger at 0x700390 logs each (format, value) pair."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g54be40(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def lg(em, res_):
        em.calllog.append(('log', em.arg32(1), em.arg32(2)))
        em.ret(eax=0, argbytes=0)
    Lg = obj(c, 0x20, {0x2c: e.stub_fn('log', lg)})
    e.w32(0x700390, obj(c, 0x20, {0x20: pystub(c, 2, this=True, ret=Lg)}))

    def h54(em, res_):
        em.calllog.append(('54f2b0', em.reg('ecx'), em.reg('edx')))
        em.ret(eax=0, argbytes=0)
    e.hook(0x54f2b0, h54)
    ans = r.choice([0, 0, 0, 1, 0x80004005, r.getrandbits(32)])

    def q(em, res_):
        d = em.arg32(1)
        em.calllog.append(('q', em.arg32(0), em.r32(d)))
        em.wbytes(d + 4, bytes(r.getrandbits(8) for _ in range(0x5c)))
        em.ret(eax=ans, argbytes=8)
    dev = obj(c, 0x20, {0x10: e.stub_fn('q', q)})
    t = rnd(c, 0xa300)
    e.wbytes(t + 0xa274, dev.to_bytes(4, 'little'))
    return [t]


S(0x54be40, 'GUESS log_surface_desc', 'thiscall', None, ret=None, gen=_g54be40, note='batch37118')
