"""specs_f15b006.py - fresh slice 15 batch 6 (see src/f15b006.cpp)."""
import struct
from pilot import S, F
from sthelp import rnd, obj, stub, Seq, clear_hooks, hook, HOOKED
from f15help import phook, codeaddr, loghook


def _r(c):
    return c.rng.getrandbits(32)


def _sys(c, db=None, extra=None):
    s = rnd(c, 0x1a00)
    if db is not None:
        c.emu.w32(s + 0x9b, db)
    for k, v in (extra or {}).items():
        c.emu.w32(s + k, v)
    c.emu.w32(0x70039c, s)
    return s


def _fact(c):
    seq = Seq(c); clear_hooks(c)
    o = rnd(c, 0x60) if c.rng.random() < 0.85 else 0
    a = obj(c, 0x10, {0x44: stub(c, seq, 1, ret=o)})
    d = rnd(c, 0x10); c.emu.w32(d + 8, a)
    _sys(c, db=d)
    hook(c, seq, 0x469870, 0, ret=_r(c))
    return [_r(c)]


def _slots(c, seq, spec, writer=None):
    """object whose slots are per-call loggers at heap code addresses. spec: {slot: nargs}."""
    sl = {}
    for off, n in spec.items():
        a = codeaddr(c)
        if writer and off in writer:
            phook(c, seq, a, n, this=True, pop=True, act=writer[off])
            loga = a
        else:
            loghook(c, seq, a, n, this=True, pop=True, calls=8)
        sl[off] = a
    return obj(c, 0x20, sl)


def _4a3(c):
    seq = Seq(c); clear_hooks(c)
    vals = [_r(c) for _ in range(8)]
    k = [0]
    log = c.emu.alloc(4 * 16, 4)

    def put(e, args):     # every pointer slot writes a fresh value through its pointer and logs the target offset
        e.w32(args[0], vals[k[0] % 8])
        e.w32(log + 4 * k[0], (args[0] - me) & 0xffffffff if not (0x0fe00000 <= args[0] < 0x0ff00000) else 0x5c5c)
        k[0] += 1
    me = rnd(c, 0x140)
    lg = _slots(c, seq, {0x40: 1, 0x6c: 1, 0x50: 1}, writer={0x40: put, 0x6c: put, 0x50: put})
    d = obj(c, 0x10, {0x58: loghook_addr(c, seq, 1, ret=_r(c))})
    _sys(c, db=d)
    return [me, lg]


def loghook_addr(c, seq, n, ret=0):
    a = codeaddr(c)
    loghook(c, seq, a, n, ret=ret, this=True, pop=True, calls=8)
    return a


def _4c2(c):
    seq = Seq(c); clear_hooks(c)
    sg = _slots(c, seq, {0x44: 1, 0x3c: 1, 0x60: 1, 0x4c: 1})
    return [rnd(c, 0x70), sg]


def _5ef(c):
    seq = Seq(c); clear_hooks(c)
    hook(c, seq, 0x5ee970, 1, ret=_r(c))
    sg = _slots(c, seq, {0x3c: 1, 0x60: 1, 0x4c: 1})
    return [rnd(c, 0xa0), sg]


def _569(c):
    seq = Seq(c); clear_hooks(c)
    me = rnd(c, 0x1d0)
    vlog = c.emu.alloc(16, 4)
    k = [0]

    def seen(e):        # record the object's vtable word at each delete (the 0x6a7600 store must be in place)
        e.w32(vlog + 4 * (k[0] % 4), e.r32(me)); k[0] += 1
        return 0
    loghook(c, seq, 0x634273, 2, ret=seen)
    d = obj(c, 0x40, {0x34: stub(c, seq, 1, ret=_r(c))})
    _sys(c, db=d)
    return [me]


def _650(c):
    seq = Seq(c); clear_hooks(c)
    r = c.rng
    loghook(c, seq, 0x634273, 2)
    hook(c, seq, 0x640ea0, 0, ret=_r(c))
    me = obj(c, 0x90, {0x9c: stub(c, seq, 1)})
    c.emu.w32(me + 0x38, rnd(c, 0x40) if r.random() < 0.6 else 0)
    o = obj(c, 0x60, {0x44: stub(c, seq, 2)}) if r.random() < 0.8 else 0
    c.emu.w8(me + 0x88, r.choice([0, 1, 0x80]) if o else 0)
    _sys(c, extra={0x190f: o})
    return [me]


