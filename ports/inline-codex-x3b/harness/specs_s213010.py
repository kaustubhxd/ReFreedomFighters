"""specs_s213010.py - batch 213010: parser step with callback (sibling of 0x62e070), Sonnet-w3b."""
from pilot import S
from recruits_util import rnd, clear_hooks, pystub


def g62dfa0(c):
    clear_hooks(c)
    r = c.rng
    o = rnd(c, 0x20)
    if r.random() < 0.5:
        c.emu.w32(o + 0xc, 0)
    e = rnd(c, 0x60)
    c.emu.w32(e + 0x1c, pystub(c, 4, ret=r.choice([0, 1, r.getrandbits(32)]), pop=0))
    b = r.randint(9, 0x1f) if r.random() < 0.9 else r.getrandbits(32)
    if r.random() < 0.15:
        b = 0x1c
    return [o, b, r.getrandbits(32), r.getrandbits(32), e]


S(0x62dfa0, 'parser_step_cb2', 'cdecl', None, ret='eax', gen=g62dfa0)
