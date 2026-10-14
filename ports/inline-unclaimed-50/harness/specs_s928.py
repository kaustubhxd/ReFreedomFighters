"""specs_s928.py - batch 928: 0x58b930 (ZFFHERO::AddToTargetList, thiscall, no args). The manager M (g+0x9b, then +0xadc): slot +0x25c returns
X (drawn null or not), slot +0x294 returns Y. X and Y have slot +0x218 (one arg). Y has slot +0x154 (no args) and +0x124 (four words). The
pointer at Y+8 is the ECX of 0x4dc630 (stood in: thiscall, two words, logs its ECX identity). Both branches run; logs of every call are compared."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen(c):
    e, r = c.emu, c.rng
    nul = r.random() < 0.5

    def h218(name):
        def h(e, rr):
            e.calllog.append((name + '.218', e.arg32(0) != 0))
            e.ret(eax=0, argbytes=4)
        return h

    X = vt_object(c, 0x40, {0x218: h218('x')}, nslots=0x100, name='X')

    def h154(e, rr):
        e.calllog.append(('y.154',))
        e.ret(eax=0, argbytes=0)

    def h124(e, rr):
        e.calllog.append(('y.124', e.arg32(0), e.arg32(1), e.arg32(2), e.arg32(3)))
        e.ret(eax=0, argbytes=16)

    Y = vt_object(c, 0x40, {0x154: h154, 0x124: h124, 0x218: h218('y')}, nslots=0x100, name='Y')
    Z = rnd(c, 0x20)
    e.w32(Y + 8, Z)

    def h25c(e, rr):
        e.calllog.append(('M.25c', e.arg32(0), e.arg32(1)))
        e.ret(eax=0 if nul else X, argbytes=8)

    def h294(e, rr):
        e.calllog.append(('M.294', e.arg32(0), e.arg32(1), e.arg32(2), e.arg32(3)))
        e.ret(eax=Y, argbytes=16)

    M = vt_object(c, 0x40, {0x25c: h25c, 0x294: h294}, nslots=0x100, name='M')
    mgr = rnd(c, 0x1000)
    e.w32(mgr + 0xadc, M)
    g = rnd(c, 0x1b00)
    e.w32(g + 0x9b, mgr)
    e.w32(0x70039c, g)

    def h4dc(e, rr):
        e.calllog.append(('4dc630', e.reg('ecx') == Z, e.arg32(0), e.arg32(1)))
        e.ret(eax=0, argbytes=8)

    only_hooks(c, {0x4dc630: h4dc})
    e.w32(0x70039c, g)
    self = rnd(c, 0x200)
    return [self]


S(0x58b930, 'ZFFHERO::AddToTargetList (named)', 'thiscall', None, ret=None, gen=_gen, note='area50 batch928 (core slice)')
