"""specs_s38093.py - cascade s8 batch 38093. cdecl(vi) void. vi = 0x70-byte random block (null 3%): +4 codec setup ci (null 8%; then +8 is 0), ci+4 count, ci+0x1c private block P (n mappings at P+8, P+0x24+4i -> mapping with an index at +0xc, P+0x124+4*idx = decoder kind
0..2, count P+0x1c), +8 array of ci[4] pointers (some null), +0xc, +0x68 backend b (null 10%): b+4 -> block whose first dword is a pointer, b+0x14..0x20 four structures with a first pointer, b+0 / +0x24 / +0x28 / +0x30 / +0x2c /
+0x38 / +0x3c / +0x40 / +0x44 pointers (each null or valid). The decoder-kind function tables in the exe image (0x6f1dd8 + 4*kind) are overwritten with tables whose +0x14 entry is a logging stub. free (0x634d52) and the five
single-argument helpers are logging hooks (every call logged)."""
import struct
from pilot import S
from recruits_util import rnd, clear_hooks


def _g401c90(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def mk(addr, name):
        e.hook(addr, lambda em, res_, name=name: (em.calllog.append((name, em.arg32(0))), em.ret(eax=0, argbytes=0)))
    for a, nm in ((0x634d52, 'free'), (0x4063d0, 'h4063d0'), (0x406770, 'h406770'), (0x402480, 'h402480'), (0x4062e0, 'h4062e0'), (0x405690, 'h405690')):
        mk(a, nm)
    for kind in range(3):
        tab = e.alloc(0x40, 4)
        e.w32(tab + 0x14, e.stub_fn('kindfn%d' % kind, (lambda k: lambda em, res_: (em.calllog.append(('kindfn', k, em.arg32(0))), em.ret(eax=0, argbytes=0)))(kind)))
        e.w32(0x6f1dd8 + 4 * kind, tab)

    def maybe(f, p=0.75):
        return f() if r.random() < p else 0

    def blk(n=0x20):
        return rnd(c, n)

    def ptrblk():
        x = rnd(c, 0x10)
        e.w32(x, maybe(blk))
        return x
    vi = rnd(c, 0x70)
    ci = rnd(c, 0x40) if r.random() > 0.08 else 0
    e.w32(vi + 4, ci)
    P = 0
    if ci:
        cnt = r.choice([0, 1, 2, 3])
        e.w32(ci + 4, cnt)
        P = maybe(lambda: rnd(c, 0x200), 0.8)
        e.w32(ci + 0x1c, P)
        if cnt:
            arr = e.alloc(4 * 4, 4)
            e.wbytes(arr, struct.pack('<4I', *[maybe(blk) for _ in range(4)]))
            e.w32(vi + 8, arr)
        else:
            e.w32(vi + 8, maybe(lambda: e.alloc(16, 4), 0.4))
        e.w32(vi + 0xc, maybe(blk))
    else:
        e.w32(vi + 8, 0)
    if P:
        n = r.choice([0, 1, 2, 3])
        e.w32(P + 8, n)
        for i in range(3):
            m = rnd(c, 0x20)
            e.w32(m + 0xc, r.randrange(3))
            e.w32(P + 0x24 + 4 * i, m)
        for k in range(3):
            e.w32(P + 0x124 + 4 * k, r.randrange(3))
        e.w32(P + 0x1c, r.choice([0, 1, 2, 3]))
    b = rnd(c, 0x80) if r.random() > 0.1 else 0
    e.w32(vi + 0x68, b)
    if b:
        e.w32(b + 4, maybe(ptrblk))
        for off in (0x14, 0x18, 0x1c, 0x20):
            e.w32(b + off, ptrblk())
        e.w32(b, maybe(blk))
        e.w32(b + 0x24, maybe(ptrblk))
        e.w32(b + 0x28, maybe(ptrblk))
        for off in (0x30, 0x2c, 0x3c, 0x40, 0x44):
            e.w32(b + off, maybe(blk))
        arr = e.alloc(16, 4)
        e.wbytes(arr, struct.pack('<4I', *[r.getrandbits(32) | 1 for _ in range(4)]))
        e.w32(b + 0x38, maybe(lambda: arr))
    return [vi if r.random() > 0.03 else 0]


S(0x401c90, 'GUESS vorbis_info_clear', 'cdecl', None, ret=None, gen=_g401c90, note='batch38093')
