"""specs_f15b010.py - fresh slice 15 batch 10 (see src/f15b010.cpp)."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, hook, HOOKED
from f15help import phook, codeaddr, loghook


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


def _watch(c, addrs, ret=0):
    """ret callable that snapshots the words at `addrs` into a ring on each call (state seen by the callee)."""
    log = c.emu.alloc(4 * len(addrs) * 8, 4)
    k = [0]

    def f(e):
        for i, a in enumerate(addrs):
            e.w32(log + 4 * (len(addrs) * (k[0] % 8) + i), e.r32(a))
        k[0] += 1
        return ret(e) if callable(ret) else ret
    return f


def _5f1(c):
    seq = Seq(c); clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x40)
    c.emu.w32(me + 0xc, rnd(c, 0xc0) if r.random() < 0.7 else 0)
    w = _watch(c, [me, 0x7143ac])
    loghook(c, seq, 0x5f1370, 0, this=True, ret=w)
    loghook(c, seq, 0x634273, 2, ret=w)
    loghook(c, seq, 0x604d30, 0, ret=w)
    loghook(c, seq, 0x6038e0, 0, ret=w)
    loghook(c, seq, 0x4e66a0, 0, this=True, ret=w)
    return [me, r.choice([0, 1, 2, 3, _r(c)])]


def _blk(c, r):
    b = rnd(c, 0x90)
    c.emu.w16(b + 2, r.choice([0xffff, 0xffff, 0, 1, r.randint(0, 6)]))
    for i in range(8):
        c.emu.w16(b + 16 * (i + 1), r.choice([0xffff, r.randint(0, 6)]))
    return b


def _63a(c):
    seq = Seq(c); clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x20)
    n = r.choice([0, 1, 2, 3, 4])
    bl = [_blk(c, r) for _ in range(n)]
    for i, b in enumerate(bl):
        nx = bl[(i + 1) % n] if (i + 1 < n or r.random() < 0.6) else 0
        c.emu.w32(b + 8, nx)
    c.emu.w32(me + 8, bl[r.randint(0, n - 1)] if n else 0)
    nb = _blk(c, r)

    def grow(e, args):
        if r.random() < 0.5:
            e.w32(me + 8, nb)
    phook(c, seq, 0x63b240, 0, this=True, ret=r.choice([0, 1, 0x100, _r(c)]), act=grow)
    return [me]


def _4a3(c):
    seq = Seq(c); clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x130)
    left = [r.choice([0, 1, 2, 3, 5, 8])]

    def first(e):
        e.w32(e.r32(e.reg('esp') + 4), _r(c) if left[0] else 0)
        return _r(c)

    def nxt(e):
        it = e.r32(e.reg('esp') + 4)
        if e.r32(it):
            left[0] -= 1
        e.w32(it, (_r(c) | 1) if left[0] > 0 else 0)
        return _r(c)
    vt = c.emu.alloc(0x60, 4)
    c.emu.w32(vt + 0x4c, _code(c, seq, 1, ret=first, this=True, pop=True))
    c.emu.w32(vt + 0x5c, _code(c, seq, 1, ret=nxt, this=True, pop=True, calls=12))
    c.emu.w32(me + 0x78, vt)
    c.emu.w32(me + 0x128, r.choice([0, 1, 2, 4, r.randint(0, 9), 0x7fffffff, 0xfffffffe]))
    c.emu.w32(me + 0x124, r.choice([0, 1, 3, 5, r.randint(0, 9), 0x80000000 | r.randint(0, 9)]))
    o = rnd(c, 0x10)
    s = rnd(c, 0x200); c.emu.w32(0x70039c, s)
    c.emu.w32(s + 0x9b, obj(c, 0x60, {0x58: _code(c, seq, 1, ret=o, this=True, pop=True, calls=12)}))
    loghook(c, seq, 0x4db500, 1, this=True, pop=True)
    return [me, _r(c)]


def _node(c, k, val):
    n = rnd(c, 0x18)
    c.emu.w32(n + 5, 0); c.emu.w32(n + 9, 0)
    c.emu.w32(n + 0xd, k); c.emu.w32(n + 0x11, val)
    return n


def _5ff(c):
    seq = Seq(c); clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x130)
    head = rnd(c, 0x18)
    c.emu.w32(me + 0x121, head)
    keys = sorted(r.sample(range(0, 40), r.randint(0, 6)))
    nodes = []
    for k in keys:
        m = rnd(c, 0x10)
        nodes.append(_node(c, k, m))

    def build(lo, hi):
        if lo >= hi:
            return 0
        mid = (lo + hi) // 2
        n = nodes[mid]
        c.emu.w32(n + 5, build(lo, mid)); c.emu.w32(n + 9, build(mid + 1, hi))
        return n
    c.emu.w32(head + 1, build(0, len(nodes)))
    k1 = r.choice(keys + [r.randint(0, 45)]) if keys else r.randint(0, 45)
    klog = c.emu.alloc(16, 4)
    kl = [0]

    def find(e, args):
        m = e.reg('ecx')
        end = e.r32(m)
        kl[0] += 1
        e.w32(klog + 4 * (kl[0] % 4), e.r32(args[1]))
        k = r.random()
        node = end if k < 0.4 else rnd(c, 0x14)
        e.w32(args[0], node)
        return args[0]
    phook(c, seq, 0x5ff0f0, 2, this=True, pop=True, act=find)
    c.emu.w32(0x7003b0, _code(c, seq, 0, ret=_r(c)))
    return [me, k1, r.choice([0, 1, _r(c)])]


def _607(c):
    seq = Seq(c); clear_hooks(c)
    r = c.rng
    me = obj(c, 0x20, {0x68: _code(c, seq, 0, this=True)})
    c.emu.w32(me + 0x18, r.choice([0, 0, _r(c)]))
    loghook(c, seq, 0x41e290, 1, ret=rnd(c, 4) if r.random() < 0.85 else 0)
    loghook(c, seq, 0x607c80, 1, this=True, pop=True, ret=_r(c))
    s = rnd(c, 0x1a00); c.emu.w32(0x70039c, s)
    c.emu.w32(s + 0x190f, obj(c, 0x10, {0x294: _code(c, seq, 0, this=True)}) if r.random() < 0.7 else 0)
    loghook(c, seq, 0x64fe80, 2, this=True, pop=True, ret=_r(c))
    return [me, _r(c), _r(c)]


def _4c2(c):
    seq = Seq(c); clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x80)
    c.emu.w8(me + 0x72, r.choice([0, 1, 0x80]))

    def geth(e):
        e.w32(e.r32(e.reg('esp') + 8), _r(c))
        return _r(c)
    o = obj(c, 0x90, {0x88: _code(c, seq, 2, ret=geth, this=True, pop=True)})
    tgt = obj(c, 0x140, {0x130: _code(c, seq, 3, this=True, pop=True)}) if r.random() < 0.7 else 0
    d = obj(c, 0x140, {0x138: _code(c, seq, 0, ret=o, this=True),
                        0x58: _code(c, seq, 1, ret=tgt, this=True, pop=True),
                        0x114: _code(c, seq, 4, ret=_r(c), this=True, pop=True)})
    s = rnd(c, 0x200); c.emu.w32(0x70039c, s); c.emu.w32(s + 0x9b, d)
    return [me]


def _604(c):
    seq = Seq(c); clear_hooks(c)
    r = c.rng
    a = rnd(c, 0x10)
    op = rnd(c, 4); c.emu.w8(op, r.choice([ord('!'), ord('!'), ord('='), r.getrandbits(8)]))
    c.emu.w32(a, op)
    vals = [rnd(c, 0x10) for _ in range(2)]
    outs = [rnd(c, 4) for _ in range(3)]
    for i in range(2):
        c.emu.w32(outs[i], vals[i])
    k = [0]

    def arg(e):
        v = outs[k[0] % 3]; k[0] += 1
        return v
    loghook(c, seq, 0x5003d0, 1, this=True, pop=True, ret=arg)
    log = c.emu.alloc(4 * 13, 4)
    rv = [r.choice([0, 0, 1, -1 & 0xffffffff, _r(c)]) for _ in range(2)]
    n = [0]

    def cmp(e, rr):
        i = n[0]; n[0] += 1
        if i < 6:
            e.w32(log + 8 * i, e.arg32(0)); e.w32(log + 8 * i + 4, e.arg32(1))
        e.w32(log + 48, n[0])
        e.ret(eax=rv[min(i, 1)])
    c.emu.stub_import('_stricmp', cmp)

    def put(e, args):
        e.w32(log + 44, e.r32(args[0]))
    phook(c, seq, 0x50d7b0, 1, this=True, pop=True, act=put)
    return [a]


def _4f4(c):
    seq = Seq(c); clear_hooks(c)
    r = c.rng
    loghook(c, seq, 0x45c4f0, 2, ret=rnd(c, 0xb8) if r.random() < 0.85 else 0)
    loghook(c, seq, 0x4ee1b0, 3, this=True, pop=True)
    return [_r(c), _r(c), _r(c), _r(c)]


N = 'f15b010'
S(0x5f14f0, 'ZScriptDll::~ZScriptDll (deleting)', 'thiscall', None, ret='eax', gen=_5f1, note=N + '; callees hooked')
S(0x63afb0, 'ZDrawArray<ZTextureDrawEntry>::Add', 'thiscall', None, ret='eax', gen=_63a, note=N + '; grow 0x63b240 hooked')
S(0x4a3670, 'ZSoundMove::GetNextPos', 'thiscall', None, ret=None, gen=_4a3, note=N + '; list slots, db, GetPos hooked')
S(0x5ffd70, 'FUN_5ffd70 (two-level map lookup)', 'thiscall', None, ret='eax', gen=_5ff, note=N + '; find 0x5ff0f0, [0x7003b0] hooked')
S(0x607930, 'ZRenderGCDll::InstallPrimBuffer', 'thiscall', None, ret='eax', gen=_607, note=N + '; new, ctor, base hooked')
S(0x4c2570, 'ZSoundSegment::RemoveText', 'thiscall', None, ret=None, gen=_4c2, note=N + '; db slots hooked')
S(0x604d70, 'FUN_604d70 (string compare native)', 'stdcall', None, ret=None, gen=_604, note=N + '; arg 0x5003d0, set 0x50d7b0 hooked, _stricmp Python')
S(0x4f42f0, 'FUN_4f42f0 (fastcall factory)', 'fastcall', None, ret='eax', gen=_4f4, note=N + '; alloc 0x45c4f0, ctor 0x4ee1b0 hooked')
