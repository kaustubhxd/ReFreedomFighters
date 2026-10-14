"""specs_s34122.py - 0x4293e0: three arrays of 0..3 objects (counts at +0xc, +0x1c, +0x60; arrays at +4, +0x10, +0x20) with slot 4 recorders, argument [this+0x7c]; tail slot 0xc of this.
0x432be0: embedded container at this+0x84 with slots 0x4c, 0x44 and 0x64 (next item, 0..3 items then 0); items carry an unaligned pointer at +0xaf (zero in a third)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _g4293e0(c):
    clear_hooks(c)
    r = c.rng
    me = obj(c, 0x90, {0xc: pystub(c, 0, ret=r.getrandbits(32), this=True)}, nslots=0x10 // 4)
    for cnt_off, arr_off, room in ((0xc, 4, 2), (0x1c, 0x10, 3), (0x60, 0x20, 4)):
        k = r.randrange(0, room + 1)
        for i in range(k):
            o = obj(c, 0x20, {4: pystub(c, 1, ret=r.getrandbits(32), this=True)}, nslots=2)
            c.emu.w32(me + arr_off + 4 * i, o)
        c.emu.w32(me + cnt_off, k)
    c.emu.w32(me + 0x7c, r.getrandbits(32))
    return [me]


def _g432be0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x634273, 2, pop=0)
    hook_rec(c, 0x4cbec0, 0, this=True, pop=0, ret=r.getrandbits(32))
    items = []
    for i in range(r.choice([0, 1, 2, 3])):
        p = rnd(c, 0xb8)
        c.emu.wbytes(p + 0xaf, (0 if r.random() < 0.33 else rnd(c, 0x10)).to_bytes(4, 'little'))
        items.append(p)
    me = rnd(c, 0xa0)
    vt = c.emu.alloc(0x70, 4)
    c.emu.w32(vt + 0x4c, pystub(c, 1, this=True, stackmark=(0,)))
    c.emu.w32(vt + 0x44, pystub(c, 1, this=True, stackmark=(0,)))
    c.emu.w32(vt + 0x64, pystub(c, 1, this=True, stackmark=(0,), ret=lambda em, k: items[k] if k < len(items) else 0))
    c.emu.w32(me + 0x84, vt)
    return [me]


S(0x4293e0, 'GUESS notify three lists then tail', 'thiscall', None, ret='eax', gen=_g4293e0, note='batch34122')
S(0x432be0, 'GUESS free and reset every item', 'thiscall', None, ret=None, gen=_g432be0, note='batch34122')
