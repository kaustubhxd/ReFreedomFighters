"""specs_s35022.py - 0x4e8000. Tree object (vtable slots 0x18 (returns a random pool node), 0x28 (2 args)); [this+8] = nil node, [this+4] = root; a pool of 4 nodes (0x14 bytes, random payload and colour byte
with the black value 0 in half) whose parent/left/right pointers are drawn from the pool and nil (nil in about a third of the cases), so every branch (n with a nil child or not, parent nil / left child /
right child, y == n or not, nil result) is hit; 0x4e8450 is a thiscall recorder (1 arg)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g4e8000(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4e8450, 1, this=True)
    nil = rnd(c, 0x14)
    pool = [rnd(c, 0x14) for _ in range(4)]
    allp = pool + [nil]

    def pick():
        return nil if r.random() < 0.33 else r.choice(pool)
    for nd in pool + [nil]:
        for off in (0, 4, 8):
            e.w32(nd + off, pick())
        if r.random() < 0.5:
            e.wbytes(nd + 0x10, b'\0')
    sel = nil if r.random() < 0.2 else pool[r.randrange(4)]
    me = obj(c, 0x20, {0x18: pystub(c, 1, this=True, ret=lambda em, k: sel), 0x28: pystub(c, 2, this=True)}, nslots=0x2c // 4)
    e.w32(me + 4, r.choice(allp))
    e.w32(me + 8, nil)
    return [me, pool[0]]


S(0x4e8000, 'GUESS tree node unlink and rebalance', 'thiscall', None, ret='eax', gen=_g4e8000, note='batch35022')
