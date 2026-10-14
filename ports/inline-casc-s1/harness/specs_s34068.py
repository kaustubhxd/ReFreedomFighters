"""specs_s34068.py - cascade tier E, batch 34068.
0x54cdf0: this slot 0x30 recorder; counts at +0x8014 / +0x8018 (0..5, sometimes negative or zero), random ids in the two arrays, an unaligned record cursor into a random-filled buffer; globals 0x713e18/19 random bytes.
0x551950 (stdcall, 3 args): a slot 0x18 returns r (null in a fifth of the cases); r slot 0x4c returns a manager; hooked 0x5003d0 / 0x5002f0 record this and the argument.
0x553fa0 (stdcall, 1 arg): [0x7003b8]+0x2c15 is zero in a quarter of the cases; [a+0xc] slot 0 returns an object e with slots 0x24 / 0x28 / 0x30; hooked 0x5003d0 returns a slot cell whose byte +4 is 0, 4 or other and whose first dword is an object with slot 0x28."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _g54cdf0(c):
    clear_hooks(c)
    r = c.rng
    me = obj(c, 0x8040, {0x30: pystub(c, 0, ret=r.getrandbits(32), this=True)}, nslots=0x34 // 4)
    buf = rnd(c, 0x200)
    cur = buf + r.randrange(0, 0x40)
    c.emu.wbytes(me + 0x8021, cur.to_bytes(4, 'little'))
    n1 = r.choice([0, 1, 2, 3, 5, 0xffffffff])
    n2 = r.choice([0, 1, 2, 3, 5, 0xffffffff])
    c.emu.w32(me + 0x8014, n1)
    c.emu.w32(me + 0x8018, n2)
    c.emu.wbytes(0x713e18, bytes([r.choice([0, 1, 5]), r.choice([0, 0, 1, 7])]))
    return [me]


def _g551950(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5003d0, 1, ret=lambda em, k: r.getrandbits(32), this=True)
    hook_rec(c, 0x5002f0, 1, this=True)
    mgr = rnd(c, 0x20)
    rr = 0 if r.random() < 0.2 else obj(c, 0x20, {0x4c: pystub(c, 0, ret=mgr, this=True)}, nslots=0x50 // 4)
    a = obj(c, 0x20, {0x18: pystub(c, 1, ret=rr, this=True)}, nslots=0x1c // 4)
    return [a, r.getrandbits(32), rnd(c, 0x20)]


def _g553fa0(c):
    clear_hooks(c)
    r = c.rng
    g = rnd(c, 0x2c40)
    c.emu.w32(0x7003b8, g)
    v = 0 if r.random() < 0.25 else r.getrandbits(32)
    c.emu.wbytes(g + 0x2c15, v.to_bytes(4, 'little'))
    e = obj(c, 0x20, {0x24: pystub(c, 0, ret=r.getrandbits(32), this=True), 0x28: pystub(c, 0, ret=r.getrandbits(32), this=True),
                      0x30: pystub(c, 1, this=True)}, nslots=0x34 // 4)
    owner = obj(c, 0x20, {0: pystub(c, 2, ret=e, this=True)}, nslots=1)
    inner = obj(c, 0x20, {0x28: pystub(c, 0, this=True)}, nslots=0x2c // 4)
    cell = rnd(c, 0x10)
    c.emu.w32(cell, inner)
    c.emu.wbytes(cell + 4, bytes([r.choice([0, 4, 4, 1, 9])]))
    hook_rec(c, 0x5003d0, 1, ret=cell, this=True)
    a = rnd(c, 0x20)
    c.emu.w32(a + 8, rnd(c, 0x20))
    c.emu.w32(a + 0xc, owner)
    return [a]


S(0x54cdf0, 'GUESS flush two id lists into a record cursor', 'thiscall', None, ret=None, gen=_g54cdf0, note='batch34068')
S(0x551950, 'GUESS lookup and set four values', 'stdcall', None, ret='eax', gen=_g551950, note='batch34068')
S(0x553fa0, 'GUESS rebind a slot cell to a fresh object', 'stdcall', None, ret='eax', gen=_g553fa0, note='batch34068')
