"""specs_s816.py - animation layer thread, batch 816: UnpackBits and ZAnimFilePack::GetFramePosQuat on generated
clip data (consistent key tables most of the time, broken ones sometimes to reach the asserts)."""
import struct
from pilot import S, F
from anim_common import only_hooks, rnd, install_fmod


def pack_bits(vals, bits):
    acc, nb = 0, 0
    out = bytearray([bits & 0xff])
    for v in vals:
        acc = (acc << bits) | (v & ((1 << bits) - 1))
        nb += bits
    pad = (-nb) % 8 + 32
    acc <<= pad
    nb += pad
    out += acc.to_bytes(nb // 8, 'big')
    return bytes(out)


class Packed:
    def __init__(self, c):
        self.c = c
        self.base = c.emu.alloc(0x2000, 4)
        self.cur = 0x10
        c.emu.wbytes(self.base, bytes(c.rng.getrandbits(8) for _ in range(0x10)))

    def add(self, vals, bits):
        b = pack_bits(vals, bits)
        off = self.cur
        self.c.emu.wbytes(self.base + off, b)
        self.cur += len(b) + 4
        return off


def _unpack(c):
    only_hooks(c, {})
    r = c.rng
    pk = rnd(c, 0x30)
    P = Packed(c)
    bits = r.choice([1, 2, 3, 5, 7, 8, 11, 13, 16, 17])
    vals = [r.getrandbits(bits) for _ in range(r.randint(1, 20))]
    off = P.add(vals, bits)
    c.emu.w32(pk + 0x10, P.base)
    return [pk, off, r.choice([0, 1, len(vals), r.randint(1, len(vals))])]


def _gfpq(c):
    only_hooks(c, {})
    install_fmod(c)
    e, r = c.emu, c.rng
    hook = True
    if hook:
        e.w32(0x7003b0, e.stub_fn('assert', lambda e, res: (e.calllog.append(('assert',)), e.ret())))
    pk = rnd(c, 0x30)
    P = Packed(c)
    e.w32(pk + 0x10, P.base)
    n = r.choice([1, 2, 5, 10, 30, 60, r.randint(1, 120)])

    def keys():
        ks = sorted(set([0, n] + [r.randint(1, n) for _ in range(r.randint(0, 6))]))
        idx = [max(j for j, k in enumerate(ks) if k <= f) for f in range(1, n + 1)]
        ft = ks[1:]
        if r.random() < 0.2:
            ft = [max(0, x + r.choice([-3, 2])) for x in ft]
        bi = max(1, max(idx).bit_length()) + r.choice([0, 0, 1])
        bf = max(1, max(ft).bit_length() if ft else 1) + r.choice([0, 0, 2])
        return ks, P.add(idx, bi), P.add(ft if ft else [0], bf)
    ba = rnd(c, 0x30)
    e.w16(ba + 8, n)
    fl = r.choice([8, 4, 0]) | r.choice([0x10, 1, 2, 0]) if r.random() < 0.97 else r.getrandbits(16)
    e.w16(ba + 0xa, fl)
    cpos = c.fbuf(12 * 4)
    crot = c.fbuf(16 * 4)
    e.w32(pk + 0x1c, cpos)
    e.w32(pk + 0x20, crot)
    e.w16(ba + 4, r.randint(0, 3))
    e.w16(ba + 6, r.randint(0, 3))
    ksp, i1, f1 = keys()
    e.w32(ba + 0x1c, i1)
    e.w32(ba + 0x20, f1)
    posk = c.fbuf(3 * (len(ksp) + 1), lambda cc: cc.fv(-50, 50))
    pbase = rnd(c, 0x10)
    e.w32(pk + 0x18, pbase)
    e.w32(ba + 0x18, posk - pbase)
    ksq, i2, f2 = keys()
    e.w32(ba + 0x10, i2)
    e.w32(ba + 0x14, f2)
    nk = len(ksq) + 1
    rk = e.alloc(8 * nk + 16, 4)
    for i in range(nk):
        if fl & 1:
            e.wbytes(rk + 8 * i, struct.pack('<4h', *[r.randint(-32512, 32512) for _ in range(4)]))
        else:
            e.wbytes(rk + 4 * i, struct.pack('<4b', *[r.randint(-127, 127) for _ in range(4)]))
    rbase = rnd(c, 0x10)
    e.w32(pk + 0x14, rbase)
    e.w32(ba + 0xc, rk - rbase)
    t = r.choice([r.uniform(0, n), float(r.randint(0, n)), r.uniform(-2, n + 10), r.uniform(-5, 200)])   # finite t: NaN time faults on both sides (not a game input)
    return [pk, ba, r.choice([0, 1, 1, 0x100]), c.fbuf(3), c.fbuf(4), F(t)]


S(0x4e5de0, 'ZAnimFilePack::UnpackBits (no GC name)', 'thiscall', None, ret='eax', gen=_unpack, note='batch816')
S(0x4e54c0, 'ZAnimFilePack::GetFramePosQuat', 'thiscall', None, gen=_gfpq, note='batch816')
