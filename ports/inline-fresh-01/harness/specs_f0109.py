"""specs_f0109.py - fresh-01 batch 9 (docs/20-fresh-01.md)."""
from pilot import S
from helpers01 import rnd, hk, obj


def _iblock(c):
    return [rnd(c, 0x1700)]


def _add(c):
    n = c.rng.randint(0, 4)
    blocks = [rnd(c, 0x10 + 36 * 8 + 0x10) for _ in range(n)]
    for i, b in enumerate(blocks):
        c.emu.w16(b + 2, 0xffff if c.rng.random() < 0.6 else c.rng.randint(0, 7))
        c.emu.w32(b + 8, blocks[(i + 1) % n] if (i + 1 < n or c.rng.random() < 0.6) else 0)
    o = rnd(c, 0x20)
    c.emu.w32(o + 8, blocks[c.rng.randint(0, n - 1)] if n else 0)
    grow = c.rng.random() < 0.7
    fresh = rnd(c, 0x10 + 36 * 8 + 0x10)
    c.emu.w16(fresh + 2, c.rng.choice([0, 3, 0xffff]))

    def g(e, r):
        e.calllog.append(('grow', e.reg('ecx')))
        if grow:
            e.w32(e.reg('ecx') + 8, fresh)
        e.ret(eax=0x100 | int(grow))
    c.emu.hook(0x648dd0, g)
    hk(c, 0x647f70, 'entry init', 0)
    return [o]


def _fact(c):
    eng = rnd(c, 0x200)
    c.emu.w32(0x70039c, eng)
    r = rnd(c, 0x20)
    c.emu.w32(eng + 0x9b, r)
    sel = c.rng.random() < 0.8
    p = rnd(c, 0x240)
    c.emu.w32(r + 8, obj(c, 0x10, 'alloc', 0x20, {0x44: lambda e, a: (p if sel else 0, None)}, {0x44: 1}))
    hk(c, 0x573590, 'ctor', 0)
    return [c.rng.getrandbits(32)]


def _xml(c):
    cands = [b'\0x\0m\0l', b'\0X\0M\0L', b'\0x\0m\0L', b'\0X\0m\0l', b'\0x\0M\0l', b'\0x\0m\0q', b'\1x\0m\0l', b'\0x\1m\0l',
             b'\0y\0m\0l', b'\0x\0n\0l', b'\0x\0m\1l']
    s = c.rng.choice(cands + [bytes(c.rng.getrandbits(8) for _ in range(6))])
    if c.rng.random() < 0.1:
        s = s[:c.rng.randint(0, 5)]
    p = rnd(c, 8)
    c.emu.wbytes(p, s)
    return [c.rng.getrandbits(32), p, p + len(s), rnd(c, 4)]


def _plot(c):
    eng = rnd(c, 0xa00)
    c.emu.w32(0x70039c, eng)
    c.emu.wf32(eng + 0x9c7, c.rng.choice([0.0, -0.0, 1.0, float('nan')]))
    text = bytes(c.rng.choice(b'abc123 ') for _ in range(c.rng.randint(0, 30))) + b'\0'

    def s4c(e, r):
        e.calllog.append(('vsprintf', e.arg32(1), e.r32(e.arg32(2)), e.r32(e.arg32(2) + 4)))
        e.wbytes(e.arg32(0), text)
        e.ret(argbytes=12)
    con = rnd(c, 0x20)
    c.emu.w32(con, c.emu.fake_vtable('con', 0x20, {0x4c: s4c}))
    c.emu.w32(0x700390, con)

    def s124(e, r):
        e.calllog.append(('plot', e.arg32(0), e.arg32(1), e.arg32(2), e.rbytes(e.arg32(3), 0x40).hex()))
        e.ret()
    vt = c.emu.fake_vtable('plotter', 0x50, {0x124: s124})
    nxt = 0
    for _ in range(c.rng.randint(0, 3)):
        p = rnd(c, 0x20)
        c.emu.w32(p, vt)
        c.emu.w32(p + 8, nxt)
        nxt = p
    o = rnd(c, 0x1a00)
    c.emu.w32(o + 0x190f, nxt)
    return [o, c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _sound(c):
    hk(c, 0x4e6680, 'ZSoundDllBase', 0)
    p = 0 if c.rng.random() < 0.2 else rnd(c, 0xc0)
    hk(c, 0x41e290, 'new', 1, eax=p, regs=(), pop=False)
    hk(c, 0x5f1180, 'mgr ctor', 0, eax=lambda e: e.reg('ecx') + 2)
    return [rnd(c, 0x1020)]


def _copy(c):
    return [rnd(c, 0x200), rnd(c, 0x200)]


S(0x630c50, 'zlib init_block', 'cdecl', None, ret=None, gen=_iblock)
S(0x648350, 'ZDrawArray<ZGeomViewEntry>::Add', 'thiscall', None, ret='eax', gen=_add)
S(0x575e50, 'factory 0x575e50', 'thiscall', None, ret='eax', gen=_fact)
S(0x626ed0, 'xml name check 0x626ed0', 'cdecl', None, ret='eax', gen=_xml)
S(0x424650, 'ZSysInterfaceGC::UPlotF', 'cdecl', None, ret=None, gen=_plot)
S(0x5f12d0, 'sound dll ctor 0x5f12d0', 'thiscall', None, ret='eax', gen=_sound)
S(0x56f190, 'CNewMenu::CopyData', 'thiscall', None, ret=None, gen=_copy)
