"""specs_f1111.py - fresh slice 17, batch 11."""
import struct
from pilot import S
from specs_f0101 import _rnd, _vt, _hook, _obj
from specs_f0202 import _assert_hook


def _g621c10(c):
    e = c.emu
    enc = _rnd(c, 0x150)
    types = [0, 1, 9, 10, 11, 12, 13, 19, 20, 21, 22, 23, 25, 26, 27, 28, 29, 30, 35, 36, 0xff]
    e.wbytes(enc + 0x4c, bytes(c.rng.choice(types) for _ in range(256)))
    n = c.rng.choice([0, 1, 2, 5, 12])
    lows = [9, 0x20, 0x24, 0x40, 0x41, 0x7f, 0x80, 0xff, 0x30, 0x2d]
    s = b''
    for _ in range(n + 2):
        hi = 0 if c.rng.random() < 0.85 else c.rng.choice([1, 0x20, 0x4e, 0xd8, 0xff])
        lo = c.rng.choice(lows) if c.rng.random() < 0.5 else c.rng.getrandbits(8)
        s += bytes([hi, lo])
    p = _rnd(c, len(s) + 4)
    e.wbytes(p, s)
    if c.rng.random() < 0.5:
        # half the cases stub unicode_byte_type so non-zero high bytes also reach BT_S / BT_NAME / the default path
        # The callee takes char arguments (reads only the low bytes; the original pushes ebx/edx with stale upper
        # bits), so the stub looks only at the low bytes and answers from a per-case table.
        salt = c.rng.getrandbits(16)

        def ubt(e, r):
            hi, lo = e.arg32(0) & 0xff, e.arg32(1) & 0xff
            t = types[(hi * 131 + lo * 7 + salt) % len(types)]
            e.calllog.append(('ubt', hi, lo, t))
            e.ret(eax=t)
        e.hook(0x62c640, ubt)
    return [enc, p, p + len(s), _rnd(c, 8)]


def _g405710(c):
    e = c.emu
    m = _rnd(c, 0x10)
    cols = c.rng.choice([0, 1, 2, 3, 4, -1 & 0xffffffff])
    rows = c.rng.choice([0, 1, 2, 3, 5, -2 & 0xffffffff])
    e.w32(m, cols)
    e.w32(m + 4, rows)
    _hook(c, 0x4050f0, 2, 0, lecx=False)
    nr = rows if rows < 0x80000000 else 0
    nc = cols if cols < 0x80000000 else 0
    vals = [0.0, -0.0, 1e-13, -1e-13, 9.999999960041972e-13, 1.1e-12, 1.0, float('nan'), -5.0]
    d = 0 if c.rng.random() < 0.15 else _rnd(c, 4 * nr * nc + 4)
    if d:
        zero_p = c.rng.random()
        for i in range(nr * nc):
            v = c.rng.choice(vals) if c.rng.random() > zero_p else 0.0
            e.wf32(d + 4 * i, v)

    def h(e, r):
        e.calllog.append(('data', e.arg32(0)))
        e.ret(eax=d)
    e.hook(0x405460, h)
    return [_rnd(c, 0x20), m]


def _g4834d0(c):
    e = c.emu
    n = c.rng.choice([3, 3, 3, 2, 0, -1])
    vals = [c.rng.getrandbits(32) for _ in range(3)]

    def sc(e, r):
        e.calllog.append(('sscanf', e.arg32(0), e.arg32(1)))
        for k in range(3):
            if k < n:
                e.w32(e.arg32(2 + k), vals[k])
        e.ret(eax=n & 0xffffffff)
    e.hook(0x42ab0d, sc)
    mv = [c.rng.getrandbits(32) for _ in range(12)]

    def get(e, r):
        e.calllog.append(('get', e.reg('ecx')))
        e.wbytes(e.arg32(0), struct.pack('<9I', *mv[:9]))
        e.wbytes(e.arg32(1), struct.pack('<3I', *mv[9:]))
        e.ret(eax=c.rng.getrandbits(32), argbytes=8)

    def put(e, r):
        e.calllog.append(('put', e.reg('ecx'), e.rbytes(e.arg32(0), 0x24), e.rbytes(e.arg32(1), 12)))
        e.ret(eax=c.rng.getrandbits(32), argbytes=8)
    objs = [_obj(c, 0x10, e.fake_vtable('o%d' % k, 0x30, {0x80: get, 0x7c: put})) for k in range(2)]

    def s20(e, r):
        o = objs.pop(0) if objs else 0
        e.calllog.append(('s20', e.reg('ecx'), o))
        e.ret(eax=o)
    self_o = _rnd(c, 0x110)
    e.w32(self_o + 0x104, _obj(c, 0x10, e.fake_vtable('h', 0x10, {0x20: s20})))
    return [self_o, 0 if c.rng.random() < 0.15 else _rnd(c, 0x10)]


