"""specs_s14.py - inline session batch 14 (Haiku, overnight): 0x613830, 0x5acfb0, 0x658f70."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


# 0x613830 thiscall: (this). A prefix of 0..6 nonzero entries, then zero entries; about 5% of the time every entry
# is nonzero, so the 0x800 limit is reached. The object is 0x22100 bytes (2047 entries of 0x44 bytes after the header at +0x80).
def _claim(c):
    r = c.rng
    o = c.emu.alloc(0x22100, 4)
    if r.random() < 0.05:
        body = bytes([1]) * 0x22100
    else:
        k = r.randint(0, 6)
        body = bytearray(0x22100)
        for i in range(k):
            body[0x80 + 0x44 * i:0x80 + 0x44 * i + 4] = bytes([r.randint(1, 255), 0, 0, 0])
        body = bytes(body)
    c.emu.wbytes(o, body)
    return [o]


S(0x613830, 'claimSlot (unknown) thiscall', 'thiscall', None, ret='eax', gen=_claim,
  note='batch14; 0x800 entries of 0x44 bytes, index 0 is never used')


# 0x5acfb0 thiscall: (this). The dword at +0x72 is random; flags for 31 bits.
S(0x5acfb0, 'countBits31 (unknown) thiscall', 'thiscall', None, ret='eax',
  gen=lambda c: [_rnd(c, 0x80)], note='batch14; counts bits 0..30 only')


# 0x658f70 thiscall: (this). Flag byte at +0x3c with bit 4 set about 80% of the time; count byte at +0x3f 0..255.
def _size(c):
    r = c.rng
    o = _rnd(c, 0x80)
    c.emu.w8(o + 0x3c, r.getrandbits(8) | (4 if r.random() < 0.8 else 0))
    c.emu.w8(o + 0x3f, r.choice([0, 1, 2, 7, 255, r.getrandbits(8)]))
    c.emu.w32(o + 0x48, r.getrandbits(16))
    return [o]


S(0x658f70, 'entrySize (unknown) thiscall', 'thiscall', None, ret='eax', gen=_size,
  note='batch14; count 0 returns 0 when bit 4 is set')
