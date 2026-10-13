"""specs_s13.py - inline session batch 13 (Haiku, overnight): 0x613a70, 0x613b30, 0x648630, 0x6069f0."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _adv(size, hi):
    def gen(c):
        o = _rnd(c, size)
        c.emu.w16(o + 2, 0xffff if c.rng.random() < 0.2 else c.rng.randint(0, hi))
        return [o]
    return gen


S(0x613a70, 'advanceSlot8c (unknown) thiscall', 'thiscall', None, ret='eax', gen=_adv(0x400, 4),
  note='batch13; 0x8c-byte nodes, marker 0xffff1203')
S(0x613b30, 'advanceSlot28 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_adv(0x200, 5),
  note='batch13; 28-byte nodes, marker 0xffff1206')
S(0x648630, 'advanceSlot120 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_adv(0x400, 3),
  note='batch13; 120-byte nodes, vtable 0x6bdab4, marker 0xffff1201')


# 0x6069f0 fastcall: (dst, end, src). end is usually dst + 4k; sometimes below dst, which gives a count of 0.
def _fill(c):
    r = c.rng
    dst = _rnd(c, 64)
    k = r.randint(0, 12)
    end = dst - 8 if r.random() < 0.15 else dst + 4 * k + (2 if r.random() < 0.1 else 0)
    src = _rnd(c, 4)
    return [dst, end & 0xffffffff, src]


S(0x6069f0, 'fillDwords (unknown) fastcall', 'fastcall', None, ret=None, gen=_fill,
  note='batch13; fills dwords from a fixed source dword; count rounds up')
