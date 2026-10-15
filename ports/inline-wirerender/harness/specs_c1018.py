"""specs_c1018.py - camera batch 1018: ZFFCamera1 Reset, Init2, Load2, InitTestCam, MoveTestCameraWithGeom."""
import struct
from pilot import S as _S


def S(a, n, abi, ret=None, gen=None, **k):  # the camera thread's S(addr, name, abi, ret=, gen=) on the strict pilot's Spec
    _S(a, n, abi, None, ret=ret, gen=gen, note='wire-render; camera batch1018', **k)
from camgen import rnd, fbits, Log, handler, handler2, sys_with_mgr


def _fl(c, lo, hi, p=0.85):
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(lo, hi)))[0] if c.rng.random() < p else fbits(c)


def _cam(c, log, slots=None):
    r = c.rng
    cam = c.emu.fake_object('cam1', 0x800, slots=slots or {})
    c.emu.wbytes(cam + 4, bytes(r.getrandbits(8) for _ in range(0x7fc)))
    return cam


def _reset(c):
    r = c.rng
    log = Log(c)
    c.emu.hook(0x5c9da0, handler2(c, log, 0x5c9da0, 'v', eax=r.getrandbits(32)))
    c.emu.hook(0x5ca4c0, handler2(c, log, 0x5ca4c0, 'wv', eax=r.getrandbits(32)))
    cam = _cam(c, log, {s: handler(log, s, 0, eax=r.getrandbits(32)) for s in (0xb4, 0xb8, 0xbc)})
    return [cam]


S(0x5cc560, 'ZFFCamera1::Reset', 'thiscall', gen=_reset)


def _iter_list(c, log, k):
    """A level list object whose +0x18 iterator yields k entries (start slot 0x4c, next slot 0x5c, reset slot 0xc)."""
    r = c.rng

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
    l = rnd(c, 0x20)
    c.emu.w32(l + 0x18, c.emu.fake_object('iter', 0x10, slots={0x4c: start, 0x5c: nxt, 0xc: handler(log, 0xc, 0)}))
    return l


def _env(c, log, lists):
    r = c.rng
    s = sys_with_mgr(c, 0x1a00)
    focus = 0
    if r.random() < 0.85:
        focus = c.emu.fake_object('focus', 0x900, slots={0x100: handler(log, 0x100, 1, eax=r.choice([0, rnd(c, 0x20)])), 0xbc: handler(log, 0xbc, 1)})
        c.emu.w32(focus + 0x85a, r.choice([0, 0, rnd(c, 0x20)]))
    it = iter(lists)

    def wl(e, res):
        log.put(0x25c, e.reg('ecx'), e.arg32(0), e.arg32(1))
        e.ret(eax=next(it, 0), argbytes=8)
    world = c.emu.fake_object('world', 0x10, slots={0x25c: wl})
    geoms = {}

    def look(e, res):
        h = e.arg32(0)
        log.put(0x58, h)
        e.ret(eax=focus if r.random() < 0.5 else (c.emu.fake_object('g', 0x900, slots={0xbc: handler(log, 0xbc, 1), 0x100: handler(log, 0x100, 1, eax=0)}) if r.random() < 0.8 else 0), argbytes=4)
    m = c.emu.fake_object('mgr', 0xb00, slots={0x58: look})
    c.emu.w32(m + 0xadc, world)
    c.emu.w32(s + 0x9b, m)
    return s


def _init2(c):
    r = c.rng
    log = Log(c)
    lst = 0 if r.random() < 0.2 else _iter_list(c, log, r.randint(0, 4))
    if lst and r.random() < 0.1:
        c.emu.w32(lst + 0x18, 0)
    s = _env(c, log, [lst])
    box = rnd(c, 8)
    c.emu.w32(0x70038c, c.emu.fake_object('boxmgr', 0x10, slots={0xcc: handler(log, 0xcc, 1, eax=box)}))
    disp = c.emu.fake_object('disp', 0x10, slots={0xdc: handler(log, 0xdc, 0, eax=r.choice([0, 1, 0x100]))})
    c.emu.w32(s, c.emu.fake_vtable('sys', 0x30, {0xbc: handler(log, 0xbc0, 0, eax=disp)}))
    cl = c.emu.fake_object('camlist', 0x90, slots={0xc: handler(log, 0xc0c, 1)})
    c.emu.w8(cl + 0x83, r.choice([0, 1]))
    c.emu.w32(s + 0x190f, cl)
    cam = _cam(c, log)
    return [cam]


S(0x5cbad0, 'ZFFCamera1::Init2', 'thiscall', gen=_init2)


def _load2(c):
    r = c.rng
    log = Log(c)
    lst = 0 if r.random() < 0.2 else _iter_list(c, log, 0)
    _env(c, log, [lst])
    return [_cam(c, log)]


S(0x5cbf60, 'ZFFCamera1::Load2', 'thiscall', gen=_load2)


def _itc(c):
    r = c.rng
    log = Log(c)
    n = r.randint(0, 6)
    w = rnd(c, 0x420 + 4 * 8)
    c.emu.w32(w + 0x41c, n if r.random() < 0.9 else 0xffffffff)
    c.emu.w32(0x7003b8, w)
    lst = 0 if r.random() < 0.2 else _iter_list(c, log, r.randint(0, 4))
    if lst and r.random() < 0.1:
        c.emu.w32(lst + 0x18, 0)
    _env(c, log, [lst])
    return [_cam(c, log)]


S(0x5cbe30, 'ZFFCamera1::InitTestCam', 'thiscall', gen=_itc)


def _mtc(c):
    r = c.rng
    log = Log(c)
    c.emu.hook(0x5c9da0, handler2(c, log, 0x5c9da0, 'v', eax=r.getrandbits(32)))
    c.emu.hook(0x5ca460, handler2(c, log, 0x5ca460, 'v', eax=r.getrandbits(32)))
    c.emu.hook(0x5ca4c0, handler2(c, log, 0x5ca4c0, 'wv', eax=r.getrandbits(32)))
    c.emu.hook(0x5ccd10, handler(log, 0x5ccd10, 0, eax=r.getrandbits(32)))
    c.emu.hook(0x5ca140, handler(log, 0x5ca140, 0, eax=r.getrandbits(32)))
    cam = _cam(c, log)
    t = c.emu.fake_object('t', 0x10, slots={0x84: handler2(c, log, 0x84, 'v', eax=r.getrandbits(32))}) if r.random() < 0.85 else 0
    c.emu.w32(cam + 0x7b5, t)
    h = rnd(c, 0xd00)
    c.emu.w32(h + 0xb27, _fl(c, -1, 1))
    c.emu.w32(cam + 0x471, h)
    c.emu.w32(cam + 0x465, _fl(c, -2200, 0))
    return [cam]


S(0x5cc420, 'ZFFCamera1::MoveTestCameraWithGeom', 'thiscall', gen=_mtc)
