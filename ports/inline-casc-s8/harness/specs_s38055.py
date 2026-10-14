"""specs_s38055.py - cascade s8 batch 38055 (0x5703c0). The table (engine +0x9b) slot 0x114 (4 args, logged) maps the name strings 0x69c814 / 0x6a4f40 / 0x6a6698 to three distinct ids; the id
argument is one of those, +0x1a4 / +0x1a6, or unrelated (upper half random 30% of the time); this[0x1a3] zero 10%; this[0x94] -> a name block whose +0x48 string equals the string at 0x6a7808 half of the
time; helpers: 0x59be70 (random bool), 0x594f10 / 0x5706f0 / 0x5718b0 / 0x5707d0 / 0x561cb0 hooked (the generic handler returns a random value); table slots 0x138 (helper with slot 0x88 writing the out
dword), 0xb4; the config object (engine +0x1a9f, null 20%) slots 0xd4 / 0x138; this slots 0x84 (returns the object with slots 0x2f8 / 0x2fc) and the this[0x44] object's slot 0x12c are recorded."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g5703c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    ids = r.sample(range(1, 0x10000), 5)
    nameid = {0x69c814: ids[0], 0x6a4f40: ids[1], 0x6a6698: ids[2]}

    def s114(em, res_):
        a = em.arg32(0)
        em.calllog.append(('s114', em.reg('ecx'), a, em.arg32(1), em.arg32(2), em.arg32(3)))
        em.ret(eax=(r.getrandbits(16) << 16) | nameid.get(a, 0), argbytes=16)

    def s88(em, res_):
        em.calllog.append(('s88', em.reg('ecx'), em.arg32(0)))
        em.w32(em.arg32(1), r.getrandbits(32))
        em.ret(eax=0, argbytes=8)
    helper = obj(c, 0x20, {0x88: e.stub_fn('s88', s88)})
    sysobj(c, {0x1a9f: 0} if False else {}, table_slots={0x114: e.stub_fn('s114', s114), 0x138: pystub(c, 0, this=True, ret=helper),
                                                      0xb4: pystub(c, 1, this=True)})
    so = e.r32(0x70039c)
    cfg = obj(c, 0x40, {0xd4: pystub(c, 2, this=True), 0x138: pystub(c, 1, this=True)})
    e.wbytes(so + 0x1a9f, struct.pack('<I', cfg if r.random() > 0.2 else 0))
    cst = bytes(e.rbytes(0x6a7808, 40)).split(b'\0')[0] + b'\0'
    nb = e.alloc(0x80, 4)
    e.wbytes(nb, r.randbytes(0x80))
    if r.random() < 0.5:
        e.wbytes(nb + 0x48, cst)
    d = obj(c, 0x40, {0x2f8: pystub(c, 1, this=True), 0x2fc: pystub(c, 1, this=True)})
    me = obj(c, 0x200, {0x84: pystub(c, 0, this=True, ret=d)})
    e.w32(me + 0x44, obj(c, 0x20, {0x12c: pystub(c, 3, this=True)}))
    e.w32(me + 0x90, rnd(c, 0x20))
    e.w32(me + 0x94, nb)
    e.wbytes(me + 0x1a3, bytes([0 if r.random() < 0.1 else 1]))
    e.wbytes(me + 0x1a4, struct.pack('<HHH', ids[3], ids[4], r.getrandbits(16)))
    e.wbytes(me + 0x1a0, struct.pack('<H', r.getrandbits(16)))
    e.wbytes(me + 0x1a2, bytes([r.getrandbits(8)]))
    hook_rec(c, 0x59be70, 0, this=True, ret=lambda em, k: r.choice([0, 1, 0x100]))
    hook_rec(c, 0x594f10, 1, this=True, pop=4)
    hook_rec(c, 0x5706f0, 0, this=True)
    hook_rec(c, 0x5718b0, 0, this=True)
    hook_rec(c, 0x5707d0, 0, this=True)
    hook_rec(c, 0x561cb0, 2, this=True, pop=8, ret=lambda em, k: r.getrandbits(32))
    idv = r.choice([ids[0], ids[2], ids[3], ids[4], ids[0], ids[2], r.randrange(1, 0x10000)])
    if r.random() < 0.3:
        idv |= r.getrandbits(16) << 16
    return [me, idv, r.getrandbits(32)]


S(0x5703c0, 'GUESS menu page event handler', 'thiscall', None, ret='eax', gen=_g5703c0, note='batch38055')
