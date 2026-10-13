"""specs_c1003.py - camera batch 1003: ZFFCamera1::ChangeZoomLevel."""
import struct
from pilot import S as _S


def S(a, n, abi, ret=None, gen=None, **k):  # the camera thread's S(addr, name, abi, ret=, gen=) on the strict pilot's Spec
    _S(a, n, abi, None, ret=ret, gen=gen, note='wire-render; camera batch1003', **k)
from camgen import rnd, fbits, f32, Log, handler, sys_with_mgr


def _czl(c):
    r = c.rng
    log = Log(c)
    vals = [f32(c) if r.random() < 0.3 else r.uniform(0, 600) for _ in range(2)]
    if r.random() < 0.2:
        vals[1] = vals[0]
    it = iter(vals)
    cam = c.emu.fake_object('cam1', 0x800, slots={0xac: handler(log, 0xac, 0, st0=None)})
    vt = c.emu.r32(cam)
    # slot 0xac returns a float in ST0; rebuild that slot with the value sequence
    def h(e, res):
        log.put(0xac, e.reg('ecx'))
        e.ret(st0=next(it))
    c.emu.w32(vt + 0xac, c.emu.stub_fn('GetCurDist', h))
    c.emu.wbytes(cam + 4, bytes(r.getrandbits(8) for _ in range(0x7fc)))
    for off in range(0x451, 0x4c0, 4):
        c.emu.w32(cam + off, fbits(c))
    c.emu.w32(cam + 0x46d, struct.unpack('<I', struct.pack('<f', r.uniform(0, 0.6)))[0] if r.random() < 0.7 else fbits(c))
    c.emu.w32(cam + 0x479, struct.unpack('<I', struct.pack('<f', vals[0]))[0] if r.random() < 0.3 else fbits(c))
    c.emu.w8(cam + 0x4ca, r.choice([0, 1, 0x40]))
    mode = r.choice(list(range(0, 14)) + [r.getrandbits(32)])
    c.emu.w32(cam + 0x4dc, mode)
    c.emu.w32(cam + 0x4e0, mode if r.random() < 0.5 else r.choice(list(range(14))))
    c.emu.w8(cam + 0x598, r.choice([0, 0, 1]))
    c.emu.w8(cam + 0x599, r.choice([0, 0, 1]))
    hero = rnd(c, 0x420)
    helper = rnd(c, 0x50)
    c.emu.w32(helper + 0x44, hero)
    c.emu.w32(cam + 0x471, helper)
    s = sys_with_mgr(c, 0x1c00)
    c.emu.w32(s + 0x1b5d, r.choice([0, 0, 1, r.getrandbits(32)]))
    return [cam]


S(0x5cb190, 'ZFFCamera1::ChangeZoomLevel', 'thiscall', gen=_czl)
