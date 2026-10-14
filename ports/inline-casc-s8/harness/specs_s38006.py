"""specs_s38006.py - cascade s8 batch 38006: 0x59ae60 (dispatch by interned name id). Name table object (engine +0x9b) slot 0x114 is a logging stub mapping each of the six
name strings to a distinct u16 id; the id argument is one of them (or unrelated). Other slots and callees are recording hooks; the helper chain for the last case writes
random data into the callee's stack locals (recorded through deref in the final call). The null-out write of the second case faults on both sides, so out is never null there."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

STRS = [0x6ad354, 0x6a5c68, 0x6a5c58, 0x6a5c78, 0x6add1c, 0x6add3c]


def _g59ae60(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))
    ids = r.sample(range(1, 0x10000), 6)
    idmap = dict(zip(STRS, ids))

    def q(em, res_):
        a = [em.arg32(i) for i in range(4)]
        em.calllog.append(('q', em.reg('ecx'), tuple(a)))
        em.ret(eax=(r.getrandbits(16) << 16) | idmap.get(a[0], 0), argbytes=16)
    helper_w = rnd(c, 0x20)
    e.w32(helper_w + 8, rnd(c, 0x20))
    helper = obj(c, 0x20, {0x20: pystub(c, 0, this=True, ret=helper_w)})
    pickres = r.choice([0.0, 0.7, 1.0])
    slot58 = pystub(c, 1, this=True, ret=lambda em, k: ((helper if r.random() < pickres else 0) if k % 2 == 1 else r.getrandbits(32)))
    slot138 = pystub(c, 0, this=True, ret=lambda em, k: r.getrandbits(32))
    names = obj(c, 0x20, {0x114: e.stub_fn('name id', q), 0x58: slot58, 0x138: slot138})
    so = sysobj(c)
    e.w32(so + 0x9b, names)
    me = rnd(c, 0x13300)
    e.w32(me + 0x411, r.getrandbits(32))
    hook_rec(c, 0x5adeb0, 1, this=True, pop=4, ret=lambda em, k: r.getrandbits(32))
    hook_rec(c, 0x5ae930, 2, this=True, pop=8, deref={0: 2})
    hook_rec(c, 0x59b350, 1, this=True, pop=4, ret=lambda em, k: r.getrandbits(32))

    def side48(em, k):
        p = em.reg('ecx')
        em.calllog.append(('loc', em.r32(p), em.r32(p + 4)))
    hook_rec(c, 0x48aad0, 0, this='mark', ret=lambda em, k: r.getrandbits(32), side=side48)

    def side4d(em, k):
        em.wbytes(em.arg32(0), bytes(r.getrandbits(8) for _ in range(0x24)))
        em.wbytes(em.arg32(1), bytes(r.getrandbits(8) for _ in range(4)))
    hook_rec(c, 0x4db2c0, 2, this=True, pop=8, stackmark=(0, 1), side=side4d)
    hook_rec(c, 0x5b1760, 4, this=True, pop=16, deref={2: 1, 3: -0x24})
    k = r.random()
    if k < 0.85:
        which = r.randrange(6)
        idv = ids[which]
    else:
        which = -1
        idv = r.randrange(0x10000)
    idv |= r.getrandbits(16) << 16 if r.random() < 0.3 else 0
    out = rnd(c, 0x20)
    if which in (1, 2, 5) and r.random() < 0.3:
        e.w32(out + 4, 0)
    if which == 2 and r.random() < 0.2:
        out = 0
    if which == 5 and r.random() < 0.2:
        out = r.choice([0, out])
    return [me, idv, out]


S(0x59ae60, 'GUESS getter dispatch by name id', 'thiscall', None, ret='eax', gen=_g59ae60, note='batch38006')
