"""specs_s1015.py - unclaimed-07 batch 15 (slice 6): CCheckInsideBox::DoCheck (0x5b8020).
Fake objects per case: this (+0x44 the checked object, +0x50 a holder whose +0x18 is the item list, +0x54 a second holder
for the two original walks 0x5b8270 and 0x5b8200, +0x5c the last count); the list objects (slot +0x4c no-op, slot +0x5c
writes 1 or 0 through its pointer argument, a stack address that is not logged, and returns the next item); the engine at
0x70038c (slot +0xcc maps an item to an r object or 0); r (slot +0x84, r+8 a source object with dwords at +0x30); the
checked object (slot +0x8c, slot +0x180 returns a random bool); and the second walk's objects (slot +0x128 logs its
three arguments). Pointer arguments to the stack are not logged; the walks 0x5b8270 and 0x5b8200 run as original code."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _quiet_vt(c, name, nslots, slots):
    """slots: {offset: (value, nargs)}. The stub logs its ECX and the arguments that are not stack addresses:
    the caller passes a stack pointer when it gets a result back, so nargs for those slots is given as 0 in the log."""
    fns = {}
    for off, (val, nargs, logged) in slots.items():
        # logged: the argument indices to record (stack-pointer arguments are left out)
        def h(em, r, off=off, val=val, nargs=nargs, logged=logged):
            args = tuple(em.arg32(k) for k in logged)
            em.calllog.append((name, off, em.reg('ecx'), args))
            em.ret(eax=val, argbytes=4 * nargs)
        fns[off] = h
    return c.emu.fake_vtable(name, nslots, fns)


def _list(c, items_ref):
    """A list object: slot +0x4c no-op, slot +0x5c returns the next item through eax and writes the flag (1 or 0)."""
    n = len(items_ref)
    state = [0]

    def h5c(em, r):
        flag_ptr = em.arg32(0)
        if state[0] < n:
            item = items_ref[state[0]]
            state[0] += 1
            em.w32(flag_ptr, 1)
        else:
            item = 0
            em.w32(flag_ptr, 0)
        em.ret(eax=item, argbytes=4)

    def h4c(em, r):
        em.ret(eax=0, argbytes=4)

    lst = _rnd(c, 0x40)
    c.emu.w32(lst, c.emu.fake_vtable('list', 0x60 // 4, {0x4c: h4c, 0x5c: h5c}))
    return lst


def _docheck(c):
    e = c.emu
    self_o = _rnd(c, 0x100)
    e.w32(self_o + 0x5c, c.rng.choice([0, 0, 1, c.rng.getrandbits(32)]))
    e.wbytes(self_o + 0x58, bytes(c.rng.getrandbits(8) for _ in range(4)))

    # the checked object at this+0x44 (its slots take a stack pointer, so arguments are not logged)
    obj44 = _rnd(c, 0x40)
    bool_val = c.rng.getrandbits(32)
    e.w32(obj44, _quiet_vt(c, 'checked', 0x188 // 4 + 1,
                           {0x8c: (0, 1, ()), 0x180: (bool_val, 2, (1,))}))
    e.w32(self_o + 0x44, obj44)

    # the first list; each item maps to an r object (80%) or to 0 in the engine
    n = c.rng.randint(0, 3)
    items = [c.rng.getrandbits(32) | 0x10 for _ in range(n)]
    rmap = {}
    for it in items:
        if c.rng.random() < 0.8:
            r = _rnd(c, 0x40)
            e.w32(r + 8, _rnd(c, 0x40))
            e.w32(r, _quiet_vt(c, 'r', 0x88 // 4, {0x84: (0, 1, ())}))
            rmap[it] = r
        else:
            rmap[it] = 0
    holder = _rnd(c, 0x40)
    e.w32(holder + 0x18, _list(c, items))
    e.w32(self_o + 0x50, holder)

    # the second list (this+0x54) for the original walks: items map to objects with slot +0x128 (three logged args)
    n2 = c.rng.randint(0, 2)
    items2 = [c.rng.getrandbits(32) | 0x20 for _ in range(n2)]
    r2map = {}
    for it in items2:
        r2 = _rnd(c, 0x40)
        e.w32(r2, _quiet_vt(c, 'r2', 0x130 // 4, {0x128: (0, 3, (0, 1, 2))}))
        r2map[it] = r2
    holder2 = _rnd(c, 0x40)
    e.w32(holder2 + 0x18, _list(c, items2))
    e.w32(self_o + 0x54, holder2)

    # the engine: slot +0xcc maps an item to an object (r for the first list, r2 for the second), logged
    mapping = dict(rmap)
    mapping.update(r2map)

    def engine_map(em, a):
        em.calllog.append(('engine', 0xcc, em.reg('ecx'), (a[0],)))
        return (mapping.get(a[0], 0), None)

    engine = _rnd(c, 0x40)
    e.w32(engine, e.logging_vtable('engine', 0xd0 // 4, impl={0xcc: engine_map}, argwords={0xcc: 1}))
    e.w32(0x70038c, engine)
    return [self_o]


S(0x5b8020, 'CCheckInsideBox::DoCheck (unknown) thiscall', 'thiscall', None, ret=None, gen=_docheck,
  note='unclaimed-07 batch 15; list walk, engine slot +0xcc, r slot +0x84, obj44 slots +0x8c, +0x180; walks 0x5b8270/0x5b8200')
