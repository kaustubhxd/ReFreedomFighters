"""specs_c120.py - climb thread batch 120: ZGameOSD::PlaySound (0x59a5e0)."""
import struct
from pilot import S
from ckit import obj, rnd


def _ps(c):
    r = c.rng
    e = c.emu
    osd = rnd(c, 0x100)
    for i in range(6):
        e.w32(osd + 0x89 + 4 * i, r.choice([0, 0x12340000 + i, r.getrandbits(32)]))
    idx = r.choice([0, 1, 2, 3, 5, r.getrandbits(32) & 0xff])
    sys_ = rnd(c, 0x100)
    e.w32(0x70039c, sys_)
    mgr_on = r.random() < 0.85
    if mgr_on:
        def play(e, t, a):
            return (r.choice([0, 0x77, r.getrandbits(32)]), None, (a[0], a[1]))
        mgr = obj(e, 'soundmgr', 0x40, {0x120: (2, play)}, rng=r)
        e.w32(sys_ + 0x1a9f, mgr)
    else:
        e.w32(sys_ + 0x1a9f, 0)
    pool = [rnd(c, 0x100) for _ in range(3)]
    for p in pool:
        e.w32(p + 0x40, r.getrandbits(32))

    def eng60(e, t, a):
        k = r.random()
        return (0 if k < 0.3 else pool[r.randrange(len(pool))], None, (a[0],))
    db = obj(e, 'enginedb', 0x40, {0x60: (1, eng60)})
    e.w32(sys_ + 0x9b, db)
    return [osd, idx]


S(0x59a5e0, 'ZGameOSD::PlaySound', 'thiscall', None, ret='eax', gen=_ps,
  note='c120; sound manager and engine are logging fakes')
