"""specs_s413.py - residue 2 row 0x6097a0 (thiscall, no arguments). Byte +0x33 is 0 or 1. Two logging vtables (A at +0x1377 and B
at global 0x724b38) have slot 8 hooked as logging mocks: the mock logs its ECX and argument (one stack argument, ret 4). The first
call passes ECX = this (the exe does not reload ECX), the second passes ECX = the vtable pointer of obj2 (as the exe does)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import engine_stubs as E
import pe_emu


def _nostack(x):
    return 'stack' if pe_emu.STACK_TOP - pe_emu.STACK_SIZE <= x < pe_emu.STACK_TOP else x


def _vt(c, name):
    def h(e, rr):
        e.calllog.append((name, 8, e.reg('ecx') & 0xffffffff, (_nostack(e.arg32(0)),)))
        e.ret(eax=0, argbytes=4)
    slots = {}
    for i in range(0x10 // 4):
        slots[4 * i] = h if 4 * i == 8 else (lambda e, rr: e.ret(eax=0, argbytes=0))
    return c.emu.fake_vtable(name, 0x10 // 4, slots)


def _gen(c):
    r = c.rng
    o = E.zero_obj(c, 0x1400)
    c.emu.wbytes(o, bytes(r.getrandbits(8) for _ in range(0x1400)))
    c.emu.wbytes(o + 0x33, bytes([r.choice([0, 1])]))
    objA = E.zero_obj(c, 0x20)
    c.emu.w32(objA, _vt(c, 'SLOT8A'))
    c.emu.w32(o + 0x1377, objA)
    objB = E.zero_obj(c, 0x20)
    c.emu.w32(objB, _vt(c, 'SLOT8B'))
    E.set_global(c, 0x724b38, objB)
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x6097a0, 'two slot-8 calls and clear flag (residue 2) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='residue 2 batch 413; vtable slot 8 mocked on both objects')
