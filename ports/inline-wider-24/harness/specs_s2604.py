"""specs_s2604.py - wider batch 2604: folded assert stubs 0x4d50c0 (cdecl, no args), 0x510bd0 (thiscall, 2 args, ret 8), 0x6368b0 (thiscall, 1 arg, ret 4).
The hook at 0x7003b0 is always set (a recorder with plain ret), so the run never faults."""
from pilot import S
from recruits_util import rnd


def _hook(c):
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert', e2.reg('ecx') if False else 0))
        e2.ret()
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))


def _plain(c):
    _hook(c)
    return []


def _this(c, n):
    _hook(c)
    return [rnd(c, 0x80)] + [c.rng.getrandbits(32) for _ in range(n)]


S(0x4d50c0, 'folded assert stub (ZLNKWHANDS, low)', 'cdecl', None, ret=None, gen=_plain, note='batch2604')
S(0x510bd0, 'folded assert stub ret 8 (ZLNKWHANDS::ControlUseTwo, low)', 'thiscall', None, ret=None, gen=lambda c: _this(c, 2), note='batch2604')
S(0x6368b0, 'folded assert stub ret 4 (ZLNKWHANDS::ControlUseOneExtra, low)', 'thiscall', None, ret=None, gen=lambda c: _this(c, 1), note='batch2604')
