"""specs_s66032.py - cascade s4 batch 66032: 0x5ee110 (append or reuse an entry of a pointer list and refresh its layout)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec


def _g5ee110(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([1, 2, 3, 4])
    k = r.choice([0, 0, 1, n - 1, n, n, 2]) % (n + 1)
    arr = e.alloc(4 * n + 4, 8)
    objs = []
    for i in range(n):
        o = e.alloc(0x10, 8)
        x = e.alloc(0x20, 8)
        e.w32(o, x)
        e.w32(o + 4, r.getrandbits(32))
        e.w32(arr + 4 * i, o)
        objs.append(x)
    vals = [r.choice([0, 3, 40, 200, 0xfffffff0]) for _ in range(8)]
    hook_rec(c, 0x5ee920, 0, this=True)
    hook_rec(c, 0x5aca30, 2, this=True)
    hook_rec(c, 0x5ac5d0, 1, this=True)
    hook_rec(c, 0x5ab9d0, 0, this=True, ret=lambda em, kk: vals[min(kk, 7)])
    t = e.alloc(0x90, 8)
    e.wbytes(t, bytes(r.getrandbits(8) for _ in range(0x90)))
    e.w32(t + 5, arr)
    e.w32(t + 9, arr + 4 * n)
    e.w32(t + 0x11, r.choice([0, 1, 1, 2]))
    e.w32(t + 0x19, k)
    e.wbytes(t + 0x6a, bytes([r.choice([0, 1, 1])]))
    e.w32(t + 0x45, r.choice([0, 13, 50, 210]))
    b = r.choice([0, 1, 1, 7])
    return [t, r.getrandbits(32), b, r.getrandbits(32)]


S(0x5ee110, 'GUESS append or reuse a list entry and refresh the layout', 'thiscall', None, ret=None, gen=_g5ee110, note='batch66032')
