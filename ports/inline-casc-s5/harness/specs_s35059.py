"""specs_s35059.py - 0x442e20 (thiscall(n) ret 4). n: random block; [n+0x54] = r (null in 1/5) with [r+0xc] -> block whose unaligned dword at +0x23 has bit 0x100000 set in 2/3 of the cases; r vtable slots 0x310 and
0x30c (AL true in a third each); [r+0x50] chain of 0..3 children (next at +0x60); [this+8] equals n in a quarter; this vtable slot 0x2f4 (1 arg); dword [n+0x3c] has 0x40000 in half; 0x4db9a0 and 0x4da720 hooked
(thiscall, 1 arg; 0x4db9a0 returns AL true in half with garbage upper bytes)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g442e20(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    al = lambda p: ((r.getrandbits(24) << 8) | (r.choice([1, 2, 0x80]))) if r.random() < p else (r.getrandbits(24) << 8)
    hook_rec(c, 0x4db9a0, 1, this=True, ret=al(0.5))
    hook_rec(c, 0x4da720, 1, this=True)
    n = rnd(c, 0x80)
    if r.random() < 0.5:
        e.w32(n + 0x3c, r.getrandbits(32) | 0x40000)
    else:
        e.w32(n + 0x3c, r.getrandbits(32) & ~0x40000)
    if r.random() < 0.2:
        e.w32(n + 0x54, 0)
    else:
        blk = rnd(c, 0x40)
        fl = r.getrandbits(32)
        fl = fl | 0x100000 if r.random() < 2 / 3 else fl & ~0x100000
        e.wbytes(blk + 0x23, fl.to_bytes(4, 'little'))
        nxt = 0
        for _ in range(r.choice([0, 1, 2, 3])):
            ch = rnd(c, 0x70)
            e.w32(ch + 0x60, nxt)
            nxt = ch
        rr = obj(c, 0x70, {0x310: pystub(c, 0, this=True, ret=al(1 / 3)), 0x30c: pystub(c, 0, this=True, ret=al(1 / 3))}, nslots=0xd0)
        e.w32(rr + 0xc, blk)
        e.w32(rr + 0x50, nxt)
        e.w32(n + 0x54, rr)
    me = obj(c, 0x20, {0x2f4: pystub(c, 1, this=True)}, nslots=0xbe)
    e.w32(me + 8, n if r.random() < 0.25 else rnd(c, 0x10))
    return [me, n]


S(0x442e20, 'GUESS walk children of flagged node', 'thiscall', None, ret=None, gen=_g442e20, note='batch35059')
