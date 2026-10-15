"""specs_s67537.py - cascade s6 batch 67537 (0x651040, thiscall(target) ret 4, no return value). The object keeps six state dwords (+0x20 / 0x24 / 0x28 / 0x2c / 0x30 / 0x34, the +0x2c and +0x20 ones
sometimes zero), the depth at +0x3c (negative sometimes) and an embedded stack object at +0x40 whose vtable (dword at +0x40) has slots 0xc / 0x34 / 0x3c / 0x84; 0x634273 (free) is a hook."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g651040(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    recs = [rnd(c, 0x30) for _ in range(3)]
    hook_rec(c, 0x634273, 2, pop=0)
    vt = e.alloc(0x100, 4)
    e.wbytes(vt, bytes(0x100))
    e.w32(vt + 0xc, pystub(c, 0, this=True))
    e.w32(vt + 0x34, pystub(c, 1, this=True, ret=lambda em, k: recs[k % 3]))
    e.w32(vt + 0x3c, pystub(c, 1, this=True))
    e.w32(vt + 0x84, pystub(c, 1, this=True, ret=lambda em, k: recs[(k + 1) % 3]))
    t = rnd(c, 0x80)
    _w(c, t + 0x40, vt)
    for off in (0x20, 0x24, 0x28, 0x2c, 0x30, 0x34):
        _w(c, t + off, r.choice([0, rnd(c, 0x10)]) if off in (0x20, 0x2c) else r.getrandbits(32))
    depth = r.choice([-2, 0, 1, 2, 3, 4, 5])
    target = r.choice([-1, 0, 1, 2, 3, 4, 6, depth, depth])
    _w(c, t + 0x3c, depth)
    return [t, target & 0xffffffff]


S(0x651040, 'GUESS set_state_stack_depth', 'thiscall', None, ret=None, gen=_g651040, note='batch67537')
