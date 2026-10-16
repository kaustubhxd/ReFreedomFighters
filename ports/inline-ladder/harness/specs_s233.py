"""specs_s233.py - ladder thread batch 233: ZLNKWHANDS ClassInit2, Load2 (lookup of 'Inventory'), two thunks."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S, u32
import ladder_kit as K


def _h(c):
    e, r = c.emu, c.rng
    s = K.rnd(c, 0x400)
    inv = r.getrandbits(32)
    e.w32(s, K.vt(c, 'hands', {0x104: (1, lambda e2, a: (inv, None, None))}, nslots=0x180))
    for addr, name, n, ab in ((0x465fd0, 'ZIKLNKOBJ::ClassInit2', 0, 0), (0x466d90, 'ZIKLNKOBJ::Load2', 0, 0),
                              (0x466040, 'ZIKLNKOBJ::ClassInit', 0, 0), (0x465870, 'ZIKLNKOBJ::BoneAnimIdToCallBack', 1, 4)):
        def mk(name=name, n=n, ab=ab):
            def h(e2, res):
                e2.calllog.append((name, e2.reg('ecx'), tuple(e2.arg32(i) for i in range(n))))
                e2.ret(eax=0x4321, argbytes=ab)
            return h
        e.hook(addr, mk())
    return s


S(0x472fd0, 'ZLNKWHANDS::ClassInit2', 'thiscall', None, ret=None, gen=lambda c: [_h(c)], note='batch233')
S(0x474710, 'ZLNKWHANDS::Load2', 'thiscall', None, ret=None, gen=lambda c: [_h(c)], note='batch233')
S(0x472ff0, 'ZLNKWHANDS::ClassInit (thunk)', 'thiscall', None, ret=None, gen=lambda c: [_h(c)], note='batch233')
S(0x472450, 'ZLNKWHANDS::BoneAnimIdToCallBack (thunk)', 'thiscall', None, ret='eax',
  gen=lambda c: [_h(c), c.rng.getrandbits(32)], note='batch233')
