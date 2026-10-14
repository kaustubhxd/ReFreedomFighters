"""specs_s933.py - batch 933: 0x4fd5d0 (CMAINCAMERACONTROL::RegisterMessages, thiscall, no args). The manager's slot +0x114 (four words: string,
0, 0x69c54c, id; callee pops 16) is the stand-in: it logs the string, the id and returns a drawn dword whose low word is what the exe stores.
The thirteen word stores at this+0x62 .. +0x14c are compared in the heap."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen(c):
    e, r = c.emu, c.rng

    def h114(e, rr):
        e.calllog.append(('mgr.114', e.arg32(0), e.arg32(1), e.arg32(2), e.arg32(3)))
        e.ret(eax=r.getrandbits(32), argbytes=16)

    mgr = vt_object(c, 0x40, {0x114: h114}, nslots=0x100, name='mgr')
    g = rnd(c, 0x1b00)
    e.w32(g + 0x9b, mgr)
    e.w32(0x70039c, g)
    only_hooks(c, {})
    e.w32(0x70039c, g)
    self = rnd(c, 0x200)
    return [self]


S(0x4fd5d0, 'CMAINCAMERACONTROL::RegisterMessages (named)', 'thiscall', None, ret=None, gen=_gen, note='area50 batch933 (core slice)')
