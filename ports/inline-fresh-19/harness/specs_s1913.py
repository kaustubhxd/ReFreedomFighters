"""specs_s1913.py - fresh slice 19, batch1913 (src/batch1913.cpp). Exe callees hooked by address with logging handlers
(pop counts checked against each callee's ret N); stack objects logged by content, never by address; KERNEL32 imports
stubbed through the IAT; logger and assert hook from helpers22._log_world."""
from pilot import S, F
from helpers22 import _rnd, _pyvt, _hk, _log_world


def _r(c):
    return c.rng.getrandbits(32)


def _vh(c, name, nargs, eax=None, log_ecx=True):
    def h(em, r):
        em.calllog.append((name, 0, em.reg('ecx') if log_ecx else None, tuple(em.arg32(k) for k in range(nargs))))
        em.ret(eax=_r(c) if eax is None else (eax(em) if callable(eax) else eax), argbytes=4 * nargs)
    return h


def _db(c, slots, rmn=0x100):
    e = c.emu
    rm = _rnd(c, rmn)
    e.w32(0x70039c, rm)
    db = _rnd(c, 0x10)
    e.w32(rm + 0x9b, db)
    e.w32(db, _pyvt(c, slots))
    return rm


def _g_4f40b0(c):
    o = c.rng.choice([0, _rnd(c, 0xa0), _rnd(c, 0xa0)])
    _hk(c, 0x45c4f0, 'pool new', 2, eax=o, pop=0)
    _hk(c, 0x45c4b0, 'new', 1, eax=o, pop=0)
    _hk(c, 0x4ee240, 'base ctor', 3)
    return [_r(c), _r(c), _r(c), c.rng.choice([0, _r(c)])]


def _g_565df0(c):
    e = c.emu
    _db(c, {0x34: _vh(c, 'db.34', 1, eax=0)})
    _hk(c, 0x4690b0, 'sized delete', 2, pop=0)
    e.w32(0x7003b0, e.stub_fn('assert', lambda em, r: (em.calllog.append(('assert', 0, None, ())), em.ret(eax=0))))
    return [_rnd(c, 0x60), c.rng.choice([0, 1, 3, 4, 5, 7, _r(c)])]


def _g_5ec670(c):
    e = c.emu
    rng = c.rng
    n = rng.choice([0, 1, 2, 4])
    s = _rnd(c, 0xb0)
    e.w32(s + 0x3e, n)
    e.w32(s + 0x52, rng.choice([0, 1, 640, 0x80000000, 0xffffffff, _r(c)]))
    e.w32(s + 0x56, rng.choice([0, 2, 480, 0x80000001, _r(c)]))
    arr = _rnd(c, 4 * (n + 2))
    for k in range(n + 2):
        e.w32(arr + 4 * k, _rnd(c, 0x10))
    e.w32(s + 0x62, arr + 4)
    vt = _rnd(c, 0x28 * (n + 2))
    vb = _rnd(c, 8)
    e.w32(vb + 4, vt + 0x28)
    e.w32(s + 0x3a, vb)
    i = rng.choice([0xffffffff, 0xffffffff] + list(range(max(n, 1))))
    sc = rng.choice([0.0, 1.0, -1.0, 0.5, rng.uniform(-100, 100), rng.uniform(0, 1e-3)])
    return [s, F(sc), i]


def _g_428370(c):
    e = c.emu
    rng = c.rng
    n = rng.choice([0, 1, 0x100, 0x3c00000, 0x3c00001, 0x7800000, 0x8000000, 0xffffffff, _r(c)])
    fails = rng.choice([0, 0, 1, 2, 3, 99])
    cnt = [0]

    def wf(em, r):
        em.calllog.append(('WriteFile', 0, None, (em.arg32(0), em.arg32(1), em.arg32(2), em.arg32(4))))
        cnt[0] += 1
        em.ret(eax=0 if cnt[0] == fails else 1, argbytes=20)
    e.stub_import('WriteFile', wf)
    errs = [_r(c), _r(c)]

    def gle(em, r):
        em.calllog.append(('GetLastError', 0, None, ()))
        em.ret(eax=errs.pop(0) if errs else 7)
    e.stub_import('GetLastError', gle)
    msg = _rnd(c, 0x20)
    e.wbytes(msg, b'some error\0')

    def fm(em, r):
        em.calllog.append(('FormatMessageA', 0, None, tuple(em.arg32(k) for k in (0, 1, 2, 3, 5, 6))))
        em.w32(em.arg32(4), msg)
        em.ret(eax=10, argbytes=28)
    e.stub_import('FormatMessageA', fm)
    e.stub_import('LocalFree', lambda em, r: (em.calllog.append(('LocalFree', 0, None, (em.arg32(0),))),
                                              em.ret(eax=0, argbytes=4)))
    _log_world(c)
    return [_r(c), _r(c), n]


