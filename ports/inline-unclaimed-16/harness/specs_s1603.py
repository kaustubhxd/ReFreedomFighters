"""specs_s1603.py - unclaimed-16 batch 3 (docs/20-unclaimed-16.md): ZMatPosAnim::RunOffscreen, ZInputActions::
GetActionMapStatus and ZActor::GetAnimOffset(const char*). Virtual callees are logging vtables (pilot.py), so their
order, the object in ecx and their stack arguments are compared. The render-manager globals are set in gen."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _matpos(c):
    obj = _rnd(c, 0x200)
    c.emu.w32(obj, c.emu.logging_vtable('matpos', 0x80, argwords={0x64: 1}))
    return [obj, c.rng.choice([0, 1, 2, 0x100, 0xff, c.rng.getrandbits(32)])]


def _mapstatus(c):
    base = _rnd(c, 0x80)               # inner object is obj-4, so base holds its vtable and obj's first dword follows
    obj = base + 4
    first = c.rng.choice([3, 0, c.rng.getrandbits(32)])
    c.emu.w32(obj, first)
    inner_vt = c.emu.logging_vtable('inner', 16, impl={0x30: lambda e, a: (0x5151, None)})
    c.emu.w32(base, inner_vt)
    zi = _rnd(c, 0x100)
    zi_vt = c.emu.logging_vtable('zinput', 0x80, impl={0x58: lambda e, a: (obj, None)}, argwords={0x58: 1})
    c.emu.w32(zi, zi_vt)
    return [zi, c.rng.getrandbits(32)]


def _animoff(c):
    rm = _rnd(c, 0x200)
    q = _rnd(c, 0x100)
    c.emu.w32(rm + 0x9b, q)
    c.emu.w32(q + 0x44, c.rng.getrandbits(32))
    c.emu.w32(0x70039c, rm)
    zero = c.rng.random() < 0.2
    val = 0 if zero else c.rng.getrandbits(32)
    actor = _rnd(c, 0x1000)
    vt = c.emu.logging_vtable('actor_anim', 0x88, impl={0x21c: lambda e, a: (val, None)}, argwords={0x21c: 1})
    c.emu.w32(actor, vt)
    return [actor, c.rng.getrandbits(32)]


S(0x4a5da0, 'ZMatPosAnim::RunOffscreen (unknown) thiscall', 'thiscall', None, ret=None, gen=_matpos,
  note='unclaimed-16 b3; slot 0x64 with (16) if flag; byte arg to +0x92')
S(0x438260, 'ZInputActions::GetActionMapStatus (unknown) thiscall', 'thiscall', None, ret='eax', gen=_mapstatus,
  note='unclaimed-16 b3; slot 0x58 gives obj; first dword 3 calls slot 0x30 of obj-4; 0 clears +0x42')
S(0x478b00, 'ZActor::GetAnimOffset (unknown) thiscall', 'thiscall', None, ret='eax', gen=_animoff,
  note='unclaimed-16 b3; slot 0x21c gives p; p minus [[0x70039c]+0x9b]+0x44 (0 if p is 0)')
