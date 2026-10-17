"""specs_f0118.py - fresh-01 batch 18 (docs/20-fresh-01.md)."""
import struct
from pilot import S
from helpers01 import rnd, hk, obj


def _synth(c):
    self_ = c.emu.alloc(0x8070, 4)
    n = c.rng.choice([0, 1, 3, 4, 5, 6, 8])
    arr = rnd(c, 4 * n + 4)
    bufs = []
    for k in range(n):
        b = rnd(c, 0x80)
        w = rnd(c, 0x10)
        c.emu.w32(b + 0x5d, w)
        c.emu.w8(b + 0x7d, c.rng.choice([0, 1, 1, 1, 0xff]))
        c.emu.w32(w + 8, c.rng.choice([0xffffffff, 0x80000000, 0, 5]))
        c.emu.w32(b + 0x35, c.rng.choice([10, 20, 30, 20, c.rng.getrandbits(32)]))
        c.emu.w32(arr + 4 * k, b)
        bufs.append((b, w))
    if bufs and c.rng.random() < 0.5:
        for b, w in bufs[:4]:
            c.emu.w8(b + 0x7d, 1)
            c.emu.w32(w + 8, 0xffffffff)
    act = [(b, w) for b, w in bufs if c.emu.r8(b + 0x7d)]
    if bufs and len(act) == n and all(c.emu.r32(w + 8) >= 0x80000000 for b, w in act):
        c.emu.w32(act[-1][1] + 8, 7)          # keep one non-negative busy buffer (a null +0x35 read otherwise)
    c.emu.w32(self_ + 0x803d, arr)
    c.emu.w32(self_ + 0x805d, n if c.rng.random() < 0.95 else 0x80000000 | n)
    if c.emu.r32(self_ + 0x805d) & 0x80000000:
        c.emu.w32(self_ + 0x805d, 0xfffffff0)
    hdr = rnd(c, 0x10)
    c.emu.w32(hdr + 8, c.rng.choice([0xffffffff, 0, 1]))
    return [self_, c.rng.choice([0, 15, 25, 35, c.rng.getrandbits(32)]), hdr, c.rng.getrandbits(32)]


def _alloc(c):
    self_ = c.emu.alloc(0x3410, 4)
    nb = c.rng.choice([0, 1, 2, 4, 8])
    c.emu.w32(self_ + 0x3408, nb)
    c.emu.w32(self_ + 0x3404, c.rng.choice([8, 9, 0x28]))
    c.emu.w16(self_ + 0x3400, c.rng.getrandbits(16))
    c.emu.w16(self_ + 0x3402, c.rng.getrandbits(16))
    used = c.rng.sample(range(1024), 40)
    ui = 0
    for b in range(nb):
        prev = self_ + 4 * b
        for _ in range(c.rng.randint(0, 4)):
            nd = self_ + 0x400 + 12 * used[ui]
            ui += 1
            c.emu.w32(nd, c.rng.choice([0x100, 0x200, 0x300, c.rng.randint(0, 0x7f00)]))   # equal offsets test the tie rule
            c.emu.w32(nd + 4, c.rng.choice([1, 8, 16, 32, 64, c.rng.randint(1, 0x80)]))
            c.emu.w32(prev, nd)
            prev = nd + 8
        c.emu.w32(prev, 0)
    return [self_, c.rng.choice([1, 8, 16, 32, 64, c.rng.randint(1, 0x80)])]


def _fb(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _boxlst(c):
    eng = rnd(c, 0x1b00)
    c.emu.w32(0x70039c, eng)
    r = obj(c, 0x20, 'render', 0x40, {0x50: lambda e, a: (a[0] ^ 0x5050, None)}, {0x50: 1})
    c.emu.w32(eng + 0x9b, r)
    h = rnd(c, 0x30)
    c.emu.w32(eng + 0x1aa3, h)
    n = c.rng.choice([0, 1, 3, 10, 0x800])

    def q(e, _):
        a = [e.arg32(k) for k in range(10)]
        e.calllog.append(('query', e.reg('ecx'), bytes(e.rbytes(a[1], 36)).hex(), a[2], a[1] == a[3],
                          bytes(e.rbytes(a[4], 12)).hex(), a[5], a[6], a[7], a[8], a[9]))
        for k in range(n):
            e.w32(a[0] + 4 * k, (k * 0x9e3779b9) & 0xffffffff)
        e.ret(eax=n, argbytes=40)
    tm = rnd(c, 0x10)
    c.emu.w32(tm, c.emu.fake_vtable('tree', 0x20, {0x38: q}))
    c.emu.w32(h + 0x1c, tm)

    def s98(e, _):
        m, p = e.arg32(0), e.arg32(1)
        e.calllog.append(('xform', e.reg('ecx'), bytes(e.rbytes(m, 36)).hex(), bytes(e.rbytes(p, 12)).hex()))
        e.w32(m + 4, e.r32(p) ^ 0x1000)
        e.w32(p + 8, e.r32(m + 0x20) ^ 0x2000)
        e.ret(argbytes=8)
    self_ = rnd(c, 0x20)
    c.emu.w32(self_, c.emu.fake_vtable('tg', 0x30, {0x98: s98}))
    lst = obj(c, 0x10, 'reftab', 8, {}, {4: 1})
    mat, pos, ext = rnd(c, 36), rnd(c, 12), rnd(c, 12)
    return [self_, c.rng.getrandbits(32), lst, mat, pos, ext, c.rng.getrandbits(32), c.rng.getrandbits(32),
            c.rng.getrandbits(32)]


S(0x54da90, 'ZSynth::GetBuffer', 'thiscall', None, ret='eax', gen=_synth)
S(0x63b510, 'ZOffsetAllocPointerSort<1024>::Alloc', 'thiscall', None, ret='eax', gen=_alloc)
S(0x442150, 'ZTreeGroup::AddZGEOMBoxLst', 'thiscall', None, ret=None, gen=_boxlst)
