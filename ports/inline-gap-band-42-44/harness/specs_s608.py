"""specs_s608.py - band 0x421000-0x441000, batch 608: RemoveDll, SetEngineData, IsConnected, ExistsInZip, StopEffects.
Every virtual slot the functions call is a fake object slot that records (name, slot, ecx, args) in the call log and
returns a value fixed by the setup, so the original and the port see the same results.
"""
import os
import sys

for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)

from pilot import S  # noqa: E402


def _rec(name, off, nargs, ret=0):
    def h(e, rr):
        args = tuple(e.arg32(k) for k in range(nargs))
        e.calllog.append((name, off, e.reg('ecx'), args))
        e.ret(eax=ret, argbytes=4 * nargs)
    return h


def _obj(c, name, slots, size=0x40):
    return c.emu.fake_object(name, size, nslots=0x140, slots=slots)


# 0x4234b0 RemoveDll(p): stdcall. The object's slot 0 gets (1)
def _gen_remove(c):
    r = c.rng
    if r.random() < 0.2:
        p = 0
    else:
        p = _obj(c, 'dll', {0: _rec('dll.dtor', 0, 1)})
        c.emu.w32(p + 8, r.getrandbits(32))
    return [p]


# 0x42aac0 SetEngineData(d): thiscall. The old engine (this+0x9b) gets slot 0x94 (1) when it exists
def _gen_engine(c):
    r = c.rng
    self_ = c.emu.alloc(0x100, 16)
    c.emu.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x100)))
    old = _obj(c, 'eng_old', {0x94: _rec('eng.94', 0x94, 1)}) if r.random() < 0.7 else 0
    c.emu.w32(self_ + 0x9b, old)
    d = c.emu.alloc(0x20, 16) if r.random() < 0.5 else 0
    return [self_, d]


# 0x435d90 IsConnected(i, y): thiscall, two arguments. Devices at this+0x20 (count at +0x60), slot 0x44 (y)
def _gen_connected(c):
    r = c.rng
    self_ = c.emu.alloc(0x100, 16)
    c.emu.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x100)))
    n = r.randint(0, 4)
    c.emu.w32(self_ + 0x60, n)
    for k in range(4):
        dev = _obj(c, 'dev%d' % k, {0x44: _rec('dev.44', 0x44, 1)}) if (k < n and r.random() < 0.8) else 0
        c.emu.w32(self_ + 0x20 + 4 * k, dev)
    i = r.choice((0, 1, 2, 3, 4, 7, 0xffffffff))
    return [self_, i, r.getrandbits(32)]


# 0x434ce0 ExistsInZip(name): thiscall. this's slot 0x130 (name) gives a value; slot 0x70 (that value) gives bool-ish
def _gen_zip(c):
    r = c.rng
    # the lookup value and the result are fixed per run
    lookup = r.getrandbits(32)
    res = r.choice((0, 1, 0x100))

    def h130(e, rr):
        e.calllog.append(('zip.130', 0x130, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=lookup, argbytes=4)

    def h70(e, rr):
        e.calllog.append(('zip.70', 0x70, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=res, argbytes=4)
    self_ = _obj(c, 'zip', {0x130: h130, 0x70: h70})
    name = c.emu.alloc(0x20, 16)
    return [self_, name]


# 0x43da90 StopEffects(): thiscall, no arguments. this+4 is the effect: slots 0x48 and 0x4c (0)
def _gen_stop(c):
    r = c.rng
    self_ = c.emu.alloc(0x100, 16)
    c.emu.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x100)))
    eff = _obj(c, 'eff', {0x48: _rec('eff.48', 0x48, 1), 0x4c: _rec('eff.4c', 0x4c, 1)})
    c.emu.w32(self_ + 4, eff)
    c.emu.w32(self_ + 0x80, r.getrandbits(32))
    return [self_]


S(0x4234b0, 'ZSysInterfaceGC::RemoveDll', 'stdcall', None, ret='al', gen=_gen_remove)
S(0x42aac0, 'ZSysInterfaceGC::SetEngineData', 'thiscall', None, ret=None, gen=_gen_engine)
S(0x435d90, 'ZSysInput::IsConnected', 'thiscall', None, ret='al', gen=_gen_connected)
S(0x434ce0, 'ZSysFile::ExistsInZip', 'thiscall', None, ret='al', gen=_gen_zip)
S(0x43da90, 'ZHapticsBase::StopEffects', 'thiscall', None, ret=None, gen=_gen_stop)
