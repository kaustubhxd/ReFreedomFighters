"""specs_f0606.py - fresh slice 17, batch 6."""
import struct
from pilot import S
from specs_f0101 import _rnd, _vt, _hook, _obj


def _factory(c):
    e = c.emu
    blk = 0 if c.rng.random() < 0.25 else _rnd(c, 0x60)
    al = _obj(c, 0x10, e.fake_vtable('alloc', 0x20, {0x44: (lambda e, r: (e.calllog.append(('alloc', e.reg('ecx'), e.arg32(0))), e.ret(eax=blk, argbytes=4)))}))
    db = _rnd(c, 0x20)
    e.w32(db + 8, al)
    eng = _rnd(c, 0x100)
    e.w32(eng + 0x9b, db)
    e.w32(0x70039c, eng)

    def ctor(e, r):
        p = e.reg('ecx')
        e.calllog.append(('ctor', p))
        e.w32(p, 0x11111111)                       # the base ctor's own vtable, overwritten afterwards
        e.w32(p + 4, c.rng.getrandbits(32))        # flags the |= 0x20 must keep
        e.ret(eax=c.rng.getrandbits(32))
    e.hook(0x469870, ctor)
    return [c.rng.getrandbits(32)]


def _g456ed0(c):
    e = c.emu
    self_o = _rnd(c, 0x1d + 8 * 0x101 + 8)
    n = c.rng.choice([0, 1, 2, 3, 4, 5, 7, 8, 9, 0x100, c.rng.randint(0, 0x101)])
    for i in range(0x101):
        if i < n:
            if e.r32(self_o + 0x1d + 8 * i) == 0:
                e.w32(self_o + 0x1d + 8 * i, 1)
        elif i == n:
            e.w32(self_o + 0x1d + 8 * i, 0)
    _hook(c, 0x45f960, 1, 4)
    sg = _obj(c, 0x10, _vt(c, 'sg', 0x20, {0x3c: (1, 4, True)}))
    return [self_o, sg]


def _g54ea90(c):
    e = c.emu
    self_o = _rnd(c, 0x100)
    for off in (4, 8):
        if c.rng.random() < 0.3:
            e.w32(self_o + off, 0)
        else:
            e.w32(self_o + off, _obj(c, 0x10, _vt(c, 'com%x' % off, 4, {8: (1, 4, False)})))
    _hook(c, 0x634273, 2, 0, lecx=False)
    return [self_o, c.rng.getrandbits(32)]


def _g4d4c90(c):
    e = c.emu
    s = ''.join(chr(c.rng.randint(0x21, 0x7e)) for _ in range(c.rng.choice([0, 1, 5, 17, 40])))
    name = e.cstr(s)

    def new(e, r):
        n = e.arg32(0)
        p = e.alloc(n + 8, 4, 0xab)
        e.calllog.append(('new', n))
        e.ret(eax=p)
    e.hook(0x41e290, new)
    return [_rnd(c, 0x20), c.rng.getrandbits(32), name]


def _g424750(c):
    e = c.emu
    self_o = _rnd(c, 0x1920)
    eng = _rnd(c, 0xa00)
    k = struct.unpack('<f', e.rbytes(0x6785d0, 4))[0]
    v = c.rng.choice([k, k, 0.0, 1.0, float('nan'), -k])
    e.wf32(eng + 0x9c7, v)
    e.w32(0x70039c, eng)
    ls = [_rnd(c, 0x10) for _ in range(c.rng.randint(0, 3))]
    for i, l in enumerate(ls):
        e.w32(l + 8, ls[i + 1] if i + 1 < len(ls) else 0)

    def plot(e, r):
        o, b = e.arg32(0), e.arg32(1)
        e.calllog.append(('plot', o, e.rbytes(b, 12)))          # buffer is on the stack: its text is logged, not its address
        e.ret(eax=c.rng.getrandbits(32))
    lvt = e.fake_vtable('lst', 0x50, {0x128: plot})
    for l in ls:
        e.w32(l, lvt)
    e.w32(self_o + 0x190f, ls[0] if ls else 0)

    def vfmt(e, r):
        b, f, va = e.arg32(0), e.arg32(1), e.arg32(2)
        e.calllog.append(('fmt', e.reg('ecx'), f, e.r32(va), e.r32(va + 4)))
        e.wbytes(b, bytes(c.rng.getrandbits(8) | 1 for _ in range(11)) + b'\0')
        e.ret(eax=11, argbytes=12)
    e.w32(0x700390, _obj(c, 0x10, e.fake_vtable('log', 0x20, {0x4c: vfmt})))
    return [self_o, _rnd(c, 8), c.rng.getrandbits(32), c.rng.getrandbits(32)]


N = 'fresh 17 batch 6'
for a, vt in ((0x4a8190, 0x6901b0), (0x4b2a50, 0x691050), (0x4b2cd0, 0x691844), (0x4c3490, 0x693d70), (0x4cadd0, 0x695388)):
    S(a, 'GUESS FUN_%x (factory, base ctor 0x469870, vtable 0x%x)' % (a, vt), 'fastcall', None, ret='eax', gen=_factory,
      note=N + '; allocator slot +0x44 with ECX; base ctor hooked; SEH frame not reproduced')
S(0x456ed0, 'ZParticleController::Save(ZSaveGame*)', 'thiscall', None, ret='al', gen=_g456ed0, note=N + '; ZGEOM::Save hooked')
S(0x54ea90, 'GUESS FUN_54ea90 (scalar deleting dtor, two COM members)', 'thiscall', None, ret='eax', gen=_g54ea90, note=N + '; __builtin_delete hooked; SEH frame not reproduced')
S(0x4d4c90, 'GUESS FUN_4d4c90 (named entry ctor)', 'thiscall', None, ret='eax', gen=_g4d4c90, note=N + '; __builtin_new hooked; SEH frame not reproduced')
S(0x424750, 'ZSysInterfaceGC::UPlotFNxt(const char*, ...)', 'cdecl', None, ret=None, gen=_g424750, note=N + '; formatter and listeners stubbed; stack buffer logged by content; /GS check not reproduced')
