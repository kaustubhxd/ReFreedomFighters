"""specs_s35169.py - 0x45fc90 (thiscall(s) ret 4, ret=None). Engine table (0x1d00 bytes): slot 0x130 (1 arg, recorded), unaligned dword +0x1c5d = pool base B (zero in 1/6; B = block + 0x10 of a 0x100-byte block whose dword at B-8 holds a size 0x10..0x60 with random upper bits).
s: inside the pool, exactly at the end B+size, one before B, at B, or an unrelated string block; the copy path strings get a NUL after 0..5 bytes. 0x41e290 hooked (cdecl, 1 arg, returns a fresh 0x40-byte block). this: 0x20 random bytes."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, sysobj


def _g45fc90(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x41e290, 1, pop=0, ret=rnd(c, 0x40))
    so = sysobj(c, table_slots={0x130: pystub(c, 1, this=True)}, table_size=0x1d00)
    tab = e.r32(so + 0x9b)
    blk = rnd(c, 0x100)
    B = blk + 0x10
    size = r.randint(0x10, 0x60)
    e.w32(B - 8, (r.getrandbits(4) << 28) | size)
    if r.random() < 1 / 6:
        base = 0
    else:
        base = B
    e.wbytes(tab + 0x1c5d, base.to_bytes(4, 'little'))
    k = r.choice(['in', 'in', 'end', 'before', 'at', 'other', 'other'])
    if k == 'in':
        s = B + r.randint(0, size - 1)
    elif k == 'end':
        s = B + size
    elif k == 'before':
        s = B - 1
    elif k == 'at':
        s = B
    else:
        s = rnd(c, 0x20)
    e.wbytes(s + r.randint(0, 5), b'\0')
    return [rnd(c, 0x20), s]


S(0x45fc90, 'GUESS set string field keeping pool strings by pointer', 'thiscall', None, ret=None, gen=_g45fc90, note='batch35169')
