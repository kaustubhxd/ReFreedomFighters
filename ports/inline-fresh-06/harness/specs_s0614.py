"""specs_s0614.py - fresh-06 batch 14 (docs/20-fresh-06.md)."""
from pilot import S
from helpers06 import rnd, hk, vt, cvt, obj, seq, rv, eng, logger, handler, zero


def _params(c, n_in):
    p = rnd(c, 0x10)
    ins, out = rnd(c, 8), rnd(c, 8)
    c.emu.w32(p + 4, ins)
    c.emu.w32(p + 8, out)
    vals = [rnd(c, 8) for _ in range(n_in)]
    res = rnd(c, 8)
    m = {ins: vals, out: [res]}
    hk(c, 0x5003d0, 1, ecx=True,
       fn=lambda e, a: m[e.reg('ecx')][a[0]] if e.reg('ecx') in m and a[0] < len(m[e.reg('ecx')]) else 0)
    return p, vals, res


def _sfloat(c):
    p, vals, res = _params(c, 1)
    t = c.rng.choice([3, 4, 3, 4, 1])
    c.emu.wbytes(vals[0] + 4, bytes([t]))
    if t == 4:
        c.emu.w32(vals[0], obj(c, 0x10, vt(c, 'val', {0x34: (0, c.rng.getrandbits(32))})))
    c.emu.wbytes(res + 4, bytes([c.rng.choice([0, 2, 0, 2, 1, 3])]))
    fv = c.rng.choice([c.rng.getrandbits(32), 0x7fa00001, 0x3f800000])

    def s84(e, a, fv=fv):
        e.calllog.append(('84f', e.r32(a[1])))
        e.w32(a[1], fv)
    o = obj(c, 0x10, vt(c, 'o', {0x84: (2, s84)}))
    eng(c, {0x9b: obj(c, 0x10, vt(c, 'rm', {0x138: (0, o)}))})
    logger(c, 2)
    handler(c)
    return [p]


def _pause(c):
    p, vals, res = _params(c, 1)
    data = bytes(c.rng.getrandbits(8) for _ in range(48))

    def s80(e, a, data=data):
        e.wbytes(a[0], data[:36])
        e.wbytes(a[1], data[36:])
    g = obj(c, 0x10, vt(c, 'g', {0x80: (2, s80)}))

    def mk(name, base, ret):
        def f(e, a):
            e.calllog.append((name, e.rbytes(a[base], 36), e.rbytes(a[base + 1], 12), e.rbytes(a[base + 2], 12)))
            return ret
        return f
    t = obj(c, 0x10, vt(c, 't', {0x238: (5, mk('238', 0, c.rng.getrandbits(32))), 0x23c: (6, mk('23c', 1, 0))}))
    rm = obj(c, 0xb00, vt(c, 'rm', {0x58: (1, g), 0xb4: (1, 0)}))
    c.emu.w32(rm + 0xadc, t)
    eng(c, {0x9b: rm})
    c.emu.w32(0x713f08, c.rng.choice([0, c.rng.getrandbits(32)]))
    logger(c, 1)
    return [p]


def _osd(c):
    hk(c, 0x469870, 0, ecx=True)
    eng(c, {0x9b: obj(c, 0x10, vt(c, 'rm', {0x114: (4, seq([c.rng.getrandbits(32) for _ in range(4)]))}))})
    c.emu.w32(0x6ef80c, c.rng.getrandbits(32))
    return [rnd(c, 0xa0)]


def _koth(c):
    hk(c, 0x610100, 1, ecx=True)
    hk(c, 0x4e5e60, 0, ecx=True, fn=seq([c.rng.getrandbits(32) for _ in range(9)]))
    eng(c, {0x9b: obj(c, 0x10, vt(c, 'rm', {0x58: (1, lambda e, a: (a[0] * 2654435761 + 3) & 0xffffffff)}))})
    this = rnd(c, 0x1a0)
    c.emu.w32(this + 0x44, obj(c, 0x10, vt(c, 'm', {0xbc: (1, 0)})))
    return [this, rnd(c, 0x10)]


def _settext(c):
    def strz(s):
        a = rnd(c, len(s) + 4)
        c.emu.wbytes(a, s + b'\0')
        return a
    words = [b'', b'a', b'abc', b'hello', b'abd']
    old = c.rng.choice([None, b'abc', b'', b'hello'])
    new = c.rng.choice(words + [None] if old is None else words)
    def s_f8(e, a):
        return rnd(c, a[0] + 8)
    eng0 = obj(c, 0x200, vt(c, 'eng', {0xfc: (1, 0), 0xf8: (1, s_f8)}))
    c.emu.w32(0x70039c, eng0)
    this = obj(c, 0xa0, vt(c, 'co', {0x278: (0, c.rng.getrandbits(32)), 0x230: (0, c.rng.getrandbits(32))}))
    c.emu.w32(this + 0x97, strz(old) if old is not None else 0)
    c.emu.w32(this + 0x9b, c.rng.choice([0, c.rng.getrandbits(32)]))
    return [this, strz(new) if new is not None else 0]


S(0x50f2e0, 'ZScriptSceneInterface_t::GetSceneFloat stdcall', 'stdcall', None, gen=_sfloat)
S(0x5524a0, 'CFFTools_if::EnginePause stdcall', 'stdcall', None, gen=_pause)
S(0x5d9360, 'CTVOSDCamControl::CTVOSDCamControl thiscall', 'thiscall', None, ret='eax', gen=_osd)
S(0x56cb20, 'CMultiplayerKOTH::CopyEventDataBlock thiscall', 'thiscall', None, gen=_koth)
S(0x4f12e0, 'ZCHAROBJ::SetText thiscall', 'thiscall', None, ret='al', gen=_settext)
