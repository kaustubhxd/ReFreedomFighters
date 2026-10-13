"""specs_s339.py - decomp area 64 (docs/20-unclaimed-64.md): 0x440d70 lazy child call; exe allocator 0x41e290 and ctor 0x4ccbe0."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _malloc(em, r):
    # api-ms-win-crt-heap!malloc (cdecl, one word): hands back a fresh heap block; the caller pops the word.
    n = em.arg32(0)
    p = em.alloc(max(n, 1), 16)
    em.ret(eax=p, argbytes=0)


def _lazy(c):
    e = c.emu
    e.stub_import('malloc', _malloc)
    # The constructor 0x4ccbe0 installs the vtable at 0x695734. Its slot 4 is an exe method that may fault on the fresh
    # block, so the slot is pointed at a stub (both sides) that returns a fixed value and pops its one word.
    e.w32(0x695738, ss.code(c, b'\xb8' + ss.P(0x1234) + b'\xc2\x04\x00'))

    self_ = _rnd(c, 0x80)
    if c.rng.random() < 0.4:
        e.w32(self_ + 0x44, 0)                       # null: the allocate path
    else:
        # A child object: slot 0x28 returns rv (zero or not) and pops its one word; slot 4 returns a value.
        rv = 0 if c.rng.random() < 0.4 else c.rng.getrandbits(32) | 1
        vt = e.logging_vtable('child440d', 0x12, argwords={0x28: 1, 0x4: 1},
                              impl={0x28: lambda em, a: (rv, None), 0x4: lambda em, a: (0x777, None)})
        obj = _rnd(c, 0x40)
        e.w32(obj, vt)
        e.w32(self_ + 0x44, obj)
    return [self_, c.rng.getrandbits(32)]


S(0x440d70, 'lazyCall (GUESS)', 'thiscall', None, ret='eax', gen=_lazy,
  note='batch339; one stack word; ret 4; exe allocator 0x41e290 (cdecl) and ctor 0x4ccbe0; vtable 0x695734 slot 4 stubbed')
