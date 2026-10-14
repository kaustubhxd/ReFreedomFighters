"""specs_s34075.py - cascade tier E, batch 34075.
0x57e230: [this+0x33c] zero in a quarter; engine object 0x70039c is a heap block with the unaligned pointer +0x1907 -> block with dword +0x131c; arrays at [this+0x32c] / [this+0x334] with random bytes (count +0x338 in 0..8);
 hooked 0x634d22 (cdecl); embedded object at this+0x190 with slots 0x2c / 0x40; hooked 0x57e4f0.
0x57e370: hooked 0x5630f0; table object at [sys+0x9b] slot 0x58 returns objects with slot 0x25c (returns an inner object with slot 0x250) recorders.
0x593f40: flag bit 0x8000000 in a quarter; [sys+0x40] vs the unaligned word +0x94f around the +0x200 threshold; this slots 0x3d8 / 0x3ec / 0x3f0 recorders; a in 0..3."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _sys(c, size=0x1a00):
    so = rnd(c, size)
    c.emu.w32(0x70039c, so)
    return so


def _g57e230(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x634d22, 3, pop=0)
    hook_rec(c, 0x57e4f0, 0, this=True, pop=0)
    so = _sys(c)
    src = rnd(c, 0x40)
    mid = rnd(c, 0x1400)
    c.emu.w32(mid + 0x131c, src)
    c.emu.wbytes(so + 0x1907, mid.to_bytes(4, 'little'))
    me = rnd(c, 0x360)
    sub = obj(c, 0x20, {0x2c: pystub(c, 1, ret=r.choice([0, 1, r.getrandbits(32)]), this=True), 0x40: pystub(c, 1, this=True)}, nslots=0x44 // 4)
    c.emu.w32(me + 0x190, c.emu.r32(sub))
    n = r.choice([0, 1, 3, 8])
    c.emu.w32(me + 0x338, n)
    c.emu.w32(me + 0x33c, r.choice([0, 1, 1, 5]))
    c.emu.w32(me + 0x32c, rnd(c, 0x20))
    c.emu.w32(me + 0x334, rnd(c, 0x20))
    for base in (c.emu.r32(me + 0x32c), c.emu.r32(me + 0x334)):
        c.emu.wbytes(base, bytes(r.choice([0, 0, 1, 7]) for _ in range(0x10)))
    return [me, r.getrandbits(32)]


def _g57e370(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5630f0, 0, this=True, pop=0)
    so = _sys(c, 0xa0)

    def mk():
        inner = obj(c, 0x20, {0x250: pystub(c, 1, this=True)}, nslots=0x254 // 4)
        return obj(c, 0x20, {0x25c: pystub(c, 2, ret=inner, this=True)}, nslots=0x260 // 4)
    tbl = obj(c, 0x20, {0x58: pystub(c, 1, ret=lambda em, k: mk_ret[k % 2], this=True)}, nslots=0x5c // 4)
    mk_ret = [mk(), mk()]
    c.emu.w32(so + 0x9b, tbl)
    return [rnd(c, 0x190)]


def _g593f40(c):
    clear_hooks(c)
    r = c.rng
    so = _sys(c, 0x60)
    me = obj(c, 0x960, {0x3d8: pystub(c, 1, this=True), 0x3ec: pystub(c, 1, ret=r.getrandbits(32), this=True),
                        0x3f0: pystub(c, 0, ret=r.choice([0, 0, 1]), this=True)}, nslots=0x3f4 // 4)
    fl = r.getrandbits(32)
    fl = fl | 0x8000000 if r.random() < 0.25 else fl & ~0x8000000
    c.emu.wbytes(me + 0x417, fl.to_bytes(4, 'little'))
    v = r.getrandbits(32) if r.random() < 0.3 else r.randrange(0, 1000)
    c.emu.wbytes(me + 0x94f, v.to_bytes(4, 'little'))
    thr = (v + 0x200) & 0xffffffff
    c.emu.w32(so + 0x40, (thr + r.choice([-1, 0, 1, 5, -500, 500, 0x7fffffff])) & 0xffffffff)
    return [me, r.choice([0, 1, 2, 3, 0xffffffff, r.getrandbits(32)])]


S(0x57e230, 'GUESS refresh flag array and ask member', 'thiscall', None, ret='al', gen=_g57e230, note='batch34075')
S(0x57e370, 'GUESS set two values on two engine objects', 'thiscall', None, ret=None, gen=_g57e370, note='batch34075')
S(0x593f40, 'GUESS clamped state update', 'thiscall', None, ret=None, gen=_g593f40, note='batch34075')
