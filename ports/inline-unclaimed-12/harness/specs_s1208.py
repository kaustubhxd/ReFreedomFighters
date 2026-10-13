"""specs_s1208.py - unclaimed-12 batch 8 (docs/20-unclaimed-12.md, claim 8, in slice): two deleting destructors. Each sets
the vtable, calls base and member destructors (stubbed; the stubs log the object they run on), and calls operator delete
(0x634273, cdecl, stubbed) when the flag bit 0 is set. Returns this in eax."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss  # noqa: F401  (kept for the same import path as the other batches)
from pilot import S

def _flush_code(c):
    """Drop Unicorn's cached translations for the heap and the exe image after a patch (as area 20 does): a stale
    translation otherwise runs in place of the new stub bytes."""
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _logger(name, nargs, cdecl=False):
    # thiscall (args popped by callee) unless cdecl; logs ecx and the stack arguments
    def h(e, r):
        args = tuple(e.arg32(k) for k in range(nargs))
        e.calllog.append((name, e.reg('ecx'), args))
        e.ret(eax=0, argbytes=0 if cdecl else 4 * nargs)
    return h


def _setup_dtors(c):
    ss.patch(c, 0x504870, c.emu.stub_fn('0x504870', _logger('0x504870', 0)))
    _flush_code(c)
    ss.patch(c, 0x480fd0, c.emu.stub_fn('0x480fd0', _logger('0x480fd0', 0)))
    _flush_code(c)
    ss.patch(c, 0x4878c0, c.emu.stub_fn('0x4878c0', _logger('0x4878c0', 0)))
    _flush_code(c)
    ss.patch(c, 0x634273, c.emu.stub_fn('0x634273', _logger('0x634273', 2, cdecl=True)))
    _flush_code(c)


def _dtor_gen(c):
    return [_rnd(c, 0x200), c.rng.getrandbits(32)]


S(0x506370, 'ZActorIf::~ZActorIf (unknown) thiscall', 'thiscall', None, ret='eax', gen=_dtor_gen,
  setup=_setup_dtors, note='unclaimed-12 batch 8 (in slice); vtable 0x69cf6c; base 0x504870; delete 0x1c if flag bit 0')
S(0x5e16f0, 'ZFFHeroMovementStand::~ZFFHeroMovementStand (unknown) thiscall', 'thiscall', None, ret='eax',
  gen=_dtor_gen, setup=_setup_dtors,
  note='unclaimed-12 batch 8 (in slice); vtable 0x6b753c; members 0x480fd0 x5; base 0x4878c0; delete 0x189 if flag bit 0')
