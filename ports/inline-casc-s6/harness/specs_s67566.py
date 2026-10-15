"""specs_s67566.py - cascade s6 batch 67566 (0x4f12e0, thiscall(name) ret 4, returns al). this[0x97] holds the current name (or 0), this[0x9b] a cached block (or 0); the name argument is null / empty /
equal to the current one / different (short ASCII strings sharing prefixes). sys slots 0xf8 (alloc, returns a spec buffer, requested size logged) / 0xfc (free) and this slots 0x278 (result with garbage
high bits) / 0x230 are stubs."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g4f12e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    bufs = [rnd(c, 0x40) for _ in range(2)]
    sysobj(c, slots={0xf8: pystub(c, 1, this=True, ret=lambda em, k: bufs[min(k, 1)]),
                     0xfc: pystub(c, 1, this=True)})
    alpha = b'abAB'

    def mkstr(b):
        a = e.alloc(len(b) + 2, 1)
        e.wbytes(a, b + b'\0\0')
        return a
    base = bytes(r.choice(alpha) for _ in range(r.choice([0, 1, 2, 3, 5])))
    cur = mkstr(base) if r.random() < 0.7 else 0
    pick = r.random()
    if pick < 0.15:
        name = 0
    elif pick < 0.3:
        name = mkstr(b'')
    elif pick < 0.55:
        name = mkstr(base)
    elif pick < 0.75:
        name = mkstr(base + bytes([r.choice(alpha)]))
    elif pick < 0.85 and base:
        name = mkstr(base[:-1])
    else:
        name = mkstr(bytes(r.choice(alpha) for _ in range(r.choice([1, 2, 3, 4]))))
    t = obj(c, 0xb0, {0x278: pystub(c, 0, this=True, ret=lambda em, k: r.getrandbits(32)),
                      0x230: pystub(c, 0, this=True)})
    _w(c, t + 0x97, cur)
    _w(c, t + 0x9b, r.choice([0, rnd(c, 8)]))
    return [t, name]


S(0x4f12e0, 'GUESS set_name', 'thiscall', None, ret='al', gen=_g4f12e0, note='batch67566')
