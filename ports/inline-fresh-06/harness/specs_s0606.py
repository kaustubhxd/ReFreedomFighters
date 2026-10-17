"""specs_s0606.py - fresh-06 batch 6 (docs/20-fresh-06.md)."""
from pilot import S, F
from helpers06 import rnd, hk, vt, cvt, obj, seq, rv, eng, logger, handler, zero
import math


def _subzone(c):
    hk(c, 0x610100, 1, ecx=True)
    hk(c, 0x4e5e60, 0, ecx=True, fn=seq(rv(c)))
    eng(c, {0x9b: obj(c, 0x10, vt(c, 'rm', {0x58: (1, seq(rv(c)))}))})
    return [rnd(c, 0x240), rnd(c, 0x20)]


def _fac(c):
    al = obj(c, 0x10, vt(c, 'al', {0x44: (1, c.rng.choice([0, rnd(c, 0x160)]))}))
    rm = rnd(c, 0x20)
    c.emu.w32(rm + 8, al)
    eng(c, {0x9b: rm})
    hk(c, 0x469870, 0, ecx=True)
    return [c.rng.getrandbits(32)]


def _vb(c):
    dev = obj(c, 0x10, cvt(c, 'dev', {0x5c: (6, c.rng.getrandbits(32))}, pops={0x5c: 0x18}))
    fvf = rnd(c, 8)
    cnt = rnd(c, 8)
    c.emu.w32(cnt, c.rng.choice([0, 1, 4, 1000, c.rng.getrandbits(32)]))
    return [rnd(c, 0x40), dev, fvf, cnt, c.rng.getrandbits(32)]


def _ctor69(c):
    hk(c, 0x519330, 2, ecx=True)
    hk(c, 0x51ace0, 0, ecx=True)
    c.emu.w32(0x701730, c.rng.choice([0, 1]))
    idv = c.rng.getrandbits(32)

    def wid(e, a):
        e.w32(a[0], idv)
    a = rnd(c, 0x40)
    c.emu.w32(a + 0x15, obj(c, 0x10, vt(c, 'rd', {0x40: (1, wid)})))
    eng(c, {0x9b: obj(c, 0x10, vt(c, 'rm', {0x58: (1, c.rng.getrandbits(32))}))})
    return [rnd(c, 0x40), a, c.rng.getrandbits(32)]


def _treesize(c):
    s = bytes(c.rng.getrandbits(8) for _ in range(8))

    def calc(e, a, s=s):
        e.wbytes(a[0], s)
    hk(c, 0x48c4b0, 2, ecx=True, fn=calc)
    hk(c, 0x4cc1d0, 0, ecx=True, ret=rnd(c, 0x10))
    hk(c, 0x4cbec0, 0, ecx=True)
    c.emu.w32(0x700394, obj(c, 0x10, vt(c, 'fs', {0x30: (2, c.rng.getrandbits(32))})))
    return [rnd(c, 0x20)]


def _freedyn(c):
    hk(c, 0x4dc1e0, 1, ecx=True)
    k = c.rng.randrange(0, 4)
    counts = list(range(k, -1, -1))
    st = [0]

    def cnt(e, a):
        v = counts[min(st[0], len(counts) - 1)]
        st[0] += 1
        return v
    items = rv(c, 4)
    ok = [c.rng.choice([1, 1, 0]) for _ in range(4)]
    s2 = [0]

    def nxt(e, a):
        i = s2[0] % 4
        s2[0] += 1
        e.w32(a[0], ok[i])
        return items[i]
    this = obj(c, 0x100, vt(c, 'room', {0x36c: (1, 0)}))
    c.emu.w32(this + 0xa8, c.rng.choice([0, obj(c, 0x10, vt(c, 'l', {0x14: (0, cnt), 0x4c: (1, 0), 0x5c: (1, nxt), 0: (1, 0)}))]))
    return [this]


def _ctor96(c):
    hk(c, 0x5fa5d0, 0, ecx=True)
    hk(c, 0x41e290, 1, pop=0, ret=c.rng.getrandbits(32))
    return [rnd(c, 0x40)]


