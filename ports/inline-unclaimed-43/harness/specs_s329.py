"""specs_s329.py - area 71 batch 329: 0x559f60, thiscall, one stack argument, ret 4. this+0x1c is a logging object whose slot
0x6f8 returns a value v; arg+8 is a two-level array (as in batch 305); element 0 is the element passed to 0x5002f0 (original
code), whose type byte (+4) must be 0 or 1 (other values reach its printer). v is passed to 0x5002f0 as its stack argument."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import engine_stubs as E
import pe_emu


def _nostack(x):
    return 'stack' if pe_emu.STACK_TOP - pe_emu.STACK_SIZE <= x < pe_emu.STACK_TOP else x


def _array(c, n):
    data = c.emu.alloc(8 * n + 16, 8)
    c.emu.wbytes(data, bytes(c.rng.getrandbits(8) for _ in range(8 * n + 16)))
    c.emu.wbytes(data + 4, bytes([c.rng.randrange(2)]))   # element 0 type byte: 0 or 1
    t = E.zero_obj(c, 0x20)
    c.emu.w32(t, data)
    c.emu.w32(t + 8, n)
    a = E.zero_obj(c, 0x20)
    c.emu.w32(a, t)
    c.emu.w32(a + 4, 0)
    c.emu.w32(a + 8, n)
    return a


def _gen(c):
    r = c.rng
    v = r.getrandbits(32)
    obj = E.zero_obj(c, 0x40)
    slots = {}
    for i in range(0x6f8 // 4 + 1):
        off = 4 * i

        def h(e, rr, off=off):
            e.calllog.append(('ZVCALLOBJ', off, e.reg('ecx'), ()))
            e.ret(eax=v if off == 0x6f8 else 0, argbytes=0)
        slots[off] = h
    c.emu.w32(obj, c.emu.fake_vtable('ZVCALLOBJ', 0x6f8 // 4 + 1, slots))
    this = E.zero_obj(c, 0x40)
    c.emu.w32(this + 0x1c, obj)
    arg = E.zero_obj(c, 0x40)
    c.emu.w32(arg + 8, _array(c, r.randrange(1, 4)))
    c.emu.mu.ctl_flush_tb()
    return [this, arg]


S(0x559f60, 'vcall 0x6f8 then 0x5002f0 on element 0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='area 71 batch 329 (leaf, residue 10); 0x5002f0 and 0x5003d0 are original exe code')
