"""specs_f1212.py - fresh slice 17, batch 12."""
import struct
from pilot import S
from specs_f0101 import _rnd, _vt, _hook, _obj
from specs_f0202 import _assert_hook


_FV = [0x00000000, 0x80000000, 0x3f800000, 0xbf800000, 0x7f7fffff, 0x00000001, 0x807fffff, 0x7f800000, 0xff800000,
       0x7fc00000, 0x7f800001, 0xffbfffff, 0x7fa12345, 0x3eaaaaab, 0x42f6e979]


def _fword(c):
    return c.rng.choice(_FV) if c.rng.random() < 0.4 else c.rng.getrandbits(32)


def _g4078d0(c):
    e = c.emu
    n = c.rng.choice([1, 1, 2, 3, 4, 7, 8, 16])
    s = _rnd(c, 0x20)
    e.w32(s + 0xc, n)
    inp = _rnd(c, 4 * n)
    for i in range(n):
        e.w32(inp + 4 * i, _fword(c))

    def tf(e, r):
        b = e.arg32(1)
        e.calllog.append(('tf', e.arg32(0), e.rbytes(b, 8 * n)))
        e.wbytes(b, struct.pack('<%dI' % (2 * n), *[_fword(c) for _ in range(2 * n)]))
        e.ret(eax=c.rng.getrandbits(32))
    e.hook(0x40e240, tf)

    def fin(e, r):
        e.calllog.append(('fin', e.rbytes(e.arg32(0), 8 * n), e.arg32(1), e.arg32(2), e.arg32(3)))
        e.ret(eax=c.rng.getrandbits(32))
    e.hook(0x407770, fin)
    return [inp, c.rng.getrandbits(32), s]


def _g449050(c):
    e = c.emu
    self_o = _rnd(c, 0x20)
    e.w32(self_o + 0x14, c.rng.getrandbits(32))
    g = _rnd(c, 0x70)
    e.w32(self_o + 8, g)
    rec = [c.rng.getrandbits(32) for _ in range(14)]

    def s84(e, r):
        e.calllog.append(('rec', e.reg('ecx'), e.arg32(0)))
        e.wbytes(e.arg32(1), struct.pack('<14I', *rec))
        e.w32(self_o + 0x14, c.rng.getrandbits(32))   # the original re-reads +0x14 after this call
        e.ret(eax=c.rng.getrandbits(32), argbytes=8)
    lm = _obj(c, 0x10, e.fake_vtable('lm', 0x30, {0x84: s84}))
    x = _rnd(c, 0x20)
    e.w32(x + 0x18, lm)
    eng = _rnd(c, 0x1b00)
    e.w32(eng + 0x1aa3, x)
    e.w32(0x70039c, eng)
    db = _obj(c, 0x10, _vt(c, 'db', 0x30, {0x94: (4, 16, True), 0x98: (4, 16, True), 0x9c: (4, 16, True)}))
    return [self_o, db, c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _remove(size, flag):
    def g(c):
        e = c.emu
        k = c.rng.randint(1, 4)
        bsz = 0x10 + size * 4 + 0x10
        blks = [_rnd(c, bsz) for _ in range(k)]
        if c.rng.random() < 0.1:
            for b in blks:
                e.w32(b + 8, b)
                e.w32(b + 0xc, b)
        else:
            for i, b in enumerate(blks):
                e.w32(b + 8, blks[(i + 1) % k])
                e.w32(b + 0xc, blks[(i - 1) % k])
        blk = c.rng.choice(blks)
        e.w8(blk, c.rng.choice([1, 1, 2, 3, 0x80]))
        ent = blk + 0x10 + size * c.rng.randint(0, 3) + c.rng.choice([0, 0, 4, size - flag - 1])
        if c.rng.random() < 0.1:
            ent = blk + 4   # below the first slot: the index is a signed division (truncates to 0)

        def s2c(e, r):
            e.calllog.append(('blk', e.reg('ecx'), e.arg32(0)))
            e.ret(eax=blk, argbytes=4)

        def s34(e, r):
            e.calllog.append(('free', e.reg('ecx'), e.arg32(0)))
            e.ret(eax=c.rng.getrandbits(32), argbytes=4)
        self_o = _obj(c, 0x10, e.fake_vtable('arr', 0x10, {0x2c: s2c, 0x34: s34}))
        e.w32(self_o + 8, c.rng.choice(blks + [blk]))
        return [self_o, ent]
    return g


def _g4d43d0(c):
    e = c.emu
    self_o = _rnd(c, 0x10e0)
    strs = [_rnd(c, 0x30) for _ in range(3)]
    for st in strs:
        e.wbytes(st, bytes(c.rng.randrange(1, 256) for _ in range(c.rng.randint(0, 20))) + b'\0')
    dens = c.rng.choice([0.1, 0.5, 1.0])
    for i in range(20):
        e.w32(self_o + 0xfb7 + 4 * i, c.rng.choice(strs) if c.rng.random() < dens else 0)
    if c.rng.random() < 0.15:
        e.w32(self_o + 0xfb7, 0)
    elif c.rng.random() < 0.3:
        e.w32(self_o + 0xfb7, c.rng.choice(strs))
    e.w32(self_o + 0x10d7, c.rng.randint(0, 19))
    e.w8(self_o + 0x1007, c.rng.choice([0, 0x41]))
    return [self_o, c.rng.choice([0, 1, 0x100, 0xffffff01])]


def _dtor(c):
    e = c.emu
    _assert_hook(c)
    _hook(c, 0x4690b0, 2, 0, lecx=False)
    db = _obj(c, 0x10, _vt(c, 'db', 0x20, {0x34: (1, 4, True)}))
    eng = _rnd(c, 0x100)
    e.w32(eng + 0x9b, db)
    e.w32(0x70039c, eng)
    return [_rnd(c, 0x50), c.rng.choice([0, 1, 2, 4, 5, 7, 0xfffffffe])]


N = 'fresh 17 batch 12'
S(0x4078d0, 'GUESS FUN_4078d0 (spectrum helper)', 'cdecl', None, ret='eax', gen=_g4078d0, note=N + '; 0x40e240 / 0x407770 hooked (buffer logged by contents)')
S(0x449050, 'ZSPOTLIGHT::Draw(ZDrawBuffer*, ZCAMERA*, const float*, const float*)', 'thiscall', None, ret=None, gen=_g449050, note=N)
S(0x6152d0, 'ZDrawArray<ZPrimInstDrawEntryGC, ZPrimInstDrawEntry, ZArrayBlock>::Remove(ZPrimInstDrawEntry*)', 'thiscall', None, ret=None, gen=_remove(0x1c, 5), note=N)
S(0x615f50, 'ZDrawArray<ZCameraViewEntryGC, ZCameraViewEntry, ZArrayBlock>::Remove(ZCameraViewEntry*)', 'thiscall', None, ret=None, gen=_remove(0x138, 9), note=N)
S(0x4d43d0, 'GUESS FUN_4d43d0 (cycle text slots(bool))', 'thiscall', None, ret=None, gen=_g4d43d0, note=N)
S(0x4c3990, 'ZParticleEmitter::~ZParticleEmitter() (deleting)', 'thiscall', None, ret='eax', gen=_dtor, note=N + '; SEH not reproduced')
S(0x5d38d0, 'CMPCheckInsideHill::~CMPCheckInsideHill() (deleting)', 'thiscall', None, ret='eax', gen=_dtor, note=N + '; SEH not reproduced')
