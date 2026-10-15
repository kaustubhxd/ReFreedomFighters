"""specs_s209.py - ladder thread batch 209: ZFFHeroMovementGuide ctor, deleting dtor, GetAnims, Load, Save.
Base-class functions are hooked with logging stubs, so only this class's own code is compared."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import ladder_kit as K


def _hooks(c):
    e = c.emu

    def mk(name, argbytes, nargs, ret_this=False, eax=None):
        def h(e2, res):
            a = tuple(e2.arg32(i) for i in range(nargs))
            e2.calllog.append((name, e2.reg('ecx'), a))
            e2.ret(eax=e2.reg('ecx') if ret_this else (eax if eax is not None else 0x7777), argbytes=argbytes)
        return h
    e.hook(0x5e0e10, mk('BaseMove::ctor', 8, 2, ret_this=True))
    e.hook(0x480fd0, mk('~ZMovementBaseMove', 0, 0))
    e.hook(0x4878d0, mk('base dtor 0x4878d0', 0, 0))
    e.hook(0x634273, mk('delete', 0, 2))
    e.hook(0x488bc0, mk('ZMovementBaseMove::GetAnims', 0, 0))
    e.hook(0x489350, mk('ZMovementBase::Load', 4, 1))
    e.hook(0x489d00, mk('ZMovementBase::Save', 4, 1))


def _self(c, slots=None):
    s = K.rnd(c, 0x600)
    c.emu.w32(s, K.vt(c, 'guide', slots or {}, nslots=0x20))
    return s


def _ctor(c):
    _hooks(c)
    return [K.rnd(c, 0x600), c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _dtor(c):
    _hooks(c)
    return [K.rnd(c, 0x600), c.rng.getrandbits(32)]


def _anims(c):
    _hooks(c)
    r = c.rng
    v = r.getrandbits(32)

    def find(e2, a):
        return v, None, e2.cstr_read(a[0]) if hasattr(e2, 'cstr_read') else bytes(e2.rbytes(a[0], 13))
    s = _self(c, {0x58: (1, find), 0x54: (1, lambda e2, a: (0, None, e2.r32(a[0])))})
    return [s]


def _load(c):
    _hooks(c)
    r = c.rng
    h = r.getrandbits(32)
    lg = K.rnd(c, 0x10)

    def rd(e2, a):
        e2.w32(a[0], h)
        return 0, None, None
    c.emu.w32(lg, K.vt(c, 'loadgame', {0x40: (1, rd)}, nslots=0x20))
    eng = K.engine(c)
    gm = K.rnd(c, 0x10)
    c.emu.w32(eng + 0x9b, gm)
    obj = r.getrandbits(32)
    c.emu.w32(gm, K.vt(c, 'geoms', {0x58: (1, lambda e2, a: (obj, None, None))}))
    return [K.rnd(c, 0x600), lg]


def _save(c):
    _hooks(c)
    sg = K.rnd(c, 0x10)
    c.emu.w32(sg, K.vt(c, 'savegame', {0x64: (1, lambda e2, a: (0, None, None))}, nslots=0x20))
    return [K.rnd(c, 0x600), sg]


S(0x5e1040, 'ZFFHeroMovementGuide::ctor', 'thiscall', None, ret='eax', gen=_ctor, note='batch209')
S(0x5e1450, 'ZFFHeroMovementGuide::scalar deleting dtor', 'thiscall', None, ret='eax', gen=_dtor, note='batch209')
S(0x5e4600, 'ZFFHeroMovementGuide::GetAnims', 'thiscall', None, ret=None, gen=_anims, note='batch209')
S(0x5e5bc0, 'ZFFHeroMovementGuide::Load', 'thiscall', None, ret='al', gen=_load, note='batch209')
S(0x5e7150, 'ZFFHeroMovementGuide::Save', 'thiscall', None, ret='al', gen=_save, note='batch209')
