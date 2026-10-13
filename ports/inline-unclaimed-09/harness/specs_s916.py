"""specs_s916.py - unclaimed-09 batch 8 (docs/20-unclaimed-09.md, claim 8): ZMovementAction::~ZMovementAction.

The object is 0x100 random bytes; the flags argument is random, so bit 0 is set in about half the cases. The exe's
free at 0x634273 is hooked (emu.hook): it logs its two arguments (the object pointer is a heap value, stable across
exe and port) and returns with a plain ret, since the caller pops the cdecl arguments."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _free(e2, r):
    e2.calllog.append(('Free634273', e2.arg32(0), e2.arg32(1)))
    e2.ret(argbytes=0)


def _gen(c):
    c.emu.hook(0x634273, _free)
    return [_rnd(c, 0x100), c.rng.getrandbits(32)]


S(0x487900, 'ZMovementAction::~ZMovementAction (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-09 b8; free 0x634273 hooked (unverified callee)')
