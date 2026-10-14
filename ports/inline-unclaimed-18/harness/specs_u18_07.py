"""specs_u18_07.py - area 18, group 7 (unclaimed-18 thread)."""
import struct
from pilot import S
from ckit import rnd


def _delete(e, r):
    e.calllog.append(('delete', e.arg32(0), e.arg32(1)))
    e.ret(argbytes=0)


def _base(name):
    def h(e, r):
        e.calllog.append((name, e.reg('ecx')))
        e.ret()
    return h


def _dtor(c, base_addr, name, vt_size):
    e = c.emu
    e.hook(0x634273, _delete)
    e.hook(base_addr, _base(name))
    o = rnd(c, 0x80)
    return [o, c.rng.getrandbits(32)]


S(0x4cd210, 'LINKSORTREFTAB::~LINKSORTREFTAB', 'thiscall', None, ret='eax',
  gen=lambda c: _dtor(c, 0x4cce40, 'base4cce40', 0x2c), note='u18; base cleanup is a logging hook')
S(0x51fc90, 'ZPmvIf::~ZPmvIf', 'thiscall', None, ret='eax',
  gen=lambda c: _dtor(c, 0x51b020, 'base51b020', 0x24), note='u18; base cleanup is a logging hook')


def _rrp(c):
    o = rnd(c, 0x40)
    run = rnd(c, 0x20)
    return [o, run]


S(0x4cf150, 'LINKREFTAB::RunInitPrevRef', 'thiscall', None, ret=None, gen=_rrp, note='u18')
