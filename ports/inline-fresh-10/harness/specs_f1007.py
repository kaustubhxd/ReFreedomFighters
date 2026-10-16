"""specs_f1007.py - fresh-10 batch 7: allocate+init helpers, constructors, briefing talk, view removal (slice 10)."""
import os, sys, struct
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S, F
from h10 import L, obj, rbuf, patch, iat, log_obj


def R(c): return c.rng.getrandbits(32)
def fbits(c): return struct.unpack('<I', struct.pack('<f', c.fv()))[0]


def _alloc_init(init):
    def g(c):
        patch(c, 0x45c4f0, L('alloc2', 2, pop=0, ecx=False, ret=c.rng.choice([0, R(c)])))
        patch(c, 0x45c4b0, L('alloc1', 1, pop=0, ecx=False, ret=c.rng.choice([0, R(c)])))
        patch(c, init, L('init', 3, ret=R(c)))
        return [R(c), R(c), R(c), c.rng.choice([0, R(c)])]
    return g
S(0x4ee8a0, 'GUESS fastcall alloc 0x20 + 0x4ee2e0', 'fastcall', None, ret='eax', gen=_alloc_init(0x4ee2e0))
S(0x4f88a0, 'GUESS fastcall alloc 0x1df + 0x4f8630', 'fastcall', None, ret='eax', gen=_alloc_init(0x4f8630))
S(0x52a760, 'GUESS fastcall alloc 0x99 + ZPathfinder3 ctor', 'fastcall', None, ret='eax', gen=_alloc_init(0x52a370))


def g_444120(c):   # ZROOM::AddDynamicGeomToRoom(ZBaseGeom*)
    tab = obj(c, 'tab', {0x28: L('tab28', 1, ret=c.rng.choice([0, 1, R(c)])), 4: L('tab4', 1)}, size=0x20)
    patch(c, 0x41e290, L('new', 1, pop=0, ecx=False, ret=tab))
    patch(c, 0x4ccba0, L('REFTAB32', 0, retf=lambda e, a: e.reg('ecx')))
    o = rbuf(c, 0xb0); c.emu.w32(o + 0xa8, 0 if c.rng.random() < 0.4 else obj(c, 'tab0', {0x28: L('t28', 1, ret=c.rng.choice([0, R(c)])), 4: L('t4', 1)}, size=0x10))
    return [o, R(c)]
S(0x444120, 'ZROOM::AddDynamicGeomToRoom', 'thiscall', None, ret='al', gen=g_444120)


def g_5f29e0(c):   # ZScriptDll::ScheduleProcesses()
    patch(c, 0x5fd6f0, L('scheduleProcesses', 0)); patch(c, 0x4cc5f0, L('Length', 0, ret=c.rng.choice([0, 3])))
    d = obj(c, 'dbg', {0x184: L('print', 4, pop=0, ecx=False)}, size=0x10)
    c.emu.w32(0x70039c, obj(c, 'sys', {0x190: L('sys190', 0, ret=d)}, size=0x10))
    x = rbuf(c, 0xa0); c.emu.w32(x + 4, rbuf(c, 0x10)); c.emu.w32(x + 0x98, c.rng.randint(0, 6))
    o = obj(c, 'dll', {0x8c: L('dll8c', 1, ret=c.rng.randint(0, 7))}, size=0x20); c.emu.w32(o + 0xc, x)
    return [o]
S(0x5f29e0, 'ZScriptDll::ScheduleProcesses', 'thiscall', None, ret=None, gen=g_5f29e0)


def g_49d220(c):   # GUESS constructor (vtable 0x68ee80): two arrays of n and m dwords
    patch(c, 0x41e290, L('new', 1, pop=0, ecx=False, retf=lambda e, a: 0x30000000 ^ a[0]))
    c.emu.w32(0x70038c, 0 if c.rng.random() < 0.3 else obj(c, 'mem', {0x24: L('mem24', 2)}, size=0x10))
    big = lambda: c.rng.choice([c.rng.randint(0, 100), 0x40000000, 0x3fffffff, R(c)])
    return [rbuf(c, 0x30), big(), big(), R(c)]
S(0x49d220, 'GUESS ctor 0x68ee80 (two dword arrays)', 'thiscall', None, ret='eax', gen=g_49d220)


