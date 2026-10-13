"""specs_s325.py - area 71 batch 325: 0x4407a0, thiscall, one stack argument, ret 4. Calls the object's vtable slot 0x2c0 with
(argument, 0x800). The slot is a logging stub taking two stack arguments."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import engine_stubs as E
import pe_emu


def _nostack(x):
    return 'stack' if pe_emu.STACK_TOP - pe_emu.STACK_SIZE <= x < pe_emu.STACK_TOP else x


def _gen(c):
    o = E.zero_obj(c, 0x40)
    slots = {}
    for i in range(0x2c0 // 4 + 1):
        off = 4 * i

        def h(e, r, off=off):
            args = [e.arg32(0), e.arg32(1)] if off == 0x2c0 else []
            e.calllog.append(('ZCALLEE', off, e.reg('ecx'), tuple(_nostack(x) for x in args)))
            e.ret(eax=0, argbytes=8 if off == 0x2c0 else 0)
        slots[off] = h
    c.emu.w32(o, c.emu.fake_vtable('ZCALLEE', 0x2c0 // 4 + 1, slots))
    arg = c.rng.getrandbits(32)
    c.emu.mu.ctl_flush_tb()
    return [o, arg]


S(0x4407a0, 'call slot 0x2c0 with (arg, 0x800) (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='area 71 batch 325 (leaf, residue 10)')
