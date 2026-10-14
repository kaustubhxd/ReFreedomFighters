"""specs_s35164.py - 0x4d2e50 (thiscall(a, p) ret 8, ret='eax'). this: object with slot 0xb0 (2 args recorded; returns a record r, null in 1/5). r: 0x40 random bytes with [+4] -> type block whose dword +0x10 has bit 0 set in half, size [+8] in 0..4, offset [+0] in 0..8. 0x634d22 hooked (cdecl memcpy, 3 args; the stack
destination is marked; side effect writes a random dword, zero in 1/3, into it). Logger at 0x700390 with slot 0x24 (3 args, ECX = the vtable, caller-popped). p: byte, random (zero in 1/3)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g4d2e50(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def fill(em, k):
        v = 0 if r.random() < 1 / 3 else r.getrandbits(32)
        em.wbytes(em.arg32(0), v.to_bytes(4, 'little'))
    hook_rec(c, 0x634d22, 3, pop=0, stackmark=(0,), side=fill)
    lg = obj(c, 0x20, {0x24: pystub(c, 3, this=True, pop=0)}, nslots=0x20)
    e.w32(0x700390, lg)
    tb = rnd(c, 0x20)
    e.w32(tb + 0x10, (r.getrandbits(32) | 1) if r.random() < 0.5 else (r.getrandbits(32) & ~1))
    rec = 0 if r.random() < 0.2 else rnd(c, 0x40)
    if rec:
        e.w32(rec + 4, tb)
        e.w32(rec + 8, r.randint(0, 4))
        e.w32(rec, r.randint(0, 8))
    me = obj(c, 0x20, {0xb0: pystub(c, 2, this=True, ret=rec)}, nslots=0x30)
    p = rnd(c, 4)
    e.w8(p, 0 if r.random() < 1 / 3 else r.randint(1, 255))
    return [me, r.getrandbits(32), p]


S(0x4d2e50, 'GUESS read stored value by id into byte flag with logging', 'thiscall', None, ret='eax', gen=_g4d2e50, note='batch35164')
