"""specs_s1608.py - soundtimers batch 1608: ZFFHERO::InitSounds (FindInSoundSet and memset as in batch 1604)."""
from pilot import S
from sthelp import obj, stub, Seq, sysobj, clear_hooks
from specs_s1604 import _crt, _findset


def _init(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    _crt(c, seq)
    missing = set(n for n in ('*_Attac', '*_All*', '*_Die') if r.random() < 0.3)
    dll = obj(c, 0x40, {0x60: _findset(c, seq, missing)})
    sysobj(c, extra={0x1a9f: dll if r.random() < 0.9 else 0})
    me = obj(c, 0x1000, {0x578: stub(c, seq, 0, ret=r.getrandbits(32) if r.random() < 0.9 else 0)})
    return [me]


S(0x592580, 'ZFFHERO::InitSounds', 'thiscall', None, ret=None, gen=_init, note='batch1608; 23 hero lines')
