"""specs_s954.py - area 50 batch 954 (residue 16): 0x50a380 (thiscall, no args, plain ret; SEH-framed in the exe, the frame is not reproduced; the
body is). The global at 0x701128 is drawn zero or not. Stand-ins (logged): 0x59a9b0 (thiscall: ECX = the local, one arg 0x32; logs the arg and the
three dwords of the local), this's slot +0x1c (thiscall, one arg; logs the three dwords it points to) and 0x4ff9d0 (thiscall, no args; logs)."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen(c):
    e, r = c.emu, c.rng

    def h59a(e, rr):
        p = e.arg32(1) if False else e.reg('ecx')
        e.calllog.append(('59a9b0', e.arg32(0), tuple(e.r32(p + 4 * k) for k in range(3))))
        e.ret(eax=0, argbytes=4)

    def h4ff(e, rr):
        p = e.reg('ecx')
        e.calllog.append(('4ff9d0', tuple(e.r32(p + 4 * k) for k in range(3))))
        e.ret(eax=0, argbytes=0)

    def h1c(e, rr):
        p = e.arg32(0)
        e.calllog.append(('self.1c', e.reg('ecx') != 0, tuple(e.r32(p + 4 * k) for k in range(3))))
        e.ret(eax=0, argbytes=4)

    only_hooks(c, {0x59a9b0: h59a, 0x4ff9d0: h4ff})
    e.w32(0x701128, 0 if r.random() < 0.6 else r.getrandbits(32))
    self = vt_object(c, 0x100, {0x1c: h1c}, nslots=0x100, name='self')
    return [self]


S(0x50a380, 'init local and call slot 0x1c (no name in map; SEH frame not reproduced; 59a9b0 and 4ff9d0 stood in)', 'thiscall', None, gen=_gen, note='area50 batch954 (residue 16)')
