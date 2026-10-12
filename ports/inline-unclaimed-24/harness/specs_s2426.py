"""specs_s2426.py - decomp area 24, batch 2426: three short functions with one vtable call each.
0x4b1bb0 ZCutSeqBlood::Init(ZGEOM*, DBREAD&), thiscall, ret 8: object at +0x44 gets slot 0xbc with argument 1 when bit
10 of the dword at [[+0x44]+8]+0x3c is clear. The slot is a recorder (one stack argument).
0x4743f0 (GUESS, unnamed): if the byte at +0x55 is zero the result is 0; else the sys table (0x70039c)+0x9b gets slot 0x58
with the dword at +0x51, and that result is returned (plain ret, thiscall). Slot 0x58 is a recorder.
0x4f7070 ZScrollArea::DestroyCamera(): the camera at +0x93 (when set) gets slot 0x210 with argument 1, then the pointer
is cleared. The slot is a recorder."""
from pilot import S
from recruits_util import rnd, pystub, obj, sysobj, clear_hooks


def _init(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    self_ = rnd(c, 0x100)
    o3 = rnd(c, 0x80)
    e.w32(o3 + 0x3c, r.getrandbits(32))
    o2 = obj(c, 0x80, {0xbc: pystub(c, 1)})
    e.w32(o2 + 8, o3)
    e.w32(self_ + 0x44, o2)
    return [self_, rnd(c, 0x40), rnd(c, 0x40)]


def _lookup(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    sysobj(c, table_slots={0x58: pystub(c, 1, ret=lambda emu, k: r.getrandbits(32))})
    self_ = rnd(c, 0x80)
    e.w8(self_ + 0x55, r.choice([0, 1, 1]))
    e.w32(self_ + 0x51, r.getrandbits(32))
    return [self_]


def _destroy(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    self_ = rnd(c, 0x100)
    if r.random() < 0.7:
        cam = obj(c, 0x40, {0x210: pystub(c, 1)})
        e.w32(self_ + 0x93, cam)
    else:
        e.w32(self_ + 0x93, 0)
    return [self_]


S(0x4b1bb0, 'ZCutSeqBlood::Init', 'thiscall', None, ret=None, gen=_init, note='batch2426')
S(0x4743f0, 'GUESS: table lookup on sys object (0x4743f0)', 'thiscall', None, ret='eax', gen=_lookup, note='batch2426')
S(0x4f7070, 'ZScrollArea::DestroyCamera', 'thiscall', None, ret=None, gen=_destroy, note='batch2426')
