"""specs_s210063.py - Sonnet-w3a: 0x4d8ef0. Container slots 0x4c (fill iterator) and 0x64 (next element, then 0); elements are {data pointer, length} with data equal to the key, differing at a random byte, or short."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def g4d8ef0(c):
    clear_hooks(c)
    e = c.emu
    ln = c.rng.choice([0, 1, 2, 3, 4, 5, 7, 8, 9, 13])
    key = rnd(c, 0x20)
    kb = e.rbytes(key, 0x20)
    elems = []
    for _ in range(c.rng.choice([0, 1, 2, 3, 4])):
        el = rnd(c, 0x10)
        data = rnd(c, 0x20)
        b = bytearray(kb)
        r = c.rng.random()
        if r < 0.4 and ln:
            b[c.rng.randrange(ln)] ^= c.rng.choice([1, 0x80, 0xff])
        e.wbytes(data, bytes(b))
        e.w32(el, data)
        e.w32(el + 4, ln if c.rng.random() < 0.8 else c.rng.choice([ln + 1, max(ln - 1, 0), _r(c)]))
        elems.append(el)
    seq = elems + [0]
    cont = obj(c, 0x40, {0x4c: pystub(c, 1, ret=_r(c), stackmark=(0,), this=True),
                         0x64: pystub(c, 1, ret=lambda emu, k: seq[min(k, len(seq) - 1)], stackmark=(0,), this=True)}, nslots=0x30)
    return [0 if c.rng.random() < 0.1 else cont, key, ln]


S(0x4d8ef0, 'find_element_by_bytes', 'stdcall', None, ret='eax', gen=g4d8ef0, note='batch210063')
