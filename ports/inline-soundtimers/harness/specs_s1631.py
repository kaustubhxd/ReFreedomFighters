"""specs_s1631.py - soundtimers batch 1631: ZDllSound::CalcVolume (log10 through the CRT thunk)."""
import struct
from pilot import S
from sthelp import rnd


def _f(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _gen(c):
    r = c.rng
    x = r.choice([0.0, -0.0, 100.0, 1.0, 0.5, 10.0, 1e-6, 1e6, -5.0, float('nan'), r.uniform(0, 200), r.uniform(-50, 300)])
    return [rnd(c, 0x10), _f(x)]


S(0x535940, 'ZDllSound::CalcVolume', 'thiscall', None, ret='eax', gen=_gen, note='batch1631')
