"""specs_s801.py - unclaimed-08 batch 801 (docs/20-unclaimed-08.md): CCHECKOBJINOBJ::Init, CMAINCAMERACONTROL::End,
ZActor::OnViewEnter. All three are thiscall with no return value.

Each case builds a fake ZSysInterface at *0x70039c (random bytes, with +0x9b and +0x1907 pointing at fake engine
objects). Their vtables log (slot, args) and return a random eax, so the call log and the returned value are part of
the comparison. The object under test is 0x800 random bytes, so every store lands inside it."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _sys(c, child_9b=None, child_1907=None):
    s = _rnd(c, 0x1a00)
    if child_9b is not None:
        c.emu.w32(s + 0x9b, child_9b)
    if child_1907 is not None:
        c.emu.w32(s + 0x1907, child_1907)
    c.emu.w32(0x70039c, s)
    return s


def _child(c, name, slot, nslots, retval):
    """A fake engine object whose vtable slot `slot` logs its argument and returns retval (eax)."""
    vt = c.emu.logging_vtable(name, nslots, impl={slot: lambda e, a: (retval, None)}, argwords={slot: 1})
    return c.emu.fake_object(name, 0x40, vtable=vt)


def _init(c):
    obj = _rnd(c, 0x800)
    c.emu.w32(obj + 0x44, c.rng.getrandbits(32))
    child = _child(c, 'CheckObjInObj child', 0x4c, 0x50 // 4, c.rng.getrandbits(32))
    _sys(c, child_9b=child)
    return [obj]


S(0x4fb8b0, 'CCheckObjInObj::Init (unknown)', 'thiscall', None, ret=None, gen=_init,
  note='unclaimed-08; byte to +0x48, vtable +0x4c(+0x44) to +0x49')


def _end(c):
    obj = _rnd(c, 0x800)
    k = c.rng.random()
    if k < 0.2:
        cam = 0
    else:
        cam = _child(c, 'MainCameraControl child', 0x14, 0x18 // 4 + 1, 0)
    _sys(c, child_1907=cam)
    return [obj]


S(0x4fc140, 'CMainCameraControl::End (unknown)', 'thiscall', None, ret=None, gen=_end,
  note='unclaimed-08; vtable +0x14(0x67d9e8) if ZSysInterface+0x1907 is set')


def _view_enter(c):
    actor = _rnd(c, 0x800)
    k = c.rng.random()
    n = 0 if k < 0.5 else (1 if k < 0.6 else c.rng.getrandbits(32))
    c.emu.w32(actor + 0x640, n)
    owner = _rnd(c, 0x80)
    flags = c.rng.getrandbits(32)
    c.emu.w32(owner + 0x3c, flags)
    c.emu.w32(actor + 8, owner)
    vt = c.emu.logging_vtable('ZActor vtable', 0xc0 // 4 + 1, impl={0xbc: lambda e, a: (0, None)}, argwords={0xbc: 1})
    c.emu.w32(actor, vt)
    _sys(c)
    return [actor]


S(0x47aa80, 'ZActor::OnViewEnter (unknown)', 'thiscall', None, ret=None, gen=_view_enter,
  note='unclaimed-08; counter at +0x640; first entry calls vtable +0xbc unless owner flags 0x800')


def _load3(c):
    hero = _rnd(c, 0x1000)
    c.emu.w8(hero + 0x684, c.rng.getrandbits(8))
    gd = _rnd(c, 0x3000)
    c.emu.w32(0x7003b8, gd)
    return [hero]


S(0x592d20, 'ZFFHERO::Load3 (unknown)', 'thiscall', None, ret=None, gen=_load3,
  note='unclaimed-08 batch 2; GetGameOSD(byte(+0x684)-1) to +0x852; callee inlined')
