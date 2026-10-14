"""specs_s34140.py - 0x57dd10: [this+0x18c], [this+0x54] and child objects with slots 0xbc / 0x25c; engine 0x70039c with slot 0xbc and +0x1907 object holding a count at +0x1210 (0..0x40); hooked 0x41e290 and 0x563510.
0x5d3a10: words at +0x7a/+0x7c/+0x7e (the id's low word equals one of them in each of three quarters, high bits random), +0x4c pointer or 0, table slot 0x58 (null in a third), fallback object at +0x44, out a block with prefilled random dwords."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _g57dd10(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x41e290, 1, ret=rnd(c, 0x100), pop=0)
    hook_rec(c, 0x563510, 1, this=True)
    b = obj(c, 0x20, {0xbc: pystub(c, 1, this=True)}, nslots=0xc0 // 4)
    a = obj(c, 0x20, {0xbc: pystub(c, 1, this=True), 0x25c: pystub(c, 2, this=True, ret=lambda em, k: b)}, nslots=0x260 // 4)
    top = obj(c, 0x20, {0x25c: pystub(c, 2, this=True, ret=lambda em, k: a)}, nslots=0x260 // 4)
    c18c = obj(c, 0x20, {0xbc: pystub(c, 1, this=True)}, nslots=0xc0 // 4)
    q = rnd(c, 0x1220)
    e.w32(q + 0x1210, r.choice([0, 1, 7, 0x40, r.randrange(0x100)]))
    so = obj(c, 0x1920, {0xbc: pystub(c, 0, this=True, ret=r.getrandbits(32))}, nslots=0xc0 // 4)
    e.wbytes(so + 0x1907, q.to_bytes(4, 'little'))
    e.w32(0x70039c, so)
    me = rnd(c, 0x340)
    e.w32(me + 0x18c, c18c)
    e.w32(me + 0x54, top)
    return [me]


def _g5d3a10(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    t1 = obj(c, 0x20, {0x84: pystub(c, 1, this=True)}, nslots=0x88 // 4)
    t2 = obj(c, 0x20, {0x84: pystub(c, 1, this=True)}, nslots=0x88 // 4)
    tbl = obj(c, 0x20, {0x58: pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, t1, t1]))}, nslots=0x5c // 4)
    so = rnd(c, 0xa0)
    e.w32(so + 0x9b, tbl)
    e.w32(0x70039c, so)
    me = rnd(c, 0x90)
    ws = [r.getrandbits(16) for _ in range(3)]
    e4c = r.choice([0, 1, 5])
    k = r.choice([0, 1, 2, 2, 3])
    objp = t1 if r.random() < 0.7 else t2
    if k == 2 and e4c == 0:
        ws[2] = objp & 0xffff           # t = id is dereferenced: the id must be an object pointer whose low word is the id word
        ident = objp
    else:
        w = ws[k] if k < 3 else r.getrandbits(16)
        ident = w | (r.getrandbits(16) << 16 if r.random() < 0.5 else 0)
    e.wbytes(me + 0x7a, b''.join(w.to_bytes(2, 'little') for w in ws))
    e.w32(me + 0x44, t2)
    e.w32(me + 0x4c, e4c)
    out = rnd(c, 0x10)
    return [me, ident, out]


S(0x57dd10, 'GUESS set up scratch area and children', 'thiscall', None, ret=None, gen=_g57dd10, note='batch34140')
S(0x5d3a10, 'GUESS property get set', 'thiscall', None, ret='eax', gen=_g5d3a10, note='batch34140')
