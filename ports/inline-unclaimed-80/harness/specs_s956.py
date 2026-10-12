"""specs_s956.py - unclaimed-80 gap band (docs/20-unclaimed-80.md): 0x4288c0 and 0x428830 (see src/batch956.cpp). self+0xd is an object
(null 20%) whose first dword is a logging vtable with slot +0x1c (one stack argument, callee-cleaned). The slot returns the next
value of a per-case HRESULT list kept in the object's memory (a call counter at +0x60, values from +0x70), so both runs see the same
sequence: 0..3 retry codes (0x8007001e or 0x8007000c) then one other value. Null and non-null paths both run."""
import struct
from pilot import S

RETRY = (0x8007001e, 0x8007000c)


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _rd(e, a):
    return int.from_bytes(bytes(e.rbytes(a, 4)), 'little')


def _seq_slot(c):
    def impl(e, args):
        o = args[0]
        k = _rd(e, o + 0x60)
        e.w32(o + 0x60, (k + 1) & 0xffffffff)
        return (_rd(e, o + 0x70 + 4 * k) if k < 4 else 0, None)
    return impl


def _gen(c):
    self_o = _rnd(c, 0x200)
    if c.rng.random() < 0.2:
        c.emu.w32(self_o + 0xd, 0)
        return [self_o]
    o = _rnd(c, 0x100)
    seq = [RETRY[c.rng.randint(0, 1)] for _ in range(c.rng.randint(0, 3))]
    while True:
        last = c.rng.getrandbits(32)
        if last not in RETRY:
            break
    seq.append(last)
    c.emu.w32(o + 0x60, 0)
    for i, v in enumerate(seq):
        c.emu.w32(o + 0x70 + 4 * i, v)
    vt = c.emu.logging_vtable('ZRetryObj', 0x8, impl={0x1c: _seq_slot(c)}, argwords={0x1c: 1})
    c.emu.w32(o, vt)
    c.emu.w32(self_o + 0xd, o)
    return [self_o]


S(0x4288c0, 'HRESULT retry loop (unknown) thiscall', 'thiscall', None, ret='al', gen=_gen,
  note='unclaimed-80 gap band; slot +0x1c with one stack argument; flag byte at +0x45')
S(0x428830, 'HRESULT retry loop (unknown) thiscall', 'thiscall', None, ret='al', gen=_gen,
  note='unclaimed-80 gap band; slot +0x1c with one stack argument; flag byte at +0x1b1')
