"""specs_c1027.py - camera batch 1027: ZFFCam Save / Load."""
from pilot import S
from camgen import rnd, Log, handler


def _io(c, slots, base):
    r = c.rng
    log = Log(c, 512)
    c.emu.hook(base, handler(log, base, 1, eax=r.choice([0, 1, 0x101, r.getrandbits(32)])))
    sg = c.emu.fake_object('io', 0x10, slots={s: handler(log, s, 1, eax=r.getrandbits(32)) for s in slots})
    return [rnd(c, 0x460), sg]


S(0x5ca270, 'ZFFCam::Save', 'thiscall', ret='al', gen=lambda c: _io(c, (0x3c, 0x44, 0x4c, 0x60, 0x68, 0x70), 0x4fb2f0))
S(0x5c9f80, 'ZFFCam::Load', 'thiscall', ret='al', gen=lambda c: _io(c, (0x40, 0x48, 0x50, 0x68, 0x6c, 0x74), 0x4fb360))


def _io1(c, slots, base, ease):
    r = c.rng
    log = Log(c, 512)
    c.emu.hook(base, handler(log, base, 1, eax=r.choice([0, 1, 0x101, r.getrandbits(32)])))
    c.emu.hook(ease, handler(log, ease, 1, eax=r.getrandbits(32)))
    sl = {s: handler(log, s, 1, eax=r.getrandbits(32)) for s in slots}
    sl[slots[-1]] = handler(log, slots[-1], 2, eax=r.getrandbits(32))  # raw (ptr, size)
    sg = c.emu.fake_object('io', 0x10, slots=sl)
    return [rnd(c, 0x5a0), sg]


S(0x5cc620, 'ZFFCamera1::Save', 'thiscall', ret='al', gen=lambda c: _io1(c, (0x4c, 0x54, 0x60, 0x68, 0x10), 0x5ca270, 0x662660))
S(0x5cc020, 'ZFFCamera1::Load', 'thiscall', ret='al', gen=lambda c: _io1(c, (0x50, 0x58, 0x68, 0x6c, 0x18), 0x5c9f80, 0x6625c0))
