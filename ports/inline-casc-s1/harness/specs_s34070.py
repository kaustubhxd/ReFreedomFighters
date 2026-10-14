"""specs_s34070.py - 0x4dbd10 recursive node update: node tree with random flags, children chain through [q+0x50] / [c+0x60], logging branch via engine object 0x700390 (slot 0x20 -> printer slot 0x2c, cdecl).
Hooked 0x4dc630 (2 stack args), 0x4d9ce0, 0x4d9bf0, 0x4d9d20; slot 0x24 of the node's [+0x54] object records."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _node(c, depth):
    r = c.rng
    me = rnd(c, 0x80)
    fl = r.getrandbits(32)
    if r.random() < 0.5:
        fl |= 0x40000
    if r.random() < 0.5:
        fl &= ~0x200c00
    if r.random() < 0.92:
        fl |= 0x400
    c.emu.w32(me + 0x3c, fl)
    c.emu.w32(me + 0x64, r.choice([0, 1, r.getrandbits(32)]))
    nf = rnd(c, 0x70)
    nfl = r.getrandbits(32)
    if r.random() < 0.6:
        nfl &= ~0x400
    c.emu.w32(nf + 0x3c, nfl)
    c.emu.w32(nf + 0x54, 0 if r.random() < 0.3 else rnd(c, 0x10))
    if r.random() < 0.5:
        c.emu.w32(c.emu.r32(nf + 0x54) + 4, r.choice([0, 0x12345678, r.getrandbits(32)])) if c.emu.r32(nf + 0x54) else None
    c.emu.w32(me + 0x50, nf)
    if r.random() < 0.15:
        c.emu.w32(me + 0x54, 0)
    else:
        blk = rnd(c, 0x40)
        f = r.getrandbits(32)
        if r.random() < 0.65:
            f |= 0x100000
        c.emu.wbytes(blk + 0x23, f.to_bytes(4, 'little'))
        q = obj(c, 0x70, {0x24: pystub(c, 1, this=True)}, nslots=0x28 // 4)
        c.emu.w32(q + 0xc, blk)
        c.emu.w32(q + 4, r.choice([0, 0x23456789, r.getrandbits(32)]))
        head = 0
        if depth < 2:
            kids = [_node(c, depth + 1) for _ in range(r.choice([0, 1, 2, 3]))]
            for a, b in zip(kids, kids[1:] + [0]):
                c.emu.w32(a + 0x60, b)
            head = kids[0] if kids else 0
        c.emu.w32(q + 0x50, head)
        c.emu.w32(me + 0x54, q)
    return me


def _g(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4dc630, 2)
    hook_rec(c, 0x4d9ce0, 0, this=True, pop=0)
    hook_rec(c, 0x4d9bf0, 0, this=True, pop=0)
    hook_rec(c, 0x4d9d20, 1, this=True)
    pr = obj(c, 0x20, {0x2c: pystub(c, 4, pop=0)}, nslots=0x30 // 4)
    sysx = obj(c, 0x20, {0x20: pystub(c, 2, ret=pr, this=True)}, nslots=0x24 // 4)
    c.emu.w32(0x700390, sysx)
    me = _node(c, 0)
    return [me]


S(0x4dbd10, 'GUESS recursive node update', 'thiscall', None, ret=None, gen=_g, note='batch34070')
