"""specs_f16b014.py - fresh slice 16 batch 14 (see src/f16b014.cpp)."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, sysobj
from f16help import phook, codeaddr


def _633(c):
    r = c.rng
    clear_hooks(c)
    k = r.random()
    if k < 0.2:
        c.emu.w16(0x400000, r.choice([0x5a4d, 0x1234]))
    if k < 0.1:
        c.emu.w32(0x400000 + c.emu.r32(0x40003c), r.choice([0x4550, 0x4551]))
    p = r.choice([0x401000 + r.randint(0, 0x260000), 0x660000 + r.randint(0, 0x80000), 0x6e4000 + r.randint(0, 0x130000),
                  r.getrandbits(32), 0x400000 + r.randint(0, 0x1000)])
    return [p]


def _616(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    phook(c, seq, 0x659330, 2, this=True, pop=True)
    t = rnd(c, 0x10)
    a = rnd(c, 0x10)
    c.emu.w32(a + 8, t)
    o38 = rnd(c, 0x40)
    o = rnd(c, 0x40)
    c.emu.w32(o + 0x38, o38)
    ge = rnd(c, 0x14)
    c.emu.w32(ge + 0x10, a)
    c.emu.w32(ge + 0xc, o)
    return [rnd(c, 0x14), r.getrandbits(32), ge, rnd(c, 0xb9b0)]


def _629(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    phook(c, seq, 0x62c640, 2, ret=lambda e: r.choice([0x12, 0x18, 0x19, 0x1a, 0, 0x16]))
    enc = rnd(c, 0x150)
    for i in range(256):
        c.emu.w8(enc + 0x4c + i, r.choice([0x12, 0x18, 0x19, 0x18, 0x19, 0x1a, 0x16, 0]))
    n = r.randint(0, 8)
    buf = c.emu.alloc(2 * n + 2, 2)
    for i in range(n):
        c.emu.w8(buf + 2 * i, r.getrandbits(8))
        c.emu.w8(buf + 2 * i + 1, 0 if r.random() < 0.8 else r.getrandbits(8))
    nx = rnd(c, 4)
    return [enc, buf, buf + 2 * n, nx]


def _448(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    phook(c, seq, 0x45c4f0, 2, ret=rnd(c, 0x20) if r.random() < 0.8 else 0)
    phook(c, seq, 0x45c4b0, 1, ret=rnd(c, 0x20) if r.random() < 0.8 else 0)
    phook(c, seq, 0x447580, 3, this=True, pop=True, ret=r.getrandbits(32))
    return [r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), r.choice([0, r.getrandbits(32)])]


S(0x633e05, '___scrt_is_nonwritable_in_current_image', 'cdecl', None, ret='al', gen=_633, note='f16b014; find_pe_section runs real; SEH4 not reproduced')
S(0x616580, 'FUN_616580 (constructor, vtable 0x6bdc58)', 'thiscall', None, ret='eax', gen=_616, note='f16b014; SEH not reproduced')
S(0x629a40, 'FUN_629a40 (expat big2 scan)', 'cdecl', None, ret='eax', gen=_629, note='f16b014')
S(0x448000, 'FUN_448000 (alloc + construct)', 'fastcall', None, ret='eax', gen=_448, note='f16b014; SEH not reproduced')
