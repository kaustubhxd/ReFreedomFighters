"""specs_s28.py - inline session batch 28 (Haiku, overnight): 0x4cc180, 0x4d4270, 0x4ccad0."""
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _text(c):
    r = c.rng
    n = r.randint(0, 7)
    return bytes(r.choice(b'ab') for _ in range(n)) + b'\0'


# 0x4cc180 thiscall, one string arg. The holder at ECX points to the first string. Half the time the second string equals
# the first, otherwise it is a changed copy.
def _streq(c):
    r = c.rng
    s1 = _text(c)
    if r.random() < 0.5:
        s2 = s1
    else:
        t = bytearray(s1)
        if len(t) > 1 and r.random() < 0.5:
            t[r.randint(0, len(t) - 2)] ^= 1
        else:
            t = bytearray(s1[:-1]) + bytearray(b'ab\0')
        s2 = bytes(t)
    a1 = c.emu.alloc(16, 4)
    c.emu.wbytes(a1, s1 + bytes(16 - len(s1)))
    a2 = c.emu.alloc(16, 4)
    c.emu.wbytes(a2, s2 + bytes(16 - len(s2)))
    holder = c.emu.alloc(8, 4)
    c.emu.w32(holder, a1)
    return [holder, a2]


S(0x4cc180, 'strIs (unknown) thiscall', 'thiscall', None, ret='al', gen=_streq,
  note='batch28; two-byte-at-a-time equality of NUL-terminated strings; returns 1 when equal')


# 0x4d4270 thiscall, no args, returns AL. The flag at +4 chooses the branch. Floats at +7 and +0xb; the value is usually in
# the range where the 1.0 and 0 comparisons go both ways.
def _acc(c):
    r = c.rng
    obj = _rnd(c, 0x20)
    c.emu.wbytes(obj + 4, bytes([r.choice([0, 1])]))
    c.emu.wf32(obj + 7, c.fv())
    c.emu.wf32(obj + 0xb, c.fv())
    return [obj]


S(0x4d4270, 'accumulate (unknown) thiscall', 'thiscall', None, ret='al', gen=_acc,
  note='batch28; flag at +4 picks the add-and-clamp branch or the subtract branch; NaN fails the compare')


# 0x4ccad0 thiscall, two stack dwords a (signed) and b. A small signed a and a 0..20 b keep the product small.
def _grid(c):
    r = c.rng
    obj = _rnd(c, 0x40)
    return [obj, r.randint(-3, 10) & 0xffffffff, r.randint(0, 20)]


S(0x4ccad0, 'initGrid (unknown) thiscall', 'thiscall', None, ret='eax', gen=_grid,
  note='batch28; count clamped to at least 1; stride b+4; vtable word 0x6959f8')
