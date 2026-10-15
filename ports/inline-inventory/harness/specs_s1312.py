"""specs_s1312.py - inventory thread batch 1312 (src/batch1312.cpp): ZFFInventorySelector::SwapWeapons.

Every callee is a stub or a hook on the exe address, so the port's calls must match the original's order and arguments.
GetInventoryInfo answers per (list, type) from a table built per case: list 1 (self+0x180) always has its record, list 2
(self+0x1d4) sometimes not. Items returned by the item slots are real objects (the code dereferences them).
"""
from pilot import S
from inv_helpers import Rec, rnd, set_global

SYS = 0x70039C
WEAPONS = [3, 5, 6, 7, 8, 11, 4, 10]
COUNTED = [13, 12, 14, 16, 15]


def _arg(emu, k):
    return emu.r32(emu.reg('esp') + 4 + 4 * k)


def _item(c, r, tmpl, spare, spare2):
    it = rnd(c, 0x40, 4)
    c.emu.w32(it, r.vtable({
        0x1E0: r.stub(41, 1, rand=True),
        0x2E8: r.stub(42, 0, rets=[tmpl]),
        0x320: r.stub(43, 0, rand=True),
        0x324: r.stub(44, 1, rand=True),
        0x328: r.stub(45, 0, rets=[spare]),
        0x360: r.stub(46, 1, rand=True),
        0x364: r.stub(47, 0, rets=[c.rng.randrange(0, 60)]),
        0x2C4: r.stub(48, 1, rets=[spare2]),
        0x2F0: r.stub(49, 3, rand=True),
    }))
    return it


def _record(c, obj, typ, flag):
    rec = rnd(c, 0x40, 4)
    c.emu.w32(rec, obj)
    c.emu.w32(rec + 4, c.rng.randrange(0, 60))
    c.emu.w32(rec + 0xC, c.rng.randrange(0, 60))
    c.emu.w32(rec + 0x10, typ)
    c.emu.w8(rec + 0x14, flag)
    c.emu.w32(rec + 0x19, 1 if c.rng.random() < 0.5 else c.rng.choice([0, 2]))
    return rec


