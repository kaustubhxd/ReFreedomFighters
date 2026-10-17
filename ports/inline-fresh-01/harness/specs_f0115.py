"""specs_f0115.py - fresh-01 batch 15 (docs/20-fresh-01.md)."""
import struct
from pilot import S
from helpers01 import rnd, hk, obj


def _handler(c):
    def hnd(e, r):
        e.calllog.append(('handler',))
        e.ret(eax=0xbad)
    c.emu.w32(0x7003b0, c.emu.stub_fn('handler', hnd))


def _serial(c):
    n = c.rng.choice([0, 1, 2, 3, 5, 8, 12])
    head = rnd(c, 0x20)
    nodes = [rnd(c, 0x20) for _ in range(n)]

    def build(lo, hi, parent):
        if lo >= hi:
            return 0
        m = c.rng.randint(lo, hi - 1)
        nd = nodes[m]
        c.emu.w32(nd + 1, parent)
        c.emu.w32(nd + 5, build(lo, m, nd))
        c.emu.w32(nd + 9, build(m + 1, hi, nd))
        return nd
    root = build(0, n, head)
    c.emu.w32(head + 1, root)
    c.emu.w32(head + 5, nodes[0] if n else head)
    c.emu.w32(head + 9, nodes[-1] if n else head)
    for nd in nodes:
        v = rnd(c, 0x30)
        c.emu.w32(nd + 0x19, v)
        if c.rng.random() < 0.5:
            c.emu.w32(v + 0x1c, 0)
        else:
            c.emu.w32(v + 0x1c, obj(c, 0x10, 'type', 4, {8: lambda e, a: ((a[0] * 3 + 0x11) & 0xffff, None)}, {8: 1}))
        if c.rng.random() < 0.4:
            c.emu.w32(v + 0x24, 0)
        else:
            c.emu.w32(v + 0x24, rnd(c, 0x30))
    o = rnd(c, 0x10)
    c.emu.w32(o + 1, head)
    return [o]


def _block(c):
    p, q = rnd(c, 12), rnd(c, 12)
    base = rnd(c, 0x40)
    if c.rng.random() < 0.5:
        for k in range(16):
            c.emu.w32(base + 4 * k, c.rng.randint(0, 255))
    idx = rnd(c, 0x40)
    for k in range(16):
        c.emu.w32(idx + 4 * k, c.rng.randint(0, 3))
    small = c.rng.random() < 0.5

    def tb(e, r):
        a, b = e.arg32(0), e.arg32(1)
        e.calllog.append(('table', e.reg('ecx'), bytes(e.rbytes(a, 12)).hex(), bytes(e.rbytes(b, 12)).hex()))
        out = e.reg('edx')
        h = (e.r32(a) * 31 + e.r32(b + 4) * 7 + e.reg('ecx')) & 0xffffffff
        for k in range(16):
            h = (h * 1103515245 + 12345) & 0xffffffff
            e.w32(out + 4 * k, (h >> 24) if small else h)
        e.ret(argbytes=8)
    c.emu.hook(0x6383a0, tb)
    lim = c.rng.choice([0x7fffffff, 0, 1000, 50000, c.rng.getrandbits(32)])
    return [c.rng.choice([0, 1, c.rng.getrandbits(32)]), c.rng.randint(0, 3), p, q, base, idx, lim]


def _view(c):
    _handler(c)
    self_ = c.emu.alloc(0x181d0, 4)
    c.emu.w32(self_, c.emu.logging_vtable('view', 0x20, {}, {0x48: 1}))
    draw = obj(c, 0x10, 'draw', 0x30, {}, {0xa0: 1})
    c.emu.w32(self_ + 0x1005d, draw)
    ent = rnd(c, 0x10)
    inst = rnd(c, 0x14)
    c.emu.w8(inst + 9, c.rng.choice([0, 0, 1, 0xff]))
    c.emu.w32(ent + 8, inst)
    prim = 0 if c.rng.random() < 0.15 else rnd(c, 0x10)
    c.emu.w32(inst + 0x10, prim)
    tab = rnd(c, 0x10)
    c.emu.w32(self_ + 0x10071, tab)
    if prim:
        c.emu.w16(prim + 0xc, c.rng.choice([0, 0, 1, 0xffff]))
        pd = rnd(c, 8)
        c.emu.w32(prim + 8, pd)
        ti = c.rng.randint(0, 3)
        c.emu.w16(pd + 6, ti | (c.rng.getrandbits(4) << 12))
        for k in range(4):
            rec = rnd(c, 0x10)
            c.emu.w32(rec + 0xc, c.rng.choice([0, 0, 1, 0xffffffff]))
            c.emu.w32(tab + 4 * k, rec)
    if c.rng.random() < 0.2:
        c.emu.w32(self_ + 0x181c5, 0)
    else:
        lst = c.emu.alloc(0x8010, 4)
        c.emu.w32(lst, c.rng.choice([0, 1, 5, 0x1fff, 0x2000, 0xffffffff]))
        c.emu.w32(self_ + 0x181c5, lst)
    hk(c, 0x63da80, 'DrawBase::PrimInstanceEnter', 1)
    hk(c, 0x658f50, 'GetTextureNrFrames', 0, eax=c.rng.choice([0, 1, 2, 0x80000000]))
    return [self_, ent]


def _vert(c):
    db = rnd(c, 8)
    if c.rng.random() < 0.1:
        c.emu.w32(db, 0)
        return [rnd(c, 0x70), db]
    buf = rnd(c, 0x20)
    for k in range(0x20):
        c.emu.w8(buf + k, c.rng.choice([2, 3, 0x42, 0x83, 0xff, 0, 1, c.rng.getrandbits(8)]))
    c.emu.w32(db, buf)

    def adv(e):
        p = e.reg('ecx')
        cur = e.r32(p)
        e.w32(p, cur + 1)
        return cur

    def ui(e, r):
        cur = adv(e)
        e.calllog.append(('uint', cur))
        e.ret(eax=0 if e.r8(cur) & 1 else e.r32(cur) | 1)

    def fl(e, r):
        cur = adv(e)
        e.calllog.append(('float', cur))
        e.ret(st0=struct.unpack('<f', struct.pack('<I', e.r32(cur) & 0x7fbfffff))[0])

    def us(e, r):
        cur = adv(e)
        e.calllog.append(('ushort', cur))
        e.ret(eax=e.r32(cur) ^ 0x12340000)
    c.emu.hook(0x4e5e60, ui)
    c.emu.hook(0x4e5e80, fl)
    c.emu.hook(0x4e5e40, us)
    return [rnd(c, 0x70), db]


S(0x603110, 'RunTimeTypeLibrary_t::serialSize', 'thiscall', None, ret='eax', gen=_serial)
S(0x63a390, 'block error 0x63a390', 'fastcall', None, ret='eax', gen=_block)
S(0x64d490, 'ZViewBase::PrimInstanceEnter', 'thiscall', None, ret=None, gen=_view)
S(0x4a4ad0, 'ZVertAnim::CopyEventDataBlock', 'thiscall', None, ret=None, gen=_vert)
