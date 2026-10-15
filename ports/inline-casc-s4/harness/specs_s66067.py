"""specs_s66067.py - cascade s4 batch 66067: 0x456d10 (read a table of ids from a stream and wire the chained records to their objects)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec


def _g456d10(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x45f3c0, 1, this=True)
    n = r.choice([0, 1, 2, 3])
    vals = [0x300 + i for i in range(8)]
    cnt = {'k': 0}

    def s40(em, rr):                      # s->slot 0x40 (out) ret 4
        p = em.arg32(0)
        k = cnt['k']
        cnt['k'] += 1
        em.calllog.append(('s40', k, p if 0x20000000 <= p < 0x30000000 else 0))
        em.w32(p, n if k == 0 else (vals[k % 8] if k % 2 else 0x11))
        em.ret(eax=0, argbytes=4)
    s = obj(c, 0x30, {0x40: e.stub_fn('s40', s40)})
    nrec = 4
    recs = e.alloc(0x94c * nrec + 0x20, 8)
    for i in range(nrec):
        e.w32(recs + 0x94c * i, r.choice([0, 0] + list(range(i + 2, nrec + 1))))
    objs = {}
    for v in vals + [0x11, 0x12, 0x21]:
        o = e.alloc(0x100, 8)
        e.w32(o + 0xdd, r.getrandbits(32))
        objs[v] = o

    def find(em, rr):
        v = em.arg32(0)
        em.calllog.append(('tab.slot58', v))
        em.ret(objs.get(v) or objs[0x11], 4)

    def s4c(em, rr):
        em.calllog.append(('s4c', em.arg32(0)))
        em.ret(eax=0xabc0000 | r.getrandbits(8), argbytes=4)
    sysobj(c, table_slots={0x58: e.stub_fn('find', find), 0x4c: e.stub_fn('s4c', s4c)})
    t = e.alloc(0x900, 8)
    for i in range(0x100):
        pass
    for i in range(6):
        e.w32(t + 0x1d + 8 * i, r.choice([0, 0x11, 0x12, 0x21]) if i > 2 else 0x11)
        e.w32(t + 0x21 + 8 * i, r.choice([0, 1, 2, 3, 4]))
    e.w32(t + 0x1d + 8 * 6, 0)
    e.w32(t + 0x81d, recs)
    return [t, s]


S(0x456d10, 'GUESS read a table of ids from a stream and wire chained records', 'thiscall', None, ret='al', gen=_g456d10, note='batch66067')
