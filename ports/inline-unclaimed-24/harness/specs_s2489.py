"""specs_s2489.py - decomp area 24, batch 2489.
0x4b8a10 ZRelayMessageList::Load(ZLoadGame*): thiscall, ret 4, AL = 1; clears bit 0x40 of +4; slot 0x50 of the load object with this+0x54.
0x522740 ZTankIf::~ZTankIf(flags): thiscall, ret 4, returns this; vtable 0x6a06f4; base step 0x51aa60 (recorded, thiscall, no argument);
__builtin_delete (this, 0x20) when bit 0 is set.
0x51e810 ZHeliIf::~ZHeliIf(flags): thiscall, ret 4, returns this; vtable 0x69fa64; base step 0x519430 (recorded); delete (this, 0x1c).
0x488b60 ZMovementBaseMove::GetActiveWalkDefsList(): thiscall; owner at +4; slot 0x534 of the owner (returns AL fixed per case), flags
dword at owner+0x417 (0x400 and 0x800 tests); the result is this+0x25, this+0x3d, or this+0x55."""
from pilot import S
from recruits_util import rnd, pystub, obj, clear_hooks, hook_rec


def _load(c):
    clear_hooks(c)
    r = c.rng
    ld = obj(c, 0x40, {0x50: pystub(c, 1)})
    o = rnd(c, 0x100)
    return [o, ld]


def _tank(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x51aa60, 0, this=True)
    hook_rec(c, 0x634273, 2, pop=0)
    o = rnd(c, 0x100)
    return [o, r.choice([0, 1, 3])]


def _heli(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x519430, 0, this=True)
    hook_rec(c, 0x634273, 2, pop=0)
    o = rnd(c, 0x100)
    return [o, r.choice([0, 1, 2])]


def _walk(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    owner = obj(c, 0x440, {0x534: pystub(c, 0, ret=r.choice([0, 1]))})
    e.w32(owner + 0x417, r.choice([0, 0x400, 0x800, 0xc00]))
    o = rnd(c, 0x100)
    e.w32(o + 4, owner)
    return [o]


S(0x4b8a10, 'ZRelayMessageList::Load', 'thiscall', None, ret='al', gen=_load, note='batch2489')
S(0x522740, 'ZTankIf::~ZTankIf', 'thiscall', None, ret='eax', gen=_tank, note='batch2489')
S(0x51e810, 'ZHeliIf::~ZHeliIf', 'thiscall', None, ret='eax', gen=_heli, note='batch2489')
S(0x488b60, 'ZMovementBaseMove::GetActiveWalkDefsList', 'thiscall', None, ret='eax', gen=_walk, note='batch2489')
