"""specs_s35053.py - 0x4af6d0 (thiscall, no args, ret='eax'). Byte +0x55 zero in 1/3; ids [+0x48], [+0x58] (zero in 1/4); word [+0x5c]; engine table slot 0x58 (1 arg recorded) returns objects (with slot 0x128, 3 args,
writing the out dword (zero in 1/3)) or random values or zero by call index; table slot 0x138 returns an object with slot 0x88 (2 args, writes a random dword through the out pointer)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, sysobj


def _g4af6d0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = rnd(c, 0x70)
    e.wbytes(me + 0x55, bytes([0 if r.random() < 1 / 3 else r.choice([1, 2, 0x80])]))
    if r.random() < 1 / 4:
        e.w32(me + 0x58, 0)

    def w128(em, k):
        em.w32(em.arg32(1), 0 if r.random() < 1 / 3 else r.getrandbits(32) | 1)
    o = obj(c, 0x10, {0x128: pystub(c, 3, nullflag=(1,), this=True, side=w128)}, nslots=0x4c)
    q = obj(c, 0x10, {0x88: pystub(c, 2, nullflag=(1,), this=True, side=lambda em, k: em.w32(em.arg32(1), r.getrandbits(32)))}, nslots=0x24)
    seq = [r.choice([o, o, 0, obj(c, 0x10, {0x128: pystub(c, 3, nullflag=(1,), this=True, side=w128)}, nslots=0x4c)]) for _ in range(4)]
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: seq[min(k, 3)]), 0x138: pystub(c, 0, this=True, ret=q)}, table_size=0x140)
    return [me]


S(0x4af6d0, 'GUESS resolve object by id or name', 'thiscall', None, ret='eax', gen=_g4af6d0, note='batch35053')
