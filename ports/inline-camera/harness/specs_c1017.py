"""specs_c1017.py - camera batch 1017: SetFocusSystemOni, ControlBody, ControlA."""
import struct
from pilot import S
from camgen import rnd, fbits, Log, handler, handler2, sys_with_mgr


def _fl(c, lo, hi, p=0.85):
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(lo, hi)))[0] if c.rng.random() < p else fbits(c)


def _sfo(c):
    r = c.rng
    log = Log(c)
    hero = c.emu.fake_object('hero', 0x420, slots={0x378: handler2(c, log, 0x378, 'F', eax=r.getrandbits(32)),
                                                  0x84: handler2(c, log, 0x84, 'v', eax=r.getrandbits(32))})
    c.emu.w32(hero + 0x417, r.getrandbits(32))
    h = rnd(c, 0xe40)
    c.emu.w32(h + 0x44, hero)
    cam = rnd(c, 0x500)
    c.emu.w32(cam + 0x4aa, _fl(c, 0, 300))
    c.emu.w32(h + 0xb54, cam)
    for off in range(0xc71, 0xcad, 4):
        c.emu.w32(h + off, _fl(c, -1, 1) if off >= 0xc89 else _fl(c, -500, 500))
    c.emu.w32(h + 0xae9, _fl(c, -3.2, 3.2))
    c.emu.w32(h + 0xaed, _fl(c, -1.3, 1.3))
    return [h]


S(0x5d2080, 'ZCamHelper::SetFocusSystemOni', 'thiscall', gen=_sfo)


def _cb(c):
    r = c.rng
    log = Log(c)
    for a in (0x5cdab0, 0x5ceb70, 0x5ceb30, 0x5cff20, 0x5d0080, 0x5cecd0):
        c.emu.hook(a, handler(log, a, 0, eax=r.getrandbits(32)))
    c.emu.hook(0x5cf420, handler(log, 0x5cf420, 1, eax=r.getrandbits(32)))
    hero = c.emu.fake_object('hero', 0x660, slots={0x80: handler(log, 0x80, 2, eax=r.getrandbits(32)),
                                                  0x438: handler(log, 0x438, 0, eax=lambda e: r.choice([0, 0, 1, 0x100]))})
    h = c.emu.fake_object('helper', 0xe40, slots={0x84: handler(log, 0x84, 0, eax=r.getrandbits(32))})
    c.emu.wbytes(h + 4, bytes(r.getrandbits(8) for _ in range(0xe3c)))
    c.emu.w32(h + 0x44, hero)
    c.emu.w8(h + 0xdd8, r.choice([0, 0, 1]))
    c.emu.w32(h + 0xe1c, r.choice([0, 1, 2, 3, 3]))
    g = c.emu.fake_object('camgeom', 0x10, slots={0x80: handler(log, 0x80, 2, eax=r.getrandbits(32))})
    s = sys_with_mgr(c, 0x100)
    m = c.emu.fake_object('mgr', 0x40, slots={0x58: handler(log, 0x58, 1, eax=g)})
    c.emu.w32(s + 0x9b, m)
    return [h]


S(0x5cdb70, 'ZCamHelper::ControlBody', 'thiscall', gen=_cb)


def _ca(c):
    r = c.rng
    log = Log(c)
    for a in (0x5d0c90, 0x5d0f10, 0x5d2eb0, 0x5d2ab0, 0x5d1530, 0x5d2280, 0x5cd890, 0x5cdc60, 0x5ce0b0, 0x5d2080):
        c.emu.hook(a, handler(log, a, 0, eax=r.getrandbits(32)))
    h = rnd(c, 0xe40)
    c.emu.w8(h + 0xb45, r.choice([0, 1]))
    c.emu.w32(h + 0xad5, r.choice([5, 1, 4]))
    return [h]


S(0x5cdab0, 'ZCamHelper::ControlA', 'thiscall', gen=_ca)
