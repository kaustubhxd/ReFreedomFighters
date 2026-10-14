"""specs_s1518.py - recruits thread batch 1518: CSaveMissions::LevelCompleted (0x5b1000) and
GetSubZoneMissionInfo (0x5b0f20). Plain exe code: LevelCompleted runs as exe code under GetSubZoneMissionInfo.
The save-mission table: entry names are 4+ byte strings in the heap, sometimes sharing a prefix with the query."""
from pilot import S
from recruits_util import rnd
from recruits_util import obj


def _gen(c):
    r = c.rng
    e = c.emu
    t = rnd(c, 0x800)
    n = r.randint(0, 8)
    prefixes = [b'Lev1', b'Lev2', b'Lev3', b'C05A']
    e.w32(t + 0x5b8, n)
    for i in range(n):
        s = r.choice(prefixes) + bytes([0x61 + i]) + b'\0'
        a = c.emu.alloc(len(s) + 4, 4)
        e.wbytes(a, s)
        e.w32(t + 8 + 4 * i, a)
        e.w32(t + 0x5c0 + 4 * i, r.choice([0, 0, 0, 4, 1]))
        e.w32(t + 0x3c8 + 4 * i, r.choice([0, 1, 2]))
        e.w32(t + 0x790 + 4 * i, r.getrandbits(32))
    q = r.choice(prefixes) + b'\0\0\0\0'
    name = c.emu.alloc(len(q) + 4, 4)
    e.wbytes(name, q)
    out = rnd(c, 0x110)
    return [t, out, name]


S(0x5b1000, 'CSaveMissions::LevelCompleted', 'thiscall', ret='al', gen=lambda c: _gen(c)[:1] + [_gen(c)[2]], note='batch1518')
S(0x5b0f20, 'CSaveMissions::GetSubZoneMissionInfo', 'thiscall', gen=_gen, note='batch1518')