def _g_578c70(c):
    e = c.emu
    rng = c.rng
    s = _rnd(c, 0x1c0)
    for o in (0x1b4, 0x1b5, 0x1b6, 0x1b7):
        e.wbytes(s + o, bytes([rng.choice([0, 1, rng.getrandbits(8)])]))
    e.w32(s + 0x194, rng.choice([0, 1, 3, _r(c)]))
    e.w32(s, _pyvt(c, {0xd0: _vh(c, 'self.d0', 1, eax=0)}))
    for a, nm in ((0x579bd0, 'SetIV'), (0x579b20, 'SetIH'), (0x579a60, 'SetA')):
        _hk(c, a, nm, 1)

    def spf(em, r):
        em.calllog.append(('o.198', 0, None, (em.arg32(0), em.arg32(2), em.arg32(3))))
        em.wbytes(em.arg32(1), b'Rumble%d\0' % (em.arg32(3) & 0x7fffffff))
        em.ret(eax=0, argbytes=0)
    o = _rnd(c, 0x10)
    e.w32(o, _pyvt(c, {0x198: spf}))
    rm = _db(c, {0x134: None})
    o2 = _rnd(c, 0x10)

    def f68(em, r):
        em.calllog.append(('o2.68', 0, em.reg('ecx'), (em.rbytes(em.arg32(0), 0x20).split(b'\0')[0],
                                                       em.arg32(1) & 0xff, em.arg32(2))))
        em.ret(eax=0, argbytes=12)
    e.w32(o2, _pyvt(c, {0x68: f68}))
    db = c.emu.r32(rm + 0x9b)
    e.w32(db, _pyvt(c, {0x134: _vh(c, 'db.134', 0, eax=o2)}))
    e.w32(rm, _pyvt(c, {0x190: _vh(c, 'eng.190', 0, eax=o)}))
    return [s]


def _g_62d2b0(c):
    e = c.emu
    rng = c.rng
    st = _rnd(c, 0x10)
    e.w32(st + 0xc, rng.choice([0, 0, 1, _r(c)]))
    res = [rng.choice([0, 1, 0, _r(c)]), rng.choice([0, 1, 0])]

    def nm(em, r):
        em.calllog.append(('nameMatchesAscii', 0, None, tuple(em.arg32(k) for k in range(4))))
        em.ret(eax=res.pop(0) if res else 0)
    enc = _rnd(c, 0x40)
    e.w32(enc + 0x1c, e.stub_fn('nameMatchesAscii', nm))
    tok = rng.choice([0xf, 0x12, 0x12, 0x12, 0x17, 0x1c, 0x1c, 0, 1, 0x11, 0x13, 0x29, _r(c) & 0x3f])
    return [st, tok, _r(c), _r(c), enc]


def _g_553830(c):
    e = c.emu
    rng = c.rng
    g = rng.choice([0, _rnd(c, 0x60), _rnd(c, 0x60), _rnd(c, 0x60)])
    _db(c, {0x58: _vh(c, 'db.58', 1, eax=g)})
    if g:
        e.w32(g + 0x54, rng.choice([0, _rnd(c, 8)]))
        g2 = rng.choice([0, _rnd(c, 0x10)])
        if g2:
            e.w32(g2, _pyvt(c, {0x1e0: _vh(c, 'g2.1e0', 1, eax=rng.choice([0, 1, 0x100, _r(c)]))}))
        e.w32(g, _pyvt(c, {0x1e0: _vh(c, 'g.1e0', 1, eax=rng.choice([0, 1, 0x100, _r(c)])),
                           0x20: _vh(c, 'g.20', 0, eax=g2)}))
    els = [_rnd(c, 8), _rnd(c, 8)]
    _hk(c, 0x5003d0, 'elem', 1, eax=lambda em: els[0] if em.reg('ecx') == pa else els[1])
    _hk(c, 0x5002f0, 'seti', 1)
    _log_world(c)
    pr = _rnd(c, 0x10)
    pa = _rnd(c, 0x10)
    e.w32(pr + 4, pa)
    e.w32(pr + 8, _rnd(c, 0x10))
    return [_rnd(c, 0x10), pr]


