"""specs_s1619.py - soundtimers batch 1619: ZFFHERO footstep/SFX wrappers, ZIKLNKOBJ::KillAllSounds."""
from pilot import S
from sthelp import rnd, stub, Seq, world
from specs_s1610 import _foot


def _herofoot(c):
    a = _foot(c)
    me = a[0]
    c.emu.w32(me + 0x417, c.rng.choice([0, 0x400, 0x401, c.rng.getrandbits(32)]))
    return a


S(0x593fd0, 'ZFFHERO::PlaySoundFootStep', 'thiscall', None, ret='eax', gen=_herofoot, note='batch1619')


def _herosfx(c):
    seq = Seq(c)
    r = c.rng
    me, hc, hn = world(c, seq, size=0x1000)
    c.emu.w32(me + 0xf5a, hc if r.random() < 0.6 else (0 if r.random() < 0.5 else r.getrandbits(32)))
    return [me, r.getrandbits(32)]


S(0x593ff0, 'ZFFHERO::PlaySoundSFX', 'thiscall', None, ret='eax', gen=_herosfx, note='batch1619')


def _kill(c):
    seq = Seq(c)
    me, hc, hn = world(c, seq, dll_slots={0x84: stub(c, seq, 1)})
    return [me]


S(0x466ce0, 'ZIKLNKOBJ::KillAllSounds', 'thiscall', None, ret=None, gen=_kill, note='batch1619')
