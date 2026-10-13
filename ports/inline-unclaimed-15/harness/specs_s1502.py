"""specs_s1502.py - unclaimed-15 claim 2 (docs/20-unclaimed-15.md): ZInputActions::DisableActions (0x438360),
CheckAction(const char*, void*) (0x437fe0), GetActionValue (0x438f30), ForceSetAction (0x438880) and
CheckActionCheat(unsigned int, void*) (0x4380a0).

Each case gets a fresh ZInputActions object with a logging vtable (every slot logs its call, this and its arguments).
Slot +0x58 is the lookup: it returns a random 0x40-byte action (70%) or 0. The other slots return random eax values, so
the exe and the port see the same answers. CheckActionCheat reads the render manager from the global at 0x70039c; the
spec points it at a random 0x1000-byte object whose byte at +0x9b9 is drawn from {0, 1, 0x80, random}."""
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _name(c):
    return _rnd(c, 16)


def _zia(c):
    """A ZInputActions object with a logging vtable; returns (object, lookup result)."""
    o = _rnd(c, 0x200)
    found = _rnd(c, 0x40) if c.rng.random() < 0.7 else 0
    rv = {off: c.rng.getrandbits(32) for off in (0x2c, 0x4c, 0xa0)}
    impl = {0x58: lambda e, a: (found, None)}
    for off, v in rv.items():
        impl[off] = (lambda v: (lambda e, a: (v, None)))(v)
    vt = c.emu.logging_vtable('ZInputActions', 0xb0, impl=impl,
                              argwords={0x58: 1, 0x2c: 2, 0x4c: 2, 0xa0: 1})
    c.emu.w32(o, vt)
    return o


def _name_only(c):
    o = _zia(c)
    return [o, _name(c)]


def _name_bool(c):
    o = _zia(c)
    return [o, _name(c), c.rng.choice([0, 1, 0x100, 0x80000000, c.rng.getrandbits(32)])]


def _cheat(c):
    o = _rnd(c, 0x200)
    _rnd(c, c.rng.randrange(4, 0x400, 4))      # random pad: without it rm is always 0x20000200 (low byte 0)
    rm = _rnd(c, 0x1000)
    c.emu.wbytes(rm + 0x9b9, bytes([c.rng.choice([0, 0, 1, 0x80, c.rng.getrandbits(8)])]))
    c.emu.w32(0x70039c, rm)
    vt = c.emu.logging_vtable('ZInputActions', 0xb0, impl={0x2c: lambda e, a: (c.rng.getrandbits(32), None)},
                              argwords={0x2c: 2})
    c.emu.w32(o, vt)
    return [o, c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x438360, 'ZInputActions::DisableActions (unknown) thiscall', 'thiscall', None, ret=None, gen=_name_only,
  note='unclaimed-15 claim 2; lookup via slot +0x58, clears byte +0xc of the result')
S(0x437fe0, 'ZInputActions::CheckAction (unknown) thiscall', 'thiscall', None, ret='eax', gen=_name_bool,
  note='unclaimed-15 claim 2; slot +0x58 then slot +0x2c with (result, 0)')
S(0x438f30, 'ZInputActions::GetActionValue (unknown) thiscall', 'thiscall', None, ret='eax', gen=_name_only,
  note='unclaimed-15 claim 2; slot +0x58 then slot +0xa0 with the result')
S(0x438880, 'ZInputActions::ForceSetAction (unknown) thiscall', 'thiscall', None, ret='eax', gen=_name_bool,
  note='unclaimed-15 claim 2; slot +0x58 then slot +0x4c with (result, bool)')
S(0x4380a0, 'ZInputActions::CheckActionCheat (unknown) thiscall', 'thiscall', None, ret='eax', gen=_cheat,
  note='unclaimed-15 claim 2; render manager byte +0x9b9; else tail to slot +0x2c with (id, 0)')
