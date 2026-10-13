"""specs_s760.py - gap band batch 760 (docs/20-gap-band-401000.md): 0x41ce80, the _exit path. The global object [0x700390] has slot 0x20
(two args, logged, returns an object R whose vtable has slot 0x2c, caller-cleaned, two args, logged). The import slot 0x676394 (_exit) is a
stub that logs its argument and then returns to the caller of 0x41ce80 (the real process would end there: the spec models that as a return
so that the calls before it are compared)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from unicorn.x86_const import UC_X86_REG_ESP


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _setup(c):
    v_vt = c.emu.fake_vtable('g760-v', 0x100, {0x2c: lambda e, r: (e.calllog.append(('0x2c', tuple(e.arg32(k) for k in range(2)))),
                                                                  e.ret(eax=0, argbytes=0))[-1]})
    R = _rnd(c, 0x40)
    c.emu.w32(R, v_vt)
    g_vt = c.emu.fake_vtable('g760-g', 0x100, {0x20: lambda e, r: (e.calllog.append(('0x20', tuple(e.arg32(k) for k in range(2)))),
                                                                  e.ret(eax=R, argbytes=8))[-1]})
    g = _rnd(c, 0x40)
    c.emu.w32(g, g_vt)
    c.emu.w32(0x700390, g)

    def exit_stub(e, r):
        e.calllog.append(('_exit', e.arg32(0)))
        esp = e.reg('esp')
        e.mu.reg_write(UC_X86_REG_ESP, (esp + 8) & 0xffffffff)
        e.ret(eax=0, argbytes=0)                        # pops the caller's return address and continues there
    c.emu.w32(0x676394, c.emu.stub_fn('_exit model', exit_stub))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


S(0x41ce80, 'CRT exit path 0x41ce80 (unknown) cdecl', 'cdecl', None, ret=None, gen=lambda c: [], setup=_setup,
  note='gap band batch 760: two vtable calls then _exit(1) (modelled as a return)')
