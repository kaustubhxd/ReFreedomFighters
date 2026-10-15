"""specs_s0610.py - fresh-06 batch 10 (docs/20-fresh-06.md)."""
from pilot import S
from helpers06 import rnd, hk, vt, cvt, obj, seq, rv, eng, logger, handler, zero


def _serial(ctor, glob, init):
    def g(c):
        hk(c, 0x41e290, 1, pop=0, ret=c.rng.choice([0, rnd(c, 0x20), rnd(c, 0x20)]))
        hk(c, ctor, 2, ecx=True)
        hk(c, init, 0, ecx=True)
        c.emu.w32(glob, c.rng.choice([0, 1, c.rng.getrandbits(32)]))
        v = c.rng.getrandbits(32)

        def s40(e, a, v=v):
            e.w32(a[0], v)
            return 0
        st = obj(c, 0x10, vt(c, 'st', {0x40: (1, s40)}))
        si = rnd(c, 0x20)
        c.emu.w32(si + 0x15, st)
        eng(c, {0x9b: obj(c, 0x10, vt(c, 'rm', {0x58: (1, c.rng.getrandbits(32))}))})
        return [si, rnd(c, 0x10)]
    return g


def _ltdtor(c):
    hk(c, 0x4ccf60, 0, ecx=True)
    hk(c, 0x4690b0, 2, pop=0)
    eng(c, {0x9b: obj(c, 0x10, vt(c, 'rm', {0x34: (1, 0)}))})
    handler(c)
    return [rnd(c, 0x80), c.rng.choice([0, 1, 4, 5, 7, c.rng.getrandbits(32)])]


def _owner(c):
    a0 = rnd(c, 8)
    res = rnd(c, 8)
    c.emu.wbytes(res + 4, bytes([c.rng.choice([0, 1, 2, 0xff])]))
    arrs = {}
    p = rnd(c, 0x10)
    in_arr, out_arr = rnd(c, 8), rnd(c, 8)
    c.emu.w32(p + 4, in_arr)
    c.emu.w32(p + 8, out_arr)
    m = {in_arr: a0, out_arr: res}
    hk(c, 0x5003d0, 1, ecx=True, fn=lambda e, a: m.get(e.reg('ecx'), 0))
    hk(c, 0x5002f0, 1, ecx=True)
    hk(c, 0x4db2f0, 1, ecx=True, ret=c.rng.getrandbits(32))
    g = c.rng.choice([0, rnd(c, 0x10)])
    eng(c, {0x9b: obj(c, 0x10, vt(c, 'rm', {0x58: (1, g), 0x4c: (1, c.rng.getrandbits(32))}))})
    logger(c, 2)
    handler(c)
    return [p]


def _gf(c):
    hk(c, 0x447140, 2, ecx=True, edx=True, ret=c.rng.getrandbits(32))
    hk(c, 0x45c4b0, 1, pop=0, ret=c.rng.choice([0, rnd(c, 0x20), rnd(c, 0x20)]))
    hk(c, 0x45c3a0, 3, ecx=True)
    rm = rnd(c, 0xc00)
    c.emu.wbytes(rm + 0xbad, bytes([c.rng.choice([0, 1, 0x80])]))
    eng(c, {0x9b: rm})
    return [rnd(c, 0x10), rnd(c, 0x10), rnd(c, 0x10), c.rng.choice([0, rnd(c, 0x10)])]


S(0x504660, 'serial factory OpaqueType 0x69c9c0 (GUESS) fastcall', 'fastcall', None, ret='eax',
  gen=_serial(0x5f9700, 0x700e70, 0x5044c0))
S(0x51ae60, 'serial factory 0x69f364 (GUESS) fastcall', 'fastcall', None, ret='eax',
  gen=_serial(0x519330, 0x701730, 0x51ace0))
S(0x51f320, 'serial factory 0x69fa64 (GUESS) fastcall', 'fastcall', None, ret='eax',
  gen=_serial(0x519330, 0x7018d8, 0x51f170))
S(0x57fc20, 'CLightToggle deleting dtor thiscall', 'thiscall', None, ret='eax', gen=_ltdtor)
S(0x50f060, 'ZScriptSceneInterface_t::GetOwnerForGeom stdcall', 'stdcall', None, gen=_owner)
S(0x4480a0, 'geom factory 0x67e300 (GUESS) fastcall', 'fastcall', None, ret='eax', gen=_gf)
