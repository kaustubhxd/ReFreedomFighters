"""specs_s1318.py - inventory thread batch 1318 (src/batch1318.cpp): CInventory::AddItem.

Objects answer by identity (the `this` in ecx): IsA from a per-object class set, the template (slot 0x2e8) from a
per-object table, ids from the reference table dictionaries. Message ids come from a fixed map. The logger's printers
are cdecl (their stubs do not pop), one for each argument count the original uses (3 and 4). The MYSTR temporaries
from slot 0x1d8 are objects whose count (ext 0x4cc1d0) is taken from a per-object table.
"""
from pilot import S
from inv_helpers import Rec, rnd, set_global

SYS = 0x70039C
LOGGER = 0x700390
TEMPLATE_NAMES = ['KevlarVest', 'Beretta', 'Frag', 'Spas12']
OWNER_CLASS = 0x80200014


def _arg(emu, k):
    return emu.r32(emu.reg('esp') + 4 + 4 * k)


def _stricmp(emu, res):
    def rs(a):
        out = b''
        while True:
            x = emu.rbytes(a, 1)
            if x == b'\0' or len(out) > 200:
                return out
            out += x
            a += 1
    a, b = rs(_arg(emu, 0)), rs(_arg(emu, 1))
    emu.ret(eax=0 if a.lower() == b.lower() else 1, argbytes=0)


