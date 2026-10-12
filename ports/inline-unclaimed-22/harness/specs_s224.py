"""specs_s224.py - unclaimed area 22, batch224 (src/batch224.cpp): 0x4da6d0 and 0x5a2bd0.

0x4dcdf0 and 0x5a01e0 are stubbed with recorders (they are other functions' bodies; the stubs keep the same
stack shape and log their argument or ecx). Vtable callees are logged sparse slots.
"""
from pilot import S
import serial_stubs as ss
from helpers22 import _rnd, _multi_vt, _flush_heap_code, jmp_patch


def _rec_ecx(c, addr, nargs):
    """Recorder for a thiscall callee: stores ecx and its stack words, returns 0 (ret 4 * nargs)."""
    slots = [c.emu.alloc(4, 4) for _ in range(nargs + 1)]
    for sl in slots:
        c.emu.w32(sl, 0)
    code = b'\x89\x0d' + ss.P(slots[0])
    for i in range(nargs):
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i]) + b'\xa3' + ss.P(slots[1 + i])
    code += b'\x31\xc0' + b'\xc2' + (4 * nargs).to_bytes(2, 'little')
    jmp_patch(c, addr, ss.code(c, code))
    _flush_heap_code(c)


def _g_4da6d0(c):
    self_ = _rnd(c, 0x80)
    e = c.rng.choice([0, c.rng.getrandbits(32)])
    c.emu.w32(self_ + 0x6c, e)
    rm = _rnd(c, 0x2000)
    c.emu.w32(rm + 0x3c, c.rng.choice([0x64, 0x65, 0, c.rng.getrandbits(32)]))
    o = _rnd(c, 0x40)
    obj = _rnd(c, 0x40)
    c.emu.w32(o + 0x18, obj)
    c.emu.w32(rm + 0x1aa3, o)
    c.emu.w32(obj, _multi_vt(c, {0x18: (lambda em, args, v=c.rng.choice([0, 1, 0x100, c.rng.getrandbits(32)]):
                                       (v, None), 1),
                                 0x6c: (lambda em, args: (c.rng.getrandbits(32), None), 2)}))
    c.emu.w32(0x70039c, rm)
    _rec_ecx(c, 0x4dcdf0, 1)
    c.emu.mu.ctl_flush_tb()
    return [self_]


def _g_5a2bd0(c):
    self_ = _rnd(c, 0x900)
    vt_self = _multi_vt(c, {0x130: (lambda em, args: (0, None), 3)})   # SendCommand, ret 0xc
    vt_alt = c.emu.logging_vtable('alt130', 1, impl={0: lambda em, args: (0, None)}, argwords={0: 3})
    alt = c.emu.alloc(0x134, 4)
    c.emu.w32(alt + 0x130, c.emu.r32(vt_alt))
    c.emu.w32(self_, vt_self)
    rm = _rnd(c, 0x100)
    o = _rnd(c, 0x40)
    v114 = c.rng.getrandbits(32)
    # the 0x114 callee rewrites this's vtable: the original reads the vtable before the call (esi), the port must too
    c.emu.w32(o, _multi_vt(c, {0x114: (lambda em, args, s=self_, a=alt, v=v114: (c.emu.w32(s, a) or v, None), 4)}))   # RegisterZMsg, ret 0x10
    c.emu.w32(rm + 0x9b, o)
    c.emu.w32(0x70039c, rm)
    a = _rnd(c, 0x10)
    _rec_ecx(c, 0x5a01e0, 0)
    c.emu.mu.ctl_flush_tb()
    return [self_, a]


S(0x4da6d0, 'guardedChain (GUESS)', 'thiscall', None, ret=None, gen=_g_4da6d0,
  note='batch224; vtable 0x18 guard, then vtable 0x6c, then 0x4dcdf0 (stubbed, ret 4)')
S(0x5a2bd0, 'copyAfterCall (GUESS)', 'thiscall', None, ret=None, gen=_g_5a2bd0,
  note='batch224; vtable 0x114, then this vtable 0x130, then 0x5a01e0 (stubbed), then a 16-byte copy')
