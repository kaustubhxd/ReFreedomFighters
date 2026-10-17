"""specs_s1310.py - inventory thread batch 1310 (src/batch1310.cpp): ZFFInventorySelector::Init2.

Every callee is a logged stub (inv_helpers.Rec), so the original and the port must make the same calls in the same
order with the same arguments. Return values come from the case rng at generation time.
"""
from pilot import S
from inv_helpers import Rec, rnd, set_global

SYS = 0x70039c
HERO_NAME, LIST1_NAME, LIST2_NAME = 0x681320, 0x6a7374, 0x6a738c
WEAPONS = [3, 5, 6, 7, 8, 11, 4, 10]
COUNTED = [13, 12, 14, 16, 15]


def _arg(emu, k):
    return emu.r32(emu.reg('esp') + 4 + 4 * k)


def _sys_and_ref(c, r):
    """sys object with ref table (id->obj by a dict, obj->id by a dict) and the message map (names -> ids)."""
    objs, ids = {}, {}
    names = {}
    nxt = [0x40]

    def id_of(o):
        if o not in ids:
            nxt[0] += 4
            ids[o] = nxt[0]
            objs[nxt[0]] = o
        return ids[o]

    hero = rnd(c, 0x40, 4)
    names[HERO_NAME] = id_of(hero)
    names[LIST1_NAME] = id_of(rnd(c, 0x40, 4))
    names[LIST2_NAME] = id_of(rnd(c, 0x40, 4))

    def m88(emu, res):
        name = _arg(emu, 0)
        out = _arg(emu, 1)
        emu.w32(out, names.get(name, 0))
        emu.ret(argbytes=8)

    m = r.vtable({0x88: m88})
    mobj = rnd(c, 0x40, 4)
    c.emu.w32(mobj, m)

    def h138(emu, res):
        emu.ret(eax=mobj, argbytes=0)

    def h58(emu, res):
        emu.ret(eax=objs.get(_arg(emu, 0), 0), argbytes=4)

    def h4c(emu, res):
        emu.ret(eax=id_of(_arg(emu, 0)), argbytes=4)

    refobj = rnd(c, 0x40, 4)
    c.emu.w32(refobj, r.vtable({0x138: h138, 0x58: h58, 0x4c: h4c}))
    sysobj = rnd(c, 0x2000, 4)
    set_global(c, SYS, sysobj)
    c.emu.w32(sysobj + 0x9b, refobj)
    return sysobj


def _info_pool(c, r, n):
    """Info records (+0 object with vtable slot 0x354, +4 ammo, +0xc max, +0x10 type, +0x14 flag)."""
    recs = [0]
    for _ in range(n):
        if c.rng.random() < 0.25:
            recs.append(0)
            continue
        rec = rnd(c, 0x20, 4)
        obj = rnd(c, 0x20, 4)
        c.emu.w32(obj, r.vtable({0x354: r.stub(55, 0, rets=[c.rng.randrange(0, 60)])}))
        c.emu.w32(rec, obj)
        c.emu.w32(rec + 4, c.rng.randrange(0, 40))
        c.emu.w32(rec + 0xc, c.rng.randrange(0, 60))
        c.emu.w32(rec + 0x10, c.rng.choice(WEAPONS + COUNTED))
        c.emu.w8(rec + 0x14, c.rng.choice([0, 0, 1]))
        recs.append(rec)
    return recs


def _maxc_writer(vals):
    """GetMaxInventory(this=ctrl, out): one stack argument, the 20-byte count written through it."""
    def h(emu, res):
        out = _arg(emu, 0)
        for i, v in enumerate(vals):
            emu.w32(out + 4 * i, v)
        emu.ret(argbytes=4)
    return h


def init2(c):
    r = Rec(c)
    sysobj = _sys_and_ref(c, r)

    # the profile holder: byte +0x4a = chapter digit; the profile is at +0x57 of the holder
    holder = rnd(c, 0x1000, 4)
    c.emu.w8(holder + 0x4a, c.rng.choice([0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x31, 0x39, 0]))
    self_obj = rnd(c, 0x800, 4)
    c.emu.w32(self_obj + 0x94, holder)
    if c.rng.random() < 0.08:
        c.emu.w32(self_obj + 0x94, 0)

    r.hook(0x5aee60, 10, 1, rand=True)                                        # AddList
    lt, st, cn = c.rng.choice(WEAPONS + COUNTED + [0]), c.rng.choice(WEAPONS + COUNTED + [0]), c.rng.randrange(0, 30)
    r.hook(0x5b04a0, 11, 2, rand=True, writes={0: lt, 1: cn}, quiet_args=(0, 1))                  # GetLargeItem(type&, count&)
    r.hook(0x5b04c0, 12, 2, rand=True, writes={0: st, 1: c.rng.randrange(0, 30)}, quiet_args=(0, 1))  # GetSmallItem
    r.hook(0x5adda0, 13, 0, rets=[c.rng.choice([0, 1, 0x100, 0xff00])])       # FirstTimeInZone (al)
    r.hook(0x5aef80, 14, 1, rand=True)                                        # GetAmmo(list, type)
    r.hook(0x5b07d0, 15, 2, rand=True)                                        # SetLargeItem
    r.hook(0x5b07f0, 16, 2, rand=True)                                        # SetSmallItem
    r.hook(0x567930, 17, 1, rand=True)                                        # AddAdditionalWeapons
    r.hook(0x5af230, 18, 1, rets=[c.rng.choice([0, 1, 1, 0x100]) for _ in range(8)])  # ItemAvailible
    r.hook(0x5aefc0, 19, 1, rand=True)                                        # GetAmmoForItem
    pool = _info_pool(c, r, 40)
    r.hook(0x5af130, 20, 1, rets=pool)                                        # GetInventoryInfo(list, type)
    r.hook(0x5aedf0, 21, 1, rand=True)                                        # add unique (list, info)
    r.hook(0x5afc10, 22, 0, rand=True)                                        # controller ctor
    maxvals = [c.rng.randrange(0, 20) for _ in range(5)]
    c.emu.hook(0x5afce0, _maxc_writer(maxvals))                              # GetMaxInventory(ctrl, out)
    r.hook(0x5af2a0, 24, 2, rand=True)                                        # SetNoOfItem
    r.hook(0x5b04e0, 25, 5, rand=True)                                        # GiveDefaultAdditional (by value)
    r.hook(0x5af260, 26, 1, rand=True)                                        # RemoveInventoryInfo
    r.hook(0x5aef10, 27, 0, rand=True)                                        # rebel unlock reset
    r.hook(0x4cc1d0, 28, 0, rets=[c.rng.randrange(0, 4)])                     # list count
    valid = [p for p in pool if p] or [pool[0]]
    r.hook(0x5af0d0, 29, 1, rets=[c.rng.choice(valid) for _ in range(16)])     # never null: the port reads +0x14
    r.hook(0x5aee20, 30, 2, rand=True)                                        # rebel stash add
    r.hook(0x569260, 31, 0, rand=True)                                        # UpdateWeaponStash
    self_obj_vt = r.vtable({0x64: r.stub(32, 1, rand=True)})
    c.emu.w32(self_obj, self_obj_vt)
    # hero slot writes make the selector fields readable; the port and the original start from the same bytes
    return [self_obj]


S(0x568350, 'ZFFInventorySelector::Init2', 'thiscall', None, ret=None, gen=init2, note='batch1310')
