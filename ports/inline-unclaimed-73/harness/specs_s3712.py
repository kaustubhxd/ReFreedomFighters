"""specs_s3712.py - area 73 batch 12 (residue 12): CAction::End (0x4a0440). The fake world per case:
- the render control ctl (g_sys+0x9b): slot +0x138 gives x; x slot +0x88 writes the action (or 0) through its stack out pointer;
  ctl slot +0x4c (logged) and holder at ctl+0xadc (slot +0x25c gives esi or 0).
- the controller 0x70038c: slot +0xcc maps the action to y (or 0), logged.
- self (the action): flag byte +0x5e, lists at +0x6a/+0x6e and +0x7e/+0x82, owner list at +0x102 (0 or a list with self in it),
  +0x44 -> s44 (slot +0x12c, logged) -> +0x10 -> obj10 -> +8 -> q (slot +0x4c writes a flag, slot +0x5c writes a flag and returns
  an item; both through stack pointers), +0x7a, +0x76 (tail values), +0x65 byte.
- items: slot +0x14 returns a string pointer (the constant 0x67a110 about half the time).
- esi (from holder slot +0x25c): slot +0x224 (logged), +0x18 -> sub with slot +0x28 (returns 0 or 1).
- sys object: slot +0xfc (logged, the tail).
Helpers 0x4a1630, 0x49f8a0 and 0x4dc630 are hooked; the logger 0x700390 writes 0x4cb messages through slot +0x20/+0x2c."""
from pilot import S

STR_EQ = 0x67a110


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _const(v):
    return lambda em, a: (v, None)


