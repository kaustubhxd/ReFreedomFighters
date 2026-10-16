"""specs_s210065.py - Sonnet-w3a: 0x5c56f0. Reader hooks: 0x4e5ea0 returns two NUL-terminated strings (lengths around the 0x80 limit), 0x4e5e40 / 0x4e5e60 return distinct tagged values in call order; errors go through the [0x700390] handler object (slot 0x2c is cdecl with 3 args)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def g5c56f0(c):
    clear_hooks(c)
    e = c.emu
    strs = []
    for _ in range(2):
        n = c.rng.choice([0, 1, 5, 0x7e, 0x7f, 0x80, 0x81, 0xa0])
        p = rnd(c, 0x100)
        e.wbytes(p, bytes(c.rng.randrange(1, 256) for _ in range(n)) + b'\0')
        strs.append(p)
    v16 = [_r(c) for _ in range(3)]
    v32 = [c.rng.choice([0, _r(c), 0x100, 0x80000000]), c.rng.choice([0, 1, _r(c), 0x100])]
    hook_rec(c, 0x4e5ea0, 0, ret=lambda emu, k: strs[min(k, 1)], this=True)
    hook_rec(c, 0x4e5e40, 0, ret=lambda emu, k: v16[min(k, 2)], this=True)
    hook_rec(c, 0x4e5e60, 0, ret=lambda emu, k: v32[min(k, 1)], this=True)
    rep = obj(c, 0x40, {0x2c: pystub(c, 3, ret=_r(c), pop=0, stackmark=())}, nslots=0x20)
    g = obj(c, 0x40, {0x20: pystub(c, 2, ret=rep, this=True)}, nslots=0x20)
    e.w32(0x700390, g)
    return [rnd(c, 0x170), rnd(c, 0x20)]


S(0x5c56f0, 'read_two_strings_and_fields', 'thiscall', None, ret=None, gen=g5c56f0, note='batch210065')
