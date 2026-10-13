"""specs_s81.py - inline session batch 81: CCheckInside ReadInput, CopyEventDataBlock, Save and Load, and
ZShotActivate Load and Save. The save/load objects and the DBREAD operators come from the shared serialisation
stubs (decomp-pilot/shared-harness/serial_stubs.py)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
import specs_s53 as k53
import serial_stubs as ss

_rnd = k53._rnd


def _dbread(c):
    r = c.rng
    rets32 = [r.getrandbits(32) for _ in range(8)]
    rets16 = [r.getrandbits(16) | (r.getrandbits(16) << 16) for _ in range(8)]
    counts = [r.randint(0, 3) for _ in range(8)]
    ss.dbread_patch(c, rets32, rets16, counts)
    ss.rm_object(c, r.getrandbits(32))


def _ri(c):
    self = _rnd(c, 0x80)
    db = _rnd(c, 0x40)
    _dbread(c)
    c.emu.mu.ctl_flush_tb()
    return [self, db]


def _save_ci(c):
    self = _rnd(c, 0x80)
    s = ss.save_obj(c, {0x60: ss.rec(c, 1), 0x3c: ss.rec(c, 1)})
    c.emu.mu.ctl_flush_tb()
    return [self, s]


def _load_ci(c):
    r = c.rng
    self = _rnd(c, 0x80)
    _dbread(c)
    s = ss.load_obj(c, {0x68: ss.wr(c, 1, 0, 1, r.getrandbits(8)), 0x40: ss.wr(c, 1, 0, 4, r.getrandbits(32))})
    c.emu.mu.ctl_flush_tb()
    return [self, s]


def _save_sa(c):
    self = _rnd(c, 0x80)
    s = ss.save_obj(c, {0x60: ss.rec(c, 1)})
    c.emu.mu.ctl_flush_tb()
    return [self, s]


def _load_sa(c):
    self = _rnd(c, 0x80)
    s = ss.load_obj(c, {0x68: ss.wr(c, 1, 0, 4, c.rng.getrandbits(32))})
    c.emu.mu.ctl_flush_tb()
    return [self, s]


S(0x4afa50, 'CCheckInside::ReadInput', 'thiscall', None, ret=None, gen=_ri, note='batch81; serial stubs')
S(0x4af6c0, 'CCheckInside::CopyEventDataBlock', 'thiscall', None, ret=None, gen=_ri, note='batch81; serial stubs')
S(0x4afb00, 'CCheckInside::Save', 'thiscall', None, ret='al', gen=_save_ci, note='batch81; serial stubs')
S(0x4af9f0, 'CCheckInside::Load', 'thiscall', None, ret='al', gen=_load_ci, note='batch81; serial stubs')
S(0x4c8e00, 'ZShotActivate::Load', 'thiscall', None, ret='al', gen=_load_sa, note='batch81; serial stubs')
S(0x4c9080, 'ZShotActivate::Save', 'thiscall', None, ret='al', gen=_save_sa, note='batch81; serial stubs')
