"""specs_s35112.py - 0x579a60 (thiscall(a) ret 4). Engine (sysobj) slot 0x190 returns s (slot 0x198: cdecl-style four stack args, ECX = vtable, fills the 0x40-byte buffer); engine table slot 0x134 returns t (slot 0x68: three args, the buffer compared by content);
global 0x7003b8 -> block holding unaligned handler dwords at [block + 4 * idx + 0x2c3d] (idx = [this+0x194] 0..3, zero in 1/3); handler h: random 0x900 bytes with vtable slot 0x100 (1 arg, returns a 0xb00-byte block) and the unaligned dword at +0x85a zero in half, else a 0xb00-byte block."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, sysobj


def _g579a60(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    data = bytes(r.getrandbits(8) for _ in range(0x40))

    def fill(em, k):
        em.wbytes(em.arg32(1), data)
    s = obj(c, 0x20, {0x198: pystub(c, 4, nullflag=(1,), this=True, pop=0, side=fill)}, nslots=0x67)
    t = obj(c, 0x20, {0x68: pystub(c, 3, deref={0: -0x40}, this=True)}, nslots=0x1c)
    sysobj(c, slots={0x190: pystub(c, 0, ret=s, this=True)}, table_slots={0x134: pystub(c, 0, ret=t, this=True)}, table_size=0x140)
    idx = r.randint(0, 3)
    blk = rnd(c, 0x2d00)
    hs = []
    for i in range(4):
        if r.random() < 1 / 3:
            h = 0
        else:
            q = rnd(c, 0xb00)
            h = obj(c, 0x900, {0x100: pystub(c, 1, this=True, ret=q)}, nslots=0x41)
            e.wbytes(h + 0x85a, (0 if r.random() < 0.5 else rnd(c, 0xb00)).to_bytes(4, 'little'))
        e.wbytes(blk + 0x2c3d + 4 * i, h.to_bytes(4, 'little'))
    e.w32(0x7003b8, blk)
    me = rnd(c, 0x1c0)
    e.w32(me + 0x194, idx)
    return [me, r.getrandbits(32)]


S(0x579a60, 'GUESS format label and record low byte in handler state', 'thiscall', None, ret=None, gen=_g579a60, note='batch35112')
