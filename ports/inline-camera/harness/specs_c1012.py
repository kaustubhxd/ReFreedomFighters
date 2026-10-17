"""specs_c1012.py - camera batch 1012: SetFocusSystemMouse."""
import struct
from pilot import S
from camgen import rnd, fbits, Log, handler, handler2


def _fl(c, lo, hi, p=0.85):
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(lo, hi)))[0] if c.rng.random() < p else fbits(c)


def _sfm(c):
    r = c.rng
    log = Log(c)
    hero = c.emu.fake_object('hero', 0x420, slots={0x378: handler2(c, log, 0x378, 'F', eax=r.getrandbits(32)),
                                                  0x84: handler2(c, log, 0x84, 'v', eax=r.getrandbits(32))})
    c.emu.w32(hero + 0x417, r.choice([0, 0x20000000]) | (r.getrandbits(32) & ~0x20000000))
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


S(0x5d1ea0, 'ZCamHelper::SetFocusSystemMouse', 'thiscall', gen=_sfm)


def _rpa(c):
    r = c.rng
    log = Log(c)
    from camgen import sys_with_mgr
    c.emu.hook(0x591b20, handler(log, 0x591b20, 0, eax=r.choice([9, 9, 9, 1])))
    c.emu.hook(0x5cf820, handler2(c, log, 0x5cf820, 'ffv', eax=r.getrandbits(32)))

    def cdecl(e, res):
        log.put(0x2c, e.arg32(0), e.arg32(1), e.arg32(2), e.arg32(3))
        e.ret(eax=0x1234)
    stream = c.emu.fake_object('stream', 0x10, slots={0x2c: cdecl})
    c.emu.w32(0x700390, c.emu.fake_object('dbg', 0x10, slots={0x20: handler(log, 0x20, 2, eax=stream)}))
    hero = c.emu.fake_object('hero', 0x850, slots={0x80: handler2(c, log, 0x80, 'wq', eax=r.getrandbits(32))})
    h = rnd(c, 0xe40)
    c.emu.w32(h + 0x44, hero)
    for off in range(0xa54, 0xa80, 4):
        c.emu.w32(h + off, _fl(c, -3.3, 3.3))
    c.emu.w8(h + 0xb1a, r.choice([0, 0, 1]))
    c.emu.w32(h + 0xbd1, r.choice([0, 0]))
    grp = 0
    if r.random() < 0.7:
        grp = rnd(c, 0x50)
        c.emu.w32(grp + 0x48, _fl(c, -4, 4))
    if r.random() < 0.5:
        c.emu.w32(h + 0xbd1, grp)
    g = c.emu.fake_object('mgobj', 0x10, slots={0x100: handler(log, 0x100, 1, eax=grp)})
    s = sys_with_mgr(c, 0x100)
    c.emu.w32(s + 0x48, _fl(c, 0, 0.1))
    m = c.emu.fake_object('mgr', 0x40, slots={0x58: handler(log, 0x58, 1, eax=g)})
    c.emu.w32(s + 0x9b, m)
    return [h]


S(0x5d1530, 'ZCamHelper::RestrictPointerAngle', 'thiscall', gen=_rpa)
