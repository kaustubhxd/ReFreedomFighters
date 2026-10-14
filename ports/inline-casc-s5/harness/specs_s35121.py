"""specs_s35121.py - 0x45c880 (thiscall(m, x) ret 8). m: object with vtable slot 0x64 (1 arg) and flags dword [m+0x14] among 0, 0x200, 0x8, 0x208, random; this: vtable slot 0x40 (0 args), [+8] -> block whose dword +0x3c has bit 0x400 in half, [+0x10] -> record (dword +4 random,
dword +0x10 zero in half, else a heap block); 0x41e290 hooked (cdecl, 1 arg, returns a fresh block, null in a quarter of the calls)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g45c880(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    blk = rnd(c, 0x20)
    hook_rec(c, 0x41e290, 1, pop=0, ret=lambda em, k: 0 if r.random() < 0.25 else blk)
    f = r.choice([0, 0x200, 0x8, 0x208, 0x1, 0x9, r.getrandbits(32), r.getrandbits(32) | 8])
    m = obj(c, 0x40, {0x64: pystub(c, 1, this=True)}, nslots=0x1a)
    e.w32(m + 0x14, f)
    rec = rnd(c, 0x20)
    if r.random() < 0.5:
        e.w32(rec + 0x10, 0)
    pb = rnd(c, 0x50)
    fl = r.getrandbits(32)
    fl = (fl | 0x400) if r.random() < 0.5 else (fl & ~0x400)
    e.w32(pb + 0x3c, fl)
    me = obj(c, 0x20, {0x40: pystub(c, 0, this=True)}, nslots=0x11)
    e.w32(me + 8, pb)
    e.w32(me + 0x10, rec)
    return [me, m, r.getrandbits(32)]


S(0x45c880, 'GUESS merge flag bits into shared record', 'thiscall', None, ret=None, gen=_g45c880, note='batch35121')
