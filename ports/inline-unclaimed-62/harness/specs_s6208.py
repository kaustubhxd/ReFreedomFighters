"""specs_s6208.py - unclaimed-62 claim 4 (slice 1): ZGeomIf::GetAngleToObject (0x501050). The parameter record's arrays are built valid
(0x5003d0 exe). The object's slot 0x194 (one argument) returns a float in ST0 (logged). The second array's tag byte is 0, 2, or other (the
error path, with the reporter's three words logged and a logged assert hook installed). No faulting cases."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from pfspec import rnd, sf
from specs_s6207 import reporter_all


def _arr(c, dword, tag):
    e = c.emu
    data = e.alloc(8 * 4)
    e.wbytes(data, bytes(c.rng.getrandbits(8) for _ in range(32)))
    e.w32(data, dword)
    e.w8(data + 4, tag)
    P = e.alloc(16)
    e.w32(P, data)
    e.w32(P + 8, 4)
    arr = e.alloc(16)
    e.w32(arr, P)
    e.w32(arr + 4, 0)
    e.w32(arr + 8, 1)
    return arr


def _gan(c):
    e = c.emu
    r = c.rng
    reporter_all(c, 3)
    fret = r.uniform(-50, 50)
    vt = e.fake_vtable('geomobj', 0x200, {0x194: None})
    def slot194(em, rr):
        em.calllog.append(('geomobj', 0x194, em.arg32(0)))
        em.ret(st0=sf(fret), argbytes=4)
    obj = e.alloc(0x40)
    e.w32(obj, e.fake_vtable('geomobj2', 0x200, {0x194: slot194}))
    self_ = rnd(c, 0x100)
    e.w32(self_ + 0xc, obj)
    p = rnd(c, 0x40)
    dword = r.choice([0, r.getrandbits(32) | 1])
    e.w32(p + 4, _arr(c, dword, 0))
    e.w32(p + 8, _arr(c, 0, r.choice([0, 2, 2, 5])))
    return [self_, p]


S(0x501050, 'ZGeomIf::GetAngleToObject', 'thiscall', None, gen=_gan, n=300)
