"""specs_s240003.py - Sonnet-w4a: _alldiv / _allrem."""
from pilot import S
from recruits_util import clear_hooks


def _val(c, nonzero=False):
    r = c.rng
    k = r.random()
    if k < 0.2:
        v = r.getrandbits(8)
    elif k < 0.4:
        v = r.getrandbits(32)
    elif k < 0.55:
        v = r.getrandbits(32) << 32 | r.getrandbits(8)
    elif k < 0.6:
        v = r.choice([0x8000000000000000, 0x7fffffffffffffff, 0xffffffffffffffff, 1, 0x100000000, 0xffffffff])
    else:
        v = r.getrandbits(64)
    if r.random() < 0.4:
        v = (-v) & 0xffffffffffffffff
    if nonzero and v == 0:
        v = 1
    return v


def gen(c):
    clear_hooks(c)
    a = _val(c)
    b = _val(c, True)
    if c.rng.random() < 0.2:
        b = a if a else 3
    return [a & 0xffffffff, a >> 32, b & 0xffffffff, b >> 32]


S(0x634290, 'GUESS _alldiv', 'stdcall', None, ret='eax:edx', gen=gen, note='batch240003')
S(0x634380, 'GUESS _allrem', 'stdcall', None, ret='eax:edx', gen=gen, note='batch240003')
