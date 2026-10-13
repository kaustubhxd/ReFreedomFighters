"""specs_s253.py - area 22, batch253 (src/batch253.cpp): ZFFInventoryInfoList::GetInventoryInfo(EFFItemType),
ZFFInventoryBridge::SetAmmo and ZFFInventoryBridge::GiveAmmo. All callees are logged vtable slots with their exe arities
(db vt[0x4c] 1 word via 0x48ff90 -> 0x497390 ret 4, vt[0x154] 2 words ret 8; item vt[0x2f0] 3 words from the stack
balance of 0x5af7c0). Results of repeated calls (db vt[0x58], owner vt[0x55c]) come from per-case sequences."""
from pilot import S
from helpers22 import _rnd, _multi_vt

KINDS = [3, 4, 5, 6, 7, 8, 10, 11, 0, 1, 2, 9, 12]


def _r(c):
    return c.rng.getrandbits(32)


def _infos(c, n):
    lst = c.emu.alloc(4 + 4 * n + 8, 4)
    c.emu.w32(lst, n)
    kinds = []
    for i in range(n):
        rec = _rnd(c, 0x14)
        k = c.rng.choice(KINDS + [_r(c)])
        kinds.append(k)
        c.emu.w32(rec, c.rng.choice([_r(c), _r(c), 0]))
        c.emu.w32(rec + 0x10, k)
        c.emu.w32(lst + 4 + 4 * i, rec)
    return lst, kinds


def _g_5af130(c):
    lst, kinds = _infos(c, c.rng.choice([0, 1, 2, 4, 7]))
    return [lst, c.rng.choice(kinds + [_r(c)]) if kinds else _r(c)]


def _obj(c, slots):
    o = _rnd(c, 0x10)
    c.emu.w32(o, _multi_vt(c, slots))
    return o


def _seq(seq, default):
    return lambda em, a: (seq.pop(0) if seq else default, None)


def _spare(c):
    return _obj(c, {0x324: (lambda em, a: (0, None), 1)})


def _gun(c):
    tm = _obj(c, {0x2c4: (lambda em, a, it=_obj(c, {0x2f0: (lambda em, a: (0, None), 3),
                                                   0x2d0: (lambda em, a: (0, None), 2)}): (it, None), 1)})
    return _obj(c, {0x35c: (lambda em, a, v=_r(c) & 0xffff: (v, None), 0),
                    0x360: (lambda em, a: (0, None), 1),
                    0x328: (lambda em, a, t=tm: (t, None), 0),
                    0x1e0: (lambda em, a, v=(_r(c) & ~0xff) | c.rng.choice([0, 1, 1, 0x40]): (v, None), 1)})


def _flag(c):
    return (_r(c) & ~0xff) | c.rng.choice([0, 1, 0, 0x80])


def _g_5afb40(c):
    flag = _flag(c)
    sp = _spare(c) if (flag & 0xff) or c.rng.random() < 0.6 else 0
    owner = _obj(c, {0x55c: (lambda em, a, s=sp: (s, None), 1)})
    self_ = _rnd(c, 0x10)
    c.emu.w32(self_, owner)
    return [self_, _gun(c), _r(c), flag]


def _g_5af7c0(c):
    e = c.emu
    flag = _flag(c)
    gun = _gun(c)
    sp = _spare(c)
    first = c.rng.choice([0, sp])
    owner = _obj(c, {0x55c: (_seq([first, sp if flag & 0xff else c.rng.choice([0, sp])], sp), 1),
                     0x20: (lambda em, a, v=_r(c): (v, None), 1)})
    lst, kinds = _infos(c, c.rng.choice([0, 1, 3, 5]))
    mgr = _obj(c, {0x98: (lambda em, a, v=_r(c): (v, None), 2)})
    ci = _rnd(c, 0x30)
    dseq = c.rng.choice([[gun, gun, gun]] * 5 + [[0], [gun, gun, 0], [_rnd(c, 0x10), gun, gun]])
    db = _obj(c, {0x58: (_seq(list(dseq), gun), 1),
                  0x154: (lambda em, a, v=ci: (v, None), 2),
                  0x4c: (lambda em, a, v=_r(c): (v, None), 1)})
    if dseq[0] and dseq[0] != gun:   # a geom whose class test is answered by the gun-like slot
        e.w32(dseq[0], e.r32(gun))
    rm = _rnd(c, 0x100)
    e.w32(rm + 0x9b, db)
    e.w32(0x70039c, rm)
    self_ = _rnd(c, 0x10)
    e.w32(self_, owner)
    e.w32(self_ + 4, lst)
    e.w32(self_ + 8, mgr)
    e.mu.ctl_flush_tb()
    return [self_, c.rng.choice(kinds + [_r(c)]) if kinds else _r(c), _r(c), flag]


S(0x5af130, 'ZFFInventoryInfoList::GetInventoryInfo(EFFItemType)', 'thiscall', None, ret='eax', gen=_g_5af130,
  note='batch253; linear search of the info records by kind (+0x10)')
S(0x5afb40, 'ZFFInventoryBridge::SetAmmo', 'thiscall', None, ret=None, gen=_g_5afb40,
  note='batch253; void; spareOnly with no spare item faults in the exe, so inputs always give one then')
S(0x5af7c0, 'ZFFInventoryBridge::GiveAmmo', 'thiscall', None, ret=None, gen=_g_5af7c0,
  note='batch253; void; creates the spare-ammo item when the owner has none')
