"""specs_s3611.py - area 73 batch 11 (residue 12): ZFFSearchLightGroup::Init (0x5c6f40). Objects per case: this (+0x44 an object
whose +0x18 is the item list, +0x60 an object with a logging slot +4, +0x71 a float); the list (slot +0x4c no-op, slot +0x5c writes
1 or 0 through its pointer and returns the next item, 0..3 items); the sys object at 0x70039c with +0x9b the render control (slot
+0x58 maps an item to an item object, +0x138 returns the 'esi' object, +0x4c logged, +0xadc a holder with slot +0x25c); each item
object has slots +0x248 and +0x240 returning floats in ST0 (logged); the 'esi' object has a logging slot +0x60 (three args). The
allocator 0x41e290 is hooked (fresh pattern buffer), 0x4ccbe0 (ctor, logged, returns a dword), 0x5c7570 (logged)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _const(v):
    return lambda em, a: (v, None)


def _searchlight(c):
    e = c.emu
    self_o = _rnd(c, 0x200)
    e.w32(self_o + 0x71, 0)
    e.wbytes(self_o + 0x71, bytes([c.rng.getrandbits(8) for _ in range(4)]))
    pattern = bytes(c.rng.getrandbits(8) | 1 for _ in range(0x100))

    def new(em, r):
        n = em.arg32(0)
        em.calllog.append(('new', 0, None, (n,)))
        p = em.alloc(n + 16, 4)
        em.wbytes(p, pattern[:n + 16])
        em.ret(eax=p)

    e.hook(0x41e290, new)

    def ctor(em, r):
        em.calllog.append(('4ccbe0', 0, em.reg('ecx'), (em.arg32(0), em.arg32(1))))
        em.ret(eax=ctor_ret, argbytes=8)

    ctor_ret = c.rng.getrandbits(32)
    e.hook(0x4ccbe0, ctor)

    def ext5c7570(em, r):
        em.calllog.append(('5c7570', 0, em.reg('ecx'), (em.arg32(0),)))
        em.ret(argbytes=4)

    e.hook(0x5c7570, ext5c7570)

    # the 'this+0x60' object: slot +4 logged (one argument)
    o60 = _rnd(c, 0x40)
    e.w32(o60, e.logging_vtable('slg60', 0x10 // 4 + 1, impl={4: _const(0)}, argwords={4: 1}))
    e.w32(self_o + 0x60, o60)

    # items: each has slots +0x248 and +0x240 returning floats
    n_items = c.rng.randint(0, 3)
    items = []
    for _ in range(n_items):
        a = _rnd(c, 0x40)
        f248 = c.rng.uniform(-50.0, 50.0)
        f240 = c.rng.uniform(-50.0, 50.0)

        def h248(em, r, f=f248):
            em.calllog.append(('item248', 0, em.reg('ecx'), ()))
            em.ret(st0=f, argbytes=0)

        def h240(em, r, f=f240):
            em.calllog.append(('item240', 0, em.reg('ecx'), ()))
            em.ret(st0=f, argbytes=0)

        e.w32(a, e.fake_vtable('slg_item', 0x250 // 4, {0x248: h248, 0x240: h240}))
        items.append(a)

    # the list at this+0x44 +0x18: slot +0x4c no-op, slot +0x5c writes the flag and returns the next item
    state = [0]

    def h5c(em, r):
        flag_ptr = em.arg32(0)
        if state[0] < len(items):
            item = items[state[0]]
            state[0] += 1
            em.w32(flag_ptr, 1)
        else:
            item = 0
            em.w32(flag_ptr, 0)
        em.ret(eax=item, argbytes=4)

    def h4c(em, r):
        em.ret(eax=0, argbytes=4)

    lst = _rnd(c, 0x40)
    e.w32(lst, e.fake_vtable('slg_list', 0x60 // 4, {0x4c: h4c, 0x5c: h5c}))
    obj44 = _rnd(c, 0x40)
    e.w32(obj44 + 0x18, lst)
    e.w32(self_o + 0x44, obj44)

    # the render control at g_sys+0x9b
    item_map = {it: it for it in items}

    def h58(em, a):
        em.calllog.append(('ctl58', 0x58, em.reg('ecx'), (a[0],)))
        return (item_map.get(a[0], 0), None)

    esi_obj = _rnd(c, 0x40)
    e.w32(esi_obj, e.logging_vtable('slg_esi', 0x64 // 4, impl={0x60: _const(0)}, argwords={0x60: 3}))
    ctl = _rnd(c, 0x200)
    holder = _rnd(c, 0x40)
    e.w32(holder, e.logging_vtable('slg_holder', 0x260 // 4, impl={0x25c: _const(c.rng.getrandbits(32))},
                                   argwords={0x25c: 2}))
    e.w32(ctl + 0xadc, holder)
    e.w32(ctl, e.logging_vtable('slg_ctl', 0x140 // 4,
                                impl={0x58: h58, 0x138: lambda em, a: (esi_obj, None), 0x4c: _const(0)},
                                argwords={0x58: 1, 0x138: 0, 0x4c: 1}))
    sys = _rnd(c, 0x200)
    e.w32(sys + 0x9b, ctl)
    e.w32(0x70039c, sys)
    return [self_o]


S(0x5c6f40, 'ZFFSearchLightGroup::Init (unknown) thiscall', 'thiscall', None, ret=None, gen=_searchlight,
  note='area 73 batch 11; list at +0x44+0x18; per item floats +0x248/+0x240; ctor 0x4ccbe0 x4; 0x5c7570; tail slots')
