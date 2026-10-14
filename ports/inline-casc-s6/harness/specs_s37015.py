"""specs_s37015.py - cascade s6 batch 37015: 0x4a7620 (load an entry from a stream). Stream slots write random bytes (sizes: 0x68 1, 0x6c 12, others 4) through their pointer,
so overlapping field writes expose any change of order; 0x4e7480 hooked."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g4a7620(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))
    hook_rec(c, 0x4e7480, 1, this=True)

    def wr(nb):
        def side(em, k):
            em.wbytes(em.arg32(0), bytes(r.getrandbits(8) for _ in range(nb)))
        return side
    sizes = {0x40: 4, 0x48: 4, 0x50: 4, 0x58: 4, 0x68: 1, 0x6c: 12, 0x74: 4}
    st = obj(c, 0x20, {s: pystub(c, 1, this=True, side=wr(n)) for s, n in sizes.items()})
    me = rnd(c, 0x140)
    return [me, st]


S(0x4a7620, 'GUESS load entry from stream (26 fields)', 'thiscall', None, ret='al', gen=_g4a7620, note='batch37015')
