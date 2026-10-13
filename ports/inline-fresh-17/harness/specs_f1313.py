"""specs_f1313.py - fresh slice 17, batch 13."""
import struct
from pilot import S
from specs_f0101 import _rnd, _vt, _hook, _obj
from specs_f0202 import _assert_hook

_FV = [0x00000000, 0x80000000, 0x3f800000, 0xbf800000, 0x7f7fffff, 0x00000001, 0x807fffff, 0x7f800000, 0xff800000,
       0x7fc00000, 0x3eaaaaab, 0x42f6e979, 0x1e3ce508, 0x5f000000]


def _f(c):
    if c.rng.random() < 0.3:
        return c.rng.choice(_FV)
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(-100, 100)))[0]


def _g453a50(c):
    e = c.emu
    self_o = _obj(c, 0x50, _vt(c, 'gate', 0x30, {0x88: (1, 4, True)}))

    def sub(e, r):
        e.calllog.append(('sub', e.reg('edx'), e.arg32(0)))
        e.wbytes(e.reg('ecx'), struct.pack('<3I', *[_f(c) for _ in range(3)]))
        e.ret(argbytes=4)
    e.hook(0x43e920, sub)
    zero = c.rng.random() < 0.3

    def cross(e, r):
        e.calllog.append(('cross', e.reg('ecx'), e.rbytes(e.reg('edx'), 12), e.rbytes(e.arg32(0), 12)))
        if zero:
            v = [c.rng.choice([0, 0x80000000]) for _ in range(3)]
            if c.rng.random() < 0.4:
                v[c.rng.randrange(3)] = _f(c)
        else:
            v = [_f(c) for _ in range(3)]
        e.wbytes(e.reg('ecx'), struct.pack('<3I', *v))
        e.ret(argbytes=4)
    e.hook(0x446ee0, cross)
    return [self_o, _rnd(c, 0x10)]


def _g4b13d0(c):
    e = c.emu
    _assert_hook(c)
    _hook(c, 0x4690b0, 2, 0, lecx=False)
    _hook(c, 0x4cbec0, 0, 0)
    db = _obj(c, 0x10, _vt(c, 'db', 0x20, {0x34: (1, 4, True)}))
    eng = _rnd(c, 0x100)
    e.w32(eng + 0x9b, db)
    e.w32(0x70039c, eng)
    return [_rnd(c, 0x60), c.rng.choice([0, 1, 2, 4, 5, 7, 0xfffffffe])]


def _g5fad90(c):
    e = c.emu
    self_o = _rnd(c, 0x48)
    for off in (0x14, 0x20, 0x2c, 0x38):
        k = c.rng.random()
        b = 0 if k < 0.25 else c.rng.getrandbits(32)
        e.w32(self_o + off, b)
        e.w32(self_o + off + 8, b if k > 0.75 else c.rng.getrandbits(32))
    _hook(c, 0x54f870, 2, 8)
    return [self_o]


def _g65a3d0(c):
    e = c.emu
    n = c.rng.choice([1, 2, 3, 4, 5, 8, 9])
    blocks = (n + 3) >> 2
    sz = blocks * 32

    def words(k):
        sp = [0, 1, 0x7fff, 0x8000, 0xffff, 0x1000, 0x0fff]
        return struct.pack('<%dH' % k, *[c.rng.choice(sp) if c.rng.random() < 0.3 else c.rng.getrandbits(16) for _ in range(k)])
    dst, src, cc = _rnd(c, sz), _rnd(c, sz), _rnd(c, sz)
    for p in (dst, src, cc):
        e.wbytes(p, words(sz // 2))
    a, b = _rnd(c, 8), _rnd(c, 8)
    e.wbytes(a, words(4))
    e.wbytes(b, words(4))
    return [dst, src, a, b, cc, n]


def _g481450(c):
    e = c.emu
    _hook(c, 0x4808d0, 2, 8)
    p = 0 if c.rng.random() < 0.2 else _rnd(c, 0x70)
    e.hook(0x45c4b0, lambda e, r: (e.calllog.append(('alloc', e.arg32(0), p)), e.ret(eax=p)))
    _hook(c, 0x480a40, 3, 12)
    eng = _rnd(c, 0x1910)
    e.w32(eng + 0x1907, 0 if c.rng.random() < 0.3 else _obj(c, 0x10, _vt(c, 'reg', 4, {0xc: (3, 12, True)})))
    e.w32(0x70039c, eng)
    ex = 0 if c.rng.random() < 0.6 else c.rng.getrandbits(32)
    return [c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32), ex]


def _g441ad0(c):
    e = c.emu
    p = 0 if c.rng.random() < 0.2 else _rnd(c, 0x90)
    e.hook(0x45c4f0, lambda e, r: (e.calllog.append(('alloc', e.arg32(0), e.arg32(1), p)), e.ret(eax=p)))
    _hook(c, 0x43e990, 3, 12)
    return [c.rng.getrandbits(32) for _ in range(4)]


N = 'fresh 17 batch 13'
S(0x453a50, 'ZGATE::GetRootNormal(float*)', 'thiscall', None, ret=None, gen=_g453a50, note=N + '; PSVECSubtract / vcross hooked (fastcall + 1 word)')
S(0x4b13d0, 'CCutSequenceShowHide::~CCutSequenceShowHide() (deleting)', 'thiscall', None, ret='eax', gen=_g4b13d0, note=N + '; SEH not reproduced')
S(0x5fad90, 'GUESS FUN_5fad90 (destructor of four host vectors)', 'thiscall', None, ret=None, gen=_g5fad90, note=N + '; free 0x54f870 hooked; SEH not reproduced')
S(0x65a3d0, 'GUESS FUN_65a3d0 (MMX blend)', 'fastcall', None, ret=None, gen=_g65a3d0, note=N + '; n >= 1')
S(0x481450, 'GUESS FUN_481450 (ZPlayer-derived factory)', 'fastcall', None, ret='eax', gen=_g481450, note=N + '; 0x4808d0 / allocator / ZPlayer ctor hooked; SEH not reproduced')
S(0x441ad0, 'GUESS FUN_441ad0 (ZGROUP-derived factory)', 'fastcall', None, ret='eax', gen=_g441ad0, note=N + '; allocator / ZGROUP ctor hooked; SEH not reproduced')
