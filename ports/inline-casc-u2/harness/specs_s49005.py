"""specs_s49005.py - cascade u2 batch 49005: 0x55ad10 (thiscall(a) ret 4). a+4 / a+8 are table objects; 0x5003d0 (slot lookup, thiscall(idx) ret 4) is a hook returning float cells for the source table and
8-byte records (float, state byte at +4: 0, 2, or another value that makes the code take the assert path) for the destination table. this+0x1c is an object whose slot 0x84 rewrites the vector;
the log object (0x700390 slots 0x20 and 0x2c) and the assert hook 0x7003b0 are stubs."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, logger, pystub


def _g55ad10(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    fv = c.fv
    logger(c, nargs=3)

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    src = rnd(c, 0x10)
    dst = rnd(c, 0x10)
    cells = [e.alloc(8, 4) for _ in range(3)]
    for p in cells:
        e.wbytes(p, struct.pack('<f', fv(-10, 10, 0.1)) + bytes([r.getrandbits(8)] * 4))
    recs = [e.alloc(8, 4) for _ in range(3)]
    for p in recs:
        e.wbytes(p, struct.pack('<f', fv(-10, 10, 0.1)) + bytes([r.choice([0, 0, 2, 2, 1, 3, 255])] + [r.getrandbits(8)] * 3))

    def idh(em, res_):
        t, i = em.reg('ecx'), em.arg32(0)
        em.calllog.append(('id', t, i))
        em.ret(eax=(cells if t == src else recs)[i % 3], argbytes=4)
    e.hook(0x5003d0, idh)

    def rew(em, k):
        for i in range(3):
            if r.random() < 0.4:
                em.wbytes(em.arg32(0) + 4 * i, struct.pack('<f', fv(-10, 10, 0.1)))
    o = obj(c, 0x20, {0x84: pystub(c, 1, this=True, side=rew, nullflag=(0,))}, nslots=0x40)
    me = rnd(c, 0x40)
    e.w32(me + 0x1c, o)
    a = rnd(c, 0x20)
    e.w32(a + 4, src)
    e.w32(a + 8, dst)
    return [me, a]


S(0x55ad10, 'GUESS copy transformed vector into three slots', 'thiscall', None, ret=None, gen=_g55ad10, note='batch49005')
