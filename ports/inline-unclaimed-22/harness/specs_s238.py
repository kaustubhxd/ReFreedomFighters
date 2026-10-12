"""specs_s238.py - area 59, batch238 (src/batch238.cpp): 0x5035a0 (SEH frame and cookie not reproduced).

Stack-pointer arguments are never logged: the stubs write through them and record only values (heap slots):
  0x5003d0 (three rows): a table lookup by its argument, one stack word, ret 4.
  0x84 and 0x7c (vtable on this[+0xc]): the 0x84 stub writes three dwords through its pointer; the 0x7c stub records the
    dwords behind both pointers. Both record ecx in a heap slot (the object).
  0x43e920 (thiscall, pointer argument): records the dword behind its argument.
  0x4de040 (fastcall ecx, edx, one stack word): records the dwords behind ecx and edx.
"""
from pilot import S, F
import serial_stubs as ss
from helpers22 import _rnd, _flush_heap_code, jmp_patch


def _heap_slot(c):
    a = c.emu.alloc(4, 4)
    c.emu.w32(a, 0)
    return a


def _g_5035a0(c):
    self_ = _rnd(c, 0x40)
    a = _rnd(c, 0x40)
    rows = [_rnd(c, 0x20) for _ in range(3)]
    for r in rows:
        for k in range(3):
            c.emu.wf32(r + 4 * k, c.rng.uniform(-5.0, 5.0))
    c.emu.w32(a + 4, _rnd(c, 0x40))
    tab = c.emu.alloc(12, 4)
    for i, r in enumerate(rows):
        c.emu.w32(tab + 4 * i, r)
    # 0x5003d0 stand-in: index into tab, one stack word, ret 4
    jmp_patch(c, 0x5003d0, ss.code(c, b'\x8b\x44\x24\x04\x8b\x04\x85' + ss.P(tab) + b'\xc2\x04\x00'))
    # 0x84: write three dwords through the pointer, record ecx
    slot_ecx = _heap_slot(c)
    w = [c.rng.getrandbits(32) for _ in range(3)]
    code84 = (b'\x89\x0d' + ss.P(slot_ecx) + b'\x8b\x44\x24\x04'
              + b'\xc7\x00' + ss.P(w[0]) + b'\xc7\x40\x04' + ss.P(w[1]) + b'\xc7\x40\x08' + ss.P(w[2])
              + b'\xc2\x04\x00')
    # 0x7c: record the dwords behind both pointers
    s0 = _heap_slot(c)
    s1 = _heap_slot(c)
    code7c = (b'\x8b\x44\x24\x04\x8b\x00\xa3' + ss.P(s0)
              + b'\x8b\x44\x24\x08\x8b\x00\xa3' + ss.P(s1)
              + b'\xc2\x08\x00')
    vt = c.emu.alloc(0x100, 4)
    c.emu.w32(vt + 0x84, ss.code(c, code84))
    c.emu.w32(vt + 0x7c, ss.code(c, code7c))
    obj = _rnd(c, 0x40)
    c.emu.w32(obj, vt)
    c.emu.w32(self_ + 0xc, obj)
    # 0x43e920: copies the three dwords behind its pointer into the object it is called on (ecx, a stack object), then
    # records them (heap slots)
    s43 = [_heap_slot(c) for _ in range(3)]
    code43 = (b'\x8b\x44\x24\x04'                        # mov eax, [esp+4]
              + b'\x8b\x10\x89\x11'                      # mov edx, [eax]; mov [ecx], edx
              + b'\x8b\x50\x04\x89\x51\x04'            # mov edx, [eax+4]; mov [ecx+4], edx
              + b'\x8b\x50\x08\x89\x51\x08'            # mov edx, [eax+8]; mov [ecx+8], edx
              + b'\x8b\x10\x89\x15' + ss.P(s43[0])       # record the three dwords
              + b'\x8b\x50\x04\x89\x15' + ss.P(s43[1])
              + b'\x8b\x50\x08\x89\x15' + ss.P(s43[2])
              + b'\x31\xc0\xc2\x04\x00')
    jmp_patch(c, 0x43e920, ss.code(c, code43))
    # 0x4de040 (fastcall ecx, edx; one stack word): copies the first two dwords of edx into ecx, records both
    s4a = _heap_slot(c)
    s4b = _heap_slot(c)
    code4 = (b'\x8b\x02\x89\x01'                       # mov eax, [edx]; mov [ecx], eax
             + b'\x8b\x42\x04\x89\x41\x04'           # mov eax, [edx+4]; mov [ecx+4], eax
             + b'\x8b\x01\xa3' + ss.P(s4a)              # mov eax, [ecx]; mov [s4a], eax
             + b'\x8b\x02\xa3' + ss.P(s4b)              # mov eax, [edx]; mov [s4b], eax
             + b'\x31\xc0\xc2\x04\x00')
    jmp_patch(c, 0x4de040, ss.code(c, code4))
    _flush_heap_code(c)
    c.emu.mu.ctl_flush_tb()
    return [self_, a]


S(0x5035a0, 'triple (GUESS)', 'thiscall', None, ret=None, gen=_g_5035a0,
  note='batch238; SEH frame and cookie not reproduced; callees stubbed (stack-pointer arguments not logged)')
