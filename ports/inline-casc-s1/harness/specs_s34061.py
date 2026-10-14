"""specs_s34061.py - cascade tier E, batch 34061.
0x5f4040: globals 0x724278 (-> object whose +0x3c object has slot 0 returning a random value) and 0x724270 (the real 0x5fa630 reads it: an object with slots 0x4c (three args) and, for its result, 0x48 (two args));
hooked 0x5ffb70 returns a record (0 in a quarter); [this+0x96] unaligned.
0x5f4f00 / 0x5f51e0: the vector base block holds up to 4 elements of 8 bytes whose kind byte is 4 (object with slots 0x24 -> clone, 0x28 -> release, recorders) or another value; the element p (inside or outside the
vector) likewise; counts include zero (pop) and full capacity (push); the assert hook is set; count is kept within the block."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _assert_hook(c):
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))


def _g5f4040(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    o = obj(c, 0x20, {0: pystub(c, 1, ret=lambda em, k: r.getrandbits(32), this=True)}, nslots=4)
    g = rnd(c, 0x60)
    e.w32(g + 0x3c, o)
    e.w32(0x724278, g)
    rec = 0 if r.random() < 0.25 else rnd(c, 0x20)
    hook_rec(c, 0x5ffb70, 1, ret=rec, this=True)
    p = 0 if r.random() < 0.25 else obj(c, 0x20, {0x48: pystub(c, 2, this=True)}, nslots=0x4c // 4)
    h = obj(c, 0x20, {0x4c: pystub(c, 3, ret=p, this=True)}, nslots=0x50 // 4)
    e.w32(0x724270, h)
    me = rnd(c, 0xa0)
    e.wbytes(me + 0x96, rnd(c, 0x10).to_bytes(4, 'little'))
    return [me, r.getrandbits(32)]


def _refobj(c, r):
    return obj(c, 0x20, {0x24: pystub(c, 0, ret=lambda em, k: rnd(c, 0x20), this=True), 0x28: pystub(c, 0, this=True)}, nslots=0x2c // 4)


def _vec(c, r, n, cap):
    e = c.emu
    base = rnd(c, 8 * 6)
    for i in range(6):
        kind = 4 if r.random() < 0.5 else r.choice([0, 1, 2, r.getrandbits(8)])
        e.w32(base + 8 * i, _refobj(c, r) if kind == 4 else r.getrandbits(32))
        e.wbytes(base + 8 * i + 4, bytes([kind & 0xff]))
    me = rnd(c, 0x20)
    e.w32(me, base)
    e.w32(me + 4, cap)
    e.w32(me + 8, n)
    return me, base


def _elem(c, r, base, n, force_inside=None):
    e = c.emu
    if force_inside is not None:
        return base + 8 * force_inside
    q = rnd(c, 8)
    kind = 4 if r.random() < 0.5 else r.choice([0, 1, 2, r.getrandbits(8)])
    e.w32(q, _refobj(c, r) if kind == 4 else r.getrandbits(32))
    e.wbytes(q + 4, bytes([kind & 0xff]))
    return q


def _g5f4f00(c):
    clear_hooks(c)
    r = c.rng
    _assert_hook(c)
    n = r.choice([0, 1, 2, 3, 4])
    me, base = _vec(c, r, n, 4)
    k = r.random()
    if n and k < 0.3:
        p = base + 8 * (n - 1)          # p is the last element itself
    elif n and k < 0.6:
        p = base + 8 * r.randrange(n)   # p is some element
    else:
        p = _elem(c, r, base, n)
    return [me, p]


def _g5f51e0(c):
    clear_hooks(c)
    r = c.rng
    _assert_hook(c)
    n = r.choice([0, 1, 2, 3, 4])
    cap = r.choice([n, n + 1, 5, r.randint(0, 5)])
    if n >= 6:
        n = 5
    me, base = _vec(c, r, n, cap)
    k = r.random()
    if k < 0.2:
        p = base + 8 * n                # p is the destination slot itself
    elif n and k < 0.5:
        p = base + 8 * r.randrange(n)
    else:
        p = _elem(c, r, base, n)
    return [me, p]


S(0x5f4040, 'GUESS build an object from a record found by a lookup', 'thiscall', None, ret='eax', gen=_g5f4040, note='batch34061')
S(0x5f4f00, 'GUESS swap-remove from a vector of 8-byte refs', 'thiscall', None, ret=None, gen=_g5f4f00, note='batch34061')
S(0x5f51e0, 'GUESS push-copy onto a vector of 8-byte refs', 'thiscall', None, ret='eax', gen=_g5f51e0, note='batch34061')
