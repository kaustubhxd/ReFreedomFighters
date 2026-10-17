"""specs_c1045.py - camera batch 1045: ZCAMERA::Save.

Save-slot handlers log their arguments only (no RNG draws in a handler). The manager's slot 0x4c is a pure
function of its argument. List entries are small objects holding their handle word at +0x54."""
from pilot import S
from camgen import rnd, Log, sys_with_mgr


def _mix(x):
    return ((x * 2654435761) ^ 0x9e3779b9) & 0xffffffff


def _save(c):
    log = Log(c, 512)
    r = c.rng
    cam = rnd(c, 0x200)
    for i in range(2):   # the list is +0x24..+0x2b; the count word at +0x2c follows it
        obj = rnd(c, 0x60)
        c.emu.w32(obj + 0x54, r.getrandbits(32))
        c.emu.w32(cam + 0x24 + 4 * i, obj)
    c.emu.w32(cam + 0x2c, r.choice([0, 1, 2]))
    rp = rnd(c, 0x40)
    c.emu.w32(rp + 0x18, r.getrandbits(32))
    c.emu.w32(cam + 0x10, rp)

    def w_val(tag):
        def h(e, res):
            log.put(tag, e.arg32(0))
            e.ret(argbytes=4)
        return h

    def w_vec(e, res):
        p = e.arg32(0)
        log.put(0x68, *[c.emu.r32(p + 4 * k) for k in range(3)])
        e.ret(argbytes=4)

    def w_raw(e, res):
        p = e.arg32(0)
        n = e.arg32(1)
        log.put(0x10, n, *[c.emu.r32(p + 4 * k) for k in range(4)])
        e.ret(argbytes=8)

    save = rnd(c, 0x40)
    c.emu.w32(save, c.emu.fake_vtable('save', 0x70 // 4, {
        0x3c: w_val(0x3c), 0x44: w_val(0x44), 0x4c: w_val(0x4c), 0x60: w_val(0x60),
        0x68: w_vec, 0x10: w_raw,
    }))

    mgr = rnd(c, 0x40)

    def m4c(e, res):
        log.put(0x4c, e.arg32(0))
        e.ret(eax=_mix(e.arg32(0) + 0x4c), argbytes=4)

    c.emu.w32(mgr, c.emu.fake_vtable('mgr', 0x50 // 4, {0x4c: m4c}))
    s = sys_with_mgr(c, 0x200)
    c.emu.w32(s + 0x9b, mgr)
    return [cam, save]


S(0x4464e0, 'ZCAMERA::Save', 'thiscall', gen=_save)
