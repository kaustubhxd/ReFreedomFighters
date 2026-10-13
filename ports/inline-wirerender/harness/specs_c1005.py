"""specs_c1005.py - camera batch 1005: ZFFCamera1::DoChangeDistance."""
import struct
from pilot import S as _S


def S(a, n, abi, ret=None, gen=None, **k):  # the camera thread's S(addr, name, abi, ret=, gen=) on the strict pilot's Spec
    _S(a, n, abi, None, ret=ret, gen=gen, note='wire-render; camera batch1005', **k)
from camgen import rnd, fbits, Log, handler, sys_with_mgr


def _fl(c, lo, hi, p=0.8):
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(lo, hi)))[0] if c.rng.random() < p else fbits(c)


def _dcd(c):
    r = c.rng
    log = Log(c)
    c.emu.hook(0x662330, handler(log, 0x662330, 3, eax=r.getrandbits(32)))
    c.emu.hook(0x5d0bd0, handler(log, 0x5d0bd0, 3, eax=r.getrandbits(32)))
    cam = rnd(c, 0x600)
    for off in range(0x451, 0x4b6, 4):
        c.emu.w32(cam + off, _fl(c, -600, 600))
    c.emu.w8(cam + 0x4ca, r.choice([0, 1, 1, 0x20]))
    c.emu.w8(cam + 0x598, r.choice([0, 1, 1]))
    c.emu.w8(cam + 0x599, r.choice([0, 1]))
    c.emu.w32(cam + 0x4dc, r.choice([4, 5, 12, r.getrandbits(32)]))
    s = sys_with_mgr(c, 0x100)
    now = r.getrandbits(31)
    c.emu.w32(s + 0x40, now)
    c.emu.w32(cam + 0x4b6, (now + r.randint(-3, 3)) & 0xffffffff if r.random() < 0.7 else r.getrandbits(32))
    zc = rnd(c, 0x80)
    c.emu.w32(cam + 0x44, zc)
    hero = rnd(c, 0x680)
    c.emu.w8(hero + 0x67a, r.choice([0, 0, 0, 1]))
    helper = rnd(c, 0xb00)
    c.emu.w32(helper + 0xaed, _fl(c, -0.6, 0.6, 0.9))
    c.emu.w32(helper + 0x44, hero)
    c.emu.w32(cam + 0x471, helper)
    return [cam]


S(0x5cb7a0, 'ZFFCamera1::DoChangeDistance (inferred)', 'thiscall', gen=_dcd)


def _mcg(c):
    from camgen import handler2
    r = c.rng
    log = Log(c)
    c.emu.hook(0x5c9da0, handler2(c, log, 0x5c9da0, 'v', eax=r.getrandbits(32)))
    c.emu.hook(0x5ca460, handler2(c, log, 0x5ca460, 'v', eax=r.getrandbits(32)))
    for a, n in ((0x5ccd10, 0), (0x5ca4c0, 2), (0x5cb410, 0), (0x5cb7a0, 0), (0x5cb190, 0)):
        c.emu.hook(a, handler(log, a, n, eax=r.getrandbits(32)))
    cam = c.emu.fake_object('cam1', 0x800, slots={0xbc: handler(log, 0xbc, 0, eax=r.getrandbits(32))})
    c.emu.wbytes(cam + 4, bytes(r.getrandbits(8) for _ in range(0x7fc)))
    for off in range(0x45d, 0x4b2, 4):
        c.emu.w32(cam + off, _fl(c, 0, 2000))
    if r.random() < 0.3:
        c.emu.w32(cam + 0x481, c.emu.r32(cam + 0x485 if r.random() < 0.5 else cam + 0x479))
    c.emu.w8(cam + 0x4ca, r.choice([0, 1]))
    c.emu.w8(cam + 0x30a, r.choice([0, 1]))
    return [cam]


S(0x5cc330, 'ZFFCamera1::MoveCameraWithGeom', 'thiscall', gen=_mcg)
