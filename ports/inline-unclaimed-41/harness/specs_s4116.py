"""specs_s4116.py - unclaimed-41 batch 16 (slice 13): 0x5ec390 (thiscall, five stack arguments A, X, C, B, I; ret 0x14).

this: +0x62 = arr (4 entry pointers), +0x3a = Q with Q+4 = P (a list of 40-byte records, room for 4), +0x52 and +0x56 random
dwords (zero about one time in six: the divisions then give inf or NaN, as the exe does). Entries E: 0x40 random bytes; E+4 and
E+6 random words (zero about one time in six); E+0x28 and E+0x2a equal to (C, B) in about a third of cases (the early exit).
The arguments: A, X, B, C random 32-bit; I in 0..3. No calls, so no stubs. Faulting cases must be 0 (JSON)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _word(c):
    return c.rng.getrandbits(16) if c.rng.random() > 1 / 6 else 0


def _ec(c):
    self_ = _rnd(c, 0x100)
    c.emu.w32(self_ + 0x52, c.rng.getrandbits(32) if c.rng.random() > 1 / 6 else 0)
    c.emu.w32(self_ + 0x56, c.rng.getrandbits(32) if c.rng.random() > 1 / 6 else 0)
    q = _rnd(c, 0x20)
    p = _rnd(c, 40 * 4 + 0x40)
    c.emu.w32(q + 4, p)
    c.emu.w32(self_ + 0x3a, q)
    arr = c.emu.alloc(4 * 4, 4)
    args = [c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(16), c.rng.getrandbits(16)]
    A, X, C, B = args
    for i in range(4):
        e = _rnd(c, 0x40)
        c.emu.w32(e + 4, 0)
        c.emu.wbytes(e + 4, _word(c).to_bytes(2, 'little'))
        c.emu.wbytes(e + 6, _word(c).to_bytes(2, 'little'))
        if c.rng.random() < 1 / 3:
            c.emu.wbytes(e + 0x28, C.to_bytes(2, 'little'))
            c.emu.wbytes(e + 0x2a, B.to_bytes(2, 'little'))
        c.emu.w32(arr + 4 * i, e)
    c.emu.w32(self_ + 0x62, arr)
    I = c.rng.randint(0, 3)
    return [self_, A, X, C, B, I]


S(0x5ec390, 'fn5ec390 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_ec,
  note='unclaimed-41 batch 16; pure double/float math on table entries')
