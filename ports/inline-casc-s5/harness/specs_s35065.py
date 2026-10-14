"""specs_s35065.py - 0x64d360 (thiscall(a) ret 4). this = 0x10100 random bytes with unaligned [this+0x1005d] = L and [this+0x10071] = table of 0x1000 entry pointers (entry (i >> 9) & 7); entry blocks have count [+0xc] in {0, 0, 1, 5} and
[+8] -> block whose byte +8 is 0, 1 or 255; a: block with [a+8] = src; 0x658f50 hooked (thiscall, returns 0..4), 0x658f10 hooked (thiscall, 1 arg, returns a record block with a word at +0x40 whose low 12 bits are
random, or 0), 0x63da80 hooked (thiscall, 1 arg)."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _g64d360(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 2, 3, 4])
    hook_rec(c, 0x658f50, 0, this=True, ret=n)
    recs = []
    for _ in range(4):
        if r.random() < 0.2:
            recs.append(0)
            continue
        rb = rnd(c, 0x48)
        e.wbytes(rb + 0x40, (r.randint(0, 0xfff) | (r.getrandbits(4) << 12)).to_bytes(2, 'little'))
        recs.append(rb)
    hook_rec(c, 0x658f10, 1, this=True, ret=lambda em, k: recs[min(k, 3)])
    hook_rec(c, 0x63da80, 1, this=True)
    ents = []
    for _ in range(8):
        eb = rnd(c, 0x20)
        e.w32(eb + 0xc, r.choice([0, 0, 1, 5]))
        sb = rnd(c, 0x10)
        e.wbytes(sb + 8, bytes([r.choice([0, 1, 255])]))
        e.w32(eb + 8, sb)
        ents.append(eb)
    tab = rnd(c, 0x4000)
    for i in range(0x1000):
        e.w32(tab + 4 * i, ents[(i >> 9) & 7])
    me = rnd(c, 0x10100)
    e.wbytes(me + 0x1005d, rnd(c, 0x10).to_bytes(4, 'little'))
    e.wbytes(me + 0x10071, tab.to_bytes(4, 'little'))
    a = rnd(c, 0x20)
    e.w32(a + 8, rnd(c, 0x10))
    return [me, a]


S(0x64d360, 'GUESS take references on resource targets', 'thiscall', None, ret=None, gen=_g64d360, note='batch35065')
