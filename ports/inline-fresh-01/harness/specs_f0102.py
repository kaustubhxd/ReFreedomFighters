"""specs_f0102.py - fresh-01 batch 2 (docs/20-fresh-01.md)."""
from pilot import S
from helpers01 import rnd, hk, obj


def _zone(c):
    hk(c, 0x610100, 'base CopyEventDataBlock', 1)
    hk(c, 0x4e5e60, 'DBREAD::uint', 0, eax=lambda e: 0x0db00000 ^ e.reg('ecx'))
    return [rnd(c, 0x200), c.rng.getrandbits(32)]


def _sdd(c):
    hk(c, 0x4cd050, '~STATICREFTAB', 0)
    hk(c, 0x634273, 'delete', 2, regs=(), pop=False)
    return [rnd(c, 0x40), c.rng.getrandbits(32)]


def _f54c(c):
    o = rnd(c, 0x80)
    if c.rng.random() < 0.7:
        c.emu.w32(o + 0x50, obj(c, 0x20, 'tgt', 0x10, {0x1c: lambda e, a: (0x77665500 | (a[0] & 0xff), None)}, {0x1c: 1}))
    else:
        c.emu.w32(o + 0x50, 0)
    return [o, c.rng.getrandbits(32)]


def _save(c):
    o = rnd(c, 0x100)
    c.emu.w32(o + 0xbd, obj(c, 0x20, 'state', 0x20, {0x64: lambda e, a: (0x1111, None)}))
    sv = obj(c, 0x20, 'save', 0x20, {0x78: lambda e, a: (0x2222, None)}, {0x78: 1})
    return [o, sv]


def _text(c):
    hk(c, 0x42ac56, 'strfmt', 3, regs=(), pop=False)
    return [obj(c, 0x1100, 'win', 0x10, {0x1c: lambda e, a: (0x31337, None)}), c.rng.getrandbits(32)]


def _copymode(c):
    bufs = [rnd(c, 0x40), rnd(c, 0x40)]
    return [obj(c, 0x20, 'prims', 0x8, {0xc: lambda e, a: (bufs[a[0] & 1], None)}, {0xc: 1}),
            c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _filetime(c):
    def s20(e, r):
        e.calllog.append(('slot20', e.reg('ecx'), e.arg32(0), e.arg32(2)))
        ok = e.arg32(0) & 3
        if ok:
            e.w32(e.arg32(1), e.arg32(0) ^ 0xfeedbeef)
            e.w32(e.arg32(1) + 4, 0x01d00000 | (e.arg32(2) & 0xffff))
        e.ret(eax=0x12345600 | ok, argbytes=12)
    o = rnd(c, 0x40)
    c.emu.w32(o, c.emu.fake_vtable('file', 0x10, {0x20: s20}))
    return [o, c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _load2(c):
    hk(c, 0x644820, 'ZRagdollContainer::Load2', 0)
    eng = rnd(c, 0x2000)
    c.emu.w32(0x70039c, eng)
    c.emu.w32(eng + 0x190f, obj(c, 0x20, 'scene', 0x70, {0x1b0: lambda e, a: (0xabcd0000 ^ a[0], None)}, {0x1b0: 1}))
    ld = obj(c, 0x20, 'load', 0x10, {}, {0xc: 1})
    return [rnd(c, 0x80), ld]


def _showmode(c):
    flags = c.rng.getrandbits(32)
    show = c.rng.getrandbits(16)

    def gsi(e, r):
        p = e.arg32(0)
        e.calllog.append(('GetStartupInfoW', bytes(e.rbytes(p, 0x44)).hex()))
        e.w32(p + 0x2c, flags)
        e.w32(p + 0x30, show | (c.rng.getrandbits(16) << 16))
        e.ret(argbytes=4)
    c.emu.stub_import('GetStartupInfoW', gsi)

    def ms(e, r):
        d, v, n = e.arg32(0), e.arg32(1), e.arg32(2)
        e.calllog.append(('memset', v, n))
        e.wbytes(d, bytes([v & 0xff]) * n)
        e.ret(eax=d)
    c.emu.stub_import('VCRUNTIME140.dll!memset', ms)
    return []


def _ring(c):
    o = rnd(c, 0x800)
    c.emu.w32(o + 0x414, c.rng.choice([0, 1, 0x7e, 0x7f, c.rng.randint(-0x80, 0x7f)]) & 0xffffffff)
    return [o, c.rng.getrandbits(32)]


def _sload(c):
    return [rnd(c, 0x80), obj(c, 0x20, 'load', 0x20, {}, {0x40: 1, 0x44: 1, 0x50: 1})]


def _dump(c):
    def s2c(e, r):
        e.calllog.append(('log', e.arg32(0), e.arg32(1), e.arg32(2)))
        e.ret(argbytes=0)
    o = rnd(c, 0x20)
    c.emu.w32(o, c.emu.fake_vtable('logger', 0x10, {0x2c: s2c}))
    c.emu.w32(0x700390, obj(c, 0x20, 'mgr', 0x10, {0x20: lambda e, a: (o, None)}, {0x20: 2}))

    def hnd(e, r):
        e.calllog.append(('handler',))
        e.ret()
    c.emu.w32(0x7003b0, c.emu.stub_fn('handler', hnd))
    return [c.rng.getrandbits(32)]


S(0x57ad10, 'ZFFSetStartZone::CopyEventDataBlock', 'thiscall', None, ret=None, gen=_zone)
S(0x4cd390, 'STATICREFTAB scalar deleting destructor', 'thiscall', None, ret='eax', gen=_sdd)
S(0x54c2d0, 'forward 0x54c2d0 (slot 0x1c of +0x50)', 'thiscall', None, ret='al', gen=_f54c)
S(0x650cd0, 'ZRenderGC::Save', 'thiscall', None, ret='al', gen=_save)
S(0x4d42d0, 'set text 0x4d42d0', 'thiscall', None, ret='eax', gen=_text)
S(0x656e50, 'ZPrimControlGC::CopyPrimDrawMode', 'thiscall', None, ret=None, gen=_copymode)
S(0x427210, 'ZSysFileGC::GetFileTime', 'thiscall', None, ret='eax:edx', gen=_filetime)
S(0x64ff10, 'ZRenderBaseDll::Load2', 'thiscall', None, ret='eax', gen=_load2)
S(0x634994, '__scrt_get_show_window_mode', 'cdecl', None, ret='eax', gen=_showmode)
S(0x65c990, 'ring push 0x65c990', 'thiscall', None, ret=None, gen=_ring)
S(0x4bb2d0, 'ZSoundNotify::Load', 'thiscall', None, ret='al', gen=_sload)
S(0x5f17d0, 'ZScriptDll::DumpCurrentScriptCallStack', 'stdcall', None, ret=None, gen=_dump)
