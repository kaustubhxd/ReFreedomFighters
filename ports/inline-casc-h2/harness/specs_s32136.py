"""specs_s32136.py - h2 (Sonnet) batch 32136: 0x5291f0, 0x5d7ef0."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

NAN = 0x7fc00000


def g5291f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = rnd(c, 0x2200)
    e.wbytes(me + 0x8d, struct.pack('<I', r.choice([0, 1, 2, 3, 4, 0xffffffff, 0x80000000])))
    e.wbytes(me + 0x91, struct.pack('<I', r.choice([0, 1, 2, 3, 4, 0xffffffff])))

    def side(emu, k):
        if r.random() < 0.15:
            emu.wbytes(me + 0x8d, struct.pack('<I', r.choice([0, 1, 2, 3])))
        if r.random() < 0.15:
            emu.wbytes(me + 0x91, struct.pack('<I', r.choice([0, 1, 2, 3])))
        emu.calllog.append(('s', k))
    hook_rec(c, 0x516730, 1, this=True, pop=4)
    hook_rec(c, 0x52a1e0, 0, this=True, pop=0, side=side)
    return [me, F(r.choice([0.0, 1.0, r.uniform(-9, 9), struct.unpack('<f', struct.pack('<I', NAN))[0]]))]


def g5d7ef0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 2, 3, 4, 5])
    me = rnd(c, 4 + 12 * (n + 4))
    e.w32(me, n)
    idx = r.choice([0, 0, 1, 2, n - 1 if n else 0, n, n + 1, n + 2, r.randrange(0, n + 3)])
    if idx > n + 2:
        idx = n + 2
    if n and r.random() < 0.2:
        src = me + 4 + 12 * r.randrange(0, n)   # source inside the array (read after the move)
    else:
        src = rnd(c, 0x10)
    return [me, idx, src]


def _bits(f):
    return struct.unpack('<I', struct.pack('<f', f))[0]


def g4bf2b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    w48 = r.getrandbits(16)
    w4a = r.choice([r.getrandbits(16), w48])
    lim = r.choice([0.0, 1.0, r.uniform(-9, 9), 100.0, -2.5])
    nanf = struct.unpack('<f', struct.pack('<I', NAN))[0]
    rv = r.choice([lim, lim, lim - 1.0, lim + 1.0, lim + 0.5, nanf, r.uniform(-9, 9)])
    sysobj(c, rand=rv)
    me = obj(c, 0x80, {0x64: pystub(c, 1, this=True), 0x68: pystub(c, 2, this=True)}, nslots=0x6c // 4)
    e.wbytes(me + 0x48, struct.pack('<H', w48))
    e.wbytes(me + 0x4a, struct.pack('<H', w4a))
    e.wbytes(me + 0x66, struct.pack('<I', _bits(lim) if r.random() < 0.9 else NAN))
    t = r.random()
    w = r.choice([w48, w48, w4a, r.getrandbits(16), w48 ^ 0x100])
    w |= r.getrandbits(16) << 16
    if r.random() < 0.2:
        p = 0
    else:
        p = rnd(c, 0x10)
        vals = [0, 1, 2, 5, -1, -3, 0x7fffffff, 0x80000000, 0x1000001, r.getrandbits(32)]
        x = r.choice(vals)
        y = r.choice(vals + [x, x + 1])
        e.wbytes(p, struct.pack('<III', x & 0xffffffff, y & 0xffffffff, r.choice(vals) & 0xffffffff))
    return [me, w, p]


S(0x5291f0, 'GUESS update two arrays of entries (variant)', 'thiscall', None, ret=None, gen=g5291f0, nan_heap=True, note='batch32136')
S(0x5d7ef0, 'GUESS insert 12-byte element into array', 'thiscall', None, ret=None, gen=g5d7ef0, nan_heap=True, note='batch32136')
S(0x4bf2b0, 'GUESS handle press and release event', 'thiscall', None, ret='eax', gen=g4bf2b0, nan_heap=True, note='batch32136')
