"""specs_s790.py - gap band batch 790 (docs/20-gap-band-401000.md): 0x41f4a0, stdcall (a). The render object's +0x9b object has +0x1c5d (a pointer e)
which may be 0 or a block with a size word at e-8; the callback [0x7003b0] is a logging stub; the global 0x70038c has slot 0x20 (one argument,
callee pops 4) returning 0 or 1 per case. a is random near e in some cases so both range tests run."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _setup(c):
    import serial_stubs as ss
    cb = c.emu.stub_fn('7003b0 callback', lambda e, r: (e.calllog.append(('cb',)), e.ret(eax=0, argbytes=0)))
    c.emu.w32(0x7003b0, cb)
    seed = c.rng.getrandbits(32)
    G_vt = c.emu.fake_vtable('g790-g', 0x100, {0x20: lambda e, r: (e.calllog.append(('0x20', e.arg32(0))),
                                                                  e.ret(eax=(seed >> (e.arg32(0) & 7)) & 1, argbytes=4))[-1]})
    G = c.emu.alloc(0x40, 4)
    c.emu.w32(G, G_vt)
    c.emu.w32(0x70038c, G)
    obj = c.emu.alloc(0x2000, 4)
    c.emu.wbytes(obj, bytes(c.rng.getrandbits(8) for _ in range(0x2000)))
    # the range block: e = base + 8, with the size word (low 29 bits) at e - 8; obj+0x1c5d holds e in most cases
    base = c.emu.alloc(0x110, 4)
    c.emu.wbytes(base, bytes(c.rng.getrandbits(8) for _ in range(0x110)))
    c.emu.w32(base, c.rng.randint(0, 0x80))
    e_blk = base + 8
    c.emu.w32(obj + 0x1c5d, e_blk if c.rng.random() < 0.8 else 0)
    render = c.emu.alloc(0xa00, 4)
    c.emu.wbytes(render, bytes(c.rng.getrandbits(8) for _ in range(0xa00)))
    c.emu.w32(render + 0x9b, obj)
    c.emu.w32(0x70039c, render)
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen(c):
    # the argument is inside the 0x100-byte block after e, so a - 0xc is always readable (the spec's own choice of range)
    base = c.emu.alloc(0x100, 4)
    c.emu.wbytes(base, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    a = c.rng.choice([base + 0x40, base + 0x10, base + 0x10 + 0xc, base + 0x80])
    c.emu.w32(a - 0xc, c.rng.choice([0, 1, 2, 7]))     # the value tested when the callback path is not taken
    return [a]


S(0x41f4a0, 'ZFF range check 0x41f4a0 (unknown) stdcall', 'stdcall', None, ret='al', gen=_gen, setup=_setup,
  note='gap band batch 790: range test, optional callback, vtable slot 0x20, bool result')
