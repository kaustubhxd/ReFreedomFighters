"""specs_s2607.py - wider batch 2607. 0x439320 (GUESS guessSlotPick): stdcall(p, a2, flag), ret 0xc. p = 0 or [p] != 0 gives 0; flag != 0 gives 0x439380(p-4, a2)
(hooked: thiscall, 1 arg, ret 4 - verified as its own row); otherwise via the selector object at p+0x11: slot 0x14 (count), a2 < count (signed), slot 0x30(a2) -> 0x439570(x)
(hooked: stdcall, 1 arg)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _gen(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x439380, 1, this=True, ret=lambda em, k: r.getrandbits(32))
    hook_rec(c, 0x439570, 1, ret=lambda em, k: r.getrandbits(32))
    p = rnd(c, 0x100)
    e.w32(p, 0 if r.random() < 0.8 else r.choice([1, 7]))
    if r.random() < 0.85:
        cnt = r.choice([0, 3, 0x10, 6, r.getrandbits(32)])
        m = obj(c, 0x40, {0x14: pystub(c, 0, this=True, ret=cnt), 0x30: pystub(c, 1, this=True, ret=lambda em, k: r.getrandbits(32))})
        e.w32(p + 0x11, m)
    else:
        e.w32(p + 0x11, 0)
    a2 = r.choice([0, 1, 2, 5, 0x10, r.getrandbits(32), 0xffffffff])
    return [p if r.random() < 0.95 else 0, a2, r.choice([0, 1, 0x100, 0])]


S(0x439320, 'GUESS guessSlotPick (0x439320)', 'stdcall', None, ret='eax', gen=_gen, note='batch2607')
