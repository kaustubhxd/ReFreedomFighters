"""specs_c1071.py - camera batch 1071: ZCAMERA::GetScreenSelect (0x445e90).

The object's slots 0x84 and 0x88 log their query vector; the manager's +0xadc object (slot 0x2e0) fills the hit record
(a position at +0x28..+0x30, an id at +0x44) from the query pointer and returns a hit flag chosen in the generator
(the same in both builds); the manager's slot 0x54 accepts an id by a fixed rule. The vector add 0x43e8e0 runs as original code."""
import struct
from pilot import S
from camgen import rnd, Log, sys_with_mgr


def _fl(c, lo, hi):
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(lo, hi)))[0]


def _mix(x):
    return ((x * 2654435761) ^ 0x9e3779b9) & 0xffffffff


def _gss(c):
    log = Log(c, 256)
    r = c.rng
    self_ = rnd(c, 0x200)
    c.emu.w32(self_ + 0x64, _fl(c, -40, 40))
    c.emu.w32(self_ + 0x68, _fl(c, -40, 40))
    hit = r.random() < 0.6
    accept = r.random() < 0.7
    ids = _mix(r.getrandbits(16))
    pos = [_fl(c, -4.0, 4.0) for _ in range(3)]   # the hit position (constants: the query pointer is a stack address)

    def v84(e, res):
        p = e.arg32(0)
        log.put(0x84, *[c.emu.r32(p + 4 * k) for k in range(3)])
        e.ret(argbytes=4)

    def v88(e, res):
        p = e.arg32(0)
        log.put(0x88, *[c.emu.r32(p + 4 * k) for k in range(3)])
        e.ret(argbytes=4)

    c.emu.w32(self_, c.emu.fake_vtable('camss', 0x8c // 4 + 1, {0x84: v84, 0x88: v88}))

    def v2e0(e, res):
        p = e.arg32(0)
        log.put(0x2e0, e.arg32(2), e.arg32(3), e.arg32(4), e.arg32(5))
        if hit:
            for k in range(3):
                c.emu.w32(p + 0x28 + 4 * k, pos[k])
            c.emu.w32(p + 0x44, ids)
        e.ret(eax=1 if hit else 0, argbytes=24)

    obj2 = rnd(c, 0x40)
    c.emu.w32(obj2, c.emu.fake_vtable('mgr2', 0x2e4 // 4, {0x2e0: v2e0}))
    s = sys_with_mgr(c, 0x2000)
    mgr = rnd(c, 0x1000)
    c.emu.w32(mgr + 0xadc, obj2)
    c.emu.w32(s + 0x9b, mgr)

    def v54(e, res):
        log.put(0x54, e.arg32(0))
        e.ret(eax=1 if accept else 0, argbytes=4)

    c.emu.w32(mgr, c.emu.fake_vtable('mgr', 0x58 // 4, {0x54: v54}))
    out = rnd(c, 0x20)
    return [self_, out, 0, r.randint(0, 5), _fl(c, -5.0, 5.0)]


S(0x445e90, 'ZCAMERA::GetScreenSelect', 'thiscall', gen=_gss)
