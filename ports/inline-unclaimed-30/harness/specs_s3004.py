"""specs_s3004.py - unclaimed-30 batch 4 (docs/20-unclaimed-30.md, claim 1): CFFTargetList::Init (0x5b23d0). The DBREAD u32
operator (0x4e5e60) is patched by serial_stubs.dbread_patch (a sequence of flags per run). The engine's message table, its
collision object (slots 0x25c, 0x294) and the returned objects (slots 0x154, 0x124, 0x218) are logged stubs; the object's +8 is a
zeroed sub-object for the exe's 0x4dc630. No faulting cases: all pointers are valid."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
import serial_stubs as ss


def _cfl(c):
    r = c.rng
    e = c.emu
    flags = [r.randint(0, 1) for _ in range(8)]
    ss.dbread_patch(c, flags, [0] * 8, [0] * 8)
    # the returned objects: o1 (found by name) or none (then o2 is made)
    def made(ret_slots):
        sub = ss.mkobj(c, {}, 0x40)
        o = ss.mkobj(c, ret_slots)
        e.w32(o + 8, sub)
        return o
    o2 = made({0x154: ss.rec(c, 0), 0x124: ss.rec(c, 4), 0x218: ss.rec(c, 1)})
    o1 = made({0x154: ss.rec(c, 0), 0x124: ss.rec(c, 4), 0x218: ss.rec(c, 1)})
    found = r.random() < 0.5
    coll = ss.mkobj(c, {0x25c: ss.rec(c, 2, ret=o1 if found else 0),
                        0x294: ss.rec(c, 4, ret=o2)})
    msg = e.alloc(0xb00)
    e.w32(msg + 0xadc, coll)
    sysi = e.alloc(0xa0)
    e.w32(sysi + 0x9b, msg)
    e.w32(0x70039c, sysi)
    self_ = ss.mkobj(c, {0x58: ss.rec(c, 0)})
    dbread = e.alloc(0x20)
    return [self_, r.getrandbits(32), dbread]


S(0x5b23d0, 'CFFTargetList::Init', 'thiscall', None, gen=_cfl, n=300)
