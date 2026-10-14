"""specs_s38015.py - cascade s8 batch 38015: 0x40ceb0. Plan struct: [1] = factor count (1..4, sometimes 0 or negative), factors from {2,3,4,5,7,8}; n is the product (so every
division is exact and never by zero); the three buffers are random heap blocks of n dwords (plus slack); 0x40d690 / 0x40d060 / 0x40d220 are recording hooks (cdecl, all
args compared), so the factor order, the ping-pong buffer roles, the pointer offsets and the final copy-back are all observable."""
import struct
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _g40ceb0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    k = r.choice([1, 2, 2, 3, 3, 4, 0, 0xffffffff])
    kk = k if k < 0x80000000 else 0
    fs = [r.choice([2, 3, 4, 5, 7, 8, 4, 2]) for _ in range(max(kk, 1))]
    n = 1
    for f in fs[:kk]:
        n *= f
    if kk == 0:
        n = r.choice([1, 5, 12])
    plan = e.alloc(8 + 4 * 6, 4)
    e.wbytes(plan, struct.pack('<I', r.getrandbits(32)) + struct.pack('<I', k) + b''.join(struct.pack('<I', f) for f in fs) + bytes(16))
    sz = 4 * (n + 8)
    b1, b2, wk = rnd(c, sz), rnd(c, sz), rnd(c, 4 * (3 * n + 8))
    hook_rec(c, 0x40d690, 10, pop=0)
    hook_rec(c, 0x40d060, 5, pop=0)
    hook_rec(c, 0x40d220, 7, pop=0)
    return [n, b1, b2, wk, plan]


S(0x40ceb0, 'GUESS mixed-radix pass driver', 'cdecl', None, ret=None, gen=_g40ceb0, note='batch38015')
