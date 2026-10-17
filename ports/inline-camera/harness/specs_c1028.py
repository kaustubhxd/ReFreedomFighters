"""specs_c1028.py - camera batch 1028: ZCamHelper::ControlBodyOni (first attempt; callees stubbed)."""
import struct
from pilot import S
from camgen import rnd, fbits, Log, handler, handler2, sys_with_mgr


def _fl(c, lo, hi, p=0.85):
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(lo, hi)))[0] if c.rng.random() < p else fbits(c)


def _cbo(c):
    r = c.rng
    log = Log(c, 512)
    for a, n in ((0x4e0830, 0),):
        pass
    hero_slots = {0x648: handler(log, 0x648, 1), 0x4d0: handler(log, 0x4d0, 0, eax=r.choice([0, 1])),
                  0x3f0: handler(log, 0x3f0, 0, eax=r.choice([0x11, 3])), 0x80: handler2(c, log, 0x80, 'O'),
                  0x5c0: handler2(c, log, 0x5c0, 'v'), 0x5d0: handler(log, 0x5d0, 0, eax=r.choice([0x10, 1, 0xf])),
                  0x438: handler(log, 0x438, 0, eax=0)}
    hero = c.emu.fake_object('hero', 0x900, slots=hero_slots)
    c.emu.wbytes(hero + 4, bytes(r.getrandbits(8) for _ in range(0x8fc)))
    c.emu.w8(hero + 0x600, r.choice([1, 1, 0]))
    c.emu.w8(hero + 0x66f, r.choice([0, 0, 1]))
    c.emu.w8(hero + 0x94e, r.choice([0, 1]))
    c.emu.w32(hero + 0x417, r.getrandbits(32))
    c.emu.w32(hero + 0x80b, _fl(c, 0, 5) if r.random() < 0.5 else 0)
    cam = rnd(c, 0xc00)
    for off in range(0xb11, 0xb50, 4):
        c.emu.w32(cam + off, _fl(c, -2, 2))
    c.emu.w8(cam + 0xb45, r.choice([0, 1]))
    c.emu.w8(cam + 0xb19, 0)
    c.emu.w32(cam + 0x44, hero)
    cam_slots = {0x90: handler2(c, log, 0x90, 'O'), 0x84: handler2(c, log, 0x84, 'v')}
    return [cam]


S(0x5ce0b0, 'ZCamHelper::ControlBodyOni (first attempt)', 'thiscall', gen=_cbo)
