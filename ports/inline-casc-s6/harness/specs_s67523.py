"""specs_s67523.py - cascade s6 batch 67523 (0x4acc20, thiscall(stream) ret 4, returns 1). The stream's slots 0x44 / 0x40 / 0x70 log every call (destination offsets, via calllog because the
0x44 slot is called 16 times) and write distinct values (2 bytes for 0x44, 4 bytes otherwise); the embedded object at +0x1c6 has slot 0xc."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g4acc20(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    base = {}

    def mk(tag, size):
        def f(em, k):
            d = em.arg32(0)
            em.calllog.append((tag, d - base['t'], k))
            em.wbytes(d, ((0x1111 * (k + 1) + (0x10000 if size == 4 else 0) * (k + 3)) & ((1 << (8 * size)) - 1)).to_bytes(size, 'little'))
        return f
    stream = obj(c, 0x20, {0x44: pystub(c, 1, this=True, side=mk('s44', 2)), 0x40: pystub(c, 1, this=True, side=mk('s40', 4)), 0x70: pystub(c, 1, this=True, side=mk('s70', 4))})
    t = rnd(c, 0x1d0)
    base['t'] = t
    vt = e.alloc(0x20, 4)
    e.w32(vt + 0xc, pystub(c, 0, this=True))
    e.wbytes(t + 0x1c6, vt.to_bytes(4, 'little'))
    return [t, stream]


S(0x4acc20, 'GUESS load_fields', 'thiscall', None, ret='al', gen=_g4acc20, note='batch67523')
