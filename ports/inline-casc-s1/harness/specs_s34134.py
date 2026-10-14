"""specs_s34134.py - 0x4f67a0: this with words at +0x48/+0x4a (the id equals the first in a third, the second in a third, with high bits in the id too), t = [this+0x44] with slots 0x374 (2 args), 0x2c4 (returns r), 0x20 (random), 0xbc (1 arg); r with slot 0x2fc (1 arg); this slots 0x64 (1 arg) and 0x68 (2 args)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _g(c):
    clear_hooks(c)
    r = c.rng
    rr = obj(c, 0x20, {0x2fc: pystub(c, 1, this=True, ret=r.getrandbits(32))}, nslots=0x300 // 4)
    t = obj(c, 0x20, {0x374: pystub(c, 2, this=True), 0x2c4: pystub(c, 0, ret=rr, this=True),
                      0x20: pystub(c, 0, ret=r.getrandbits(32), this=True), 0xbc: pystub(c, 1, this=True)}, nslots=0x378 // 4)
    me = obj(c, 0x60, {0x64: pystub(c, 1, this=True), 0x68: pystub(c, 2, this=True)}, nslots=0x6c // 4)
    w1, w2 = r.getrandbits(16), r.getrandbits(16)
    c.emu.w32(me + 0x44, t)
    c.emu.wbytes(me + 0x48, w1.to_bytes(2, 'little') + w2.to_bytes(2, 'little'))
    k = r.choice([0, 1, 2, 3])
    w = w1 if k == 0 else w2 if k == 1 else r.getrandbits(16)
    if k == 3:
        w = w1 ^ 1
    ident = w | (r.getrandbits(16) << 16 if r.random() < 0.5 else 0)
    return [me, ident, r.getrandbits(32)]


S(0x4f67a0, 'GUESS command handler', 'thiscall', None, ret='eax', gen=_g, note='batch34134')
