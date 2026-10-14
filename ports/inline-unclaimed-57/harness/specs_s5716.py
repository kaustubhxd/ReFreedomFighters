"""specs_s5716.py - unclaimed-57, batch 16: 0x563d40 (GUESS). Stdcall, three stack arguments (a1, p, lim), ret 0xc, returns eax. The
cell p points at a random dword; lim is random or the cell's next value (so both branches run). Leaf: no calls."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _step(c):
    cell = _rnd(c, 8)
    cur = c.rng.choice([0, 1, 5, 0x7ffffffe, 0xffffffff, c.rng.getrandbits(32)])
    c.emu.w32(cell, cur)
    nxt = (cur + 1) & 0xffffffff
    lim = c.rng.choice([nxt, (nxt + 1) & 0xffffffff, (nxt - 1) & 0xffffffff, c.rng.getrandbits(32)])
    return [c.rng.getrandbits(32), cell, lim]


S(0x563d40, 'unnamed_563d40 (GUESS) stdcall', 'stdcall', None, ret='eax', gen=_step,
  note='unclaimed-57 batch 16; leaf; counter step with a reset value a1')
