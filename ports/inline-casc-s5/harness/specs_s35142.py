"""specs_s35142.py - 0x57a6b0 (thiscall, no args). Global object at 0x7003a0 with slot 0x4c (returns a random mask). this: random 0x1a0 bytes with shifts at +0x184 + 4i (-1, 0..40) and flag bytes at +0x194.. (0 or 1), +0x198 (0 in 2/3), +0x88 (zero in half), [+0x94] = P (null in a third, else a 0x13300-byte block with the two tested bytes
zero in half); vtable slot 0x84 (0 args, returns o with slot 0x2fc, 1 arg); 0x57aaf0 hooked (thiscall)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g57a6b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x57aaf0, 0, this=True)
    g = obj(c, 0x20, {0x4c: pystub(c, 0, this=True, ret=r.getrandbits(32))}, nslots=0x14)
    e.w32(0x7003a0, g)
    o = obj(c, 0x20, {0x2fc: pystub(c, 1, this=True)}, nslots=0xc0)
    me = obj(c, 0x1a0, {0x84: pystub(c, 0, this=True, ret=o)}, nslots=0x22)
    for i in range(4):
        e.w32(me + 0x184 + 4 * i, r.choice([0xffffffff, r.randint(0, 40)]))
        e.wbytes(me + 0x194 + i, bytes([r.choice([0, 1])]))
    e.wbytes(me + 0x198, bytes([0 if r.random() < 2 / 3 else 1]))
    e.wbytes(me + 0x88, bytes([0 if r.random() < 0.5 else r.randint(1, 255)]))
    if r.random() < 1 / 3:
        P = 0
    else:
        P = rnd(c, 0x13300)
        for off in (0x13298, 0x13299):
            e.wbytes(P + off, bytes([0 if r.random() < 0.6 else r.randint(1, 255)]))
    e.w32(me + 0x94, P)
    return [me]


S(0x57a6b0, 'GUESS flag missing slots and refresh', 'thiscall', None, ret=None, gen=_g57a6b0, note='batch35142')
