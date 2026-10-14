"""specs_u69_03.py - area 69, group 3 (unclaimed-69 thread): two destructors. Bases and delete are GUESS stubs."""
import struct
from pilot import S
from ckit import rnd


def _hooks(e):
    def base_breath(e, res):
        e.w32(e.reg('ecx'), 0x67c3a4)            # the base stores its own vtable (GUESS; its real chain is not modelled)
        e.calllog.append(('base43de70', e.reg('ecx')))
        e.ret()
    e.hook(0x43de70, base_breath)
    e.hook(0x465660, lambda e, res: (e.calllog.append(('base465660', e.reg('ecx'))), e.ret()))
    e.hook(0x45c510, lambda e, res: (e.calllog.append(('delete', e.arg32(0))), e.ret(argbytes=0)))


def _dt(c):
    r = c.rng
    e = c.emu
    _hooks(e)
    o = rnd(c, 0x100)
    flags = r.choice([0, 1, 4, 5, 3, r.getrandbits(32)])
    return [o, flags]


S(0x44cb10, 'ZBreath::~ZBreath', 'thiscall', None, ret='eax', gen=_dt, note='u69; base and delete are GUESS stubs')
S(0x468090, 'ZCTRLIKLNKOBJ::~ZCTRLIKLNKOBJ', 'thiscall', None, ret='eax', gen=_dt, note='u69; base and delete are GUESS stubs')
