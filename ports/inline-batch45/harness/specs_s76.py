"""specs_s76.py - main thread batch 76: OpenGate / RaiseFlag Move and OpenGate TerminateControl.
mcpy, mpul, RestoreItem and the OSD flag setter run as exe code. Stubs: the movement's own slot 0x48 (collision check),
the engine logger [0x700390] slots 0x20 / 0x2c, the hero's slots 0x3dc, 0x480, 0x504 (used by RestoreItem)."""
import struct
from pilot import S
from kit76 import obj, rnd, floats, wfloats, rvt


def _sys(c, t0):
    s = rnd(c, 0x100)
    c.emu.w32(0x70039c, s)
    c.emu.w32(s + 0x40, t0)
    return s


def _mover(t0off, posoff, name):
    def gen(c):
        r = c.rng
        e = c.emu
        self_ = rnd(c, 0x5e0)
        t0 = r.randint(0, 1 << 20)
        _sys(c, t0)
        # start time in seconds: in place (> 0.24 s ago), exactly at the edge, moving, in the future, odd values
        back = r.choice([0, 100, 245, 246, 1000, r.randint(-50, 400), r.randint(0, 1 << 21)])
        st = (t0 - back) / 1024.0 if r.random() < 0.95 else r.choice([float('nan'), float('inf'), -0.0, 1e12])
        wfloats(e, self_ + t0off, [st])
        wfloats(e, self_ + posoff, [c.fv(-500, 500) for _ in range(6)])
        hit = r.choice([0, 1, 0x100])
        e.w32(self_, rvt(e, name, {0x48: (5, lambda e, t, a: (hit, None, (a[0], a[1], floats(e, a[2], 9), floats(e, a[3], 3), a[4])))}))
        lg = obj(e, 'log', 0x10, {0x2c: (2, lambda e, t, a: (0, None, (a[0], a[1])), 0)})
        logger = obj(e, 'logger', 0x10, {0x20: (2, lambda e, t, a: (lg, None, (a[0], a[1])))})
        e.w32(0x700390, logger)
        c.emu.mu.ctl_flush_tb()
        return [self_, c.fbuf(9), c.fbuf(3), c.fbuf(9), c.fbuf(3), c.fbuf(3)]
    return gen


S(0x5e6d60, 'ZFFHeroMovementOpenGate::Move', 'thiscall', None, ret=None, gen=_mover(0x54f, 0x55f, 'opengate'),
  note='b76; mcpy and mpul run as original')
S(0x5e7000, 'ZFFHeroMovementRaiseFlag::Move', 'thiscall', None, ret=None, gen=_mover(0x555, 0x56d, 'raiseflag'),
  note='b76; mcpy and mpul run as original')


def _term(c):
    r = c.rng
    e = c.emu
    self_ = rnd(c, 0x5e0)
    e.w8(self_ + 0x54c, r.choice([0, 0, 1, r.getrandbits(8)]))
    osd = rnd(c, 0x2300)
    cur = r.getrandbits(32)
    hero = obj(e, 'hero', 0xa00, {0x3dc: (0, None), 0x480: (1, None),
                                  0x504: (0, lambda e, t, a: (r.choice([0, cur, 1]), None, ()))}, rng=r)
    e.w32(hero + 0x852, osd)
    e.w32(hero + 0x836, r.getrandbits(32))
    e.w32(hero + 0x832, r.choice([0, cur, r.getrandbits(32)]))
    e.w32(self_ + 0x36d, hero)
    c.emu.mu.ctl_flush_tb()
    return [self_, r.choice([0, 1, 0x100, r.getrandbits(32)])]


S(0x5e73c0, 'ZFFHeroMovementOpenGate::TerminateControl', 'thiscall', None, ret='al', gen=_term,
  note='b76; RestoreItem and the OSD flag setter run as original; hero slots 0x3dc/0x480/0x504 are recorders')
