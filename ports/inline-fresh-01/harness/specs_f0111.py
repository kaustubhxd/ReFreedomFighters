"""specs_f0111.py - fresh-01 batch 11 (docs/20-fresh-01.md)."""
from pilot import S
from helpers01 import rnd, hk, obj


def _engine(c, n=0x200):
    eng = rnd(c, n)
    c.emu.w32(0x70039c, eng)
    return eng


def _render(c, impl=None, argw=None, n=0x20):
    eng = _engine(c)
    r = obj(c, n, 'render', 0x60, impl or {}, argw or {})
    c.emu.w32(eng + 0x9b, r)
    return r


def _handler(c):
    def hnd(e, r):
        e.calllog.append(('handler',))
        e.ret(eax=0xbad)
    c.emu.w32(0x7003b0, c.emu.stub_fn('handler', hnd))


def _save(c):
    ok = c.rng.random() < 0.8
    hk(c, 0x4fa630, 'ZCONTROL::Save', 1, eax=0x100 | int(ok))
    _render(c, {0x4c: lambda e, a: (a[0] ^ 0x4c00, None)}, {0x4c: 1})
    sv = obj(c, 0x20, 'save', 0x20, {}, {0x3c: 1, 0x10: 2, 0x4c: 1, 0x60: 1})
    return [rnd(c, 0xb0), sv]


def _ctor(c):
    mid = c.rng.getrandbits(32)
    _render(c, {0x114: lambda e, a: (mid, None)}, {0x114: 4})
    hk(c, 0x469870, 'base', 0)
    return [0 if c.rng.random() < 0.15 else rnd(c, 0x60)]


def _setstr(c):
    eng = _engine(c)
    r = rnd(c, 0xb00)
    c.emu.w32(eng + 0x9b, r)
    txt = bytes(c.rng.choice(b'abc %d') for _ in range(c.rng.randint(0, 20))) + b'\0'
    tp = rnd(c, len(txt) + 4)
    c.emu.wbytes(tp, txt)
    c.emu.w32(r + 0xae4, obj(c, 0x10, 'texts', 4, {0: lambda e, a: (tp, None)}, {0: 2}))

    def s198(e, r_):
        e.calllog.append(('sprintf', e.arg32(0), e.arg32(1), e.arg32(2), e.arg32(3)))
        e.ret()
    fo = rnd(c, 0x10)
    c.emu.w32(fo, c.emu.fake_vtable('fmt', 0x70, {0x198: s198}))
    c.emu.w32(eng, c.emu.logging_vtable('eng', 0x70, {0x190: lambda e, a: (fo, None)}))
    num = 0 if c.rng.random() < 0.5 else rnd(c, 4)
    return [c.rng.getrandbits(32), rnd(c, 0x20), 0 if c.rng.random() < 0.1 else c.rng.getrandbits(32), num,
            0 if c.rng.random() < 0.5 else c.rng.getrandbits(32)]


def _seq(c):
    hk(c, 0x61ba30, 'base', 1)
    hk(c, 0x4cbeb0, 'MYSTR()', 0)
    hk(c, 0x4cbe80, 'MYSTR(text)', 1)
    return [rnd(c, 0x250), c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _ctor2(c):
    p = 0 if c.rng.random() < 0.2 else rnd(c, 0x20)
    hk(c, 0x41e290, 'new', 1, eax=p, regs=(), pop=False)
    hk(c, 0x4ccc30, 'table ctor', 2, eax=lambda e: e.reg('ecx') + 3)
    return [rnd(c, 0x30), c.rng.getrandbits(32)]


def _dtor(c):
    _render(c, {}, {0x34: 1})
    hk(c, 0x4690b0, 'sized delete', 2, regs=(), pop=False)
    _handler(c)
    return [rnd(c, 0x60), c.rng.choice([0, 1, 4, 5, c.rng.getrandbits(32)])]


S(0x4f7410, 'ZScrollArea::Save', 'thiscall', None, ret='al', gen=_save)
S(0x4af390, 'constructor 0x4af390', 'thiscall', None, ret='eax', gen=_ctor)
S(0x565190, 'CFileWindow::SetStringInBuffer', 'thiscall', None, ret=None, gen=_setstr)
S(0x43b710, 'ZInputActionSequence ctor 0x43b710', 'thiscall', None, ret='eax', gen=_seq)
S(0x4e7dd0, 'constructor 0x4e7dd0', 'thiscall', None, ret='eax', gen=_ctor2)
S(0x57bad0, 'ZFFLoadError scalar deleting destructor', 'thiscall', None, ret='eax', gen=_dtor)
