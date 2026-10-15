"""specs_s66075.py - cascade s4 batch 66075: 0x5db2e0 (queue a notification record for every entry of a list that has a controller)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, reftab_vt


def _g5db2e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def alloc(em, rr):
        em.calllog.append(('alloc', em.arg32(0)))
        em.ret(eax=e.alloc(max(em.arg32(0), 16), 8), argbytes=0)
    e.hook(0x41e290, alloc)
    n = r.choice([0, 1, 2, 3])
    ids = [0x700 + i for i in range(n)]
    objs = {}

    def h90(em, rr):                      # 0x4daf90 (ecx = holder, &loc) ret 4
        loc = em.arg32(0)
        em.calllog.append(('h4daf90', em.reg('ecx')))
        for i in range(3):
            em.w32(loc + 4 * i, 0xc0 + i)
        em.ret(eax=0, argbytes=4)
    e.hook(0x4daf90, h90)

    def s84(em, rr):
        loc = em.arg32(0)
        em.calllog.append(('s84', em.reg('ecx'), bytes(em.rbytes(loc, 12))))
        em.ret(eax=0, argbytes=4)
    for i in ids:
        o = obj(c, 0x80, {0x84: e.stub_fn('s84', s84), 0x1e0: pystub(c, 1, this=True, ret=r.choice([0, 1, 0x100, 5, 0x102]))})
        e.w32(o + 0x54, r.choice([0, 5, 5]))
        e.w32(o + 8, rnd(c, 8))
        objs[i] = o

    def find(em, rr):
        v = em.arg32(0)
        em.calllog.append(('tab.slot58', v))
        em.ret(objs[v], 4)
    sysobj(c, table_slots={0x58: e.stub_fn('find', find)})
    base = reftab_vt(c, ids)
    vt = e.alloc(0x100, 4)
    for off in (0x4c, 0x5c):
        e.w32(vt + off, int.from_bytes(bytes(e.rbytes(base + off, 4)), 'little'))
    lst = e.alloc(0x20, 8)
    e.w32(lst, vt)
    holder = e.alloc(0x40, 8)
    e.w32(holder + 0x18, 0 if r.random() < 0.15 else lst)
    sink = obj(c, 0x30, {4: pystub(c, 1, this=True)})
    t = e.alloc(0x100, 8)
    e.w32(t + 0x48, holder)
    e.w32(t + 0x84, sink)
    return [t]


S(0x5db2e0, 'GUESS queue a notification record for every controlled entry', 'thiscall', None, ret=None, gen=_g5db2e0, note='batch66075')
