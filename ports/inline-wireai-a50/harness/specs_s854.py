"""specs_s854.py - area 50, batch 854: 0x4fc710 (name GUESS), thiscall, no args.
Stand-ins (hooked, logged): 0x4fd5d0 (the render-manager word table; it writes nothing here). The settings object (render
manager vt +0x138) answers floats by name (vt +0x84; some are exactly zero, the exe's compare-with-zero branches), a
three-dword block (vt +0x9c, or 0), and a dword (vt +0x88). The sub-object at this+0x44 logs its setters (vt +0x214,
+0x218, +0x21c, +0x220, +0x224). The engine's object (vt +0xbc) gives Y; Y's vt +0x58 returns a float (st0). The debug
object at engine+0x1907 is present in some cases (vt +0x0c, logged)."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen(c):
    e, r = c.emu, c.rng
    fin = lambda x: x if x == x and abs(x) < 1e6 else 0.0

    def val():
        return 0.0 if r.random() < 0.35 else fin(c.fv(-5, 5))

    names = [0x6922bc, 0x6922c8, 0x69c208, 0x6954e8, 0x6954f8]
    fv_by_name = {n: val() for n in names}
    blk = rnd(c, 16)
    for i in range(3):
        e.w32(blk + 4 * i, r.randint(0, 255))
    has_blk = r.random() < 0.7
    dw = r.getrandbits(32)
    yval = fin(c.fv(-3, 3))
    st = {}

    def s84(e, rr):
        name, out = e.arg32(0), e.arg32(1)
        e.wf32(out, fv_by_name.get(name, 0.0))
        e.calllog.append(('set.84', name))
        e.ret(eax=0, argbytes=8)

    def s9c(e, rr):
        e.calllog.append(('set.9c', e.arg32(0), e.arg32(1)))
        e.ret(eax=blk if has_blk else 0, argbytes=8)

    def s88(e, rr):
        name, out = e.arg32(0), e.arg32(1)
        e.w32(out, dw)
        e.calllog.append(('set.88', name))
        e.ret(eax=0, argbytes=8)

    def mgr138(e, rr):
        e.calllog.append(('mgr.138',))
        e.ret(eax=sett, argbytes=0)

    def setter(name):
        def h(e, rr):
            e.calllog.append((name, e.arg32(0)))                 # the float argument as its bits
            e.ret(eax=0, argbytes=4)
        return h

    def dbg0c(e, rr):
        e.calllog.append(('dbg.0c', e.arg32(0), e.arg32(1), e.arg32(2)))
        e.ret(eax=0, argbytes=12)

    def y58(e, rr):
        e.calllog.append(('y.58', e.arg32(0), e.arg32(1)))
        e.ret(eax=0, argbytes=8, st0=yval)

    def ybc(e, rr):
        e.calllog.append(('eng.bc',))
        e.ret(eax=Y, argbytes=0)

    def stub4fd5(e, rr):
        e.calllog.append(('stand.4fd5d0', e.reg('ecx')))
        e.ret(eax=0, argbytes=0)

    only_hooks(c, {0x4fd5d0: stub4fd5})
    sett = vt_object(c, 0x40, {0x84: s84, 0x9c: s9c, 0x88: s88}, nslots=0x100, name='settings')
    mgr = vt_object(c, 0x40, {0x138: mgr138}, nslots=0x140, name='render')
    A = vt_object(c, 0x200, {0x214: setter('A.214'), 0x218: setter('A.218'), 0x21c: setter('A.21c'),
                             0x220: setter('A.220'), 0x224: setter('A.224')}, nslots=0x240, name='sub')
    Y = vt_object(c, 0x40, {0x58: y58}, nslots=0x60, name='Y')
    g_vt = vt_object(c, 0x1b00, {0xbc: ybc}, nslots=0x100, name='engine')   # the engine object
    e.w32(0x70039c, g_vt)
    e.w32(g_vt + 0x9b, mgr)
    if r.random() < 0.6:
        dbg = vt_object(c, 0x40, {0x0c: dbg0c}, nslots=0x20, name='dbg')
        e.w32(g_vt + 0x1907, dbg)
    else:
        e.w32(g_vt + 0x1907, 0)
    self = vt_object(c, 0x200, {}, nslots=0x20, name='ctl')
    e.w32(self + 0x44, A)
    e.w32(self + 0x6e, 0 if r.random() < 0.5 else r.getrandbits(32))
    return [self]


S(0x4fc710, 'Init4fc710 (GUESS name)', 'thiscall', None, gen=_gen, note='area50 batch854')
