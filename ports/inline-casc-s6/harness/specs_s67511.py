"""specs_s67511.py - cascade s6 batch 67511 (0x4ac310, thiscall(), plain ret). Engine object (sysobj with slots 0x14 / 0x10, byte +0x9b7, table object with slots 0x138 -> resolver
with slot 0x88 writing scripted ids (zero ends early) and 0x58 -> objects or null); this slot 0x8c; embedded iterator at +0x11a (slots 0x4c / 0x5c with a scripted count run); objects with
slot 0x1e0 / 0x324. Every iterator call is logged through calllog."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, pystub


def _g4ac310(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    ids = [r.choice([0, 7, 9]) if r.random() < 0.2 else r.randrange(1, 60) for _ in range(2)]
    present = [r.random() < 0.9 for _ in range(2)]

    def s88(em, k):
        em.calllog.append(('s88', em.arg32(0), 1))
        em.w32(em.arg32(1), ids[min(k, 1)])
    resolver = obj(c, 0x20, {0x88: pystub(c, 2, this=True, stackmark=(1,), side=s88)})
    objs = [obj(c, 0x20, {0x1e0: pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, 1, 1, 0x100])), 0x324: pystub(c, 1, this=True)}) for _ in range(4)]
    plain = obj(c, 0x20, {0x1e0: pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, 1])), 0x324: pystub(c, 1, this=True)})

    def t58(em, k):
        a = em.arg32(0)
        if a in ids:
            i = ids.index(a)
            return plain if present[i] else 0
        return r.choice(objs + [0])
    so = sysobj(c, slots={0x14: pystub(c, 0, this=True), 0x10: pystub(c, 0, this=True)},
                table_slots={0x138: pystub(c, 0, this=True, ret=resolver), 0x58: pystub(c, 1, this=True, ret=t58)}, table_size=0x140)
    e.wbytes(so + 0x9b7, bytes([r.choice([0, 1, 1])]))
    runs = [r.choice([0, 1, 2, 3]) for _ in range(2)]
    st = {'name': 0, 'left': 0}

    def s4c(em, k):
        em.calllog.append(('s4c', 1))
        st['left'] = runs[min(st['name'], 1)]
        st['name'] += 1

    def s5c(em, k):
        em.calllog.append(('s5c', st['left']))
        em.w32(em.arg32(0), st['left'])
        if st['left'] > 0:
            st['left'] -= 1
    itvt = e.alloc(0x80, 4)
    e.w32(itvt + 0x4c, pystub(c, 1, this=True, stackmark=(0,), side=s4c))
    e.w32(itvt + 0x5c, pystub(c, 1, this=True, stackmark=(0,), side=s5c, ret=lambda em, k: r.randrange(1, 40)))
    t = obj(c, 0x140, {0x8c: pystub(c, 1, this=True)})
    e.w32(t + 0x11a, itvt)
    return [t]


S(0x4ac310, 'GUESS apply_names', 'thiscall', None, ret=None, gen=_g4ac310, note='batch67511')
