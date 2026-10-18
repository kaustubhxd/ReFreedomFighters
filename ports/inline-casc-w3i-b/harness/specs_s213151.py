"""specs_s213151.py - batch 213151: zlib huft_build (Huffman decoding table), Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def g632360(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rb = lambda: r.getrandbits(32)
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)

    def w32u(addr, v):
        e.wbytes(addr, struct.pack('<I', v & 0xffffffff))
    # code lengths: a complete prefix code from random splits, then optional perturbation
    nsym = r.choice([1, 2, 3, 5, 8, 12, 19, 30, 40, 60, 100, 150, 257, 288, 300])
    leaves = [0]   # depths
    while len(leaves) < nsym:
        i = r.randrange(len(leaves))
        if leaves[i] >= 14:
            break
        d0 = leaves.pop(i)
        leaves += [d0 + 1, d0 + 1]
    lens = [max(1, x) if len(leaves) > 1 else 1 for x in leaves]
    if r.random() < 0.3:
        # skewed (chain) code: depths 1, 2, ..., d, d plus some extras at random depths
        d_ = r.randint(2, 14)
        lens = list(range(1, d_ + 1)) + [d_]
    mode = r.random()
    if mode < 0.12 and len(lens) > 2:
        lens.pop(r.randrange(len(lens)))                       # incomplete
    elif mode < 0.22:
        lens.append(r.randint(1, 6))                           # likely over-subscribed
    elif mode < 0.26:
        lens = [r.randint(0, 15) for _ in range(r.randint(1, 20))]   # random
    if r.random() < 0.3 and len(lens) > 2:
        for _ in range(r.choice([1, 1, 2])):
            lens.pop(r.randrange(len(lens)))      # incomplete code
    r.shuffle(lens)
    # interleave unused symbols
    full = []
    for L in lens:
        while r.random() < 0.25:
            full.append(0)
        full.append(L)
    if r.random() < 0.05:
        full = [0] * r.randint(1, 5)
    n = len(full)
    b = e.alloc(4 * n + 8, 4)
    e.wbytes(b, b''.join(struct.pack('<I', x) for x in full))
    s_ = r.choice([0, 1, 3, n // 2, n, n + 5, 257, 256, 255, 257, 256, n // 3])
    dd = e.alloc(4 * 400, 4)
    ee = e.alloc(4 * 400, 4)
    e.wbytes(dd, b''.join(struct.pack('<I', rb() & 0xffff) for _ in range(400)))
    e.wbytes(ee, b''.join(struct.pack('<I', r.getrandbits(5)) for _ in range(400)))
    t = e.alloc(8, 4)
    w32u(t, 0xdeadbee0)
    m = e.alloc(8, 4)
    w32u(m, r.choice([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 15]))
    hp = e.alloc(8 * 0x5a0 + 64, 4)
    hn = e.alloc(8, 4)
    w32u(hn, r.choice([0, 0, 0, 0, 7, 100, 0x59f, 0x580, 0x5a0 - 33]))
    v = e.alloc(4 * (n + 8), 4)
    c.huft_hp = hp
    return [b, n, s_, dd, ee, t, m, hp, hn, v]


def mask(c):
    hp = c.huft_hp
    # struct padding bytes (offset 2..3 of each 8-byte entry) are uninitialised stack in the original
    return [(hp + 8 * i + 2, 2) for i in range(0x5a0 + 8)]


S(0x632360, 'huft_build', 'cdecl', None, ret='eax', gen=g632360, stack_arg_bytes=40, heap_mask=mask)
