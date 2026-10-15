"""specs_c1042.py - camera batch 1042: ZCAMERA::Draw."""
import struct
from pilot import S
from camgen import rnd, Log


def _fl(c, lo, hi):
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(lo, hi)))[0]


def _draw(c):
    log = Log(c)
    r = c.rng

    def h_vec(e, res):
        vec = e.arg32(2)
        log.put(0xc0, e.arg32(0), e.arg32(1), *[c.emu.r32(vec + 4 * k) for k in range(3)])
        e.ret(argbytes=12)

    def h_draw(e, res):
        log.put(0xbc, e.arg32(0), e.arg32(1), e.arg32(2), e.arg32(3))
        e.ret(argbytes=16)

    a1 = rnd(c, 0x40)
    c.emu.w32(a1, c.emu.fake_vtable('draw', 0xc4 // 4, {0xc0: h_vec, 0xbc: h_draw}))
    cam = rnd(c, 0x200)
    c.emu.w32(cam + 0x14, r.choice([0, 1, 1, 0x09, 0x11, 0x19, 0xff]))
    c.emu.w32(cam + 0x5c, _fl(c, 0.1, 3.0) if r.random() < 0.9 else 0)
    c.emu.w32(cam + 0x40, _fl(c, 0.5, 3.0) if r.random() < 0.9 else 0)
    return [cam, a1, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x445ca0, 'ZCAMERA::Draw', 'thiscall', gen=_draw)
