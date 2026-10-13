"""specs_c1000.py - camera batch 1000: getters and setters of ZFFCamera1, ZFFCam, ZBaseCamera, ZCAMERA."""
from pilot import S as _S


def S(a, n, abi, ret=None, gen=None, **k):  # the camera thread's S(addr, name, abi, ret=, gen=) on the strict pilot's Spec
    _S(a, n, abi, None, ret=ret, gen=gen, note='wire-render; camera batch1000', **k)
from camgen import rnd, fbits, Log, handler, sys_with_mgr


def _cam(c, n=0x500):
    return rnd(c, n)


def _is1st(c):
    cam = _cam(c)
    a = rnd(c, 0x50)
    b = rnd(c, 0x680)
    c.emu.w32(cam + 0x471, a)
    c.emu.w32(a + 0x44, b)
    return [cam]


S(0x5cbf50, 'ZFFCamera1::Is1stPerson', 'thiscall', ret='eax', gen=_is1st)
S(0x5cbac0, 'ZFFCamera1::GetQuality', 'thiscall', ret='st0', gen=lambda c: [_cam(c)])


def _curdist(c):
    cam = _cam(c)
    c.emu.w32(cam + 0x465, fbits(c))
    return [cam]


S(0x5cba90, 'ZFFCamera1::GetCurDist', 'thiscall', ret='st0', gen=_curdist)
S(0x5c9e60, 'ZFFCam::GetCameraPosition', 'thiscall', gen=lambda c: [_cam(c), rnd(c, 16)])
S(0x5c9ea0, 'ZFFCam::GetFocalPos', 'thiscall', gen=lambda c: [_cam(c), rnd(c, 16)])


def _focal(c):
    cam = _cam(c)
    log = Log(c)
    if c.rng.random() < 0.2:
        c.emu.w32(cam + 0x471, 0)
    else:
        o = c.emu.fake_object('owner', 0x40, slots={0x88: handler(log, 0x88, 1, eax=c.rng.getrandbits(32))})
        c.emu.w32(cam + 0x471, o)
    return [cam]


S(0x5cccf0, 'ZFFCamera1::UpdateFocalPoint', 'thiscall', gen=_focal)


def _mgr(c, log, hit):
    """Fake ZSysInterface whose +0x9b manager resolves handles (slot 0x58) to `hit` (or 0)."""
    s = sys_with_mgr(c)
    m = c.emu.fake_object('mgr', 0xb00, slots={0x58: handler(log, 0x58, 1, eax=hit)})
    c.emu.wbytes(m + 4, bytes(c.rng.getrandbits(8) for _ in range(0xafc)))
    c.emu.w32(s + 0x9b, m)
    return s, m


def _focusmat(c):
    cam = _cam(c)
    log = Log(c)
    g = 0
    if c.rng.random() < 0.8:
        g = c.emu.fake_object('geom', 0x40, slots={0x2b0: handler(log, 0x2b0, 2, eax=c.rng.getrandbits(32))})
    _mgr(c, log, g)
    return [cam]


S(0x5ca5b0, 'ZFFCam::UpdateFocusMatPos', 'thiscall', gen=_focusmat)
S(0x4fb550, 'ZBaseCamera::ActivateCamera', 'thiscall', gen=lambda c: [_cam(c, 0x80), c.rng.getrandbits(32)])
S(0x4fb570, 'ZBaseCamera::DeactivateCamera', 'thiscall', gen=lambda c: [_cam(c, 0x80)])
S(0x4fb580, 'ZBaseCamera::EnableCamera', 'thiscall', ret='al', gen=lambda c: [_cam(c, 0x80), c.rng.getrandbits(32)])
S(0x446d60, 'ZCAMERA::SetCameraRoot', 'thiscall', ret='eax', gen=lambda c: [_cam(c, 0x80), c.rng.getrandbits(32)])


def _getroot(c):
    cam = _cam(c, 0x80)
    log = Log(c)
    r = c.rng.random()
    c.emu.w32(cam + 0x1c, 0 if r < 0.25 else c.rng.getrandbits(32))
    hit = 0 if c.rng.random() < 0.3 else rnd(c, 16)
    _mgr(c, log, hit)
    return [cam]


S(0x445de0, 'ZCAMERA::GetCameraRoot', 'thiscall', ret='eax', gen=_getroot)


def _prio(c):
    cam = _cam(c, 0x80)
    log = Log(c)
    s = sys_with_mgr(c)
    nxt = 0
    for i in range(c.rng.randint(0, 5)):
        acc = c.rng.getrandbits(32)
        l = c.emu.fake_object('camlist', 0x20, slots={0xc0: handler(log, 0xc0, 1, eax=acc),
                                                      0xc4: handler(log, 0xc4, 2, eax=c.rng.getrandbits(32))})
        c.emu.w32(l + 8, nxt)
        nxt = l
    c.emu.w32(s + 0x190f, nxt)
    from pe_emu import F
    import struct
    f = struct.unpack('<f', struct.pack('<I', fbits(c)))[0]
    return [cam, F(f)]


S(0x446d00, 'ZCAMERA::SetCameraListPrio', 'thiscall', gen=_prio)
