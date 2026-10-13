"""specs_s938.py - batch 938: 0x5135c0 (ZMoveOnSpline::Load, thiscall, one stream arg, ret 4, returns al = 1). Stand-ins (logged): the gate 0x440e10 (thiscall;
a drawn bool), 0x523710 (thiscall: ECX = this+0x5c, one arg), 0x511bc0 (fastcall: ECX = stream, EDX = pointer), 0x4e78c0 (thiscall: ECX = this+0x144, one arg).
The stream's slots write drawn values (dword slots +0x40, +0x48, +0x50, +0x68, +0x6c, +0x74, +0x70; the +0x18 slot writes its byte count); the manager
slot +0x58 maps the local to a drawn dword. this's slot +0x2e4 (no args) logs."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen(c):
    e, r = c.emu, c.rng
    ok = r.random() < 0.8

    def hgate(e, rr):
        e.calllog.append(('440e10', e.reg('ecx') != 0, e.arg32(0) != 0))
        e.ret(eax=1 if ok else 0, argbytes=4)

    def h523(e, rr):
        e.calllog.append(('523710', e.reg('ecx') != 0, e.arg32(0) != 0))
        e.ret(eax=0, argbytes=4)

    def h511(e, rr):
        e.calllog.append(('511bc0', e.reg('ecx') != 0, e.reg('edx') != 0))
        e.ret(eax=0, argbytes=0)

    def h4e7(e, rr):
        e.calllog.append(('4e78c0', e.reg('ecx') != 0, e.arg32(0) != 0))
        e.ret(eax=0, argbytes=4)

    only_hooks(c, {0x440e10: hgate, 0x523710: h523, 0x511bc0: h511, 0x4e78c0: h4e7})

    def dw(name):
        def h(e, rr):
            e.w32(e.arg32(0), r.getrandbits(32))
            e.calllog.append(('s.' + name, e.arg32(0) != 0))
            e.ret(eax=0, argbytes=4)
        return h

    def h18(e, rr):
        p, n = e.arg32(0), e.arg32(1)
        e.wbytes(p, bytes(r.getrandbits(8) for _ in range(n)))
        e.calllog.append(('s.18', n))
        e.ret(eax=0, argbytes=8)

    def h70(e, rr):          # slot +0x70 takes a dword VALUE (pushed as push dword ptr): log it, write nothing
        e.calllog.append(('s.70', e.arg32(0)))
        e.ret(eax=0, argbytes=4)

    stream = vt_object(c, 0x40, {0x18: h18, 0x40: dw('40'), 0x48: dw('48'), 0x50: dw('50'), 0x68: dw('68'), 0x6c: dw('6c'),
                                  0x70: h70, 0x74: dw('74')}, nslots=0x100, name='stream')

    def m58(e, rr):
        e.calllog.append(('mgr.58', e.arg32(0)))
        e.ret(eax=r.getrandbits(32), argbytes=4)

    mgr = vt_object(c, 0x40, {0x58: m58}, nslots=0x100, name='mgr')
    g = rnd(c, 0x1b00)
    e.w32(g + 0x9b, mgr)
    e.w32(0x70039c, g)

    def h2e4(e, rr):
        e.calllog.append(('self.2e4',))
        e.ret(eax=0, argbytes=0)

    self = vt_object(c, 0x800, {0x2e4: h2e4}, nslots=0x200, name='self')
    e.w32(self + 0x5c, rnd(c, 0x40))
    return [self, stream]


S(0x5135c0, 'ZMoveOnSpline::Load (named; gate 440e10 stood in)', 'thiscall', None, ret='al', gen=_gen, note='area50 batch938 (core slice)')
