"""specs_s704.py - soldier AI batch 704: CCheckVisible OnCheckVisibleTo, OnForceVisible, OnSeerAdd.
OnForceVisible plants the seer ref in up to three slots and the object in some, so 'seer found but object
missing, next seer slot' paths run."""
from pilot import S
from specs_s701 import _world, _cv, _ref
from specs_s702 import _inv


def _cvt(c):
    _world(c)
    _inv(c)
    cv = _cv(c)
    s, o = _ref(c), _ref(c)
    if c.rng.random() < 0.8:
        c.emu.w32(cv + 0x694 + 0x1b8 * c.rng.randrange(200), s)
    if c.rng.random() < 0.7:
        i = c.rng.randrange(200)
        c.emu.w32(cv + 0x54 + 8 * i, o)
    ev = c.emu.alloc(12, 4)
    c.emu.wbytes(ev, c.rng.randbytes(12))
    c.emu.w32(ev, s)
    c.emu.w32(ev + 4, o)
    return [cv, ev]


S(0x4aad50, 'CCheckVisible::OnCheckVisibleTo', 'thiscall', None, ret='eax', gen=_cvt,
  note='b704 [high]; CanSee runs as exe code')


def _force(c):
    _world(c)
    _inv(c)
    cv = _cv(c)
    s, o = _ref(c), _ref(c)
    for _ in range(c.rng.choice([0, 1, 1, 3])):
        c.emu.w32(cv + 0x694 + 0x1b8 * c.rng.randrange(200), s)
    if c.rng.random() < 0.7:
        i = c.rng.randrange(200)
        c.emu.w32(cv + 0x54 + 8 * i, o)
    ev = c.emu.alloc(8, 4)
    c.emu.w32(ev, s)
    c.emu.w32(ev + 4, o)
    return [cv, ev]


S(0x4aae40, 'CCheckVisible::OnForceVisible', 'thiscall', None, ret='eax', gen=_force, note='b704 [high]')


def _seeradd(c):
    _world(c)
    return [_cv(c), _ref(c)]


S(0x4ab1c0, 'CCheckVisible::OnSeerAdd', 'thiscall', None, ret='eax', gen=_seeradd, note='b704 [high]')
