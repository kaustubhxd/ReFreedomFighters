"""specs_s191.py - unclaimed area 19 (docs/20-unclaimed-19.md): slot read, last-entry read, UTF-8 encoder."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _slot(c):
    return [_rnd(c, 0x200), c.rng.randrange(-4, 12) & 0xffffffff]


def _last(c):
    n = c.rng.randrange(1, 7)
    self_ = _rnd(c, 0x40)
    c.emu.w32(self_ + 0x18, n)
    arr = _rnd(c, 0x40)
    if c.rng.random() < 0.3:
        c.emu.w32(arr + n * 4 - 4, 0)
    return [self_, arr]


_CP_EDGES = [0, 0x7e, 0x7f, 0x80, 0x7ff, 0x800, 0xffff, 0x10000, 0x1fffff, 0x200000, 0xffffffff]


def _utf8(c):
    out = _rnd(c, 0x10)
    if c.rng.random() < 0.5:
        cp = c.rng.choice(_CP_EDGES)
    else:
        cp = c.rng.getrandbits(32) if c.rng.random() < 0.2 else c.rng.randrange(0, 0x200000)
    return [out, cp]


S(0x5a4720, 'slotRead (GUESS)', 'thiscall', None, ret='eax', gen=_slot, note='batch191; stack argument, ret 4')
S(0x4ce4e0, 'lastEntry (GUESS)', 'thiscall', None, ret='eax', gen=_last, note='batch191; stack argument, ret 4')
S(0x4cc6e0, 'utf8Put (GUESS)', 'fastcall', None, ret='eax', gen=_utf8, note='batch191; out in ECX, codepoint in EDX')
