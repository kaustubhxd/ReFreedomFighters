"""specs_s53000.py - u6 (Sonnet) batch 53000: 0x4de1d0 matrix to quaternion (register ABI), and 0x40e430 radf2-style float pass (cdecl, 5 args). Buffers hold random floats (some NaN/inf); nan_heap=True."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, clear_hooks, pystub


def _f(b):
    return struct.unpack('<f', struct.pack('<I', b))[0]


def _fb(v):
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _fill(c, a, nwords):
    r = c.rng
    for i in range(nwords):
        x = r.random()
        bits = r.choice([_fb(c.fv(-4, 4))] * 12 + [0x7fc00000, 0x7f800000, 0xff800000, 0, 0x80000000])
        c.emu.wbytes(a + 4 * i, bits.to_bytes(4, 'little'))


def g40e430(c):
    clear_hooks(c)
    r = c.rng
    ido = r.choice([0, 1, 2, 2, 3, 3, 4, 5, 5, 6, 7, 8, 9])
    l1 = r.choice([0, 1, 1, 2, 3, 4, 5])
    if ido == 0:
        l1 = 0
    words = 2 * max(ido, 1) * max(l1, 1) + 8
    cc = rnd(c, 4 * words)
    ch = rnd(c, 4 * words)
    wa = rnd(c, 4 * (ido + 4))
    _fill(c, cc, words)
    _fill(c, wa, ido + 4)
    return [ido, l1, cc, ch, wa]


S(0x40e430, 'GUESS radf2 real FFT radix-2 pass', 'cdecl', None, ret=None, gen=g40e430, nan_heap=True, note='batch53000')


def g4de1d0(c):
    clear_hooks(c)
    r = c.rng
    m = rnd(c, 0x24)
    q = rnd(c, 0x10)
    mode = r.random()
    for i in range(9):
        if mode < 0.15:
            bits = r.choice([_fb(c.fv(-2, 2)), 0x7fc00000, 0x7f800000, 0xff800000, 0, 0x80000000])
        elif mode < 0.4:
            bits = _fb(c.fv(-1, 1) if i not in (0, 4, 8) else c.fv(0.2, 1))   # trace likely positive
        else:
            bits = _fb(c.fv(-1, 1))
        c.emu.wbytes(m + 4 * i, bits.to_bytes(4, 'little'))
    return [q, m]


S(0x4de1d0, 'GUESS rotation matrix to quaternion', 'fastcall', None, ret=None, gen=g4de1d0, nan_heap=True, note='batch53000')


def g5c0160(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 2, 3, 4, 5, 6, 8])
    m = max(n, 1)
    perm = list(range(m))
    r.shuffle(perm)
    keys = sorted(c.fv(-3, 3) for _ in range(m))
    tie = r.random() < 0.3
    if tie:
        keys = sorted(round(k * 8) / 8 if abs(k) < 100 else 0.0 for k in keys)
    if r.random() < 0.1:
        keys = [_f(r.choice([0x7fc00000, 0x7f800000, 0xff800000, 0])) if r.random() < 0.3 else k for k in keys]
    order = e.alloc(4 * m + 8, 4)
    for i in range(m):
        e.w32(order + 4 * i, perm[i])
    # one object shape per entry: [+0x54] -> struct whose +4 is a shift count, vslot 0x20 -> struct with [+8] -> flags word at +0x3c
    ents = e.alloc(0x17 * m + 16, 4)
    e.wbytes(ents, bytes(r.getrandbits(8) for _ in range(0x17 * m + 16)))
    P = rnd(c, 12)
    py = c.fv(-2, 2)
    objs = []
    for i in range(r.choice([1, 2, m])):
        q = e.alloc(0x50, 4)
        e.wbytes(q, bytes(r.getrandbits(8) for _ in range(0x50)))
        o2 = e.alloc(0x20, 4)
        e.wbytes(o2, bytes(r.getrandbits(8) for _ in range(0x20)))
        e.w32(o2 + 8, q)
        if r.random() < 0.5:
            e.w32(q + 0x3c, e.r32(q + 0x3c) & ~(1 << 10))
        t = e.alloc(0x10, 4)
        e.wbytes(t, bytes(r.getrandbits(8) for _ in range(0x10)))
        e.w32(t + 4, r.choice([0, 1, 2, 3, 5, 31, 32, 33, r.getrandbits(32)]))
        ob = obj(c, 0x80, {0x20: pystub(c, 0, ret=o2, this=True)})
        e.w32(ob + 0x54, t)
        objs.append(ob)
    for j in range(m):
        ent = ents + 0x17 * j
        e.w32(ent, r.choice(objs))
    # entry order[i] has the i-th smallest key
    for i in range(m):
        ent = ents + 0x17 * perm[i]
        e.wbytes(ent + 4, struct.pack('<f', keys[i]))
        e.wbytes(ent + 8, struct.pack('<f', py + r.choice([0, 0.1, -0.3, 0.7, c.fv(-1, 1)])))
    me = rnd(c, 0x80)
    e.w32(me + 0x4c, order)
    e.w32(me + 0x50, ents)
    e.w32(me + 0x54, n)
    e.wbytes(me + 0x60, struct.pack('<f', c.fv(0, 1)))
    r0, flag = c.fv(0, 2), r.choice([0, 1, 0x100, 0x1ff])
    px = c.fv(-3, 3)
    if tie:
        r0, flag, px = r.choice([0.25, 0.5, 1.0]), 1, r.choice(keys) + r.choice([0.25, 0.5, 1.0, -0.25])
        if r.random() < 0.7:
            px = r.choice(keys) + r0
    for i, v in enumerate([px, py, c.fv(-3, 3)]):
        e.wbytes(P + 4 * i, struct.pack('<f', v))
    ip = e.alloc(4, 4)
    e.w32(ip, r.choice([0xffffffff] * 5 + [0, 1, 2, n - 1 & 0xffffffff, n, n + 1]))
    return [me, P, F(r0), F(c.fv(0, 1.5)), ip, flag, r.getrandbits(32) | r.choice([0, 0xffffffff])]


S(0x5c0160, 'GUESS sorted table sweep for next matching entry', 'thiscall', None, ret='eax', gen=g5c0160, nan_heap=True, note='batch53000')
