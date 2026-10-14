"""specs_s35047.py - 0x579b20 (thiscall(a) ret 4). Engine slot 0x190 returns s (slot 0x198: cdecl-style four stack args, caller-popped, ECX = its vtable, fills the 0x40-byte buffer with call-dependent bytes);
engine table slot 0x134 returns t (slot 0x68: three args, the buffer compared by content); global 0x7003b8 -> block with a handler dword at [block + 4 * idx + 0x2c3d] (idx = [this+0x194] 0..3; zero in 1/3);
[this+0x44] object with slot 0x130 (three args; the third is &v: its value is compared via deref)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, sysobj


def _g579b20(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    data = bytes(r.getrandbits(8) for _ in range(0x40))

    def fill(em, k):
        em.wbytes(em.arg32(1), data)
    s = obj(c, 0x20, {0x198: pystub(c, 4, nullflag=(1,), this=True, pop=0, side=fill)}, nslots=0x68)
    t = obj(c, 0x20, {0x68: pystub(c, 3, deref={0: -0x40}, this=True)}, nslots=0x1c)
    sysobj(c, slots={0x190: pystub(c, 0, ret=s, this=True)}, table_slots={0x134: pystub(c, 0, ret=t, this=True)}, table_size=0x140)
    idx = r.randint(0, 3)
    blk = rnd(c, 0x2d00)
    for i in range(4):
        h = 0 if r.random() < 1 / 3 else r.getrandbits(32) | 1
        e.wbytes(blk + 0x2c3d + 4 * i, h.to_bytes(4, 'little'))
    e.w32(0x7003b8, blk)
    me = rnd(c, 0x1c0)
    e.w32(me + 0x194, idx)
    e.w32(me + 0x44, obj(c, 0x20, {0x130: pystub(c, 3, deref={2: 1}, this=True)}, nslots=0x4d))
    return [me, r.getrandbits(32)]


S(0x579b20, 'GUESS format label and hand byte value to handler', 'thiscall', None, ret=None, gen=_g579b20, note='batch35047')