def swap(c):
    r = Rec(c)
    objs, ids = {}, {}
    nxt = [0x40]

    def id_of(o):
        if o not in ids:
            nxt[0] += 4
            ids[o] = nxt[0]
            objs[nxt[0]] = o
        return ids[o]

    msg = {0x688968: c.rng.randrange(1, 0xffff), 0x688984: c.rng.randrange(1, 0xffff)}

    refobj = rnd(c, 0x1000, 4)
    fmt = rnd(c, 0x40, 4)
    c.emu.w32(fmt, r.vtable({0: r.stub(77, 2, rand=True)}))
    c.emu.w32(refobj + 0xAE4, fmt)
    c.emu.w32(refobj, r.vtable({
        0x58: lambda emu, res: emu.ret(eax=objs.get(_arg(emu, 0), 0), argbytes=4),
        0x4C: lambda emu, res: emu.ret(eax=id_of(_arg(emu, 0)), argbytes=4),
        0x114: lambda emu, res: emu.ret(eax=msg.get(_arg(emu, 0), 0x55), argbytes=16),
    }))
    sysobj = rnd(c, 0x2000, 4)
    set_global(c, SYS, sysobj)
    c.emu.w32(sysobj + 0x9B, refobj)

    tmpl = rnd(c, 0x80, 4)
    c.emu.w32(tmpl + 4, c.emu.cstr(c.rng.choice(['Beretta', 'Spas12', 'Molotov'])) if c.rng.random() < 0.8 else 0)
    spare = rnd(c, 0x40, 4)
    spare2 = rnd(c, 0x40, 4)
    spare_vt = r.vtable({0x1E0: r.stub(41, 1, rand=True), 0x2E8: r.stub(42, 0, rets=[tmpl]),
                         0x320: r.stub(43, 0, rand=True), 0x324: r.stub(44, 1, rand=True),
                         0x328: r.stub(45, 0, rets=[spare]), 0x360: r.stub(46, 1, rand=True),
                         0x364: r.stub(47, 0, rand=True), 0x2C4: r.stub(48, 1, rets=[spare2]),
                         0x2F0: r.stub(49, 3, rand=True)})
    c.emu.w32(spare, spare_vt)
    c.emu.w32(spare2, spare_vt)
    back_obj = _item(c, r, tmpl, spare, spare2)
    detached = _item(c, r, tmpl, spare, spare2)

    hero = rnd(c, 0x400, 4)
    c.emu.w32(hero, r.vtable({
        0x3DC: r.stub(50, 0, rand=True),
        0x4DC: r.stub(51, 2, rand=True),
        0x55C: r.stub(52, 1, rets=[c.rng.choice([0, 0, back_obj, detached])]),
        0x20: r.stub(53, 1, rand=True),
        0x3F4: r.stub(54, 1, rand=True),
    }))
    c.emu.w32(hero + 0xF12, c.rng.getrandbits(32))

    weapon = c.rng.choice(WEAPONS + COUNTED)
    # records: list 1 holds the selection and others; list 2 holds some with the same objects
    list1 = {}
    list2 = {}
    sel = _record(c, _item(c, r, tmpl, spare, spare2), weapon, 1)
    c.emu.w32(sel + 0x19, 1)
    list1[weapon] = sel
    for t in WEAPONS + COUNTED:
        if t == weapon:
            continue
        list1[t] = _record(c, _item(c, r, tmpl, spare, spare2), t, c.rng.choice([0, 1]))
        if c.rng.random() < 0.5:
            list2[t] = _record(c, _item(c, r, tmpl, spare, spare2), t, c.rng.choice([0, 1]))
    if c.rng.random() < 0.5:
        list2[weapon] = _record(c, _item(c, r, tmpl, spare, spare2), weapon, c.rng.choice([0, 1]))

    holder = rnd(c, 0x1000, 4)
    self_obj = rnd(c, 0x800, 4)
    c.emu.w32(self_obj + 0x90, hero)
    c.emu.w32(self_obj + 0x94, holder)
    c.emu.w32(self_obj + 0x291, weapon)
    c.emu.w32(self_obj + 0x44, rnd(c, 0x40, 4))
    osd = rnd(c, 0x40, 4)
    c.emu.w32(self_obj + 0x28C, osd)
    ui = rnd(c, 0x40, 4)
    c.emu.w32(ui, r.vtable({0x44: r.stub(61, 2, rand=True), 0x98: r.stub(62, 2, rand=True)}))
    c.emu.w32(self_obj + 0x288, ui)
    c.emu.w32(self_obj + 0x27C, rnd(c, 0x40, 4))

    lst1, lst2 = self_obj + 0x180, self_obj + 0x1D4

    def getinfo(emu, res):
        ecx = emu.reg('ecx')
        t = _arg(emu, 0)
        table = list1 if ecx == lst1 else list2
        emu.ret(eax=table.get(t, 0), argbytes=4)

    c.emu.hook(0x5AF130, getinfo)            # GetInventoryInfo(list, type) per (list, type)
    r.hook(0x5AF5B0, 81, 3, rand=True, writes={0: weapon, 1: c.rng.randrange(0, 30)}, quiet_args=(0, 1))
    r.hook(0x5AEDF0, 82, 1, rand=True)
    r.hook(0x5AF260, 83, 1, rand=True)
    r.hook(0x5AEF10, 84, 0, rand=True)
    r.hook(0x4CC1D0, 85, 0, rets=[c.rng.randrange(0, 4)])
    pool2 = list(list2.values()) or [list1[weapon]]
    r.hook(0x5AF0D0, 86, 1, rets=[c.rng.choice(pool2) for _ in range(8)])
    r.hook(0x5AEE20, 87, 2, rand=True)
    r.hook(0x591F00, 88, 0, rets=[c.rng.choice([0, back_obj])])
    r.hook(0x591080, 89, 0, rets=[detached])
    r.hook(0x59A580, 90, 3, rand=True)
    r.hook(0x5B0290, 91, 0, rand=True)
    r.hook(0x569260, 92, 0, rand=True)
    return [self_obj]


S(0x568DC0, 'ZFFInventorySelector::SwapWeapons', 'thiscall', None, ret=None, gen=swap, note='batch1312')
