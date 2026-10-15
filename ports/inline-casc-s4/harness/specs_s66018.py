"""specs_s66018.py - cascade s4 batch 66018: 0x5491a0 (release two referenced entries, clearing references to unreleasable ones)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g5491a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4db860, 1, this=True)

    def mkent():
        n = r.choice([0, 1, 2, 3])
        elems = [rnd(c, 8) for _ in range(n)]
        seq = list(elems[1:]) + [0]

        def adv(em, rr):
            p = em.arg32(0)
            v = seq.pop(0) if seq else 0
            em.calllog.append(('adv', v))
            em.w32(p, v)
            em.ret(eax=0, argbytes=4)
        ty = e.alloc(0x40, 8)
        flag = r.choice([0, 0x100000, 0x100000, 0x100000, 0x300000, 0x80000])
        e.wbytes(ty + 0x23, flag.to_bytes(4, 'little'))
        o = obj(c, 0x20, {0x50: e.stub_fn('adv', adv), 0xbc: pystub(c, 1, this=True)})
        e.w32(o + 8, elems[0] if elems else 0)
        e.w32(o + 0xc, ty)
        return o
    ids = {}
    for k in (11, 22):
        ids[k] = mkent() if r.random() < 0.8 else 0

    def find(em, rr):
        v = em.arg32(0)
        em.calllog.append(('tab.slot58', v))
        em.ret(ids.get(v, 0), 4)
    sysobj(c, table_slots={0x58: e.stub_fn('find', find)})
    t = rnd(c, 0x60)
    e.w32(t + 0x4c, r.choice([11, 22, 11, 5]))
    e.w32(t + 0x50, r.choice([22, 11, 22, 5]))
    return [t]


S(0x5491a0, 'GUESS release two referenced entries', 'thiscall', None, ret=None, gen=_g5491a0, note='batch66018')
