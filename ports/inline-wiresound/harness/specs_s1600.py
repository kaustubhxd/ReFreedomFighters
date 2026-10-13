"""specs_s1600.py - soundtimers batch 1600: ZCharacterControl timers and the two ZActor voice getters."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, sysobj, ticks, _cc, _timers


def _getter(c):
    return [rnd(c, 0x600)]


S(0x478a50, 'ZActor::GetActorSoundSet', 'thiscall', None, ret='eax', gen=_getter, note='batch1600; +0x5c2')
S(0x478a70, 'ZActor::GetActorVoicePitch', 'thiscall', None, ret='eax', gen=_getter, note='batch1600; +0x5c6')


def _delayed(c):
    seq = Seq(c)
    sysobj(c)
    o = _cc(c, seq)
    r = c.rng
    return [o, rnd(c, 0x40), r.getrandbits(32), r.getrandbits(32), rnd(c, 0x10)]


S(0x5dabe0, 'ZCharacterControl::Play_OnScreen_Delayed', 'thiscall', None, ret=None, gen=_delayed,
  note='batch1600; four stores and vtable +0x64(0x10)')


def _defaults(c):
    seq = Seq(c)
    sysobj(c)
    return [_cc(c, seq)]


S(0x5da950, 'ZCharacterControl::GetDefaultValues', 'thiscall', None, ret=None, gen=_defaults,
  note='batch1600; 98x3 timer table, exceptions, delayed-shout slot cleared')


def _load(c):
    seq = Seq(c)
    sysobj(c)
    return [_cc(c, seq), rnd(c, 0x20)]


S(0x5da750, 'ZCharacterControl::Load', 'thiscall', None, ret='al', gen=_load, note='batch1600')


def _init(c):
    seq = Seq(c)
    r = c.rng
    reg = obj(c, 0x40, {0x60: stub(c, seq, 2)})
    db = obj(c, 0x40, {0x138: stub(c, seq, 0, ret=reg), 0x4c: stub(c, seq, 2, ret=r.getrandbits(32))})
    sysobj(c, db=db)
    return [_cc(c, seq)]


S(0x5da700, 'ZCharacterControl::Init', 'thiscall', None, ret=None, gen=_init,
  note='batch1600; name registration through the database object, then GetDefaultValues')


def _caniplay(c):
    seq = Seq(c)
    r = c.rng
    s = sysobj(c)
    now = c.emu.r32(s + 0x40)
    o = _cc(c, seq)
    _timers(c, o, now)
    k = r.random()
    e = r.randint(0, 0x26) if k < 0.7 else (0x23 if k < 0.8 else (r.choice([4, 5, 0x22]) if k < 0.9 else r.randint(0, 0x61)))
    k = r.random()
    team = r.randint(0, 3) if k < 0.8 else r.getrandbits(32)
    return [o, e, team]


S(0x5da860, 'ZCharacterControl::CanIPlay', 'thiscall', None, ret='al', gen=_caniplay,
  note='batch1600; ticks compare, Stay/Cover share, team clamp, Generic/Greeting restart')


def _except1(c):
    """CRT _except1 (called by the float->int helper on an out-of-range or NaN value): record its flag argument and
    return 0.0 in ST0, like a masked exception."""
    rec = c.emu.alloc(8, 4)

    def h(e, r):
        e.w32(rec, e.r32(e.reg('esp') + 4))
        e.w32(rec + 4, e.r32(rec + 4) + 1)
        e.ret(st0=0.0)
    c.emu.stub_import('_except1', h)


def _frame(c):
    seq = Seq(c)
    _except1(c)
    r = c.rng
    k = r.random()
    dt = r.uniform(0, 0.1) if k < 0.8 else r.choice([0.0, 1e9, -1.0, float('inf'), float('nan'), r.uniform(-1e6, 1e6)])
    sysobj(c, dt=dt)
    o = _cc(c, seq)
    k = r.random()
    left = 0 if k < 0.4 else (r.randint(1, 3000) if k < 0.85 else r.getrandbits(32))
    c.emu.w32(o + 0x984, left)
    actor = obj(c, 0x40, {0x6ec: stub(c, seq, 3)}) if r.random() < 0.8 else 0
    c.emu.w32(o + 0x97c, actor)
    return [o]


S(0x5da760, 'ZCharacterControl::FrameUpdate', 'thiscall', None, ret=None, gen=_frame,
  note='batch1600; delayed shout countdown in ms through the CRT float->int64 helper 0x633910')
