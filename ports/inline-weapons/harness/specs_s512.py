"""specs_s512.py - weapons batch 512: reload and chamber actions."""
from pilot import S
from pe_emu import F
from wkit import rnd, stub, obj, b, sysobj, fedge


def _logger(c, slot):
    s = obj(c, 0x40, {slot: stub(c, 3, cdecl=True)})
    l = obj(c, 0x10, {0x20: stub(c, 2, ret=s)})
    c.emu.w32(0x700390, l)


def _anim(c):
    r = c.rng
    an = rnd(c, 0x80)
    a0 = r.randint(0, 100)
    c.emu.w32(an + 0x60, a0)
    c.emu.w32(an + 0x64, a0 + r.choice((0, 10, 25, 40)))
    c.emu.w32(an + 0x5c, r.randint(0, 50))
    c.emu.w32(an + 0x6c, r.choice((1, 25, 30)))
    return an


def _env(c):
    r = c.rng
    sysobj(c, {0x114: stub(c, 6, ret=r.getrandbits(32))})
    so = c.emu.r32(0x70039c)
    now = r.randint(0, 1 << 20)
    c.emu.w32(so + 0x40, now)
    c.emu.wf32(so + 0x48, r.choice((0.033, 0.016, 0.1)))
    return now


def _weapon(c):
    r = c.rng
    t = obj(c, 0x40, {0x330: stub(c, 0, ret=r.choice(list(range(14)) + [99]))})
    c.emu.w32(t + 4, 0 if r.random() < 0.3 else c.emu.alloc(8, 4))
    cur = r.choice((0, 3, 8, 30))
    return obj(c, 0x100, {0x350: stub(c, 0, ret=t), 0x2d0: stub(c, 2), 0x364: stub(c, 0, ret=r.choice((8, 30, cur))),
                          0x35c: stub(c, 0, ret=cur), 0x360: stub(c, 1), 0x358: stub(c, 1)})


def _action(c, w=None):
    r = c.rng
    now = _env(c)
    if w is None:
        w = 0 if r.random() < 0.1 else _weapon(c)
    hand = obj(c, 0x40, {0x10: stub(c, 0, ret=w)})
    owner = obj(c, 0x600, {0x560: stub(c, 1, ret=r.choice((0, 5, 999, r.getrandbits(32)))), 0x564: stub(c, 2),
                           0x128: stub(c, 1), 0x244: stub(c, 5), 0x458: stub(c, 1),
                           0x470: stub(c, 1, ret=b(c, 0.3)), 0x474: stub(c, 1, ret=b(c, 0.3))})
    a = obj(c, 0x80, {0x24: stub(c, 1, ret=r.getrandbits(32))})
    c.emu.w32(a + 8, owner)
    c.emu.w32(a + 0xc, hand)
    for off in range(0x10, 0x2c, 4):
        c.emu.w32(a + off, 0 if r.random() < 0.3 else r.getrandbits(32))
    return a, w, now


def _a0(c):
    return [_action(c)[0]]


def _aw(c):
    a, w, now = _action(c, _weapon(c))
    return [a, w]


def _rw(c):
    a, w, now = _action(c, _weapon(c))
    return [a, w, c.rng.choice((0, 1, 2, 0xffffffff))]


def _fromid(c):
    a = _a0(c)[0]
    i = c.rng.choice(list(range(0, 9)))
    if i < 1 or i > 7:
        c.emu.w32(0x7003b0, stub(c, 0, ret=c.rng.getrandbits(32)))
    return [a, i]


def _animid(c):
    r = c.rng
    a = _a0(c)[0]
    if r.random() < 0.85:
        v = c.emu.r32(a + r.choice(range(0x10, 0x2c, 4)))
    else:
        v = r.getrandbits(32)
    c.emu.w32(0x7003b0, stub(c, 0, ret=r.getrandbits(32)))
    return [a, v]


def _getanim(c, slot):
    _logger(c, slot)
    a = _a0(c)[0]
    return [a, c.emu.r32(c.emu.r32(_weapon(c)) + 0x350) and _tmpl(c)]


