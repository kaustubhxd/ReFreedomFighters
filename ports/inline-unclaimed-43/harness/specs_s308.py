"""specs_s308.py - unclaimed-43 batch 308: ZGROUP::DrawDebugObjects (0x43fe60), thiscall, four stack arguments, ret 0x10.
The object's flags dword (+0x14) picks the two parts: bit 0 -> the matrix product and translation; bits 2 and 3 -> the
vtable call on a1 (slot 0xd8). The mock logs the twelve bytes at each of the call's two temporary-vector pointers
(stack addresses are logged as 'stack'; their contents are compared), so the temporaries are checked bit for bit.
Flags come from a small set that covers all four combinations of the two tests."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import engine_stubs as E
import pe_emu

NSLOTS_A1 = 0xdc // 4         # slot 0xd8


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


def _dd(e, a):
    # a = [a3, &t1, &t2]: log the contents of both temporaries
    e.calllog.append(('dd_tmp', 0, 0, (e.rbytes(a[1], 12), e.rbytes(a[2], 12))))
    return (None, None)


def _gen(c):
    r = c.rng
    self_ = E.zero_obj(c, 0x100)
    flags = r.choice([0, 1, 2, 4, 5, 8, 9, 12, 13, 3, 0x11, 0x1d])
    c.emu.w32(self_ + 0x14, flags)
    m8 = E.zero_obj(c, 0x100)
    for k in range(0x30 // 4, 0x50 // 4):
        c.emu.wf32(m8 + 4 * k, c.fv(-20.0, 20.0))
    c.emu.w32(self_ + 8, m8)
    a1 = E.zero_obj(c, 0x40)
    a1vt = _vtable(c, 'ZDRAWDEBUGOBJ', NSLOTS_A1, {0xd8: _dd}, {0xd8: 3})
    c.emu.w32(a1, a1vt)
    a2 = r.getrandbits(32)
    a3 = c.fbuf(12)
    a4 = c.fbuf(3)
    c.emu.mu.ctl_flush_tb()
    return [self_, a1, a2, a3, a4]


S(0x43fe60, 'ZGROUP::DrawDebugObjects (GUESS name; 4 stack args)', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-43 batch 308; vmmul 0x441970 and PSVECAdd 0x441940 are original exe code')
