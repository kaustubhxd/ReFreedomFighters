"""specs_s306.py - gap band 0x601000-0x621000 (docs/20-unclaimed-76.md), batch 306: six cdecl (plain ret) accessors and
forwarders. The forwards call the first argument's vtable slots with the rest (logged, the callee pops its arguments)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _obj(c, slots, nargs):
    e = c.emu
    vt = e.logging_vtable('o306', max(slots) // 4 + 1, impl={}, argwords=dict((k, nargs) for k in slots))
    o = _rnd(c, 0x200)
    e.w32(o, vt)
    return o


def _pair(c):
    a = _rnd(c, 0x200)
    return [a, c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _two(c):
    a = _rnd(c, 0x200)
    if c.rng.random() < 0.5:
        e = c.emu
        e.w32(a + 4, e.r32(a))              # make the 'same' branch likely
    return [a, c.rng.getrandbits(32)]


def _fwd2(slot):
    def gen(c):
        o = _obj(c, [slot], 2)
        return [o, c.rng.getrandbits(32), c.rng.getrandbits(32)]
    return gen


def _fwd4(c):
    o = _obj(c, [0x20], 4)
    return [o, c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x61c5e0, 'setPair (GUESS)', 'cdecl', None, ret=None, gen=_pair, note='batch306; plain ret')
S(0x61c640, 'setIfSame (GUESS)', 'cdecl', None, ret=None, gen=_two, note='batch306; plain ret')
S(0x61bc10, 'fwd2slot0c (GUESS)', 'cdecl', None, ret='eax', gen=_fwd2(0xc), note='batch306; plain ret')
S(0x61bca0, 'fwd2slot10 (GUESS)', 'cdecl', None, ret='eax', gen=_fwd2(0x10), note='batch306; plain ret')
S(0x61bcc0, 'fwd2slot4 (GUESS)', 'cdecl', None, ret='eax', gen=_fwd2(4), note='batch306; plain ret')
S(0x61bc80, 'fwd4slot20 (GUESS)', 'cdecl', None, ret='eax', gen=_fwd4, note='batch306; plain ret')
