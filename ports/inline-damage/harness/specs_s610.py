"""specs_s610.py - damage batch 610: ZFFGameData::GetHitpointMultiplier and ZIKLNKOBJ::GetBoneCollision."""
import struct
from pilot import S
from wkit import rnd, stub, obj, fedge

NAMES = [b'EnemyPolice', b'EnemySoldier', b'EnemySergent', b'EnemySpecialist', b'EnemyVeteran', b'EnemySniper',
         b'EnemySpetsnaz', b'Friendly', b'Hero', b'FriendlyMP', b'HeroMP', b'EnemySoldie', b'Heroes', b'', b'Enemy']


def _ghm(c):
    r = c.rng
    emu = c.emu
    gd = rnd(c, 0x2c20)
    for i in range(36 + 2):
        emu.wf32(gd + 0xab9 + 4 * i, r.choice((1.0, 3.0, 0.5, fedge(c), r.uniform(0, 5))))
    cur = rnd(c, 0x420)
    emu.w32(cur + 0x411, r.choice((0, 1, 2, 3, 4, 0xffffffff)))
    emu.w32(gd + 0x2c15, cur)
    nm = r.choice(NAMES)
    a = emu.alloc(len(nm) + 1, 4)
    emu.wbytes(a, nm + b'\0')
    o2 = obj(c, 0x10, {0x2c: stub(c, 3, cdecl=True)})
    emu.w32(0x700390, obj(c, 0x10, {0x20: stub(c, 2, ret=o2)}))
    r.random()   # 2026-10-12: hook always set (strict rule, faulting_cases == 0)
    emu.w32(0x7003b0, stub(c, 0, cdecl=True))
    return [gd, a, r.choice((0, 1, 2, 3, 4, 7, -1, 0x80000000)) & 0xffffffff]


def _gbc(c):
    r = c.rng
    emu = c.emu
    off = emu.alloc(16, 4)
    for i in range(3):
        emu.wf32(off + 4 * i, r.uniform(-50, 50))
    tab = rnd(c, 48 * 20)
    pos = emu.alloc(16, 4)
    d = emu.alloc(16, 4)
    for i in range(3):
        emu.wf32(pos + 4 * i, r.uniform(-500, 500))
        emu.wf32(d + 4 * i, r.choice((r.uniform(-1, 1), 0.0, fedge(c))))
    o = obj(c, 0x40, {0x8c: stub(c, 1, skip=(0,), adds=[(0, off, 3)]),
                      0x88: stub(c, 1, skip=(0,), adds=[(0, off, 3)]),
                      0x2b8: stub(c, 1, skip=(0,), copy=(0, [(0, 'd'), (4, 'd'), (8, 'd')]),
                                  ret=r.choice((0xffffffff, r.randrange(0, 20), r.randrange(0, 20)))),
                      0x2cc: stub(c, 0, ret=tab)})
    g = rnd(c, 0x40)
    for i in range(3):
        emu.wf32(g + 4 * i, r.uniform(-1, 1))
    emu.w32(o + 8, g)
    out = rnd(c, 8)
    return [o, out, pos, d]


S(0x589c40, 'ZFFGameData::GetHitpointMultiplier', 'thiscall', ret='st0', gen=_ghm)
S(0x4666e0, 'ZIKLNKOBJ::GetBoneCollision', 'thiscall', ret='eax', gen=_gbc)
