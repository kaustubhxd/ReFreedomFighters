"""specs_s34077.py - cascade tier E, batch 34077.
0x5b7090: [this+0x48] object slots 0x2c (returns an entry or null) / 0x3c; entry +4 object (slots 0x2c / 0x3c / 0x14 / 0 recorders), +8 object (slot 0) or null; returns random.
0x5be690: table of 5-byte entries (count -1..6, key equal to the argument in half the cases, limit around the count); engine table object slot 0x58 -> object slot 0x20 -> object slot 0x28.
0x60cea0: global byte 0x724b34 random; [this+0x1377] unaligned COM-style object (stdcall slots 0x7c / 0x94 / 0xc8 with the object as first stack arg), [this+0x1416] / [this+0x141a] objects with slot 8; hooked 0x609a70 writes random dwords; /GS recorder."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _g5b7090(c):
    clear_hooks(c)
    r = c.rng
    m = lambda: obj(c, 0x20, {0: pystub(c, 1, this=True), 0x14: pystub(c, 0, ret=r.choice([0, 0, 5, r.getrandbits(32)]), this=True),
                              0x2c: pystub(c, 1, ret=r.choice([0, 1, 1, 7]), this=True), 0x3c: pystub(c, 1, this=True)}, nslots=0x40 // 4)
    ent = rnd(c, 0x20)
    c.emu.w32(ent + 4, m())
    c.emu.w32(ent + 8, 0 if r.random() < 0.4 else obj(c, 0x20, {0: pystub(c, 1, this=True)}, nslots=1))
    mgr = obj(c, 0x20, {0x2c: pystub(c, 1, ret=0 if r.random() < 0.2 else ent, this=True), 0x3c: pystub(c, 1, ret=r.getrandbits(32), this=True)}, nslots=0x40 // 4)
    me = rnd(c, 0x60)
    c.emu.w32(me + 0x48, mgr)
    return [me, r.getrandbits(32), r.getrandbits(32)]


def _g5be690(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0xa00)
    n = r.choice([0, 1, 2, 4, 6, 0xffffffff])
    c.emu.w32(me + 0x910, n)
    a = r.getrandbits(32)
    for i in range(0, 7):
        c.emu.wbytes(me + 0x718 + 5 * i, r.getrandbits(32).to_bytes(4, 'little'))
    if 0 < n < 8 and r.random() < 0.5:
        c.emu.wbytes(me + 0x718 + 5 * r.randrange(n), a.to_bytes(4, 'little'))
    lim = (n + r.choice([-1, 0, 1, 3]) if n < 0x100 else r.choice([0, 3])) & 0xffffffff
    c.emu.wbytes(me + 0x992, lim.to_bytes(4, 'little'))
    inner = obj(c, 0x20, {0x28: pystub(c, 0, this=True)}, nslots=0x2c // 4)
    mid = obj(c, 0x20, {0x20: pystub(c, 0, ret=inner, this=True)}, nslots=0x24 // 4)
    tbl = obj(c, 0x20, {0x58: pystub(c, 1, ret=mid, this=True)}, nslots=0x5c // 4)
    so = rnd(c, 0xa0)
    c.emu.w32(0x70039c, so)
    c.emu.w32(so + 0x9b, tbl)
    return [me, a]


def _g60cea0(c):
    clear_hooks(c)
    r = c.rng

    def wM(em, k):
        for i in range(16):
            em.w32(em.reg('ecx') + 4 * i, r.getrandbits(32))
    hook_rec(c, 0x609a70, 0, this='mark', pop=0, side=wM)
    hook_rec(c, 0x633654, 0, pop=0)
    c.emu.wbytes(0x724b34, bytes([r.choice([0, 0, 1])]))
    dev = obj(c, 0x20, {0x7c: pystub(c, 3), 0x94: pystub(c, 3, deref={2: 16}), 0xc8: pystub(c, 3)}, nslots=0xcc // 4)
    rel = lambda: obj(c, 0x20, {8: pystub(c, 1)}, nslots=3)
    me = rnd(c, 0x1430)
    c.emu.wbytes(me + 0x1377, dev.to_bytes(4, 'little'))
    c.emu.wbytes(me + 0x1416, rel().to_bytes(4, 'little'))
    c.emu.wbytes(me + 0x141a, rel().to_bytes(4, 'little'))
    return [me]


S(0x5b7090, 'GUESS find commit and release an entry', 'thiscall', None, ret='eax', gen=_g5b7090, note='batch34077')
S(0x5be690, 'GUESS find or add key in 5-byte table', 'thiscall', None, ret='eax', gen=_g5be690, note='batch34077')
S(0x60cea0, 'GUESS reset device state', 'thiscall', None, ret=None, gen=_g60cea0, note='batch34077')
