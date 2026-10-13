"""specs_s392.py - core batch 392: 0x5e4710 (thiscall, no arguments). Its callee 0x5e3e90 is hooked by address and logged
(GUESS: body not ported; the hook returns nothing). Slot 0x58 of the object's vtable is a logging mock: it logs its one
argument and returns a random dword that the function stores at +0x554."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import engine_stubs as E
import pe_emu


def _nostack(x):
    return 'stack' if pe_emu.STACK_TOP - pe_emu.STACK_SIZE <= x < pe_emu.STACK_TOP else x


def _setup(c):
    c.emu.hook(0x5e3e90, lambda em, r: (em.calllog.append(('init5e3e90', 0, em.reg('ecx'), ())), em.ret(eax=0, argbytes=0)))


def _gen(c):
    r = c.rng
    rv = r.getrandbits(32)
    slots = {}
    for i in range(0x60 // 4 + 1):
        off = 4 * i

        def h(e, rr, off=off):
            args = [e.arg32(0)] if off == 0x58 else []
            e.calllog.append(('PLACEC4', off, e.reg('ecx'), tuple(_nostack(x) for x in args)))
            e.ret(eax=rv if off == 0x58 else 0, argbytes=4 if off == 0x58 else 0)
        slots[off] = h
    vt = c.emu.fake_vtable('PLACEC4', 0x60 // 4 + 1, slots)
    o = E.zero_obj(c, 0x600)
    c.emu.w32(o, vt)
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x5e4710, 'ZFFHeroMovementPlaceC4 init (core) thiscall', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='core batch 392; callee 0x5e3e90 hooked (GUESS); vtable slot 0x58 mocked')
