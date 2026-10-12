"""specs_s254.py - area 22, batch254 (src/batch254.cpp): ZFFInventoryBridge::GetNoOfItem. Same world as specs_s252's
GetWeapon: stack REFTAB32 as exe code, filled by the owner's SendCommand like REFTAB::Add; GetInventoryInfo(EFFItemType)
0x5af130 runs as exe code (verified in batch253)."""
from pilot import S
from helpers22 import _rnd, _multi_vt, _pyvt, _log_world

KINDS = [3, 4, 5, 6, 7, 8, 10, 11, 0, 1, 2, 9, 12]


def _r(c):
    return c.rng.getrandbits(32)


def _g_5af430(c):
    e = c.emu
    _log_world(c)
    nrec = c.rng.choice([0, 1, 3, 5])
    info = e.alloc(4 + 4 * nrec + 8, 4)
    e.w32(info, nrec)
    tmpls, kinds = [], []
    for i in range(nrec):
        rec = _rnd(c, 0x14)
        t = c.rng.choice([_r(c)] * 5 + [0])
        k = c.rng.choice(KINDS + [_r(c)])
        tmpls.append(t)
        kinds.append(k)
        e.w32(rec, t)
        e.w32(rec + 0x10, k)
        e.w32(info + 4 + 4 * i, rec)
    n = c.rng.choice([0, 1, 2, 3, 5, 8, 20])
    ids = [_r(c) for _ in range(n)]
    geoms = {}
    for i in ids:
        t = c.rng.choice(tmpls + [_r(c)]) if tmpls else _r(c)
        g = _rnd(c, 0x10)
        e.w32(g, _multi_vt(c, {0x2e8: (lambda em, a, t=t: (t, None), 0)}))
        geoms[i] = g
    db = _rnd(c, 0x40)
    e.w32(db, _multi_vt(c, {0x58: (lambda em, a, m=geoms: (m.get(a[0], 0), None), 1),
                            0x114: (lambda em, a, v=_r(c): (v, None), 4)}))
    rm = _rnd(c, 0x100)
    e.w32(rm + 0x9b, db)
    e.w32(0x70039c, rm)

    def send(em, r):
        o, cmd, tab = em.arg32(0), em.arg32(1), em.arg32(2)
        em.calllog.append(('owner.130', 0x130, em.reg('ecx'), (o, cmd)))
        if ids:
            ch = tab + 0x1c
            em.w32(ch, 0)
            em.w32(ch + 4, 0)
            em.w32(ch + 8, len(ids))
            for k, i in enumerate(ids):
                em.w32(ch + 0x10 + 4 * k, i)
            em.w32(tab + 4, ch)
            em.w32(tab + 8, ch)
            em.w32(tab + 0x14, len(ids))
        em.ret(eax=0, argbytes=12)
    owner = _rnd(c, 0x10)
    e.w32(owner, _pyvt(c, {0x130: send}))
    self_ = _rnd(c, 0x10)
    e.w32(self_, c.rng.choice([owner] * 6 + [0]))
    e.w32(self_ + 4, c.rng.choice([info] * 6 + [0]))
    e.w32(self_ + 8, c.rng.choice([_r(c) | 1] * 6 + [0]))
    e.mu.ctl_flush_tb()
    return [self_, c.rng.choice(kinds + [_r(c)]) if kinds else _r(c)]


S(0x5af430, 'ZFFInventoryBridge::GetNoOfItem', 'thiscall', None, ret='eax', gen=_g_5af430,
  note='batch254; stack REFTAB32 runs as exe code; SEH frame and cookie not reproduced')
