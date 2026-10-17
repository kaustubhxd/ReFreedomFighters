"""specs_s285.py - unclaimed area 74 (docs/20-unclaimed-74.md), slice 13 leaves: 0x4682d0, 0x5eeb90, 0x5af0d0, 0x59db50
(the last calls exe helper 0x59dae0, not claimed here)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _store(c):
    return [_rnd(c, 0x400), c.rng.getrandbits(32)]


def _table(c):
    self_ = _rnd(c, 0x100)
    n = c.rng.randrange(0, 12)
    c.emu.w32(self_, n)
    idx = c.rng.choice([c.rng.randrange(0, 14), c.rng.getrandbits(32)])
    return [self_, idx]


def _gate(c):
    e = c.emu
    self_ = _rnd(c, 0x900)
    cnt = c.rng.choice([0, 1, 2, 3])
    e.w32(self_ + 0x7ce, cnt)
    if cnt:
        base = self_ + 0x7c2 + 16 * cnt
        e.w32(base, c.rng.getrandbits(32))
    a = c.rng.choice([0, 1, c.rng.getrandbits(32)])
    return [self_, a, c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x4682d0, 'setField1d6 (GUESS)', 'thiscall', None, ret=None, gen=_store, note='batch285; ret 4')
S(0x5eeb90, 'setField4e (GUESS)', 'thiscall', None, ret=None, gen=_store, note='batch285; ret 4')
S(0x5af0d0, 'tableAt (GUESS)', 'thiscall', None, ret='eax', gen=_table, note='batch285; ret 4')
S(0x59db50, 'gateCall (GUESS)', 'thiscall', None, ret='eax', gen=_gate, note='batch285; ret 0x10; exe 0x59dae0')
