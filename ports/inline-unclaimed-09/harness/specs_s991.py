"""specs_s991.py - area 56 claim A57 (0x4e5330, ZAnimFilePack::GetAnimFileName): a pointer selector with no calls.

this is a 0x40-byte object of random bytes whose +4 is a pointer P to a 0x40-byte object of random bytes. The flags dword at P+4 has its
top two bits drawn from all four values (so every branch runs), and P+8 is random. ret='eax' (a pointer)."""
from pilot import S


def _rnd(c, n):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    rng = c.rng
    p = _rnd(c, 0x40)
    flags = (rng.getrandbits(30)) | (rng.randrange(4) << 30)
    c.emu.w32(p + 4, flags)
    this = _rnd(c, 0x40)
    c.emu.w32(this + 4, p)
    return [this]


S(0x4e5330, 'ZAnimFilePack::GetAnimFileName (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-56 A57; pointer selector, no calls')
