"""specs_s422.py - residue 2 row 0x565a60 (thiscall, no arguments). The engine object at global 0x70039c has A at +0x9b; A's
vtable slot 0x138 returns object B (logging mock); B's vtable slot 0x88 (two arguments) writes a random dword through its second
argument (a stack address, so the value comes back through the local) and logs its arguments. The callee 0x563a50 is hooked and
logged (GUESS: body not ported)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import engine_stubs as E
import pe_emu

SHARED = {'v': 0}


def _nostack(x):
    return 'stack' if pe_emu.STACK_TOP - pe_emu.STACK_SIZE <= x < pe_emu.STACK_TOP else x


def _setup(c):
    c.emu.hook(0x563a50, lambda em, r: (em.calllog.append(('d563a50', 0, em.reg('ecx') & 0xffffffff, ())), em.ret(eax=0, argbytes=0)))


def _vt(c, name, slots_spec):
    slots = {}
    for i in range(0x140 // 4):
        slots[4 * i] = (lambda e, rr: e.ret(eax=0, argbytes=0))
    for off, fn in slots_spec.items():
        slots[off] = fn
    return c.emu.fake_vtable(name, 0x140 // 4, slots)


def _gen(c):
    r = c.rng
    SHARED['v'] = r.getrandbits(32)
    B = E.zero_obj(c, 0x20)

    def h88(e, rr):
        ptr = e.arg32(1)
        e.calllog.append(('SLOTB88', 0x88, e.reg('ecx') & 0xffffffff, (e.arg32(0), _nostack(ptr))))
        e.mu.mem_write(ptr, SHARED['v'].to_bytes(4, 'little'))
        e.ret(eax=0, argbytes=8)
    c.emu.w32(B, _vt(c, 'OBJB', {0x88: h88}))

    def h138(e, rr):
        e.calllog.append(('SLOTA138', 0x138, e.reg('ecx') & 0xffffffff, ()))
        e.ret(eax=B, argbytes=0)
    A = E.zero_obj(c, 0x20)
    c.emu.w32(A, _vt(c, 'OBJA', {0x138: h138}))
    eng = E.zero_obj(c, 0xa0)
    c.emu.w32(eng + 0x9b, A)
    E.set_global(c, 0x70039c, eng)
    o = E.zero_obj(c, 0xd00)
    c.emu.wbytes(o, bytes(r.getrandbits(8) for _ in range(0xd00)))
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x565a60, 'engine loader object and value into +0xcae (residue 2) thiscall', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='residue 2 batch 422; objects A and B mocked; callee 0x563a50 hooked (GUESS)')
