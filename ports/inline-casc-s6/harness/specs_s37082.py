"""specs_s37082.py - cascade s6 batch 37082 (0x57a1e0, thiscall(), plain ret). Engine slots 0x5c (name, &out: writes a string pointer or 0 into the out word) and 0x190 (returns a
logger-like object whose slot 0x198 is a cdecl formatter stub writing fmt/arg into the buffer); table slot 0x58 returns one of three handle objects per call; handle slots 0x284
(text buffer, 16 bytes logged) and 0xbc (1 arg)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g57a1e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hs = [obj(c, 0x20, {0x284: pystub(c, 1, this=True, deref={0: -16}), 0xbc: pystub(c, 1, this=True)}) for _ in range(3)]
    names = [0, 0, 0x5000, 0x5100, r.getrandbits(32)]
    outs = [r.choice(names) for _ in range(3)]

    def out(em, k):
        em.w32(em.arg32(1), outs[k % 3])

    def fmt(em, res_):
        d, f, a = em.arg32(1), em.arg32(2), em.arg32(3)
        em.calllog.append(('fmt', f, a))
        em.wbytes(d, f.to_bytes(4, 'little') + a.to_bytes(4, 'little') + bytes([0x55]) * 8)
        em.ret(eax=0, argbytes=0)
    L = obj(c, 0x20, {0x198: e.stub_fn('fmt', fmt)})
    sysobj(c, slots={0x5c: pystub(c, 2, this=True, nullflag=(1,), side=out), 0x190: pystub(c, 0, this=True, ret=L)},
           table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: hs[k % 3])}, table_size=0x60)
    t = rnd(c, 0x80)
    return [t]


S(0x57a1e0, 'GUESS init_three_handles', 'thiscall', None, ret=None, gen=_g57a1e0, note='batch37082')
