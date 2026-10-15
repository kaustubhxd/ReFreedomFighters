"""specs_s33074.py - h3 (Sonnet) batch 33074."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _zeroed(c, size, head=0x100):
    e = c.emu
    a = e.alloc(size, 4)
    e.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(head)))
    return a


def _g47fd70(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x634273, 2, pop=0, side=lambda em, k: em.calllog.append(('d', em.arg32(1), em.r32(me + 0x8c))))
    hook_rec(c, 0x43de70, 0, this=True, side=lambda em, k: em.calllog.append(('o', em.r32(me))))
    hook_rec(c, 0x45c510, 1, pop=0, side=lambda em, k: em.calllog.append(('f', 1)))
    hook_rec(c, 0x4690b0, 2, pop=0, side=lambda em, k: em.calllog.append(('f', 2)))
    me = rnd(c, 0x90)
    en = rnd(c, 0x10)
    e.w32(me + 0x8c, r.choice([en, 0]))
    return [me, r.choice([0, 1, 4, 5, 2, 0xff, _w(c)])]


def _g4b3a00(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x44b610, 0, this=True, side=lambda em, k: em.calllog.append(('o', 1)))
    hook_rec(c, 0x44b740, 1, pop=0, side=lambda em, k: em.calllog.append(('o', 2)))
    s60 = pystub(c, 1, this=True, ret=lambda em, k: r.choice([rnd(c, 0x20), 0]))
    sysobj(c, table_slots={0x60: s60})
    sa0 = pystub(c, 0, this=True, side=lambda em, k: em.calllog.append(('v', 0xa0, em.r32(me + 0x8d))))
    s68 = pystub(c, 2, this=True)
    me = _zeroed(c, 0x120, 0x120)
    vt = e.alloc(0x200, 4)
    e.w32(vt + 0xa0, sa0)
    e.w32(vt + 0x68, s68)
    e.w32(me, vt)
    v = r.getrandbits(16)
    e.wbytes(me + 0x115, v.to_bytes(2, 'little'))
    e.wbytes(me + 0x84, bytes([r.choice([0, 1, 0x80])]))
    a = r.choice([v, v, v | (r.getrandbits(16) << 16), _w(c)])
    return [me, a, _w(c)]


def _g4e80f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    val = r.choice([0, 1, 5, 0x7fffffff, 0xffffffff, 0x80000000, _w(c)])
    s1c = pystub(c, 1, this=True, side=lambda em, k: em.calllog.append(('v', em.arg32(0))), ret=lambda em, k: r.choice([0, 1, 5, 0x7fffffff, 0xffffffff, 0x80000000, _w(c)]))
    me = obj(c, 0x40, {0x1c: s1c})
    own = _w(c)
    e.w32(me + 8, own)
    b = rnd(c, 0x10)
    e.w32(b + 4, r.choice([own, _w(c)]))
    e.w32(b + 8, r.choice([own, _w(c)]))
    e.w32(me + 4, b)
    return [me, r.choice([b, b, 0])]


def _g576560(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5764c0, 0, this=True)
    hook_rec(c, 0x5769c0, 0, this=True)
    hook_rec(c, 0x574200, 1, this=True, ret=lambda em, k: _w(c))
    sd8 = pystub(c, 0, this=True, ret=lambda em, k: r.choice([0, 0, 1, 0x100, 0x101]))
    me = obj(c, 0x100, {0xd8: sd8})
    return [me, r.choice([0, 1, 2, 3, 0xffffffff, _w(c)])]


def _g5a0050(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    vals = [_w(c) | 1 for _ in range(3)] + [0]
    v = r.choice(vals)
    s58 = pystub(c, 1, this=True, ret=lambda em, k: v)
    sysobj(c, table_slots={0x58: s58})
    s504 = pystub(c, 0, this=True, side=lambda em, k: em.calllog.append(('c', 504)), ret=lambda em, k: r.choice([v, vals[1]]))
    s500 = pystub(c, 0, this=True, side=lambda em, k: em.calllog.append(('c', 500)), ret=lambda em, k: r.choice([v, vals[2]]))
    me = obj(c, 0x600, {0x504: s504, 0x500: s500})
    return [me, _w(c)]


def _g5ed170(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x5ec190, 1, this=True, side=lambda em, k: em.calllog.append(('c', 1)))
    s68 = pystub(c, 1, this=True, side=lambda em, k: em.calllog.append(('c', 2)))
    s3c = pystub(c, 1, this=True)
    s10 = pystub(c, 2, this=True, side=lambda em, k: em.calllog.append(('e', k)))
    a = obj(c, 0x100, {0x68: s68, 0x3c: s3c, 0x10: s10})
    me = _zeroed(c, 0xe0, 0xe0)
    n = r.choice([0, 1, 2, 4])
    arr = rnd(c, 0x20)
    e.w32(me + 0xcb, arr)
    e.w32(me + 0xcf, arr + 4 * n)
    return [me, a]


def _g63b6a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def alloc(em, k):
        if r.random() < 0.15:
            return 0
        size = em.arg32(0)
        base = e.alloc(size + 0x3000, 4)
        if r.random() < 0.6:
            return ((base + 0xfff) & ~0xfff) + 0xff0 + 4 * r.randrange(0, 4)
        return base
    s0 = pystub(c, 1, this=True, ret=alloc)
    ch = obj(c, 0x40, {0: s0})
    me = _zeroed(c, 0x40, 0x40)
    e.w32(me + 0x14, ch)
    e.w32(me + 0x1c, r.choice([0, 1, 2, 3]))
    return [me]


def _g650040(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x42ab62, 2, pop=0)
    s64 = pystub(c, 0, this=True)
    s1c = pystub(c, 0, this=True, ret=lambda em, k: r.choice([0, 0x31fff, 0x32000, 0x32001, 0x40000, 0x7fffffff, 0xffffffff, 0x80000000, _w(c)]))
    s20 = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    ch = obj(c, 0x200, {0x64: s64, 0x1c: s1c, 0x20: s20})
    s40 = pystub(c, 0, this=True)
    me = _zeroed(c, 0xc4, 0xc4)
    vt = e.alloc(0x100, 4)
    e.w32(vt + 0x40, s40)
    e.w32(me, vt)
    e.w32(me + 0xbd, ch)
    return [me, rnd(c, 8)]


S(0x47fd70, 'GUESS dtor flags dispatch 90 with block', 'thiscall', None, ret='eax', gen=_g47fd70, note='batch33074')
S(0x4b3a00, 'GUESS id match release and vcalls', 'thiscall', None, ret='eax', gen=_g4b3a00, note='batch33074')
S(0x4e80f0, 'GUESS max of two slot 1c results', 'thiscall', None, ret='eax', gen=_g4e80f0, note='batch33074')
S(0x576560, 'GUESS state check then by-kind calls', 'thiscall', None, ret='al', gen=_g576560, note='batch33074')
S(0x5a0050, 'GUESS match lookup against two ids', 'thiscall', None, ret='al', gen=_g5a0050, note='batch33074')
S(0x5ed170, 'GUESS describe list to arg', 'thiscall', None, ret=None, gen=_g5ed170, note='batch33074')
S(0x63b6a0, 'GUESS allocate paged block', 'thiscall', None, ret='eax', gen=_g63b6a0, note='batch33074')
S(0x650040, 'GUESS compute offset and store', 'thiscall', None, ret='eax', gen=_g650040, note='batch33074')
