"""specs_s35057.py - 0x4931d0 (thiscall, no args). Embedded list object at this+0x1c (vtable slots 0x4c, 0x44 (1 arg, flag-recorded out param), 0x64 (hands out 0..3 entry blocks, then 0)); entries of 8 bytes
with byte [4] zero in a third and byte [5] non-zero in a third (other bytes random); the object is random bytes so the reset stores are observable."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g4931d0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    ents = []
    for _ in range(r.choice([0, 1, 2, 3])):
        p = rnd(c, 8)
        e.wbytes(p + 4, bytes([0 if r.random() < 1 / 3 else r.getrandbits(8) | 1]))
        e.wbytes(p + 5, bytes([r.getrandbits(8) | 1 if r.random() < 1 / 3 else 0]))
        ents.append(p)
    vo = obj(c, 4, {0x4c: pystub(c, 1, nullflag=(0,), this=True), 0x44: pystub(c, 1, nullflag=(0,), this=True),
                    0x64: pystub(c, 1, nullflag=(0,), this=True, ret=lambda em, k: ents[k] if k < len(ents) else 0)}, nslots=0x1a)
    me = rnd(c, 0xc00)
    e.w32(me + 0x1c, e.r32(vo))
    return [me]


S(0x4931d0, 'GUESS scan list, reset or consume ready entry', 'thiscall', None, ret=None, gen=_g4931d0, note='batch35057')