def _tmpl(c):
    r = c.rng
    t = obj(c, 0x40, {0x330: stub(c, 0, ret=r.choice(list(range(14)) + [99]))})
    c.emu.w32(t + 4, 0 if r.random() < 0.3 else c.emu.alloc(8, 4))
    return t


def _greload(c):
    _logger(c, 0x2c)
    return [_a0(c)[0], _tmpl(c)]


def _gchamber(c):
    _logger(c, 0x30)
    return [_a0(c)[0], _tmpl(c)]


def _update(c, start_off, anim_off, extra=False):
    r = c.rng
    a, w, now = _action(c)
    c.emu.w32(a + anim_off, 0 if r.random() < 0.15 else _anim(c))
    c.emu.wf32(a + start_off, (now + r.randint(-1500, 200)) / 1024.0 if r.random() < 0.9 else fedge(c))
    if extra:
        c.emu.wf32(a + 0x38, r.choice((0.0, 0.0, 0.44, 1e9, fedge(c))))
        c.emu.wf32(a + 0x3c, r.choice((0.68, 0.0, 1.0)))
        c.emu.wf32(a + 0x34, r.choice((0.0, 0.2, 0.25, 0.59, 0.61, fedge(c))))
    return [a]


S(0x64a6f0, 'ZActionReloadItem::GetHand', 'thiscall', None, ret='eax', gen=_a0)
S(0x486cb0, 'ZActionReloadItem::GetStartTime', 'thiscall', None, ret='st0', gen=_a0)
S(0x486bb0, 'ZActionReloadItem::GetReloadAnimFromId', 'thiscall', None, ret='eax', gen=_fromid)
S(0x486c30, 'ZActionReloadItem::GetReloadAnimId', 'thiscall', None, ret='eax', gen=_animid)
S(0x486aa0, 'ZActionReloadItem::GetReloadAnim', 'thiscall', None, ret='eax', gen=_greload)
S(0x4869e0, 'ZActionChamberItem::GetChamberAnim', 'thiscall', None, ret='eax', gen=_gchamber)
S(0x486e90, 'ZActionReloadItem::ReloadWeapon', 'thiscall', None, ret=None, gen=_rw)
S(0x4873f0, 'ZActionReloadItem::WeaponReloaded', 'thiscall', None, ret='al', gen=_aw)
S(0x4870c0, 'ZActionReloadItem::Terminate', 'thiscall', None, ret=None, gen=_a0)
S(0x486900, 'ZActionReloadItem::Execute', 'thiscall', None, ret='al',
  gen=lambda c: [_action(c, _weapon(c))[0]])
S(0x487230, 'ZActionReloadItem::Update', 'thiscall', None, ret='al', gen=lambda c: _update(c, 0x30, 0x2c, True))
S(0x4863c0, 'ZActionChamberItem::ChamberWeapon', 'thiscall', None, ret=None, gen=_aw)
def _cexec(c):
    _logger(c, 0x30)
    return [_action(c, _weapon(c))[0]]


S(0x486430, 'ZActionChamberItem::Execute', 'thiscall', None, ret='al', gen=_cexec)
S(0x487110, 'ZActionChamberItem::Update', 'thiscall', None, ret='al', gen=lambda c: _update(c, 0x2c, 0x28))
S(0x595210, 'ZFFHERO::ShowReloadAnim', 'thiscall', None, ret='al',
  gen=lambda c: _show(c))


def _show(c):
    r = c.rng
    cam = rnd(c, 0xc00)
    c.emu.w8(cam + 0xb45, 0 if r.random() < 0.5 else 1)
    h = rnd(c, 0x900)
    c.emu.w32(h + 0x85a, cam)
    t = obj(c, 0x40, {0x330: stub(c, 0, ret=r.choice((7, 7, 0, 5)))})
    return [h, obj(c, 0x40, {0x350: stub(c, 0, ret=t)})]
