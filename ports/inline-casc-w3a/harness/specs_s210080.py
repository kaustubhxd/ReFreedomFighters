"""specs_s210080.py - Sonnet-w3a: 0x4387a0. Container at this+0x1338 (slots 0x4c / 0x64); element name from the hooked 0x4cc1d0 (looked up by ECX); the string-compare import at IAT 0x676414 is a stub with the real strcmp result."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def _ub(c, a, v): c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def _s(c, e):
    p = rnd(c, 0x10)
    e.wbytes(p, bytes(c.rng.choice(b'ab') for _ in range(c.rng.choice([0, 1, 2]))) + b'\0')
    return p


def g4387a0(c):
    clear_hooks(c)
    e = c.emu
    a, b = _s(c, e), _s(c, e)
    n = c.rng.choice([0, 1, 2, 3, 4])
    names = {}
    elems = []
    for _ in range(n):
        el = rnd(c, 0x100)
        names[el] = _s(c, e)
        _ub(c, el + 0xaf, 0 if c.rng.random() < 0.3 else _s(c, e))
        elems.append(el)
    seq = elems + [0]

    def sc(emu, k):
        x = emu.rbytes(emu.arg32(0), 4).split(b'\0')[0]
        y = emu.rbytes(emu.arg32(1), 4).split(b'\0')[0]
        return (x > y) - (x < y) & 0xffffffff
    e.w32(0x676414, pystub(c, 2, ret=sc, pop=0))
    hook_rec(c, 0x4cc1d0, 0, ret=lambda emu, k: names[emu.reg('ecx')], this=True)
    cont = obj(c, 0x40, {0x4c: pystub(c, 1, ret=_r(c), this=True, stackmark=(0,)),
                         0x64: pystub(c, 1, ret=lambda emu, k: seq[min(k, len(seq) - 1)], this=True, stackmark=(0,))}, nslots=0x30)
    s = rnd(c, 0x1400)
    e.w32(s + 0x1338, 0 if c.rng.random() < 0.1 else cont)
    return [s, a, b]


S(0x4387a0, 'find_by_name_or_alias', 'thiscall', None, ret='eax', gen=g4387a0, note='batch210080')
