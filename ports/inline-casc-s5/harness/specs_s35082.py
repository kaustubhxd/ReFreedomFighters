"""specs_s35082.py - 0x438eb0 (stdcall(p) ret 4, ret='al'). p null in 1/6 (log path: logger at 0x700390, slot 0x20 -> object with slot 0x2c, 2 args, caller-popped); else a random 0x40-byte block with byte +0xc zero in a quarter,
kind dword [p] among 0, 1, 2, 3, random; 0x439670 hooked (thiscall, AL byte values incl. garbage bits; used with `and`), 0x438e30 hooked (thiscall, AL random)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g438eb0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x439670, 0, this=True, ret=(r.getrandbits(24) << 8) | r.choice([0, 1, 2, 0x80, 0xff, r.getrandbits(8)]))
    hook_rec(c, 0x438e30, 0, this=True, ret=(r.getrandbits(24) << 8) | r.choice([0, 1, 0x80, r.getrandbits(8)]))
    lg2 = obj(c, 0x20, {0x2c: pystub(c, 2, this=True, pop=0)}, nslots=0x20)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=lg2, this=True)}, nslots=0x20)
    e.w32(0x700390, lg)
    if r.random() < 1 / 6:
        return [0]
    p = rnd(c, 0x40)
    if r.random() < 0.25:
        e.wbytes(p + 0xc, b'\0')
    else:
        e.wbytes(p + 0xc, bytes([r.choice([1, 2, 3, 0x80, 0xff])]))
    e.w32(p, r.choice([0, 1, 2, 3, 0, 1, 3, r.getrandbits(32)]))
    return [p]


S(0x438eb0, 'GUESS evaluate entry by kind', 'stdcall', None, ret='al', gen=_g438eb0, note='batch35082')
