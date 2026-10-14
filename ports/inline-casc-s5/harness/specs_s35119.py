"""specs_s35119.py - 0x4f0040 (thiscall(n) ret 4, ret='eax'). this: random 0xb0 bytes with the unaligned string pointer at +0x97 (a UTF-8 text of 0..6 code points of 1 to 3 bytes plus NUL, decoded by the real 0x4cc500) and the object at +0x9f (slot 0x280: 1 arg, returns a glyph record
with a signed byte at +0x10; slot 0x28c: 2 args, returns a small signed number); n in -1..8 (the loop runs at least once only for n > 0)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g4f0040(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    txt = b''
    for _ in range(r.randint(0, 6)):
        cp = r.choice([0x41, 0x7a, 0x20, 0xe9, 0x3b1, 0x20ac, 0x4e2d, 0x2603])
        txt += chr(cp).encode('utf-8')
    txt += b'\0'
    sp = rnd(c, 0x20)
    e.wbytes(sp, txt)
    recs = [rnd(c, 0x20) for _ in range(4)]
    kern = [r.randint(-3, 3) & 0xffffffff for _ in range(4)]
    o = obj(c, 0x20, {0x280: pystub(c, 1, this=True, ret=lambda em, k: recs[min(k, 3)]), 0x28c: pystub(c, 2, this=True, ret=lambda em, k: kern[min(k, 3)])}, nslots=0xa4)
    me = rnd(c, 0xb0)
    e.wbytes(me + 0x97, sp.to_bytes(4, 'little'))
    e.wbytes(me + 0x9f, o.to_bytes(4, 'little'))
    return [me, r.randint(-1, 8) & 0xffffffff]


S(0x4f0040, 'GUESS measure string width with kerning', 'thiscall', None, ret='eax', gen=_g4f0040, note='batch35119')
