"""specs_s420.py - residue 2 row 0x54bde0 (thiscall, one stack argument out, ret 4, returns a bool). The object's vtable slot 0x34
is a logging mock returning a dword drawn in gen. The divisor is dword +0x10 >> 1, drawn 1..0x8000 (never zero), and the stored
quotient at +0x63dc is either the computed quotient (about one case in three, so the return-0 path runs) or random."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import engine_stubs as E
import pe_emu

SHARED = {'v': 0}


def _nostack(x):
    return 'stack' if pe_emu.STACK_TOP - pe_emu.STACK_SIZE <= x < pe_emu.STACK_TOP else x


def _vt(c):
    def h(e, rr):
        e.calllog.append(('SLOT34', 0x34, e.reg('ecx') & 0xffffffff, ()))
        e.ret(eax=SHARED['v'], argbytes=0)
    slots = {}
    for i in range(0x64 // 4):
        slots[4 * i] = h if 4 * i == 0x34 else (lambda e, rr: e.ret(eax=0, argbytes=0))
    return c.emu.fake_vtable('SLOT34', 0x64 // 4, slots)


def _gen(c):
    r = c.rng
    SHARED['v'] = r.getrandbits(32)
    d = r.randint(1, 0x8000)
    o = E.zero_obj(c, 0x7000)
    c.emu.wbytes(o, bytes(r.getrandbits(8) for _ in range(0x7000)))
    c.emu.w32(o, _vt(c))
    c.emu.w32(o + 0x10, (d << 1) | (r.getrandbits(1)))
    if r.random() < 0.33:
        q = (SHARED['v'] // d) & 0xffffffff
        c.emu.w32(o + 0x63dc, q)
    else:
        c.emu.w32(o + 0x63dc, r.getrandbits(32))
    out = E.zero_obj(c, 0x10)
    c.emu.mu.ctl_flush_tb()
    return [o, out]


S(0x54bde0, 'scaled quotient of a vtable value (residue 2) thiscall', 'thiscall', None, ret='al', gen=_gen,
  note='residue 2 batch 420; vtable slot 0x34 mocked')
