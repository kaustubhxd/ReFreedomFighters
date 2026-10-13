"""specs_s2759.py - unclaimed-27 batch 59: 0x4d3a60 (GUESS). thiscall, four stack args, ret 0x10, returns eax.
The table at 0x6e7a38 (18 entries, stride 0x14) is filled with random words; with 75% a 0xd is placed at a random entry.
HOOKED (stub, NOT verified): vtable slot +0xac (thiscall, 5 stack args, ret 0x14); records ecx and the five args, returns a random eax."""
from pilot import S
import struct


def _gen(c):
    p = lambda v: struct.pack('<I', v)
    for i in range(0x168 // 4):
        c.emu.w32(0x6e7a38 + i * 4, c.rng.getrandbits(32))
    for i in range(18):
        if c.rng.getrandbits(32) % 40 == 0:
            c.emu.w32(0x6e7a38 + i * 0x14, 0xd)   # duplicates: the first one must win
    if c.rng.getrandbits(2):
        c.emu.w32(0x6e7a38 + c.rng.randint(0, 17) * 0x14, 0xd)
    rec = c.emu.alloc(0x20, 4)
    code = b'\x89\x0d' + p(rec)
    for i in range(5):
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i]) + b'\xa3' + p(rec + 4 + 4 * i)
    code += b'\xb8' + p(c.rng.getrandbits(32)) + b'\xc2\x14\x00'
    st = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(st, code)
    vt = c.emu.alloc(0x200, 4)
    c.emu.wbytes(vt, bytes(c.rng.getrandbits(8) for _ in range(0x200)))
    c.emu.w32(vt + 0xac, st)
    obj = c.emu.alloc(0x40, 4)
    c.emu.w32(obj, vt)
    c.emu.mu.ctl_flush_tb()
    return [obj] + [c.rng.getrandbits(32) for _ in range(4)]


S(0x4d3a60, 'FUN_4d3a60 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-27 batch 59; global table at 0x6e7a38 randomised; vtable slot +0xac is a hook (stub)')
