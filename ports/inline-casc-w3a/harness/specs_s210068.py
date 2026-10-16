"""specs_s210068.py - Sonnet-w3a: 0x5edf70. Text built from {a, b, backslash, n} so literal backslash-n pairs are common; vector of element pointers at this+5 / this+9 (4 slots always valid), count at this+0x19, mode word this+0x11 (set to 1 by a hook side effect after the first line so the second branch is reachable), width flag this+0x6a."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def _ub(c, a, v): c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def g5edf70(c):
    clear_hooks(c)
    e = c.emu
    holder = []
    mode_after = c.rng.random() < 0.7
    n = c.rng.choice([0, 1, 2, 3, 4])
    if mode_after and n == 0:
        n = 1  # an empty vector with mode 1 would index before the buffer
    idx = c.rng.choice([0, 1, 2, 3, 4, 5, n, n, n + 1])
    begin = rnd(c, 0x80)
    for i in range(16):
        el = rnd(c, 0x10)
        ob = rnd(c, 0x10)
        e.w32(el, ob)
        e.w32(begin + 4 * i, el)
    widths = [c.rng.choice([0, 1, 5, 0x80000000, _r(c) & 0xff]) for _ in range(6)]

    def s5aca(emu, k):
        if mode_after:
            _ub(c, holder[0] + 0x11, 1)
    hook_rec(c, 0x5ee920, 0, ret=_r(c), this=True)
    hook_rec(c, 0x5aca30, 2, ret=_r(c), this=True, side=s5aca)
    hook_rec(c, 0x5ac5d0, 1, ret=_r(c), this=True)
    hook_rec(c, 0x5ab9d0, 0, ret=lambda emu, k: widths[min(k, 5)], this=True)
    def s5ee1(emu, k):
        emu.calllog.append(('mode', emu.r32(holder[0] + 0x11) if False else int.from_bytes(emu.rbytes(holder[0] + 0x11, 4), 'little')))
    hook_rec(c, 0x5ee110, 3, ret=_r(c), this=True, side=s5ee1)
    s = rnd(c, 0x90)
    holder.append(s)
    _ub(c, s + 5, begin); _ub(c, s + 9, begin + 4 * n)
    _ub(c, s + 0x11, c.rng.choice([0, 0, _r(c), 5]))
    _ub(c, s + 0x19, idx)
    e.wbytes(s + 0x6a, bytes([c.rng.choice([0, 1])]))
    _ub(c, s + 0x45, c.rng.choice([0, _r(c)]))
    txt = bytes(c.rng.choice(b'ab\\nn\\n') for _ in range(c.rng.choice([0, 1, 2, 3, 5, 8, 12]))) + b'\0'
    st = rnd(c, 0x20)
    e.wbytes(st, txt)
    return [s, st, _r(c)]


S(0x5edf70, 'split_text_on_backslash_n', 'thiscall', None, ret=None, gen=g5edf70, note='batch210068')
