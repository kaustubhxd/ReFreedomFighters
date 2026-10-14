"""specs_s35097.py - 0x4a03b0 (thiscall(name, on) ret 8). this: random 0x120 bytes; the unaligned slot at +0x102 holds an array {count 0..3, child pointers} in 2/3 of the cases, otherwise zero (the creator slot 0x128 of [this+0x44] (3 args) then
writes the array into the slot in half the cases; when it does not, the default array at this+0x7e is used with a zero count); children: 0x90 random bytes with an unaligned string pointer at +0x76 and flags at +0x5a; name null, empty, or one of a few
strings; `on` includes values whose low byte is 0; _stricmp stubbed in Python (logs both strings, case-insensitive)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g4a03b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    words = [b'btn', b'BTN', b'menu', b'x', b'Menu']

    def mkstr():
        p = rnd(c, 0x10)
        e.wbytes(p, r.choice(words) + b'\0')
        return p
    kids = []
    for _ in range(r.choice([0, 1, 2, 3])):
        k = rnd(c, 0x90)
        e.wbytes(k + 0x76, mkstr().to_bytes(4, 'little'))
        kids.append(k)
    arr = rnd(c, 0x20)
    e.w32(arr, len(kids))
    for i, k in enumerate(kids):
        e.w32(arr + 4 + 4 * i, k)
    me = rnd(c, 0x120)
    e.wbytes(me + 0x7e, bytes(4))
    if r.random() < 2 / 3:
        e.wbytes(me + 0x102, arr.to_bytes(4, 'little'))
        wr = False
    else:
        e.wbytes(me + 0x102, bytes(4))
        wr = r.random() < 0.5

    def w128(em, k):
        if wr:
            em.wbytes(em.arg32(1), arr.to_bytes(4, 'little'))
    o = obj(c, 0x20, {0x128: pystub(c, 3, this=True, side=w128)}, nslots=0x4c)
    e.w32(me + 0x44, o)
    e.wbytes(0x7002ac, r.getrandbits(16).to_bytes(2, 'little'))

    def stricmp(em, res_):
        def rd(p):
            d = b''
            while len(d) < 32:
                b = bytes(em.rbytes(p + len(d), 1))
                if b == b'\0':
                    break
                d += b
            return d
        a, b = rd(em.arg32(0)), rd(em.arg32(1))
        em.calllog.append(('_stricmp', a, b))
        x, y = a.lower(), b.lower()
        em.ret(eax=0 if x == y else (1 if x > y else 0xffffffff))
    e.stub_import('_stricmp', stricmp)
    t = r.random()
    name = 0 if t < 0.15 else (mkstr() if t < 0.85 else _empty(c, e))
    return [me, name, r.choice([0, 1, 0x100, 0x101, r.getrandbits(32)])]


def _empty(c, e):
    p = rnd(c, 4)
    e.wbytes(p, b'\0')
    return p


S(0x4a03b0, 'GUESS enable or disable named children', 'thiscall', None, ret=None, gen=_g4a03b0, note='batch35097')
