"""specs_s67548.py - cascade s6 batch 67548 (0x4c2280, thiscall(stream) ret 4, returns al=1). The stream object's slots 0x44 / 0x48 / 0x50 / 0x68 (1 arg) are recorders of the destination
addresses that also write a deterministic value through them (sized per slot: 2 / 4 / 4 / 1 bytes), so the original's field stores are visible."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g4c2280(c):
    clear_hooks(c)
    r = c.rng
    vals = [r.getrandbits(32) for _ in range(32)]

    def mk(n):
        def side(em, k):
            em.wbytes(em.arg32(0), (vals[k % 32] & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))
        return pystub(c, 1, this=True, side=side)
    st = obj(c, 0x80, {0x44: mk(2), 0x48: mk(4), 0x50: mk(4), 0x68: mk(1)})
    t = rnd(c, 0x90)
    return [t, st]


S(0x4c2280, 'GUESS load_fields_b', 'thiscall', None, ret='al', gen=_g4c2280, note='batch67548')
