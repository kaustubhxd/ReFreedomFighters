"""specs_s66079.py - cascade s4 batch 66079: 0x4f2a30 (find the first resolvable entry of a list and report it)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, pystub, reftab_vt


def _g4f2a30(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 2, 3])
    ids = [0x500 + i for i in range(n)]
    objs = {i: (rnd(c, 8) if r.random() < 0.4 else 0) for i in ids}
    base = reftab_vt(c, list(ids))

    def find(em, rr):
        v = em.arg32(0)
        em.calllog.append(('tab.slot58', v))
        em.ret(objs.get(v, 0), 4)

    def mk4c(em, rr):
        em.calllog.append(('tab.slot4c', em.arg32(0)))
        em.ret(eax=(em.arg32(0) * 3 + 1) & 0xffffffff, argbytes=4)
    sysobj(c, table_slots={0x58: e.stub_fn('find', find), 0x4c: e.stub_fn('mk4c', mk4c)})
    vt = e.alloc(0x100, 4)
    for off, src in ((0x44, 0x44), (0x54, 0x4c), (0x6c, 0x5c)):
        e.w32(vt + off, int.from_bytes(bytes(e.rbytes(base + src, 4)), 'little'))
    e.w32(vt + 4, pystub(c, 1, this=True))
    t = obj(c, 0x700, {0x2dc: pystub(c, 4, this=True)})
    e.w32(t + 0xcb, vt)
    e.wbytes(t + 0x63b, bytes([r.choice([0, 3])]))
    return [t, r.choice([0, 7, 0x1234])]


S(0x4f2a30, 'GUESS find the first resolvable list entry and report it', 'thiscall', None, ret=None, gen=_g4f2a30, note='batch66079')
