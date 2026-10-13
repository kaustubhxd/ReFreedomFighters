"""specs_s2495.py - decomp area 24, batch 2495 (residue 3, smallest first).
0x4cf070 (GUESS, REFTAB element release): thiscall, ret 4. Three paths: count > 0 with the index at arg+4 minus this+0x18 positive
(array at arg+0), count > 0 with it negative (arg+0 points to a cell holding the array, index this+0x10 - this+0x18), and count <= 0
(slot 0x78 of this, recorder, returns the address of a cell holding the block). The block is passed to __builtin_delete (0x634273,
cdecl, recorded, size 1) and then REFTAB::RunDelRef 0x4cef90 (recorder, thiscall, one argument) runs on this with the argument."""
from pilot import S
from recruits_util import rnd, pystub, obj, clear_hooks, hook_rec


def _rel(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x634273, 2, pop=0)
    hook_rec(c, 0x4cef90, 1, this=True)
    arr = e.alloc(0x200, 4)
    for i in range(0x80):
        e.w32(arr + 4 * i, r.getrandbits(32))
    cell = e.alloc(4, 4)
    e.w32(cell, arr)
    cell2 = e.alloc(4, 4)
    e.w32(cell2, r.getrandbits(32))
    self_ = obj(c, 0x40, {0x78: pystub(c, 1, ret=cell2)})
    arg = rnd(c, 0x40)
    mode = r.choice(['pos', 'neg', 'else'])
    self18 = r.randint(0, 100)
    e.w32(self_ + 0x18, self18)
    if mode == 'pos':
        k = r.randint(0, 12)
        e.w32(self_ + 0x10, r.randint(0, 100))
        e.w32(arg + 0, arr)
        e.w32(arg + 4, (self18 + k) & 0xffffffff)
        e.w32(arg + 8, r.choice([1, 2]))
    elif mode == 'neg':
        m = r.randint(0, 12)
        j = r.randint(1, 12)
        e.w32(self_ + 0x10, (self18 + m) & 0xffffffff)
        e.w32(arg + 0, cell)
        e.w32(arg + 4, (self18 - j) & 0xffffffff)
        e.w32(arg + 8, 1)
    else:
        e.w32(self_ + 0x10, r.getrandbits(32))
        e.w32(arg + 0, r.getrandbits(32))
        e.w32(arg + 4, r.getrandbits(32))
        e.w32(arg + 8, r.choice([0, -1 & 0xffffffff]))
    return [self_, arg]


S(0x4cf070, 'GUESS REFTAB element release', 'thiscall', None, ret=None, gen=_rel, note='batch2495')
