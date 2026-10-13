"""specs_s803.py - gap band batch 803 (docs/20-gap-band-401000.md): 0x41fa40, thiscall (this, a). The slot 0x20 of [0x70038c] (one arg, callee pops 4)
returns 0 or 1; the range guard as 0x41f320 (the callback is a logging stub); 0x41f190 is a thiscall logging stub (one argument); the object
[0x700390] has slot 0x34 (two args, caller-cleaned, logged). The count at a-0xc is 0, 1 or 2 before the decrement."""
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
    G_vt = c.emu.fake_vtable('g803-g', 0x200, {0x20: lambda e, r: (e.calllog.append(('0x20', e.arg32(0))), e.ret(eax=(seed >> (e.arg32(0) & 7)) & 1, argbytes=4))[-1]})
    G = _rnd(c, 0x40)
    c.emu.w32(G, G_vt)
    c.emu.w32(0x70038c, G)
    O_vt = c.emu.fake_vtable('g803-o', 0x200, {0x34: lambda e, r: (e.calllog.append(('0x34', e.reg('ecx'), (e.arg32(0), e.arg32(1)))), e.ret(eax=0, argbytes=0))[-1]})
    O = _rnd(c, 0x40)
    c.emu.w32(O, O_vt)
    c.emu.w32(0x700390, O)
    cb = c.emu.stub_fn('7003b0 callback', lambda e, r: (e.calllog.append(('cb',)), e.ret(eax=0, argbytes=0)))
    c.emu.w32(0x7003b0, cb)
    ss.patch(c, 0x41f190, c.emu.stub_fn('41f190 logger', lambda e, r: (e.calllog.append(('0x41f190', e.reg('ecx'), (e.arg32(0),))), e.ret(eax=0, argbytes=4))))
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
    a = c.rng.choice([e + 0x40, e + 0x10, e + 0x80])
    c.emu.w32(a - 0xc, c.rng.choice([0, 1, 2]))
    this = _rnd(c, 0x40)
    return [this, a]


S(0x41fa40, 'CRT helper 0x41fa40 (unknown) thiscall', 'thiscall', None, ret='al', gen=_gen, setup=_setup,
  note='gap band batch 803: guard, callback, count decrement, thiscall, bool from the count')
