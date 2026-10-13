"""specs_c1009.py - camera batch 1009: ZFFCam::ActivateCamera, ZFFCam::UpdateVars."""
import struct
from pilot import S as _S


def S(a, n, abi, ret=None, gen=None, **k):  # the camera thread's S(addr, name, abi, ret=, gen=) on the strict pilot's Spec
    _S(a, n, abi, None, ret=ret, gen=gen, note='wire-render; camera batch1009', **k)
from camgen import rnd, fbits, Log, handler, handler2, sys_with_mgr


def _fl(c, lo, hi, p=0.85):
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(lo, hi)))[0] if c.rng.random() < p else fbits(c)


def _act(c):
    r = c.rng
    log = Log(c)
    c.emu.hook(0x4fb550, handler(log, 0x4fb550, 1, eax=r.getrandbits(32)))
    cam = c.emu.fake_object('cam', 0x800, slots={0xc8: handler(log, 0xc8, 0, eax=r.getrandbits(32))})
    c.emu.wbytes(cam + 4, bytes(r.getrandbits(8) for _ in range(0x7fc)))
    names = c.emu.fake_object('names', 0x10, slots={0x88: handler2(c, log, 0x88, 'wW', eax=r.getrandbits(32))})
    g = c.emu.fake_object('maincam', 0x10, slots={0x80: handler(log, 0x80, 2, eax=r.getrandbits(32))}) if r.random() < 0.8 else 0
    s = sys_with_mgr(c, 0x100)
    m = c.emu.fake_object('mgr', 0x40, slots={0x58: handler(log, 0x58, 1, eax=g), 0x138: handler(log, 0x138, 0, eax=names)})
    c.emu.w32(s + 0x9b, m)
    return [cam, r.getrandbits(32)]


S(0x5c96c0, 'ZFFCam::ActivateCamera', 'thiscall', gen=_act)


def _uv(c):
    r = c.rng
    log = Log(c)
    cam = c.emu.fake_object('cam', 0x800, slots={0xb4: handler(log, 0xb4, 0, eax=r.getrandbits(32)),
                                                 0xb8: handler(log, 0xb8, 0, eax=r.getrandbits(32))})
    c.emu.wbytes(cam + 4, bytes(r.getrandbits(8) for _ in range(0x7fc)))
    for off in range(0x390, 0x450, 4):
        c.emu.w32(cam + off, _fl(c, -500, 500))
    if r.random() < 0.15:
        c.emu.w32(cam + 0x60, 0)
    else:
        ctl = rnd(c, 0x50)
        c.emu.w32(cam + 0x60, ctl)
    g = 0
    if r.random() < 0.85:
        g = c.emu.fake_object('focus', 0x10, slots={
            0x80: handler(log, 0x80, 2, eax=r.getrandbits(32)), 0x84: handler(log, 0x84, 1, eax=r.getrandbits(32)),
            0x88: handler(log, 0x88, 1, eax=r.getrandbits(32)), 0x390: handler(log, 0x390, 1, eax=r.getrandbits(32)),
            0x3a0: handler(log, 0x3a0, 2, eax=r.getrandbits(32))})
    s = sys_with_mgr(c, 0x100)
    c.emu.w32(s + 0x48, r.choice([0, 0x80000000, _fl(c, 0, 0.1)]))
    m = c.emu.fake_object('mgr', 0x40, slots={0x58: handler(log, 0x58, 1, eax=g)})
    c.emu.w32(s + 0x9b, m)
    return [cam]


S(0x5ca5f0, 'ZFFCam::UpdateVars', 'thiscall', gen=_uv)
