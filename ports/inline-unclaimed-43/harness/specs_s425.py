"""specs_s425.py - residue 2 row 0x5553e0 (stdcall, one stack argument a, ret 4; no return value). G at global 0x7003b8 holds S at
+0x2c15 (0 in about 20% of cases, so the early return is covered). 0x59b3c0 is hooked by address (GUESS: thiscall, no arguments,
logs ECX and returns a dword drawn in gen). X = dword [[0x70039c]+0x9b] has a logging vtable whose slot 0x4c takes one argument
and returns a random w. a+8 is a two-level array as in batch 329; 0x5003d0 and 0x5002f0 run as original exe code, and element 0's
type byte (+4) is 0 or 1 so 0x5002f0 stays off its printer path."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import engine_stubs as E
import pe_emu

SHARED = {'r': 0, 'w': 0}


def _nostack(x):
    return 'stack' if pe_emu.STACK_TOP - pe_emu.STACK_SIZE <= x < pe_emu.STACK_TOP else x


def _vt(c, name, slots_spec, n=0x60):
    slots = {}
    for i in range(n // 4):
        slots[4 * i] = (lambda e, rr: e.ret(eax=0, argbytes=0))
    slots.update(slots_spec)
    return c.emu.fake_vtable(name, n // 4, slots)


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


def _setup(c):
    def h59b3(em, rr):
        em.calllog.append(('get59b3c0', 0, em.reg('ecx') & 0xffffffff, ()))
        em.ret(eax=SHARED['r'], argbytes=0)
    c.emu.hook(0x59b3c0, h59b3)


def _gen(c):
    r = c.rng
    SHARED['r'] = r.getrandbits(32)
    SHARED['w'] = r.getrandbits(32)

    def h4c(e, rr):
        e.calllog.append(('X4C', 0x4c, e.reg('ecx') & 0xffffffff, (e.arg32(0),)))
        e.ret(eax=SHARED['w'], argbytes=4)
    X = E.zero_obj(c, 0x40)
    c.emu.w32(X, _vt(c, 'XOBJ', {0x4c: h4c}))
    world = E.zero_obj(c, 0x100)
    c.emu.w32(world + 0x9b, X)
    E.set_global(c, 0x70039c, world)
    g = E.zero_obj(c, 0x2c20)
    sel = E.zero_obj(c, 0x40)
    c.emu.w32(g + 0x2c15, sel if r.random() < 0.8 else 0)
    E.set_global(c, 0x7003b8, g)
    a = E.zero_obj(c, 0x40)
    c.emu.w32(a + 8, _array(c, r.randrange(1, 4)))
    c.emu.mu.ctl_flush_tb()
    return [a]


S(0x5553e0, 'selection value into element 0 via 0x5002f0 (residue 2) stdcall', 'stdcall', None, ret=None, gen=_gen, setup=_setup,
  note='residue 2 batch 425; 0x59b3c0 hooked (GUESS); 0x5003d0 and 0x5002f0 are original exe code')
