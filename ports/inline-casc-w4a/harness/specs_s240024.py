"""specs_s240024.py - Sonnet-w4a: 0x5f4390 state dump through the global text stream."""
import pe_emu
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub

# number of dwords after the format string for each format of the dump
_NARGS = {0x6b8bb4: 0, 0x6b8bdc: 0, 0x6b8bec: 0, 0x6b8c14: 0, 0x6b8c34: 1, 0x6b8c54: 0, 0x6b8c78: 1, 0x6b8c98: 4, 0x6b8cd4: 0, 0x6b8ce8: 1,
          0x6b8d08: 1, 0x6b8d44: 1, 0x6b8d64: 1, 0x6b8d84: 1, 0x6b8da4: 0, 0x6b8db0: 1, 0x6b8dd0: 1, 0x6b8df0: 0, 0x6b8dfc: 2, 0x6b8e28: 2,
          0x6b8e54: 2}


def _w(c):
    return c.rng.getrandbits(32)


def _gen(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def printf(em, res):
        fmt = em.arg32(1)
        n = _NARGS[fmt]
        em.calllog.append(('printf', em.arg32(0), fmt) + tuple(em.arg32(2 + i) for i in range(n)))
        em.ret(eax=_w(c), argbytes=0)
    s_ = obj(c, 0x40, {0xc: e.stub_fn('printf', printf),
                       0x4: pystub(c, 0, this=True, ret=lambda em, k: _w(c)),
                       0x1c: pystub(c, 1, this=True, ret=lambda em, k: _w(c))})
    e.w32(0x724270, s_)
    this = rnd(c, 0x100)
    e.wbytes(this + 0xa, __import__('struct').pack('<f', r.choice([0.0, 1.5, -2.25, 1e10, r.uniform(-1000, 1000)])))
    e.w32(this + 0x96, rnd(c, 0x100))
    e.w32(this + 0x20, r.choice([0, 0, 1, _w(c)]))
    return [this]


S(0x5f4390, 'GUESS object state dump', 'thiscall', None, ret=None, gen=_gen, note='batch240024')
