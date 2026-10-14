"""specs_s35136.py - 0x4444a0 (thiscall, no args). [this+0xa8] = list L (null in 1/6; slots 0x14 (0 args: non-zero for the first 0..3 calls, then 0), 0x4c (1 arg, out pointer flag-recorded), 0x5c (1 arg, flag-recorded out pointer; writes a non-zero first dword in 2/3 of the calls), 0 (delete, 1 arg));
this: random 0xb0 bytes with vtable slot 0x36c (1 arg); 0x4dc1e0 hooked (thiscall, 1 arg)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g4444a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4dc1e0, 1, this=True)
    m = r.choice([0, 1, 2, 3])
    seq = [r.getrandbits(32) for _ in range(6)]
    wr = [r.random() < 2 / 3 for _ in range(6)]
    L = 0 if r.random() < 1 / 6 else obj(c, 0x10, {0x14: pystub(c, 0, this=True, ret=lambda em, k: 1 if k < m else 0),
                                                    0x4c: pystub(c, 1, nullflag=(0,), this=True),
                                                    0x5c: pystub(c, 1, nullflag=(0,), this=True, ret=lambda em, k: seq[min(k, 5)],
                                                                 side=lambda em, k: em.w32(em.arg32(0), 7 if wr[min(k, 5)] else 0)),
                                                    0: pystub(c, 1, this=True)}, nslots=0x20)
    me = obj(c, 0xb0, {0x36c: pystub(c, 1, this=True)}, nslots=0xdc)
    e.w32(me + 0xa8, L)
    return [me]


S(0x4444a0, 'GUESS drain pending list and destroy it', 'thiscall', None, ret=None, gen=_g4444a0, note='batch35136')
