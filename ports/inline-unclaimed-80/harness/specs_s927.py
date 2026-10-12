"""specs_s927.py - unclaimed-80 claim 7 (docs/20-unclaimed-80.md): CWheel::Init (0x529a30). 0x4db7c0 is a stub that writes a
per-case dword at arg+8 (the float the code reads back) and returns with ret 4 (thiscall, one argument). The objects are logging
fakes: the std object's slot +0x84 and the grp object's slot +0x8c (one argument each), and this's slot +4 (two arguments).
The flag is a random byte's bool. The 0x633654 stack-cookie check runs in the exe and is not compared (it has no effect)."""
import struct
import serial_stubs as ss
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _stub_write(c, value):
    code = b'\x8b\x44\x24\x04' + b'\xc7\x40\x08' + struct.pack('<I', value & 0xffffffff) + b'\xc2\x04\x00'
    return ss.code(c, code)


def _init(c):
    ss.patch(c, 0x4db7c0, _stub_write(c, c.rng.getrandbits(32)))
    std = _rnd(c, 0x40)
    std_c = _rnd(c, 0x40)
    c.emu.w32(std + 8, std_c)
    vals1 = [c.rng.getrandbits(32) for _ in range(3)]
    vals2 = [c.rng.getrandbits(32) for _ in range(3)]

    def write_vals(vals):
        def f(e, args):
            for k, v in enumerate(vals):
                e.w32(args[0] + 4 * k, v)
            return (0, None)
        return f

    c.emu.w32(std, c.emu.logging_vtable('ZSTDOBJ', 0x50, impl={0x84: write_vals(vals1)}, argwords={0x84: 1}))
    c.emu.w32(std_c, c.emu.logging_vtable('ZSTDOBJ_C', 0x10))
    grp = _rnd(c, 0x40)
    c.emu.w32(grp, c.emu.logging_vtable('ZGROUP', 0x50, impl={0x8c: write_vals(vals2)}, argwords={0x8c: 1}))
    o = _rnd(c, 0x200)
    c.emu.w32(o, c.emu.logging_vtable('CWheel', 0x10, argwords={4: 2}))
    return [o, grp, std, c.rng.choice([0, 1, 0x100, c.rng.getrandbits(32)])]


S(0x529a30, 'CWheel::Init (unknown) thiscall', 'thiscall', None, ret=None, gen=_init,
  note='unclaimed-80 claim 7; 0x4db7c0 stubbed (writes arg+8); slots 0x84, 0x8c, +4 logged; cookie check omitted')
