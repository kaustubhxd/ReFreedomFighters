"""specs_s6514.py - unclaimed-65 batch 14 (docs/20-unclaimed-65.md, claim 14): two destructor shapes with an SEH frame (not reproduced;
the fs:[0] writes are not compared). Callees: 0x4ccf60 (plain thiscall, logs ecx; a stack-free object address), 0x4690b0 (cdecl, two
args), the function pointer 0x7003b0 (counting stub), the render object's slot +0x34 (logs), the cookie 0x633654 (ret). Flush after patches."""
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

    def cookie(e, r):
        e.ret(eax=0, argbytes=0)

    def ccf60(e, r):
        e.calllog.append(('0x4ccf60', e.reg('ecx'), ()))
        e.ret(eax=0, argbytes=0)

    def c90(e, r):
        e.calllog.append(('0x4690b0', e.reg('ecx'), (e.arg32(0), e.arg32(1))))
        e.ret(eax=0, argbytes=0)     # cdecl: the caller pops
    ss.patch(c, 0x633654, c.emu.stub_fn('cookie', cookie))
    ss.patch(c, 0x4ccf60, c.emu.stub_fn('0x4ccf60', ccf60))
    ss.patch(c, 0x4690b0, c.emu.stub_fn('0x4690b0', c90))
    c.emu.w32(0x7003b0, ss.rec(c, 0, ret=0, log=False))
    _flush_code(c)


def _gen(c):
    # the render object: slot +0x34 (one arg, logs the object it was given, which is a heap address)
    r_vt = c.emu.logging_vtable('cam-render', 0x40, argwords={0x34: 1})
    R = _rnd(c, 0x40)
    c.emu.w32(R, r_vt)
    rr = _rnd(c, 0x2000)
    c.emu.w32(rr + 0x9b, R)
    c.emu.w32(0x70039c, rr)
    self_ = _rnd(c, 0x400)
    return [self_, c.rng.getrandbits(32)]


S(0x4fb9e0, 'CMAINCAMERACONTROL::~CMAINCAMERACONTROL (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen, setup=_setup,
  note='unclaimed-65 batch 14 (residue 18); SEH frame not reproduced; base 0x4ccf60; delete 0x15a (bit 2) or fn 0x7003b0')
S(0x577860, 'GUESS FUN_577860 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen, setup=_setup,
  note='unclaimed-65 batch 14 (residue 18, GUESS); SEH frame not reproduced; delete 0x224 (bit 2) or fn 0x7003b0')
