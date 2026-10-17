"""specs_c1029.py - camera batch 1029: GetRecruitPosPrecisionAim, GetRecruitScoutPosColi.
Find3DPointerPos and Find3DPointerShadowPos are the original code (ext_), so the fake world is only a line test."""
import struct
from pilot import S
from camgen import rnd, fbits, Log, handler, handler2, sys_with_mgr


def _fl(c, lo, hi, p=0.85):
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(lo, hi)))[0] if c.rng.random() < p else fbits(c)


def _helper(c, log):
    r = c.rng
    h = rnd(c, 0xf00)
    for off in range(0xa40, 0xe20, 4):
        c.emu.w32(h + off, _fl(c, -500, 500, 0.6))
    c.emu.w32(h + 0xa4c, r.choice([0, 1, 2]))
    def dist(e, res):  # camera distance: float in ST0
        log.put(0xac, e.reg('ecx'))
        e.ret(st0=r.uniform(0, 600))
    cam = c.emu.fake_object('cam', 0x10, slots={0xac: dist})
    c.emu.w32(h + 0xb54, cam)
    hero = c.emu.fake_object('hero', 0x1000, slots={})
    c.emu.w32(hero + 8, rnd(c, 0x60))  # geometry the original Find3D reads (+0x3c flags)
    def tracked_ok(e, res):  # vslot 0x220(this, pt): logs only the tag (the pointer argument is a stack address)
        log.put(0x220)
        e.ret(eax=r.choice([0, 1]), argbytes=4)
    c.emu.w32(hero + 0xecb, r.choice([0, c.emu.fake_object('tracked', 0x10, slots={0x220: tracked_ok})]))
    c.emu.w32(h + 0x44, hero)
    s = sys_with_mgr(c, 0x100)
    world = c.emu.fake_object('world', 0x10, slots={0x2e0: handler(log, 0x2e0, 6, eax=r.getrandbits(32))})
    m = c.emu.fake_object('mgr', 0xb00, slots={})
    c.emu.w32(m + 0xadc, world)
    c.emu.w32(s + 0x9b, m)
    return h


def _pa(c):
    log = Log(c)
    h = _helper(c, log)
    return [h, rnd(c, 16)]


S(0x5cfa00, 'ZCamHelper::GetRecruitPosPrecisionAim', 'thiscall', ret='al', gen=_pa)


def _sc(c):
    log = Log(c)
    h = _helper(c, log)
    return [h, rnd(c, 16)]


S(0x5cfb10, 'ZCamHelper::GetRecruitScoutPosColi', 'thiscall', gen=_sc)
