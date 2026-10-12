"""specs_s1602.py - unclaimed-16 batch 2 (docs/20-unclaimed-16.md). Each callee through a vtable is a logging
vtable (pilot's logging_vtable), so the call order, the object passed in ecx and the stack arguments are compared.
The CAction objects are 0x100 bytes, the ZActor object 0x1000 bytes; the sub-object at +0x44 is always set."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _vt(c, name):
    return c.emu.logging_vtable(name, 80, argwords={0x128: 3})


def _globals(c):
    """Random words for the globals the callers read (0x6ffa2c/30/34 path notes, 0x7002c8 action word). Written in
    gen, so each run sees the same values and the image restore does not undo them."""
    for a in (0x6ffa2c, 0x6ffa30, 0x6ffa34, 0x7002c8):
        c.emu.w16(a, c.rng.getrandbits(16))


def _action(c):
    _globals(c)
    obj = _rnd(c, 0x100)
    sub = _rnd(c, 0x100)
    c.emu.w32(sub, _vt(c, 'action_sub'))
    c.emu.w32(obj + 0x44, sub)
    c.emu.wbytes(obj + 0x63, bytes([c.rng.choice([0, 1, 2, 0x80, 0xff, c.rng.getrandbits(8)])]))
    return [obj, c.rng.getrandbits(32)]


def _actor(c):
    _globals(c)
    obj = _rnd(c, 0x1000)
    c.emu.w32(obj, _vt(c, 'actor_vt'))
    return [obj, c.rng.getrandbits(32)]


def _moveflags(c):
    obj = _rnd(c, 0x1000)
    a1 = c.rng.randint(0, 25) if c.rng.random() < 0.8 else c.rng.getrandbits(32)
    return [obj, a1]


S(0x4a1d80, 'CAction::SetPriority (unknown) thiscall', 'thiscall', None, ret=None, gen=_action,
  note='unclaimed-16 b2; arg to +0x52; if byte +0x63 call slot 0x128 of +0x44 with (word 0x7002c8, 1, obj)')
S(0x4a1db0, 'CAction::SetType (unknown) thiscall', 'thiscall', None, ret=None, gen=_action,
  note='unclaimed-16 b2; arg to +0x48; if byte +0x63 call slot 0x128 of +0x44 with (word 0x7002c8, 1, obj)')
S(0x479810, 'ZActor::OnPathCanceled (unknown) thiscall', 'thiscall', None, ret=None, gen=_actor,
  note='unclaimed-16 b2; slot 0x128 of self with (word 0x6ffa2c, arg, 0); clears +0x6ba, +0x6be')
S(0x479850, 'ZActor::OnPathCanceledLockedDoor (unknown) thiscall', 'thiscall', None, ret=None, gen=_actor,
  note='unclaimed-16 b2; word 0x6ffa30')
S(0x479890, 'ZActor::OnPathError (unknown) thiscall', 'thiscall', None, ret=None, gen=_actor,
  note='unclaimed-16 b2; word 0x6ffa34')
S(0x478c90, 'ZActor::GetMoveFlags (unknown) thiscall', 'thiscall', None, ret='eax', gen=_moveflags,
  note='unclaimed-16 b2; jump table: 6..10 -> 0x40c, else 0x400')
