"""specs_s926.py - batch 926: 0x569590 (thiscall, one stack arg (id), ret 4, returns al). Stand-ins (logged): 0x562c20 (thiscall; drawn bool),
0x563500 (thiscall, no args), 0x561f10 and 0x562af0 (thiscall, one arg), the CRT import atoi (0x6762d8, cdecl; reads the string the value points to),
the manager's slots +0xa4 (no args), +0xa0 (one arg), +0x134 (returns an object X), X's slot +0x68 (three words, callee pops 12), and the engine
object g's slot +0x5c (ECX = g; two words; may write a new string pointer through the second word; callee pops 8). The argument is drawn among
1, 0x8ae, a string pointer ("2222", "5", "100", "300000000") and a random value."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen(c):
    e, r = c.emu, c.rng
    ok = r.random() < 0.2
    gwrite = r.random() < 0.5
    newp = e.cstr(r.choice(['7', '42']))

    def h620(e, rr):
        e.calllog.append(('562c20', e.reg('ecx') != 0, e.arg32(0)))
        e.ret(eax=1 if ok else 0, argbytes=4)

    def h500(e, rr):
        e.calllog.append(('563500', e.reg('ecx') != 0))
        e.ret(eax=0, argbytes=0)

    def h1f10(e, rr):
        e.calllog.append(('561f10', e.reg('ecx') != 0, e.arg32(0)))
        e.ret(eax=0, argbytes=4)

    def h2af(e, rr):
        e.calllog.append(('562af0', e.reg('ecx') != 0, e.arg32(0)))
        e.ret(eax=0, argbytes=4)

    def atoi(e, rr):
        v = e.arg32(0) // 10          # the value depends on the pointer, so the equality boundary (local == 10 * value) can be hit
        e.calllog.append(('atoi', v))
        e.ret(eax=v, argbytes=0)

    e.stub_import('atoi', atoi)

    def h68(e, rr):
        e.calllog.append(('x.68', e.arg32(0), e.arg32(1), e.arg32(2)))
        e.ret(eax=0, argbytes=12)

    X = vt_object(c, 0x40, {0x68: h68}, nslots=0x40, name='X')

    def ha4(e, rr):
        e.calllog.append(('mgr.a4',))
        e.ret(eax=0, argbytes=0)

    def ha0(e, rr):
        e.calllog.append(('mgr.a0', e.arg32(0)))
        e.ret(eax=0, argbytes=4)

    def h134(e, rr):
        e.calllog.append(('mgr.134',))
        e.ret(eax=X, argbytes=0)

    mgr = vt_object(c, 0x40, {0xa4: ha4, 0xa0: ha0, 0x134: h134}, nslots=0x60, name='mgr')

    def h5c(e, rr):
        e.calllog.append(('g.5c', e.arg32(0), e.r32(e.arg32(1)) if gwrite else 0))
        if gwrite:
            e.w32(e.arg32(1), newp)
        e.ret(eax=1 if gwrite else 0, argbytes=8)

    gobj = vt_object(c, 0x1b00, {0x5c: h5c}, nslots=0x100, name='g')
    e.w32(gobj + 0x9b, mgr)
    e.w32(0x70039c, gobj)
    only_hooks(c, {0x562c20: h620, 0x563500: h500, 0x561f10: h1f10, 0x562af0: h2af})
    e.w32(0x70039c, gobj)
    self = rnd(c, 0x80)
    arg = r.choice([1, 0x8ae, (newp // 10) * 10, (newp // 10) * 10 + 3, 0x20000050, r.getrandbits(32)])
    return [self, arg]


S(0x569590, 'run569590 (no name in map; stand-ins)', 'thiscall', None, ret='al', gen=_gen, note='area50 batch926 (dependency slice)')
