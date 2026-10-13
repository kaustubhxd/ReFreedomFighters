"""specs_s2498.py - decomp area 24, batch 2498 (residue 3, smallest first).
0x4ce7b0 (GUESS, bitset free-slot search): thiscall, plain ret, EAX = arr[i] & (m-1). Array words are generated so that the first pass
already exits ((arr[i] + m) & -m is nonzero for every word), which keeps the index inside the array; the index may still become -1
when it equals the slot, which is recorded through the stored index. The counter at +0x10 is incremented once."""
from pilot import S
from recruits_util import rnd, clear_hooks


def _find(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    m = r.choice([1, 2, 4, 8, 16])
    negm = (-m) & 0xffffffff
    arr = e.alloc(0x100, 4)
    for k in range(0x40):
        w = r.getrandbits(32)
        while (((w + m) & negm) & 0xffffffff) == 0:
            w = r.getrandbits(32)
        e.w32(arr + 4 * k, w)
    o = rnd(c, 0x40)
    e.w32(o + 4, arr)
    e.w32(o + 8, m)
    e.w32(o + 0xc, r.randint(0, 15))
    e.w32(o + 0x10, r.getrandbits(16))
    return [o]


S(0x4ce7b0, 'GUESS bitset free-slot search', 'thiscall', None, ret='eax', gen=_find, note='batch2498')
