"""specs_s832.py - residue-00 batch 832 (docs/20-unclaimed-65.md). 0x5f0f00: thiscall, one stack argument (ret 4). The object (this) has the
bytes at +0 and +1, and the dwords at +3, +0xb and +0xf that pick the branch. Callees, all HOOKED by address (GUESS):
  render sub-object r9 at [0x70039c]+0x9b: slot 0x138 (no arguments) returns O; slot 0x114 (five words, callee pops 0x14) returns a random word.
  O: slot 0x88 (two words, callee pops 8) writes a random local dword through its second argument (zero in a third of the cases).
  Q = r9+0xadc: slot 0x12c (two words, callee pops 8, logged).
  0x5f0d30 (thiscall, no arguments; logs ecx); 0x5f0cd0 (fastcall, logs ecx and edx)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _setup(c):
    import serial_stubs as ss
    ss.patch(c, 0x5f0d30, c.emu.stub_fn('5f0d30 hook', lambda e, r: (e.calllog.append(('0x5f0d30', e.reg('ecx'))), e.ret(eax=0, argbytes=0))))
    ss.patch(c, 0x5f0cd0, c.emu.stub_fn('5f0cd0 hook', lambda e, r: (e.calllog.append(('0x5f0cd0', e.reg('ecx'), e.reg('edx'))), e.ret(eax=0, argbytes=0))))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen(c):
    local_val = c.rng.choice([0, c.rng.getrandbits(32) | 1])
    word = c.rng.getrandbits(32)
    o_vt = c.emu.fake_vtable('c832-o', 0x100, {
        0x88: lambda e, r: (e.calllog.append(('0x88', e.reg('ecx'), e.arg32(0))), e.w32(e.arg32(1), local_val), e.ret(eax=0, argbytes=8))[-1]})
    o = _rnd(c, 0x40)
    c.emu.w32(o, o_vt)
    q_vt = c.emu.fake_vtable('c832-q', 0x200, {
        0x12c: lambda e, r: (e.calllog.append(('0x12c', e.reg('ecx'), e.arg32(0), e.arg32(1))), e.ret(eax=0, argbytes=8))[-1]})
    q = _rnd(c, 0x40)
    c.emu.w32(q, q_vt)
    r9_vt = c.emu.fake_vtable('c832-r9', 0x200, {
        0x138: lambda e, r: (e.calllog.append(('0x138', e.reg('ecx'))), e.ret(eax=o, argbytes=0))[-1],
        0x114: lambda e, r: (e.calllog.append(('0x114', tuple(e.arg32(k) for k in range(5)))), e.ret(eax=word, argbytes=0x14))[-1]})
    r9 = _rnd(c, 0x1000)
    c.emu.w32(r9, r9_vt)
    c.emu.w32(r9 + 0xadc, q)
    render = _rnd(c, 0x200)
    c.emu.w32(render + 0x9b, r9)
    c.emu.w32(0x70039c, render)
    this = _rnd(c, 0x100)
    c.emu.w32(this, 0)
    c.emu.wbytes(this, bytes([c.rng.choice([0, 0, 0, 1])]))
    c.emu.wbytes(this + 1, bytes([c.rng.choice([0, 0, 0, 1])]))
    v11 = c.rng.choice([0, c.rng.getrandbits(32) | 1])
    c.emu.w32(this + 0xb, v11)
    c.emu.w32(this + 0xf, c.rng.choice([0x1234, v11]))
    c.emu.w32(this + 3, c.rng.choice([0, 0, 0x4321, v11]))
    arg = c.rng.getrandbits(32)
    return [this, arg]


S(0x5f0f00, 'ZFFWindowCoordinator::TapMap (unknown) thiscall one arg', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='residue-00 batch 832: five-argument slot 0x114, two-argument slot 0x12c, hooked helpers')
