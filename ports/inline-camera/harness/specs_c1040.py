"""specs_c1040.py - camera batch 1040: ZCAMERA::SetCamTaget."""
import struct
from pilot import S
from camgen import rnd, fbits, Log


def _fl(c, lo, hi):
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(lo, hi)))[0]


def _vec3(c, lo=-300, hi=300):
    r = c.rng
    if r.random() < 0.15:
        return [0, 0, 0]
    return [_fl(c, lo, hi) if r.random() < 0.9 else fbits(c) for _ in range(3)]


def _set_cam_taget(c):
    log = Log(c)
    r = c.rng

    def vt(e, res):
        ptr = e.arg32(0)
        log.put(0x6c, *[c.emu.r32(ptr + 4 * k) for k in range(3)])
        e.ret(argbytes=4)

    cam = rnd(c, 0x200)
    c.emu.w32(cam, c.emu.fake_vtable('cam', 0x70 // 4, {0x6c: vt}))
    sub = rnd(c, 0x80)
    c.emu.w32(cam + 8, sub)
    for i, w in enumerate(_vec3(c)):
        c.emu.w32(sub + 0x24 + 4 * i, w)
    mat = rnd(c, 0x40)
    for i in range(9):
        c.emu.w32(mat + 4 * i, _fl(c, -2, 2) if r.random() < 0.9 else fbits(c))
    c.emu.w32(sub + 0x50, mat)
    p = rnd(c, 0x20)
    for i, w in enumerate(_vec3(c)):
        c.emu.w32(p + 4 * i, w)
    return [cam, p, 0]


S(0x446b50, 'ZCAMERA::SetCamTaget', 'thiscall', gen=_set_cam_taget)
