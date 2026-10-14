"""specs_s36072.py - cascade s4 batch 36072: 0x44ab20 (rebuild an animation track list)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g44ab20(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x634273, 2, pop=0)
    hook_rec(c, 0x4609f0, 4, this=True)
    hook_rec(c, 0x460bb0, 0, this=True)

    def alloc(em, rr):
        sz = em.arg32(0)
        em.calllog.append(('malloc', sz))
        if sz > 0x1000 or fail:
            em.ret(eax=0, argbytes=0)
            return
        blk = e.alloc(max(sz, 16), 4)
        e.wbytes(blk, bytes([0x44]) * max(sz, 16))
        em.ret(eax=blk, argbytes=0)
    fail = r.random() < 0.1
    e.hook(0x41e290, alloc)
    cntrec = rnd(c, 8)
    e.w32(cntrec, r.choice([0, 1, 2, 3, 5, 0x20000000]))
    r3 = rnd(c, 0x10)

    def s0fc(em, rr):
        em.calllog.append(('s0fc', em.reg('ecx'), em.arg32(0)))
        em.ret(eax=r3, argbytes=4)
    G = obj(c, 0x110, {0x100: pystub(c, 1, this=True, ret=cntrec), 0xfc: e.stub_fn('s0fc', s0fc)})
    X = rnd(c, 0x40)
    e.w32(X + 0x18, G)
    so = sysobj(c)
    e.w32(so + 0x1aa3, X)
    owner = rnd(c, 0x80)
    e.w32(owner + 0x6c, 0 if r.random() < 0.15 else r.getrandbits(32) | 1)
    d = rnd(c, 0x40)
    e.w32(d + 8, owner)
    e.w32(d + 0x18, 0 if r.random() < 0.4 else rnd(c, 0x40))
    return [d]


S(0x44ab20, 'GUESS rebuild an animation track list', 'thiscall', None, ret=None, gen=_g44ab20, note='batch36072')
