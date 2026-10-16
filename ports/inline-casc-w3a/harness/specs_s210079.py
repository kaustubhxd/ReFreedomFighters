"""specs_s210079.py - Sonnet-w3a: 0x6057d0. Shared entry from 0x605400 (hooked) with a 16-bit capacity and buffer; name string at this+0xc with this+0x10 capacity; the lowercasing import at IAT 0x67641c is a stub that really lowercases; cell from 0x5003d0 with state byte 0 / 4 / other."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def g6057d0(c):
    clear_hooks(c)
    e = c.emu
    letters = b'abcXYZ_-1 \x80\xe9\xff'
    name = bytes(c.rng.choice(letters) for _ in range(c.rng.choice([0, 1, 3, 6]))) + b'\0'
    nm = rnd(c, 0x40); e.wbytes(nm, name)
    cap = c.rng.choice([0, 1, 2, len(name) - 1, len(name), len(name) + 1, 0x10, 0xffff, 0x10001 & 0xffff])
    obuf = rnd(c, 0x40)
    old = bytes(c.rng.choice(letters) for _ in range(c.rng.choice([0, 2, 5]))) + b'\0'
    e.wbytes(obuf, old)
    newb = rnd(c, 0x40)
    hook_rec(c, 0x634273, 2, ret=_r(c), pop=0)
    hook_rec(c, 0x41e290, 1, ret=newb, pop=0)
    edi = obj(c, 0x40, {0x24: pystub(c, 0, ret=_r(c), this=True), 0x28: pystub(c, 0, ret=_r(c), this=True)}, nslots=0x20)
    e.w32(edi + 0xc, obuf)
    e.wbytes(edi + 0x10, c.rng.choice([0, 1, 4, 7, 0x10, 0xffff]).to_bytes(2, 'little'))
    hook_rec(c, 0x605400, 0, ret=edi, this=True)

    def tl(emu, k):
        ch = emu.arg32(0) & 0xff
        return ch + 0x20 if 65 <= ch <= 90 else ch
    e.w32(0x67641c, pystub(c, 1, ret=tl, pop=0))
    oldobj = obj(c, 0x40, {0x28: pystub(c, 0, ret=_r(c), this=True)}, nslots=0x20)
    cell = rnd(c, 0x10)
    e.w32(cell, oldobj)
    e.wbytes(cell + 4, bytes([c.rng.choice([0, 4, 4, 1, 3])]))
    hook_rec(c, 0x5003d0, 1, ret=cell, this=True)
    s = rnd(c, 0x20)
    e.w32(s + 0xc, nm)
    e.wbytes(s + 0x10, (cap & 0xffff).to_bytes(2, 'little'))
    a = rnd(c, 0x20); e.w32(a + 8, rnd(c, 0x10))
    return [s, a]


S(0x6057d0, 'intern_lowercase_name', 'thiscall', None, ret=None, gen=g6057d0, note='batch210079')
