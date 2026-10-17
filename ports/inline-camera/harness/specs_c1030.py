"""specs_c1030.py - camera batch 1030: ZCamHelper::Save. The save object logs every call (slot and argument)."""
from pilot import S
from camgen import rnd, Log, handler


def _save(c):
    r = c.rng
    log = Log(c, 1024)
    slots = {s: handler(log, s, 1) for s in (0x4c, 0x60, 0x40, 0x68, 0x70, 0x3c, 0x64)}
    sg = c.emu.fake_object('sg', 0x10, slots=slots)
    h = rnd(c, 0xf00)
    c.emu.w32(h + 4, r.getrandbits(32))
    return [h, sg]


S(0x5d18a0, 'ZCamHelper::Save', 'thiscall', ret='al', gen=_save)
