"""specs_f0808.py - fresh slice 17, batch 8."""
from pilot import S
from specs_f0101 import _rnd, _vt, _hook, _obj
from specs_f0202 import _assert_hook, _logmgr


def _g426f50(c):
    e = c.emu
    raw = c.rng.choice([0, 1, 0x100, 0x101])
    h = c.rng.getrandbits(32)
    arc = 0 if c.rng.random() < 0.3 else _obj(c, 0x10, e.fake_vtable('arc', 8, {0x14: (lambda e, r: (e.calllog.append(('has', e.reg('ecx'), e.arg32(0))), e.ret(eax=c.rng.choice([0, 1, 0x100]), argbytes=4)))}))
    fsys = _obj(c, 0x10, e.fake_vtable('fs', 0x50, {
        0x130: lambda e, r: (e.calllog.append(('hash', e.reg('ecx'), e.arg32(0))), e.ret(eax=h, argbytes=4)),
        0x70: lambda e, r: (e.calllog.append(('arc', e.reg('ecx'), e.arg32(0))), e.ret(eax=arc, argbytes=4))}))
    ff = c.rng.choice([0xffffffff, 0x1234, 0])
    e.stub_import('FindFirstFileA', lambda e, r: (e.calllog.append(('FindFirstFileA', e.arg32(0))), e.wbytes(e.arg32(1), b'\x55' * 8), e.ret(eax=ff, argbytes=8)))
    e.stub_import('FindClose', lambda e, r: (e.calllog.append(('FindClose', e.arg32(0))), e.ret(eax=1, argbytes=4)))
    return [fsys, _rnd(c, 8), raw]


def _g638e10(c):
    e = c.emu
    w, h = c.rng.randint(-1, 6), c.rng.randint(-1, 5)
    pitch_src = c.rng.randint(max(w, 1), 12)
    x, y = c.rng.randint(0, 3), c.rng.randint(0, 3)
    data = _rnd(c, pitch_src * (y + max(h, 0) + 1) + x + 16)
    info = _rnd(c, 0x20)
    e.w32(info + 4, pitch_src)
    e.w32(info + 0x10, data)
    self_o = _obj(c, 0x40, e.fake_vtable('tex', 0x20, {0x38: (lambda e, r: (e.calllog.append(('info', e.reg('ecx'), e.arg32(0))), e.ret(eax=info, argbytes=4)))}))
    e.w32(self_o + 0x2d, _rnd(c, 0x400))
    e.w32(self_o + 0x36, _rnd(c, pitch_src * (y + max(h, 0) + 1) + x + 16))
    dpitch = c.rng.choice([4 * max(w, 0), 4 * max(w, 0) + 8, 32])
    dst = _rnd(c, dpitch * (max(h, 0) + 1) + 64)
    return [self_o, dst, x, y, w & 0xffffffff, h & 0xffffffff, dpitch, c.rng.getrandbits(32)]


def _gsize(c):
    e = c.emu
    nm = e.cstr('cache.bin')

    def calc(e, r):
        out, tag = e.arg32(0), e.arg32(1)
        e.calllog.append(('calc', e.reg('ecx'), tag))
        e.w32(out, nm)
        e.w32(out + 4, 0x1111)
        e.ret(eax=out, argbytes=8)
    e.hook(0x48c4b0, calc)
    e.hook(0x4cbec0, lambda e, r: (e.calllog.append(('dtor', e.r32(e.reg('ecx')), e.r32(e.reg('ecx') + 4))), e.ret(eax=c.rng.getrandbits(32))))
    e.w32(0x700394, _obj(c, 0x10, _vt(c, 'fs', 0x20, {0x30: (2, 8, True)})))
    return [_rnd(c, 0x20)]


def _g5f5250(c):
    e = c.emu
    _assert_hook(c)
    _logmgr(c)
    self_o = _rnd(c, 0x10)
    cnt = c.rng.randint(1, 8)
    arr = _rnd(c, 8 * (cnt + 1))
    for i in range(cnt + 1):
        e.w8(arr + 8 * i + 4, c.rng.choice([0, 1, 1, 2, 4, 0xff]))
    e.w32(self_o, arr)
    e.w32(self_o + 4, cnt)
    e.w32(self_o + 8, c.rng.randint(0, cnt))
    _hook(c, 0x42ab62, 1, 0, lecx=False)
    return [self_o, _rnd(c, 4)]


N = 'fresh 17 batch 8'
S(0x426f50, 'ZSysFileGC::GetSize(const char*, bool)', 'thiscall', None, ret='al', gen=_g426f50, note=N + '; FindFirstFileA/FindClose stubbed; /GS check not reproduced')
S(0x638e10, 'GUESS FUN_638e10 (palettised texture unpack)', 'thiscall', None, ret=None, gen=_g638e10, note=N)
S(0x490090, 'ZEngineDataBase::GetAnimsSize()', 'thiscall', None, ret='eax', gen=_gsize, note=N + '; CalcCacheFileName and ~MYSTR hooked; MYSTR logged by content')
S(0x491210, 'ZEngineDataBase::GetTextureSize()', 'thiscall', None, ret='eax', gen=_gsize, note=N + '; same shape')
S(0x5f5250, 'GUESS FUN_5f5250 (slot pool set, kind 1)', 'thiscall', None, ret='eax', gen=_g5f5250, note=N + '; printf hooked; assert hook set')
