"""specs_s226.py - unclaimed area 22, batch226 (src/batch226.cpp): 0x4fb8d0.

0x4fbd50 (a bool getter with a security cookie and its own calls) is stubbed with a recorder: it stores ecx and returns a
random eax, of which the caller keeps only al. Vtable callees are logged sparse slots.
"""
from pilot import S
import serial_stubs as ss
from helpers22 import _rnd, _multi_vt, _flush_heap_code, jmp_patch


def _g_4fb8d0(c):
    self_ = _rnd(c, 0x80)
    c.emu.w32(self_ + 0x48, c.rng.choice([0, 1, 0x80, c.rng.getrandbits(8)]))
    c.emu.w32(self_ + 0x55, c.rng.getrandbits(32))
    c.emu.w32(self_ + 0x49, c.rng.getrandbits(32))
    o = _rnd(c, 0x40)
    ret58 = c.rng.choice([0, o])
    obj = _rnd(c, 0x40)
    c.emu.w32(obj, _multi_vt(c, {0x58: (lambda em, args, v=ret58: (v, None), 1)}))
    rm = _rnd(c, 0x100)
    c.emu.w32(0x70039c, rm)
    c.emu.w32(rm + 0x9b, obj)
    c.emu.w32(o, _multi_vt(c, {0x128: (lambda em, args: (0, None), 3)}))
    # 0x4fbd50 stand-in: stores ecx, returns a random eax (only al is used by the caller)
    slot = c.emu.alloc(4, 4)
    c.emu.w32(slot, 0)
    ret_v = c.rng.getrandbits(32)
    code = b'\x89\x0d' + ss.P(slot) + b'\xb8' + ss.P(ret_v) + b'\xc3'
    jmp_patch(c, 0x4fbd50, ss.code(c, code))
    _flush_heap_code(c)
    c.emu.mu.ctl_flush_tb()
    return [self_]


S(0x4fb8d0, 'stateSlot128 (GUESS)', 'thiscall', None, ret=None, gen=_g_4fb8d0,
  note='batch226; 0x4fbd50 stubbed (bool), vtable 0x58 on the global object, then 0x128 with three words')
