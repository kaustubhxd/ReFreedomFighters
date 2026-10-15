"""specs_s1311.py - inventory thread batch 1311 (src/batch1311.cpp): ZFFInventorySelector::Init.

Fake HUD group (ref id -> object) whose slot 0x25c(name, 0) returns the child id for that name (a per-case dict, so
the original and the port store the same values). The message map gives ids for 0x6a71d4 (group) and any owner.
"""
from pilot import S
from inv_helpers import Rec, rnd, set_global

SYS = 0x70039c
GROUP_NAME = 0x6a71d4
OWNER_NAME = 0x6a70a8
CHILD_NAMES = [0x6a71e0, 0x6a71f0, 0x6a7200, 0x6a7214, 0x6a7220, 0x6a7230, 0x6a7244, 0x6a724c, 0x6a7258,
               0x6a7268, 0x6a7270, 0x6a727c, 0x6a728c, 0x6a7298, 0x6a72a8, 0x6a72bc, 0x6a72c4, 0x6a72d0,
               0x6a72e0, 0x6a72ec, 0x6a72fc, 0x6a7310, 0x6a7318, 0x6a7324, 0x6a7334, 0x6a7340, 0x6a7350,
               0x6a7358, 0x6a7368]


def _init(c):
    r = Rec(c)
    objs, ids = {}, {}
    nxt = [0x40]

    def id_of(o):
        if o not in ids:
            nxt[0] += 4
            ids[o] = nxt[0]
            objs[nxt[0]] = o
        return ids[o]

    owner_obj = rnd(c, 0x40, 4)
    group = rnd(c, 0x40, 4)
    names = {OWNER_NAME: id_of(owner_obj), GROUP_NAME: id_of(group)}
    child_ids = {n: c.rng.getrandbits(32) | 0x40 for n in CHILD_NAMES}

    def m88(emu, res):
        name = emu.r32(emu.reg('esp') + 4)
        out = emu.r32(emu.reg('esp') + 8)
        emu.w32(out, names.get(name, 0))
        emu.ret(argbytes=8)

    def m60(emu, res):   # (name, owner id, flag) on the HUD map: nothing to record here
        emu.ret(argbytes=12)

    m1 = rnd(c, 0x40, 4)
    c.emu.w32(m1, r.vtable({0x60: m60}))
    mobj = rnd(c, 0x40, 4)
    c.emu.w32(mobj, r.vtable({0x88: m88}))

    calls = {'n': 0}

    def h138(emu, res):
        # first message-map lookup is m1 (slot 0x60), the second is mobj (slot 0x88): the original's order
        calls['n'] += 1
        emu.ret(eax=m1 if calls['n'] % 2 == 1 else mobj, argbytes=0)

    def h58(emu, res):
        emu.ret(eax=objs.get(emu.r32(emu.reg('esp') + 4), 0), argbytes=4)

    def h4c(emu, res):
        emu.ret(eax=id_of(emu.r32(emu.reg('esp') + 4)), argbytes=4)

    refobj = rnd(c, 0x40, 4)
    c.emu.w32(refobj, r.vtable({0x138: h138, 0x58: h58, 0x4c: h4c}))

    def h25c(emu, res):
        name = emu.r32(emu.reg('esp') + 4)
        emu.ret(eax=child_ids.get(name, 0), argbytes=8)

    c.emu.w32(group, r.vtable({0x25c: h25c}))

    sysobj = rnd(c, 0x2000, 4)
    set_global(c, SYS, sysobj)
    c.emu.w32(sysobj + 0x9b, refobj)
    return r, mobj, m1


def init(c):
    r, mobj, m1 = _init(c)
    r.hook(0x562440, 90, 0, rand=True)                      # CBaseWindow::Init
    self_obj = rnd(c, 0x800, 4)
    c.emu.w32(self_obj + 0x44, rnd(c, 0x40, 4))
    c.emu.w32(self_obj, r.vtable({}))
    return [self_obj]


S(0x568900, 'ZFFInventorySelector::Init', 'thiscall', None, ret=None, gen=init, note='batch1311')
