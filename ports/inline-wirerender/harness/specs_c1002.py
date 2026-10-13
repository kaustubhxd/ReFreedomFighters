"""specs_c1002.py - camera batch 1002: sniper zoom, close-up, camera boxes, commands, LookAtFocal, ResetCamPos."""
import struct
from pilot import S as _S


def S(a, n, abi, ret=None, gen=None, **k):  # the camera thread's S(addr, name, abi, ret=, gen=) on the strict pilot's Spec
    _S(a, n, abi, None, ret=ret, gen=gen, note='wire-render; camera batch1002', **k)
from camgen import rnd, fbits, Log, handler, handler2, sys_with_mgr, _boxenv

FOVS = [0x3d8efa34, 0x3ed67750, 0x3d8efa33, 0x3d8efa35, 0x3ed6774f, 0x3ed67751]


def _fov(c):
    r = c.rng.random()
    if r < 0.3:
        return c.rng.choice(FOVS)
    if r < 0.8:
        return struct.unpack('<I', struct.pack('<f', c.rng.uniform(0.0, 0.6)))[0]
    return fbits(c)


def _cam(c):
    cam = rnd(c, 0x800)
    for off in range(0x2f6, 0x4c0, 4):
        c.emu.w32(cam + off, fbits(c))
    return cam


def _tap(c):
    cam = _cam(c)
    c.emu.w32(cam + 0x46d, _fov(c))
    return [cam]


S(0x5cca60, 'ZFFCamera1::SniperTapZoomIn', 'thiscall', gen=_tap)
S(0x5ccaa0, 'ZFFCamera1::SniperTapZoomOut', 'thiscall', gen=_tap)


def _hold(c):
    cam = _cam(c)
    zc = rnd(c, 0x80)
    c.emu.w32(zc + 0x5c, _fov(c))
    c.emu.w32(cam + 0x44, zc)
    c.emu.w8(cam + 0x598, c.rng.choice([0, 0, 1, 0xff]))
    s = sys_with_mgr(c, 0x100)
    c.emu.w32(s + 0x48, fbits(c) if c.rng.random() < 0.2 else struct.unpack('<I', struct.pack('<f', c.rng.uniform(0, 0.1)))[0])
    return [cam]


S(0x5ccae0, 'ZFFCamera1::SniperZoomIn', 'thiscall', gen=_hold)
S(0x5ccb40, 'ZFFCamera1::SniperZoomOut', 'thiscall', gen=_hold)


def _closeup(c):
    log = Log(c)
    c.emu.hook(0x5cb190, handler(log, 0x5cb190, 0, eax=c.rng.getrandbits(32)))
    cam = _cam(c)
    c.emu.w8(cam + 0x4ca, c.rng.choice([0, 1, 0x80]))
    s = sys_with_mgr(c, 0x100)
    return [cam, c.rng.choice([0, 1, 0x100, 0x101, c.rng.getrandbits(32)])]


S(0x5cc880, 'ZFFCamera1::SetCloseUp', 'thiscall', gen=_closeup)


def _testbox(c):
    log = Log(c)
    _boxenv(c, log)
    return [_cam(c), c.rng.getrandbits(32)]


S(0x5ccba0, 'ZFFCamera1::TestBox', 'thiscall', gen=_testbox)


def _camboxes(c):
    log = Log(c)
    _boxenv(c, log)
    cam = _cam(c)
    if c.rng.random() < 0.2:
        c.emu.w32(cam + 0x475, 0)
    else:
        inner = c.emu.fake_object('boxiter', 0x10, slots={
            0x4c: handler(log, 0x4c, 1, eax=c.rng.getrandbits(32)),
            0x5c: handler(log, 0x5c, 1, eax=c.rng.getrandbits(32))})
        l = rnd(c, 0x20)
        c.emu.w32(l + 0x18, inner)
        c.emu.w32(cam + 0x475, l)
    c.emu.w32(cam + 0x59c, c.rng.choice([0, 0, c.rng.getrandbits(32)]))
    return [cam]


S(0x5cb410, 'ZFFCamera1::CheckCamBoxes', 'thiscall', gen=_camboxes)


def _init1(c):
    log = Log(c)
    c.emu.hook(0x5c9f30, handler(log, 0x5c9f30, 0, eax=c.rng.getrandbits(32)))
    return [_cam(c)]


S(0x5cbc80, 'ZFFCamera1::Init', 'thiscall', gen=_init1)


def _cmd(c):
    log = Log(c)
    c.emu.hook(0x5cc900, handler(log, 0x5cc900, 3, eax=c.rng.getrandbits(32)))
    c.emu.hook(0x4fb260, handler(log, 0x4fb260, 2, eax=c.rng.getrandbits(32)))
    cam = _cam(c)
    msg = c.rng.getrandbits(16)
    c.emu.w16(cam + 0x59a, msg)
    cmd = (c.rng.getrandbits(16) << 16 | msg) if c.rng.random() < 0.5 else c.rng.getrandbits(32)
    data = c.emu.alloc(0x20, 4)
    for i in range(8):
        c.emu.w32(data + 4 * i, fbits(c))
    return [cam, cmd, data]


S(0x5cb750, 'ZFFCamera1::Command', 'thiscall', ret='eax', gen=_cmd)


def _follow(c):
    log = Log(c)
    cam = _cam(c)
    n = c.rng.choice([0, 1, 2, 5])
    c.emu.w32(cam + 0x5ac, n)
    for i in range(8):
        c.emu.w32(cam + 0x5b0 + 4 * i, c.rng.getrandbits(32))
    if n:
        k = c.rng.randint(0, n - 1)
        c.emu.w32(cam + 0x7b1, cam + 0x5b0 + 4 * k)
    s = sys_with_mgr(c, 0x100)
    m = c.emu.fake_object('mgr', 0x40, slots={0x58: handler(log, 0x58, 1, eax=c.rng.getrandbits(32))})
    c.emu.w32(s + 0x9b, m)
    return [cam]


S(0x5ccc80, 'ZFFCamera1::TestCamNextFollow', 'thiscall', gen=_follow)


def _roomhint(c):
    log = Log(c)
    c.emu.hook(0x4fb610, handler(log, 0x4fb610, 0, eax=c.rng.getrandbits(32)))
    c.emu.hook(0x4fb680, handler(log, 0x4fb680, 0, eax=c.rng.getrandbits(32)))
    o = c.emu.fake_object('cam', 0x100, slots={0x88: handler(log, 0x88, 0, eax=c.rng.getrandbits(32))})
    return [o]


S(0x4fb800, 'ZBaseCamera::CalcRoomHint', 'thiscall', gen=_roomhint)


def _look(c):
    log = Log(c)
    cam = _cam(c)
    c.emu.w32(cam + 0x44, c.emu.fake_object('geom', 0x40, slots={
        0x78: handler(log, 0x78, 1), 0x7c: handler(log, 0x7c, 2)}))
    return [cam]


S(0x5ca140, 'ZFFCam::LookAtFocal (inferred)', 'thiscall', gen=_look)
S(0x5ca1c0, 'ZFFCam::ResetCamPos', 'thiscall', gen=_look)
