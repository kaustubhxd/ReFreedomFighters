"""specs_s38027.py - cascade s8 batch 38027. About 35% of the cases take the first path (+0x1c3 set, +0x156 == 2, +0x1e6 clear); the others vary the byte flags, the list pointers (null 10%), the
count of the first list (1..5) against +0x156 (0..count), and the second list's count (0..4). Lists have slots 0x14 (count, fixed per case) and 0x30 (id from a pool); the table (engine +0x9b) has
slots 0x138 (helper with slot 0x88 writing a random out dword), 0x114 (random id), 0x58 (id -> object or 0; objects record 0xbc and 0x138) and 0x4c (random handle); this[0x44] slot 0x12c is recorded."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, pystub


def _g5d7bc0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    pool = list(range(1, 7))
    objs = {i: (obj(c, 0x40, {0xbc: pystub(c, 1, this=True), 0x138: pystub(c, 3, this=True)}) if r.random() > 0.2 else 0) for i in pool}

    def s58(em, res_):
        a = em.arg32(0)
        em.calllog.append(('s58', em.reg('ecx'), a))
        em.ret(eax=objs.get(a, 0), argbytes=4)

    def s88(em, res_):
        em.calllog.append(('s88', em.reg('ecx'), em.arg32(0)))
        em.w32(em.arg32(1), r.getrandbits(32))
        em.ret(eax=0, argbytes=8)
    helper = obj(c, 0x20, {0x88: e.stub_fn('s88', s88)})
    sysobj(c, {}, table_slots={0x138: pystub(c, 0, this=True, ret=helper), 0x114: pystub(c, 4, this=True, ret=lambda em, k: r.getrandbits(32)),
                               0x58: e.stub_fn('s58', s58), 0x4c: pystub(c, 1, this=True, ret=lambda em, k: r.getrandbits(32))})
    eng = e.r32(0x70039c)
    e.w32(eng + 0x40, r.getrandbits(32))
    a = r.randrange(1, 6)
    cc = r.randrange(0, 5)
    l1 = obj(c, 0x40, {0x14: pystub(c, 0, this=True, ret=a), 0x30: pystub(c, 1, this=True, ret=lambda em, k: r.choice(pool))})
    l2 = obj(c, 0x40, {0x14: pystub(c, 0, this=True, ret=cc), 0x30: pystub(c, 1, this=True, ret=lambda em, k: r.choice(pool))})
    me = obj(c, 0x300, {})
    e.w32(me + 0x44, obj(c, 0x40, {0x12c: pystub(c, 3, this=True)}))
    if r.random() < 0.35:
        e.wbytes(me + 0x1c3, bytes([r.choice([1, 2, 0xff])]))
        e.w32(me + 0x156, 2)
        e.wbytes(me + 0x1e6, bytes([0 if r.random() < 0.85 else 1]))
    else:
        e.wbytes(me + 0x1c3, bytes([r.choice([0, 1])]))
        e.w32(me + 0x156, r.randrange(0, a + 1))
        e.wbytes(me + 0x1e6, bytes([r.choice([0, 1])]))
    e.w32(me + 0x14e, l1 if r.random() > 0.1 else 0)
    e.w32(me + 0x152, l2 if r.random() > 0.1 else 0)
    e.wbytes(me + 0x140, struct.pack('<H', r.getrandbits(16)))
    e.wbytes(me + 0x144, struct.pack('<H', r.getrandbits(16)))
    return [me]


S(0x5d7bc0, 'GUESS apply selected list entry', 'thiscall', None, ret=None, gen=_g5d7bc0, note='batch38027')
