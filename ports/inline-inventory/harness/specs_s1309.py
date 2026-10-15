"""specs_s1309.py - inventory thread batch 1309 (src/batch1309.cpp): CInventory give-item family.

Fake objects per case (rebuilt identically for the original and the port, from the same rng seed):
  * a message map (ref table slot 0x138 -> m; m slot 0x88(name, &id)) and a ref table (slot 0x58 id->obj,
    slot 0x4c obj->id);
  * the inventory's item REFTAB at +0x11a: begin (slot 0x4c) and next (slot 0x5c) over a list of item ids;
  * item objects: slot 0x1e0 = IsA (their class), slot 0x2e8 = template, slot 0x324 = set ammo (logged);
  * template objects with a class-desc chain (+0xc -> desc, desc +0x23 = type, desc +0xc = parent), name at +4 and
    slot 0x340 = container key;
  * group geoms: +0x50 first child, child +0x54 template (or 0), +0x60 next.
ZBaseGeom::IsDerivedFrom (0x4db9a0) is real exe code: it walks the desc chains built here.
"""
import struct
from pilot import S
from inv_helpers import Rec, rnd, set_global

SYS = 0x70039c
NAMES = {0x690ad0: 'ItemsGroup', 0x690adc: 'WeaponsGroup'}


class Env:
    def __init__(self):
        self.objs = {}     # id -> object
        self.ids = {}      # object -> id
        self.names = {}    # name pointer -> id
        self.next_id = 0x40


def _id_of(env, o):
    if o not in env.ids:
        env.next_id += 4
        env.ids[o] = env.next_id
        env.objs[env.next_id] = o
    return env.ids[o]


def _arg(emu, k):
    return emu.r32(emu.reg('esp') + 4 + 4 * k)


def _desc_chain(c, types):
    """Class-desc chain, leaf first: each desc = +0x23 type, +0xc parent desc."""
    nxt = 0
    for t in reversed(types):
        d = rnd(c, 0x30, 4)
        c.emu.w32(d + 0x23, t)
        c.emu.w32(d + 0xc, nxt)
        nxt = d
    return nxt


def _template(c, r, env, desc, key):
    t = rnd(c, 0x80, 4)
    nm = c.rng.choice([0, 'Beretta', 'Spas12', 'AK', 'Frag', 'C4', 'Molotov'])
    c.emu.w32(t + 4, 0 if nm == 0 else c.emu.cstr(nm))
    c.emu.w32(t + 0xc, desc)
    c.emu.w32(t, r.vtable({0x340: r.stub(40, 1, rets=[key], pop=True)}))
    return t


def _item(c, r, env, cls, tmpl):
    it = rnd(c, 0x40, 4)
    def isa(emu, res, cls=cls):
        emu.ret(eax=1 if _arg(emu, 0) == cls else 0, argbytes=4)
    def tmpl_of(emu, res, tmpl=tmpl):
        emu.ret(eax=tmpl, argbytes=0)
    c.emu.w32(it, r.vtable({0x1e0: isa, 0x2e8: tmpl_of, 0x324: r.stub(60, 1, rand=True)}))
    _id_of(env, it)
    return it


def _tab(c, r, env, vals):
    """REFTAB with a value list: begin writes cursor[0] = non-empty, next returns the next value."""
    state = {'i': 0}

    def begin(emu, res):
        cur = _arg(emu, 0)
        state['i'] = 0
        emu.w32(cur, 1 if vals else 0)
        emu.ret(argbytes=4)

    def nxt(emu, res):
        cur = _arg(emu, 0)
        i = state['i']
        v = vals[i] if i < len(vals) else 0
        state['i'] = i + 1
        emu.w32(cur, 1 if i + 1 < len(vals) else 0)
        emu.ret(eax=v, argbytes=4)
    return r.vtable({0x4c: begin, 0x5c: nxt})   # embedded in the inventory: its vtable pointer sits at +0x11a


def _env(c, r):
    env = Env()
    m = r.obj(0x40, {0x88: None})
    def m88(emu, res, env=env):
        name = _arg(emu, 0)
        out = _arg(emu, 1)
        emu.w32(out, env.names.get(name, 0))
        emu.ret(argbytes=8)
    c.emu.w32(m, r.vtable({0x88: m88}))
    refobj = r.obj(0x40, {})

    def h138(emu, res, m=m):
        emu.ret(eax=m, argbytes=0)

    def h58(emu, res, env=env):
        emu.ret(eax=env.objs.get(_arg(emu, 0), 0), argbytes=4)

    def h4c(emu, res, env=env):
        emu.ret(eax=_id_of(env, _arg(emu, 0)), argbytes=4)
    c.emu.w32(refobj, r.vtable({0x138: h138, 0x58: h58, 0x4c: h4c}))
    return env, refobj


def _sys_obj(c, r, env, refobj, flag):
    sysobj = rnd(c, 0x2000, 4)
    set_global(c, SYS, sysobj)
    c.emu.w32(sysobj + 0x9b, refobj)
    c.emu.w8(sysobj + 0x9b7, flag)
    c.emu.w32(sysobj, r.vtable({0x14: r.stub(70, 0, rand=True), 0x10: r.stub(71, 0, rand=True)}))
    return sysobj


