"""specs_s47003.py - cascade t8 batch 47003: 0x5f9130 (set a handle with flag word checks). Callees 0x5f3c90, 0x5f5620, 0x5f56f0, 0x5f55e0, 0x6001e0 hooked."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g5f9130(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    e._image_dirty = True
    me = rnd(c, 0x140)
    fl = r.choice([0, 0, 0, 0x800, 0x8000, 0x8800, 0x0001, 0x1234 & 0x77ff, r.getrandbits(16)])
    e.wbytes(me + 0xac, fl.to_bytes(2, 'little'))
    ids = [0xffffffff, 0xffffffff, 0, 1, 0x1234, r.getrandbits(32)]
    e.w32(me + 0x6c, r.choice(ids))
    e.w32(me + 0x68, r.choice(ids))
    a = r.choice([0, 1, 0x1234, r.getrandbits(32)])
    e.w32(me + 0x64, a if r.random() < 0.4 else r.choice([0, 1, r.getrandbits(32)]))
    e.w32(me + 0x96, rnd(c, 0x10))

    def rec_words(em, k):   # 0x5f3c90 gets a record of 5 dwords of which words 1 and 2 are uninitialised stack: record 0, 3, 4 only
        p = em.arg32(0)
        em.calllog.append(('rec', em.r32(p), em.r32(p + 12), em.r32(p + 16)))
    hook_rec(c, 0x5f3c90, 1, this=True, side=rec_words, stackmark=(0,))
    hook_rec(c, 0x5f5620, 1, this=True, ret=lambda em, k: r.getrandbits(32))
    hook_rec(c, 0x5f56f0, 0, this=True)
    hook_rec(c, 0x5f55e0, 0, this=True)
    hook_rec(c, 0x6001e0, 4, this=True, pop=16)
    return [me, a, r.choice([0, 1, 2, 0xff, r.getrandbits(32)])]


S(0x5f9130, 'GUESS set handle with flag word checks', 'thiscall', None, ret=None, gen=_g5f9130, note='batch47003')
