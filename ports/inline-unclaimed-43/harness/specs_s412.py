"""specs_s412.py - residue 2 row 0x4b16a0 (thiscall, one unused stack argument, ret 4, returns true). The global callback at 0x7003b0 is always a
logging stub (the NULL case is an exe trap, not drawn); the object's vtable slot 0x84 is a logging mock taking one argument. The
object's +4 dword is random, so the bit 6 clear shows in the heap compare."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import engine_stubs as E
import pe_emu


def _nostack(x):
    return 'stack' if pe_emu.STACK_TOP - pe_emu.STACK_SIZE <= x < pe_emu.STACK_TOP else x


def _gen(c):
    r = c.rng
    slots = {}

    def h84(e, rr):
        e.calllog.append(('SLOT84', 0x84, e.reg('ecx') & 0xffffffff, (e.arg32(0),)))
        e.ret(eax=0, argbytes=4)
    for i in range(0x88 // 4 + 1):
        slots[4 * i] = h84 if 4 * i == 0x84 else (lambda e, rr: e.ret(eax=0, argbytes=0))
    vt = c.emu.fake_vtable('NOTIFY', 0x88 // 4 + 1, slots)
    o = E.zero_obj(c, 0x40)
    c.emu.wbytes(o, bytes(r.getrandbits(8) for _ in range(0x40)))
    c.emu.w32(o, vt)
    # The NULL case is not drawn: the exe traps (int3 at 0x4b16c4) when 0x7003b0 is NULL, and the port does not reproduce that.
    stub = c.emu._new_stub('notify7003b0', lambda e, rr: (e.calllog.append(('NOTIFY', 0, e.reg('ecx') & 0xffffffff, ())),
                                                         e.ret(eax=0, argbytes=0)))
    E.set_global(c, 0x7003b0, stub)
    c.emu.mu.ctl_flush_tb()
    return [o, r.getrandbits(32)]


S(0x4b16a0, 'clear flag, optional notify, vtable slot 0x84 (residue 2) thiscall', 'thiscall', None, ret='al', gen=_gen,
  note='residue 2 batch 412; global callback 0x7003b0 stub or NULL; vtable mocked')
