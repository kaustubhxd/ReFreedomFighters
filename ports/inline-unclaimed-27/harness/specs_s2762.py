"""specs_s2762.py - unclaimed-27 batch 62: 0x663060 (GUESS). thiscall, one stack arg (pointer to 3 floats), ret 4, void.
HOOKED (stubs, NOT verified): 0x4e0830 (float in st0; chosen around the threshold 0.1f at 0x67a284 incl. equal, NaN, +-inf),
0x4e0030 (float in st0, random), 0x662ab0 and 0x662b00 (thiscall, one stack dword, ret 4). All four count their calls and
record ecx/edx/args in a heap record, so both sides see the same."""
from pilot import S
import struct

THR = struct.unpack('<f', struct.pack('<f', 0.1))[0]
CH = [THR, 0.0, -1.0, 1.0, 0.2, 0.0999, float('nan'), float('inf'), -float('inf'), 1e30, 3.5, -0.0]


def _gen(c):
    rec = c.emu.alloc(0x40, 4)
    d = c.rng.choice(CH) if c.rng.getrandbits(32) % 2 else c.rng.uniform(-2, 2)
    f = c.rng.choice(CH) if c.rng.getrandbits(32) % 2 else c.rng.uniform(-100, 100)

    def h830(e, r):
        e.w32(rec, (e.r32(rec) + 1) & 0xffffffff)
        e.w32(rec + 4, e.reg('ecx')); e.w32(rec + 8, e.reg('edx'))
        e.ret(st0=d, argbytes=0)

    def h030(e, r):
        e.w32(rec + 0xc, (e.r32(rec + 0xc) + 1) & 0xffffffff)
        e.w32(rec + 0x10, e.reg('ecx')); e.w32(rec + 0x14, e.reg('edx'))
        e.ret(st0=f, argbytes=0)

    def h2ab(e, r):
        e.w32(rec + 0x18, (e.r32(rec + 0x18) + 1) & 0xffffffff)
        e.w32(rec + 0x1c, e.reg('ecx')); e.w32(rec + 0x20, e.arg32(0))
        e.ret(argbytes=4)

    def h2b0(e, r):
        e.w32(rec + 0x24, (e.r32(rec + 0x24) + 1) & 0xffffffff)
        e.w32(rec + 0x28, e.reg('ecx')); e.w32(rec + 0x2c, e.arg32(0))
        e.ret(argbytes=4)

    c.emu.hook(0x4e0830, h830)
    c.emu.hook(0x4e0030, h030)
    c.emu.hook(0x662ab0, h2ab)
    c.emu.hook(0x662b00, h2b0)
    obj = c.emu.alloc(0x60, 4)
    c.emu.wbytes(obj, bytes(c.rng.getrandbits(8) for _ in range(0x60)))
    arg = c.emu.alloc(0x20, 4)
    c.emu.wbytes(arg, bytes(c.rng.getrandbits(8) for _ in range(0x20)))
    c.emu.mu.ctl_flush_tb()
    return [obj, arg]


S(0x663060, 'FUN_663060 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-27 batch 62; callees 0x4e0830, 0x4e0030 (st0 floats), 0x662ab0, 0x662b00 are hooks (stubs)')
