"""specs_s37045.py - cascade s6 batch 37045. this: slots 0x3f0 (state, random from a small set per call), 0x500 / 0x504 (objects or 0), 0x45c (2 args); a: slots 0x2e8, 0x1e0;
the objects returned by 0x500 / 0x504 have slot 0x2e8 returning state objects with slots 0x300 / 0x308."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g4730b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))

    def mkobj():
        so = obj(c, 0x20, {0x300: pystub(c, 0, this=True, ret=lambda em, k: r.choice([2, 2, 0, 1])),
                           0x308: pystub(c, 0, this=True, ret=lambda em, k: r.choice([0, 1]))})
        return obj(c, 0x20, {0x2e8: pystub(c, 0, this=True, ret=so)})
    p500 = mkobj() if r.random() < 0.8 else 0
    p504 = mkobj() if r.random() < 0.8 else 0
    states = [3, 4, 4, 5, 6, 9, 0xa, 0, 1]
    me = obj(c, 0x20, {0x3f0: pystub(c, 0, this=True, ret=lambda em, k: r.choice(states)),
                       0x500: pystub(c, 0, this=True, ret=p500), 0x504: pystub(c, 0, this=True, ret=p504),
                       0x45c: pystub(c, 2, this=True)})
    a = obj(c, 0x20, {0x2e8: pystub(c, 0, this=True), 0x1e0: pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, 1, 0x100]))})
    return [me, a]


S(0x4730b0, 'GUESS request state transition', 'thiscall', None, ret='eax', gen=_g4730b0, note='batch37045')
