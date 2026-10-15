"""specs_s33073.py - h3 (Sonnet) batch 33073."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _zeroed(c, size, head=0x100):
    e = c.emu
    a = e.alloc(size, 4)
    e.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(head)))
    return a


def _g4b3460(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x44b610, 0, this=True, side=lambda em, k: em.calllog.append(('o', 1)))
    hook_rec(c, 0x44b740, 1, pop=0, side=lambda em, k: em.calllog.append(('o', 2)))
    s60 = pystub(c, 1, this=True, ret=lambda em, k: r.choice([rnd(c, 0x20), 0]))
    sysobj(c, table_slots={0x60: s60})
    sa0 = pystub(c, 0, this=True, side=lambda em, k: em.calllog.append(('v', 0xa0, em.rbytes(me + 0x182, 1)[0])))
    me = _zeroed(c, 0x190, 0x190)
    vt = e.alloc(0x200, 4)
    e.w32(vt + 0xa0, sa0)
    e.w32(me, vt)
    v70 = r.getrandbits(16)
    v72 = r.choice([v70, r.getrandbits(16)])
    e.wbytes(me + 0x70, v70.to_bytes(2, 'little'))
    e.wbytes(me + 0x72, v72.to_bytes(2, 'little'))
    e.wbytes(me + 0x182, bytes([r.choice([0, 1])]))
    e.wbytes(me + 0x184, bytes([r.choice([0, 1])]))
    a = r.choice([v70, v70, v72, v70 | (r.getrandbits(16) << 16), _w(c)])
    return [me, a, _w(c)]


def _g4cf410(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    slog = pystub(c, 2, pop=0, ret=lambda em, k: _w(c), side=lambda em, k: em.calllog.append(('log', 1)))
    robj = obj(c, 0x80, {0x2c: slog})
    s20 = pystub(c, 2, this=True, ret=lambda em, k: robj)
    e.w32(0x700390, obj(c, 0x80, {0x20: s20}))
    me = rnd(c, 0x40)
    e.w32(me + 0xc, r.choice([0, 5, 0xffffffff, 0x80000000]))
    e.w32(me + 0x18, r.choice([0, 1, 2, 3]))
    e.w32(me + 0x20, r.choice([0, _w(c) & ~3, _w(c) & ~3]))
    a = rnd(c, 0x10)
    inner = rnd(c, 0x10)
    e.w32(inner, r.choice([0, _w(c)]))
    e.w32(a, r.choice([0, inner]))
    return [me, a]


def _g4dabe0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4d9f90, 0, this=True, side=lambda em, k: em.calllog.append(('o', 9)))
    s31c = pystub(c, 1, this=True, side=lambda em, k: em.calllog.append(('r', 0x31c)))
    rr = obj(c, 0x400, {0x31c: s31c})
    hook_rec(c, 0x4daff0, 0, this=True, ret=lambda em, k: r.choice([rr, rr, 0]))
    sub = rnd(c, 0x20)
    x = rnd(c, 0x20)
    e.w32(x + 8, _w(c))
    p = rnd(c, 0x80)
    e.w32(p + 0x54, x)
    me = _zeroed(c, 0x80, 0x80)
    e.w32(me + 0x50, r.choice([p, 0]))
    low = r.choice([0, 1, 0x80, 0xff])
    flags = (low | (r.choice([0, 0x4000]) << 0) | (r.getrandbits(8) << 8) & 0xbf00)
    e.w32(me + 0x3c, flags | (0x4000 if r.random() < 0.5 else 0))
    e.wbytes(me + 0x5c, r.choice([0, 1, 0x1234]).to_bytes(2, 'little'))
    tgt = _zeroed(c, 0x40, 0x40)
    s5c = pystub(c, 1, this=True, ret=lambda em, k: r.choice([tgt, 0]))
    so = sysobj(c)
    tab = e.r32(so + 0x9b)
    e.w32(tab + 8, obj(c, 0x80, {0x5c: s5c}))
    return [me]


def _g52b020(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def mk(addr, tag):
        def side(em, k):
            o = em.arg32(0)
            em.w32(o, _w(c))
            em.w32(o + 4, _w(c))
            em.calllog.append((tag, em.reg('ecx')))
        hook_rec(c, addr, 2, this=True, nullflag=(0,), side=side)
    mk(0x530b60, 't1')
    mk(0x530db0, 't2')
    hook_rec(c, 0x52e4f0, 3, this=True, deref={0: 2, 1: 2})
    me = _zeroed(c, 0x80, 0x80)
    e.w32(me + 0x65, rnd(c, 0x20))
    return [me, _w(c), _w(c), _w(c)]


def _g5a4690(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s = pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, 1, 0x100, 0x101]))
    a = obj(c, 0x100, {0x1e0: s})
    p = rnd(c, 0x20)
    e.w32(p + 4, r.choice([2, 3, 4, 5, 9, 10, 11, 0, 1, 0xffffffff, 0x7fffffff, 0x80000000]))
    e.w32(a + 0x54, r.choice([p, p, p, 0]))
    return [rnd(c, 0x100), r.choice([a, a, a, 0])]


def _g5b96d0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s3c = pystub(c, 1, this=True, side=lambda em, k: em.calllog.append(('v', 0x3c, em.arg32(0))))
    s64 = pystub(c, 1, this=True, side=lambda em, k: em.calllog.append(('v', 0x64, em.arg32(0))))
    a = obj(c, 0x100, {0x3c: s3c, 0x64: s64})
    me = rnd(c, 0x80)
    e.w32(me + 4, _w(c))
    return [me, a]


def _g5fb920(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    blk = _zeroed(c, 0x20, 0x20)
    hook_rec(c, 0x41e290, 1, pop=0, ret=lambda em, k: blk)
    fn = e.r32(0x6b8508 + 0xc)
    hook_rec(c, fn, 1, this=True, side=lambda em, k: em.calllog.append(('v', em.r32(em.reg('ecx')), em.r32(em.reg('ecx') + 4), em.rbytes(em.reg('ecx') + 0x14, 1)[0])))
    hook_rec(c, 0x603110, 0, this=True, ret=lambda em, k: _w(c))
    hook_rec(c, 0x6031e0, 1, this=True)
    me = rnd(c, 0x20)
    e.w32(me, rnd(c, 0x20))
    return [me]


def _g4572d0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x634273, 2, pop=0, side=lambda em, k: em.calllog.append(('d', em.arg32(1), em.r32(me + 0x84))))
    hook_rec(c, 0x451a00, 0, this=True, side=lambda em, k: em.calllog.append(('o', em.r32(me))))
    hook_rec(c, 0x45c510, 1, pop=0, side=lambda em, k: em.calllog.append(('f', 1)))
    hook_rec(c, 0x4690b0, 2, pop=0, side=lambda em, k: em.calllog.append(('f', 2)))
    me = rnd(c, 0x90)
    en = rnd(c, 0x10)
    e.w32(me + 0x84, r.choice([en, 0]))
    return [me, r.choice([0, 1, 4, 5, 2, 0xff, _w(c)])]


S(0x4b3460, 'GUESS id match flag clear and release', 'thiscall', None, ret='eax', gen=_g4b3460, note='batch33073')
S(0x4cf410, 'GUESS pointer chase with log on negative', 'thiscall', None, ret='eax', gen=_g4cf410, note='batch33073')
S(0x4dabe0, 'GUESS notify and clear linked field', 'thiscall', None, ret=None, gen=_g4dabe0, note='batch33073')
S(0x52b020, 'GUESS two output temps then combine', 'thiscall', None, ret=None, gen=_g52b020, note='batch33073')
S(0x5a4690, 'GUESS slot address by kind', 'thiscall', None, ret='eax', gen=_g5a4690, note='batch33073')
S(0x5b96d0, 'GUESS six vcalls on arg', 'thiscall', None, ret='al', gen=_g5b96d0, note='batch33073')
S(0x4572d0, 'GUESS dtor flags dispatch d9 with block', 'thiscall', None, ret='eax', gen=_g4572d0, note='batch33073')
S(0x5fb920, 'GUESS new object then init via exe slot', 'thiscall', None, ret='eax', gen=_g5fb920, note='batch33073')
