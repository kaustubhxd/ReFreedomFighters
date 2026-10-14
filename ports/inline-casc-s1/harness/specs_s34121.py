"""specs_s34121.py - 0x5e0330: this+8 object with slots 0x144, 0x1e0 (low byte in half), 0x2d0, 0x2f0; engine table [[0x70039c]+0x9b] slot 0x4c; [this+0x10] object with slot 8.
0x5eb600: the argument object's getters write through their pointer argument (random values), engine table slot 0x58 and a +0x44 field."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _g5e0330(c):
    clear_hooks(c)
    r = c.rng
    branch = r.random() < 0.5   # the table slot 0x4c takes three stack arguments on the first branch and one on the second
    o = obj(c, 0x20, {0x144: pystub(c, 1, this=True), 0x1e0: pystub(c, 1, ret=r.choice([1, 0x101, 0x201]) if branch else r.choice([0, 0x100 * r.randrange(1, 50)]), this=True),
                      0x2d0: pystub(c, 2, this=True), 0x2f0: pystub(c, 1, this=True)}, nslots=0x2f4 // 4)
    tbl = obj(c, 0x20, {0x4c: pystub(c, 3 if branch else 1, ret=r.getrandbits(32), this=True)}, nslots=0x50 // 4)
    so = rnd(c, 0xa0)
    c.emu.w32(so + 0x9b, tbl)
    c.emu.w32(0x70039c, so)
    p = obj(c, 0x20, {8: pystub(c, 2, this=True)}, nslots=3)
    me = rnd(c, 0x30)
    c.emu.w32(me + 8, o)
    c.emu.w32(me + 0xc, r.getrandbits(32))
    c.emu.w32(me + 0x10, p)
    return [me]


def _g5eb600(c):
    clear_hooks(c)
    r = c.rng

    def wr(em, k):
        em.w32(em.arg32(0), r.getrandbits(32))

    def wr1(em, k):
        em.wbytes(em.arg32(0), bytes([r.getrandbits(8)]))
    a = obj(c, 0x20, {0x40: pystub(c, 1, this=True, side=wr, stackmark=(0,)), 0x50: pystub(c, 1, this=True, side=wr),
                      0x68: pystub(c, 1, this=True, side=wr1), 0x6c: pystub(c, 1, ret=r.getrandbits(32), this=True, side=wr1)}, nslots=0x70 // 4)
    tbl = obj(c, 0x60, {0x58: pystub(c, 1, ret=r.getrandbits(32), this=True)}, nslots=0x5c // 4)
    so = rnd(c, 0xa0)
    c.emu.w32(so + 0x9b, tbl)
    c.emu.w32(0x70039c, so)
    return [rnd(c, 0x30), a]


S(0x5e0330, 'GUESS hand a pending object over', 'thiscall', None, ret='al', gen=_g5e0330, note='batch34121')
S(0x5eb600, 'GUESS read object fields through getters', 'thiscall', None, ret='eax', gen=_g5eb600, note='batch34121')
