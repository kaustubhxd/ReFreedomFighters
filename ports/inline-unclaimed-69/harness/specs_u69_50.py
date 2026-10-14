"""specs_u69_50.py - area 69, group 50 (slice 8): 0x4cda40, an interval-list removal, no callees.
The list P has room for 16 entries; N is 0..8. Half the runs place x inside an interval, and some runs use x+len = the interval's end
or x = the interval's start, so the boundary branches are reached."""
from pilot import S
from ckit import rnd


def _gen(c):
    e = c.emu
    r = c.rng
    o = rnd(c, 0x10)
    P = rnd(c, 8 * 16)
    e.w32(o + 4, P)
    n = r.randrange(0, 9)
    e.w32(o + 8, n)
    ents = []
    base = r.randrange(0, 0x1000)
    for i in range(n):
        start = base + r.randrange(0, 0x100)
        ln = r.randrange(1, 0x80)
        ents.append((start, ln))
        base = start + ln + r.randrange(1, 0x40)
        e.w32(P + 8 * i, start & 0xffffffff)
        e.w32(P + 8 * i + 4, ln)
    if n and r.random() < 0.7:
        start, ln = r.choice(ents)
        mode = r.random()
        if mode < 0.3:
            x = start                                  # x == start
        elif mode < 0.6:
            x = start + r.randrange(0, ln)             # inside
        else:
            x = start + r.randrange(0, ln)
        end = start + ln
        if r.random() < 0.3:
            length = end - x                           # x + len == end
        else:
            length = r.randrange(0, 2 * ln + 2)
    else:
        x = r.getrandbits(16)
        length = r.randrange(0, 0x40)
    if length == 0 and r.random() < 0.5:
        length = 1
    return [o, x & 0xffffffff, length & 0xffffffff]


S(0x4cda40, 'removeRange4cda40 (thiscall, two args, ret 8, returns bool)', 'thiscall', None, ret='al', gen=_gen,
  note='u69 group 50; no callees')
