"""specs_c1006.py - camera batch 1006: FrameUpdate, ActivateCamera, AdjustForObstacles, ZFFCam::FrameUpdate."""
import struct
from pilot import S
from camgen import rnd, fbits, Log, handler, handler2, sys_with_mgr


def _fl(c, lo, hi, p=0.85):
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(lo, hi)))[0] if c.rng.random() < p else fbits(c)


def _mgr(c, log, g):
    s = sys_with_mgr(c, 0x100)
    m = c.emu.fake_object('mgr', 0x40, slots={0x58: handler(log, 0x58, 1, eax=g)})
    c.emu.w32(s + 0x9b, m)


def _focusgeom(c, log):
    r = c.rng
    if r.random() < 0.15:
        return 0
    g = c.emu.fake_object('focus', 0x900, slots={0x100: handler(log, 0x100, 1, eax=r.choice([0, rnd(c, 0xb20)])),
                                               0x84: handler(log, 0x84, 1, eax=r.getrandbits(32))})
    c.emu.wbytes(g + 4, bytes(r.getrandbits(8) for _ in range(0x8fc)))
    c.emu.w32(g + 0x85a, 0 if r.random() < 0.5 else rnd(c, 0xb20))
    return g


def _fu4a(c):
    log = Log(c)
    return [c.emu.fake_object('cam', 0x40, slots={0xc8: handler(log, 0xc8, 0, eax=c.rng.getrandbits(32))})]


S(0x4a95f0, 'ZFFCam::FrameUpdate', 'thiscall', gen=_fu4a)


def _fu(c):
    r = c.rng
    log = Log(c)
    for a in (0x4a95f0, 0x5cc420, 0x5cc330, 0x4fb800):
        c.emu.hook(a, handler(log, a, 0, eax=r.getrandbits(32)))
    cam = rnd(c, 0x800)
    c.emu.w8(cam + 0x5a, r.choice([0, 1, 1, 1]))
    c.emu.w8(cam + 0x7b0, r.choice([0, 0, 1]))
    _mgr(c, log, _focusgeom(c, log))
    return [cam]


S(0x5cb9f0, 'ZFFCamera1::FrameUpdate', 'thiscall', gen=_fu)


def _act(c):
    r = c.rng
    log = Log(c)
    c.emu.hook(0x5c96c0, handler(log, 0x5c96c0, 1, eax=r.getrandbits(32)))
    for a in (0x5cbe30, 0x5cbca0, 0x5d1440):
        c.emu.hook(a, handler(log, a, 0, eax=r.getrandbits(32)))
    cam = rnd(c, 0x800)
    c.emu.w8(cam + 0x4d7, r.choice([0, 0, 1]))
    _mgr(c, log, _focusgeom(c, log))
    return [cam, r.getrandbits(32)]


S(0x5cacf0, 'ZFFCamera1::ActivateCamera', 'thiscall', gen=_act)


def _afo(c):
    r = c.rng
    log = Log(c)
    cam = rnd(c, 0x800)
    for off in list(range(0x30c, 0x318, 4)) + list(range(0x444, 0x450, 4)):
        c.emu.w32(cam + off, _fl(c, -800, 800))
    c.emu.w32(cam + 0x4aa, _fl(c, 0, 900))
    c.emu.w32(cam + 0x2fa, _fl(c, 0, 50))
    for off in range(0x3b4, 0x3e4, 4):
        c.emu.w32(cam + off, _fl(c, -1, 1))
    c.emu.w32(cam + 0x44, c.emu.fake_object('geom', 0x40, slots={0x78: handler2(c, log, 0x78, 'v', eax=r.getrandbits(32))}))
    return [cam]


S(0x5cae30, 'ZFFCamera1::AdjustForObstacles', 'thiscall', gen=_afo)
