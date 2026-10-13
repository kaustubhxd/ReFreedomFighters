"""specs_s2505.py - decomp area 24, batch 2505.
0x634730 (CRT 64-bit left shift helper): value EDX:EAX, count CL (the other ECX bits random), result EDX:EAX, plain ret."""
from pilot import S
from recruits_util import clear_hooks


def _gen(c):
    clear_hooks(c)
    r = c.rng
    k = r.random()
    if k < 0.25:
        n = r.randint(0, 31)
    elif k < 0.5:
        n = r.randint(32, 63)
    elif k < 0.65:
        n = r.choice([0, 1, 31, 32, 33, 63, 64, 65, 127, 128, 255, 0x40, 0x20, 0x1f])
    else:
        n = r.randint(0, 255)
    return [r.getrandbits(32), r.getrandbits(32), (r.getrandbits(24) << 8) | n]


S(0x634730, 'CRT 64-bit left shift (__allshl)', ('regs', ['eax', 'edx', 'ecx']), None, ret='eax:edx', gen=_gen, note='batch2505')
