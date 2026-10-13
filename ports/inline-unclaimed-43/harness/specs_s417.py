"""specs_s417.py - residue 2 rows 0x626da0 (cdecl, ten arguments; calls 0x628810 with 0x628a70 and the ten arguments) and
0x566820 (thiscall, no arguments; conditional slot 0x12c call on the object at +0x44). 0x628810 is hooked and logged (GUESS: body
not ported); its eleven arguments are checked in the log. The slot 0x12c is a logging mock (three arguments)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import engine_stubs as E


def _setup_a(c):
    c.emu.hook(0x628810, lambda em, r: (em.calllog.append(('f628810', 0, 0, tuple(em.arg32(k) for k in range(11)))),
                                        em.ret(eax=0, argbytes=0)))


def _gen_a(c):
    r = c.rng
    c.emu.mu.ctl_flush_tb()
    return [r.getrandbits(32) for _ in range(10)]


def _vt12c(c):
    def h(e, rr):
        e.calllog.append(('SLOT12C', 0x12c, e.reg('ecx') & 0xffffffff, (e.arg32(0), e.arg32(1), e.arg32(2))))
        e.ret(eax=0, argbytes=12)
    slots = {}
    for i in range(0x130 // 4):
        slots[4 * i] = h if 4 * i == 0x12c else (lambda e, rr: e.ret(eax=0, argbytes=0))
    return c.emu.fake_vtable('SLOT12C', 0x130 // 4, slots)


def _gen_b(c):
    r = c.rng
    o = E.zero_obj(c, 0xa10)
    c.emu.wbytes(o, bytes(r.getrandbits(8) for _ in range(0xa10)))
    c.emu.wbytes(o + 0xa0c, bytes([r.choice([0, 1])]))
    obj = E.zero_obj(c, 0x40)
    c.emu.w32(obj, _vt12c(c))
    c.emu.w32(o + 0x44, obj)
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x626da0, 'wrapper of 0x628810 with ten arguments (residue 2) cdecl', 'cdecl', None, ret=None, gen=_gen_a, setup=_setup_a,
  note='residue 2 batch 417; callee 0x628810 hooked (GUESS)')
S(0x566820, 'conditional slot 0x12c call on +0x44 (residue 2) thiscall', 'thiscall', None, ret=None, gen=_gen_b,
  note='residue 2 batch 417; vtable slot 0x12c mocked')
