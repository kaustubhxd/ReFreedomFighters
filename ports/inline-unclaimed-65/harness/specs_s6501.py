"""specs_s6501.py - unclaimed-65 batch 1 (docs/20-unclaimed-65.md, claim 1): two deleting destructors. Callees are logging stubs
(thiscall with no args: 0x43de70, 0x480fd0, 0x4878d0; cdecl: 0x45c510 (1 arg), 0x4690b0 (2 args), 0x634273 (2 args)).
Translation cache flushed after the patches. No faulting cases allowed."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _flush_code(c):
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _logger(name, nargs, cdecl=False):
    def h(e, r):
        args = tuple(e.arg32(k) for k in range(nargs))
        e.calllog.append((name, e.reg('ecx'), args))
        e.ret(eax=0, argbytes=0 if cdecl else 4 * nargs)
    return h


def _setup(c):
    from serial_stubs import patch
    patch(c, 0x43de70, c.emu.stub_fn('0x43de70', _logger('0x43de70', 0)))
    patch(c, 0x45c510, c.emu.stub_fn('0x45c510', _logger('0x45c510', 1, cdecl=True)))
    patch(c, 0x4690b0, c.emu.stub_fn('0x4690b0', _logger('0x4690b0', 2, cdecl=True)))
    patch(c, 0x4878d0, c.emu.stub_fn('0x4878d0', _logger('0x4878d0', 0)))
    patch(c, 0x480fd0, c.emu.stub_fn('0x480fd0', _logger('0x480fd0', 0)))
    patch(c, 0x634273, c.emu.stub_fn('0x634273', _logger('0x634273', 2, cdecl=True)))
    _flush_code(c)


def _gen(c):
    return [_rnd(c, 0x800), c.rng.getrandbits(32)]


S(0x573760, 'ZMapHelper::~ZMapHelper (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen, setup=_setup,
  note='unclaimed-65 batch 1 (residue 18); base 0x43de70; flag bit 0 -> bit 2 ? 0x4690b0(this,0x2c) : 0x45c510(this)')
S(0x5e1390, 'ZFFHeroMovementCloseCombat::~ZFFHeroMovementCloseCombat (unknown) thiscall', 'thiscall', None, ret='eax',
  gen=_gen, setup=_setup, note='unclaimed-65 batch 1 (residue 17); vtable 0x6b7748; members 0x480fd0 x4; base 0x4878d0; delete 0x611')
