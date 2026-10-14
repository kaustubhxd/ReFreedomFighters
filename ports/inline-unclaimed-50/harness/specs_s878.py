"""specs_s878.py - area 50, batch 878: 0x5b23d0 CFFTargetList::Init (ZGEOM*, DBREAD&), thiscall, ret 8.
Recorded/stood in: the DBREAD word reader 0x4e5e60 (a generation-time value), the render manager's object (vt +0x25c returns an
object or null; vt +0x294 returns an object), the objects' vtable slots (+0x154, +0x124, +0x218, logged), 0x4dc630 (stood in, logged),
and this's vt +0x58 (logged)."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen(c):
    e, r = c.emu, c.rng
    flag = r.choice([0, 1, 7])
    got_obj = r.random() < 0.5

    def hdb(e, rr):
        e.calllog.append(('db.u32', flag))
        e.ret(eax=flag, argbytes=0)

    def v25c(e, rr):
        e.calllog.append(('mgr.25c', e.arg32(0), e.arg32(1)))
        e.ret(eax=objA if got_obj else 0, argbytes=8)

    def v294(e, rr):
        e.calllog.append(('mgr.294', e.arg32(0), e.arg32(1), e.arg32(2), e.arg32(3)))
        e.ret(eax=objB, argbytes=16)

    def logv(name, n):
        def h(e, rr):
            e.calllog.append((name,) + tuple(e.arg32(k) for k in range(n)))
            e.ret(eax=0, argbytes=4 * n)
        return h

    def h4dc(e, rr):
        e.calllog.append(('4dc630', e.reg('ecx'), e.arg32(0), e.arg32(1)))
        e.ret(eax=0, argbytes=8)

    only_hooks(c, {0x4e5e60: hdb, 0x4dc630: h4dc})
    mgrobj = vt_object(c, 0x1000, {0x25c: v25c, 0x294: v294}, nslots=0x100, name='rm_obj')
    mgr = rnd(c, 0x1000)
    e.w32(mgr + 0xadc, mgrobj)
    g = rnd(c, 0x1b00)
    e.w32(g + 0x9b, mgr)
    e.w32(0x70039c, g)
    objA = vt_object(c, 0x80, {0x218: logv('A.218', 1)}, nslots=0x100, name='A')
    objB = vt_object(c, 0x80, {0x154: logv('B.154', 0), 0x124: logv('B.124', 4), 0x218: logv('B.218', 1)},
                     nslots=0x100, name='B')
    e.w32(objA + 8, rnd(c, 0x20)) if False else None
    e.w32(objB + 8, rnd(c, 0x20))
    self = vt_object(c, 0x100, {0x58: logv('self.58', 0)}, nslots=0x40, name='targets')
    geom = rnd(c, 0x40)
    db = rnd(c, 0x40)
    return [self, geom, db]


S(0x5b23d0, 'CFFTargetList::Init (DBREAD reader)', 'thiscall', None, gen=_gen, note='area50 batch878')