def _g_4352f0(c):
    e = c.emu
    nm = bytes(c.rng.choice(b'abcXYZ019 ') for _ in range(c.rng.choice([0, 1, 7, 8, 30]))) + b'\0'

    def f6c(em, r):
        em.calllog.append(('io.6c', 0, em.reg('ecx'), (em.rbytes(em.arg32(0), 0x80), em.arg32(1), em.arg32(2))))
        em.wbytes(em.arg32(0), nm)
        em.ret(eax=0, argbytes=12)
    io = _rnd(c, 0x10)
    e.w32(io, _pyvt(c, {0x6c: f6c}))
    e.w32(0x7003ac, io)
    mark = _rnd(c, 8)

    def ctor(em, r):
        em.calllog.append(('MYSTR(const char*)', 0, None, (em.rbytes(em.arg32(0), 0x80),)))
        em.wbytes(em.reg('ecx'), em.rbytes(mark, 8))
        em.ret(eax=em.reg('ecx'), argbytes=4)
    e.hook(0x4cbe80, ctor)

    def assign(em, r):
        em.calllog.append(('MYSTR=', 0, em.reg('ecx'), (em.rbytes(em.arg32(0), 8),)))
        em.ret(eax=em.reg('ecx'), argbytes=4)
    e.hook(0x4cbee0, assign)

    def dtor(em, r):
        em.calllog.append(('~MYSTR', 0, None, (em.rbytes(em.reg('ecx'), 8),)))
        em.ret(eax=0, argbytes=0)
    e.hook(0x4cbec0, dtor)
    return [_rnd(c, 0xa0)]


def _g_4285f0(c):
    e = c.emu
    rng = c.rng
    rm = _rnd(c, 0xa00)
    e.w32(0x70039c, rm)
    com = rng.choice([0, _rnd(c, 0x10)])
    if com:
        e.w32(com, _pyvt(c, {8: _vh(c, 'com.Release', 1, eax=0, log_ecx=False),
                             0x10: _vh(c, 'com.EnumDevices', 5, eax=0, log_ecx=False)}))
    hr = rng.choice([0, 1, 0x80000000, 0x8007000e, _r(c)])

    def di(em, r):
        em.calllog.append(('DirectInput8Create', 0, None, tuple(em.arg32(k) for k in range(5))))
        em.w32(em.arg32(3), com)
        em.ret(eax=hr, argbytes=20)
    e.hook(0x61ba16, di)
    _hk(c, 0x435ae0, 'base ctor', 0)
    _hk(c, 0x428990, 'fn_428990', 0)
    _hk(c, 0x4293e0, 'InitDevices', 0)
    return [_rnd(c, 0x90)]


S(0x4f40b0, 'FUN_004f40b0 (factory)', 'fastcall', None, ret='eax', gen=_g_4f40b0, note='batch1913; SEH not ported')
S(0x565df0, 'CBriefing::`scalar deleting destructor', 'thiscall', None, ret='eax', gen=_g_565df0,
  note='batch1913; SEH not ported')
S(0x5ec670, 'CSprite3D::SetScale', 'thiscall', None, ret=None, gen=_g_5ec670, nan_heap=True, note='batch1913; void')
S(0x428370, 'ZSysFileWintel::WriteTo (GC map: ZSysFileGC::Exists)', 'stdcall', None, ret='al', gen=_g_428370,
  note='batch1913; KERNEL32 via IAT stubs')
S(0x578c70, 'ZControllerA::DiscardChanges', 'thiscall', None, ret=None, gen=_g_578c70,
  note='batch1913; void; cookie not ported; stack buffer by content')
S(0x62d2b0, 'element1 (expat xmlrole)', 'cdecl', None, ret='eax', gen=_g_62d2b0, note='batch1913')
S(0x553830, 'FUN_00553830 (GetActorTeam native)', 'thiscall', None, ret=None, gen=_g_553830,
  note='batch1913; void; 0x5003d0/0x5002f0 stack-word sharing')
S(0x4352f0, 'ZSysFile::SetSaveGameName', 'thiscall', None, ret=None, gen=_g_4352f0,
  note='batch1913; void; SEH and cookie not ported; MYSTR temp by content')
S(0x4285f0, 'FUN_004285f0 (ZSysInputWintel ctor)', 'thiscall', None, ret='eax', gen=_g_4285f0,
  note='batch1913; SEH not ported')
