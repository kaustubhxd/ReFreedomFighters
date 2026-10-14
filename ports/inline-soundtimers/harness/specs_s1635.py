"""specs_s1635.py - soundtimers batch 1635: ZDllSound::FindWave and GetObjFromSoundSet (both DLL slots are stubs)."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks
from specs_s1632 import _data


def _cstr(c, s):
    a = c.emu.alloc(len(s) + 4, 4)
    c.emu.wbytes(a, s.encode() + b'\0')
    return a


def _fw(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    b = _data(c, seq)
    d = rnd(c, 0x5400)
    vt = obj(c, 0x200, {0x1b0: stub(c, seq, 3, ret=r.getrandbits(32)), 0x1d8: stub(c, seq, 2, ret=r.getrandbits(32)),
                        0x54: stub(c, seq, 1, ret=rnd(c, 8))})
    c.emu.w32(d, c.emu.r32(vt))
    c.emu.w32(d + 0x5302, b)
    return [d, _cstr(c, r.choice(['Wood', 'Snow', 'Default']))]


S(0x536950, 'ZDllSound::FindWave', 'thiscall', None, ret='eax', gen=_fw, note='batch1635')


def _gos(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    d = rnd(c, 0x5400)
    vt = obj(c, 0x200, {0x1d8: stub(c, seq, 2, ret=r.choice([0, r.getrandbits(32)])),
                        0x54: stub(c, seq, 1, ret=rnd(c, 8))})
    c.emu.w32(d, c.emu.r32(vt))
    return [d, r.getrandbits(32), _cstr(c, 'Wood')]


S(0x537340, 'ZDllSound::GetObjFromSoundSet', 'thiscall', None, ret='eax', gen=_gos, note='batch1635')
