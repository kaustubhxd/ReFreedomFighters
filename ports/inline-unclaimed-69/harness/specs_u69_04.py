"""specs_u69_04.py - area 69, group 4 (unclaimed-69 thread): CLensFlare::CopyData. The C-runtime cast is a GUESS stub that
returns its first argument (a successful cast) and logs the type arguments."""
from pilot import S
from ckit import rnd


def _cast(e, res):
    e.calllog.append(('__RTDynamicCast', e.arg32(1), e.arg32(4)))
    e.ret(eax=e.arg32(0), argbytes=0)     # cdecl: the caller pops the five arguments


def _cfd(c):
    e = c.emu
    e.hook(0x634d2e, _cast)
    self_ = rnd(c, 0x100)
    ev = rnd(c, 0x100)
    return [self_, ev]


S(0x5d5e50, 'CLensFlare::CopyData', 'thiscall', None, ret=None, gen=_cfd,
  note='u69; __RTDynamicCast is a GUESS stub (returns its argument)')
