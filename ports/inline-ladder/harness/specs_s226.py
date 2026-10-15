"""specs_s226.py - ladder thread batch 226: ZIKLNKOBJ Save/Load, deleting destructor, ZActionDispatcher::SetCurrent."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S, u32
import ladder_kit as K


def _hk(c, addr, name, n, ab, ret=0):
    def h(e2, res):
        e2.calllog.append((name, e2.reg('ecx'), tuple(K.nostack(e2.arg32(i)) for i in range(n))))
        e2.ret(eax=ret, argbytes=ab)
    c.emu.hook(addr, h)


def _stream(c, name):
    e, r = c.emu, c.rng
    st = K.rnd(c, 0x10)
    slots = {}
    for o in (0x3c, 0x44, 0x4c, 0x60):
        slots[o] = (1, lambda e2, a: (0, None, None))
    for o in (0x40, 0x48, 0x50):
        slots[o] = (1, lambda e2, a, o=o: (e2.w32(a[0], r.choice([0, 0, r.getrandbits(32)])) or 0, None, None))
    slots[0x68] = (1, lambda e2, a: (st, None, None))
    slots[0x6c] = (1, lambda e2, a: (st, None, None))
    e.w32(st, K.vt(c, name, slots, nslots=0x20))
    return st


def _self(c):
    e, r = c.emu, c.rng
    s = K.rnd(c, 0x200)
    act = K.rnd(c, 0x20)
    e.w32(act, K.vt(c, 'action', {4: (0, lambda e2, a: (0x77, None, None)), 0x18: (1, lambda e2, a: (0, None, None)),
                                  0x1c: (1, lambda e2, a: (0, None, None))}, nslots=0x10))
    e.w32(s, K.vt(c, 'self', {0x3d4: (0, lambda e2, a: (0, None, None)), 0x358: (0, lambda e2, a: (0, None, None)),
                              0x3ec: (1, lambda e2, a: (act, None, None))}, nslots=0x110))
    d = K.rnd(c, 0x10)
    e.w32(d + 4, act if r.random() < 0.6 else 0)
    e.w32(s + 0x1ce, d)
    base = r.choice([0, 1, 0x100])
    _hk(c, 0x4640f0, 'ZLNKOBJ::Save', 1, 4, base)
    _hk(c, 0x463620, 'ZLNKOBJ::Load', 1, 4, base)
    _hk(c, 0x467850, 'ZTARGET::Save', 2, 8)
    _hk(c, 0x466eb0, 'ZTARGET::Load', 2, 8)
    _hk(c, 0x465660, 'dtor body', 0, 0)
    _hk(c, 0x45c510, 'ZGEOM::delete', 1, 0)
    return s


S(0x4946a0, 'ZActionDispatcher::SetCurrent', 'thiscall', [lambda c: K.rnd(c, 0x10), u32()], ret=None, note='batch226')
S(0x467770, 'ZIKLNKOBJ::Save', 'thiscall', None, ret='al', gen=lambda c: [_self(c), _stream(c, 'save')], note='batch226')
S(0x466dc0, 'ZIKLNKOBJ::Load', 'thiscall', None, ret='al', gen=lambda c: [_self(c), _stream(c, 'load')], note='batch226')
S(0x465720, 'ZIKLNKOBJ::scalar deleting dtor', 'thiscall', None, ret='eax',
  gen=lambda c: [_self(c), c.rng.getrandbits(3)], note='batch226')