def _rstr(emu, a):
    out = b''
    while True:
        b = emu.rbytes(a, 1)
        if b == b'\0' or len(out) > 256:
            return out
        out += b
        a += 1


def _stricmp_handler(emu, res):
    """_stricmp(a, b) (cdecl, the IAT import): 0 when equal ignoring ASCII case, else nonzero."""
    a, b = _rstr(emu, _arg(emu, 0)), _rstr(emu, _arg(emu, 1))
    eq = a.lower() == b.lower()
    emu.ret(eax=0 if eq else 1, argbytes=0)


def _inventory(c, r, env, n_items):
    """The inventory (this): vtable with 0x88 / 0x8c stubs and the item REFTAB at +0x11a."""
    inv = rnd(c, 0x200, 4)
    c.emu.w32(inv, r.vtable({0x88: r.stub(80, 2, rand=True), 0x8c: r.stub(81, 1, rand=True)}))
    items = []
    for _ in range(n_items):
        cls = c.rng.choice([0x1007d1, 0x1007d8, 0x1007d8])
        tmpl = rnd(c, 0x80, 4)
        items.append(_item(c, r, env, cls, tmpl))
    c.emu.w32(inv + 0x11a, _tab(c, r, env, [_id_of(env, it) for it in items]))
    return inv


def _children(c, r, env, group_kind_for):
    """A group with a chain of children (+0x50 first, +0x60 next), each with its template chain."""
    grp = rnd(c, 0x80, 4)
    n = c.rng.randrange(0, 5)
    prev = 0
    first = 0
    for _ in range(n):
        kind = group_kind_for(c)
        g = rnd(c, 0x80, 4)
        if kind == 'none':
            c.emu.w32(g + 0x54, 0)
        else:
            types = {'tmpl': [0x1007d3], 'cont': [0x1007d4, 0x1007d3], 'nested': [0x100001],
                     'weird': [0x1007d1]}[kind]
            key = rnd(c, 0x80, 4)
            desc = _desc_chain(c, types)
            t = _template(c, r, env, desc, key)
            c.emu.w32(g + 0x54, t)
        c.emu.w32(g + 0x60, 0)
        if prev:
            c.emu.w32(prev + 0x60, g)
        else:
            first = g
        prev = g
    c.emu.w32(grp + 0x50, first)
    return grp


def _kind(c):
    return c.rng.choice(['tmpl', 'tmpl', 'cont', 'cont', 'nested', 'weird', 'none'])


def give_in_group(c):
    r = Rec(c)
    set_global(c, 0x676414, c.emu.stub_fn('_stricmp', _stricmp_handler))
    env, refobj = _env(c, r)
    _sys_obj(c, r, env, refobj, c.rng.choice([0, 1]))
    inv = _inventory(c, r, env, c.rng.randrange(0, 4))
    grp = _children(c, r, env, _kind)
    # names: the name argument is a C string; match it to a template name sometimes
    nm = c.rng.choice(['Beretta', 'Spas12', 'Frag', 'nothing'])
    name = c.emu.cstr(nm)
    r.hook(0x4acf30, 90, 1, rand=True)
    return [inv, grp, name]


def give_all(c):
    r = Rec(c)
    set_global(c, 0x676414, c.emu.stub_fn('_stricmp', _stricmp_handler))
    env, refobj = _env(c, r)
    _sys_obj(c, r, env, refobj, c.rng.choice([0, 1]))
    if c.rng.random() < 0.6:
        env.names[0x690ad0] = _id_of(env, r.obj(0x40, {0x8c: r.stub(82, 1, rand=True)}))
        env.names[0x690adc] = _id_of(env, r.obj(0x40, {0x8c: r.stub(83, 1, rand=True)}))
    else:
        env.names[0x690ad0] = c.rng.choice([0, _id_of(env, rnd(c, 0x40, 4))])
    inv = _inventory(c, r, env, c.rng.randrange(0, 5))
    r.hook(0x4acf30, 90, 1, rand=True)
    return [inv]


def give_all_in_group(c):
    r = Rec(c)
    set_global(c, 0x676414, c.emu.stub_fn('_stricmp', _stricmp_handler))
    env, refobj = _env(c, r)
    _sys_obj(c, r, env, refobj, 0)
    inv = _inventory(c, r, env, c.rng.randrange(0, 4))
    grp = _children(c, r, env, _kind)
    r.hook(0x4acf30, 90, 1, rand=True)
    return [inv, grp]


S(0x4abf90, 'CInventory::GiveItemInGroup', 'thiscall', None, ret='al', gen=give_in_group, note='batch1309')
S(0x4ac310, 'CInventory::GiveAllItems', 'thiscall', None, ret=None, gen=give_all, note='batch1309')
S(0x4ac120, 'CInventory::GiveAllItemsInGroup', 'thiscall', None, ret=None, gen=give_all_in_group, note='batch1309')
