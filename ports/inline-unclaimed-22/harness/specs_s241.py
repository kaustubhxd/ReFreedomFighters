"""specs_s241.py - area 59, batch241 (src/batch241.cpp): 0x4376c0, tokenizer. 0x41e290 is the bump allocator stub (cdecl).
The token callee (vtable slot 4 of this+0xd) is a logged sparse slot with one argument; its argument is a heap block
(the bump allocator is deterministic). Strings are short (no assertion path) and drawn from digits, '+' and letters, with
a leading '0' sometimes so the early exit is exercised."""
from pilot import S
import serial_stubs as ss
from helpers22 import _rnd, _multi_vt, _flush_heap_code, jmp_patch


def _g_4376c0(c):
    self_ = _rnd(c, 0x40)
    sub = _rnd(c, 0x40)
    c.emu.w32(sub, _multi_vt(c, {4: (lambda em, args: (0, None), 1)}))
    c.emu.w32(self_ + 0xd, sub)
    pool = _rnd(c, 0x800)
    bump = c.emu.alloc(4, 4)
    c.emu.w32(bump, pool)
    jmp_patch(c, 0x41e290, ss.code(c, b'\x8b\x44\x24\x04' + b'\x8b\x15' + ss.P(bump) + b'\x01\x05' + ss.P(bump)
                                  + b'\x89\xd0' + b'\xc3'))
    _flush_heap_code(c)
    alphabet = b'0123456789+++ABCDEFabc'
    n = c.rng.randrange(0, 0x60)
    s = bytes(c.rng.choice(alphabet) for _ in range(n))
    if c.rng.random() < 0.2:
        s = b'0' + s
    src = _rnd(c, 0x100)
    c.emu.wbytes(src, s + b'\x00')
    obj = _rnd(c, 0x40)
    c.emu.w32(obj + 0x10, src)
    c.emu.mu.ctl_flush_tb()
    return [self_, obj]


S(0x4376c0, 'tokenize (GUESS)', 'thiscall', None, ret=None, gen=_g_4376c0,
  note='batch241; splits on +, stops at NUL or a leading 0; token callee is vtable slot 4 of this+0xd')
