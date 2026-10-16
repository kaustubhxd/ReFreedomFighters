"""specs_f0101.py - fresh-01 batch 1 (docs/20-fresh-01.md). Exe callees are replaced by logging stubs (helpers01.hk),
so the call order, registers and stack words of each call are compared; vtable calls go to logging vtables."""
from pilot import S
from helpers01 import rnd, hk, obj


def _none(c):
    return []


def _o(c):
    return [rnd(c, 0x2000)]


def _recycle(c):
    o = obj(c, 0x40, 'proc', 0x20, {0x50: lambda e, a: (0x5e5e0000 + (a[0] & 0xff), None)}, {0x50: 1})
    c.emu.w32(0x724270, o)
    return [rnd(c, 0x40), c.rng.getrandbits(32)]


def _produce(c):
    hk(c, 0x6054b0, 'factory', 0, eax=0x600df00d, regs=('ecx', 'edx'))
    return [c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _loaderr(c):
    hk(c, 0x5630f0, 'OnWindowOpen2', 0)
    hk(c, 0x565100, 'SetStatus', 1)
    return [rnd(c, 0x1000)]


def _light(c):
    return [rnd(c, 0x40), rnd(c, 0x40)]


def _savefloat(c):
    o = rnd(c, 0x40)
    s = obj(c, 0x40, 'stream', 0x20, {0x4c: lambda e, a: (0x5a5a0000 ^ a[0], None)}, {0x4c: 1})
    c.emu.w32(o + 0x15, s)
    return [o, c.rng.getrandbits(32)]


def _cursor(c):
    def sc(e, r):
        e.calllog.append(('SetCursor', (), (e.arg32(0),)))
        e.ret(eax=0x1234, argbytes=4)
    c.emu.stub_import('SetCursor', sc)
    return [obj(c, 0x1400, 'render', 0x30, {}, {0x88: 1})]


def _alloc(c):
    hk(c, 0x64f760, 'ZRender::AllocateDrawBuffers', 0)
    hk(c, 0x41e290, 'new', 1, eax=0x7ab00000, regs=(), pop=False)
    return [rnd(c, 0x1400)]


def _chain(c):
    n = c.rng.randint(0, 4)
    nxt = 0
    for _ in range(n + 1):
        o = rnd(c, 0xa0)
        c.emu.w32(o + 0x9c, nxt)
        nxt = o
    return [nxt]


S(0x60db10, 'ZRenderGC::GetRenderName', 'cdecl', None, ret='eax', gen=_none)
S(0x5f5510, 'Process_t::recycle', 'thiscall', None, ret='eax', gen=_recycle)
S(0x605b90, 'serial size 0x605b90', 'thiscall', None, ret='eax', gen=_o)
S(0x605550, 'OpaqueStringFactory_t::produceOpaqueObjectFromSerial', 'thiscall', None, ret='eax', gen=_produce)
S(0x57bd50, 'ZFFLoadError::OnWindowOpen2', 'thiscall', None, ret=None, gen=_loaderr)
S(0x656950, 'ZPrimControlBase::ModifyLight', 'stdcall', None, ret=None, gen=_light)
S(0x5f3210, 'SaveSerialInfo_t::savefloat', 'thiscall', None, ret='eax', gen=_savefloat)
S(0x654c90, 'render 0x654c90 (SetCursor)', 'thiscall', None, ret=None, gen=_cursor)
S(0x658110, 'ZRenderGC::AllocateDrawBuffers', 'thiscall', None, ret=None, gen=_alloc)
S(0x5ffb50, 'VMImageInfo_t::getDataSegSize', 'thiscall', None, ret='eax', gen=_chain)
