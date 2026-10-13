"""specs_c1008.py - camera batch 1008: InitCamboxDist, lower limit."""
import struct
from pilot import S
from camgen import rnd, fbits, Log, handler, handler2, sys_with_mgr, _boxenv


def _fl(c, lo, hi, p=0.85):
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(lo, hi)))[0] if c.rng.random() < p else fbits(c)


def _icd(c):
    r = c.rng
    log = Log(c)
    c.emu.unhook(0x5ccba0)
    _boxenv(c, log)
    cam = rnd(c, 0x800)
    c.emu.w32(cam + 0x489, _fl(c, 0, 600))
    k = r.randint(0, 5)

    def start(e, res):
        log.put(0x4c, e.reg('ecx'))
        e.w32(e.arg32(0), k)
        e.ret(eax=r.getrandbits(32), argbytes=4)

    def nxt(e, res):
        it = e.arg32(0)
        v = e.r32(it)
        log.put(0x5c, e.reg('ecx'), v)
        e.w32(it, v - 1 if v else 0)
        e.ret(eax=r.getrandbits(32), argbytes=4)
    x = r.random()
    if x < 0.15:
        c.emu.w32(cam + 0x475, 0)
    else:
        l = rnd(c, 0x20)
        if x < 0.25:
            c.emu.w32(l + 0x18, 0)
        else:
            c.emu.w32(l + 0x18, c.emu.fake_object('boxiter', 0x10, slots={0x4c: start, 0x5c: nxt}))
        c.emu.w32(cam + 0x475, l)
    return [cam]


S(0x5cbca0, 'ZFFCamera1::InitCamboxDist (inferred)', 'thiscall', gen=_icd)


def _low(c):
    r = c.rng
    log = Log(c)
    cam = rnd(c, 0x800)
    for off in list(range(0x30c, 0x318, 4)) + list(range(0x3b4, 0x3e4, 4)):
        c.emu.w32(cam + off, _fl(c, -2, 2) if off >= 0x3b4 else _fl(c, -800, 800))
    c.emu.w32(cam + 0x4aa, _fl(c, 0, 1500))
    hero = rnd(c, 0x420)
    c.emu.w32(hero + 0x417, r.choice([0, 0x8000000]) | (r.getrandbits(32) & ~0x8000000))
    helper = rnd(c, 0x50)
    c.emu.w32(helper + 0x44, hero)
    c.emu.w32(cam + 0x471, helper)
    g = c.emu.fake_object('focus', 0x40, slots={0x84: handler2(c, log, 0x84, 'v', eax=r.getrandbits(32)),
                                               0x8c: handler2(c, log, 0x8c, 'v', eax=r.getrandbits(32))})
    s = sys_with_mgr(c, 0x100)
    m = c.emu.fake_object('mgr', 0x40, slots={0x58: handler(log, 0x58, 1, eax=g)})
    c.emu.w32(s + 0x9b, m)
    return [cam]


S(0x5cc200, 'ZFFCamera1 lower limit (inferred LowerCollisionCheck)', 'thiscall', gen=_low)
