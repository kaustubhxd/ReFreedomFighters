"""specs_s37083.py - cascade s6 batch 37083 (0x46f7d0, thiscall(stream) ret 4, returns bool). The stream object has recording stubs on slots 0x6c, 0x40, 0x48, 0x68, 0x50, 0x70;
the chained results are two further objects (chain A: slots 0x40/0x48/0x68 return chain B and so on) so a wrong chain order shows up. Slot 0x40 writes a dword through its pointer;
0x46f520 is a recording hook."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g46f7d0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x46f520, 1, this=True)
    vals = [r.getrandbits(32) for _ in range(6)]

    def wr(em, k):
        em.w32(em.arg32(0), vals[k % 6])
    Cb = []

    def lg(tag):
        def f(em, k):
            v = em.arg32(0)
            em.calllog.append((tag, v if 0x20000000 <= v < 0x30000000 else 1))
        return f
    sw = lambda em, k: (lg('c40')(em, k), wr(em, k))
    ret = lambda em, k: Cb[0]
    C = obj(c, 0x20, {0x40: pystub(c, 1, this=True, ret=ret, side=sw, stackmark=(0,)), 0x48: pystub(c, 1, this=True, ret=ret, side=lg('c48')), 0x68: pystub(c, 1, this=True, ret=ret, side=lg('c68'))})
    Cb.append(C)
    A2 = C
    s = obj(c, 0x20, {0x6c: pystub(c, 1, this=True), 0x40: pystub(c, 1, this=True, ret=A2), 0x48: pystub(c, 1, this=True, ret=A2),
                      0x68: pystub(c, 1, this=True, ret=A2), 0x50: pystub(c, 1, this=True, ret=A2), 0x70: pystub(c, 1, this=True)})
    t = rnd(c, 0x110)
    return [t, s]


S(0x46f7d0, 'GUESS serialise_fields', 'thiscall', None, ret='al', gen=_g46f7d0, note='batch37083')
