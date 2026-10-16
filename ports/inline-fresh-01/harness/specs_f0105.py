"""specs_f0105.py - fresh-01 batch 5 (docs/20-fresh-01.md)."""
from pilot import S
from helpers01 import rnd, hk, obj


def _logmgr(c, n=3):
    def s2c(e, r):
        e.calllog.append(('log',) + tuple(e.arg32(k) for k in range(n)))
        e.ret(eax=0x10910000, argbytes=0)
    o = rnd(c, 0x20)
    c.emu.w32(o, c.emu.fake_vtable('logger', 0x10, {0x2c: s2c}))
    c.emu.w32(0x700390, obj(c, 0x20, 'mgr', 0x10, {0x20: lambda e, a: (o, None)}, {0x20: 2}))


def _handler(c):
    def hnd(e, r):
        e.calllog.append(('handler',))
        e.ret(eax=0xbad)
    c.emu.w32(0x7003b0, c.emu.stub_fn('handler', hnd))


def _engine(c, n=0x2000):
    eng = rnd(c, n)
    c.emu.w32(0x70039c, eng)
    return eng


def _dinput(c):
    hr = c.rng.choice([0, 1, 0x80000000, 0x80070057, c.rng.getrandbits(32)])

    def s10(e, r):
        e.calllog.append(('SetProperty', tuple(e.arg32(k) for k in range(7))))
        e.ret(eax=hr, argbytes=28)
    o = rnd(c, 0x80)
    if c.rng.random() < 0.8:
        d = rnd(c, 0x20)
        c.emu.w32(d, c.emu.fake_vtable('di', 0x10, {0x10: s10}))
        c.emu.w32(o + 4, d)
    else:
        c.emu.w32(o + 4, 0)
    _logmgr(c, 2)
    return [o]


def _inflate(c):
    hk(c, 0x6322e0, 'inflate_blocks_reset', 3, regs=(), pop=False)
    k = c.rng.random()
    if k < 0.1:
        return [0]
    s = rnd(c, 0x40)
    st = rnd(c, 0x40)
    if c.rng.random() < 0.5:
        c.emu.w32(st + 0xc, 0)
    c.emu.w32(s + 0x1c, 0 if k < 0.2 else st)
    return [s]


def _key(c):
    ctl = obj(c, 0x20, 'ctl', 0x100, {})
    sel = c.rng.random() < 0.7
    impl = {0x318: lambda e, a: ((0x3180 + a[0]) if sel else 0, None), 0x2c4: lambda e, a: (ctl, None)}
    o = obj(c, 0x40, 'self', 0xd0, impl, {0x318: 1})
    c.emu.w32(ctl, c.emu.logging_vtable('ctl', 0x100, {}, {0x2ec: 1}))
    return [o, c.rng.choice([0x100, 0x101, 0x102, 0x103, 0xff, 0x104, 0, c.rng.getrandbits(32)])]


def _defrag(c):
    n = c.rng.randint(0, 4)
    blocks = [rnd(c, 0x20) for _ in range(n)]
    for i, b in enumerate(blocks):
        c.emu.w32(b + 8, blocks[(i + 1) % n] if (i + 1 < n or c.rng.random() < 0.6) else 0)
    o = rnd(c, 0x20)
    c.emu.w32(o + 8, blocks[c.rng.randint(0, n - 1)] if n else 0)
    c.emu.w32(o + 4, obj(c, 0x20, 'res', 0x10, {0x10: lambda e, a: (0x1234500 | (a[0] >> 4 & 0xff), None)}, {0x10: 1}))
    _logmgr(c)
    return [o]


def _command(c):
    eng = _engine(c, 0x200)
    mid = c.rng.getrandbits(16)
    c.emu.w32(eng + 0x9b, obj(c, 0x20, 'render', 0x50, {0x114: lambda e, a: (0xabcd0000 | mid, None)}, {0x114: 4}))
    hk(c, 0x561cb0, 'CBaseWindow::Command', 2, eax=0xc0de)
    data = 0 if c.rng.random() < 0.2 else rnd(c, 8)
    msg = c.rng.choice([mid, mid | 0x10000, c.rng.getrandbits(32)])
    return [rnd(c, 0xd00), msg, data]


