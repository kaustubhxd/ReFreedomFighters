"""specs_f16b005.py - fresh slice 16 batch 5 (see src/f16b005.cpp)."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, sysobj
from f16help import phook, codeaddr, crt, reporter, fval


def _562(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    phook(c, seq, 0x4f21f0, 1, this=True, pop=True)
    sysobj(c, extra={0x30: r.choice([0, 1, -1 & 0xffffffff, 0x7fffffff, 0x80000000, r.getrandbits(32), r.randint(0, 5000)])})
    me = obj(c, 0x100, {0x84: stub(c, seq, 0, ret=rnd(c, 0x10))})
    c.emu.w8(me + 0x85, r.choice([0, 0, 1]))
    c.emu.w32(me + 0xdc, r.choice([2, 2, 1, 4, r.getrandbits(32)]))
    return [me]


def _4f8(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    phook(c, seq, 0x4fa390, 1, ret=r.getrandbits(32), this=True, pop=True)
    me = obj(c, 0xa0, {0x370: stub(c, seq, 1)})
    c.emu.w32(me + 0x9b, fval(c))
    return [me, r.choice([0x102, 0x103, 0x101, 0x104, 0x10102, r.getrandbits(32)])]


def _50b(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    reporter(c, seq)
    h = codeaddr(c)
    phook(c, seq, h, 0, ret=r.getrandbits(32))
    c.emu.w32(0x7003b0, h)
    e = rnd(c, 0x10)
    c.emu.w8(e + 4, r.choice([0, 1, 2, 0xff, r.getrandbits(8)]))
    phook(c, seq, 0x5003d0, 1, ret=e, this=True, pop=True)
    p = rnd(c, 0x10)
    return [p]


def _grp(c, seq, depth):
    r = c.rng
    g = rnd(c, 0x70)
    nodes = [rnd(c, 0x70) for _ in range(r.randint(0, 3) if depth < 3 else 0)]
    for i, s in enumerate(nodes):
        c.emu.w32(s + 0x60, nodes[i + 1] if i + 1 < len(nodes) else 0)
        k = r.random()
        if k < 0.6 and depth < 3:
            ch = _grp(c, seq, depth + 1)
            m = rnd(c, 0x30)
            c.emu.w32(m + 0x23, r.getrandbits(32) | 0x100000 if r.random() < 0.8 else r.getrandbits(32) & ~0x100000)
            c.emu.w32(ch + 0xc, m)
            c.emu.w32(s + 0x54, ch)
        else:
            c.emu.w32(s + 0x54, 0)
    c.emu.w32(g + 0x50, nodes[0] if nodes else 0)
    f = codeaddr(c)

    def act(e, a, g=g):
        x = e.r32(g + 0x50)
        e.w32(g + 0x50, e.r32(x + 0x60))
    phook(c, seq, f, 2, this=True, pop=True, act=act)
    vt = c.emu.alloc(0x294, 4)
    c.emu.w32(vt + 0x290, f)
    c.emu.w32(g, vt)
    return g


def _496(c):
    seq = Seq(c)
    clear_hooks(c)
    return [rnd(c, 0x10), _grp(c, seq, 0)]


def _4e4(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    phook(c, seq, 0x4e6bf0, 1, this=True, pop=True)
    sz = r.choice([0x10, 0x20, 0x14])
    nrows = 8
    base = rnd(c, sz * nrows)
    n = r.randint(1, nrows - 1)
    me = base + r.randint(0, nrows - 1) * sz
    for i in range(nrows):
        for j in range(4):
            if r.random() < 0.4:
                c.emu.w16(base + i * sz + 2 * j, (me - base) // sz)
    c.emu.w16(me + 8, n if r.random() < 0.9 else 0)
    c.emu.w32(me + 0xc, 0 if r.random() < 0.85 else 1)
    c.emu.w32(me, 0 if r.random() < 0.85 else 1)
    c.emu.w32(me + 4, 0 if r.random() < 0.85 else 1)
    pool = rnd(c, 0x10)
    c.emu.w32(pool, base)
    c.emu.w32(pool + 0xc, sz)
    return [me, pool]


def _53a(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    els = [rnd(c, 0x10) for _ in range(r.randint(0, 4))]
    for e in els:
        c.emu.w32(e + 8, r.choice([r.getrandbits(32), r.randint(0, 1000), 0x80000000, 0x7fffffff]))
    out = rnd(c, 4) if (not els or r.random() < 0.7) else r.choice(els) + 8
    sysobj(c, t=r.choice([r.randint(0, 1000), r.getrandbits(32)]))
    seqv = list(els) + [0]
    cnt = [0]

    def nxt(e):
        v = seqv[min(cnt[0], len(seqv) - 1)]
        cnt[0] += 1
        return v
    f4c, f64 = codeaddr(c), codeaddr(c)
    phook(c, seq, f4c, 1, this=True, pop=True)
    phook(c, seq, f64, 1, ret=nxt, this=True, pop=True)
    vt = c.emu.alloc(0x68, 4)
    c.emu.w32(vt + 0x4c, f4c)
    c.emu.w32(vt + 0x64, f64)
    l = rnd(c, 0x10)
    c.emu.w32(l, vt)
    me = rnd(c, 0x10)
    c.emu.w32(me + 4, l if r.random() < 0.85 else 0)
    return [me, out]


S(0x562bc0, 'CBaseWindow::LoadLevel', 'thiscall', None, ret=None, gen=_562, note='f16b005; EnableFade hooked')
S(0x4f8040, 'ZSlider::OnKeyPress', 'thiscall', None, ret='al', gen=_4f8, note='f16b005; ZCONTROL::OnKeyPress hooked')
S(0x50b780, 'FUN_50b780 (slot reset or report)', 'stdcall', None, ret='eax', gen=_50b, note='f16b005; null-handler int3 not run')
S(0x496700, 'ZGeomBuffer::DetachAllGeoms', 'thiscall', None, ret=None, gen=_496, note='f16b005')
S(0x4e4900, 'FUN_4e4900 (pool slot release)', 'thiscall', None, ret=None, gen=_4e4, note='f16b005; DeAlloc hooked')
S(0x53aa80, 'CEVENTCONTROLLER::GetOldestNotifyTime', 'thiscall', None, ret='eax', gen=_53a, note='f16b005')