def add(c):
    r = Rec(c)
    set_global(c, 0x676414, c.emu.stub_fn('_stricmp', _stricmp))

    # ---- the reference table: ids for objects, objects for ids
    objs, ids = {}, {}
    nxt = [0x40]

    def id_of(o):
        if o not in ids:
            nxt[0] += 4
            ids[o] = nxt[0]
            objs[nxt[0]] = o
        return ids[o]

    msgs = {0x690c00: 0x2A1, 0x690c14: 0x2A2}
    armour_id = 0x2A2

    # ---- class sets and tables per object (filled below)
    cls = {}        # object -> set of class ids answered by slot 0x1e0
    tmpl_of = {}    # object -> template object (slot 0x2e8)
    count_of = {}   # MYSTR object -> count (ext 0x4cc1d0)
    mm_obj_holder = {}

    def isa(emu, res):
        this = emu.reg('ecx')
        emu.ret(eax=1 if _arg(emu, 0) in cls.get(this, set()) else 0, argbytes=4)

    def tmpl(emu, res):
        emu.ret(eax=tmpl_of.get(emu.reg('ecx'), 0), argbytes=0)

    def mystr(emu, res):
        # a MYSTR filled by slot 0x1d8(out, flag): returns the object (count by object)
        o = c.emu.alloc(0x20, 4)
        count_of[o] = c.rng.randrange(0, 9)
        emu.ret(eax=o, argbytes=8)

    # the owner/item/template/new-item objects share one vtable factory
    def mkobj(classes, template=0, extra=None):
        o = rnd(c, 0x80, 4)
        slots = {
            0x1E0: isa,
            0x2E8: tmpl,
            0x1D8: mystr,
            0x20: r.stub(90, 1, rets=[c.rng.randrange(0, 50)]),
            0x210: r.stub(91, 1, rand=True),
            0x2D0: r.stub(92, 2, rand=True),
            0x2F0: r.stub(93, 2, rand=True),
            0x31C: r.stub(94, 0, rand=True),
            0x320: r.stub(95, 0, rand=True),
            0x324: r.stub(96, 1, rand=True),
            0x328: r.stub(97, 1, rand=True),
            0x128: r.stub(98, 3, rand=True),
            0x2C4: r.stub(99, 2, rets=[0]),
            0xBC: r.stub(100, 1, rand=True),
        }
        if 0x1007D8 in classes:
            slots[0x2E8] = r.stub(107, 1, rets=[template or 0])   # ammo-type objects take one argument in slot 0x2e8
        if extra:
            slots.update(extra)
        c.emu.w32(o, r.vtable(slots))
        cls[o] = set(classes)
        if template:
            tmpl_of[o] = template
        return o

    # ---- the id lookups (ref slot 0x58 by id, 0x4c by object)
    def h58(emu, res):
        emu.ret(eax=objs.get(_arg(emu, 0), 0), argbytes=4)

    def h4c(emu, res):
        emu.ret(eax=id_of(_arg(emu, 0)), argbytes=4)

    def h114(emu, res):
        emu.ret(eax=msgs.get(_arg(emu, 0), 0x3F), argbytes=16)

    mmobj = rnd(c, 0x40, 4)

    def m88(emu, res):
        name = _arg(emu, 0)
        out = _arg(emu, 1)
        emu.w32(out, armour_id if name == 0x690c14 else 0)
        emu.ret(argbytes=8)
    c.emu.w32(mmobj, r.vtable({0x88: m88}))

    ref = rnd(c, 0x1000, 4)
    c.emu.w32(ref, r.vtable({
        0x58: h58, 0x4C: h4c, 0x114: h114,
        0x138: lambda emu, res: emu.ret(eax=mmobj, argbytes=0),
    }))
    c.emu.w32(ref + 0xADC, c.rng.getrandbits(32))
    sysobj = rnd(c, 0x2000, 4)
    set_global(c, SYS, sysobj)
    c.emu.w32(sysobj + 0x9B, ref)

    # ---- printers (cdecl: the stub does not pop) and the logger
    pr3 = rnd(c, 0x40, 4)
    c.emu.w32(pr3, r.vtable({0x2C: r.stub(101, 3, pop=False, rand=True, log_ecx=False)}))
    pr4 = rnd(c, 0x40, 4)
    c.emu.w32(pr4, r.vtable({0x2C: r.stub(102, 4, pop=False, rand=True, log_ecx=False)}))

    def logger(emu, res):
        line = _arg(emu, 1)
        emu.ret(eax=pr3 if line == 0x243 else pr4, argbytes=8)
    lg = rnd(c, 0x40, 4)
    c.emu.w32(lg, r.vtable({0x20: logger}))
    set_global(c, LOGGER, lg)

    # ---- the container list at +0x11a (slot 4 adds the id)
    lst = rnd(c, 0x40, 4)
    c.emu.w32(lst, r.vtable({0x4: r.stub(103, 1, rand=True)}))

    # ---- the cases: owner, items, templates
    owner_cls = {OWNER_CLASS} if c.rng.random() < 0.5 else set()
    owner = mkobj(owner_cls, extra={0x98: r.stub(104, 1, rets=[c.rng.getrandbits(32)])})

    new_item = mkobj({c.rng.choice([0x1007D1, 0x1007D8, 0x1007D2, 0x1007D5])})
    if c.rng.random() < 0.15:
        new_item = 0

    def named_template(classes):
        t = mkobj(classes, extra={0x2C4: r.stub(99, 2, rets=[new_item])})
        c.emu.w32(t + 4, c.emu.cstr(c.rng.choice(TEMPLATE_NAMES)))
        return t

    kind = c.rng.choice(['tmpl', 'item', 'item', 'plain', 'ammo'])
    if kind == 'tmpl':
        ob = named_template({0x1007D3, 0x1007D4} if c.rng.random() < 0.6 else {0x1007D3})
    elif kind == 'ammo':
        # an ammo-type object (not an item): its own slot 0x2e8 takes one stack argument (the caller pushes 0)
        t_ammo = named_template({0x1007D3})
        ob = mkobj({0x1007D8}, extra={0x2E8: r.stub(107, 1, rets=[t_ammo])})
    elif kind == 'item':
        t_item = named_template({0x1007D3})
        ob = mkobj({0x1007D1}, template=t_item)
    else:
        ob = mkobj(set())

    lookup_id = id_of(ob)
    new_id = id_of(new_item) if new_item else 0

    self_obj = rnd(c, 0x800, 4)
    c.emu.w32(self_obj + 0x44, owner)
    c.emu.w32(self_obj + 0x6A, c.rng.choice([0, 0, 0x55]))
    c.emu.w32(self_obj + 0x48, c.rng.getrandbits(16))
    c.emu.w32(self_obj + 0x11A, r.vtable({0x4: r.stub(103, 1, rand=True)}))   # embedded list: its vtable pointer sits at +0x11a
    c.emu.w32(self_obj, r.vtable({0x98: r.stub(106, 1, rets=[c.rng.choice([0, new_id, lookup_id])])}))
    # the holder object for +0x6a (a plain object with slot 0x128)
    if c.emu.r32(self_obj + 0x6A):
        holder = mkobj(set())
        objs[c.emu.r32(self_obj + 0x6A)] = holder

    # counts for MYSTR objects are per object, answered by ext 0x4cc1d0 (count of its argument's object)
    def cnt(emu, res):
        emu.ret(eax=count_of.get(emu.reg('ecx'), 3), argbytes=0)
    c.emu.hook(0x4CC1D0, cnt)
    r.hook(0x4CBEC0, 110, 0, rand=True, log_ecx=False)

    return [self_obj, lookup_id]


S(0x4ACF30, 'CInventory::AddItem', 'thiscall', None, ret='eax', gen=add, note='batch1318')
