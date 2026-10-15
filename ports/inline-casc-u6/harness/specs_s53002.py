"""specs_s53002.py - u6 batch 53002: 0x5d00e0 (fills a 0xe20+ byte object from its owner and the engine tables). Hooked: 0x591ae0, 0x5922c0, 0x4de7a0; every vtable
slot is a recorder stub (outputs through stack pointers are written by `side`); the log object at 0x700390 is the shared logger()."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, logger


def g5d00e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def side_byte(em, k):
        em.wbytes(em.arg32(1), bytes([r.choice([0, 1, 0x55])]))

    def side_dword(em, k):
        em.w32(em.arg32(1), r.getrandbits(32))

    def side_vec(em, k):
        for i in range(3):
            em.w32(em.arg32(0) + 4 * i, r.getrandbits(32))

    A = obj(c, 0x40, {0x90: pystub(c, 2, this=True, side=side_byte, stackmark=(1,))})
    B = obj(c, 0x40, {0x88: pystub(c, 2, this=True, side=side_dword, stackmark=(1,))})
    R = obj(c, 0x40, {0x80: pystub(c, 2, this=True)}) if r.random() < 0.85 else 0
    so = sysobj(c, table_slots={0x134: pystub(c, 0, ret=A, this=True), 0x138: pystub(c, 0, ret=B, this=True),
                                0x58: pystub(c, 1, ret=R, this=True)})
    e.wbytes(so + 0x6c, bytes([r.choice([0, 1, 1, 7])]))
    logger(c)
    owner = obj(c, 0x700, {0x378: pystub(c, 1, this=True, side=lambda em, k: [em.w32(em.arg32(0) + 4 * i, r.getrandbits(32)) for i in range(3)], stackmark=(0,)),
                           0x84: pystub(c, 1, this=True, side=(side_vec if r.random() < 0.5 else None), stackmark=(0,))})
    e.w32(owner + 0x684, r.choice([0, 1, 2, 3, 4, 5, 6, r.getrandbits(32)]))
    me = rnd(c, 0xe40)
    e.w32(me + 0x44, owner)
    hook_rec(c, 0x591ae0, 0, this=True, ret=r.getrandbits(32))
    hook_rec(c, 0x5922c0, 1, this=True, pop=4)
    hook_rec(c, 0x4de7a0, 0, this='mark', pop=0)
    return [me]


S(0x5d00e0, 'GUESS fill object fields from owner and engine tables', 'thiscall', None, ret=None, gen=g5d00e0, nan_heap=True, note='batch53002')
