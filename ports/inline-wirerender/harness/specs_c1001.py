"""specs_c1001.py - camera batch 1001: ZFFCam focus transforms, position setters, focal point."""
from pilot import S as _S


def S(a, n, abi, ret=None, gen=None, **k):  # the camera thread's S(addr, name, abi, ret=, gen=) on the strict pilot's Spec
    _S(a, n, abi, None, ret=ret, gen=gen, note='wire-render; camera batch1001', **k)
from camgen import rnd, fbits, Log, handler, sys_with_mgr


def _cam(c):
    cam = rnd(c, 0x500)
    for off in range(0x2f6, 0x460, 4):
        c.emu.w32(cam + off, fbits(c))  # float fields (unaligned ones overlap; fine)
    return cam


def _vec(c, n=3):
    v = c.emu.alloc(4 * n + 4, 4)
    for i in range(n + 1):
        c.emu.w32(v + 4 * i, fbits(c))
    return v


def _geom(c, log, slots):
    return c.emu.fake_object('geom', 0x40, slots={s: handler(log, s, 1, eax=c.rng.getrandbits(32)) for s in slots})


def _mgr(c, log, hits):
    s = sys_with_mgr(c)
    it = iter(hits)
    m = c.emu.fake_object('mgr', 0x40, slots={0x58: handler(log, 0x58, 1, eax=lambda e: next(it, 0))})
    c.emu.w32(s + 0x9b, m)


def _xf(c):
    return [_cam(c), _vec(c)]


S(0x5c9da0, 'ZFFCam focus->world (unnamed)', 'thiscall', gen=_xf)
S(0x5c9e00, 'ZFFCam world->focus (unnamed)', 'thiscall', gen=_xf)


def _slot(off):
    def g(c):
        log = Log(c)
        geo = _geom(c, log, [off]) if c.rng.random() < 0.8 else 0
        _mgr(c, log, [geo])
        return [_cam(c), _vec(c)]
    return g


S(0x5c9dd0, 'ZFFCam focus geom slot 0x84 (unnamed)', 'thiscall', gen=_slot(0x84))
S(0x5c9e30, 'ZFFCam focus geom slot 0x8c (unnamed)', 'thiscall', gen=_slot(0x8c))
S(0x5c9e90, 'ZFFCam::GetCurDist', 'thiscall', ret='st0', gen=lambda c: [_cam(c)])
S(0x5c9ed0, 'ZFFCam::GetGlobalFocalPoint', 'thiscall', gen=lambda c: [_cam(c), rnd(c, 16)])
S(0x5c9f00, 'ZFFCam::GetQuality', 'thiscall', ret='st0', gen=lambda c: [_cam(c)])
S(0x5c9f10, 'ZFFCam::GetVectFromFocal', 'thiscall', gen=lambda c: [_cam(c), rnd(c, 16)])


def _init(c):
    log = Log(c)
    c.emu.hook(0x4fb040, handler(log, 0x4fb040, 0, eax=c.rng.getrandbits(32)))
    return [_cam(c)]


S(0x5c9f30, 'ZFFCam::Init', 'thiscall', gen=_init)
S(0x5ca460, 'ZFFCam SetCamPos (unnamed)', 'thiscall', gen=_xf)


def _place(c):
    log = Log(c)
    cam = _cam(c)
    c.emu.w32(cam + 0x44, _geom(c, log, [0x78, 0x7c]))
    return [cam, _vec(c)]


S(0x5ca490, 'ZFFCam SetCamPosAndPlace (unnamed)', 'thiscall', gen=_place)


def _matpos(c):
    log = Log(c)
    cam = _cam(c)
    c.emu.w32(cam + 0x44, c.emu.fake_object('geom', 0x40, slots={0x7c: handler(log, 0x7c, 2)}))
    return [cam, _vec(c, 9), _vec(c)]


S(0x5ca4c0, 'ZFFCam SetCamMatPos (unnamed)', 'thiscall', gen=_matpos)


def _ufp(c):
    log = Log(c)
    hits = [_geom(c, log, [0x84, 0x8c]) if c.rng.random() < 0.8 else 0 for _ in range(2)]
    _mgr(c, log, hits)
    return [_cam(c)]


S(0x5ca520, 'ZFFCam::UpdateFocalPoint', 'thiscall', gen=_ufp)
