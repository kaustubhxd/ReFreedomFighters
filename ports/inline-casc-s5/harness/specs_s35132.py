"""specs_s35132.py - 0x48fed0 (thiscall(a) ret 4). Engine table (0x6000 bytes so the unaligned dword at +0x5d35 is readable): slot 0x178 (0 args, AL true in a third), slot 0x50 (1 arg recorded; random result); [tab+0x5d35] = X (null in 1/4) with slot 0x14 (1 arg);
this: random 0x200 bytes, vtable slot 4 (0 args), byte [+0xd0] zero in 1/4, count [+0xcc] 0..4 or 0x32 (a quarter: the list-full call; stores at +4+4*0x32 stay inside the 0x200 block); a: random 0x50 bytes with the flag dword [a+0x3c] containing 0x20200000 bits in a third; 0x4d96d0 and 0x4dc630 hooked (thiscall, 1 and 2 args)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, sysobj


def _g48fed0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4d96d0, 1, this=True)
    hook_rec(c, 0x4dc630, 2, this=True)
    al = ((r.getrandbits(24) << 8) | r.choice([1, 2, 0x80])) if r.random() < 1 / 3 else (r.getrandbits(24) << 8)
    so = sysobj(c, table_slots={0x178: pystub(c, 0, this=True, ret=al), 0x50: pystub(c, 1, this=True, ret=r.getrandbits(32))}, table_size=0x6000)
    tab = e.r32(so + 0x9b)
    X = 0 if r.random() < 0.25 else obj(c, 0x20, {0x14: pystub(c, 1, this=True)}, nslots=8)
    e.wbytes(tab + 0x5d35, X.to_bytes(4, 'little'))
    me = obj(c, 0x200, {4: pystub(c, 0, this=True)}, nslots=2)
    e.wbytes(me + 0xd0, bytes([0 if r.random() < 0.25 else r.randint(1, 255)]))
    e.w32(me + 0xcc, 0x32 if r.random() < 0.25 else r.randint(0, 4))
    a = rnd(c, 0x50)
    fl = r.getrandbits(32) & ~0x20200000
    if r.random() < 1 / 3:
        fl |= r.choice([0x20000000, 0x200000, 0x20200000])
    e.w32(a + 0x3c, fl)
    return [me, a]


S(0x48fed0, 'GUESS register object in bounded list or hand to shared owner', 'thiscall', None, ret=None, gen=_g48fed0, note='batch35132')
