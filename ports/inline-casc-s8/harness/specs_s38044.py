"""specs_s38044.py - cascade s8 batch 38044. The mapping is built so that most cases pass the two checks: entries below 0x80 whose class (read from the image table 0x6bf2f4) is not 0 / 0x1c map to
themselves, other entries are drawn from -1, -2..-4, small codes whose class is 0 / 0x1c, 0x80..0xffff (incl. the surrogate range, 0xfffe / 0xffff and high byte 0 values) and 12% of the cases carry one
poisoned entry (-5, > 0xffff, a mismatched ASCII code) to exercise the failure returns. The class / bitmap tables are read from the exe image (fixed data). 0x626e10 is a hook returning a random byte.
The output block is 0x800 random bytes."""
import struct
from pilot import S
from recruits_util import clear_hooks, hook_rec


def _g626b00(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    cls = e.rbytes(0x6bf2f4, 0x80)
    plain = [j for j in range(0x80) if cls[j] not in (0, 0x1c)]
    soft = [j for j in range(0x80) if cls[j] in (0, 0x1c)]
    vals = []
    for i in range(256):
        if i < 0x80 and i in plain:
            vals.append(i)
            continue
        k = r.random()
        if k < 0.08:
            v = -1
        elif k < 0.16:
            v = r.choice([-2, -3, -4])
        elif k < 0.30 and soft:
            v = r.choice(soft)
            if i < 0x80 and i in plain:
                v = i
        elif k < 0.36:
            v = r.randrange(0xd800, 0xe000)
        elif k < 0.40:
            v = r.choice([0xfffe, 0xffff, 0xff00, 0xff10])
        elif k < 0.45:
            v = r.randrange(0x80, 0x100)
        else:
            v = r.randrange(0x100, 0xd800)
        vals.append(v)
    if r.random() < 0.12:
        j = r.randrange(256)
        vals[j] = r.choice([-5, 0x10000, 0x12345, -100, 0x7fffffff])
    if r.random() < 0.04 and plain:
        j = r.choice(plain)
        vals[j] = (j + 1) % 0x80
    mp = e.alloc(4 * 256, 4)
    e.wbytes(mp, struct.pack('<256i', *vals))
    dst = e.alloc(0x800, 4)
    e.wbytes(dst, r.randbytes(0x800))
    hook_rec(c, 0x626e10, 2, pop=0, ret=lambda em, k: r.getrandbits(32))
    return [dst, mp, r.choice([0, 1, 5, r.getrandbits(32)]), r.getrandbits(32)]


S(0x626b00, 'GUESS build 256-entry character class table', 'cdecl', None, ret='eax', gen=_g626b00, note='batch38044')
