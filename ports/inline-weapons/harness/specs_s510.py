"""specs_s510.py - weapons batch 510: item get/put/swap actions and ZLNKWHANDS::AddAction."""
from pilot import S
from wkit import rnd, stub, obj, b, sysobj, patch_jmp, fedge


def _patches(c):
    patch_jmp(c, 0x467410, stub(c, 6, rec_ecx=True))
    patch_jmp(c, 0x461570, stub(c, 3, rec_ecx=True))
    patch_jmp(c, 0x4614d0, stub(c, 3, rec_ecx=True))


def _hand(c, item):
    return obj(c, 0x40, {0x8: stub(c, 2), 0x10: stub(c, 0, ret=item)})


def _item(c):
    r = c.rng
    t = obj(c, 0x40, {0x1e0: stub(c, 1, ret=b(c, 0.5))})
    return obj(c, 0x40, {0x2d0: stub(c, 2), 0x2e8: stub(c, 0, ret=t)})


def _owner(c):
    r = c.rng
    return obj(c, 0x40, {0x228: stub(c, 5, ret=r.getrandbits(32)), 0x230: stub(c, 2, ret=r.getrandbits(32))})


def _logger(c):
    s = obj(c, 0x40, {0x30: stub(c, 2, cdecl=True)})
    l = obj(c, 0x10, {0x20: stub(c, 2, ret=s)})
    c.emu.w32(0x700390, l)


def _env(c):
    r = c.rng
    _patches(c)
    _logger(c)
    sysobj(c, {0x4c: stub(c, 1, ret=r.getrandbits(32)), 0x58: stub(c, 1, ret=r.getrandbits(32))})
    so = c.emu.r32(0x70039c)
    vt = c.emu.alloc(0x200, 4)
    c.emu.w32(vt + 0x1c0, stub(c, 2, fldv=r.choice((0.0, 0.5, 0.999, r.random()))))
    c.emu.w32(so, vt)


def _act(c, layout):
    r = c.rng
    _env(c)
    a = obj(c, 0x40, {0xc: stub(c, 0, ret=r.getrandbits(32))})
    for off, kind in layout:
        if kind == 'item':
            v = _item(c)
        elif kind == 'owner':
            v = _owner(c)
        elif kind == 'hand':
            v = _hand(c, 0 if r.random() < 0.25 else _item(c))
        else:
            v = 0 if r.random() < 0.2 else r.getrandbits(32)
        c.emu.w32(a + off, v)
    return [a]


def _get(c):
    return _act(c, ((8, 'item'), (0xc, 'owner'), (0x10, 'hand'), (0x14, 'anim'), (0x18, 'anim')))


def _put(c):
    a = _act(c, ((8, 'owner'), (0xc, 'hand'), (0x10, 'anim'), (0x14, 'anim')))
    return a


def _putx(c):   # Execute needs an item in the hand
    r = c.rng
    a = _put(c)[0]
    c.emu.w32(a + 0xc, _hand(c, _item(c)))
    return [a]


def _swap(c):
    return _act(c, ((8, 'owner'), (0xc, 'hand'), (0x10, 'hand'), (0x14, 'anim')))


def _setitem(c):
    return [rnd(c, 0x20), c.rng.getrandbits(32)]


def _addaction(c):
    r = c.rng
    sysobj(c, {0x58: stub(c, 1, ret=r.getrandbits(32))})
    act = rnd(c, 0x40)
    self = obj(c, 0x600, {0x3ec: stub(c, 1, ret=act), 0x3d8: stub(c, 1)})
    i = r.choice(list(range(1, 16)) + [0, 16, 0xffffffff])
    if i < 1 or i > 15:
        c.emu.w32(0x7003b0, stub(c, 0))
    return [self, i, r.getrandbits(32)]


S(0x4870b0, 'action SetItem (+8)', 'thiscall', None, ret=None, gen=_setitem)
S(0x486020, 'ZActionGetItem::CallBack', 'thiscall', None, ret='al', gen=_get)
S(0x4864e0, 'ZActionGetItem::Execute', 'thiscall', None, ret='al', gen=_get)
S(0x4861f0, 'ZActionPutItem::CallBack', 'thiscall', None, ret='al', gen=_put)
S(0x486890, 'ZActionPutItem::Execute', 'thiscall', None, ret='al', gen=_putx)
S(0x4862b0, 'ZActionSwapItems::CallBack', 'thiscall', None, ret='al', gen=_swap)
S(0x4869a0, 'ZActionSwapItems::Execute', 'thiscall', None, ret='al', gen=_swap)
S(0x471ff0, 'ZLNKWHANDS::AddAction', 'thiscall', None, ret=None, gen=_addaction)