def g_63fce0(c):   # ZDrawBase::RemoveView(ZViewBase*)
    patch(c, 0x64b070, L('RemoveCameras', 0)); patch(c, 0x648280, L('End', 0))
    patch(c, 0x634273, L('delete', 2, pop=0, ecx=False))
    v = c.emu.alloc(0x10060, 4); c.emu.w32(v, c.emu.fake_vtable('view', 5, {0x10: L('view10', 0)})); c.emu.w32(v + 0x10055, c.rng.randint(0, 7))
    o = obj(c, 'draw', {0x64: L('draw64', 0), 0x60: L('draw60', 0)}, size=0x140)
    n = c.rng.randint(0, 8); c.emu.w32(o + 0xec, n)
    for i in range(8): c.emu.w32(o + 0xf0 + 4 * i, R(c))
    if n and c.rng.random() < 0.75: c.emu.w32(o + 0xf0 + 4 * c.rng.randint(0, n - 1), v)
    return [o, v]
S(0x63fce0, 'ZDrawBase::RemoveView', 'thiscall', None, ret='al', gen=g_63fce0)


def g_566b20(c):   # CBriefing::Talk()
    r = c.fv(-5, 5)
    def mumble(e, _):
        e.calllog.append(('StartMumbling', e.reg('ecx'), (e.arg32(0), e.arg32(1), e.arg32(2))))
        e.ret(eax=0, argbytes=12, st0=r)
    patch(c, 0x5668d0, mumble)
    rm = rbuf(c, 0x60); c.emu.w32(0x70039c, rm); c.emu.w32(rm + 0x40, c.rng.randint(-3000, 3000))
    o = rbuf(c, 0xa10)
    c.emu.wf32(o + 0x1ea, c.rng.choice([c.fv(-3, 3), float(c.rng.randint(-3, 3))]))
    n = c.rng.randint(0, 8); c.emu.w32(o + 0x1be, n); c.emu.w32(o + 0x9f8, c.rng.randint(0, 9))
    for i in range(8): c.emu.w32(o + 0x19e + 4 * i, c.rng.choice([0, R(c)]))
    return [o]
S(0x566b20, 'CBriefing::Talk', 'thiscall', None, ret=None, gen=g_566b20)


def g_41f1e0(c):   # GUESS ZSysMem constructor (vtable 0x677370, global 0x70038c)
    patch(c, 0x41e180, L('base', 0)); patch(c, 0x41e4b0, L('CheckAndInitRefs', 0))
    patch(c, 0x41e290, L('new', 1, pop=0, ecx=False, ret=c.rng.choice([0, R(c)])))
    patch(c, 0x4cf940, L('ZMalloc', 3, ret=R(c)))
    iat(c, 0x6760c0, 'InitializeCriticalSection', 1)
    return [rbuf(c, 0x60), R(c), R(c), R(c)]
S(0x41f1e0, 'GUESS ZSysMem ctor', 'thiscall', None, ret='eax', gen=g_41f1e0)


def g_420ea0(c):   # GUESS: MYSTR(out, <exe folder>\\error.log)
    path = c.rng.choice([b'C:\\Games\\FF\\Freedom.exe', b'Freedom.exe', b'D:\\a\\b\\', b'\\x', b''])
    def gmfn(e, _):
        h, buf, n = e.arg32(0), e.arg32(1), e.arg32(2)
        e.calllog.append(('GetModuleFileNameA', 0, (h, n)))
        e.wbytes(buf, path + b'\0'); e.ret(eax=len(path), argbytes=12)
    def rchr(e, _):
        s, ch = e.arg32(0), e.arg32(1) & 0xff
        b = e.rbytes(s, 0x400); b = b[:b.index(0)]; i = b.rfind(bytes([ch]))
        e.calllog.append(('strrchr', 0, (ch,)))
        e.ret(eax=s + i if i >= 0 else 0, argbytes=0)
    c.emu.w32(0x67607c, c.emu.stub_fn('gmfn', gmfn)); c.emu.w32(0x676258, c.emu.stub_fn('strrchr', rchr))
    patch(c, 0x4cbe80, L('MYSTR', 1, ret=R(c)))
    return [rbuf(c, 0x10)]
S(0x420ea0, 'GUESS error.log path', 'cdecl', None, ret='eax', gen=g_420ea0, stack_arg_bytes=0x30)
