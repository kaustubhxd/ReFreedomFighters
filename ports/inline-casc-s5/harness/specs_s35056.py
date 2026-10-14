"""specs_s35056.py - 0x4973b0 (thiscall(h) ret 4, ret='eax'). h: 0 (1/8), tagged with 0x40000000 and a multiple-of-16 offset inside / outside the limit ([this+0x65], unaligned) or unaligned offset, or untagged random;
[[this+0x14]+4] = block with the flag dword at +0x3c random; [this+8] object with slot 0x14 (1 arg, AL true in half; garbage upper bytes) and +0x10 mask 0xff/0xf; [this+0xc] = table of 256 dwords;
logger at 0x700390 (slot 0x20 -> object with slot 0x2c, 3 args, caller-popped)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g4973b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    lg2 = obj(c, 0x20, {0x2c: pystub(c, 3, this=True, pop=0)}, nslots=0x20)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=lg2, this=True)}, nslots=0x20)
    e.w32(0x700390, lg)
    base = rnd(c, 0x100)
    mid = rnd(c, 0x10)
    e.w32(mid + 4, base)
    o = obj(c, 0x20, {0x14: pystub(c, 1, this=True, ret=(r.getrandbits(24) << 8) | (r.choice([1, 2, 0x80]) if r.random() < 0.5 else 0))}, nslots=8)
    e.w32(o + 0x10, r.choice([0xff, 0xf, 0x3]))
    me = rnd(c, 0x80)
    e.w32(me + 8, o)
    e.w32(me + 0xc, rnd(c, 0x400))
    e.w32(me + 0x14, mid)
    limit = r.choice([0x10, 0x30, 0x60, 0xe0])
    e.wbytes(me + 0x65, limit.to_bytes(4, 'little'))
    k = r.random()
    if k < 1 / 8:
        h = 0
    elif k < 0.6:
        off = r.choice([0, 0x10, 0x20, 0x30, 0x40, 0x60, 0x70, 0xd0, 0xe0, 0x8, 0x11, r.randrange(0x100)])
        h = 0x40000000 | off | (0x80000000 if r.random() < 0.1 else 0)
        if off + 0x40 <= 0x100:
            e.w32(base + off + 0x3c, r.choice([0, 0x4000000, r.getrandbits(32)]))
    else:
        h = r.getrandbits(32) & ~0x40000000
    return [me, h]


S(0x4973b0, 'GUESS resolve handle tagged or hashed', 'thiscall', None, ret='eax', gen=_g4973b0, note='batch35056')