def _fdiv(c):
    o = rnd(c, 0x10)
    c.emu.wf32(o, c.fv())
    c.emu.w8(o + 4, c.rng.choice([2, 2, 2, 0, 1, 3, c.rng.getrandbits(8)]))
    a = rnd(c, 4)
    c.emu.wf32(a, c.fv())
    _logmgr(c)
    _handler(c)
    return [o, a]


def _check(c):
    eng = _engine(c, 0xa00)
    k = c.rng.random()
    o = obj(c, 0x20, 'o', 0x10, {0xc: lambda e, a: (0x100 | int(k < 0.2), None)})
    c.emu.w32(eng, c.emu.logging_vtable('engine', 0x70, {0x1b0: lambda e, a: ((o if k < 0.5 else 0), None)}))
    for off in (0x9c7, 0x9c3):
        c.emu.wf32(eng + off, c.rng.choice([0.0, -0.0, 1.0, float('nan'), c.fv()]))
    s = rnd(c, 0x80)
    if c.rng.random() < 0.3:
        c.emu.w32(s + 0x74, 0)
    return [s]


def _load(c):
    hk(c, 0x42d730, 'ZSysInterface::Load', 1)
    t = c.rng.choice([0, 1, -1, 123456789, -0x80000000, c.rng.getrandbits(32)]) & 0xffffffff

    def ck(e, r):
        e.calllog.append(('clock',))
        e.ret(eax=t)
    c.emu.stub_import('clock', ck)
    ld = obj(c, 0x20, 'load', 0x20, {}, {0x54: 1, 0x5c: 1})
    s = obj(c, 0x2400, 'sys', 0x60, {0x170: lambda e, a: (0x1700, None)})
    return [s, ld]


def _spot(c):
    eng = _engine(c, 0x1b00)
    lt = rnd(c, 0x40)
    blob = bytes(c.rng.getrandbits(8) for _ in range(0x38))

    def s84(e, r):
        e.calllog.append(('GetLight', e.reg('ecx'), e.arg32(0)))
        e.wbytes(e.arg32(1), blob)
        e.ret(argbytes=8)

    def sa0(e, r):
        e.calllog.append(('SetLight', e.reg('ecx'), e.arg32(0), e.rbytes(e.arg32(1), 0x38).hex()))
        e.ret(argbytes=8)
    dev = rnd(c, 0x20)
    c.emu.w32(dev, c.emu.fake_vtable('dev', 0x30, {0x84: s84, 0xa0: sa0}))
    h = rnd(c, 0x40)
    c.emu.w32(h + 0x18, dev)
    c.emu.w32(eng + 0x1aa3, h)
    s = obj(c, 0x20, 'spot', 0x90, {})
    c.emu.w32(s + 8, lt)
    return [s, c.rng.getrandbits(32)]


S(0x54f250, 'DirectInput setup 0x54f250', 'thiscall', None, ret=None, gen=_dinput)
S(0x62fad0, 'zlib inflateReset', 'stdcall', None, ret='eax', gen=_inflate)
S(0x4fa390, 'ZCONTROL::OnKeyPress', 'thiscall', None, ret='al', gen=_key)
S(0x64ab50, 'ZDrawArray<ZDrawResource>::Defracment', 'thiscall', None, ret=None, gen=_defrag)
S(0x57bc10, 'ZFFLoadError::Command', 'thiscall', None, ret='eax', gen=_command)
S(0x5f4110, 'script float div 0x5f4110', 'thiscall', None, ret='eax', gen=_fdiv)
S(0x6511d0, 'check 0x6511d0', 'thiscall', None, ret='al', gen=_check)
S(0x421810, 'ZSysInterfaceGC::Load', 'thiscall', None, ret='eax', gen=_load)
S(0x4496d0, 'ZSPOTLIGHT::SetDiffuseColor', 'thiscall', None, ret=None, gen=_spot)
