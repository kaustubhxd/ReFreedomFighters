"""specs_s1200.py - pathfinding batch 1200: small ZPFOctree_packed / ZPathfinder3 / ZActor leaves."""
from pilot import S, u32, const


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _action(c):
    r = c.rng.random()
    if r < 0.5:
        return c.rng.choice([0, 1, 2, 3]) | c.rng.choice([0, 0x4000, 0x8000, 0xc000]) | (c.rng.getrandbits(1) << 12)
    return c.rng.getrandbits(32)


S(0x532730, 'ZPFOctree_packed::isActionAllowed', 'thiscall', [u32(), _action], ret='al')

N = 48


def _coarser(c):
    r = c.rng
    e = c.emu
    obj = _rnd(c, 0x80)
    levels = r.randint(0, 4)
    e.w32(obj + 0x38, levels)
    comp = _rnd(c, N * 0x16 + 8)
    area = _rnd(c, N * 12 + 8)
    for k in range(N):
        e.w16(comp + k * 0x16 + 2, 0xffff if r.random() < 0.4 else r.getrandbits(16))
        e.w16(comp + k * 0x16 + 4, r.randrange(N))
        e.w16(area + k * 12 + 2, 0xffff if r.random() < 0.4 else r.getrandbits(16))
        e.w16(area + k * 12 + 4, r.randrange(N))
    e.w32(obj + 0x54, comp)
    e.w32(obj + 0x5a, area)
    idx = r.randrange(N) | (r.choice([0, 0, 0, 0xabcd0000]))
    level = r.choice([levels, levels - 1, levels - 2, 0, r.getrandbits(32)])
    return [obj, _rnd(c, 8), idx, level]


S(0x532770, 'ZPFOctree_packed::isInCoarserPath', 'thiscall', None, ret='al', gen=_coarser)


def _box(c):
    r = c.rng
    e = c.emu
    box = _rnd(c, 0x20)
    for k in range(1, 7):
        e.w32(box + 4 * k, r.randint(-4, 4) if r.random() < 0.8 else r.getrandbits(32))
    lo = _rnd(c, 12)
    hi = _rnd(c, 12)
    for k in range(3):
        e.w32(lo + 4 * k, r.randint(-4, 4) if r.random() < 0.8 else r.getrandbits(32))
        e.w32(hi + 4 * k, r.randint(-4, 4) if r.random() < 0.8 else r.getrandbits(32))
    return [box, _rnd(c, 16), r.getrandbits(32), lo, hi]


S(0x532800, 'ZPFOctreeNodeCheckBox_packed::isOK', 'thiscall', None, ret='al', gen=_box)
S(0x530fb0, 'ZPFOctree_packed::Init0', 'thiscall', [lambda c: _rnd(c, 16), u32(), u32()])


def _door(c):
    obj = _rnd(c, 0x90)
    c.emu.w32(obj + 0x7d, c.rng.getrandbits(32))
    return [obj, c.rng.choice([0, 1, 2, c.rng.getrandbits(32)])]


S(0x52b370, 'ZPathfinder3::GetDoorBlockerPtr', 'thiscall', None, ret='eax', gen=_door)
S(0x478e90, 'ZActor::GetPathFinder3', 'thiscall', [lambda c: _rnd(c, 0x700)], ret='eax')
S(0x47bfb0, 'ZActor::SetPathFinder3', 'thiscall', [lambda c: _rnd(c, 0x700), u32()])
S(0x478620, 'ZActor::EnablePathFinder', 'thiscall', [lambda c: _rnd(c, 0x700), u32()])
