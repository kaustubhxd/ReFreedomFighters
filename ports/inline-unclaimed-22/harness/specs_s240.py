"""specs_s240.py - area 59, batch240 (src/batch240.cpp): 0x4cc2c0, string append-assign.

0x41e290 (cdecl allocator) is a bump allocator over a per-case pool; 0x634273 (cdecl free) records the pointer it frees.
Both are heap-value stubs, so the port and the original see the same block addresses. Strings are short printable ASCII,
sometimes long enough to take the allocation path (total >= 0x7c).
"""
from pilot import S
import serial_stubs as ss
from helpers22 import _rnd, _flush_heap_code, jmp_patch


def _cstr(c, n):
    return bytes(c.rng.randrange(0x41, 0x5b) for _ in range(n)) + b'\x00'


def _g_4cc2c0(c):
    self_ = _rnd(c, 0x100)
    pool = _rnd(c, 0x800)
    import out_stubs
    out_stubs.bump_alloc(c, pool, 0x41e290)      # cdecl(size) bump allocator (shared stub file)
    out_stubs.free_hook(c, 0x634273, stack_words=2)   # cdecl(p, size) recorder (shared stub file)
    _flush_heap_code(c)
    # this: the string is inline (at +4) or a block in the pool
    n1 = c.rng.choice([0, 3, 20, 60, 100])
    if c.rng.random() < 0.5:
        p = self_ + 4
        c.emu.w32(self_, p)
        c.emu.wbytes(p, _cstr(c, min(n1, 0x70)))
    else:
        p = pool + 0x400
        c.emu.w32(self_, p)
        c.emu.wbytes(p, _cstr(c, n1))
    if c.rng.random() < 0.1:
        c.emu.mu.ctl_flush_tb()
        return [self_, 0]
    obj = _rnd(c, 0x40)
    n2 = c.rng.choice([0, 2, 30, 80, 120])
    sbuf = _rnd(c, 0x200)
    c.emu.wbytes(sbuf, _cstr(c, n2))
    c.emu.w32(obj, sbuf)
    c.emu.mu.ctl_flush_tb()
    return [self_, obj]


S(0x4cc2c0, 'appendStr (GUESS)', 'thiscall', None, ret='eax', gen=_g_4cc2c0,
  note='batch240; string append-assign; 0x41e290 bump allocator, 0x634273 recorder')
