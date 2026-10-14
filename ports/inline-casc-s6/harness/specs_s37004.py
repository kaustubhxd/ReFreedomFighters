"""specs_s37004.py - cascade s6 batch 37004: 0x5c1b60 (load an entry from a stream). Hooked: 0x6352f0 and 0x5c1dc0 (recorders). Stream slots record and write random data through their
pointer (0x40, 0x48, 0x68 byte, 0x58, 0x6c); table at [[0x70039c]+0x9b] slot 0x58 returns random; this+0x44 object has slots 0x1e0 and 0x20."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g5c1b60(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))
    hook_rec(c, 0x6352f0, 1, this=True, nullflag=(0,), side=lambda em, k: em.w32(em.arg32(0), r.getrandbits(32)))
    hook_rec(c, 0x5c1dc0, 1, this=True, deref={0: 1})

    def wr(nb):
        def side(em, k):
            em.wbytes(em.arg32(0), bytes(r.getrandbits(8) for _ in range(nb)))
        return side
    so = sysobj(c)
    tab = e.r32(so + 0x9b)
    vt = e.alloc(0x40, 4)
    e.w32(tab, vt)
    e.w32(vt + 0x58, pystub(c, 1, this=True, ret=lambda em, k: r.getrandbits(32)))
    st = obj(c, 0x20, {0x40: pystub(c, 1, this=True, nullflag=(0,), side=wr(4)),
                       0x48: pystub(c, 1, this=True, nullflag=(0,), side=wr(4)),
                       0x68: pystub(c, 1, this=True, nullflag=(0,), side=wr(1)),
                       0x58: pystub(c, 1, this=True, nullflag=(0,), side=wr(4)),
                       0x6c: pystub(c, 1, this=True, nullflag=(0,), side=wr(4)),
                       0x18: pystub(c, 2, this=True, nullflag=(0,), side=wr(0x50))})
    o = obj(c, 0x20, {0x1e0: pystub(c, 1, this=True, ret=r.choice([0, 1, 0x100, 0x1ff])), 0x20: pystub(c, 0, this=True, ret=r.getrandbits(32))})
    me = rnd(c, 0x120)
    e.w32(me + 0x44, o)
    return [me, st]


S(0x5c1b60, 'GUESS load entry from stream', 'thiscall', None, ret='al', gen=_g5c1b60, note='batch37004')
