"""specs_s210071.py - Sonnet-w3a: 0x591b20. Flag word at this+0x417 (unaligned) with bit 0x2000000 set or not; slot 0x504 returns a value equal to the cached this[0x658] about half of the time; previous byte this[0x65c] random; slot 0x438 returns al with garbage high bytes; 0x5aeff0 hooked."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def _ub(c, a, v): c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def g591b20(c):
    clear_hooks(c)
    e = c.emu
    hook_rec(c, 0x5aeff0, 1, ret=_r(c), this=True)
    cache = c.rng.choice([0, 7, _r(c)])
    v = cache if c.rng.random() < 0.5 else c.rng.choice([0, 7, _r(c)])
    s = obj(c, 0x680, {0x504: pystub(c, 0, ret=v, this=True), 0x438: pystub(c, 0, ret=c.rng.choice([0, 1, 0x100, 0x101]), this=True)}, nslots=0x180)
    flags = _r(c) & ~0x2000000
    if c.rng.random() < 0.3: flags |= 0x2000000
    _ub(c, s + 0x417, flags)
    e.w32(s + 0x658, cache)
    e.w32(s + 0x654, _r(c))
    e.wbytes(s + 0x65c, bytes([c.rng.choice([0, 0, 1, 0x80])]))
    return [s]


S(0x591b20, 'refresh_cached_lookup', 'thiscall', None, ret='eax', gen=g591b20, note='batch210071')
