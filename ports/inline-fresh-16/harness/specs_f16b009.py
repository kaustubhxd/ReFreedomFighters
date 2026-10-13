"""specs_f16b009.py - fresh slice 16 batch 9 (see src/f16b009.cpp)."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, sysobj
from f16help import phook, codeaddr, crt, reporter, fval


def _vobj(c, seq, slots, size=0x20):
    vt = c.emu.alloc(max(slots) + 4, 4)
    for off, (n, ret, act) in slots.items():
        f = codeaddr(c)
        phook(c, seq, f, n, ret=ret, this=True, pop=True, act=act)
        c.emu.w32(vt + off, f)
    o = rnd(c, size)
    c.emu.w32(o, vt)
    return o


def _4f6(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    phook(c, seq, 0x4f05d0, 1, ret=r.choice([1, 1, 1, 0, 0x100, 0xabcdef01]), this=True, pop=True)
    v = r.getrandbits(32)
    w = r.random() < 0.8

    def wr(e, a):
        if w:
            e.w32(a[0], v)
    lg = _vobj(c, seq, {0x40: (1, 0, wr)})
    blk = rnd(c, 0x40)
    c.emu.w32(blk + 4, r.choice([0, 8, 0x10]))
    ft = obj(c, 0x20, {0xc: stub(c, seq, 1, ret=blk)})
    t = rnd(c, 0x20)
    c.emu.w32(t + 0x18, ft)
    sysobj(c, extra={0x1aa3: t})
    return [rnd(c, 0xa4), lg]


def _639(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    phook(c, seq, 0x634273, 2)
    buf = rnd(c, 0x40)
    phook(c, seq, 0x41e290, 1, ret=buf)
    me = rnd(c, 0x30)
    c.emu.w8(me + 0x28, r.choice([0, 1]))
    if r.random() < 0.15:
        return [me, 0]
    n = r.randint(0, 40)
    s = c.emu.alloc(n + 1, 1)
    c.emu.wbytes(s, bytes(r.randint(1, 255) for _ in range(n)) + b'\0')
    return [me, s]


def _63b(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    n = r.randint(1, 12)
    e = rnd(c, 0x10 + 0x10 * n + 0x10)
    me = obj(c, 0x20, {0x30: stub(c, seq, 0, ret=e if r.random() < 0.85 else 0), 0x28: stub(c, seq, 0, ret=n)})
    if r.random() < 0.7:
        l = rnd(c, 0x10)
        t = rnd(c, 0x10)
        c.emu.w32(l + 0xc, t)
        c.emu.w32(me + 8, l)
    else:
        c.emu.w32(me + 8, 0)
    return [me]


def _603(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    phook(c, seq, 0x5f55e0, 0, this=True)
    phook(c, seq, 0x41e2c0, 1)
    k = r.random()
    n = r.randint(0, 20) if k < 0.8 else r.choice([0x20000000, 0x1fffffff, 0xffffffff])
    buf = rnd(c, 8 * min(n, 20) + 8)
    phook(c, seq, 0x41e290, 1, ret=buf if (n <= 20 and r.random() < 0.9) else 0)
    pn = rnd(c, 4)
    c.emu.w32(pn, n)
    return [rnd(c, 0x10), pn]


def _485(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    phook(c, seq, 0x469870, 0, this=True)
    a = obj(c, 0x50, {0x44: stub(c, seq, 1, ret=rnd(c, 0x50) if r.random() < 0.8 else 0)})
    db = rnd(c, 0x20)
    c.emu.w32(db + 8, a)
    sysobj(c, db=db)
    return [rnd(c, 0x20)]


S(0x4f6600, 'ZTTFONT::Load', 'thiscall', None, ret='al', gen=_4f6, note='f16b009; ZWINOBJ::Load hooked')
S(0x639d00, 'FUN_639d00 (set owned string)', 'thiscall', None, ret=None, gen=_639, note='f16b009; new/delete hooked')
S(0x63b240, 'FUN_63b240 (new block + free list)', 'thiscall', None, ret='al', gen=_63b, note='f16b009; n >= 1 only')
S(0x603c00, 'FUN_603c00 (realloc 8-byte table)', 'thiscall', None, ret=None, gen=_603, note='f16b009; new/free hooked')
S(0x485a40, 'FUN_485a40 (create object 0x68c774)', 'thiscall', None, ret='eax', gen=_485, note='f16b009; SEH not reproduced')
