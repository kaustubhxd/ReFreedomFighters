"""specs_s42.py - inline session batch 42 (Haiku, night): walk-tree clean leaves 0x439570 (table lookup over the global at
0x6e48c0), 0x5a7500 (two floats to +0x358/+0x35c), 0x5acac0 (byte to +8), 0x589c20 (GetGameOSD, dword at this+0x2c2d+4c)."""
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _lookup(c):
    r = c.rng
    n = r.randint(1, 3)
    size = r.randint(1, 8)
    c.emu.w32(0x6e48c4, size)
    for k in range(n):
        arr = _rnd(c, 0x200)
        c.emu.w32(0x6e48c0 + 16 * k, arr)
        c.emu.w32(0x6e48c0 + 16 * k + 4, size)
    c.emu.w32(0x6e48c0 + 16 * n, 0)
    if n < 3:
        c.emu.w32(0x6e48c0 + 16 * (n + 1), 0)
    arg = r.randint(0, n * size + 2) if r.random() < 0.9 else r.getrandbits(32)
    return [arg]


def _two(c):
    obj = _rnd(c, 0x400)
    return [obj, F(c.fv()), F(c.fv())]


def _byte(c):
    return [_rnd(c, 0x400), c.rng.getrandbits(32)]


def _osd(c):
    obj = _rnd(c, 0x3000)
    return [obj, c.rng.getrandbits(32)]


S(0x439570, 'LookupTable0x6e48c0', 'stdcall', None, ret='eax', gen=_lookup,
  note='batch42; table of 16-byte entries at 0x6e48c0; segment size from entry 0 +4; returns ptr[3*rem] or 0')
S(0x5a7500, 'SetTwoFloats358', 'thiscall', None, ret=None, gen=_two,
  note='batch42; two floats to this+0x358 and +0x35c')
S(0x5acac0, 'SetByte8', 'thiscall', None, ret=None, gen=_byte,
  note='batch42; low byte of the stack arg to this+8')
S(0x589c20, 'ZFFGameData::GetGameOSD', 'thiscall', None, ret='eax', gen=_osd,
  note='batch42; dword at this+0x2c2d+4*sign-extended arg')
