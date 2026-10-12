"""specs_s915.py - unclaimed-01 claim 14 (docs/20-unclaimed-01.md): 0x4a1c80 (GUESS name CAction::SetStrings; the GC name map
says CAction::InRange, which the body does not match). The global allocator at 0x70039c is a logging fake: slot +0xf8
returns the next of two per-case buffers (each call takes the next), slot +0xfc returns 0. The two string arguments are
random null-terminated strings (null about 20% of the time). The old pointers at +0x7a and +0x76 are random dwords, so the
frees log them."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _cstr(c):
    if c.rng.random() < 0.2:
        return 0
    n = c.rng.randint(0, 15)
    a = c.emu.alloc(n + 8, 4)
    c.emu.wbytes(a, bytes(c.rng.randint(1, 255) for _ in range(n)) + b'\x00')
    return a


def _setstrings(c):
    bufs = [c.emu.alloc(0x40, 4), c.emu.alloc(0x40, 4)]
    for b in bufs:
        c.emu.wbytes(b, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
    pending = list(bufs)

    def nextbuf(e, args):
        return pending.pop(0) if pending else 0

    alloc = c.emu.logging_vtable('ZSysAlloc', 0x40, impl={0xf8: (lambda e, a: (nextbuf(e, a), None)),
                                                          0xfc: (lambda e, a: (0, None))},
                                 argwords={0xf8: 1, 0xfc: 1})
    g = _rnd(c, 0x100)
    c.emu.w32(g, alloc)
    c.emu.w32(0x70039c, g)
    o = _rnd(c, 0x100)
    c.emu.w32(o + 0x7a, c.rng.choice([0, c.rng.getrandbits(32)]))
    c.emu.w32(o + 0x76, c.rng.choice([0, c.rng.getrandbits(32)]))
    return [o, _cstr(c), _cstr(c)]


S(0x4a1c80, 'CAction::SetStrings (GUESS; map says InRange) thiscall', 'thiscall', None, ret=None, gen=_setstrings,
  note='unclaimed-01 claim 14; GUESS name; allocator slots +0xf8 and +0xfc; two string copies')
