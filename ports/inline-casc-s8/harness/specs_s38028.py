"""specs_s38028.py - cascade s8 batch 38028: 0x40e270. Plan struct: [1] = factor count (1..4, sometimes 0 or negative), factors from {2,3,4,5,7,8}; n is the product of the first k factors so every
division is exact (the loop divides n by the running product); three random heap buffers; the four pass functions (0x40eda0 / 0x40e5e0 / 0x40e430 / 0x40e8b0) are recording hooks (cdecl, every
argument compared), so the factor order, the buffer roles, the work-pointer offsets and the final copy-back are observable."""
import struct
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _g40e270(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    k = r.choice([1, 2, 2, 3, 3, 4, 0, 0xffffffff])
    kk = k if k < 0x80000000 else 0
    fs = [r.choice([2, 3, 4, 5, 7, 8, 4, 2, 3]) for _ in range(max(kk, 1))]
    n = 1
    for f in fs[:kk]:
        n *= f
    if kk == 0:
        n = r.choice([1, 5, 12])
    plan = e.alloc(8 + 4 * 6, 4)
    e.wbytes(plan, struct.pack('<I', r.getrandbits(32)) + struct.pack('<I', k) + b''.join(struct.pack('<I', f) for f in fs) + bytes(16))
    sz = 4 * (n + 8)
    b1, b2, wk = rnd(c, sz), rnd(c, sz), rnd(c, 4 * (3 * n + 8))
    hook_rec(c, 0x40eda0, 10, pop=0)
    hook_rec(c, 0x40e5e0, 6, pop=0)
    hook_rec(c, 0x40e430, 5, pop=0)
    hook_rec(c, 0x40e8b0, 7, pop=0)
    return [n, b1, b2, wk, plan]


S(0x40e270, 'GUESS mixed-radix pass driver (forward)', 'cdecl', None, ret=None, gen=_g40e270, note='batch38028')
