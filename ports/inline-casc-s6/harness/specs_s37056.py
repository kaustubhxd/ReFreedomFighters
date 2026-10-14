"""specs_s37056.py - cascade s6 batch 37056 (0x54d760). src descriptor is a spec block with the fields the function reads; memset thunk 0x634d10 does a real fill; this has slot 0x40
and a pointer at +8 to an object whose +0x8061 holds a factory with slot 1 (4 args, returns a spec object with slot 2 / fields +4 +0x57) or 0."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g54d760(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))

    def fill(em, k):
        d, v, n = em.arg32(0), em.arg32(1), em.arg32(2)
        if n < 0x5000:
            em.wbytes(d, bytes([v & 0xff]) * n)
    hook_rec(c, 0x634d10, 3, pop=0, side=fill)
    src = rnd(c, 0x40)
    kind = r.choice([0x11, 0x11, 0x1000, 0x2222, 0x11])
    neg = r.random() < 0.65
    _w(c, src + 8, (kind | 0x80000000) if neg else r.choice([0, 5, 0x7fffffff & kind]))
    _w(c, src + 0x28, r.choice([0, 1, 2, 0x10, 3, 0x2001]))
    _w(c, src + 0x2c, r.randint(1, 20))
    _w(c, src + 0x1c, r.choice([6, 6, 0, 1]))
    _w(c, src + 0x14, r.randint(0, 0x500))
    y = obj(c, 0x80, {0x8: pystub(c, 1, this=True)})
    z = obj(c, 0x20, {0x4: pystub(c, 4, this=True, ret=lambda em, k: 0 if r.random() < 0.3 else y)})
    ee = e.alloc(0x8100, 4)
    for off in range(0, 0x100, 4):
        e.w32(ee + off, r.getrandbits(32))
    _w(c, ee + 0x8061, z)
    _w(c, ee + 0x802d, r.getrandbits(32))
    me = rnd(c, 0x4100)
    vt = e.alloc(0x100, 4)
    e.w32(vt + 0x40, pystub(c, 0, this=True))
    e.w32(me, vt)
    _w(c, me + 8, ee)
    _w(c, me + 0x75, 0)
    return [me, src, r.getrandbits(32)]


S(0x54d760, 'GUESS init stream buffer description', 'thiscall', None, ret='al', gen=_g54d760, note='batch37056')
