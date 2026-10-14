"""specs_s1601.py - soundtimers batch 1601: ZIKLNKOBJ sound calls (PlaySound x3, ControlSound, Sound_Delete).

World: sys+0x9b database whose SRefToPtr stub maps two handles (current speech, new sound) to sound objects;
sys+0x1a9f sound DLL (slot 0xf0: is-3D); ZGROUP::AddSound3d / AddSound2d (exe code) hooked to recorders that
return the new handle."""
from pilot import S
from sthelp import Seq, world


def _sound1(c):
    seq = Seq(c)
    me, hc, hn = world(c, seq)
    return [me, c.rng.getrandbits(32)]


S(0x466f60, 'ZIKLNKOBJ::PlaySound(uint)', 'thiscall', None, ret='eax', gen=_sound1,
  note='batch1601; 3D/2D through the group, flag 0x80 on, flag 4 off, category 2, priority from +0x143')


def _delete(c):
    seq = Seq(c)
    me, hc, hn = world(c, seq)
    return [me]


S(0x467c40, 'ZIKLNKOBJ::Sound_Delete', 'thiscall', None, ret=None, gen=_delete,
  note='batch1601; 0.1 s fade-out of the current speech')


def _control(c):
    seq = Seq(c)
    me, hc, hn = world(c, seq)
    r = c.rng
    return [me, r.getrandbits(32), r.choice([0, 1, 0x100, 0xffffff00, r.getrandbits(32)])]


S(0x466290, 'ZIKLNKOBJ::ControlSound', 'thiscall', None, ret='eax', gen=_control,
  note='batch1601; one speech at a time, force = fade out + 0.1 s delay')


def _play3(c):
    seq = Seq(c)
    me, hc, hn = world(c, seq)
    r = c.rng
    return [me, r.getrandbits(32), r.getrandbits(32), r.choice([0, 1, 0x100, r.getrandbits(32)])]


S(0x467060, 'ZIKLNKOBJ::PlaySound(uint,int,bool)', 'thiscall', None, ret='eax', gen=_play3, note='batch1601')


def _play4(c):
    seq = Seq(c)
    me, hc, hn = world(c, seq)
    r = c.rng
    d = r.choice([0, 100, 250, r.randint(-5000, 5000), r.getrandbits(32)])
    return [me, r.getrandbits(32), r.getrandbits(32), d, r.choice([0, 1, 0x100, r.getrandbits(32)])]


S(0x467000, 'ZIKLNKOBJ::PlaySound(uint,int,int,bool)', 'thiscall', None, ret='eax', gen=_play4, note='batch1601')
