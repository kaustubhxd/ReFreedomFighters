"""specs_s1623.py - soundtimers batch 1623: ZDllSound::SetMasterVolume, ZSoundObject::ControlAutoFade."""
import struct
from pilot import S
from sthelp import rnd, obj, stub, Seq, sysobj, clear_hooks


def _mv(c):
    r = c.rng
    return [rnd(c, 0x5300), r.choice([0, 100, 50, -20, 1000, r.getrandbits(32)])]


S(0x539c70, 'ZDllSound::SetMasterVolume', 'thiscall', None, ret=None, gen=_mv, note='batch1623')


def _fade(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    db = obj(c, 0x200, {0xb8: stub(c, seq, 0, ret=r.choice([0, 1, 0x100, r.getrandbits(32)]))})
    sysobj(c, db=db, dt=r.uniform(0, 0.1))
    s = c.emu.r32(0x70039c)
    c.emu.wf32(s + 0x20, r.uniform(0, 0.5))
    o = rnd(c, 0x100)
    c.emu.w8(o + 0xec, 1 if r.random() < 0.9 else 0)
    now = c.emu.r32(s + 0x40)
    k = r.random()
    start = (now / 1024.0) - r.uniform(0, 3) if k < 0.7 else ((now / 1024.0) + r.uniform(0, 2))
    c.emu.wf32(o + 0xed, start)
    c.emu.wf32(o + 0xf1, r.choice([1.0, 1.5, 0.5, r.uniform(0, 3)]))
    c.emu.wf32(o + 0xf5, r.choice([0.0, 0.1, 0.5, r.uniform(0, 2)]))
    c.emu.wf32(o + 0x88, r.uniform(0, 100))
    c.emu.w32(o + 4, 2)
    return [o]


S(0x44bc00, 'ZSoundObject::ControlAutoFade', 'thiscall', None, ret='al', gen=_fade, note='batch1623')