def _sndfree(c):
    hk(c, 0x44b610, 0, ecx=True)
    s = c.rng.choice([0, rnd(c, 0x20)])
    if s:
        c.emu.w32(s + 0x10, c.rng.choice([0, 1]))
    rm = obj(c, 0x10, vt(c, 'rm', {0x60: (1, s)}))
    eng(c, {0x9b: rm, 0x1a9f: c.rng.choice([0, obj(c, 0x10, vt(c, 'ss', {0x118: (1, 0)}))])})
    this = rnd(c, 0x40)
    c.emu.w32(this + 0x1c, c.rng.choice([0, 7, c.rng.getrandbits(32)]))
    return [this]


def _blk(c, free):
    b = rnd(c, 0x10 + 4 * 0x4c + 8)
    c.emu.wbytes(b + 2, b'\xff\xff' if not free else c.rng.randrange(4).to_bytes(2, 'little'))
    return b


def _roomadd(c):
    blks = [_blk(c, c.rng.random() < 0.3) for _ in range(c.rng.choice([0, 1, 2, 3]))]
    for i, b in enumerate(blks):
        c.emu.w32(b + 8, blks[i + 1] if i + 1 < len(blks) else c.rng.choice([0, blks[0]]))
    this = rnd(c, 0x40)
    c.emu.w32(this + 8, blks[0] if blks else 0)
    nb = _blk(c, c.rng.random() < 0.7)

    ok = c.rng.choice([0, 1, 0x100])

    def cc(e, a, nb=nb, ok=ok):
        if ok & 0xff:
            e.w32(e.reg('ecx') + 8, nb)
        return ok
    hk(c, 0x63b440, 0, ecx=True, fn=cc)
    return [this]


def _trig(c):
    o = obj(c, 0x10, vt(c, 'o', {0x30: (1, 0)}))
    sl = rnd(c, 8)
    c.emu.w32(sl, o)
    hk(c, 0x5003d0, 1, ecx=True, ret=sl)
    ev = obj(c, 0x10, vt(c, 'ev', {0x4c: (0, rnd(c, 0x10))}))
    fac = obj(c, 0x10, vt(c, 'fac', {0x18: (1, c.rng.choice([0, ev, ev]))}))
    eng(c, {0x9b: obj(c, 0x10, vt(c, 'rm', {0x58: (1, c.rng.choice([0, rnd(c, 0x10)]))}))})
    return [fac, c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _viewport(c):
    def fv():
        # in int range only: out-of-range and NaN values take the CRT's error path, which faults in the emulator
        return F(c.rng.choice([0.0, 0.5, 1.5, -1.5, 2.5, 640.0, 479.9, -0.0, 2.1e9, -2.1e9, c.rng.uniform(-1e4, 1e4)]))
    dev = obj(c, 0x10, cvt(c, 'dev', {0xa0: (2, lambda e, a: e.calllog.append(('vp', e.rbytes(a[1], 24).hex())) or 0)},
                           pops={0xa0: 8}))
    this = rnd(c, 0x1400)
    c.emu.w32(this + 0x1377, dev)
    return [this, fv(), fv(), fv(), fv()]


S(0x576120, 'ZSubZoneMap::CopyEventDataBlock thiscall', 'thiscall', None, gen=_subzone)
S(0x5c5360, 'factory vtable 0x6b4180 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_fac)
S(0x607da0, 'vertex buffer wrapper init (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_vb)
S(0x51a960, 'ctor vtable 0x69f364 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_ctor69)
S(0x490c60, 'ZEngineDataBase::GetRoomInsideTreeSize thiscall', 'thiscall', None, ret='eax', gen=_treesize,
  stack_arg_bytes=8)
S(0x4444a0, 'ZROOM::FreeDynamicGeomList thiscall', 'thiscall', None, gen=_freedyn)
S(0x600be0, 'ctor vtable 0x6b96fc (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_ctor96)
S(0x44c060, 'ZSNDOBJ::Free thiscall', 'thiscall', None, gen=_sndfree)
S(0x63af20, 'ZDrawArray<ZRoomDrawEntry>::Add thiscall', 'thiscall', None, ret='eax', gen=_roomadd)
S(0x5007e0, 'TriggerEventTranslator_t::handleEventTranslation stdcall', 'stdcall', None, ret='eax', gen=_trig,
  stack_arg_bytes=25)
S(0x610ea0, 'set viewport (GUESS) thiscall', 'thiscall', None, gen=_viewport)
