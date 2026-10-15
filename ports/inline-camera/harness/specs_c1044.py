"""specs_c1044.py - camera batch 1044: ZCAMERA::Load.

Stub values are pure functions of the destination pointer (the same in both builds: the same case gives the same
addresses), never RNG draws inside a handler, so both runs see identical data."""
from pilot import S
from camgen import rnd, Log, sys_with_mgr


def _mix(x):
    return ((x * 2654435761) ^ 0x9e3779b9) & 0xffffffff


def _load(c):
    log = Log(c, 512)
    cam = rnd(c, 0x200)

    def cam_slot40(e, res):
        log.put(0x40c)
        e.ret(argbytes=0)

    c.emu.w32(cam, c.emu.fake_vtable('cam', 0x44 // 4, {0x40: cam_slot40}))
    sub = rnd(c, 0x40)
    c.emu.w32(cam + 0x10, sub)

    def inside(p):
        return cam <= p < cam + 0x200

    def read(tag, size):
        def h(e, res):
            dest = e.arg32(0)
            log.put(tag)
            if dest == cam + 0x2c:             # the list count: keep it small
                c.emu.w32(dest, _mix(dest) % 4)
            elif inside(dest):
                for k in range(0, size, 4):
                    c.emu.w32(dest + k, _mix(dest + k + tag))
            else:                              # a stack temporary: the same fixed value in both builds
                c.emu.w32(dest, 0x51)
            e.ret(argbytes=4)
        return h

    def read_raw(e, res):
        dest = e.arg32(0)
        n = e.arg32(1)
        log.put(0x18, n)
        for k in range(0, n, 4):
            c.emu.w32(dest + k, _mix(dest + k + 0x18))
        e.ret(argbytes=8)

    load = rnd(c, 0x40)
    c.emu.w32(load, c.emu.fake_vtable('load', 0x70 // 4, {
        0x40: read(0x40, 4),
        0x48: read(0x48, 4),
        0x50: read(0x50, 4),
        0x68: read(0x68, 4),
        0x6c: read(0x6c, 12),
        0x18: read_raw,
    }))

    s = sys_with_mgr(c, 0x200)
    mgr = rnd(c, 0x40)

    def m54(e, res):
        log.put(0x54, e.arg32(0))
        e.ret(eax=_mix(e.arg32(0) + 0x54), argbytes=4)

    def m58(e, res):
        log.put(0x58, e.arg32(0))
        e.ret(eax=_mix(e.arg32(0) + 0x58), argbytes=4)

    c.emu.w32(mgr, c.emu.fake_vtable('mgr', 0x5c // 4 + 1, {0x54: m54, 0x58: m58}))
    c.emu.w32(s + 0x9b, mgr)
    c.emu.w32(cam + 0x2c, 0)
    return [cam, load]


S(0x446040, 'ZCAMERA::Load', 'thiscall', gen=_load)