def _g49a6d0(c):
    e = c.emu
    _assert_hook(c)
    kind = c.rng.choice([0, 1, 2, 3, 4, 5, 0xffffffff])
    words = [kind, c.rng.getrandbits(32)]

    def s14(e, r):
        w = words.pop(0) if words else 0
        e.calllog.append(('rd', e.reg('ecx'), e.r32(e.arg32(0))))
        e.w32(e.arg32(0), w)
        e.ret(eax=c.rng.getrandbits(32), argbytes=4)
    self_o = _obj(c, 0x10, e.fake_vtable('ld', 8, {0x14: s14}))
    db = _obj(c, 0x10, _vt(c, 'db', 0x61, {0x17c: (0, 0, True), 0x180: (0, 0, True)}))
    eng = _rnd(c, 0x1b00)
    e.w32(eng + 0x9b, db)
    x = _rnd(c, 0x20)
    e.w32(x + 0x18, _obj(c, 0x10, _vt(c, 'rt', 4, {0xc: (1, 4, True)})))
    e.w32(eng + 0x1aa3, x)
    e.w32(0x70039c, eng)
    return [self_o]


def _g5707d0(c):
    e = c.emu
    _hook(c, 0x570cb0, 0, 0)
    _hook(c, 0x561be0, 0, 0, rv=c.rng.choice([0, 1, 0x100, 0xffffff01]))
    _hook(c, 0x5ae710, 1, 4)
    _hook(c, 0x59c620, 0, 0)
    o = _rnd(c, 0x100)
    e.w32(o + 0xcb, _vt(c, 'cb', 8, {0x14: (0, 0, True)}) if c.rng.random() < 0.5 else e.fake_vtable('cb0', 8, {0x14: lambda e, r: (e.calllog.append(('cb', e.reg('ecx'))), e.ret(eax=0))}))
    e.w32(o, _vt(c, 'own', 0xc0, {0x2f8: (1, 4, True)}))

    def s84(e, r):
        e.calllog.append(('s84', e.reg('ecx')))
        e.ret(eax=o)
    self_o = _obj(c, 0x200, e.fake_vtable('menu', 0x40, {0x84: s84, 0xd0: lambda e, r: (e.calllog.append(('d0', e.reg('ecx'), e.arg32(0))), e.ret(eax=0, argbytes=4))}))
    prof = _rnd(c, 0x80)
    name = c.rng.choice([b'C01A\0', b'C01A\0', b'C01B\0', b'C0\0', b'\0', b'C01AX\0', b'C06A\0'])
    e.wbytes(prof + 0x48, name)
    e.w32(self_o + 0x94, prof)
    return [self_o]


def _g4b7190(c):
    e = c.emu
    self_o = _rnd(c, 0x230)
    e.w8(self_o + 0x223, c.rng.choice([0, 1, 0x80]))
    ref = c.rng.getrandbits(32)

    def s88(e, r):
        e.calllog.append(('find', e.reg('ecx'), e.arg32(0), e.r32(e.arg32(1))))
        if c.rng.random() < 0.8:
            e.w32(e.arg32(1), ref)
        e.ret(eax=c.rng.getrandbits(32), argbytes=8)
    o = _obj(c, 0x10, e.fake_vtable('nm', 0x30, {0x88: s88}))
    g = 0 if c.rng.random() < 0.3 else _obj(c, 0x10, _vt(c, 'g', 0x50, {0x130: (3, 12, True)}))
    db = _obj(c, 0x10, e.fake_vtable('db', 0x50, {
        0x138: lambda e, r: (e.calllog.append(('s138', e.reg('ecx'))), e.ret(eax=o)),
        0x58: lambda e, r: (e.calllog.append(('ptr', e.reg('ecx'), e.arg32(0))), e.ret(eax=g, argbytes=4)),
        0x114: lambda e, r: (e.calllog.append(('reg', e.reg('ecx')) + tuple(e.arg32(k) for k in range(4))), e.ret(eax=c.rng.getrandbits(32), argbytes=16))}))
    eng = _rnd(c, 0x100)
    e.w32(eng + 0x9b, db)
    e.w32(0x70039c, eng)
    return [self_o]


N = 'fresh 17 batch 11'
S(0x621c10, 'big2_isPublicId (expat, UTF-16BE)', 'cdecl', None, ret='eax', gen=_g621c10, note=N + '; unicode_byte_type 0x62c640 native in half the cases, stubbed in the rest')
S(0x405710, 'GUESS FUN_405710 (matrix info init)', 'cdecl', None, ret='eax', gen=_g405710, note=N + '; 0x4050f0 / 0x405460 hooked')
S(0x4834d0, 'GUESS FUN_4834d0 (SetPosition from "x,y,z")', 'thiscall', None, ret=None, gen=_g4834d0, note=N + '; sscanf 0x42ab0d hooked; /GS not reproduced')
S(0x49a6d0, 'ZLoadGame::GetRefTabRaw(LINKREFTAB*)', 'thiscall', None, ret='eax', gen=_g49a6d0, note=N)
S(0x5707d0, 'CSewerMenu::EnterRebelBase()', 'thiscall', None, ret=None, gen=_g5707d0, note=N + '; NextLevel / AutoSaveEnabled / SaveRaw / SceneChange hooked')
S(0x4b7190, 'CCutSequenceSoundStartStop::RemoveText()', 'thiscall', None, ret=None, gen=_g4b7190, note=N)
