"""specs_s263.py - area 22, batch263 (src/batch263.cpp): ZMoveOnSpline::CopyDataBlock and CFireController::CFireController.
The DBLK readers are hooked by address (GUESS stubs, logged): Get(unsigned*) writes the next per-case word to its target
(the target address is not logged: two of them are stack slots), GetType returns the next per-case type, Get(bool*)
writes a byte, NextBlock and ZGROUP::CopyDataBlock only log. The base constructor 0x469870 runs as exe code (verified in
inline-mountedgun). The base constructor reads and updates the float at engine db +0xae0
and registers the object (db vt[0x30]). The two message-id words at 0x714270/0x714274 are cleared before each case."""
import struct
from pilot import S
from helpers22 import _rnd, _multi_vt, _hk


def _r(c):
    return c.rng.getrandbits(32)


def _g_512850(c):
    e = c.emu
    words = [_r(c) for _ in range(5)]
    types = [c.rng.choice([8, 8, 3, 0, 0x108]) for _ in range(3)]

    def get(em, r):
        dst = em.arg32(0)
        em.calllog.append(('DBLK::Get', 0x4e12e0, None, (em.arg32(1),)))
        em.w32(dst, words.pop(0) if words else 0x5151)
        em.ret(eax=0, argbytes=8)

    def getb(em, r):
        dst = em.arg32(0)
        em.calllog.append(('DBLK::GetBool', 0x4e14a0, None, (dst, em.arg32(1))))
        em.wbytes(dst, bytes([c.rng.choice([0, 1])]))
        em.ret(eax=0, argbytes=8)
    e.hook(0x4e12e0, get)
    e.hook(0x4e14a0, getb)
    _hk(c, 0x4e1600, 'DBLK::GetType', 0, eax=lambda em: (types.pop(0) if types else 0) | 0x5500)
    _hk(c, 0x4e1b30, 'DBLK::NextBlock', 0)
    _hk(c, 0x43f900, 'ZGROUP::CopyDataBlock', 1)
    db = _rnd(c, 0x40)
    e.w32(db, _multi_vt(c, {0x58: (lambda em, a: (a[0] ^ 0x1111, None), 1)}))
    rm = _rnd(c, 0x100)
    e.w32(rm + 0x9b, db)
    e.w32(0x70039c, rm)
    e.mu.ctl_flush_tb()
    return [_rnd(c, 0x140), _rnd(c, 0x20)]


def _g_581410(c):
    e = c.emu
    gl = _rnd(c, 0x2c60)
    e.w32(0x7003b8, gl)
    db = _rnd(c, 0xb00)
    e.w32(db, _multi_vt(c, {0x114: (lambda em, a: (_r(c), None), 4), 0x30: (lambda em, a: (0, None), 1)}))
    e.w32(db + 0xae0, struct.unpack('<I', struct.pack('<f', c.rng.uniform(0.0, 1.2)))[0])   # read by the base ctor
    m = 0
    if c.rng.random() < 0.7:
        m = _rnd(c, 0x10)
        e.w32(m, _multi_vt(c, {0x68: (lambda em, a, v=_r(c): (v, None), 1)}))
    rm = _rnd(c, 0x1b00)
    e.w32(rm + 0x9b, db)
    e.w32(rm + 0x1a9f, m)
    e.w32(0x70039c, rm)
    e.wbytes(0x714270, bytes(8))
    e.mu.ctl_flush_tb()
    return [_rnd(c, 0xa80)]


S(0x512850, 'ZMoveOnSpline::CopyDataBlock', 'thiscall', None, ret=None, gen=_g_512850,
  note='batch263; void; DBLK readers hooked (GUESS stubs)')
S(0x581410, 'CFireController::CFireController', 'thiscall', None, ret='eax', gen=_g_581410,
  note='batch263; base ctor 0x469870 as exe code; SEH frame and cookie not reproduced')
