"""specs_s1313.py - inventory thread batch 1313 (src/batch1313.cpp): ZFFInventorySelector::FrameUpdate.

Callees are logged stubs or hooks on the exe addresses. GetInventoryInfo and the record index answer from per-case
tables (keyed by the list address), the count answers per list. SwapWeapons (0x568dc0) is a logged stub, so only the
call is compared here. The hero slot 0x84 takes one stack argument.
"""
from pilot import S
from inv_helpers import Rec, rnd, set_global

SYS = 0x70039C
WEAPONS = [3, 5, 6, 7, 8, 11, 4, 10]
COUNTED = [13, 12, 14, 16, 15]


def _arg(emu, k):
    return emu.r32(emu.reg('esp') + 4 + 4 * k)


def _cstr(c, emu, n):
    return emu.cstr(''.join(chr(ord('a') + c.rng.randrange(26)) for _ in range(n)))


def frame(c):
    r = Rec(c)
    sysobj = rnd(c, 0x2000, 4)
    set_global(c, SYS, sysobj)
    ref = rnd(c, 0x1000, 4)
    c.emu.w32(sysobj + 0x9B, ref)
    # the formatter (ref+0xae4): slot 0 returns one text per call, in order
    texts = [_cstr(c, c.emu, c.rng.randrange(0, 30)) for _ in range(40)]
    fmt = rnd(c, 0x40, 4)
    c.emu.w32(fmt, r.vtable({0: r.stub(77, 2, rets=texts)}))
    c.emu.w32(ref + 0xAE4, fmt)
    # the object at sys+0x1907: slot 0x60 (returns object A), slot 0x2c (returns a bool)
    a_obj = rnd(c, 0x40, 4)
    c.emu.w32(a_obj, r.vtable({0x14: r.stub(78, 1, rand=True)}))
    x = rnd(c, 0x40, 4)
    c.emu.w32(x, r.vtable({0x60: r.stub(79, 1, rets=[a_obj]), 0x2C: r.stub(80, 2, rand=True)}))
    c.emu.w32(sysobj + 0x1907, x)

    # the hero (ZFFHERO) with the osd pointer at +0x852
    osd = rnd(c, 0x2000, 4)
    ui = rnd(c, 0x40, 4)
    c.emu.w32(osd + 0x1D0F, ui)
    hero = rnd(c, 0x1000, 4)
    c.emu.w32(hero + 0x852, osd)
    c.emu.w32(hero, r.vtable({0x464: r.stub(81, 0, rand=True), 0x84: r.stub(82, 1, rand=True)}))

    self_obj = rnd(c, 0x800, 4)
    c.emu.w32(self_obj + 0x90, hero)
    c.emu.w8(self_obj + 0x290, c.rng.choice([0, 1, 1]))
    c.emu.w32(self_obj + 0x291, c.rng.choice([0, 3, 5, 6, 7, 8, 11, 4, 10, 13]))
    c.emu.w32(self_obj + 0x29D, 0)
    list1, list2, list3 = self_obj + 0x180, self_obj + 0x1D4, self_obj + 0x228

    # slots 0x3ee..: eight (value object, type) pairs; the value object has slot 0x84 (1 arg)
    for k in range(8):
        base = self_obj + 0x3EE + 8 * k
        if c.rng.random() < 0.7:
            vo = rnd(c, 0x40, 4)
            c.emu.w32(vo, r.vtable({0x84: r.stub(83, 1, rets=[0])}))
            c.emu.w32(base, vo)
        else:
            c.emu.w32(base, 0)
        c.emu.w32(base + 4, c.rng.choice(WEAPONS + COUNTED))

    recs1 = {}
    recs2 = {}
    for t in WEAPONS + COUNTED:
        o = rnd(c, 0x40, 4)
        c.emu.w32(o, r.vtable({0x84: r.stub(84, 1, rets=[0])}))
        rec = rnd(c, 0x40, 4)
        c.emu.w32(rec, o)
        c.emu.w32(rec + 4, c.rng.randrange(0, 40))
        c.emu.w32(rec + 0xC, c.rng.randrange(0, 60))
        c.emu.w32(rec + 0x10, t)
        c.emu.w8(rec + 0x14, c.rng.choice([0, 1]))
        c.emu.w32(rec + 0x19, c.rng.choice([0, 1, 2]))
        recs1[t] = rec
        if c.rng.random() < 0.6:
            recs2[t] = rec

    counts = {list1: c.rng.randrange(0, 4), list2: c.rng.randrange(0, 4), list3: c.rng.randrange(0, 3)}
    rec_seq = [recs2[t] for t in recs2] or [recs1[WEAPONS[0]]]

    def getinfo(emu, res):
        ecx = emu.reg('ecx')
        t = _arg(emu, 0)
        table = recs1 if ecx == list1 else recs2
        emu.ret(eax=table.get(t, 0), argbytes=4)

    def getrec(emu, res):
        ecx = emu.reg('ecx')
        emu.ret(eax=rec_seq[_arg(emu, 0) % len(rec_seq)], argbytes=4)

    def cnt(emu, res):
        emu.ret(eax=counts.get(emu.reg('ecx'), 0), argbytes=0)

    c.emu.hook(0x5AF130, getinfo)
    c.emu.hook(0x5AF0D0, getrec)
    c.emu.hook(0x4CC1D0, cnt)
    r.hook(0x5AFBB0, 90, 2, rand=True)
    r.hook(0x5AF5B0, 91, 3, rand=True, writes={0: WEAPONS[0], 1: c.rng.randrange(0, 30)}, quiet_args=(0, 1))
    r.hook(0x5A8510, 92, 2, rand=True)
    r.hook(0x568DC0, 93, 0, rand=True)
    return [self_obj]


S(0x567F70, 'ZFFInventorySelector::FrameUpdate', 'thiscall', None, ret=None, gen=frame, note='batch1313')
