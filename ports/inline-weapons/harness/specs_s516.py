"""specs_s516.py - weapons batch 516: ZWeaponRecycleList and ZFFHERO::RemoveFromWeaponRecycleList."""
from pilot import S
from wkit import rnd, stub, obj, sysobj, fedge


def _list(c, n=None, items=None):
    r = c.rng
    l = rnd(c, 0x460)
    if n is None:
        n = r.randint(0, 6)
    c.emu.w32(l + 0x48, n)
    for i in range(n):
        it = items[i] if items else (0 if r.random() < 0.3 else r.getrandbits(32))
        c.emu.w32(l + 0x4c + 8 * i, it)
        c.emu.wf32(l + 0x50 + 8 * i, r.uniform(0, 1000))
    c.emu.wf32(l + 0x44c, r.choice((30.0, 0.0, 120.5, fedge(c))))
    return l


def _ticks(c):
    so = rnd(c, 0xa0)
    c.emu.w32(so + 0x40, c.rng.randint(0, 1 << 20))
    c.emu.w32(0x70039c, so)


def _add(c):
    _ticks(c)
    l = _list(c, c.rng.randint(0, 20))
    return [l, c.rng.getrandbits(32)]


def _remove(c):
    r = c.rng
    vals = [r.choice((0, 0, 5, 7, r.getrandbits(32))) for _ in range(r.randint(0, 7))]
    l = _list(c, len(vals), vals)
    return [l, r.choice(vals + [5, 0]) if vals else 5, r.choice((0, 1, 0x100))]


def _frame(c):
    r = c.rng
    _ticks(c)
    now = c.emu.r32(c.emu.r32(0x70039c) + 0x40) / 1024.0
    items = [0 if r.random() < 0.2 else obj(c, 0x40, {0x2e8: stub(c, 0), 0x210: stub(c, 1)}) for _ in range(r.randint(0, 5))]
    l = _list(c, len(items), items)
    for i in range(len(items)):
        c.emu.wf32(l + 0x50 + 8 * i, now + r.choice((-1.0, 1.0, 0.0, r.uniform(-50, 50))))
    g = rnd(c, 0x8b8 + 4 * 16)
    m = r.randint(0, 10)
    c.emu.w32(g + 0x8b4, m)
    for i in range(m):
        c.emu.w32(g + 0x8b8 + 4 * i, r.choice(items) if items and r.random() < 0.5 else r.getrandbits(32))
    c.emu.w32(0x7003b8, g)
    return [l]


def _init(c):
    r = c.rng
    x = obj(c, 0x100, {0x88: stub(c, 2, skip=(1,)), 0x5c: stub(c, 3)})
    sysobj(c, {0x138: stub(c, 0, ret=x)})
    return [rnd(c, 0x460)]


def _copy(c):
    return [rnd(c, 0x460), _list(c)]


def _hero(c):
    r = c.rng
    l = _list(c)
    src = c.emu.alloc(4, 4)
    c.emu.w32(src, l)
    x = obj(c, 0x100, {0x88: stub(c, 2, skip=(1,), ofills=((1, 0, src, 1),))})
    sysobj(c, {0x138: stub(c, 0, ret=x)})
    h = rnd(c, 0xa00)
    c.emu.w8(h + 0x9e7, 0 if r.random() < 0.2 else 1)
    n = c.emu.r32(l + 0x48)
    item = c.emu.r32(l + 0x4c + 8 * r.randrange(n)) if n and r.random() < 0.7 else r.getrandbits(32)
    return [h, item]


S(0x5e9300, 'ZWeaponRecycleList::AddWeapon', 'thiscall', None, ret=None, gen=_add)
S(0x5e93f0, 'ZWeaponRecycleList::RemoveWeapon', 'thiscall', None, ret=None, gen=_remove)
S(0x5e9150, 'ZWeaponRecycleList::FrameUpdate', 'thiscall', None, ret=None, gen=_frame)
S(0x5e90f0, 'ZWeaponRecycleList::Init', 'thiscall', None, ret=None, gen=_init)
S(0x5e9070, 'ZWeaponRecycleList::CopyData', 'thiscall', None, ret=None, gen=_copy)
S(0x594540, 'ZFFHERO::RemoveFromWeaponRecycleList', 'thiscall', None, ret=None, gen=_hero)
