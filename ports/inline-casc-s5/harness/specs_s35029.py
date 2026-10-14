"""specs_s35029.py - 0x5fe560 (thiscall(t) ret 4). A node has a child pointer +0x9c (null in 2/5; the child is a second node without a child), offsets +0x84 / +0x80 and base +0x98; the two tables (counts 0..3, six-byte
entries with unaligned dword offsets 0..0x40) live in one region; the target t has an unaligned data pointer at +0x9e and vtable slots 0x34 and 0x4 (1 arg, recorded)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _node(c, child):
    r = c.rng
    e = c.emu
    R = rnd(c, 0x100)
    n = rnd(c, 0xc0)
    a1 = 0x10
    a2 = 0x60
    for a in (a1, a2):
        cnt = r.choice([0, 1, 2, 3])
        e.w32(R + a, cnt)
        for i in range(4):
            e.wbytes(R + a + 4 + 6 * i, r.randint(0, 0x40).to_bytes(4, 'little'))
    e.w32(n + 0x84, a1)
    e.w32(n + 0x80, a2)
    e.w32(n + 0x98, R)
    e.w32(n + 0x9c, child)
    return n


def _g5fe560(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    child = 0 if r.random() < 0.4 else _node(c, 0)
    me = _node(c, child)
    t = obj(c, 0xc0, {0x34: pystub(c, 1, this=True), 0x4: pystub(c, 1, this=True)}, nslots=0x10)
    D = rnd(c, 0x100)
    e.wbytes(t + 0x9e, D.to_bytes(4, 'little'))
    return [me, t]


S(0x5fe560, 'GUESS apply packed index tables to target', 'thiscall', None, ret=None, gen=_g5fe560, note='batch35029')
