"""specs_s243.py - area 22, batch243 (src/batch243.cpp): gameplay-core functions from the docs/39 list.
Exe callees are hooked by address (helpers22._hk: ecx and stack words logged); vtable callees are logged sparse slots;
the logger and assert hook follow inline-ai specs_s709; _stricmp is a Python C-locale stub on the IAT."""
import struct
from pilot import S
from helpers22 import _rnd, _multi_vt, _hk, _log_world, _stricmp_stub


def _r(c):
    return c.rng.getrandbits(32)


def _alb(c):
    """A return value whose low byte is zero or not, with random upper bits (tests al-only tests)."""
    return (c.rng.getrandbits(24) << 8) | c.rng.choice([0, 0, 1, c.rng.getrandbits(8)])


def _g_47adc0(c):
    self_ = _rnd(c, 0x40)
    c.emu.w32(self_, _multi_vt(c, {0x584: (lambda em, a: (0, None), 1), 0x654: (lambda em, a, v=_r(c): (v, None), 1)}))
    c.emu.mu.ctl_flush_tb()
    return [self_]


def _g_489160(c):
    self_ = _rnd(c, 0x400)
    v58 = _r(c)
    c.emu.w32(self_, _multi_vt(c, {0x58: (lambda em, a, v=v58: (v, None), 1), 0x54: (lambda em, a: (0, None), 1)}))
    _hk(c, 0x488bc0, '488bc0', 0)
    c.emu.mu.ctl_flush_tb()
    return [self_]


def _g_5b3780(c):
    self_ = _rnd(c, 0x200)
    c.emu.w32(self_ + 0x4d, c.rng.choice([3, 3, 0, 1, 2, _r(c), (c.rng.getrandbits(24) << 8) | 3]))   # high bits over a low byte 3: the compare is 32-bit
    rm = _rnd(c, 0x100)
    c.emu.wbytes(rm + 0x6c, bytes([c.rng.choice([0, 0, 1, c.rng.getrandbits(8)])]))
    c.emu.w32(0x70039c, rm)
    for a in (0x5b37e0, 0x5b3540, 0x5b3ba0, 0x5b3ef0):
        _hk(c, a, '%x' % a, 0, eax=_r(c))
    c.emu.mu.ctl_flush_tb()
    return [self_]


def _g_514600(c):
    flagobj = _rnd(c, 0x40)
    o = _rnd(c, 0x40)
    c.emu.w32(o + 8, flagobj)
    c.emu.w32(o, _multi_vt(c, {0x1e0: (lambda em, a, v=_alb(c): (v, None), 1),
                               0x438: (lambda em, a, v=_alb(c): (v, None), 0)}))
    ret58 = c.rng.choice([o, o, o, 0])
    db = _rnd(c, 0x40)
    c.emu.w32(db, _multi_vt(c, {0x58: (lambda em, a, v=ret58: (v, None), 1)}))
    rm = _rnd(c, 0x100)
    c.emu.w32(rm + 0x9b, db)
    c.emu.w32(0x70039c, rm)
    c.emu.mu.ctl_flush_tb()
    return [_rnd(c, 0x40), _r(c)]


_MOVE = ['Stand', 'Start', 'Stop', 'StopLeftLeg', 'StopRightLeg', 'StairsUp', 'StairsDown', 'Forward', 'ForwardTurnLeft',
         'ForwardTurnRight', 'Backward', 'TurnLeft45', 'TurnLeft90', 'TurnLeft135', 'TurnRight45', 'TurnRight90',
         'TurnRight135', 'Turn180']


def _g_478e20(c):
    _log_world(c)
    _stricmp_stub(c)
    k = c.rng.random()
    if k < 0.6:
        s = c.rng.choice(_MOVE)
        if c.rng.random() < 0.5:
            s = ''.join(ch.upper() if c.rng.random() < 0.5 else ch.lower() for ch in s)
    elif k < 0.8:
        s = c.rng.choice(_MOVE)
        s = c.rng.choice([s[:-1], s + 'x', s + ' ', '_' + s])
    else:
        s = ''.join(chr(c.rng.randint(32, 126)) for _ in range(c.rng.randint(0, 12)))
    c.emu.mu.ctl_flush_tb()
    return [_rnd(c, 0x40), c.emu.cstr(s)]


def _g_55c840(c):
    _log_world(c)
    p = _rnd(c, 0x10)
    c.emu.wbytes(p + 4, bytes([c.rng.choice([0, 0, 2, 2, 1, 3, c.rng.getrandbits(8)])]))
    _hk(c, 0x5003d0, '5003d0', 1, eax=p)
    _hk(c, 0x5a2d20, '5a2d20', 1)
    self_ = _rnd(c, 0x40)
    c.emu.w32(self_ + 0x1c, _rnd(c, 0x40))
    params = _rnd(c, 0x10)
    c.emu.w32(params + 4, _rnd(c, 0x20))
    c.emu.mu.ctl_flush_tb()
    return [self_, params]


S(0x47adc0, 'ZActor::Resurrect', 'thiscall', None, ret=None, gen=_g_47adc0, note='batch243; vt 0x584(1), vt 0x654(1)')
S(0x489160, 'ZMovementGuide::GetAnims', 'thiscall', None, ret=None, gen=_g_489160,
  note='batch243; 0x488bc0 hooked, vt 0x58 result stored at +0x391, vt 0x54(this+0x391)')
S(0x5b3780, 'ZActionControlMap::GenerateGameActions', 'thiscall', None, ret=None, gen=_g_5b3780,
  note='batch243; engine flag +0x6c, mode +0x4d; 0x5b37e0, 0x5b3540, 0x5b3ba0, 0x5b3ef0 hooked')
S(0x514600, 'ZMoveOnSpline::TargetValid', 'thiscall', None, ret='al', gen=_g_514600,
  note='batch243; engine db vt 0x58, object vt 0x1e0 and 0x438, flag bit 10')
S(0x478e20, 'ZActor::GetMoveTypeId', 'thiscall', None, ret='eax', gen=_g_478e20,
  note='batch243; 18-entry table at 0x68ac68 via _stricmp, warning on unknown names')
S(0x55c840, 'ZFFActorIf::SetHPMultiplierForHeadShot', 'thiscall', None, ret=None, gen=_g_55c840,
  note='batch243; type check with logger and assert hook, 0x5a2d20(float)')
