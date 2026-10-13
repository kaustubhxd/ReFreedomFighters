"""specs_s414.py - residue 2 rows 0x4a80a0 (thiscall, no arguments, returns this) and 0x60fe20 (cdecl, no arguments).
0x4a80a0 calls 0x469870 (exe, hooked by address and logged; GUESS: body not ported), then sets flags and the vtable (no mocks
needed). 0x60fe20 compares the two globals 0x724958 and 0x724950; when they differ it stores the first and calls slot 0xc8 of
the object at global 0x724a00 with ECX = its vtable and arguments (obj, 0x22, value). The slot is a logging mock (three
stack arguments, ret 12)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import engine_stubs as E
import pe_emu


def _nostack(x):
    return 'stack' if pe_emu.STACK_TOP - pe_emu.STACK_SIZE <= x < pe_emu.STACK_TOP else x


def _setup_a(c):
    c.emu.hook(0x469870, lambda em, r: (em.calllog.append(('a469870', 0, em.reg('ecx') & 0xffffffff, ())),
                                        em.ret(eax=0, argbytes=0)))


def _gen_a(c):
    o = E.zero_obj(c, 0x60)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x60)))
    c.emu.mu.ctl_flush_tb()
    return [o]


def _setup_b(c):
    pass


def _gen_b(c):
    r = c.rng
    slots = {}

    def h(e, rr):
        e.calllog.append(('SLOTC8', 0xc8, e.reg('ecx') & 0xffffffff, (_nostack(e.arg32(0)), e.arg32(1), e.arg32(2))))
        e.ret(eax=0, argbytes=12)
    for i in range(0xcc // 4 + 1):
        slots[4 * i] = h if 4 * i == 0xc8 else (lambda e, rr: e.ret(eax=0, argbytes=0))
    vt = c.emu.fake_vtable('SLOTC8', 0xcc // 4 + 1, slots)
    obj = E.zero_obj(c, 0x40)
    c.emu.w32(obj, vt)
    E.set_global(c, 0x724a00, obj)
    cur = r.getrandbits(32)
    E.set_global(c, 0x724958, cur)
    E.set_global(c, 0x724950, cur if r.random() < 0.4 else r.getrandbits(32))
    c.emu.mu.ctl_flush_tb()
    return []


S(0x4a80a0, 'init with vtable 0x6901b0 (residue 2) thiscall', 'thiscall', None, ret='eax', gen=_gen_a, setup=_setup_a,
  note='residue 2 batch 414; callee 0x469870 hooked (GUESS)')
S(0x60fe20, 'compare globals and call slot 0xc8 (residue 2) cdecl', 'cdecl', None, ret=None, gen=_gen_b, setup=_setup_b,
  note='residue 2 batch 414; vtable slot 0xc8 mocked')
