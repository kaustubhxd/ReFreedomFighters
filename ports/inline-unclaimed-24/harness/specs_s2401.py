"""specs_s2401.py - decomp area 24, batch 2401: ZActionControlMap::ModifyGameActions (0x5b3ef0).
The map object has random bytes; the flags that gate the branches are zero with probability 0.7 (so the stick and
accumulation paths run often). The player object (pointer at map+0x5f) has a random stick value at +0x9e3 (sometimes
zero, NaN, or large). The engine object (0x70039c) has the time at +0x40 and the mode byte at +0x6c.
The length helper (0x4dfda0) and the normaliser (0x4dff10) run as exe code (they use the sqrt import, which pe_emu
implements)."""
import math
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, sysobj


def _gen(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    now = r.randint(10, 1 << 20)
    so = sysobj(c)
    e.w32(so + 0x40, now)
    e.w8(so + 0x6c, r.choice([0, 0, 0, 1]))
    m = rnd(c, 0x300)
    flagoffs = [0x1b4, 0x1b3, 0x1b1, 0x1bc, 0x189, 0x22f, 0x1a3, 0x55, 0x56, 0x168, 0x1bd, 0x1b6, 0x4c]
    for off in flagoffs:
        e.w8(m + off, 0 if r.random() < 0.7 else r.randint(0, 255))
    for off in (0x1a0, 0x19f, 0x1a1, 0x1a2):
        e.w8(m + off, r.choice([r.randint(0, 0x3f), 0x40, r.randint(0x41, 0x7f), 0]))
    e.w32(m + 0x4d, r.choice([3, 3, 1, 0]))
    e.w8(m + 0x4c, 0 if r.random() < 0.8 else 1)
    for off in (0x18b, 0x18f, 0x193, 0x197):
        e.wf32(m + off, r.choice([0.0, 0.1, -0.1, r.uniform(-1.5, 1.5), r.uniform(-0.6, 0.6)]))
    for off in (0x171, 0x172, 0x173, 0x174, 0x169, 0x16d, 0x1ab, 0x1af, 0x1a6, 0x1aa):
        e.w8(m + off, r.randint(0, 255))
    player = rnd(c, 0xa00)
    v = r.choice([0.0, r.uniform(-1.2, 1.2), r.uniform(-0.4, 0.4), float('nan'), r.uniform(0.9, 1.1)])
    e.wf32(player + 0x9e3, v)
    e.w32(m + 0x5f, player)
    return [m]


S(0x5b3ef0, 'ZActionControlMap::ModifyGameActions', 'thiscall', None, gen=_gen, note='batch2401')