def _452(c):
    seq = Seq(c); clear_hooks(c)
    r = c.rng
    m, m2 = rnd(c, 0x10), rnd(c, 0x10)
    n = r.randint(0, 4)
    objs, toks = [], {}
    for i in range(n):
        objs.append(None)
    me = None
    # list: s_i with [s+8] = token; manager slot 0x25c(name, prev) returns the object whose predecessor token is prev
    chain = {}
    prev = 0
    for i in range(n):
        s = obj(c, 0x20, {0x20: stub(c, seq, 0, ret=r.choice([m, m, m2]))})
        c.emu.w32(s + 0x18, r.choice([0x4000, 0x8000, 0xc000, 0, _r(c)]))
        tok = _r(c) | 1
        c.emu.w32(s + 8, tok)
        chain[prev] = s
        prev = tok
    lg = c.emu.alloc(4 * 20, 4)
    cnt = [0]
    a25c = codeaddr(c)

    def nxt(e, args):
        e.w32(lg + 4 * (cnt[0] % 20), args[1])
        cnt[0] += 1
        return chain.get(args[1], 0)
    phook(c, seq, a25c, 2, this=True, pop=True, act=nxt)
    mgr = obj(c, 0x10, {0x25c: a25c})
    me = obj(c, 0x40, {0x20: stub(c, seq, 0, ret=mgr)})
    c.emu.w32(me + 0x18, r.choice([0, 0, 0x4000, 0x8000, _r(c)]))
    # objects compare their own slot 0x20 to mgr (sometimes equal)
    for s in chain.values():
        if r.random() < 0.6:
            vt = c.emu.r32(s)
            c.emu.w32(vt + 0x20, stub(c, seq, 0, ret=mgr))
    return [me]


def _64f(c):
    seq = Seq(c); clear_hooks(c)
    r = c.rng
    n = r.randint(0, 4)
    items = [_r(c) for _ in range(n + 1)]
    known = [r.choice([0, 1]) for _ in range(n + 1)]
    lg = c.emu.alloc(4 * 24, 4)
    k = [0]

    def init(e, args):
        e.w32(args[0], n); e.w32(args[0] + 4, 0)

    def nx(e, args):
        i = e.r32(args[0] + 4)
        e.w32(args[0] + 4, i + 1)
        e.w32(args[0], n - i)
        return items[min(i, n)]

    def rem(e, args):
        e.w32(lg + 4 * (k[0] % 24), e.r32(args[0] + 4)); k[0] += 1
    a4c, a5c, a44 = codeaddr(c), codeaddr(c), codeaddr(c)
    phook(c, seq, a4c, 1, this=True, pop=True, act=init)
    phook(c, seq, a5c, 1, this=True, pop=True, act=nx)
    phook(c, seq, a44, 1, this=True, pop=True, act=rem)
    C = obj(c, 0x40, {0x4c: a4c, 0x5c: a5c, 0x44: a44, 0x30: stub(c, seq, 1, ret=_r(c))})
    a58 = codeaddr(c)
    phook(c, seq, a58, 1, this=True, pop=True, act=lambda e, a: known[items.index(a[0])] if a[0] in items else 0)
    _sys(c, db=obj(c, 0x60, {0x58: a58}))
    me = rnd(c, 0x90)
    c.emu.w32(me + 0x8c, C)
    return [me, _r(c)]


N = 'f15b006'
S(0x4bee70, 'FUN_4bee70 (factory, vt 0x6934dc)', 'thiscall', None, ret='eax', gen=_fact, note=N + '; base ctor hooked')
S(0x5bdbf0, 'FUN_5bdbf0 (factory, vt 0x6b34b4)', 'thiscall', None, ret='eax', gen=_fact, note=N + '; base ctor hooked')
S(0x4a3a30, 'ZSoundMove::Load', 'thiscall', None, ret='al', gen=_4a3, note=N + '; load slots Python')
S(0x4c26b0, 'ZMusicSegment::Save', 'thiscall', None, ret='al', gen=_4c2, note=N)
S(0x5efe70, 'CMessageHint::Save', 'thiscall', None, ret=None, gen=_5ef, note=N + '; CMessageTextBox::Save hooked')
S(0x569730, 'FUN_569730 (dtor body, vt 0x6a7600)', 'thiscall', None, ret=None, gen=_569, note=N + '; delete hooked')
S(0x6503b0, 'ZRenderBaseDll::PopScene', 'thiscall', None, ret=None, gen=_650, note=N + '; 0x640ea0, delete hooked')
S(0x452b30, 'ZENVIRONMENT::ClassInit', 'thiscall', None, ret=None, gen=_452, note=N + '; manager walk Python')
S(0x64faf0, 'ZRender::GetCamera', 'thiscall', None, ret='eax', gen=_64f, note=N + '; iterator slots Python')
