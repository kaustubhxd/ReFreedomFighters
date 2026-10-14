"""specs_c1047.py - camera batch 1047: ZFFCameraClass::Load and ::Save wrappers.

Stub values depend only on destination pointers or the argument (identical in both builds). The camera part runs
the original ZCAMERA::Load / Save, so the same fake state as specs_c1044 and specs_c1045 is set up here."""
from pilot import S
from camgen import rnd, Log, sys_with_mgr


def _mix(x):
    return ((x * 2654435761) ^ 0x9e3779b9) & 0xffffffff


def _setup(c, log, cam):
    """Camera part shared by both wrappers: the room object, the manager, and the list count."""
    rp = rnd(c, 0x40)
    c.emu.w32(cam + 0x10, rp)
    s = sys_with_mgr(c, 0x200)
    mgr = rnd(c, 0x40)

    def m54(e, res):
        log.put(0x54, e.arg32(0))
        e.ret(eax=_mix(e.arg32(0) + 0x54), argbytes=4)

    def m58(e, res):
        log.put(0x58, e.arg32(0))
        e.ret(eax=_mix(e.arg32(0) + 0x58), argbytes=4)

    def m4c(e, res):
        log.put(0x4c, e.arg32(0))
        e.ret(eax=_mix(e.arg32(0) + 0x4c), argbytes=4)

    c.emu.w32(mgr, c.emu.fake_vtable('mgr', 0x5c // 4 + 1, {0x4c: m4c, 0x54: m54, 0x58: m58}))
    c.emu.w32(s + 0x9b, mgr)
    return s


def _load_gen(c):
    log = Log(c, 512)
    cam = rnd(c, 0x200)
    cam_vt = c.emu.fake_vtable('cam', 0x44 // 4, {0x40: lambda e, r: (log.put(0x40c), e.ret(argbytes=0))})
    c.emu.w32(cam, cam_vt)
    c.emu.w32(cam + 0x2c, 1)
    _setup(c, log, cam)
    load = rnd(c, 0x40)

    def inside(p):
        return cam <= p < cam + 0x200

    def read(tag, size):
        def h(e, res):
            dest = e.arg32(0)
            log.put(tag)
            if dest == cam + 0x2c:
                c.emu.w32(dest, _mix(dest) % 4)
            elif inside(dest):
                for k in range(0, size, 4):
                    c.emu.w32(dest + k, _mix(dest + k + tag))
            else:
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

    c.emu.w32(load, c.emu.fake_vtable('load', 0x78 // 4, {
        0x40: read(0x40, 4), 0x48: read(0x48, 4), 0x50: read(0x50, 4),
        0x68: read(0x68, 4), 0x6c: read(0x6c, 12), 0x74: read(0x74, 36), 0x18: read_raw,
    }))
    # The wrapper's own object: the same camera block, fields at +0x197..+0x1c0 (inside cam's 0x200 bytes).
    return [cam, load]


def _save_gen(c):
    log = Log(c, 512)
    r = c.rng
    cam = rnd(c, 0x200)
    c.emu.w32(cam + 0x2c, r.choice([0, 1, 2]))
    for i in range(2):
        obj = rnd(c, 0x60)
        c.emu.w32(obj + 0x54, r.getrandbits(32))
        c.emu.w32(cam + 0x24 + 4 * i, obj)
    cam_vt = c.emu.fake_vtable('cam', 0x44 // 4, {0x40: lambda e, res: (log.put(0x40c), e.ret(argbytes=0))})
    c.emu.w32(cam, cam_vt)
    _setup(c, log, cam)

    def w_val(tag):
        def h(e, res):
            log.put(tag, e.arg32(0))
            e.ret(argbytes=4)
        return h

    def w_vec(e, res):
        p = e.arg32(0)
        log.put(0x68, *[c.emu.r32(p + 4 * k) for k in range(3)])
        e.ret(argbytes=4)

    def w_mat(e, res):
        p = e.arg32(0)
        log.put(0x70, *[c.emu.r32(p + 4 * k) for k in range(3)])
        e.ret(argbytes=4)

    save = rnd(c, 0x40)
    c.emu.w32(save, c.emu.fake_vtable('save', 0x78 // 4, {
        0x3c: w_val(0x3c), 0x44: w_val(0x44), 0x4c: w_val(0x4c), 0x60: w_val(0x60), 0x64: w_val(0x64),
        0x68: w_vec, 0x70: w_mat,
        0x10: lambda e, res: (log.put(0x10, e.arg32(1)), e.ret(argbytes=8)),
    }))
    return [cam, save]


S(0x5b2300, 'ZFFCameraClass::Load', 'thiscall', gen=_load_gen)
S(0x5b2370, 'ZFFCameraClass::Save', 'thiscall', gen=_save_gen)
