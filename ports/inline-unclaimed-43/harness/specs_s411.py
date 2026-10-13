"""specs_s411.py - residue 2 rows 0x4d2b20 (stdcall(a, b): al = 0x4d2b40(a, b) != 0) and 0x4c3260 (thiscall: stores vtable slot
0x100 of [this+0x48] called with 0x693df8 at [this+0x4c]). Callee 0x4d2b40 is hooked and logged (GUESS: body not ported); the
vtable of the object at +0x48 is a logging mock returning a dword drawn in gen."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import engine_stubs as E
import pe_emu

SHARED = {'ret': 0, 'slot': 0}


def _nostack(x):
    return 'stack' if pe_emu.STACK_TOP - pe_emu.STACK_SIZE <= x < pe_emu.STACK_TOP else x


def _setup_a(c):
    c.emu.hook(0x4d2b40, lambda em, r: (em.calllog.append(('t4d2b40', 0, 0, (em.arg32(0), em.arg32(1)))),
                                        em.ret(eax=SHARED['ret'], argbytes=8)))


def _gen_a(c):
    r = c.rng
    SHARED['ret'] = r.choice([0, 1, 2, 0x80000000, 0x100]) if r.random() < 0.6 else r.getrandbits(32)
    c.emu.mu.ctl_flush_tb()
    return [r.getrandbits(32), r.getrandbits(32)]


def _setup_b(c):
    pass


def _gen_b(c):
    r = c.rng
    SHARED['slot'] = r.getrandbits(32)
    slots = {}

    def h(e, rr):
        e.calllog.append(('SLOT100', 0x100, e.reg('ecx') & 0xffffffff, (e.arg32(0),)))
        e.ret(eax=SHARED['slot'], argbytes=4)
    for i in range(0x104 // 4):
        slots[4 * i] = (h if 4 * i == 0x100 else (lambda e, rr: e.ret(eax=0, argbytes=0)))
    vt = c.emu.fake_vtable('SLOT', 0x104 // 4, slots)
    obj = E.zero_obj(c, 0x40)
    c.emu.w32(obj, vt)
    o = E.zero_obj(c, 0x60)
    c.emu.wbytes(o, bytes(r.getrandbits(8) for _ in range(0x60)))
    c.emu.w32(o + 0x48, obj)
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x4d2b20, 'nonzero result of 0x4d2b40 (residue 2) stdcall', 'stdcall', None, ret='al', gen=_gen_a, setup=_setup_a,
  note='residue 2 batch 411; callee 0x4d2b40 hooked (GUESS)')
S(0x4c3260, 'store slot 0x100 result at +0x4c (residue 2) thiscall', 'thiscall', None, ret=None, gen=_gen_b, setup=_setup_b,
  note='residue 2 batch 411; vtable mocked')
