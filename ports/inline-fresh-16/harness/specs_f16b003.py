"""specs_f16b003.py - fresh slice 16 batch 3 (see src/f16b003.cpp)."""
import struct
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, sysobj
from f16help import phook, codeaddr, crt

TABLE = [0x35, 0x61, 0xc1, 0x185, 0x301, 0x607, 0xc07, 0x1807, 0x3001, 0x6011, 0xc005, 0x1800d, 0x30005, 0x60019,
         0xc0001, 0x180005, 0x30000b, 0x60000d, 0xc00005, 0x1800013, 0x3000005, 0x6000017, 0xc000013, 0x18000005,
         0x30000059, 0x60000005, 0xc0000001, 0xfffffffb]


def _4cb(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    o = obj(c, 0x40, {0xe0: stub(c, seq, 2)})
    t = rnd(c, 0x40)
    c.emu.w32(t + 0x18, o)
    sysobj(c, extra={0x1aa3: t})
    me = rnd(c, 0x60)
    c.emu.w32(me + 0x44, rnd(c, 0x10))
    cmd = r.choice([0x401, 0x401, 0x10401, 0x400, r.getrandbits(32)])
    return [me, cmd, r.getrandbits(32)]


def _423(c):
    seq = Seq(c)
    clear_hooks(c)
    phook(c, seq, 0x42f8c0, 1, this=True, pop=True)
    sg = obj(c, 0x40, {0x50: stub(c, seq, 2), 0x58: stub(c, seq, 2)})
    return [rnd(c, 0x2400), sg]


def _607(c):
    r = c.rng
    clear_hooks(c)
    k = r.random()
    if k < 0.4:
        key = r.choice(TABLE)
    elif k < 0.6:
        key = (r.choice(TABLE) + r.choice([-1, 1])) & 0xffffffff
    else:
        key = r.getrandbits(r.choice([8, 16, 24, 32]))
    return [key]


def _4f3(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    phook(c, seq, 0x44edd0, 1, this=True, pop=True)
    phook(c, seq, 0x4e12e0, 2, this=True, pop=True)
    phook(c, seq, 0x4e1600, 0, ret=r.choice([8, 8, 7, 0x108, r.getrandbits(32)]), this=True)
    phook(c, seq, 0x4e1b30, 0, this=True)
    return [rnd(c, 0x80), rnd(c, 0x20)]


def _5ff(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    h = codeaddr(c)
    phook(c, seq, h, 0, ret=r.getrandbits(32))
    c.emu.w32(0x7003b0, h)
    phook(c, seq, 0x5ffd10, 1, ret=r.getrandbits(32), this=True, pop=True)
    nxt = 0
    for _ in range(r.randint(1, 4)):
        im = rnd(c, 0xb0)
        c.emu.w32(im + 0x9c, nxt)
        c.emu.w32(im + 0xa8, r.choice([0, 1, r.getrandbits(32)]))
        c.emu.w32(im + 0xa0, r.choice([r.randint(0, 0x30), r.getrandbits(32), 0x10000 + r.randint(0, 5)]))
        nxt = im
    return [nxt, r.choice([r.randint(0, 0x40), r.getrandbits(32)])]


def _57b(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    phook(c, seq, 0x564b10, 0, this=True)
    s = obj(c, 0x80, {0x60: stub(c, seq, 3)})
    db = obj(c, 0x140, {0x138: stub(c, seq, 0, ret=s), 0x4c: stub(c, seq, 1, ret=r.getrandbits(32))})
    sysobj(c, db=db)
    return [rnd(c, 0x60)]


def _64c(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    t = obj(c, 0x20, {0xf8: stub(c, seq, 0, ret=r.getrandbits(32))})
    o = rnd(c, 0x60)
    c.emu.w32(o + 0x54, t)
    a = rnd(c, 0x40)
    c.emu.w32(a + 0x38, o)
    p = rnd(c, 0x20)
    c.emu.w32(p + 8, a)
    c.emu.w32(p + 0xc, rnd(c, 0x30) if r.random() < 0.7 else 0)
    return [p]


def _651(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    x = obj(c, 0x20, {0xc: stub(c, seq, 0, ret=r.choice([0, 1, 0x100, r.getrandbits(32)]))})
    s = obj(c, 0xa00, {0x1b0: stub(c, seq, 0, ret=x if r.random() < 0.6 else 0)})
    k = r.random()
    bits = 0 if k < 0.3 else (0x80000000 if k < 0.4 else (0x7fc00000 if k < 0.5 else r.getrandbits(32)))
    c.emu.w32(s + 0x9c7, bits)
    c.emu.w32(0x70039c, s)
    me = rnd(c, 0x80)
    c.emu.w32(me + 0x74, r.choice([0, r.getrandbits(32)]))
    return [me]


S(0x4cbcc0, 'ZTextureAnim::Command', 'thiscall', None, ret='eax', gen=_4cb, note='f16b003')
S(0x423980, 'ZSysInterfaceGC::Save', 'thiscall', None, ret=None, gen=_423, note='f16b003; base Save hooked')
S(0x6071c0, 'FUN_6071c0 (table lower_bound)', 'thiscall', None, ret='eax', gen=_607, note='f16b003')
S(0x4f3e00, 'ZWINDOW::CopyDataBlock', 'thiscall', None, ret=None, gen=_4f3, note='f16b003; DBLK calls hooked')
S(0x5ffb00, 'VMImageInfo_t::getCommonString', 'thiscall', None, ret='eax', gen=_5ff, note='f16b003; null-handler int3 not run')
S(0x57bd00, 'ZFFLoadError::Init', 'thiscall', None, ret=None, gen=_57b, note='f16b003')
S(0x64c040, 'FUN_64c040 (flag + 48-byte copy)', 'stdcall', None, ret=None, gen=_64c, note='f16b003; null-object input not run')
S(0x651180, 'ZRender::TextDisplayEnabled', 'thiscall', None, ret='al', gen=_651, note='f16b003')
