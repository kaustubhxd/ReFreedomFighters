"""specs_s1604.py - unclaimed-16 batch 4 (docs/20-unclaimed-16.md): ZFFActor::SetHero, GetProjectilesInMagazine and
GetItemTemplate. The render-manager global at 0x70039c points to an object whose dword at +0x9b is a logging vtable
object; its slot 0x58 returns a chosen pointer or 0. Virtual callees are logging vtables, so their arguments and call
order are compared; their bodies are not verified here. ZActor::SetHero is original code (not a stub)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _mgr(c, impl58):
    """Sets the global 0x70039c to a render-manager object whose +0x9b dword is a logging object with slot 0x58."""
    q = _rnd(c, 0x100)
    c.emu.w32(q, c.emu.logging_vtable('mgr', 0x80, impl={0x58: impl58}, argwords={0x58: 1}))
    rm = _rnd(c, 0x200)
    c.emu.w32(rm + 0x9b, q)
    c.emu.w32(0x70039c, rm)


def _setpose(c):
    v = c.rng.getrandbits(32)
    _mgr(c, lambda e, a: (v, None))
    return [_rnd(c, 0x1000), c.rng.getrandbits(32)]


def _proj(c):
    ret35c = c.rng.getrandbits(32)
    proj = _rnd(c, 0x100)
    c.emu.w32(proj, c.emu.logging_vtable('proj', 0x100, impl={0x35c: lambda e, a, r=ret35c: (r, None)}))
    ptr = 0 if c.rng.random() < 0.25 else proj
    _mgr(c, lambda e, a, p=ptr: (p, None))
    obj = _rnd(c, 0x1000)
    a1 = c.rng.choice([0, 1, 2, c.rng.getrandbits(32)])
    return [obj, a1]


def _item(c):
    r = c.rng.choice([0, 1, 0x100, 0x101, 0xff00, c.rng.getrandbits(32)])
    item = _rnd(c, 0x100)
    c.emu.w32(item, c.emu.logging_vtable('item', 0x100, impl={0x1e0: lambda e, a, v=r: (v, None)},
                                         argwords={0x1e0: 1}))
    ptr = 0 if c.rng.random() < 0.2 else item
    _mgr(c, lambda e, a, p=ptr: (p, None))
    return [_rnd(c, 0x1000), c.rng.getrandbits(32)]


S(0x5a2d60, 'ZFFActor::SetHero (unknown) thiscall', 'thiscall', None, ret=None, gen=_setpose,
  note='unclaimed-16 b4; calls original ZActor::SetHero, stores slot 0x58 result at +0x92e')
S(0x59ff70, 'ZFFActor::GetProjectilesInMagazine (unknown) thiscall', 'thiscall', None, ret='eax', gen=_proj,
  note='unclaimed-16 b4; slot from +0x78a (arg 0) or +0x78e; null gives -1; else slot 0x35c')
S(0x59fe20, 'ZFFActor::GetItemTemplate (unknown) thiscall', 'thiscall', None, ret='eax', gen=_item,
  note='unclaimed-16 b4; obj from slot 0x58; slot 0x1e0 low byte decides obj or 0')
