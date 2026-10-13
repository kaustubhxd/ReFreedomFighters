"""specs_s1028.py - area 81, batch 1028: 0x476dc0 (array constructor, thiscall: this; n). n is 0..8 (0 takes the early return). The allocator 0x41e290 is a cdecl
bump allocator over a per-case pool (size argument advances the pool; returns the old pointer). The pool is random at the start, so the zeroing of the
second and third blocks is visible in the heap compare (the first block is not zeroed by the function)."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import obj, r32


def g(c):
    rnd = c.rng
    pool = c.emu.alloc(0x2000, 16)
    c.emu.wbytes(pool, bytes(rnd.getrandbits(8) for _ in range(0x2000)))
    bump = c.emu.alloc(4, 4)
    c.emu.w32(bump, pool)
    code = (b'\x8b\x44\x24\x04'                                  # mov eax,[esp+4]
            + b'\x8b\x15' + struct.pack('<I', bump)              # mov edx,[bump]
            + b'\x01\x05' + struct.pack('<I', bump)              # add [bump],eax
            + b'\x89\xd0'                                        # mov eax,edx
            + b'\xc3')                                           # ret (cdecl: caller pops)
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    ss.patch(c, 0x41e290, a)
    n = rnd.randint(0, 8)
    self_ = obj(c, 0x80)
    return [self_, n]


S(0x476dc0, 'GUESS 0x476dc0 array constructor', 'thiscall', gen=g)
