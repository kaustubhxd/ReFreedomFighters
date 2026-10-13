"""specs_s800.py - gap band batch 800 (docs/20-gap-band-401000.md): 0x41f6a0, thiscall (this, xp). The argument x sits in a block with a count at
x-0xc (0 to 2) and a size word at x-8; the range guard uses the global object as in 0x41f320; the callback 0x7003b0 is a logging stub; slot 8 of this
returns a fixed block (one argument, callee pops 4); the copy 0x634d22 is a logging stub."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _rnd(c, n):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _setup(c):
    import serial_stubs as ss
    blk = _rnd(c, 0x100)
    this_vt = c.emu.fake_vtable('g800-this', 0x100, {0x8: lambda e, r: (e.calllog.append(('0x8', e.arg32(0))), e.ret(eax=blk, argbytes=4))[-1]})
    this = _rnd(c, 0x80)
    c.emu.w32(this, this_vt)
    c.thisobj = this
    cb = c.emu.stub_fn('7003b0 callback', lambda e, r: (e.calllog.append(('cb',)), e.ret(eax=0, argbytes=0)))
    c.emu.w32(0x7003b0, cb)
    ss.patch(c, 0x634d22, c.emu.stub_fn('634d22 logger', lambda e, r: (e.calllog.append(('0x634d22', (e.arg32(0), e.arg32(1), e.arg32(2)))), e.ret(eax=0, argbytes=0))))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen(c):
    e_base = c.emu.alloc(0x110, 4)
    c.emu.wbytes(e_base, bytes(c.rng.getrandbits(8) for _ in range(0x110)))
    e = e_base + 8
    c.emu.w32(e_base, c.rng.randint(0, 0x40))
    obj = _rnd(c, 0x2000)
    c.emu.w32(obj + 0x1c5d, e if c.rng.random() < 0.8 else 0)
    render = _rnd(c, 0xa00)
    c.emu.w32(render + 0x9b, obj)
    c.emu.w32(0x70039c, render)
    rec = _rnd(c, 0x40)
    x = c.rng.choice([e + 0x40, e + 0x10])
    c.emu.w32(x - 0xc, c.rng.choice([0, 1, 2]))
    c.emu.w32(x - 8, c.rng.randint(0, 0x30))
    xp = _rnd(c, 0x10)
    c.emu.w32(xp, x)
    return [c.thisobj, xp]


S(0x41f6a0, 'CRT helper 0x41f6a0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='gap band batch 800: range guard, optional copy into a fresh block, count decrement')
