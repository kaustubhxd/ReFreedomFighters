"""specs_s34069.py - 0x4c5610 (slot 0x84), 0x59a8d0 (member +0x1d0f, null or slot 0x214), 0x64fad0 (member +0xbd, null or slot 0x60) tail forwarders; 0x4d61c0 flag getter."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g4c5610(c):
    clear_hooks(c)
    r = c.rng
    me = obj(c, 0x40, {0x84: pystub(c, 2, ret=r.getrandbits(32), this=True)}, nslots=0x88 // 4)
    return [me, r.getrandbits(32), r.getrandbits(32)]


def _g59a8d0(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x1d20)
    inner = 0 if r.random() < 0.3 else obj(c, 0x40, {0x214: pystub(c, 2, ret=r.getrandbits(32), this=True)}, nslots=0x218 // 4)
    c.emu.wbytes(me + 0x1d0f, inner.to_bytes(4, 'little'))
    return [me, r.getrandbits(32), r.getrandbits(32)]


def _g64fad0(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0xd0)
    inner = 0 if r.random() < 0.3 else obj(c, 0x40, {0x60: pystub(c, 2, ret=r.getrandbits(32), this=True)}, nslots=0x64 // 4)
    c.emu.wbytes(me + 0xbd, inner.to_bytes(4, 'little'))
    return [me, r.getrandbits(32), r.getrandbits(32)]


def _g4d61c0(c):
    clear_hooks(c)
    r = c.rng
    a = rnd(c, 0x440)
    c.emu.wbytes(a + 0x42e, r.choice([1, 1, 0, 2, r.getrandbits(32), 0x100 | 1]).to_bytes(4, 'little'))
    return [a]


S(0x4c5610, 'GUESS forward slot 0x84', 'thiscall', None, ret='eax', gen=_g4c5610, note='batch34069')
S(0x59a8d0, 'GUESS forward member +0x1d0f slot 0x214', 'thiscall', None, ret='eax', gen=_g59a8d0, note='batch34069')
S(0x64fad0, 'GUESS forward member +0xbd slot 0x60', 'thiscall', None, ret='eax', gen=_g64fad0, note='batch34069')
S(0x4d61c0, 'GUESS flag +0x42e == 1', 'stdcall', None, ret='al', gen=_g4d61c0, note='batch34069')
