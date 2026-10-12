"""specs_s1911.py - unclaimed-66 batch 1911: 0x64fb90 (float == 0.0 test) and 0x499c10 (vtable +0x10 with the argument's address).

0x64fb90: the float at +0x70 is chosen from 0.0, -0.0, NaN, +inf, tiny values and random values, so the equal-zero, NaN and
sign-of-zero cases all run. 0x499c10: its vtable +0x10 is a logging stub with two arguments (the callee pops 8); the first
argument is the caller's stack slot, so it is not logged (it differs between builds); the stub writes a random dword through
it. The argument of 0x499c10 is random."""
import struct
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _f(c):
    k = c.rng.random()
    if k < 0.2:
        return c.rng.choice([0.0, -0.0, float('nan'), float('inf'), -float('inf'), 1e-45])
    return c.rng.uniform(-3.0, 3.0)


def _cmp(c):
    self = _rnd(c, 0x100)
    c.emu.wbytes(self + 0x70, struct.pack('<f', _f(c)))
    return [self]


def _slot(name, off):
    """Logs the second argument only (the first is the caller's stack slot); writes 0x5a5a1234 through the first."""
    def h(e, r):
        a0 = e.arg32(0)
        a1 = e.arg32(1)
        e.calllog.append((name, off, e.reg('ecx'), (None, a1)))
        e.w32(a0, 0x5a5a1234)
        e.ret(eax=0, argbytes=8)
    return h


def _forward(c):
    vt = c.emu.fake_vtable('leaf499c10 obj', 0x14 // 4 + 1, slots={0x10: _slot('leaf499c10 obj +0x10 (stub)', 0x10)})
    self = _rnd(c, 0x100)
    c.emu.w32(self, vt)
    return [self, c.rng.getrandbits(32)]


S(0x64fb90, 'GUESS FUN_0064fb90 (float equal zero)', 'thiscall', None, ret='eax', gen=_cmp,
  note='unclaimed-66 batch 1911; slice-5 (GUESS); ordered-equal to 0.0 gives 0, else 1')
S(0x499c10, 'GUESS FUN_00499c10 (vtable +0x10 with arg address)', 'thiscall', None, ret='eax', gen=_forward,
  note='unclaimed-66 batch 1911; slice-5 (GUESS); vtable slot stubbed; stack arg address masked')
