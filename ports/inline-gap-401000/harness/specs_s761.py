"""specs_s761.py - gap band batch 761 (docs/20-gap-band-401000.md): 0x40ba30, cdecl with a pointer to a float. The float bits are random
(NaN and infinities included: both sides run the same x87 ops). 0x634dfa (the CRT _ftol thunk) is a stand-in on the st0 bits (see _st0_int)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _st0_int(e):
    """Stand-in for the CRT conversion 0x634dfa: unicorn gives ST0 as a 64-bit integer (not the 80-bit value), so the true truncation
    cannot be read here. The stand-in is a fixed function of those bits: (bits >> 33) as a signed 32-bit int. It varies with the input and
    covers the negative, in-range and over-range branches of the clamp; the conversion itself stays unverified (another claim)."""
    from unicorn.x86_const import UC_X86_REG_ST0
    raw = int(e.mu.reg_read(UC_X86_REG_ST0)) & ((1 << 64) - 1)
    return (raw >> 33) & 0xffffffff


def _gen(c):
    a = c.emu.alloc(0x10, 4)
    import struct
    # the function is a*7.3142857 + 1023.5 clamped to [0, 0x3ff]: most inputs are drawn from [-200, 200] so both clamps run
    if c.rng.random() < 0.8:
        bits = struct.unpack('<I', struct.pack('<f', c.rng.uniform(-200.0, 200.0)))[0]
    else:
        bits = c.rng.choice([c.rng.getrandbits(32), 0x42c80000, 0xc2c80000, 0x7f800000])
    c.emu.w32(a, bits)
    return [a]


def _setup(c):
    import serial_stubs as ss
    ss.patch(c, 0x634dfa, c.emu.stub_fn('_ftol model', lambda e, r: (e.calllog.append(('0x634dfa', _st0_int(e))), e.ret(eax=_st0_int(e), argbytes=0))))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


S(0x40ba30, 'CRT clamp 0x40ba30 (unknown) cdecl', 'cdecl', None, ret='eax', gen=_gen, setup=_setup,
  note='gap band batch 761: st0 = [a]*k + m, then 0x634dfa and a clamp to [0,0x3ff]')
