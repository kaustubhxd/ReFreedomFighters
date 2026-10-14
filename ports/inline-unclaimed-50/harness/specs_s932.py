"""specs_s932.py - batch 932: 0x5159b0 (ZVehicle::Load, thiscall, one stream arg, ret 4, returns al). The gate 0x5135c0 is stood in (thiscall, a drawn
bool; not read). The stream's slots +0x18 (two words), +0x40, +0x50, +0x6c, +0x74 (one word each) each write a drawn dword to the pointer (the
callee pops its argument(s)); the manager (g+0x9b) slot +0x58 maps the value read into the argument slot to a drawn dword. The writes into this
(+0x216 .. +0x2c3) are compared."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen(c):
    e, r = c.emu, c.rng
    ok = r.random() < 0.8

    def h5135(e, rr):
        e.calllog.append(('5135c0', e.reg('ecx') != 0, e.arg32(0) != 0))
        e.ret(eax=1 if ok else 0, argbytes=4)

    only_hooks(c, {0x5135c0: h5135})

    def sw(name, nargs):
        def h(e, rr):
            if nargs == 2:
                p, n = e.arg32(0), e.arg32(1)
                e.wbytes(p, bytes(r.getrandbits(8) for _ in range(n)))
                e.calllog.append(('s.' + name, n))
                e.ret(eax=0, argbytes=8)
            else:
                p = e.arg32(0)
                e.w32(p, r.getrandbits(32))
                e.calllog.append(('s.' + name, p != 0))
                e.ret(eax=0, argbytes=4)
        return h

    stream = vt_object(c, 0x40, {0x18: sw('18', 2), 0x40: sw('40', 1), 0x50: sw('50', 1), 0x6c: sw('6c', 1), 0x74: sw('74', 1)},
                       nslots=0x100, name='stream')

    def m58(e, rr):
        e.calllog.append(('mgr.58', e.arg32(0)))
        e.ret(eax=r.getrandbits(32), argbytes=4)

    mgr = vt_object(c, 0x40, {0x58: m58}, nslots=0x100, name='mgr')
    g = rnd(c, 0x1b00)
    e.w32(g + 0x9b, mgr)
    e.w32(0x70039c, g)
    self = rnd(c, 0x400)
    return [self, stream]


S(0x5159b0, 'ZVehicle::Load (named; gate 5135c0 stood in)', 'thiscall', None, ret='al', gen=_gen, note='area50 batch932 (core slice)')
