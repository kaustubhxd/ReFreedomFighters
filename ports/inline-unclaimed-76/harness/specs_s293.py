"""specs_s293.py - unclaimed area 76 (docs/20-unclaimed-76.md), residue 15: 0x5edc80 (fastcall swap inward, one stack arg) and
0x5edcb0 (fastcall rotate, three stack args). Pure memory: pointers into one heap buffer of dwords, chosen so the equal-pointer
cases happen often."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _buf(c):
    return _rnd(c, 4 * 40)


def _pick(c, buf):
    i = c.rng.randrange(0, 10)
    return buf + 4 * i


def _c80(c):
    # the walk meets only when a <= b (both 4-aligned in one buffer): a == b is the early return
    buf = _buf(c)
    i = c.rng.randrange(0, 10)
    j = c.rng.randrange(i, 10) if c.rng.random() < 0.8 else i
    return [buf + 4 * i, buf + 4 * j, c.rng.getrandbits(32)]


def _c_b0(c):
    # the rotate needs x < end < s1 (its passes meet only then); x == end and s1 == end are the early returns
    buf = _buf(c)
    r = c.rng.random()
    i, j, k = sorted(c.rng.sample(range(10), 3))
    if r < 0.1:
        x, end, s1 = i, i, k
    elif r < 0.2:
        x, end, s1 = i, j, j
    else:
        x, end, s1 = i, j, k
    return [buf + 4 * x, buf + 4 * end, buf + 4 * s1, c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x5edc80, 'swapInward (GUESS)', 'fastcall', None, ret=None, gen=_c80, note='batch293; ret 4')
S(0x5edcb0, 'rotate (GUESS)', 'fastcall', None, ret='eax', gen=_c_b0, note='batch293; ret 0xc')
