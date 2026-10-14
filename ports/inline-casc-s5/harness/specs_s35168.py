"""specs_s35168.py - 0x46b9d0 (thiscall(a, b) ret 8, ret='eax'). this: 0x100 random bytes with vtable slots 0x12c (3 args) and 0x2d0 (2 args), [+0x60] zero in 1/5, words +0x7c and +0x92 (the id words; a's low word equals each in a quarter of the cases, the high half random), unaligned dword +0x8e zero in 1/4.
b: object with slot 0x88 (2 args; writes v: 3 in half, else random). 0x41e680 hooked (thiscall, 0 args, returns a random dword); 0x46b800 hooked (thiscall, 2 args)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g46b9d0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x41e680, 0, this=True, ret=r.getrandbits(32))
    hook_rec(c, 0x46b800, 2, this=True)

    def w88(em, k):
        em.w32(em.arg32(1), 3 if r.random() < 0.5 else r.getrandbits(32))
    b = obj(c, 0x20, {0x88: pystub(c, 2, this=True, nullflag=(1,), side=w88)}, nslots=0x30)
    me = obj(c, 0x100, {0x12c: pystub(c, 3, this=True), 0x2d0: pystub(c, 2, this=True)}, nslots=0xb5)
    e.w32(me + 0x60, 0 if r.random() < 0.2 else r.getrandbits(32) | 1)
    w7c, w92 = r.getrandbits(16), r.getrandbits(16)
    e.wbytes(me + 0x7c, w7c.to_bytes(2, 'little'))
    e.wbytes(me + 0x92, w92.to_bytes(2, 'little'))
    e.wbytes(me + 0x8e, (0 if r.random() < 0.25 else r.getrandbits(32) | 1).to_bytes(4, 'little'))
    t = r.random()
    lo = w7c if t < 0.3 else (w92 if t < 0.55 else r.getrandbits(16))
    if r.random() < 0.1:
        e.wbytes(me + 0x92, w7c.to_bytes(2, 'little'))   # both ids equal: the first test wins
    a = (r.getrandbits(16) << 16) | lo
    return [me, a, b]


S(0x46b9d0, 'GUESS dispatch event id: act on two registered ids else forward', 'thiscall', None, ret='eax', gen=_g46b9d0, note='batch35168')
