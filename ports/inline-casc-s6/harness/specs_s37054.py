"""specs_s37054.py - cascade s6 batch 37054 (0x64b170). Pools are objects with slot 2 (alloc, 0 args) and slot 3 (free, 1 arg); owner at this+0x1005d has slots 0xa8 (3 args) / 0xac (1);
this has slots 0x54 / 0x58 (1 arg) and an embedded object at +0x101ad (slot 2); 0x64d490 hooked; engine offset at [[engine+0x1aa3]+0x20]."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g64b170(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))
    hook_rec(c, 0x64d490, 1, this=True, pop=4)
    so = sysobj(c)
    holder = rnd(c, 0x40)
    _w(c, so + 0x1aa3, holder)

    def pool(p_none):
        blocks = [rnd(c, 0x40) for _ in range(3)]
        return obj(c, 0x20, {0x8: pystub(c, 0, this=True, ret=lambda em, k: 0 if r.random() < p_none else blocks[k % 3]),
                             0xc: pystub(c, 1, this=True)})
    own = obj(c, 0x300, {0xa8: pystub(c, 3, this=True, ret=lambda em, k: r.choice([0, 1, 1, 0x100])),
                         0xac: pystub(c, 1, this=True)})
    _w(c, own + 0x224, pool(0.1))
    _w(c, own + 0x234, pool(0.15))
    me = e.alloc(0x10300, 4)
    vt = e.alloc(0x100, 4)
    e.w32(vt + 0x54, pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, 1, 1, 0x100])))
    e.w32(vt + 0x58, pystub(c, 1, this=True))
    e.w32(me, vt)
    _w(c, me + 0x1005d, own)
    _w(c, me + 0x1007d, rnd(c, 0x20))
    _w(c, me + 0x1015d, pool(0.15))
    evt = e.alloc(0x40, 4)
    e.w32(evt + 8, pystub(c, 1, this=True, deref={0: 1}))
    _w(c, me + 0x101ad, evt)
    return [me, r.getrandbits(32), r.choice([0, 1, 0x100])]


S(0x64b170, 'GUESS allocate handle and record', 'thiscall', None, ret='eax', gen=_g64b170, note='batch37054')
