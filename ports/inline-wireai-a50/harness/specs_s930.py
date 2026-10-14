"""specs_s930.py - batch 930: 0x477ff0 (ZActor::ClassInit, thiscall, no args). The stack cookie check (0x633654) is NOT reproduced (tagged).
The engine object g (0x70039c): slot +0x1c0 (two args, returns a float in st0, drawn). this's slots: +0x3c (one arg), +0x84 (one arg; writes a drawn
dword into the 0x660 block), +0x80 (two args; writes a drawn dword into the local and logs), +0x5bc (no args), +0x5ac (two args). Stand-ins:
0x472ff0 (thiscall), 0x4e09e0 (fastcall: ECX, EDX; logs both), 0x477740 (thiscall, two words)."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen(c):
    e, r = c.emu, c.rng
    rv = r.uniform(-4.0, 4.0)
    v84 = r.getrandbits(32)
    v80 = r.getrandbits(32)

    def h1c0(e, rr):
        e.calllog.append(('g.1c0', e.arg32(0), e.arg32(1)))
        e.ret(st0=rv, argbytes=8)

    g = vt_object(c, 0x1b00, {0x1c0: h1c0}, nslots=0x100, name='g')

    def h3c(e, rr):
        e.calllog.append(('self.3c', e.arg32(0)))
        e.ret(eax=0, argbytes=4)

    def h84(e, rr):
        e.w32(e.arg32(0), v84)
        e.calllog.append(('self.84', e.arg32(0) != 0))
        e.ret(eax=0, argbytes=4)

    def h80(e, rr):
        e.w32(e.arg32(0), v80)
        e.calllog.append(('self.80', e.arg32(1) != 0))
        e.ret(eax=0, argbytes=8)

    def h5bc(e, rr):
        e.calllog.append(('self.5bc',))
        e.ret(eax=0, argbytes=0)

    def h5ac(e, rr):
        e.calllog.append(('self.5ac', e.arg32(0), e.arg32(1)))
        e.ret(eax=0, argbytes=8)

    self = vt_object(c, 0x1000, {0x3c: h3c, 0x84: h84, 0x80: h80, 0x5bc: h5bc, 0x5ac: h5ac}, nslots=0x400, name='self')
    e.w32(0x70039c, g)

    def h472(e, rr):
        e.calllog.append(('472ff0', e.reg('ecx') == self))
        e.ret(eax=0, argbytes=0)

    def h4e09(e, rr):
        e.calllog.append(('4e09e0', e.reg('ecx') != 0, e.reg('edx') != 0, e.r32(e.reg('edx'))))
        e.ret(eax=0, argbytes=0)

    def h477(e, rr):
        e.calllog.append(('477740', e.reg('ecx') == self, e.arg32(0), e.arg32(1)))
        e.ret(eax=0, argbytes=8)

    only_hooks(c, {0x472ff0: h472, 0x4e09e0: h4e09, 0x477740: h477})
    e.w32(0x70039c, g)
    e.w32(self + 0x664, r.getrandbits(32))     # overwritten by the zero stores in the exe before the reads
    return [self]


S(0x477ff0, 'ZActor::ClassInit (named; cookie not reproduced)', 'thiscall', None, ret=None, gen=_gen, note='area50 batch930 (core slice)')
