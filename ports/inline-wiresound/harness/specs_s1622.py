"""specs_s1622.py - soundtimers batch 1622: small ZDllSound accessors (GetListener uses the database and listener stubs)."""
import struct
from pilot import S
from sthelp import rnd, obj, stub, Seq, sysobj, clear_hooks


def _group(c):
    r = c.rng
    o = rnd(c, 0x5300)
    return [o, r.randint(0, 31) if r.random() < 0.9 else r.getrandbits(32), r.getrandbits(32)]


S(0x5398d0, 'ZDllSound::SetGroupPitch', 'thiscall', None, ret=None, gen=_group, note='batch1622')


def _self(c):
    return [rnd(c, 0x5300)]


S(0x5333c0, 'ZDllSound::GetGraph', 'thiscall', None, ret='eax', gen=_self, note='batch1622')
S(0x533b40, 'ZDllSound::IsPaused', 'thiscall', None, ret='al', gen=_self, note='batch1622')
S(0x5333d0, 'ZDllSound::GetMutedSourceGroups', 'thiscall', None, ret='eax', gen=_self, note='batch1622')


def _listener(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    reg = r.getrandbits(32)
    rec = rnd(c, 0x40)
    db = obj(c, 0x80, {0x58: stub(c, seq, 1, ret=rec if r.random() < 0.7 else 0)})
    lis = obj(c, 0x40, {0xb4: stub(c, seq, 1, ret=r.getrandbits(32))})
    sysobj(c, db=db, extra={0x190f: lis if r.random() < 0.85 else 0})
    d = rnd(c, 0x5300)
    c.emu.w32(d + 0x51ad, reg)
    return [d]


S(0x537200, 'ZDllSound::GetListener', 'thiscall', None, ret='eax', gen=_listener, note='batch1622')
