"""specs_s35095.py - 0x4db3b0 (thiscall, no args, ret='eax'). Flags [this+0x3c]: no tested bit (a third), 0x40040000, 0x40000000 or 0x40000 only; chain of 1..4 nodes after this (this itself has a record too) ([+0x50] next, [+0x54] record -> [+0xc] block with the unaligned dword at +0x23 equal to 0x100021 in a third);
[this+0x5c] word non-zero when the 0x40000000 path is chosen (the exe reads address 0x5c otherwise, a crash the harness cannot compare); engine [+0x9b]: +8 = L (slot 0x4c returns an array of five 0x70-byte elements with random words at +0x5c, zero in a third; slot 0x5c (1 arg) returns an object
(byte +0x1c non-zero in half) or 0), +0xadc random dword."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, sysobj


def _g4db3b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    t = r.random()
    f = 0 if t < 1 / 3 else (0x40040000 if t < 0.55 else (0x40000000 if t < 0.8 else 0x40000))
    if f == 0:
        f = r.getrandbits(32) & ~0x40040000
    f |= r.getrandbits(32) & 0x3ffbffff if r.random() < 0.5 else 0
    if f & 0x40040000 == 0 and t >= 1 / 3:
        f |= 0x40000
    me = rnd(c, 0x70)
    e.w32(me + 0x3c, f)
    nxt = 0
    for j in range(r.choice([1, 2, 3, 4])):
        nd = rnd(c, 0x70) if j < 4 else me
        rec = rnd(c, 0x20) if r.random() < 0.8 else 0
        if rec:
            blk = rnd(c, 0x40)
            e.wbytes(blk + 0x23, (0x100021 if r.random() < 1 / 3 else r.getrandbits(32)).to_bytes(4, 'little'))
            e.w32(rec + 0xc, blk)
        e.w32(nd + 0x54, rec)
        e.w32(nd + 0x50, nxt)
        nxt = nd
    e.w32(me + 0x50, nxt)
    mrec = rnd(c, 0x20) if r.random() < 0.8 else 0
    if mrec:
        mblk = rnd(c, 0x40)
        e.wbytes(mblk + 0x23, (0x100021 if r.random() < 1 / 3 else r.getrandbits(32)).to_bytes(4, 'little'))
        e.w32(mrec + 0xc, mblk)
    e.w32(me + 0x54, mrec)
    w = r.randint(1, 4) if (f & 0x40000000) else r.choice([0, 1, 2, 7])
    e.wbytes(me + 0x5c, w.to_bytes(2, 'little'))
    arr = rnd(c, 0x70 * 5)
    for i in range(5):
        e.wbytes(arr + 0x70 * i + 0x5c, (0 if r.random() < 1 / 3 else r.randint(1, 5)).to_bytes(2, 'little'))
    objs = []
    for _ in range(4):
        o = rnd(c, 0x20)
        e.wbytes(o + 0x1c, bytes([0 if r.random() < 0.5 else r.randint(1, 255)]))
        objs.append(0 if r.random() < 0.2 else o)
    L = obj(c, 0x10, {0x4c: pystub(c, 0, this=True, ret=arr), 0x5c: pystub(c, 1, this=True, ret=lambda em, k: objs[min(k, 3)])}, nslots=0x20)
    so = sysobj(c, table_size=0xb00)
    tab = e.r32(so + 0x9b)
    e.w32(tab + 8, L)
    e.w32(tab + 0xadc, r.getrandbits(32))
    return [me]


S(0x4db3b0, 'GUESS find matching entry by chain or table index', 'thiscall', None, ret='eax', gen=_g4db3b0, note='batch35095')
