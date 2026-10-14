"""specs_s47000.py - cascade t8 batch 47000: 0x5f3eb0 (walk typed entries, call slots on elem and out), 0x57bfe0 (UI code handler via table slots)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, logger


def _assert_hook(c):
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    e._image_dirty = True


def _g5f3eb0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _assert_hook(c)
    n = r.choice([0, 1, 2, 3, 5, 8])
    arr = rnd(c, 0x10)
    holder = {}

    def shrink(em, k):   # sometimes a callee shrinks the count so later index asserts fire
        if r.random() < 0.25:
            em.w32(arr + 8, r.randrange(0, n + 1))
    data = e.alloc(8 * max(n, 1) + 8, 4)
    for i in range(n):
        t = r.choice([3, 4, 3, 4, 0, 1, 2, 5, 0xff, 0x83, 0x84])
        if t == 4:
            el = obj(c, 0x20, {0x38: pystub(c, 0, this=True, ret=r.getrandbits(32), side=shrink),
                               0x3c: pystub(c, 1, this=True)})
        else:
            el = rnd(c, 0x20)
        e.w32(data + 8 * i, el)
        e.wbytes(data + 8 * i + 4, bytes([t]) + bytes(r.getrandbits(8) for _ in range(3)))
    e.w32(arr, data)
    e.w32(arr + 8, n)
    out = obj(c, 0x20, {0: pystub(c, 1, this=True)})
    hook_rec(c, 0x5f9db0, 1, this=True)
    return [arr, out]


def _g57bfe0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    logger(c, 3)
    code = r.choice([0x61, 0x15, 0x47, 0x5b, 0x61, 0x15, 0x47, 0x5b, 0, 1, 0x58, r.getrandbits(8), r.getrandbits(32)])

    def put(em, k):
        em.w32(em.arg32(1), r.getrandbits(32)) if False else None
    sub = obj(c, 0x20, {0x88: pystub(c, 2, this=True, deref={1: 1}, side=lambda em, k: em.w32(em.arg32(1), r.getrandbits(32))),
                        0x68: pystub(c, 3, this=True)})
    sysobj(c, table_slots={0x138: pystub(c, 0, this=True, ret=sub), 0x134: pystub(c, 0, this=True, ret=sub)})
    hook_rec(c, 0x562c20, 1, this=True, ret=lambda em, k: r.choice([0, 0, 1, 0x100, 0x1ff]))
    hook_rec(c, 0x562af0, 1, this=True)
    me = obj(c, 0x40, {0xd0: pystub(c, 1, this=True)})
    return [me, code]


S(0x5f3eb0, 'GUESS walk typed entries, call slots', 'stdcall', None, ret=None, gen=_g5f3eb0, note='batch47000')
S(0x57bfe0, 'GUESS UI code handler', 'thiscall', None, ret='al', gen=_g57bfe0, note='batch47000')
