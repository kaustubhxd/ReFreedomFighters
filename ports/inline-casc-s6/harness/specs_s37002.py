"""specs_s37002.py - cascade s6 batch 37002: 0x6392e0 (image -> 4x4 block encoder driver). Hooked: 0x41e290 (alloc, returns a spec buffer), 0x636de0 (fastcall block encoder:
records ecx, the 16 block dwords and writes two random dwords through its last argument), 0x634273 (free). Slot 0x58 of this records its args."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g6392e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))
    w = r.choice([1, 2, 3, 4, 5, 6, 7, 8, 9, 12, 13, 16, 20])
    h = r.choice([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 13, 16])
    ww = (w + 3) & ~3
    hh = (h + 3) & ~3
    buf = rnd(c, ww * hh // 2 + 16)
    src = e.alloc(4 * w * h + 16, 4)
    mode = r.random()
    for i in range(w * h):
        if mode < 0.3:
            a = r.choice([0x00, 0x7f, 0x80, 0xff, r.getrandbits(8)])
        elif mode < 0.5:
            a = 0xff
        else:
            a = r.getrandbits(8)
        e.w32(src + 4 * i, (a << 24) | r.getrandbits(24))
    hook_rec(c, 0x41e290, 1, pop=0, ret=buf)

    def side(em, k):
        o = em.arg32(4)
        em.w32(o, r.getrandbits(32))
        em.w32(o + 4, r.getrandbits(32))
    hook_rec(c, 0x636de0, 5, this=True, deref={2: 16}, nullflag=(3, 4), side=side, pop=0x14)
    hook_rec(c, 0x634273, 2, pop=0)
    me = obj(c, 0x80, {0x58: pystub(c, 6, this=True)})
    return [me, r.getrandbits(32), w, h, src]


S(0x6392e0, 'GUESS image to 4x4 blocks via encoder', 'thiscall', None, ret=None, gen=_g6392e0, note='batch37002')
