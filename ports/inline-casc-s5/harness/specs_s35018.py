"""specs_s35018.py - 0x56c6a0. Object (0xd00 bytes) with unaligned fields +0xcae (Y), +0xcb2 (X), +0xcd2, +0xcd6 (objects), +0xce6 (mode, signed: values around 1 and random incl. negative); slots 0xfc (1 arg),
0x84 (returns an object with slot 0x2ec). X slot 0x31c (2 args); the two +0xcd2/+0xcd6 objects slot 0xbc is a custom stub that records the flag argument masked to its low byte (the exe pushes an
uninitialised dword); Y slot 0x70 records the three dwords of the vector it is handed."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g56c6a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    o2 = obj(c, 0x10, {0x2ec: pystub(c, 1, this=True)}, nslots=0xc0)
    me = obj(c, 0xd00, {0xfc: pystub(c, 1, this=True), 0x84: pystub(c, 0, ret=o2, this=True)}, nslots=0x40)

    def bc(em, rr):
        em.calllog.append(('bc', em.reg('ecx'), em.arg32(0) & 0xff))
        em.ret(argbytes=4)
    stub_bc = e.stub_fn('bc', bc)
    X = obj(c, 0x20, {0x31c: pystub(c, 2, this=True)}, nslots=0xc8)
    Y = obj(c, 0x20, {0x70: pystub(c, 1, deref={0: 3}, this=True)}, nslots=0x20)
    d1 = obj(c, 0x20, {0xbc: stub_bc}, nslots=0x30)
    d2 = obj(c, 0x20, {0xbc: stub_bc}, nslots=0x30)
    for off, v in ((0xcae, Y), (0xcb2, X), (0xcd2, d1), (0xcd6, d2)):
        e.wbytes(me + off, v.to_bytes(4, 'little'))
    mode = r.choice([0, 1, 2, 3, 0xffffffff, 0x80000000, 0x7fffffff, r.getrandbits(32)])
    e.wbytes(me + 0xce6, mode.to_bytes(4, 'little'))
    return [me]


S(0x56c6a0, 'GUESS reset sub-objects by mode and update camera', 'thiscall', None, ret=None, gen=_g56c6a0, note='batch35018')
