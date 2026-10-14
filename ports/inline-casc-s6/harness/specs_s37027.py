"""specs_s37027.py - cascade s6 batch 37027: 0x55f6b0. Global callback stack (count at 0x7140c8, entries from 0x7140d0) is seeded with a random count that is often close to
the capacity 0x32 so the overflow path (slot 0x44 of this, assert hook) runs at different steps; a+0xc random; 0x505a00 hooked."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g55f6b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))
    hook_rec(c, 0x505a00, 1, this=True)
    cnt = r.choice([0, 1, 10, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f, 0x30, 0x31, 0x32, 0x33, 0x40])
    e.w32(0x7140c8, cnt)
    for i in range(0x36):
        e.w32(0x7140d0 + 4 * i, r.getrandbits(32))
    me = obj(c, 0x20, {0x44: pystub(c, 1, this=True, side=lambda em, k: em.w32(0x7140c8, r.choice([0, 5, 0x20, 0x32, 0x33])))})
    a = rnd(c, 0x20)
    e.wbytes(a + 0xc, bytes([r.choice([0, 1, 1, 1, 7])]))
    return [me, a]


S(0x55f6b0, 'GUESS push six callbacks on global stack', 'thiscall', None, ret=None, gen=_g55f6b0, note='batch37027')
