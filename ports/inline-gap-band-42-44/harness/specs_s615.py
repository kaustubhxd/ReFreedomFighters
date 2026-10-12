"""specs_s615.py - band 0x421000-0x441000, batch 615 (see src/batch615.cpp).
0x434e00 reads the global object at 0x700394 and calls its slot 0x90 (name, 1): the object is a recording fake.
0x4359d0 calls the receiver's slot 0x128 (name, flag): recorded.
Note: 0x434e00 takes one stack argument and has no receiver; the port's first parameter is a dummy (ecx is not read).
"""
import os
import sys

for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)

from pilot import S  # noqa: E402

GLOBAL_394 = 0x700394


def _rec(name, off, nargs, ret):
    def h(e, rr):
        e.calllog.append((name, off, e.reg('ecx'), tuple(e.arg32(k) for k in range(nargs))))
        e.ret(eax=ret, argbytes=4 * nargs)
    return h


def _gen_scene(c):
    r = c.rng
    obj = c.emu.fake_object('scene', 0x40, nslots=0x100, slots={0x90: _rec('scene.90', 0x90, 2, 0)})
    c.emu.w32(GLOBAL_394, obj)
    return [0, r.getrandbits(32)]   # receiver (ecx, unused), then the name argument


def _gen_big(c):
    r = c.rng
    self_ = c.emu.fake_object('zfile', 0x40, nslots=0x100, slots={0x128: _rec('zfile.128', 0x128, 2, r.getrandbits(32))})
    return [self_, r.getrandbits(32), r.getrandbits(32)]


S(0x434e00, 'ZSysFileGC::LoadWholeSceneZip', 'thiscall', None, ret=None, gen=_gen_scene)
S(0x4359d0, 'ZSysFile::UseBig', 'thiscall', None, ret='al', gen=_gen_big)
