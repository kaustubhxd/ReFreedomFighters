"""specs_s67540.py - cascade s6 batch 67540 (0x5c8fc0, thiscall(stream) ret 4, returns al=1). The stream object's slots 0x40 / 0x50 (1 arg) record the destination and write a deterministic dword
into it (so the local the original reads back is defined; the stack destination is stack-marked); the object table slot 0x58 maps that value."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, pystub


def _g5c8fc0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    vals = [r.getrandbits(32) for _ in range(32)]

    def mk():
        def side(em, k):
            em.wbytes(em.arg32(0), vals[k % 32].to_bytes(4, 'little'))
        return pystub(c, 1, this=True, stackmark=(0,), side=side)
    st = obj(c, 0x20, {0x40: mk(), 0x50: mk()})
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: r.getrandbits(32))})
    t = rnd(c, 0xa0)
    return [t, st]


S(0x5c8fc0, 'GUESS load_fields', 'thiscall', None, ret='al', gen=_g5c8fc0, note='batch67540')
