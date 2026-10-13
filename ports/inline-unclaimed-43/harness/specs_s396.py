"""specs_s396.py - core batch 396: 0x46f690 ZItemTemplateAmmo::Load (thiscall, one stack argument, ret 4; returns true).
The base load 0x440e10 is hooked by address and logged (stdcall, one argument; GUESS: not ported). The loader object has a
logging vtable: slot 0x70 (one argument), slot 0x40 (one argument), slot 0x18 (two arguments). The item block has random bytes."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import engine_stubs as E
import pe_emu


def _nostack(x):
    return 'stack' if pe_emu.STACK_TOP - pe_emu.STACK_SIZE <= x < pe_emu.STACK_TOP else x


def _setup(c):
    c.emu.hook(0x440e10, lambda em, r: (em.calllog.append(('base440e10', 0, 0, (em.arg32(0),))), em.ret(eax=0, argbytes=4)))


def _gen(c):
    r = c.rng
    nargs = {0x70: 1, 0x40: 1, 0x18: 2}
    slots = {}
    for i in range(0x80 // 4):
        off = 4 * i

        def h(e, rr, off=off):
            n = nargs.get(off, 0)
            args = [e.arg32(k) for k in range(n)]
            e.calllog.append(('LOADER', off, e.reg('ecx'), tuple(_nostack(x) for x in args)))
            e.ret(eax=0, argbytes=4 * n)
        slots[off] = h
    loader_vt = c.emu.fake_vtable('LOADER', 0x80 // 4, slots)
    loader = E.zero_obj(c, 0x40)
    c.emu.w32(loader, loader_vt)
    item = E.zero_obj(c, 0x100)
    c.emu.wbytes(item, bytes(r.getrandbits(8) for _ in range(0x100)))
    c.emu.mu.ctl_flush_tb()
    return [item, loader]


S(0x46f690, 'ZItemTemplateAmmo::Load (core) thiscall', 'thiscall', None, ret='al', gen=_gen, setup=_setup,
  note='core batch 396; base load 0x440e10 hooked (GUESS); loader vtable mocked')
