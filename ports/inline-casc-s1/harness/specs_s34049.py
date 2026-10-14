"""specs_s34049.py - cascade escalation batch 34049.
0x4c5680: hooked 0x4c5770 (thiscall ret 4, returns a random value); the byte at +0x52 is random.
0x4dc030 (recursive tree update): a random tree of up to 3 levels (children at [owner+0x50], siblings at +0x60; [+0x50] of a node is a separate probe node used by the 0x4daff0 path; every non-root node has a non-null owner object at +0x54 with slot 0x24, whose record [+0xc] carries the
flag dword at +0x23 with bit 0x100000 set in two thirds of the cases); the node flag dword at +0x3c has bit 0x400 set in a fifth, bit 0x40000 in half, a non-zero low byte in 70%; [+0x64] / [+0x68] zero or
random (a node whose path needs a first child always has one); hooked 0x4da770 (1 arg), 0x4dc630 (2 args), 0x4dae60 and 0x4daff0 (returns an object with slot 0x320 or 0); the engine table has the observer
object at the unaligned +0x5d35 (slot 0x10) in three quarters of the cases. Call order across all recorders is logged."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec, sysobj


def _g4c5680(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4c5770, 1, ret=r.getrandbits(32), this=True)
    return [rnd(c, 0x60)]


def _g4dc030(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4da770, 1, this=True)
    hook_rec(c, 0x4dc630, 2, this=True)
    hook_rec(c, 0x4dae60, 0, this=True, pop=0)
    ycache = {}

    def yret(em, k):
        if k not in ycache:
            ycache[k] = 0 if r.random() < 0.4 else obj(c, 0x20, {0x320: pystub(c, 1, this=True)}, nslots=0x330 // 4)
        return ycache[k]
    hook_rec(c, 0x4daff0, 0, ret=yret, this=True, pop=0)
    so = sysobj(c, table_size=0x5e00)
    tbl = e.r32(so + 0x9b)
    observer = 0 if r.random() < 0.25 else obj(c, 0x20, {0x10: pystub(c, 1, this=True)}, nslots=0x20 // 4)
    e.wbytes(tbl + 0x5d35, observer.to_bytes(4, 'little'))

    def mk(depth, root=False):
        n = rnd(c, 0x80)
        flags = r.getrandbits(32)
        flags = (flags | 0x400) if r.random() < 0.2 else (flags & ~0x400)
        flags = (flags | 0x40000) if r.random() < 0.5 else (flags & ~0x40000)
        if r.random() < 0.7:
            flags |= 1 << r.randrange(0, 8)
        else:
            flags &= ~0xff
        e.w32(n + 0x3c, flags & 0xffffffff)
        kids = []
        if depth < 3:
            for _ in range(r.choice([0, 1, 2, 2])):
                kids.append(mk(depth + 1))
        probe = rnd(c, 0x80)
        e.w32(probe + 0x54, rnd(c, 0x20))
        e.w32(n + 0x50, probe)
        for a, b in zip(kids, kids[1:] + [0]):
            e.w32(a + 0x60, b)
        if root and r.random() < 0.2:
            e.w32(n + 0x54, 0)
        else:
            blk = rnd(c, 0x40)
            w = r.getrandbits(32)
            w = (w | 0x100000) if r.random() < 2 / 3 else (w & ~0x100000)
            e.wbytes(blk + 0x23, (w & 0xffffffff).to_bytes(4, 'little'))
            rec = rnd(c, 0x20)
            e.w32(rec + 0xc, blk)
            own = obj(c, 0x60, {0x24: pystub(c, 1, this=True)}, nslots=0x28 // 4)
            e.w32(own + 0xc, blk)
            e.w32(own + 0x50, kids[0] if kids else 0)
            e.w32(n + 0x54, own)
        e.w32(n + 0x64, 0 if r.random() < 0.4 else (r.getrandbits(32) | 1))
        e.w32(n + 0x68, 0 if r.random() < 0.4 else (r.getrandbits(32) | 1))
        return n
    return [mk(0, True)]


S(0x4c5680, 'GUESS forward a byte to 0x4c5770', 'thiscall', None, ret='eax', gen=_g4c5680, note='batch34049')
S(0x4dc030, 'GUESS recursive tree update', 'thiscall', None, ret=None, gen=_g4dc030, note='batch34049')
