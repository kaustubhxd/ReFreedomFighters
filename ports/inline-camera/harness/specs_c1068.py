"""specs_c1068.py - camera batch 1068: ZFFCam::CheckCollisions (0x5c9ba0).

The collision-ray casts go through the manager's +0xadc object (slot 0x2e0, a hit flag per ray). The hit is a fixed
function of the ray's start address, chosen in the generator, so both builds see the same answers. The object's own
slot 0xc4 is a logging stub. 0x5c9910 (the ray set-up) and the vector helpers run as original code."""
import struct
from pilot import S
from camgen import rnd, Log, sys_with_mgr, fbits
import specs_c1067


def _fl(c, lo, hi):
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(lo, hi)))[0]


def _cc(c):
    log = Log(c, 256)
    r = c.rng
    self_ = rnd(c, 0x900)
    c.emu.w32(self_ + 0x68, r.randint(0, 4))
    c.emu.w32(self_ + 0x2fa, _fl(c, -2.0, 2.0) if r.random() < 0.9 else 0)
    c.emu.w32(self_ + 0x2f6, _fl(c, 0.0, 6.0))
    for off in (0x78, 0x7c, 0x80, 0x30c, 0x310, 0x314, 0x444, 0x448, 0x44c):
        c.emu.w32(self_ + off, _fl(c, -40, 40))
    for k in range(0, 0x2e5 - 0x6c, 4):
        c.emu.w32(self_ + 0x6c + k, _fl(c, -40, 40) if r.random() < 0.8 else fbits(c))
    for k in range(5):
        c.emu.w32(self_ + 0xd9 + 0x82 * k, _fl(c, 0.0, 400.0))
    c.emu.w32(self_ + 0x30a, r.getrandbits(8) & 1)

    # the hit answer for each ray start (the three-word offset at +0x6c and each record's +0x6c)
    hits = {}
    for k in range(5):
        hits[self_ + 0x82 * k + 0x6c] = r.random() < 0.6
    hits[self_ + 0x6c] = r.random() < 0.6

    def v2e0(e, res):
        p = e.arg32(0)
        log.put(0x2e0, e.arg32(1), e.arg32(2), e.arg32(3), e.arg32(4), e.arg32(5))
        e.ret(eax=1 if hits.get(p, False) else 0, argbytes=24)

    def v_c4(e, res):
        log.put(0xc4)
        e.ret(argbytes=0)

    obj2 = rnd(c, 0x40)
    c.emu.w32(obj2, c.emu.fake_vtable('mgr2', 0x2e4 // 4, {0x2e0: v2e0}))
    s = sys_with_mgr(c, 0x2000)
    mgr = rnd(c, 0x1000)
    c.emu.w32(mgr + 0xadc, obj2)
    c.emu.w32(s + 0x9b, mgr)

    selfvt = c.emu.fake_vtable('camself', 0xc8 // 4 + 1, {0xc4: v_c4})
    c.emu.w32(self_, selfvt)

    # the object at +0x44 for 0x5c9910 (its slot 0x88 logs the ray); the ray set-up is the exe's code
    def v88(e, res):
        p = e.arg32(0)
        log.put(0x88, *[c.emu.r32(p + 4 * k) for k in range(3)])
        e.ret(argbytes=4)
    o44 = rnd(c, 0x80)
    c.emu.w32(o44, c.emu.fake_vtable('o44', 0x8c // 4 + 1, {0x88: v88}))
    c.emu.w32(self_ + 0x44, o44)
    return [self_]


S(0x5c9ba0, 'ZFFCam::CheckCollisions', 'thiscall', gen=_cc)