def _end(c):
    e = c.emu
    self_o = _rnd(c, 0x200)
    act = _rnd(c, 0x200)
    e.wbytes(act + 0x5e, bytes([0]))
    # the action found by slot +0x88
    have_act = c.rng.random() < 0.85
    # items and their objects (slot +0x14 gives a string)
    n_items = c.rng.randint(0, 2)
    item_objs = []
    for _ in range(n_items):
        r = _rnd(c, 0x140)
        pick = c.rng.random()
        if pick < 0.5:
            s = STR_EQ
        elif pick < 0.75:
            s = 0
        else:
            tmp = _rnd(c, 0x20)
            e.wbytes(tmp, b'xy\x00')
            s = tmp
        e.w32(r, e.logging_vtable('item14', 0x18 // 4 + 1, impl={0x14: _const(s)}, argwords={0x14: 0}))
        item_objs.append(r)
    item_map = {}
    for r in item_objs:
        item_map[r] = r
    # items the walk visits (through q)
    visit = list(item_objs)
    # owner list at +0x102
    if c.rng.random() < 0.5:
        lst = _rnd(c, 0x40)
        members = [self_o] + visit[:1]
        e.w32(lst, len(members))
        for i, m in enumerate(members):
            e.w32(lst + 4 + 4 * i, m)
        e.w32(self_o + 0x102, lst)
    else:
        e.w32(self_o + 0x102, 0)

    # self flags and lists
    e.wbytes(self_o + 0x5e, bytes([1 if c.rng.random() < 0.7 else 0]))
    e.wbytes(self_o + 0x65, bytes([1 if c.rng.random() < 0.4 else 0]))
    e.w32(self_o + 0x6a, c.rng.randint(0, 2))
    e.w32(self_o + 0x7e, c.rng.randint(0, 2) if c.rng.random() < 0.6 else 0)
    for i in range(2):
        e.w32(self_o + 0x6e + 4 * i, c.rng.getrandbits(32))
        e.w32(self_o + 0x82 + 4 * i, c.rng.getrandbits(32))
    e.w32(self_o + 0x7a, c.rng.getrandbits(32) if c.rng.random() < 0.5 else 0)
    e.w32(self_o + 0x76, c.rng.getrandbits(32) if c.rng.random() < 0.5 else 0)
    e.w16 = None
    e.wbytes(0x7002c4, bytes([c.rng.getrandbits(8), c.rng.getrandbits(8)]))
    # the action pointer at self+0x82 must be an object (its +0x5e is written)
    e.w32(self_o + 0x82, act)

    # self+0x44 -> s44 -> +0x10 -> obj10 -> +8 -> q (list walker)
    flag_q = [c.rng.choice([0, 1]) for _ in range(len(visit) + 2)]

    def qwrite(name):
        def h(em, r):
            p = em.arg32(0)
            em.calllog.append(('q', name, em.reg('ecx'), ()))
            em.wbytes(p, bytes([0]))   # placeholder, replaced below
            em.ret(eax=0, argbytes=4)
        return h

    seq_flag = [1] * len(visit) + [0]
    idx = [0]

    def q4c(em, r):
        p = em.arg32(0)
        em.calllog.append(('q4c', 0x4c, em.reg('ecx'), ()))
        em.w32(p, 1 if visit else 0)
        em.ret(eax=0, argbytes=4)

    def q5c(em, r):
        p = em.arg32(0)
        em.calllog.append(('q5c', 0x5c, em.reg('ecx'), ()))
        k = idx[0]
        idx[0] += 1
        if k < len(visit):
            em.w32(p, 1)
            item = visit[k]
        else:
            em.w32(p, 0)
            item = 0
        em.ret(eax=item, argbytes=4)

    q = _rnd(c, 0x40)
    e.w32(q, e.fake_vtable('q_chain', 0x60 // 4, {0x4c: q4c, 0x5c: q5c}))
    obj10 = _rnd(c, 0x40)
    e.w32(obj10 + 8, q)
    s44 = _rnd(c, 0x100)
    e.w32(s44 + 0x10, obj10)
    e.w32(s44, e.logging_vtable('s44', 0x130 // 4 + 1, impl={0x12c: _const(0)}, argwords={0x12c: 3}))
    e.w32(self_o + 0x44, s44)

    # the controller: slot +0xcc maps the action to y (a logged object), 0 otherwise
    y = _rnd(c, 0x40)
    have_y = c.rng.random() < 0.7

    def h_cc(em, a):
        em.calllog.append(('ctrl_cc', 0xcc, em.reg('ecx'), (a[0],)))
        return ((y if have_y else 0), None)

    ctrl = _rnd(c, 0x40)
    e.w32(ctrl, e.logging_vtable('controller', 0xd0 // 4, impl={0xcc: h_cc}, argwords={0xcc: 1}))
    e.w32(0x70038c, ctrl)

    # x: slot +0x88 writes the action (or 0) through its stack out pointer
    def x88(em, a):
        out = em.arg32(1)
        em.calllog.append(('x88', 0x88, em.reg('ecx'), (em.arg32(0),)))
        em.w32(out, act if have_act else 0)
        em.ret(eax=0, argbytes=8)

    x = _rnd(c, 0x40)
    e.w32(x, e.fake_vtable('x88obj', 0x90 // 4, {0x88: x88}))

    # esi (holder result) and its sub-object
    sub = _rnd(c, 0x40)
    sub_ret = c.rng.choice([0, 1])
    e.w32(sub, e.logging_vtable('esi_sub', 0x30 // 4 + 1, impl={0x28: _const(sub_ret)}, argwords={0x28: 1}))
    esi = _rnd(c, 0x40)
    e.w32(esi, e.logging_vtable('esi', 0x228 // 4 + 1, impl={0x224: _const(0)}, argwords={0x224: 1}))
    e.w32(esi + 0x18, sub)
    esi_present = c.rng.random() < 0.7

    holder = _rnd(c, 0x40)
    e.w32(holder, e.logging_vtable('holder', 0x260 // 4, impl={0x25c: _const(esi if esi_present else 0)},
                                   argwords={0x25c: 2}))
    ctl = _rnd(c, 0x200)
    e.w32(ctl + 0xadc, holder)
    e.w32(ctl, e.logging_vtable('ctl', 0x140 // 4,
                                impl={0x138: lambda em, a: (x, None), 0x4c: _const(c.rng.getrandbits(32))},
                                argwords={0x138: 0, 0x4c: 1}))
    if c.rng.random() < 0.1:
        e.w32(ctl + 0xadc, 0)
    sysobj = _rnd(c, 0x200)
    e.w32(sysobj + 0x9b, ctl)
    e.w32(sysobj, e.logging_vtable('sys', 0x100 // 4, impl={0xfc: _const(0)}, argwords={0xfc: 1}))
    e.w32(0x70039c, sysobj)

    # helpers
    def h4a1630(em, r):
        em.calllog.append(('4a1630', 0, em.reg('ecx'), (em.arg32(0),)))
        em.ret(argbytes=4)

    def h49f8a0(em, r):
        em.calllog.append(('49f8a0', 0, em.reg('ecx'), (em.arg32(0),)))
        em.ret(argbytes=4)

    def h4dc630(em, r):
        em.calllog.append(('4dc630', 0, em.reg('ecx'), (em.arg32(0), em.arg32(1))))
        em.ret(argbytes=8)

    e.hook(0x4a1630, h4a1630)
    e.hook(0x49f8a0, h49f8a0)
    e.hook(0x4dc630, h4dc630)

    # the logger for the 0x4cb message
    stream = _rnd(c, 16)
    e.w32(stream, e.fake_vtable('log', 16, {0x2c: lambda em, r: (em.calllog.append(('log.printf', 0x2c, None, (em.arg32(0), em.arg32(1)))), em.ret(eax=0, argbytes=0))}))
    lg = _rnd(c, 16)
    e.w32(lg, e.logging_vtable('logger', 16, impl={0x20: lambda em, a: (stream, None)}, argwords={0x20: 2}))
    e.w32(0x700390, lg)
    return [self_o]


S(0x4a0440, 'CAction::End (unknown) thiscall', 'thiscall', None, ret=None, gen=_end,
  note='area 73 batch 12; x88 action, ctrl 0xcc, owner list at +0x102, q chain 0x4c/0x5c, s44 0x12c, holder 0x25c, sub 0x28, tail 0xfc')
