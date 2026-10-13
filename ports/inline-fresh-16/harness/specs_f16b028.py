"""specs_f16b028.py - fresh slice 16 batch 28 (see src/f16b028.cpp)."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, sysobj
from f16help import phook, codeaddr


def _621(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    ctx = rnd(c, 0x1c0)
    buf = rnd(c, 0x40)
    c.emu.w32(ctx + 0x1b8, buf)
    c.emu.w32(ctx + 0x1b4, buf + r.randrange(0, 4))
    c.emu.w32(ctx + 0x1b0, buf + r.randrange(4, 12))

    def grow(e, a):
        if r.random() < 0.1:
            return 0
        pool = a[0]
        nb = rnd(c, 0x80)
        st, pt = e.r32(pool + 0x10), e.r32(pool + 0xc)
        e.wbytes(nb, bytes(e.rbytes(st, pt - st)) if 0 < pt - st < 0x40 else b'')
        e.w32(pool + 0x10, nb)
        e.w32(pool + 0xc, nb + (pt - st if 0 < pt - st < 0x40 else 0))
        e.w32(pool + 8, nb + 0x80)
        return 1
    phook(c, seq, 0x6206e0, 1, act=grow)

    def look(e, a):
        k = r.random()
        if k < 0.1:
            return 0
        res = rnd(c, 8)
        e.w32(res, a[1] if k < 0.6 else r.getrandbits(32))
        return res
    phook(c, seq, 0x61fd60, 3, act=look)
    name = bytes(r.choice(b'ab:c') for _ in range(r.randrange(0, 10))) + b'\0'
    nm = c.emu.alloc(len(name) + 4, 4)
    c.emu.wbytes(nm, name)
    elem = rnd(c, 8)
    c.emu.w32(elem, nm)
    return [ctx, elem]


def _638(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    w, h = r.randrange(0, 5), r.randrange(0, 4)
    s = rnd(c, 0x20)
    c.emu.w32(s + 4, w + r.randrange(0, 3))
    pix = rnd(c, 0x80)
    c.emu.w32(s + 0x10, pix)
    src = rnd(c, 0x30)
    c.emu.w32(src + 0, r.randrange(0, 4))
    c.emu.w32(src + 4, r.randrange(0, 3))
    c.emu.w32(src + 8, w)
    c.emu.w32(src + 0xc, h)
    c.emu.w32(src + 0x10, 4 * w + r.randrange(0, 8))
    masks = r.choice([(0xf800, 0x7e0, 0x1f, 0), (0x7c00, 0x3e0, 0x1f, 0x8000), (0xff0000, 0xff00, 0xff, 0xff000000),
                      (0xf00, 0xf0, 0xf, 0xf000)])
    for i, m in enumerate(masks):
        c.emu.w32(src + 0x14 + 4 * i, m)
    c.emu.w32(src + 0x24, r.choice([16, 32, 16]))
    c.emu.w32(src + 0x2c, rnd(c, 0x80))
    pal = rnd(c, 0x400)
    me = obj(c, 0x40, {0x38: stub(c, seq, 1, ret=s)})
    c.emu.w32(me + 0x2d, pal)
    return [me, src, r.getrandbits(32)]


S(0x6210c0, 'setElementTypePrefix (expat)', 'cdecl', None, ret='eax', gen=_621, note='f16b028')
S(0x638b80, 'FUN_638b80 (palette blit through a pixel converter)', 'thiscall', None, ret=None, gen=_638, note='f16b028; 0x4d06a0/0x639df0 run as exe code; cookie not reproduced')
