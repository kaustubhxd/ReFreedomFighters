"""specs_s66046.py - cascade s4 batch 66046: 0x482680 (turn option switches into a mode flag word)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks


def _g482680(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    names = [0x68b5bc, 0x68b5c8, 0x68b5d8, 0x68b5e8, 0x68b5b4, 0x67a110]
    vals = {n: r.choice([0, 0, 0, 1, 0x100, 0x1ff, 5]) for n in names}

    def opt(em, rr):
        n = em.arg32(0)
        em.calllog.append(('opt', n, em.arg32(1)))
        em.ret(eax=vals.get(n, 0), argbytes=8)
    o = obj(c, 0x30, {0x38: e.stub_fn('opt', opt)})
    so = sysobj(c)
    e.w32(so + 0x1907, o)
    t = e.alloc(0x440, 8)
    e.wbytes(t + 0x410, bytes(r.getrandbits(8) for _ in range(0x20)))
    e.w32(t + 0x417, r.choice([0, 0, 0x167, 0xffffffff, r.getrandbits(32)]))
    return [t]


S(0x482680, 'GUESS turn option switches into a mode flag word', 'thiscall', None, ret=None, gen=_g482680, note='batch66046')
