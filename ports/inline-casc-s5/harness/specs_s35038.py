"""specs_s35038.py - 0x49c420 (stdcall(node, unused) ret 8). Chain of 0..3 nodes of 4 dwords (next at +0xc); the three tagged dwords are random, zero-pointer values (0..7) in a quarter of the cases;
engine table slot 0x54 (1 arg recorded) returns a different random value per call."""
from pilot import S
from recruits_util import rnd, clear_hooks, pystub, sysobj


def _g49c420(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    vals = [r.getrandbits(32) for _ in range(12)]
    sysobj(c, table_slots={0x54: pystub(c, 1, this=True, ret=lambda em, k: vals[k % 12])})
    nxt = 0
    for _ in range(r.choice([0, 1, 2, 3])):
        nd = rnd(c, 0x10)
        for k in range(3):
            if r.random() < 0.25:
                e.w32(nd + 4 * k, r.randint(0, 7))
        e.w32(nd + 12, nxt)
        nxt = nd
    return [nxt, r.getrandbits(32)]


S(0x49c420, 'GUESS relocate tagged handles in chain', 'stdcall', None, ret=None, gen=_g49c420, note='batch35038')
