"""specs_s38042.py - cascade s8 batch 38042. 0x5003d0 is a custom hook: req[8] -> a result object, req[4] with argument 0 / 1 -> two id cells whose type byte (+4) is 0 / 1 mostly (an invalid type 15% of the
time), the id in the first dword; the engine table's slot 0x54 maps the two ids to objects (each missing 15%); the first object has slot 0x180 inside its +0x54 object (returns a byte, upper bits
random) and 0x4db9a0 (hooked, random bool), 0x4daf90 / 0x4db670 / 0x4db1f0 fill / modify the 12-byte stack position (every call logged with the bytes). Logger stream arities: 3 args for line 0x104, 2 for
the others; the assert hook is always set."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g500cb0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    st2 = obj(c, 0x20, {0x2c: pystub(c, 2, pop=0)})
    st3 = obj(c, 0x20, {0x2c: pystub(c, 3, pop=0)})

    def lg(em, res_):
        line = em.arg32(1)
        em.calllog.append(('logger', em.reg('ecx') != 0, em.arg32(0), line))
        em.ret(eax=st3 if line == 0x104 else st2, argbytes=8)
    e.w32(0x700390, obj(c, 0x40, {0x20: e.stub_fn('logger', lg)}))
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))
    ids = r.sample(range(1, 500), 2)

    def cell(idv):
        p = e.alloc(8, 4)
        e.w32(p, idv)
        e.wbytes(p + 4, bytes([r.choice([0, 1, 0, 1, 2, 5]) if r.random() < 0.15 else r.choice([0, 1])]))
        return p
    c0, c1 = cell(ids[0]), cell(ids[1])
    resobj = rnd(c, 0x20)
    q4, q8 = rnd(c, 0x20), resobj
    req = rnd(c, 0x20)
    e.w32(req + 4, q4)
    e.w32(req + 8, q8)

    def h3d0(em, res_):
        ecx, a = em.reg('ecx'), em.arg32(0)
        em.calllog.append(('h5003d0', ecx, a))
        em.ret(eax=resobj if ecx == q8 else (c0 if a == 0 else c1), argbytes=4)
    e.hook(0x5003d0, h3d0)
    hook_rec(c, 0x5002f0, 1, this=True, pop=4)
    sub = obj(c, 0x40, {0x180: pystub(c, 2, this=True, stackmark=(0,), side=lambda em, k: em.calllog.append(('s180', em.rbytes(em.arg32(0), 12))), ret=lambda em, k: (r.getrandbits(24) << 8) | r.choice([0, 1, 0x7f, 0xff]))})
    xo = rnd(c, 0x80)
    e.w32(xo + 0x54, sub)
    yo = rnd(c, 0x80)
    objs = {ids[0]: xo if r.random() > 0.15 else 0, ids[1]: yo if r.random() > 0.15 else 0}

    def s54(em, res_):
        a = em.arg32(0)
        em.calllog.append(('s54', em.reg('ecx'), a))
        em.ret(eax=objs.get(a, 0), argbytes=4)
    sysobj(c, {}, table_slots={0x54: e.stub_fn('s54', s54)})

    def fill(n, mode):
        def side(em, k):
            p = em.arg32(0)
            if mode == 'w':
                em.wbytes(p, bytes(r.getrandbits(8) for _ in range(n)))
            else:
                em.wbytes(p, bytes((b + 1) & 0xff for b in em.rbytes(p, n)))
            em.calllog.append(('pos', mode, em.reg('ecx'), em.rbytes(p, n)))
        return side
    hook_rec(c, 0x4db9a0, 1, this=True, pop=4, ret=lambda em, k: r.choice([0, 1, 0x100, 0x101]))
    hook_rec(c, 0x4daf90, 1, this=True, pop=4, stackmark=(0,), side=fill(12, 'w'))
    hook_rec(c, 0x4db670, 1, this=True, pop=4, stackmark=(0,), side=fill(12, 'a'))
    hook_rec(c, 0x4db1f0, 1, this=True, pop=4, stackmark=(0,), side=fill(12, 'a'))
    return [req]


S(0x500cb0, 'GUESS script move object relative to another', 'stdcall', None, ret=None, gen=_g500cb0, note='batch38042')
