"""specs_s66074.py - cascade s4 batch 66074: 0x5edcb0 (rotate a dword range around a middle point)."""
from pilot import S
from recruits_util import clear_hooks


def _g5edcb0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 2, 3, 5, 8, 11])
    arr = e.alloc(4 * 16, 8)
    for i in range(16):
        e.w32(arr + 4 * i, 0x100 + i)
    a = r.randint(0, min(2, n))
    b = r.randint(a, n)
    m = r.randint(a, b)
    first, mid, last = arr + 4 * a, arr + 4 * m, arr + 4 * b
    return [first, mid, last, r.getrandbits(32), r.getrandbits(32)]


S(0x5edcb0, 'GUESS rotate a dword range around a middle point', 'fastcall', None, ret='eax', gen=_g5edcb0, note='batch66074')
