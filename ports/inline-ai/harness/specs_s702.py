"""specs_s702.py - soldier AI batch 702: CCheckVisible::CanSee, OnGetAllVisible, OnSendVisiblePing.
State words are drawn so that every combination of the pending (0x8000) and visible (0x4000) bits occurs often.
The invisible-cheat float 0x700324 is 0.0 (60%), -0.0, 1.0 or NaN."""
import math
import struct
from pilot import S
from specs_s701 import _world, _cv, _plant, _ref


def _inv(c):
    v = c.rng.choice([0.0] * 6 + [-0.0, 1.0, math.nan, 1e-30, -2.0])
    c.emu.mu.mem_write(0x700324, struct.pack('<f', v))


def _states(c, cv, seer=None, obj=None):
    """Rewrite state words with heavy weight on the two top bits (whole table, or one seer row / object column)."""
    e = c.emu
    rows = range(200) if seer is None else [seer]
    cols = range(200) if obj is None else [obj]
    for k in rows:
        base = cv + 0x6bc + k * 0x1b8
        if obj is None:
            words = [(c.rng.choice([0, 0x4000, 0x8000, 0xc000, 0xc000]) | c.rng.getrandbits(14)) for _ in cols]
            e.wbytes(base, struct.pack('<200H', *words))
        else:
            e.w16(base + 2 * obj, c.rng.choice([0, 0x4000, 0x8000, 0xc000, 0xc000]) | c.rng.getrandbits(14))


def _cansee(c):
    _world(c)
    _inv(c)
    cv = _cv(c)
    seer = c.rng.choice([0, 199, c.rng.randrange(200)])
    ref = _ref(c)
    if c.rng.random() < 0.75:
        i = c.rng.randrange(200)
        c.emu.w32(cv + 0x54 + 8 * i, ref)
        _states(c, cv, seer=seer, obj=i)
    return [cv, seer, ref]


S(0x4a9cb0, 'CCheckVisible::CanSee', 'thiscall', None, ret='al', gen=_cansee,
  note='b702 [high]; MYSTR c_str/dtor hooked (see specs_s701)')


def _getall(c):
    _world(c)
    _inv(c)
    cv = _cv(c)
    ref = _ref(c)
    if c.rng.random() < 0.8:
        k = c.rng.randrange(200)
        c.emu.w32(cv + 0x694 + k * 0x1b8, ref)
        _states(c, cv, seer=k)
    return [cv, ref]


S(0x4ab020, 'CCheckVisible::OnGetAllVisible', 'thiscall', None, ret='eax', gen=_getall, note='b702 [high]')


def _ping(c):
    _world(c)
    _inv(c)
    cv = _cv(c)
    ref = _ref(c)
    if c.rng.random() < 0.8:
        i = c.rng.randrange(200)
        c.emu.w32(cv + 0x54 + 8 * i, ref)
        for k in range(200):
            c.emu.w16(cv + 0x6bc + k * 0x1b8 + 2 * i, c.rng.choice([0, 0x4000, 0x8000, 0xc000, 0xc000]) | c.rng.getrandbits(14))
    return [cv, ref]


S(0x4ab320, 'CCheckVisible::OnSendVisiblePing', 'thiscall', None, ret='eax', gen=_ping, note='b702 [medium]')
