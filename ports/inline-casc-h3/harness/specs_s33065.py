"""specs_s33065.py - h3 () batch 33065."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _zeroed(c, size, head=0x100):
    e = c.emu
    a = e.alloc(size, 4)
    e.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(head)))
    return a


def _g5f95a0(c):
    clear_hooks(c)
    e = c.emu
    s2c = pystub(c, 1, this=True, side=lambda em, k: em.calllog.append(('v', 0x2c)))
    s40 = pystub(c, 1, this=True, side=lambda em, k: em.calllog.append(('v', 0x40)))
    a = obj(c, 0x80, {0x2c: s2c, 0x40: s40})
    hook_rec(c, 0x6060a0, 2, this=True, side=lambda em, k: em.calllog.append(('h', k)))
    return [rnd(c, 0x60), a]


def _g467060(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x466290, 2, this=True, ret=lambda em, k: _w(c))
    hook_rec(c, 0x466f60, 1, this=True, ret=lambda em, k: _w(c))
    s60 = pystub(c, 1, this=True, ret=lambda em, k: r.choice([rnd(c, 0x80), rnd(c, 0x80), 0]))
    sysobj(c, table_slots={0x60: s60})
    return [rnd(c, 0x40), _w(c), _w(c), r.choice([0, 1, 0x100, 0x1ff])]


def _g4fa180(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4db9a0, 1, this=True, ret=lambda em, k: r.choice([0, 1, 0x100, 0x101]))
    s = pystub(c, 1, this=True)
    child = _zeroed(c, 0x100, 0x30)
    vt = e.alloc(0x200, 4)
    e.w32(vt + 0xbc, s)
    e.w32(child, vt)
    e.wbytes(child + 0x21, bytes([r.choice([0, 1, 2, 0x80, 0xff, 0x81, 0x7f])]))
    b = _zeroed(c, 0x80, 0x30)
    e.w32(b + 0x54, child)
    return [r.choice([0, 1, 2, 0x80, 0xff, 0x181, _w(c)]), b]


def _g506040(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    slog = pystub(c, 3, pop=0, ret=lambda em, k: _w(c))
    robj = obj(c, 0x80, {0x2c: slog})
    s20 = pystub(c, 2, this=True, ret=lambda em, k: robj)
    e.w32(0x700390, obj(c, 0x80, {0x20: s20}))

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    s34 = pystub(c, 0, this=True, ret=lambda em, k: _w(c))
    inner = obj(c, 0x80, {0x34: s34})
    me = rnd(c, 0x40)
    e.w32(me, inner)
    e.wbytes(me + 4, bytes([r.choice([3, 4, 4, 0, 1, 5, 0xff])]))
    return [me]


def _g520360(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x511a00, 0, this=True, side=lambda em, k: em.calllog.append(('o', 1)))
    hook_rec(c, 0x512070, 0, this=True, side=lambda em, k: em.calllog.append(('o', 2)))
    hook_rec(c, 0x45c510, 1, pop=0, side=lambda em, k: em.calllog.append(('f', 1)))
    hook_rec(c, 0x4690b0, 2, pop=0, side=lambda em, k: em.calllog.append(('f', 2)))
    return [rnd(c, 0x330), r.choice([0, 1, 4, 5, 2, 0xff, _w(c)])]


def _g54cda0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 2, 5, 0xffffffff, 0x80000000])
    hook_rec(c, 0x41e290, 1, pop=0, ret=lambda em, k: rnd(c, 0x40))
    s40 = pystub(c, 0, this=True, ret=lambda em, k: _w(c))
    me = _zeroed(c, 0x8100, 0x40)
    vt = e.alloc(0x100, 4)
    e.w32(vt + 0x40, s40)
    e.w32(me, vt)
    e.w32(me + 0x805d, n)
    return [me]


def _g593ee0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = _zeroed(c, 0xa00, 0x40)
    e.wbytes(me + 0x9e7, bytes([r.choice([0, 1, 0x80])]))

    def side(em, k):
        if r.random() < 0.7:
            em.w32(em.arg32(1), _w(c))
    s88 = pystub(c, 2, this=True, nullflag=(1,), side=side)
    p = obj(c, 0x200, {0x88: s88})
    s138 = pystub(c, 0, this=True, ret=lambda em, k: p)
    sysobj(c, table_slots={0x138: s138})
    hook_rec(c, 0x5e9300, 1, this=True)
    hook_rec(c, 0x4748b0, 1, this=True, ret=lambda em, k: _w(c))
    return [me, _w(c)]


def _g4382e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    me = _zeroed(c, 0x1220, 0x40)
    mode = r.choice(['free', 'free', 'none', 'free', 'free'])
    k = r.choice([r.randrange(0, 8), 0x1ff, 0x1ff, 0x1fe])
    for i in range(0x200):
        slot = me + 8 + 9 * i
        if mode == 'free' and i == k:
            e.w32(slot, 0)
            e.wbytes(slot + 4, bytes([r.getrandbits(8)]))
            e.w32(slot + 5, 0)
        elif mode == 'free' and i > k and r.random() < 0.5:
            e.w32(slot, 0)
            e.w32(slot + 5, 0)
        else:
            e.w32(slot, r.choice([0, 1, _w(c) | 1]))
            e.w32(slot + 5, _w(c) | 1 if e.r32(slot) == 0 else r.choice([0, 1]))
    e.w32(me + 0x1208, r.choice([0x200, 3, 0, 0x1ff, _w(c) & 0xff]))
    return [me]


S(0x5f95a0, 'GUESS arg vcalls then two 6060a0', 'thiscall', None, ret=None, gen=_g5f95a0, note='batch33065')
S(0x467060, 'GUESS lookup variant then update times', 'thiscall', None, ret='eax', gen=_g467060, note='batch33065')
S(0x4fa180, 'GUESS flag check then vcall bc twice', 'stdcall', None, ret=None, gen=_g4fa180, note='batch33065')
S(0x506040, 'GUESS kind switch with assert', 'thiscall', None, ret='eax', gen=_g506040, note='batch33065')
S(0x520360, 'GUESS dtor flags dispatch 270d', 'thiscall', None, ret='eax', gen=_g520360, note='batch33065')
S(0x54cda0, 'GUESS alloc array and fill via vcall 40', 'thiscall', None, ret=None, gen=_g54cda0, note='batch33065')
S(0x593ee0, 'GUESS optional lookup then main call', 'thiscall', None, ret='eax', gen=_g593ee0, note='batch33065')
S(0x4382e0, 'GUESS find free 9 byte slot', 'thiscall', None, ret='eax', gen=_g4382e0, note='batch33065')
