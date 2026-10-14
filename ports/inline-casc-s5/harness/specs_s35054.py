"""specs_s35054.py - 0x4a30c0 (thiscall(id, unused) ret 8, ret='eax'). Word at +0x4d (unaligned) equals the low word of id in 3/5 of the cases (upper bits random); [this+0x44] = object with [+8] and slot 0x80
(2 args: fills the 0x24-byte and 12-byte locals with call-independent random bytes); 0x4db3b0 hooked (thiscall, returns a heap object), 0x43ec00 hooked (thiscall, six args; both buffers compared by content;
result random); byte +0x4f zero in half; vtable slot 0x64 (1 arg)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g4a30c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s = rnd(c, 0x20)
    hook_rec(c, 0x4db3b0, 0, this=True, ret=s)
    hook_rec(c, 0x43ec00, 6, this=True, deref={0: -0x24, 1: -0xc}, ret=r.getrandbits(32))
    d34 = bytes(r.getrandbits(8) for _ in range(0x24))
    d10 = bytes(r.getrandbits(8) for _ in range(0xc))

    def fill(em, k):
        em.wbytes(em.arg32(0), d34)
        em.wbytes(em.arg32(1), d10)
    o = obj(c, 0x20, {0x80: pystub(c, 2, nullflag=(0, 1), this=True, side=fill)}, nslots=0x22)
    e.w32(o + 8, rnd(c, 0x10))
    me = obj(c, 0x80, {0x64: pystub(c, 1, this=True)}, nslots=0x1a)
    e.w32(me + 0x44, o)
    w = r.getrandbits(16)
    e.wbytes(me + 0x4d, w.to_bytes(2, 'little'))
    idv = (w if r.random() < 0.6 else (w ^ r.randint(1, 0xffff))) | (r.getrandbits(16) << 16 if r.random() < 0.5 else 0)
    return [me, idv, r.getrandbits(32)]


S(0x4a30c0, 'GUESS react to matching message id', 'thiscall', None, ret='eax', gen=_g4a30c0, note='batch35054')
