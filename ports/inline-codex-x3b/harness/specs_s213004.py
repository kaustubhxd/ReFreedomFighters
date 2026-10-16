"""specs_s213004.py - batch 213004: selector forwarder and bit-scan block copy, Sonnet-w3b."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def g574af0(c):
    clear_hooks(c)
    r = c.rng
    o = rnd(c, 0x110)
    hook_rec(c, 0x5aa660, 4, ret=r.getrandbits(32), this=True)
    sel = r.randint(0, 0x14) if r.random() < 0.92 else r.getrandbits(32)
    flag = r.choice([0, 1, 0x100, 0xff, r.getrandbits(32)])
    return [o, sel, r.getrandbits(32), flag, r.getrandbits(32), r.getrandbits(32)]


def _terminates(x, mask):
    for _ in range(40):
        x = (x << 1) & 0xffffffff
        if mask & x:
            return True
        if x == 0:
            return False
    return False


def g57f9b0(c):
    clear_hooks(c)
    r = c.rng
    while True:
        x = r.choice([0, 1, 1, 1, 2, 3, 5, 0x80000000, r.getrandbits(32), r.getrandbits(5)])
        mask = r.choice([1 << r.randint(1, 8), 1 << r.randint(1, 31), r.getrandbits(32),
                         (1 << r.randint(1, 5)) | r.getrandbits(32) << 8, 0x16, 0x1c])
        mask &= 0xffffffff
        if _terminates(x, mask):
            break
    o = rnd(c, 0xb0)
    c.emu.w32(o + 0xa4, mask)
    p = rnd(c, 8)
    c.emu.w32(p, x)
    dst = rnd(c, 0x40)
    return [o, p, dst]


S(0x574af0, 'forward_by_sel', 'thiscall', None, ret='eax', gen=g574af0)
S(0x57f9b0, 'bitscan_block_copy', 'thiscall', None, ret='eax', gen=g57f9b0)
