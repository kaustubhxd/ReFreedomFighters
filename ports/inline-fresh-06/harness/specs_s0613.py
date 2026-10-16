"""specs_s0613.py - fresh-06 batch 13 (docs/20-fresh-06.md)."""
from pilot import S
from helpers06 import rnd, hk, vt, cvt, obj, seq, rv, eng, logger, handler, zero


def _wincopy(c):
    vals = [c.rng.choice([0, 1, 0x100, c.rng.getrandbits(32)]) for _ in range(6)]
    st = [0]

    def get(e, a):
        e.w32(a[0], vals[st[0] % len(vals)])
        st[0] += 1
    hk(c, 0x44edd0, 1, ecx=True)
    hk(c, 0x4e12e0, 2, ecx=True, fn=get)
    hk(c, 0x4e11e0, 2, ecx=True, fn=get)
    hk(c, 0x4e14a0, 2, ecx=True, fn=lambda e, a: e.wbytes(a[0], bytes([c.rng.getrandbits(8)])))
    hk(c, 0x4e1600, 0, ecx=True, fn=seq([c.rng.choice([3, 0x103, 2, 0]) for _ in range(2)]))
    hk(c, 0x4e1b30, 0, ecx=True)
    eng(c, {0x9b: obj(c, 0x10, vt(c, 'rm', {0x58: (1, lambda e, a: (a[0] * 2654435761 + 1) & 0xffffffff)}))})
    this = obj(c, 0x600, vt(c, 'w', {0x32c: (1, 0)}))
    return [this, rnd(c, 0x10)]


def _params(c, n_in):
    p = rnd(c, 0x10)
    ins, out = rnd(c, 8), rnd(c, 8)
    c.emu.w32(p + 4, ins)
    c.emu.w32(p + 8, out)
    vals = [rnd(c, 8) for _ in range(n_in)]
    res = rnd(c, 8)
    m = {ins: vals, out: [res]}
    hk(c, 0x5003d0, 1, ecx=True, fn=lambda e, a: m[e.reg('ecx')][a[0]] if e.reg('ecx') in m and a[0] < len(m[e.reg('ecx')]) else 0)
    hk(c, 0x5002f0, 1, ecx=True)
    return p, vals


def _native(c):
    p, vals = _params(c, 2)
    t = c.rng.choice([3, 4, 3, 4, 1, 0x13])
    c.emu.wbytes(vals[0] + 4, bytes([t]))
    if t == 4:
        c.emu.w32(vals[0], obj(c, 0x10, vt(c, 'val', {0x34: (0, c.rng.getrandbits(32))})))
    nv = c.rng.getrandbits(32)

    def s88(e, a, nv=nv):
        e.calllog.append(('88n', e.r32(a[1])))
        e.w32(a[1], nv)
    o = obj(c, 0x10, vt(c, 'o', {0x88: (2, s88), 0x5c: (3, 0)}))
    eng(c, {0x9b: obj(c, 0x10, vt(c, 'rm', {0x138: (0, o)}))})
    logger(c, 2)
    handler(c)
    return [p]


def _copypos(c):
    p, vals = _params(c, 2)
    data = bytes(c.rng.getrandbits(8) for _ in range(48))

    def s80(e, a, data=data):
        e.wbytes(a[0], data[:36])
        e.wbytes(a[1], data[36:])

    def s7c(e, a):
        e.calllog.append(('7c', e.rbytes(a[0], 36), e.rbytes(a[1], 12)))
    src = obj(c, 0x10, vt(c, 's', {0x80: (2, s80)}))
    dst = obj(c, 0x10, vt(c, 'd', {0x7c: (2, s7c)}))
    gs = {1: c.rng.choice([0, dst, dst]), 2: c.rng.choice([0, src, src])}
    c.emu.w32(vals[0], 1)
    c.emu.w32(vals[1], 2)
    eng(c, {0x9b: obj(c, 0x10, vt(c, 'rm', {0x58: (1, lambda e, a: gs.get(a[0], 0))}))})
    logger(c, 1)
    return [p]


def _freename(c):
    def s140(e, a):
        e.wbytes(a[0], b'PATHSTR\0')
        return a[0]
    eng0 = obj(c, 0x200, vt(c, 'eng', {0x140: (1, s140)}))
    c.emu.w32(0x70039c, eng0)
    cs = rnd(c, 0x10)
    hk(c, 0x4cc1d0, 0, ecx=True, fn=lambda e, a: (e.calllog.append(('cstr', e.rbytes(e.reg('ecx'), 8))), cs)[1])
    hk(c, 0x4cbec0, 0, ecx=True)

    def spr(e, a):
        e.wbytes(a[0], b'%x/%x/%x/%x\0' % (a[1], a[2], a[3], a[4]))
    hk(c, 0x42ac56, 5, pop=0, fn=spr)
    fs = obj(c, 0x10, vt(c, 'fs', {
        0x5c: (1, lambda e, a: e.calllog.append(('n', e.rbytes(a[0], 40))) or 0),
        0x34: (2, seq([c.rng.choice([0, 0, 1, 0x100]) for _ in range(3)]))}))
    c.emu.w32(0x700394, fs)
    return [c.rng.getrandbits(32)]


S(0x4f20a0, 'ZWINDOWS::CopyDataBlock thiscall', 'thiscall', None, gen=_wincopy)
S(0x50d9e0, 'script native (GUESS) stdcall', 'stdcall', None, gen=_native)
S(0x50dc60, 'ZScriptSceneInterface_t::CopyObjectPosDir stdcall', 'stdcall', None, gen=_copypos)
S(0x48f5e0, 'find free numbered name (GUESS) stdcall', 'stdcall', None, ret='al', gen=_freename)
