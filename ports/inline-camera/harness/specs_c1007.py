"""specs_c1007.py - camera batch 1007: CalcCollisionParameters, CheckCollisions."""
import struct
from pilot import S
from camgen import rnd, fbits, Log, handler, handler2, sys_with_mgr


def _fl(c, lo, hi, p=0.85):
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(lo, hi)))[0] if c.rng.random() < p else fbits(c)


def _ccp(c):
    r = c.rng
    log = Log(c)
    cam = rnd(c, 0x800)
    for off in list(range(0x30c, 0x318, 4)) + list(range(0x444, 0x450, 4)):
        c.emu.w32(cam + off, _fl(c, -800, 800))
    c.emu.w32(cam + 0x2fa, _fl(c, 0, 50))
    c.emu.w32(cam + 0x44, c.emu.fake_object('geom', 0x40, slots={0x88: handler2(c, log, 0x88, 'v', eax=r.getrandbits(32))}))
    return [cam]


S(0x5caf80, 'ZFFCamera1::CalcCollisionParameters', 'thiscall', gen=_ccp)


def _cc(c):
    r = c.rng
    log = Log(c)
    c.emu.hook(0x4dc630, handler(log, 0x4dc630, 2, eax=r.getrandbits(32)))
    c.emu.hook(0x5cc200, handler(log, 0x5cc200, 0, eax=r.getrandbits(32)))
    pole = 0
    if r.random() < 0.6:
        pole = rnd(c, 0x10)
        c.emu.w32(pole + 8, rnd(c, 0x40))
    c.emu.hook(0x5c1650, handler(log, 0x5c1650, 0, eax=pole))
    cam = c.emu.fake_object('cam1', 0x800, slots={0xc0: handler(log, 0xc0, 0, eax=r.getrandbits(32)),
                                                  0xc4: handler(log, 0xc4, 0, eax=r.getrandbits(32))})
    c.emu.wbytes(cam + 4, bytes(r.getrandbits(8) for _ in range(0x7fc)))
    for off in range(0x6c, 0x2f0, 4):
        c.emu.w32(cam + off, _fl(c, 0, 2000))
    c.emu.w32(cam + 0x68, r.choice([0, 1, 2, 3, 3, r.choice([-1, -2, -3, -5, 6])]))
    helper = rnd(c, 0xe00)
    c.emu.w8(helper + 0xdd8, r.choice([0, 1]))
    c.emu.w32(cam + 0x471, helper)
    focus = rnd(c, 0x20)
    c.emu.w32(focus + 8, rnd(c, 0x40))
    world = c.emu.fake_object('world', 0x10, slots={0x2e0: handler(log, 0x2e0, 6, eax=lambda e: r.getrandbits(32))})
    s = sys_with_mgr(c, 0x100)
    m = c.emu.fake_object('mgr', 0xb00, slots={0x58: handler(log, 0x58, 1, eax=focus)})
    c.emu.w32(m + 0xadc, world)
    c.emu.w32(s + 0x9b, m)
    return [cam]


S(0x5cb480, 'ZFFCamera1::CheckCollisions', 'thiscall', ret='al', gen=_cc)
