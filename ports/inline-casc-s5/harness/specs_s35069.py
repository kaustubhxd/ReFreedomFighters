"""specs_s35069.py - 0x5af8f0 (thiscall(a, n) ret 8, ret='eax'). 0x5af130 hooked (thiscall, 1 arg) returning a record r (null in 1/6; [r] = X null in 1/6) where X is an object with slot 0x2c4 (2 args, returns o or 0 by call);
engine table (+0xadc dword random): slot 0x4c (3 args, returns a random id); o: slots 0x2f0 (1 arg), 0x2d0 (2 args); n in 0..4."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, sysobj


def _g5af8f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    os_ = [0 if r.random() < 0.25 else obj(c, 0x20, {0x2f0: pystub(c, 1, this=True), 0x2d0: pystub(c, 2, this=True)}, nslots=0xc0) for _ in range(4)]
    X = obj(c, 0x20, {0x2c4: pystub(c, 2, this=True, ret=lambda em, k: os_[min(k, 3)])}, nslots=0xb2)
    t = r.random()
    if t < 1 / 6:
        rec = 0
    else:
        rec = rnd(c, 0x10)
        e.w32(rec, 0 if t < 2 / 6 else X)
    hook_rec(c, 0x5af130, 1, this=True, ret=rec)
    so = sysobj(c, table_slots={0x4c: pystub(c, 3, this=True, ret=lambda em, k: (k + 1) * 0x101)}, table_size=0xb00)
    e.w32(e.r32(so + 0x9b) + 0xadc, r.getrandbits(32))
    me = obj(c, 0x20, {}, nslots=2)
    e.w32(me, r.getrandbits(32))
    e.w32(me + 4, rnd(c, 0x10))
    return [me, r.getrandbits(32), r.choice([0, 1, 2, 3, 4])]


S(0x5af8f0, 'GUESS repeat lookup and notify on entry', 'thiscall', None, ret='eax', gen=_g5af8f0, note='batch35069')
