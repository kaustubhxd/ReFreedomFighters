"""specs_s33041.py - h3 () batch 33041."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec


def _w(c):
    return c.rng.getrandbits(32)


def _gctor(c):
    clear_hooks(c)
    hook_rec(c, 0x469870, 0, this=True)
    return [rnd(c, 0x200)]


def _g47fce0(c):
    clear_hooks(c)
    hook_rec(c, 0x43de40, 3, this=True)
    return [rnd(c, 0x100), _w(c), _w(c), _w(c)]


def _g4cbe50(c):
    clear_hooks(c)
    hook_rec(c, 0x4cc630, 1, this=True)
    a = rnd(c, 8)
    c.emu.w32(a, c.rng.choice([0, _w(c)]))
    return [rnd(c, 0x40), a]


def _g5f1590(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4301c0, 2, this=True, deref={1: 1})
    me = rnd(c, 0x40)
    o = rnd(c, 0x100)
    buf = rnd(c, 0x40)
    mode = r.choice(['full', 'null', 'room'])
    cur = {'full': buf, 'null': 0, 'room': buf}[mode]
    end = buf if mode == 'full' else buf + 0x20
    if mode == 'null':
        end = buf + 0x20
    c.emu.w32(o + 0xb0, cur)
    c.emu.w32(o + 0xb4, end)
    c.emu.w32(me + 0xc, o)
    return [me, _w(c)]


def _g59db50(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x59dae0, 5, this=True)
    me = rnd(c, 0xb00)
    n = r.choice([0, 0, 1, 2, 3, 0x10, 0x30])
    c.emu.w32(me + 0x7ce, n)
    a = _w(c)
    mem = r.choice([a - 1, a, a + 1, a - 0x1000, a + 0x1000, _w(c)]) & 0xffffffff
    c.emu.w32(me + n * 16 + 0x7c2, mem)
    return [me, a, _w(c), _w(c), _w(c)]


def _g5f15d0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def side(em, k):
        t = em.arg_ecx() if hasattr(em, 'arg_ecx') else em.reg('ecx')
        for i in range(3):
            em.w32(t + 4 * i, r.getrandbits(32))
    hook_rec(c, 0x42b390, 2, this='mark', side=side, nullflag=(1,))
    hook_rec(c, 0x602750, 7, this=True, ret=lambda em, k: r.getrandbits(32))
    inner = rnd(c, 0x20)
    mid = rnd(c, 0x20)
    e.w32(mid, inner)
    top = rnd(c, 0x20)
    e.w32(top + 4, mid)
    me = rnd(c, 0x40)
    e.w32(me + 0xc, top)
    return [me, _w(c), _w(c), _w(c), _w(c), _w(c)]


def _g40fa40(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x634d52, 1, pop=0)
    if r.random() < 0.15:
        return [0]
    p = rnd(c, 0x20)
    c.emu.w32(p + 4, r.choice([0, _w()] if False else [0, _w(c)]))
    c.emu.w32(p + 8, r.choice([0, _w(c)]))
    return [p]


def _g4d5e40(c):
    clear_hooks(c)
    r = c.rng

    def side(em, k):
        em.wbytes(em.arg32(1), bytes(r.getrandbits(8) for _ in range(0x1c)))
    hook_rec(c, 0x4d6520, 3, this=True, side=side, nullflag=(1,),
             ret=lambda em, k: r.choice([0, 1, 0x100, _w(c)]))
    return [rnd(c, 0x40), _w(c)]


S(0x5c4530, 'GUESS ctor flag+vtable+6 fields', 'thiscall', None, ret='eax', gen=_gctor, note='batch33041')
S(0x47fce0, 'GUESS ctor3 with float fields', 'thiscall', None, ret='eax', gen=_g47fce0, note='batch33041')
S(0x4cbe50, 'GUESS call with string or empty', 'thiscall', None, ret='eax', gen=_g4cbe50, note='batch33041')
S(0x5f1590, 'GUESS vector push_back', 'thiscall', None, ret=None, gen=_g5f1590, note='batch33041')
S(0x59db50, 'GUESS guarded call return 1', 'thiscall', None, ret='eax', gen=_g59db50, note='batch33041')
S(0x5f15d0, 'GUESS temp struct then call', 'thiscall', None, ret='eax', gen=_g5f15d0, note='batch33041')
S(0x40fa40, 'GUESS free two fields clear', 'cdecl', None, ret=None, gen=_g40fa40, note='batch33041')
S(0x4d5e40, 'GUESS call buf return field or -1', 'thiscall', None, ret='eax', gen=_g4d5e40, note='batch33041')
