"""specs_s0609.py - fresh-06 batch 9 (docs/20-fresh-06.md)."""
import math
import struct
from pilot import S
from helpers06 import rnd, hk, vt, cvt, obj, seq, rv, eng, logger, handler, zero



def fbits(c):
    v = c.rng.choice([0.0, -0.0, 1.0, 0.5, -2.5, 100.0, 1e-30, 1e30, math.inf, -math.inf, math.nan,
                      c.rng.uniform(-1e3, 1e3)])
    b = struct.unpack('<I', struct.pack('<f', v))[0]
    if c.rng.random() < 0.1:
        b = 0x7f800000 | c.rng.getrandbits(23) | (c.rng.getrandbits(1) << 31)   # NaN payloads
    return b


def _deldtor(c):
    hk(c, 0x4690b0, 2, pop=0)
    eng(c, {0x9b: obj(c, 0x10, vt(c, 'rm', {0x34: (1, 0)}))})
    handler(c)
    return [rnd(c, 0x80), c.rng.choice([0, 1, 4, 5, 7, c.rng.getrandbits(32)])]


def _tv(c):
    hk(c, 0x469870, 0, ecx=True)
    eng(c, {0x9b: obj(c, 0x10, vt(c, 'rm', {0x114: (4, seq([c.rng.getrandbits(32) for _ in range(2)]))}))})
    return [rnd(c, 0x60)]


def _ctor_4b1c(c):
    hk(c, 0x469870, 0, ecx=True)
    hk(c, 0x41e290, 1, pop=0, ret=c.rng.choice([0, rnd(c, 0x108)]))
    hk(c, 0x4d8330, 3, ecx=True, ret=c.rng.getrandbits(32))
    c.emu.w32(0x70039c, obj(c, 0x200, vt(c, 'eng', {0x1a4: (1, 0)})))
    return [rnd(c, 0x60)]


def _tower(c):
    def cm(e, a):
        ecx = e.reg('ecx')
        e.wbytes(ecx, bytes((i * 13 + (e.reg('edx') & 0xff)) & 0xff for i in range(0x24)))
    hk(c, 0x51f930, 0, ecx=True)
    hk(c, 0x4de040, 1, ecx=True, edx=True, fn=cm)
    hk(c, 0x514890, 6, ecx=True)
    this = rnd(c, 0x1700)
    c.emu.w32(this + 0x1684, vt(c, 'ctl', {4: (2, 0), 8: (1, 0), 0xc: (0, c.rng.choice([0, 1, 0x100, 0xffffff01]))}))
    c.emu.w32(this + 0x1658, c.rng.choice([0, rnd(c, 0x40)]))
    c.emu.w32(this + 0x16d5, c.rng.choice([0, 1, 0x100, c.rng.getrandbits(32)]))
    return [this]


def _remove(c):
    nb = c.rng.randrange(1, 4)
    blks = [rnd(c, 0x10 + 140 * 8) for _ in range(nb)]
    for i, b in enumerate(blks):
        c.emu.w32(b + 8, blks[(i + 1) % nb])
        c.emu.w32(b + 0xc, blks[(i - 1) % nb])
        c.emu.wbytes(b, bytes([c.rng.choice([1, 1, 2, 5])]))
    b = c.rng.choice(blks)
    e = b + 0x10 + 140 * c.rng.randrange(8)
    this = obj(c, 0x20, vt(c, 'da', {0x2c: (1, b), 0x34: (1, 0)}))
    c.emu.w32(this + 8, c.rng.choice(blks))
    return [this, e]


def _showhide(c):
    s = bytes(c.rng.getrandbits(8) for _ in range(0x20))

    def ctor(e, a, s=s):
        e.wbytes(e.reg('ecx'), s)
    hk(c, 0x4e5e60, 0, ecx=True, fn=seq([c.rng.choice([0, 1, 0x100, c.rng.getrandbits(32)]) for _ in range(3)]))
    st = rnd(c, 8)
    c.emu.wbytes(st, bytes([c.rng.choice([0, 0x41])]))
    hk(c, 0x4e5ea0, 0, ecx=True, ret=c.rng.choice([0, st, st]))
    hk(c, 0x4cbe80, 1, ecx=True, fn=ctor)
    hk(c, 0x4cbee0, 1, ecx=True)
    hk(c, 0x4cbec0, 0, ecx=True)
    return [rnd(c, 0x80), rnd(c, 0x10)]


def _addcam(c):
    v = rnd(c, 0x20)
    def vp(e, a):   # stack pointers are compared by their first 4 bytes only: log the whole viewport
        e.calllog.append(('vp', e.rbytes(a[0], 16)))
    hk(c, 0x64dde0, 1, ecx=True, fn=vp)
    hk(c, 0x648e50, 1, ecx=True)
    d = obj(c, 0x10, vt(c, 'dev', {0xd8: (0, c.rng.getrandbits(32)), 0xdc: (0, c.rng.getrandbits(32))}))
    eng(c, {0x190f: d})
    this = obj(c, 0x20, vt(c, 'r', {0xa4: (1, c.rng.choice([0, v])), 0xa0: (1, rnd(c, 0x20))}))
    return [this, rnd(c, 0x10)]


def _inside(c):
    nodes = []
    for _ in range(c.rng.randrange(0, 4)):
        n = rnd(c, 0x30)
        if c.rng.random() < 0.7:
            cnt = c.rng.randrange(0, 4)
            pl = rnd(c, 4 + 16 * cnt)
            c.emu.w32(pl, cnt)
            for i in range(4 * cnt):
                c.emu.w32(pl + 4 + 4 * i, fbits(c))
            c.emu.w32(n + 0x24, 0x1000 + len(nodes))
            nodes.append(('pl', pl))
        else:
            c.emu.w32(n + 0x24, 0)
        nodes.append(('n', n))
    ns = [x for k, x in nodes if k == 'n']
    pls = [x for k, x in nodes if k == 'pl']
    m = {}
    for i, n in enumerate(ns):
        m[0x100 + i] = n
        c.emu.w32(n + 8, 0x100 + i + 1 if i + 1 < len(ns) else 0)
    j = 0
    for k, x in nodes:
        pass
    for i, n in enumerate(ns):
        ps = c.emu.r32(n + 0x24)
        if ps:
            m[ps] = pls[j]
            j += 1
    this = obj(c, 0x10, vt(c, 'pc', {0xc: (1, lambda e, a: m.get(a[0], 0))}))
    p = rnd(c, 12)
    for i in range(3):
        c.emu.w32(p + 4 * i, fbits(c))
    return [this, 0x100 if ns else 0, p, fbits(c)]


for a in (0x548d60, 0x5736a0):
    S(a, 'deleting dtor thiscall', 'thiscall', None, ret='eax', gen=_deldtor)
S(0x5d8fa0, 'CTVOnOff::CTVOnOff thiscall', 'thiscall', None, ret='eax', gen=_tv)
S(0x4c6360, 'ctor vtable 0x694b1c (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_ctor_4b1c)
S(0x51fbe0, 'ZPmv::UpdateTowerCannonDir thiscall', 'thiscall', None, gen=_tower)
S(0x615220, 'ZDrawArray<ZGeomDrawEntry>::Remove thiscall', 'thiscall', None, gen=_remove)
S(0x4b1320, 'CCutSequenceShowHide::LoadInit thiscall', 'thiscall', None, gen=_showhide)
S(0x64f6a0, 'ZRender::AddCameraToView thiscall', 'thiscall', None, gen=_addcam)
S(0x655fa0, 'ZPrimControlBase::CheckPointInsidePrim thiscall', 'thiscall', None, ret='al', gen=_inside)
