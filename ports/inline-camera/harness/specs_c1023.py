"""specs_c1023.py - camera batch 1023: ZShakeCamera."""
from pilot import S
from camgen import rnd, fbits, f32, Log, handler, handler2, sys_with_mgr


def _shaker(c, log):
    r = c.rng
    o = rnd(c, 0x70)
    c.emu.w32(o + 0x44, c.emu.fake_object('geom', 0x10, slots={0x84: handler2(c, log, 0x84, 'v', eax=r.getrandbits(32)),
                                                              0x130: _send(c, log)}))
    for off in (0x55, 0x59, 0x5d, 0x61):
        cam = 0 if r.random() < 0.25 else c.emu.fake_object('cam', 0x10, slots={0x230: handler(log, 0x230, 0, eax=r.choice([0, r.getrandbits(32)]))})
        c.emu.w32(o + off, cam)
    c.emu.w8(o + 0x54, r.choice([0, 1]))
    return o


def _send(c, log):
    def h(e, res):  # slot 0x130(receiver, id, data*): log the 5 floats of the message, not the stack pointer
        d = e.arg32(2)
        log.put(0x130, e.reg('ecx'), e.arg32(0), e.arg32(1), *[e.r32(d + 4 * i) for i in range(5)])
        e.ret(eax=0, argbytes=12)
    return h


def _names(c, log):
    r = c.rng
    s = sys_with_mgr(c, 0x100)
    names = c.emu.fake_object('names', 0x10, slots={0x88: handler2(c, log, 0x88, 'wW', eax=r.getrandbits(32))})
    cams = [0] + [c.emu.fake_object('cam', 0x10, slots={0x230: handler(log, 0x230, 0, eax=r.choice([0, r.getrandbits(32)]))})
                  for _ in range(3)]
    m = c.emu.fake_object('mgr', 0x140, slots={0x58: handler(log, 0x58, 1, eax=lambda e: r.choice(cams)),
                                              0x138: handler(log, 0x138, 0, eax=names)})
    c.emu.w32(s + 0x9b, m)


S(0x5d3780, 'ZShakeCamera::Shake', 'thiscall', gen=lambda c: [_shaker(c, Log(c))])


def _fc(c):
    log = Log(c)
    _names(c, log)
    return [rnd(c, 0x70)]


S(0x5d3520, 'ZShakeCamera::FindCameras', 'thiscall', gen=_fc)


def _cmd(c):
    log = Log(c)
    o = _shaker(c, log)
    msg = c.rng.getrandbits(16)
    c.emu.w16(o + 0x52, msg)
    return [o, (c.rng.getrandbits(16) << 16 | msg) if c.rng.random() < 0.6 else c.rng.getrandbits(32), 0]


S(0x5d3480, 'ZShakeCamera::Command', 'thiscall', ret='eax', gen=_cmd)


def _cd(c):
    log = Log(c)
    _names(c, log)
    o = _shaker(c, log)
    src = rnd(c, 0x70)
    return [o, src]


S(0x5d34a0, 'ZShakeCamera::CopyData', 'thiscall', gen=_cd)


def _ced(c):
    r = c.rng
    log = Log(c)

    def fl(e, res):
        log.put(0xf1, e.reg('ecx'))
        e.ret(st0=f32(c))
    c.emu.hook(0x4e5e80, fl)
    c.emu.hook(0x4e5e40, handler(log, 0xe40, 0, eax=lambda e: r.getrandbits(32)))
    c.emu.hook(0x4e5e60, handler(log, 0xe60, 0, eax=lambda e: r.choice([0, 1, 0x100, r.getrandbits(32)])))
    return [rnd(c, 0x70), rnd(c, 0x10)]


S(0x5d34e0, 'ZShakeCamera::CopyEventDataBlock', 'thiscall', gen=_ced)


def _init(c):
    log = Log(c)
    _names(c, log)
    return [_shaker(c, log)]


S(0x5d3640, 'ZShakeCamera::Init', 'thiscall', gen=_init)
