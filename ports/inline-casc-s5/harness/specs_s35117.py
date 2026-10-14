"""specs_s35117.py - 0x4f5c90 (thiscall(a, b, c, d) ret 0x10, ret='eax'). this: random 0x80 bytes; d zero in half; engine table slot 0x58 (1 arg recorded) returns o (null in 1/4) with slot 0x1bc (seven args: the 0x24-byte and 12-byte locals compared by content) returning r (an object with slot 0x278, 2 args);
0x4de7a0 hooked (fills its 0x24-byte local with fixed random bytes)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, sysobj


def _g4f5c90(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    data = bytes(r.getrandbits(8) for _ in range(0x24))

    def h(em, rr):
        em.calllog.append(('4de7a0',))
        em.wbytes(em.reg('ecx'), data)
        em.ret(eax=0)
    e.hook(0x4de7a0, h)
    child = obj(c, 0x20, {0x278: pystub(c, 2, this=True)}, nslots=0x9f)
    o = 0 if r.random() < 1 / 4 else obj(c, 0x20, {0x1bc: pystub(c, 7, deref={1: -0x24, 2: 3}, this=True, ret=child)}, nslots=0x70)
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=o)})
    return [rnd(c, 0x80), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), 0 if r.random() < 0.5 else r.getrandbits(32) | 1]


S(0x4f5c90, 'GUESS create child through table object and configure', 'thiscall', None, ret='eax', gen=_g4f5c90, note='batch35117')
