"""specs_s352.py - decomp area 64 (docs/20-unclaimed-64.md): dedicated pass on 0x43ec00. Helpers 0x441730, 0x440530 (lock-like, no
words) and 0x441890 (one float word) are stubbed on both sides (GUESS); the child, child2 and self vtable slots are logging stubs."""
import os, sys, struct
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


def _fl(c):
    return c.rng.uniform(-8.0, 8.0)


def _call(c):
    e = c.emu
    # Helpers 0x441730 and 0x440530: counters (so a missing call shows); 0x441890: records ecx and its float word.
    cnt = e.alloc(8, 4)
    e.wbytes(cnt, bytes(8))
    ss.patch(c, 0x441730, ss.code(c, b'\xff\x05' + ss.P(cnt) + b'\xc3'))
    ss.patch(c, 0x440530, ss.code(c, b'\xff\x05' + ss.P(cnt + 4) + b'\xc3'))
    cell = e.alloc(8, 4)
    e.wbytes(cell, bytes(8))
    ss.patch(c, 0x441890, ss.code(c, b'\x89\x0d' + ss.P(cell) + b'\x8b\x54\x24\x04' + b'\x89\x15' + ss.P(cell + 4) + b'\xc2\x04\x00'))

    # The record R (from child2's slot 0x60): a word at +0x7c for child's slot 0x54, and a float at +0x88 (unused by the stub).
    R = _rnd(c, 0x90)
    e.w32(R + 0x7c, c.rng.getrandbits(32))
    # X (from child's slot 0x54): a dword that is 2 sometimes, a signed byte at +0x17 (zero or not), and a float at +0xc.
    X = _rnd(c, 0x40)
    e.w32(X, 2 if c.rng.random() < 0.6 else c.rng.getrandbits(32))
    e.wbytes(X + 0x17, bytes([c.rng.choice([0, 1, 0x7f, 0xff, c.rng.getrandbits(8)])]))
    e.wf32(X + 0xc, _fl(c))

    # Vector B (the stack pointer): three floats.
    B = _rnd(c, 0x20)
    for i in range(3):
        e.wf32(B + 4 * i, _fl(c))

    # Child2 (sys[+0x9b]): slot 0x60 takes one word and returns R (or 0).
    r60 = R if c.rng.random() < 0.9 else 0
    c2_vt = e.logging_vtable('child2_43ec', 0x80, argwords={0x60: 1}, impl={0x60: lambda em, a: (r60, None)})
    c2 = _rnd(c, 0x40)
    e.w32(c2, c2_vt)

    # Child (sys[+0x1a9f]): slot 0x11c takes four words and returns r (sometimes 0); slot 0x54 returns X (or 0); slot 0xd8 pops six.
    r11c = c.rng.getrandbits(32) | 1 if c.rng.random() < 0.85 else 0
    r54 = X if c.rng.random() < 0.9 else 0
    c_vt = e.logging_vtable('child_43ec', 0x400, argwords={0x11c: 4, 0x54: 1, 0xd8: 6},
                            impl={0x11c: lambda em, a: (r11c, None), 0x54: lambda em, a: (r54, None)})
    child = _rnd(c, 0x40)
    e.w32(child, c_vt)

    sys_ = _rnd(c, 0x1b00)
    e.w32(sys_ + 0x9b, c2)
    e.w32(sys_ + 0x1a9f, child)
    e.w32(0x70039c, sys_)

    # self: its slot 0x84 takes one word (the local vector's address) and pops it.
    self_vt = e.logging_vtable('self_43ec', 0x240, argwords={0x84: 1})
    self_ = _rnd(c, 0x40)
    e.w32(self_, self_vt)

    C = c.rng.getrandbits(32) if c.rng.random() < 0.85 else 0
    D = c.rng.choice([0xc, 0, 1, 5, c.rng.getrandbits(32)])
    return [self_, c.rng.getrandbits(32), B, C, D, c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x43ec00, 'callChild (GUESS)', 'thiscall', None, ret='eax', gen=_call,
  note='batch352; six stack words A, B, C, D, E, F; ret 0x18; helpers 0x441730, 0x440530, 0x441890 stubbed (GUESS)')
