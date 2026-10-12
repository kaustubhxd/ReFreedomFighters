"""specs_s228.py - unclaimed area 22, batch228 (src/batch228.cpp): 0x4fc690.

0x4fdac0 is stubbed with a recorder of its ecx. The virtual getter on the global's object (slot 0x138) returns an object
whose slot 0x88 writes a value through its second argument (an out pointer on the caller's stack); the stub logs ecx and
the first argument. The sub-object's slot 0x240 is a logged sparse slot.
"""
from pilot import S
import serial_stubs as ss
from helpers22 import _rnd, _multi_vt, _flush_heap_code, jmp_patch, _rec_ecx


def _g_4fc690(c):
    self_ = _rnd(c, 0x100)
    c.emu.w32(self_ + 0x6e, c.rng.choice([0, 0, c.rng.getrandbits(32)]))
    c.emu.wbytes(self_ + 0x4d, bytes([c.rng.choice([0, 1, 0x80, c.rng.getrandbits(8)])]))
    sub = _rnd(c, 0x80)
    c.emu.w32(sub, _multi_vt(c, {0x240: (lambda em, args: (0, None), 1)}))
    c.emu.w32(sub + 0x48, c.rng.getrandbits(32))
    c.emu.w32(self_ + 0x44, sub)
    # rm->[+0x9b] = o; o->vt[0x138]() returns r; r->vt[0x88](0x690410, &local) writes value into local
    rm = _rnd(c, 0x100)
    c.emu.w32(0x70039c, rm)
    o = _rnd(c, 0x40)
    r = _rnd(c, 0x40)
    c.emu.w32(rm + 0x9b, o)
    c.emu.w32(o, _multi_vt(c, {0x138: (lambda em, args, rr=r: (rr, None), 0)}))
    value = c.rng.getrandbits(32)
    ecx_s = c.emu.alloc(4, 4)
    a1_s = c.emu.alloc(4, 4)
    c.emu.w32(ecx_s, 0)
    c.emu.w32(a1_s, 0)
    code = (b'\x89\x0d' + ss.P(ecx_s)                 # mov [ecx_s], ecx
            + b'\x8b\x44\x24\x04\xa3' + ss.P(a1_s)     # mov eax, [esp+4]; mov [a1_s], eax
            + b'\x8b\x44\x24\x08'                      # mov eax, [esp+8]  (the out pointer)
            + b'\xc7\x00' + ss.P(value)                # mov dword [eax], value
            + b'\xc2\x08\x00')                         # ret 8
    vt_r = c.emu.alloc(0x100, 4)
    c.emu.w32(vt_r + 0x88, ss.code(c, code))
    c.emu.w32(r, vt_r)
    _rec_ecx(c, 0x4fdac0, 0)
    c.emu.mu.ctl_flush_tb()
    return [self_]


S(0x4fc690, 'setupFlag (GUESS)', 'thiscall', None, ret=None, gen=_g_4fc690,
  note='batch228; out-pointer getter (slot 0x88), sub-object slot 0x240, 0x4fdac0 stubbed, bit 0x400000 set or cleared')
