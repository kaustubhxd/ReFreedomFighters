"""specs_s1628.py - soundtimers batch 1628: ZDllSound::MuteSourceGroup, SetDefaultEnv, SetTemporaryEnv."""
import struct
from pilot import S
from sthelp import rnd, sysobj


def _f(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _mute(c):
    r = c.rng
    sysobj(c)
    return [rnd(c, 0x5300), r.getrandbits(32), _f(r.choice([0.0, 1.0, -1.0, 0.5, r.uniform(-1e3, 1e3), float('nan')]))]


S(0x537f80, 'ZDllSound::MuteSourceGroup', 'thiscall', None, ret=None, gen=_mute, note='batch1628')


def _env(c):
    r = c.rng
    return [rnd(c, 0x5300), r.getrandbits(32)]


S(0x5398c0, 'ZDllSound::SetDefaultEnv', 'thiscall', None, ret=None, gen=_env, note='batch1628')
S(0x539c90, 'ZDllSound::SetTemporaryEnv', 'thiscall', None, ret=None, gen=_env, note='batch1628')
