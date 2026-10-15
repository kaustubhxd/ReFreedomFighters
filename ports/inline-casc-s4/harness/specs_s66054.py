"""specs_s66054.py - cascade s4 batch 66054: 0x5c8e00 (attach a controller to its object, pre-release matching children, bind two views)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g5c8e00(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    nch = r.choice([0, 1, 2, 3])
    kids = []
    for i in range(nch):
        k = e.alloc(0x70, 8)
        if r.random() < 0.7:
            w = e.alloc(0x20, 8)
            ty = e.alloc(0x40, 8)
            e.w32(ty + 0x23, r.choice([0, 0x100000, 0x1, 0x300000]))
            e.w32(w + 0xc, ty)
            e.w32(k + 0x54, w)
        else:
            e.w32(k + 0x54, 0)
        kids.append(k)
    nxt = {k: (kids[i + 1] if i + 1 < len(kids) else 0) for i, k in enumerate(kids)}
    names = {k: rnd(c, 8) for k in kids}
    seq = [r.choice([0, 1, 5]) for _ in range(4)]
    st = {'i': 0}

    def nm(em, rr):
        em.calllog.append(('name', em.reg('ecx')))
        em.ret(eax=names[em.reg('ecx')], argbytes=0)

    def mt(em, rr):
        em.calllog.append(('match', em.reg('ecx'), em.reg('edx')))
        em.ret(eax=seq[min(st['i'], 3)], argbytes=0)
        st['i'] += 1

    def nx(em, rr):
        em.calllog.append(('next', em.reg('ecx')))
        em.ret(eax=nxt[em.reg('ecx')], argbytes=0)
    e.hook(0x4dc110, nm)
    e.hook(0x4cc850, mt)
    e.hook(0x4db520, nx)
    hook_rec(c, 0x4db860, 1, this=True)
    h = obj(c, 0x30, {0x2f0: pystub(c, 3, this=True)})
    o = obj(c, 0x30, {0x2c4: pystub(c, 2, this=True, ret=h)})
    pa, pb = rnd(c, 8), rnd(c, 8)
    ctrl = obj(c, 0x80, {0x25c: pystub(c, 2, this=True, ret=lambda em, k, _v=[r.choice([pa, 0]), r.choice([pb, 0])]: _v[k % 2])})
    e.w32(ctrl + 0x54, kids[0] if kids else 0)

    def find(em, rr):
        em.calllog.append(('tab.slot58', em.arg32(0)))
        em.ret(o, 4)

    def mk4c(em, rr):
        em.calllog.append(('tab.slot4c', em.arg32(0)))
        em.ret(eax=(em.arg32(0) * 3 + 7) & 0xffffffff, argbytes=4)
    so = sysobj(c, table_slots={0x58: e.stub_fn('find', find), 0x4c: e.stub_fn('mk4c', mk4c)})
    tab = int.from_bytes(bytes(e.rbytes(so + 0x9b, 4)), 'little')
    e.w32(tab + 0xadc, rnd(c, 8))
    t = e.alloc(0x90, 8)
    e.wbytes(t, bytes(r.getrandbits(8) for _ in range(0x90)))
    e.w32(t + 0x44, ctrl)
    return [t]


S(0x5c8e00, 'GUESS attach a controller and bind views', 'thiscall', None, ret=None, gen=_g5c8e00, note='batch66054')
