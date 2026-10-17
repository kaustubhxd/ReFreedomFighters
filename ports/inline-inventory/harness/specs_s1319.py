"""specs_s1319.py - inventory thread batch 1319 (src/batch1319.cpp): CInventory::RemoveItem (no argument).

The container list (+0x11a, embedded) is stateful: count (0x14), first id (0x30), access check (0x28), removal (0x3c).
Each id resolves to an object through the reference table (0x58, twice). The action list (+0x1c6, embedded) is a
cursor list (0x4c begin, 0x5c next, 0x44 remove). The manager's records answer 0xcc with a record whose +0x106 is an id.
"""
from pilot import S
from inv_helpers import Rec, rnd, set_global

SYS = 0x70039C
LOGGER = 0x700390
MGR = 0x70038C


def _arg(emu, k):
    return emu.r32(emu.reg('esp') + 4 + 4 * k)


def remove(c):
    r = Rec(c)
    sysobj = rnd(c, 0x2000, 4)
    set_global(c, SYS, sysobj)
    ref = rnd(c, 0x1000, 4)
    c.emu.w32(sysobj + 0x9B, ref)

    objs, ids = {}, {}
    nxt = [0x40]

    def id_of(o):
        if o not in ids:
            nxt[0] += 4
            ids[o] = nxt[0]
            objs[nxt[0]] = o
        return ids[o]

    # container list ids and per-id answers
    items = [0x100 + 4 * k for k in range(c.rng.randrange(1, 4))]
    obj_of = {}
    for i in items:
        o = rnd(c, 0x80, 4)
        c.emu.w32(o, r.vtable({0x210: r.stub(126, 1, rand=True)}))
        obj_of[i] = o
        objs[i] = o        # always present and checked: the error branches never remove the entry (the original would loop)
    access = {i: 1 for i in items}
    holder = rnd(c, 0x40, 4)
    hid = c.rng.choice([0, 0x55])
    if hid:
        objs[hid] = holder
    c.emu.w32(holder, r.vtable({0x128: r.stub(120, 3, rand=True)}))

    state = {'items': list(items)}

    def count(emu, res):
        emu.ret(eax=len(state['items']), argbytes=0)

    def first(emu, res):
        emu.ret(eax=state['items'][0] if state['items'] else 0, argbytes=4)

    def check(emu, res):
        i = _arg(emu, 0)
        emu.ret(eax=access.get(i, 0), argbytes=4)

    def remove_entry(emu, res):
        i = _arg(emu, 0)
        if i in state['items']:
            state['items'].remove(i)
        emu.ret(argbytes=4)

    L = rnd(c, 0x40, 4)
    c.emu.w32(L, r.vtable({0x14: count, 0x30: first, 0x28: check, 0x3C: remove_entry}))

    # the action list (embedded at +0x1c6): ids, cursor-based
    acts = [c.rng.choice(items + [0x7000]) for _ in range(c.rng.randrange(0, 4))]
    astate = {'i': 0, 'list': list(acts)}

    def abegin(emu, res):
        cur = _arg(emu, 0)
        astate['i'] = 0
        emu.w32(cur, 1 if astate['list'] else 0)
        emu.ret(argbytes=4)

    def anext(emu, res):
        cur = _arg(emu, 0)
        i = astate['i']
        v = astate['list'][i] if i < len(astate['list']) else 0
        astate['i'] = i + 1
        emu.w32(cur, 1 if i + 1 < len(astate['list']) else 0)
        emu.ret(eax=v, argbytes=4)

    def aremove(emu, res):
        cur = _arg(emu, 0)
        i = astate['i'] - 1
        if 0 <= i < len(astate['list']):
            astate['list'].pop(i)
            astate['i'] = i
        emu.ret(argbytes=4)

    # records from the manager (slot 0xcc by id)
    recs = {}

    def rec_of(emu, res):
        v = _arg(emu, 0)
        if v not in recs:
            rr = rnd(c, 0x140, 4)
            c.emu.w32(rr + 0x106, v if c.rng.random() < 0.5 else 0x7777)
            c.emu.w32(rr, r.vtable({0xAC: r.stub(121, 0, rand=True)}))
            recs[v] = rr
        emu.ret(eax=recs[v], argbytes=4)
    mgr = rnd(c, 0x40, 4)
    c.emu.w32(mgr, r.vtable({0xCC: rec_of}))
    set_global(c, MGR, mgr)

    A = rnd(c, 0x40, 4)
    c.emu.w32(A, r.vtable({0x4C: abegin, 0x5C: anext, 0x44: aremove}))

    # the reference table
    def h58(emu, res):
        emu.ret(eax=objs.get(_arg(emu, 0), 0), argbytes=4)

    def h4c(emu, res):
        emu.ret(eax=id_of(_arg(emu, 0)), argbytes=4)
    c.emu.w32(ref, r.vtable({0x58: h58, 0x4C: h4c}))

    # owner, printers, logger, MYSTR
    owner = rnd(c, 0x80, 4)
    c.emu.w32(owner, r.vtable({0x1D8: r.stub(122, 2, rand=True, quiet_args=(0,))}))
    pr_a = rnd(c, 0x40, 4)
    c.emu.w32(pr_a, r.vtable({0x2C: r.stub(123, 3, pop=False, rand=True, log_ecx=False)}))
    pr_b = rnd(c, 0x40, 4)
    c.emu.w32(pr_b, r.vtable({0x2C: r.stub(124, 4, pop=False, rand=True, log_ecx=False)}))

    def logger(emu, res):
        line = _arg(emu, 1)
        emu.ret(eax=pr_a if line == 0x290 else pr_b, argbytes=8)
    lg = rnd(c, 0x40, 4)
    c.emu.w32(lg, r.vtable({0x20: logger}))
    set_global(c, LOGGER, lg)
    c.emu.hook(0x4CC1D0, lambda emu, res: emu.ret(eax=c.rng.randrange(0, 9), argbytes=0))
    r.hook(0x4CBEC0, 125, 0, rand=True, log_ecx=False)

    self_obj = rnd(c, 0x800, 4)
    c.emu.w32(self_obj + 0x44, owner)
    c.emu.w32(self_obj + 0x6A, hid)
    c.emu.w16(self_obj + 0x4A, c.rng.getrandbits(16))
    c.emu.w32(self_obj + 0x11A, c.emu.r32(L))     # embedded lists: their vtable pointers sit at the member offsets
    c.emu.w32(self_obj + 0x1C6, c.emu.r32(A))
    return [self_obj]


S(0x4AD4D0, 'CInventory::RemoveItem', 'thiscall', None, ret=None, gen=remove, note='batch1319')
