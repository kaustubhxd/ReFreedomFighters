"""specs_s313.py - unclaimed-43 batch 313: ZInputActions::PrintActionDebugInfo (0x439f60), thiscall, one stack argument, ret 4.
Mocks: this slot 0x58(name) returns the action record A (or NULL); the printer at 0x700390 returns an object whose
vtable slot 0x2c is a cdecl five-argument printer (logged, no output). A's dword at +0 must be 0 for the print path;
+4 is a heap string pointer; +0x2e and +0x2f are random bytes (they select true/false)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import engine_stubs as E
import pe_emu


def _nostack(x):
    return 'stack' if pe_emu.STACK_TOP - pe_emu.STACK_SIZE <= x < pe_emu.STACK_TOP else x


def _vtable(c, name, nslots, impl, argwords, cdecl=()):
    slots = {}
    for i in range(nslots):
        off = 4 * i

        def h(e, r, off=off):
            n = argwords.get(off, 0)
            args = [e.arg32(k) for k in range(n)]
            e.calllog.append((name, off, e.reg('ecx'), tuple(_nostack(x) for x in args)))
            f = impl.get(off)
            eax, st0 = (f(e, args) if f else (0, None))
            e.ret(eax=eax, argbytes=0 if off in cdecl else 4 * n, st0=st0)
        slots[off] = h
    return c.emu.fake_vtable(name, nslots, slots)


def _gen(c):
    r = c.rng
    this = E.zero_obj(c, 0x40)
    act = 0 if r.random() < 0.15 else E.zero_obj(c, 0x40)
    if act:
        c.emu.w32(act, 0 if r.random() < 0.85 else 1)
        s = c.emu.alloc(16, 1)
        c.emu.wbytes(s, b'actionname\0')
        c.emu.w32(act + 4, s)
        hb = r.choice([0x7f, 0x80, 0x81, r.getrandbits(8)])   # the hold test is at 0x80: hit the boundary explicitly
        c.emu.wbytes(act + 0x2e, bytes([hb, r.getrandbits(8)]))
    thvt = _vtable(c, 'ZINPUTACTIONS', 0x58 // 4 + 1, {0x58: lambda e, a: (act, None)}, {0x58: 1})
    c.emu.w32(this, thvt)
    obj = E.zero_obj(c, 0x40)
    pvt = _vtable(c, 'ZPRINTOBJ', 0x2c // 4 + 1, {}, {0x2c: 5}, cdecl=(0x2c,))
    c.emu.w32(obj, pvt)
    printer = E.zero_obj(c, 0x40)
    printvt = _vtable(c, 'ZPRINTER', 0x20 // 4 + 1, {0x20: lambda e, a: (obj, None)}, {0x20: 2})
    c.emu.w32(printer, printvt)
    E.set_global(c, 0x700390, printer)
    name = c.emu.alloc(16, 1)
    c.emu.wbytes(name, b'query\0')
    c.emu.mu.ctl_flush_tb()
    return [this, name]


S(0x439f60, 'ZInputActions::PrintActionDebugInfo(char*)', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-43 batch 313 (core residue-02); printer slot 0x2c is cdecl with five arguments')
