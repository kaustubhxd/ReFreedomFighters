"""specs_f0103.py - fresh-01 batch 3 (docs/20-fresh-01.md)."""
from pilot import S, F
from helpers01 import rnd, hk, obj


def _logmgr(c, a20=2):
    def s2c(e, r):
        e.calllog.append(('log', e.arg32(0), e.arg32(1)))
        e.ret(eax=0x10910000, argbytes=0)
    o = rnd(c, 0x20)
    c.emu.w32(o, c.emu.fake_vtable('logger', 0x10, {0x2c: s2c}))
    c.emu.w32(0x700390, obj(c, 0x20, 'mgr', 0x10, {0x20: lambda e, a: (o, None)}, {0x20: a20}))


def _rename(c):
    ok = c.rng.choice([0, 1, 7])

    def mv(e, r):
        e.calllog.append(('MoveFileA', e.arg32(0), e.arg32(1)))
        e.ret(eax=ok, argbytes=8)
    c.emu.stub_import('MoveFileA', mv)
    _logmgr(c)
    return [c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _adm(c):
    b = rnd(c, 0x18400)
    o = b + 0x40
    c.emu.w32(o + 0x20, c.rng.choice([0, 1, 2, -1 & 0xffffffff, -2 & 0xffffffff, c.rng.randint(0, 0x3000)]))
    return [o]


def _dtor(c):
    hk(c, 0x45c3e0, '~ZGEOM', 0)
    hk(c, 0x45c510, 'ZGEOM delete', 1, regs=(), pop=False)
    hk(c, 0x4690b0, 'sized delete', 2, regs=(), pop=False)
    return [rnd(c, 0x40), c.rng.getrandbits(32)]


def _ii(c):
    def v():
        return c.rng.choice([0, 1, -1, 0x7fffffff, -0x80000000, c.rng.randint(-50, 50), c.rng.getrandbits(32)]) & 0xffffffff
    a = v()
    return [a, a if c.rng.random() < 0.1 else v(), v()]


def _render(c, impl, argw):
    eng = rnd(c, 0x200)
    c.emu.w32(0x70039c, eng)
    c.emu.w32(eng + 0x9b, obj(c, 0x20, 'render', 0x60, impl, argw))


def _cut(c):
    s = obj(c, 0x20, 'seq', 0x20, {0x4c: lambda e, a: (0x4c4c0000 ^ a[1], None)}, {0x4c: 2})
    _render(c, {0x138: lambda e, a: (s, None), 0x4c: lambda e, a: (a[0] ^ 0x55aa, None)}, {0x4c: 1})
    return [rnd(c, 0x80)]


def _vec(c):
    n = c.rng.randint(0, 6)
    arr = rnd(c, 4 * n + 4)
    o = rnd(c, 0x10)
    c.emu.w32(o, arr)
    c.emu.w32(o + 4, arr + 4 * n)
    hk(c, 0x5f9570, 'elemSize', 0, eax=lambda e: (e.reg('ecx') & 0xfff) + 3)
    return [o]


def _defrag(c):
    sizes = [c.rng.choice([8, 12, 16, 20, 32, 64]) for _ in range(c.rng.randint(0, 8))]
    buf = rnd(c, sum(sizes) + 16)
    off = 0
    for s in sizes:
        c.emu.w32(buf + off, s)
        c.emu.w8(buf + off + 4, c.rng.choice([0, 1, 0x80]))
        off += s
    o = rnd(c, 0x20)
    c.emu.w32(o + 8, buf)
    c.emu.w32(o + 0xc, off)

    def mm(e, r):
        d, s_, n = e.arg32(0), e.arg32(1), e.arg32(2)
        e.calllog.append(('memmove', d, s_, n))
        e.wbytes(d, e.rbytes(s_, n))
        e.ret(eax=d)
    c.emu.stub_import('VCRUNTIME140.dll!memmove', mm)
    return [o]


def _mouse(c):
    w = obj(c, 0x20, 'win', 0x40, {0xbc: lambda e, a: (0xbcbc0000 | a[0], None)}, {0xbc: 1})
    sel = c.rng.random() < 0.75
    _render(c, {0x58: lambda e, a: (w if sel else 0, None)}, {0x58: 1})
    return [rnd(c, 0x700), c.rng.choice([0, 1, 0x100, 0xffffff00, c.rng.getrandbits(32)])]


def _cb(c):
    outv = c.rng.choice([None, 0, 0x1234, c.rng.getrandbits(32)])

    def h1(e, r):
        e.calllog.append(('61dba0', e.arg32(0), e.arg32(1), e.r32(e.arg32(2)), e.arg32(3), e.arg32(4)))
        if outv is not None:
            e.w32(e.arg32(2), outv)
        e.ret()
    c.emu.hook(0x61dba0, h1)
    hk(c, 0x620bc0, '620bc0', 4, regs=(), pop=False)
    return [rnd(c, 0x200), c.rng.choice([0, c.rng.getrandbits(32)]), c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _pos(c):
    o = obj(c, 0x100, 'obj', 0x90, {}, {})
    p = rnd(c, 0x10)
    for k in (0, 4):
        v = c.fv()
        c.emu.wf32(p + k, v)
        if c.rng.random() < 0.5:
            c.emu.wf32(o + 0x22 + k, v)
        elif c.rng.random() < 0.3:
            c.emu.w32(o + 0x22 + k, c.emu.r32(p + k) ^ 0x80000000)
    if c.rng.random() < 0.1:
        c.emu.w32(p, 0x7fc00000)
        c.emu.w32(o + 0x22, 0x7fc00000)
    return [o, p, c.rng.getrandbits(32)]


S(0x427fd0, 'ZSysFileGC::Rename', 'thiscall', None, ret='eax', gen=_rename)
S(0x648c10, 'ZViewBase::AddAlwaysDrawMaterials', 'thiscall', None, ret=None, gen=_adm)
S(0x4527d0, 'ZDebugGeom scalar deleting destructor', 'thiscall', None, ret='eax', gen=_dtor)
S(0x54f110, 'approach 0x54f110', 'stdcall', None, ret='eax', gen=_ii)
S(0x4afed0, 'CCutSequenceObjects::LoadInit', 'thiscall', None, ret='eax', gen=_cut)
S(0x500150, 'vector serial size 0x500150', 'thiscall', None, ret='eax', gen=_vec)
S(0x4d29d0, 'CGlobalCom::Defrag', 'thiscall', None, ret=None, gen=_defrag)
S(0x4f3950, 'ZWINDOWS::SetShowMouse', 'thiscall', None, ret='eax', gen=_mouse)
S(0x61fd10, 'callback setup 0x61fd10', 'cdecl', None, ret=None, gen=_cb)
S(0x4f1290, 'set pos 0x4f1290', 'thiscall', None, ret=None, gen=_pos)
