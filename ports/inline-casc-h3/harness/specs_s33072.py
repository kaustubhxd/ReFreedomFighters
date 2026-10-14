"""specs_s33072.py - h3 () batch 33072."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _zeroed(c, size, head=0x100):
    e = c.emu
    a = e.alloc(size, 4)
    e.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(head)))
    return a


def _g4717f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s4 = pystub(c, 1, this=True, ret=lambda em, k: rnd(c, 0x10))
    ch = obj(c, 0x40, {4: s4})
    s4c = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    sysobj(c, table_slots={0x4c: s4c})
    me = rnd(c, 0x100)
    e.w32(me + 0x70, ch)
    mask = r.choice([0, 1, 2, 3, 5, 0x7f, 0xff, 0x80, 0x100, 0xffffffff, 0x80000001, r.getrandbits(32)])
    return [me, _w(c), mask]


def _g4d2d90(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x634d22, 3, pop=0, side=lambda em, k: em.calllog.append(('m', em.arg32(2))))
    slog = pystub(c, 3, pop=0, side=lambda em, k: em.calllog.append(('log', 1)))
    e.w32(0x700390, obj(c, 0x80, {0x24: slog}))
    ent = _zeroed(c, 0x80, 0x80)
    x = _zeroed(c, 0x40, 0x40)
    e.wbytes(x + 0x10, bytes([r.choice([0, 1, 2, 3, 0xff])]))
    e.w32(ent + 4, x)
    e.w32(ent, r.choice([0, 4, 8]))
    e.w32(ent + 8, r.choice([0, 1, 5, 0x20]))
    s0 = pystub(c, 2, this=True, ret=lambda em, k: r.choice([ent, ent, 0]))
    me = obj(c, 0x200, {0xb0: s0})
    return [me, _w(c), rnd(c, 0x40)]


def _g4f7fe0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s2dc = pystub(c, 1, this=True)
    p = obj(c, 0x300, {0x2dc: s2dc})
    s2c4 = pystub(c, 0, this=True, ret=lambda em, k: p)
    s368 = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    me = _zeroed(c, 0x400, 0x100)
    vt = e.alloc(0x400, 4)
    e.w32(vt + 0x2c4, s2c4)
    e.w32(vt + 0x368, s368)
    e.w32(me, vt)
    s58 = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    s4c = pystub(c, 3, this=True, deref={1: 1}, ret=lambda em, k: _w(c))
    sysobj(c, table_slots={0x58: s58, 0x4c: s4c})
    return [me]


def _g5004a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: rnd(c, 0x10), side=lambda em, k: em.calllog.append(('l', k)))
    hook_rec(c, 0x5002f0, 1, this=True, side=lambda em, k: em.calllog.append(('f', k)))
    s4c = pystub(c, 0, this=True, ret=lambda em, k: rnd(c, 0x20))
    rr = obj(c, 0x80, {0x4c: s4c})
    s18 = pystub(c, 1, this=True, ret=lambda em, k: r.choice([rr, rr, 0]))
    a = obj(c, 0x80, {0x18: s18})
    return [a, _w(c), rnd(c, 0x10)]


def _g534da0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s = rnd(c, 0x40)
    hook_rec(c, 0x53a9e0, 0, this=True, ret=lambda em, k: s)
    s4c = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    sysobj(c, table_slots={0x4c: s4c})
    me = _zeroed(c, 0x5300, 0x40)
    e.w32(me + 0x52fa, r.choice([_w(c), _w(c), 0]))
    return [me, _w(c), rnd(c, 0x10), r.choice([0, 1, _w(c)]), _w(c), _w(c), _w(c)]


def _g5f2f10(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 5, 40, 200])

    def side(em, k):
        buf = em.arg32(0)
        em.wbytes(buf, bytes(r.randrange(1, 256) for _ in range(n)) + b'\0')
    s64 = pystub(c, 1, this=True, nullflag=(0,), side=side)
    ch = obj(c, 0x100, {0x64: s64})
    me = _zeroed(c, 0x40, 0x40)
    e.w32(me + 0x15, ch)

    def h2(em, k):
        b = em.arg32(0)
        end = em.arg32(1)
        em.calllog.append(('r', end - b, bytes(em.rbytes(b, min(end - b, 300)))))
    hook_rec(c, 0x5f2d60, 2, this=True, nullflag=(0, 1), side=h2)
    return [me, rnd(c, 0x40)]


def _g422e60(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    sa = r.choice([True, False])
    sb = r.choice([True, False])
    hook_rec(c, 0x4cc5f0, 0, this=True, ret=lambda em, k: (1 if sa else 0) if k == 0 else (1 if sb else 0))
    hook_rec(c, 0x4235b0, 5, this=True, ret=lambda em, k: _w(c))
    hook_rec(c, 0x422ba0, 5, this=True, ret=lambda em, k: _w(c))
    return [rnd(c, 0x2600), _w(c), _w(c), _w(c), _w(c), _w(c)]


def _g461fa0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    sa = pystub(c, 2, this=True, ret=lambda em, k: _w(c))
    sb = pystub(c, 2, this=True, ret=lambda em, k: _w(c))
    vt2 = e.alloc(0x400, 4)
    e.w32(vt2 + 0x2f4, sb)
    s_swap = pystub(c, 2, this=True, side=lambda em, k: e.w32(me, vt2), ret=lambda em, k: _w(c))
    vt1 = e.alloc(0x400, 4)
    e.w32(vt1 + 0x2f4, s_swap)
    me = rnd(c, 0x80)
    e.w32(me, vt1)
    hook_rec(c, 0x4e5330, 0, this=True, ret=lambda em, k: _w(c), side=lambda em, k: e.w32(me, vt2) if k == 0 else None)
    a = rnd(c, 0x80)
    e.w32(a + 0x5c, r.choice([0, rnd(c, 0x10)]))
    e.w32(a + 0x60, r.choice([0, rnd(c, 0x10)]))
    return [me, a]


S(0x4717f0, 'GUESS mask loop table lookup store', 'thiscall', None, ret=None, gen=_g4717f0, note='batch33072')
S(0x4d2d90, 'GUESS copy blob with log if flag', 'thiscall', None, ret='eax', gen=_g4d2d90, note='batch33072')
S(0x4f7fe0, 'GUESS lookup chain with stack slot pointer', 'thiscall', None, ret=None, gen=_g4f7fe0, note='batch33072')
S(0x5004a0, 'GUESS child lookup and pair set', 'stdcall', None, ret='eax', gen=_g5004a0, note='batch33072')
S(0x534da0, 'GUESS fill record from args', 'thiscall', None, ret='al', gen=_g534da0, note='batch33072')
S(0x5f2f10, 'GUESS big stack buffer string range', 'thiscall', None, ret=None, gen=_g5f2f10, note='batch33072')
S(0x422e60, 'GUESS dispatch by sub-object tests', 'thiscall', None, ret='eax', gen=_g422e60, note='batch33072')
S(0x461fa0, 'GUESS copy two refs via vcall 2f4', 'thiscall', None, ret=None, gen=_g461fa0, note='batch33072')
