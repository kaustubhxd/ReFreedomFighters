"""specs_s831.py - residue-00 batch 831 (docs/20-unclaimed-65.md). 0x524180: thiscall, no arguments, a float and double branch. The object (0x100
block) takes random single floats at the offsets the function reads; the word at +0x4f selects the 0x523040 call; the dword at +0x39 selects
the slot-calls. Callees, all HOOKED by address (GUESS):
  0x523040: callee pops two words (logs ecx and both words).
  global 0x700390 object O: slot 0x20 (two words, pops them) returns object P (the logged words).
  P: slot 0x2c (two words; the caller removes 16 more bytes of doubles, logged as six words), pops its two words.
  this: slot 0x8 (two float words, pops them; logged).
The cookie-free exe function; all returns are zero or fixed per case."""
import os, struct, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _f(c, lo=-100.0, hi=100.0):
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(lo, hi)))[0]


def _setup(c):
    import serial_stubs as ss
    ss.patch(c, 0x523040, c.emu.stub_fn('523040 hook', lambda e, r: (
        e.calllog.append(('0x523040', e.reg('ecx'), e.arg32(0), e.arg32(1))), e.ret(eax=0, argbytes=8))))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen(c):
    p_vt = c.emu.fake_vtable('c831-p', 0x100, {
        0x2c: lambda e, r: (e.calllog.append(('0x2c', e.reg('ecx'), tuple(e.arg32(k) for k in range(6)))), e.ret(eax=0, argbytes=8))[-1]})
    p = _rnd(c, 0x40)
    c.emu.w32(p, p_vt)
    o_vt = c.emu.fake_vtable('c831-o', 0x100, {
        0x20: lambda e, r: (e.calllog.append(('0x20', e.reg('ecx'), e.arg32(0), e.arg32(1))), e.ret(eax=p, argbytes=8))[-1]})
    o = _rnd(c, 0x40)
    c.emu.w32(o, o_vt)
    c.emu.w32(0x700390, o)
    this_vt = c.emu.fake_vtable('c831-this', 0x100, {
        0x8: lambda e, r: (e.calllog.append(('0x8', e.reg('ecx'), e.arg32(0), e.arg32(1))), e.ret(eax=0, argbytes=8))[-1]})
    this = _rnd(c, 0x100)
    c.emu.w32(this, this_vt)
    # the floats the function reads: +0x42, +4, +0x53, +0x20, +0x30 (written), +0x3d, +0x24, +0x5b, +0x57 (single precision)
    for off in (0x42, 0x04, 0x53, 0x20, 0x3d, 0x24, 0x5b, 0x57):
        c.emu.w32(this + off, _f(c, -50.0, 50.0))
    c.emu.w32(this + 0x4f, c.rng.choice([0, c.rng.getrandbits(32) | 1]))
    c.emu.w32(this + 0x39, c.rng.choice([0, 1, 2, 3]))
    if False:
        # the branch that reaches the object calls: +0x30 >= 5.0 (from (x42 - x4) * x53 * x20 = 10), +0x39 == 2, |x24| <= 2^-13
        struct_f = lambda v: struct.unpack('<I', struct.pack('<f', v))[0]
        c.emu.w32(this + 0x42, struct_f(10.0))
        c.emu.w32(this + 0x04, struct_f(0.0))
        c.emu.w32(this + 0x53, struct_f(1.0))
        c.emu.w32(this + 0x20, struct_f(1.0))
        c.emu.w32(this + 0x39, 2)
        c.emu.w32(this + 0x24, struct_f(c.rng.uniform(-1e-4, 1e-4)))
    return [this]


S(0x524180, 'ZActor-area unknown (0x524180) thiscall no args', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='residue-00 batch 831: single and double float branch; hooked 0x523040, slot 0x20/0x2c of 0x700390, slot 0x8 of this')
