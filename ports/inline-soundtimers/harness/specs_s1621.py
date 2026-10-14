"""specs_s1621.py - soundtimers batch 1621: group volume / pitch readers, CalcDelayTime."""
import struct
from pilot import S
from sthelp import rnd


def _grp(c):
    r = c.rng
    o = rnd(c, 0x5200 + 0x100)
    for g in range(32):
        c.emu.wf32(o + 0x5159 + g * 9, r.choice([0.0, 1.0, 0.5, r.uniform(-2, 2)]))
        c.emu.w32(o + 0x515e + g * 9, r.getrandbits(32))
    return [o, r.randint(0, 31) if r.random() < 0.9 else r.getrandbits(32)]


S(0x5370b0, 'ZDllSound::GetGroupVolume', 'thiscall', None, ret='st0', gen=_grp, note='batch1621')
S(0x537090, 'ZDllSound::GetGroupPitch', 'thiscall', None, ret='eax', gen=_grp, note='batch1621')


def _delay(c):
    r = c.rng
    f = r.choice([0.0, 999.9, 1000.0, 1000.0001, 2999.0, r.uniform(-10, 5000), float('nan')])
    return [rnd(c, 0x10), struct.unpack('<I', struct.pack('<f', f))[0]]


S(0x535750, 'ZDllSound::CalcDelayTime', 'thiscall', None, ret='st0', gen=_delay, note='batch1621')
