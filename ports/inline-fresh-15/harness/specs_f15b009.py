"""specs_f15b009.py - fresh slice 15 batch 9 (see src/f15b009.cpp)."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, hook, HOOKED
from f15help import phook, codeaddr, loghook, crt


def _r(c):
    return c.rng.getrandbits(32)


def _seq(vals):
    k = [0]

    def f(e):
        v = vals[k[0] % len(vals)]; k[0] += 1
        return v
    return f


def _code(c, seq, n, ret=0, this=False, pop=False, calls=6):
    a = codeaddr(c)
    loghook(c, seq, a, n, ret=ret, this=this, pop=pop, calls=calls)
    return a


def _639(c):
    seq = Seq(c); clear_hooks(c); crt(c)
    r = c.rng
    me = rnd(c, 0x20)
    tab = rnd(c, 20 * 8)
    c.emu.w32(me + 0x14, tab)
    idx = r.randint(0, 7)
    c.emu.w8(tab + idx * 20 + 0xc, r.choice([0, 0, 1, r.getrandbits(8)]))
    size = r.choice([0, 1, 4, 13, r.randint(0, 64)])
    data = rnd(c, size + 4)
    loghook(c, seq, 0x634273, 2)
    loghook(c, seq, 0x41e290, 1, ret=rnd(c, size + 4))
    return [me, data, size, _r(c), _r(c), idx, r.choice([0, 1, 0x100, _r(c)])]


def _536(c):
    seq = Seq(c); clear_hooks(c)
    r = c.rng
    me = obj(c, 0x5310, {0x1ec: _code(c, seq, 1, this=True, pop=True, calls=10)})
    pool = rnd(c, 0x100)
    c.emu.w32(me + 0x5302, pool)
    first = r.choice([0, 4, r.randint(0, 0x40)])
    n = r.choice([0, 1, 2, 5, r.randint(0, 8)])
    t1 = obj(c, 0x10, {0x2c: _code(c, seq, 4)})
    t2 = obj(c, 0x10, {0x2c: _code(c, seq, 2)})
    rep = obj(c, 0x10, {0x20: _code(c, seq, 2, ret=_seq([t1, t2]), this=True, pop=True)})
    c.emu.w32(0x700390, rep)
    return [me, first, n, _r(c)]


def _632(c):
    seq = Seq(c); clear_hooks(c)
    r = c.rng
    z = rnd(c, 0x40)
    v = r.choice([0, _r(c), _r(c), _r(c)])
    c.emu.w32(z + 0x20, _code(c, seq, 3, ret=v))
    c.emu.w32(z + 0x24, _code(c, seq, 2))
    bb = rnd(c, 4)
    c.emu.w32(bb, r.choice([0, 1, _r(c)]))
    loghook(c, seq, 0x632360, 10, ret=r.choice([0, -3 & 0xffffffff, -5 & 0xffffffff, -4 & 0xffffffff, 1, _r(c)]))
    return [_r(c), bb, _r(c), _r(c), z]


def _54e(c):
    seq = Seq(c); clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x6b * 10 + 0x200)
    for i in range(8):
        e = i * 0x6b
        for o in (0x2c, 0x68, 0x6a):
            c.emu.w8(me + e + o, r.choice([0, 0, 1, r.getrandbits(8)]))
    n = r.choice([-1, 0, 1, 2, 3, 4, r.randint(0, 4)])
    c.emu.w32(me + 0x1c5, n & 0xffffffff)
    cur = r.randint(0, max(n - 1, 0)) if r.random() < 0.85 else r.randint(0, 5)
    c.emu.w32(me + 8, cur)
    loghook(c, seq, 0x54e450, 0, this=True, ret=_seq([r.choice([0, 0, 1, 0x100, _r(c)]) for _ in range(6)]), calls=8)
    return [me]


def _607(c):
    seq = Seq(c); clear_hooks(c)
    r = c.rng
    dev = obj(c, 0x10, {0x5c: _code(c, seq, 6, pop=True)})
    fvf, cnt = rnd(c, 4), rnd(c, 4)
    return [rnd(c, 0x30), dev, fvf, cnt, _r(c)]


def _42c(c):
    seq = Seq(c); clear_hooks(c)
    tok = _r(c)
    log = c.emu.alloc(16, 4)

    def ctor(e, args):
        e.w32(e.reg('ecx'), tok)
    phook(c, seq, 0x4cbe80, 1, pop=True, act=ctor)

    def plus(e, args):
        e.w32(log, e.r32(args[1]))
        e.w32(args[0], e.r32(args[1]) ^ 0x5a5a)
    phook(c, seq, 0x4cc1e0, 2, this=True, pop=True, act=plus)

    def dt(e, args):
        e.w32(log + 4, e.r32(e.reg('ecx')))
        e.w32(log + 8, e.r32(log + 8) + 1)
    phook(c, seq, 0x4cbec0, 0, pop=True, act=dt)
    return [rnd(c, 0x130), rnd(c, 0x80)]


N = 'f15b009'
S(0x639bb0, 'FUN_639bb0 (set table slot, owned copy)', 'thiscall', None, ret=None, gen=_639, note=N + '; new, delete hooked, memcpy stubbed')
S(0x5365b0, 'ZDllSound::DumpObjectGroup', 'thiscall', None, ret=None, gen=_536, note=N + '; reporter, slot 0x1ec hooked')
S(0x6328b0, 'inflate_trees_bits', 'cdecl', None, ret='eax', gen=_632, note=N + '; huft_build, zalloc, zfree hooked')
S(0x54e570, 'ZSoundStreamer::Run', 'thiscall', None, ret=None, gen=_54e, note=N + '; ZSoundStream::Run hooked')
S(0x607e30, 'FUN_607e30 (vertex buffer ctor)', 'thiscall', None, ret='eax', gen=_607, note=N + '; device slot 0x5c hooked')
S(0x42c2f0, 'ZSysInterface::DataPath', 'thiscall', None, ret='eax', gen=_42c, note=N + '; MYSTR ctor, +, dtor hooked')
