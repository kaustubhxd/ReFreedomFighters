"""specs_s960.py - unclaimed-80 gap band (docs/20-unclaimed-80.md): 0x428870 (see src/batch960.cpp). self+0xd is an object (null 20%) whose
first dword is a logging vtable with slot +0x1c (one stack argument, callee-cleaned). The slot returns a per-case HRESULT sequence kept in
the object's memory (a call counter at +0x60, values from +0x70): 0 to 3 retry codes, then one other value. The retry count n is random
(0 to 4 about 80% of the time, else any 32-bit value)."""
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
    n = c.rng.randint(0, 4) if c.rng.random() < 0.8 else c.rng.getrandbits(32)
    if c.rng.random() < 0.2:
        c.emu.w32(self_o + 0xd, 0)
        return [self_o, n]
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
    vt = c.emu.logging_vtable('ZRetryObj2', 0x8, impl={0x1c: _seq_slot(c)}, argwords={0x1c: 1})
    c.emu.w32(o, vt)
    c.emu.w32(self_o + 0xd, o)
    return [self_o, n]


S(0x428870, 'HRESULT retry loop with a count (unknown) thiscall', 'thiscall', None, ret='al', gen=_gen,
  note='unclaimed-80 gap band; one stack argument (count); slot +0x1c with one stack argument; flag byte at +0x45')
