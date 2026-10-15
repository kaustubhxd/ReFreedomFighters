"""specs_s35198.py - 0x561720 (thiscall(a, flag) ret 8 (this = a heap block passed on to the 0x5618b0 hook), ret=None, nan_heap). a: object with slot 0x70 (1 arg, vector recorded as three dwords), [+8] -> block with floats at +0x24, [+0x50] -> list of 1..4 nodes (next at +0x60, item at +0x54): item X with [+8] -> block (dword +0x3c with bit 10 set in 1/3, floats at +0x24) and chain Y = X[0x54]; Y[0x54] = Z with Z[0xc] -> block with an unaligned dword +0x23
(bit 0x100000 set in 1/4), vtable slots 0x1e0 (al true in 3/4) and 0x290 (1 arg, returns a small int), unaligned string pointer +0x97 (null in 1/5), [+8] -> block with floats. 0x4db520 hooked (returns another Y or 0), 0x5618b0 hooked (2 args). Engine unaligned dword +0x6f random; flag low byte zero in 1/3."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, sysobj


def _fb(v):
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _g561720(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def fl(lo=-300, hi=300):
        return float(r.randint(lo, hi)) + r.choice([0.0, 0.25, 0.5, 0.75])

    def fblock(flag10=None):
        b = rnd(c, 0x60)
        for i in range(3):
            e.w32(b + 0x24 + 4 * i, _fb(fl()))
        if flag10 is not None:
            e.w32(b + 0x3c, (r.getrandbits(32) | 0x400) if flag10 else (r.getrandbits(32) & ~0x400))
        return b

    def mkZ():
        zb = rnd(c, 0x40)
        e.wbytes(zb + 0x23, ((r.getrandbits(32) | 0x100000) if r.random() < 1 / 4 else (r.getrandbits(32) & ~0x100000)).to_bytes(4, 'little'))
        zt = 1 if r.random() < 0.75 else 0
        ret = (r.getrandbits(24) << 8) | 1 if zt else (r.getrandbits(24) << 8)
        Z = obj(c, 0x100, {0x1e0: pystub(c, 1, this=True, ret=ret), 0x290: pystub(c, 1, this=True, ret=r.randint(0, 40))}, nslots=0xa8)
        e.w32(Z + 0xc, zb)
        e.w32(Z + 8, fblock())
        if r.random() < 1 / 5:
            e.wbytes(Z + 0x97, bytes(4))
        else:
            s = rnd(c, 0x20)
            e.wbytes(s + r.randint(0, 6), b'\0')
            e.wbytes(Z + 0x97, s.to_bytes(4, 'little'))
        return Z

    def mkY():
        Y = rnd(c, 0x80)
        e.w32(Y + 0x54, mkZ())
        return Y
    sibs = [mkY() if r.random() < 0.7 else 0 for _ in range(4)]
    hook_rec(c, 0x4db520, 0, this=True, pop=0, ret=lambda em, k: sibs[min(k, 3)])
    hook_rec(c, 0x5618b0, 2, this=True, pop=8)
    n = r.choice([1, 2, 3, 4])
    nodes = []
    for _ in range(n):
        node = rnd(c, 0x80)
        X = rnd(c, 0x100)
        e.w32(X + 8, fblock(r.random() < 1 / 3))
        e.w32(X + 0x54, mkY() if r.random() < 0.85 else 0)
        e.w32(node + 0x54, X)
        nodes.append(node)
    for i, nd in enumerate(nodes):
        e.w32(nd + 0x60, nodes[i + 1] if i + 1 < len(nodes) else 0)
    a = obj(c, 0x80, {0x70: pystub(c, 1, this=True, deref={0: 3})}, nslots=0x20)
    e.w32(a + 8, fblock())
    e.w32(a + 0x50, nodes[0])
    so = sysobj(c, table_size=0x20)
    e.wbytes(so + 0x6f, r.randint(0, 2000).to_bytes(4, 'little'))
    flag = (r.getrandbits(24) << 8) | (0 if r.random() < 1 / 3 else r.randint(1, 255))
    return [rnd(c, 0x20), a, flag]


S(0x561720, 'GUESS centre a row of text items', 'thiscall', None, ret=None, gen=_g561720, nan_heap=True, note='batch35198')
