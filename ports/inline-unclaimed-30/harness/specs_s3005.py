"""specs_s3005.py - unclaimed-30 batch 5 (docs/20-unclaimed-30.md, claim 1): CMsgForwardToActors::Init (0x49f010). The DBREAD word
operator (0x4e5e40) is patched by serial_stubs.dbread_patch; the DBREAD float read (0x4e5e80) is patched with a stub that returns
a value in ST0. The message table's collision object (slot 0x25c, logged) returns the object or 0; the reporter (pfspec) takes the
error text. No faulting cases."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
import serial_stubs as ss
from pfspec import reporter


def _fwd(c):
    r = c.rng
    e = c.emu
    reporter(c, 0.0)
    ss.dbread_patch(c, [0] * 8, [r.getrandbits(16) for _ in range(8)], [0] * 8)
    fv = e.alloc(4)
    e.wf32(fv, c.fv(-100, 100))
    ss.patch(c, 0x4e5e80, ss.code(c, b'\xd9\x05' + struct.pack('<I', fv) + b'\xc3'))
    o = ss.mkobj(c, {})
    found = r.random() < 0.5
    coll = ss.mkobj(c, {0x25c: ss.rec(c, 2, ret=o if found else 0)})
    msg = e.alloc(0xb00)
    e.w32(msg + 0xadc, coll)
    sysi = e.alloc(0xa0)
    e.w32(sysi + 0x9b, msg)
    e.w32(0x70039c, sysi)
    self_ = ss.mkobj(c, {}, 0x60)
    if r.random() < 0.3:
        e.w8(self_ + 4, e.r8(self_ + 4) | 2)
    else:
        e.w8(self_ + 4, e.r8(self_ + 4) & 0xfd)
    dbread = e.alloc(0x20)
    return [self_, r.getrandbits(32), dbread]


S(0x49f010, 'CMsgForwardToActors::Init', 'thiscall', None, gen=_fwd, n=300)
