"""specs_s15.py - inline session batch 15 (Haiku, overnight): 0x615500, 0x5eeb40, 0x600ba0."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _adv(c):
    o = _rnd(c, 0x400)
    c.emu.w16(o + 2, 0xffff if c.rng.random() < 0.2 else c.rng.randint(0, 2))
    return [o]


S(0x615500, 'advanceSlot312 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_adv,
  note='batch15; 312-byte nodes, marker 0xffff1201, vtable 0x6bdabc')


# 0x5eeb40 thiscall: (this, a, b, c, d). The stored values equal the arguments about a quarter of the time.
def _cache(c):
    r = c.rng
    o = _rnd(c, 0x100)
    vals = [r.choice([0, 1, 2, 0x10, r.getrandbits(32)]) for _ in range(4)]
    for i, v in enumerate(vals):
        c.emu.w32(o + 0x5a + 4 * i, v)
    args = [v if r.random() < 0.25 else r.choice([0, 1, 2, 0x10, r.getrandbits(32)]) for v in vals]
    return [o] + args


S(0x5eeb40, 'cacheFour (unknown) thiscall', 'thiscall', None, ret=None, gen=_cache,
  note='batch15; flag byte at +0x77 set only when a value changes')


# 0x600ba0 thiscall: (this, x). A list of 0..4 nodes (0xa0 bytes each) linked at +0x9c, head is this.
def _span(c):
    r = c.rng
    n = r.randint(0, 4)
    objs = [c.emu.alloc(0xa0, 4) for _ in range(n + 1)]
    for o in objs:
        c.emu.wbytes(o, bytes(r.getrandbits(8) for _ in range(0xa0)))
        c.emu.w32(o + 0x4c, r.randint(0, 40))
        c.emu.w32(o + 0x60, r.randint(0, 20))
        c.emu.w32(o + 0x64, r.randint(0, 60))
    for i, o in enumerate(objs):
        c.emu.w32(o + 0x9c, objs[i + 1] if i + 1 < len(objs) else 0)
    return [objs[0], r.randint(0, 45)]


S(0x600ba0, 'inSpan (unknown) thiscall', 'thiscall', None, ret='al', gen=_span,
  note='batch15; returns AL; the list is null-terminated')
