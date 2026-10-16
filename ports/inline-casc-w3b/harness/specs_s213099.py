"""specs_s213099.py - batch 213099: zlib gen_bitlen, Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd


def safe(heap, heap_max, freq, dl, max_code, max_length):
    """Python model of gen_bitlen's control flow: True when no bl_count wrap / downward scan / heap underflow can occur."""
    tree = list(dl)
    bl = [0] * 16
    overflow = 0
    tree[heap[heap_max]] = 0
    for h in range(heap_max + 1, 573):
        n = heap[h]
        bits = tree[tree[n]] + 1
        if bits > max_length:
            bits = max_length
            overflow += 1
        tree[n] = bits
        if n > max_code:
            continue
        bl[bits] += 1
    if overflow == 0:
        return True
    while True:
        bits = max_length - 1
        while bits >= 1 and bl[bits] == 0:
            bits -= 1
        if bits < 1 or bl[max_length] == 0:
            return False
        bl[bits] -= 1
        bl[bits + 1] += 2
        bl[max_length] -= 1
        overflow -= 2
        if overflow <= 0:
            break
    h = 573
    for bits in range(max_length, 0, -1):
        n = bl[bits]
        while n != 0:
            h -= 1
            if h <= heap_max:
                return False
            m = heap[h]
            if m > max_code:
                continue
            n -= 1
    return True


def g6309a0(c):
    for _ in range(200):
        a = _gen(c)
        if a is not None:
            return a
    raise RuntimeError('no safe case')


def _gen(c):
    r = c.rng
    e = c.emu
    N = r.choice([40, 100, 286, 300])
    max_length = r.choice([15, 15, 7, 12, 3, 1, 2, r.randrange(1, 16)])
    s = rnd(c, 0x16c0)
    mode = r.random()
    heap_max = 572 if mode < 0.3 else r.randrange(max(0, 573 - N), 573)
    max_code = r.choice([N - 1, N, N // 2, r.randrange(0, N + 1), 0])
    heap = [r.randrange(N) for _ in range(573)]
    # tree: Freq ush, Dad/Len ush (Dad indexes within the tree)
    freqs = [r.choice([0, 1, 2, 3, r.randrange(0, 0x10000), r.randrange(0, 50)]) for _ in range(N)]
    dls = [r.randrange(0, min(N, max_length + 4)) if r.random() < 0.8 else r.randrange(0, min(N, 3)) for _ in range(N)]
    if not safe(heap, heap_max, freqs, dls, max_code, max_length):
        return None
    e.w32(s + 0x144c, heap_max)
    for h in range(573):
        e.w32(s + 0xb54 + 4 * h, heap[h])
    tree = e.alloc(4 * N, 4)
    for i in range(N):
        e.wbytes(tree + 4 * i, struct.pack('<HH', freqs[i], dls[i]))
    stree = 0
    if r.random() < 0.7:
        stree = e.alloc(4 * N, 4)
        for i in range(N):
            e.wbytes(stree + 4 * i, struct.pack('<HH', r.randrange(0x10000), r.randrange(0, 20)))
    extra = e.alloc(4 * N, 4)
    for i in range(N):
        e.w32(extra + 4 * i, r.choice([0, 1, 2, 3, 5, 13, r.randrange(0, 1 << 20)]))
    base = r.choice([0, 1, N // 2, N - 1, N, r.randrange(0, N + 1), 257 if N > 257 else 3])
    sd = e.alloc(20, 4)
    for i, v in enumerate([stree, extra, base, r.randrange(0, 300), max_length]):
        e.w32(sd + 4 * i, v)
    desc = e.alloc(12, 4)
    for i, v in enumerate([tree, max_code, sd]):
        e.w32(desc + 4 * i, v)
    return [s, desc]


S(0x6309a0, 'gen_bitlen', 'cdecl', None, ret=None, gen=g6309a0)
