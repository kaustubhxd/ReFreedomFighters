"""specs_s66013.py - cascade s4 batch 66013: 0x4dad20 (/GS-protected: age and clear the flagged entries of a registry list)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec


def _g4dad20(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, this=True)
    hook_rec(c, 0x4dd3d0, 0, this=True)

    def mc(em, rr):
        d, s_, n = em.arg32(0), em.arg32(1), em.arg32(2)
        em.calllog.append(('memcpy', n))
        if n:
            em.wbytes(d, bytes(em.rbytes(s_, n)))
        em.ret(eax=d, argbytes=0)
    e.hook(0x634d22, mc)
    pool = []
    for _ in range(4):
        o = e.alloc(0x80, 8)
        e.w32(o + 0x3c, r.choice([0, 0x2000000, 0x2000000, 0x2000001]))
        e.wbytes(o + 0x58, bytes([r.choice([1, 2, 5, 0])]))
        e.w32(o + 0x68, r.choice([1, 2, 3]))
        pool.append(o)
    lists = {}
    for k in (1, 2, 3, 7):
        lst = [r.choice(pool) for _ in range(r.choice([0, 1, 2, 3]))]
        arr = e.alloc(4 * 4 + 4, 4)
        for i, o in enumerate(lst):
            e.w32(arr + 4 * i, o)
        e.w32(arr + 4 * len(lst), pool[1])
        lists[k] = (arr, len(lst))
    k0 = r.choice([1, 2, 3, 7])
    me = e.alloc(0x80, 8)
    e.w32(me + 0x68, k0)
    e.wbytes(me + 0x58, bytes([r.choice([0, 3])]))

    def s8(em, rr):
        p, key = em.arg32(0), em.arg32(1)
        arr, n = lists.get(key, (0, 0))
        em.calllog.append(('slot8', key, n))
        em.w32(p, n)
        em.ret(eax=arr, argbytes=8)
    m = obj(c, 0x20, {8: e.stub_fn('slot8', s8)})
    so = sysobj(c, table_size=0x5e00)
    tab = int.from_bytes(bytes(e.rbytes(so + 0x9b, 4)), 'little')
    e.w32(tab + 0x5d35, 0 if r.random() < 0.1 else m)
    return [me]


S(0x4dad20, 'GUESS /GS age and clear flagged registry entries', 'thiscall', None, ret=None, gen=_g4dad20, note='batch66013')
