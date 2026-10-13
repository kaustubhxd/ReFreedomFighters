"""specs_s416.py - residue 2 rows 0x4b58e0 (thiscall, no args) and 0x4cb6e0 (thiscall, one stack argument obj, ret 4).
Exe callees: 0x6352f0 (stdcall one argument, GUESS: stores a dword through its pointer; hooked), 0x4e5e40 (thiscall returning a
word in ax; GUESS, hooked, returns the drawn words in order), and slot 0x84 of the object (logging vtable mock, one argument)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import engine_stubs as E
import pe_emu

SHARED = {'v': 0, 'words': [0, 0]}


def _nostack(x):
    return 'stack' if pe_emu.STACK_TOP - pe_emu.STACK_SIZE <= x < pe_emu.STACK_TOP else x


def _setup_common(c):
    def h6352(em, r):
        p = em.arg32(0)
        em.calllog.append(('get6352f0', 0, 0, (_nostack(p),)))
        em.mu.mem_write(p, SHARED['v'].to_bytes(4, 'little'))
        em.ret(eax=0, argbytes=4)

    def h4e5e(em, r):
        em.calllog.append(('w4e5e40', 0, em.reg('ecx') & 0xffffffff, ()))
        w = SHARED['words'].pop(0)
        em.ret(eax=w, argbytes=0)
    c.emu.hook(0x6352f0, h6352)
    c.emu.hook(0x4e5e40, h4e5e)


def _vt84(c):
    def h(e, rr):
        e.calllog.append(('SLOT84', 0x84, e.reg('ecx') & 0xffffffff, (_nostack(e.arg32(0)), int.from_bytes(e.mu.mem_read(e.arg32(0), 4), 'little'))))
        e.ret(eax=0, argbytes=4)
    slots = {}
    for i in range(0x88 // 4):
        slots[4 * i] = h if 4 * i == 0x84 else (lambda e, rr: e.ret(eax=0, argbytes=0))
    return c.emu.fake_vtable('SLOT84', 0x88 // 4, slots)


def _setup_a(c):
    _setup_common(c)


def _gen_a(c):
    r = c.rng
    SHARED['v'] = r.getrandbits(32)
    o = E.zero_obj(c, 0x80)
    c.emu.wbytes(o, bytes(r.getrandbits(8) for _ in range(0x80)))
    c.emu.w32(o, _vt84(c))
    c.emu.mu.ctl_flush_tb()
    return [o]


def _setup_b(c):
    _setup_common(c)


def _gen_b(c):
    r = c.rng
    SHARED['words'] = [r.getrandbits(16), r.getrandbits(16)]
    o = E.zero_obj(c, 0x80)
    c.emu.wbytes(o, bytes(r.getrandbits(8) for _ in range(0x80)))
    obj = E.zero_obj(c, 0x20)
    c.emu.mu.ctl_flush_tb()
    return [o, obj]


S(0x4b58e0, 'out-value getter then vtable slot 0x84 (residue 2) thiscall', 'thiscall', None, ret=None, gen=_gen_a,
  setup=_setup_a, note='residue 2 batch 416; callee 0x6352f0 and 0x4e5e40 hooked (GUESS)')
S(0x4cb6e0, 'two word reads into +0x50 and +0x52 (residue 2) thiscall', 'thiscall', None, ret=None, gen=_gen_b,
  setup=_setup_b, note='residue 2 batch 416; callee 0x4e5e40 hooked (GUESS)')
