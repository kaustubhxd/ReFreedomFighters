"""specs_s67546.py - cascade s6 batch 67546 (0x596ef0, thiscall(a, flag) ret 8, return value unused). The primary list (count +0x2e6: 0 / 1-3 / negative, entries from +0xe6) and the secondary list
(count +0x1fae, current index +0x1fb2, entries from +0x1dae drawn from the same pool of values so lookups hit) are random; sys[0x1b5d] is 1 or other; 0x597050 / 0x597680 (index or -1) /
0x597a70 (bool) / 0x597e00 are hooks."""
from pilot import S
from recruits_util import rnd, sysobj, clear_hooks, hook_rec


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g596ef0(c):
    clear_hooks(c)
    r = c.rng
    pool = [0x1111, 0x2222, 0x3333, 0x4444]
    so = sysobj(c)
    _w(c, so + 0x1b5d, r.choice([1, 1, 0, 2]))
    t = rnd(c, 0x2000)
    cnt = r.choice([0, 0, 0, 1, 2, 3, -1])
    _w(c, t + 0x2e6, cnt)
    for i in range(4):
        _w(c, t + 0xe6 + 4 * i, r.choice(pool))
    n2 = r.choice([0, 1, 2, 3, 4])
    _w(c, t + 0x1fae, n2)
    _w(c, t + 0x1fb2, r.randrange(0, n2 + 1) if n2 else r.choice([0, 1]))
    for i in range(6):
        _w(c, t + 0x1dae + 4 * i, r.choice(pool))
    hook_rec(c, 0x597050, 3, this=True)
    hook_rec(c, 0x597680, 2, this=True, ret=lambda em, k: r.choice([0xffffffff, 0, 1, 2, 3][:max(2, n2 + 1)]) if n2 else 0xffffffff)
    hook_rec(c, 0x597a70, 1, this=True, ret=lambda em, k: r.choice([0, 1, 0x100]))
    hook_rec(c, 0x597e00, 1, this=True)
    return [t, r.choice([0, 1, 2, 5, 5, 7]), r.choice([0, 1, 0x100, 0x101])]


S(0x596ef0, 'GUESS apply_action_to_lists', 'thiscall', None, ret=None, gen=_g596ef0, note='batch67546')
