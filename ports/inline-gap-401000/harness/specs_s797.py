"""specs_s797.py - gap band batch 797 (docs/20-gap-band-401000.md): 0x41f320, thiscall (this, a). The slot 0x20 of [0x70038c] (one argument,
callee pops 4) returns 0 or 1 per case; the object at [0x70039c]+0x9b has e at +0x1c5d (a block with a size word at e-8); the callback at
0x7003b0 is a logging stub; 0x41f190 is a thiscall logging stub (one argument). a is inside or outside the block, and a-0xc is readable."""
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
    seed = c.rng.getrandbits(32)
    G_vt = c.emu.fake_vtable('g797-g', 0x200, {0x20: lambda e, r: (e.calllog.append(('0x20', e.arg32(0))), e.ret(eax=(seed >> (e.arg32(0) & 7)) & 1, argbytes=4))[-1]})
    G = _rnd(c, 0x40)
    c.emu.w32(G, G_vt)
    c.emu.w32(0x70038c, G)
    cb = c.emu.stub_fn('7003b0 callback', lambda e, r: (e.calllog.append(('cb',)), e.ret(eax=0, argbytes=0)))
    c.emu.w32(0x7003b0, cb)
    ss.patch(c, 0x41f190, c.emu.stub_fn('41f190 logger', lambda e, r: (e.calllog.append(('0x41f190', e.reg('ecx'), (e.arg32(0),))), e.ret(eax=0, argbytes=4))))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen(c):
    e = c.emu.alloc(0x110, 4)
    c.emu.wbytes(e, bytes(c.rng.getrandbits(8) for _ in range(0x110)))
    c.emu.w32(e - 8 if False else e, c.rng.randint(0, 0x80))
    base = e + 8
    c.emu.w32(base, c.rng.randint(0, 0x80))
    obj = _rnd(c, 0x2000)
    c.emu.w32(obj + 0x1c5d, base)
    render = _rnd(c, 0xa00)
    c.emu.w32(render + 0x9b, obj)
    c.emu.w32(0x70039c, render)
    a = c.rng.choice([base + 0x40, base + 0x10, base + 0x80])
    c.emu.w32(a - 0xc, c.rng.getrandbits(32))
    this = _rnd(c, 0x40)
    return [this, a]


S(0x41f320, 'CRT helper 0x41f320 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='gap band batch 797: range check, optional callback, count bump, thiscall 0x41f190')
