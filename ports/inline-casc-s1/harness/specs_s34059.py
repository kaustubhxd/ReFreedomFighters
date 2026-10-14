"""specs_s34059.py - cascade tier E, batch 34059.
0x4cec60: this is null in a seventh, else an iterator object (slots 0x4c, 0x5c with a stack iterator, 0..3 ids); the logger object at 0x700390 has slot 0x20 (returns an object whose slot 0x2c is a caller-popped recorder).
0x4f2750: this slot 0x2e4 (stack pointer to a 16-byte block; writes its first dword; returns a random EAX with the low byte 0 in half the cases) and 0x2e0 (two args, returns 0/1) record the block's four dwords; a covers
-1, 0, 0xffff, 0x10000 and others; d is zero in a quarter.
0x4fbab0: [this+0x44]+0x18 is an object with slot 4 (1 arg); hooked 0x41e290 (cdecl) returns a fresh block or 0 (a fifth); [this+0x4c] (the tail) is null in a third, else a node block."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _g4cec60(c):
    clear_hooks(c)
    r = c.rng
    n = r.choice([0, 1, 2, 3])

    def begin(em, k):
        for i in range(3):
            em.w32(em.arg32(0) + 4 * i, r.getrandbits(32))

    def nxt(em, k):
        em.w32(em.arg32(0), 1 if k < n else 0)
    lg2 = obj(c, 0x20, {0x2c: pystub(c, 3, this=True, pop=0)}, nslots=0x30 // 4)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=lg2, this=True)}, nslots=0x24 // 4)
    c.emu.w32(0x700390, lg)
    me = 0 if r.random() < 1 / 7 else obj(c, 0x20, {0x4c: pystub(c, 1, this=True, side=begin, stackmark=(0,)),
                                                    0x5c: pystub(c, 1, this=True, side=nxt, stackmark=(0,), ret=lambda em, k: r.getrandbits(32))},
                                          nslots=0x60 // 4)
    return [me]


def _g4f2750(c):
    clear_hooks(c)
    r = c.rng

    def w0(em, k):
        em.w32(em.arg32(0), r.getrandbits(32))
    r1 = r.getrandbits(32)
    if r.random() < 0.5:
        r1 &= ~0xff
    me = obj(c, 0x20, {0x2e4: pystub(c, 1, this=True, ret=r1, side=w0, stackmark=(0,)),
                       0x2e0: pystub(c, 2, this=True, ret=r.choice([0, 1]) | (r.getrandbits(24) << 8), deref={0: 4})}, nslots=0x2e8 // 4)
    a = r.choice([-1, 0, 0xffff, 0x10000, 0x10001, 5, r.getrandbits(32), r.getrandbits(16)]) & 0xffffffff
    d = 0 if r.random() < 0.25 else r.getrandbits(32) | 1
    return [me, a, r.getrandbits(32), r.getrandbits(32), d]


def _g4fbab0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x41e290, 1, ret=(0 if r.random() < 0.2 else rnd(c, 0x20)), pop=0)
    m = obj(c, 0x20, {4: pystub(c, 1, this=True)}, nslots=8 // 4)
    owner = rnd(c, 0x20)
    c.emu.w32(owner + 0x18, m)
    me = rnd(c, 0x60)
    c.emu.w32(me + 0x44, owner)
    c.emu.w32(me + 0x4c, 0 if r.random() < 1 / 3 else rnd(c, 0x20))
    return [me, r.getrandbits(32)]


S(0x4cec60, 'GUESS log every id of an iterator', 'thiscall', None, ret=None, gen=_g4cec60, note='batch34059')
S(0x4f2750, 'GUESS two-step query with a packed argument block', 'thiscall', None, ret='eax', gen=_g4f2750, note='batch34059')
S(0x4fbab0, 'GUESS notify an owner and append a list node', 'thiscall', None, ret='eax', gen=_g4fbab0, note='batch34059')
