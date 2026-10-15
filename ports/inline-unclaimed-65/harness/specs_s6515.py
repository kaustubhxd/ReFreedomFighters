"""specs_s6515.py - unclaimed-65 batch 15 (docs/20-unclaimed-65.md, claim 15): ZBoundDeactivateRegister::Init. SEH frame not reproduced
(the fs:[0] writes are not compared). 0x4ccba0 and 0x4ccf60 are no-op stubs (their ecx is a stack address and is not logged); 0x4e6330
writes a value through its pointer argument (the struct) and does not log it; this's slot +0x58 is a logging fake. Cookie patched to a ret."""
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


def _setup(c):
    import serial_stubs as ss

    def noop(e, r):
        e.ret(eax=0, argbytes=0)

    def read4e6330(e, r):
        ptr = e.arg32(0)                 # the struct (a stack address; not logged)
        e.calllog.append(('dbread-4e6330', e.reg('ecx'), ()))
        e.w32(ptr, 0x12345678)
        e.w32(ptr + 4, 0x9abcdef0)
        e.ret(eax=0, argbytes=4)
    ss.patch(c, 0x633654, c.emu.stub_fn('cookie', noop))
    ss.patch(c, 0x4ccba0, c.emu.stub_fn('0x4ccba0', noop))
    ss.patch(c, 0x4ccf60, c.emu.stub_fn('0x4ccf60', noop))
    ss.patch(c, 0x4e6330, c.emu.stub_fn('0x4e6330', read4e6330))
    _flush_code(c)


def _gen(c):
    # this's slot +0x58 logs (no args); the DBREAD object is a heap value (its ecx is logged)
    s_vt = c.emu.logging_vtable('zbdr', 0x70, argwords={0x58: 0})
    self_ = _rnd(c, 0x100)
    c.emu.w32(self_, s_vt)
    dbread = _rnd(c, 0x40)
    return [self_, c.rng.getrandbits(32), dbread]


S(0x4c7aa0, 'ZBoundDeactivateRegister::Init (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='unclaimed-65 batch 15 (residue 18); SEH frame not reproduced; DBREAD into a local struct; this slot 0x58')
