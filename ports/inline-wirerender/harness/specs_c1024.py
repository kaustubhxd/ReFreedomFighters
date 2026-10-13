"""specs_c1024.py - camera batch 1024: CCameraBox, ZBaseCamera command and room hints."""
from pilot import S as _S


def S(a, n, abi, ret=None, gen=None, **k):  # the camera thread's S(addr, name, abi, ret=, gen=) on the strict pilot's Spec
    _S(a, n, abi, None, ret=ret, gen=gen, note='wire-render; camera batch1024', **k)
from camgen import rnd, fbits, f32, Log, handler, handler2, sys_with_mgr


def _cdecl(log, tag, nargs, eax=None):
    def h(e, r):
        log.put(tag, *[e.arg32(i) for i in range(nargs)])
        e.ret(eax=eax(e) if callable(eax) else eax)
    return h


def _end(c):
    log = Log(c)
    c.emu.hook(0x634273, _cdecl(log, 0x634273, 2, eax=0))
    return [rnd(c, 0x60)]


S(0x5c7d90, 'CCameraBox::End', 'thiscall', gen=_end)
S(0x5c7da0, 'CCameraBox::FrameUpdate', 'thiscall',
  gen=lambda c: [c.emu.fake_object('box', 0x60, slots={0x68: handler(Log(c), 0x68, 2, eax=c.rng.getrandbits(32))})])


def _ced(c):
    log = Log(c)

    def fl(e, res):
        log.put(0xf1, e.reg('ecx'))
        e.ret(st0=f32(c))
    c.emu.hook(0x4e5e80, fl)
    return [rnd(c, 0x60), rnd(c, 0x10)]


S(0x5d86b0, 'CCameraBox::CopyEventDataBlock', 'thiscall', gen=_ced)


def _reftab(c, log):
    r = c.rng
    t = c.emu.fake_object('reftab', 0x20, slots={0x20: handler(log, 0x20, 1, eax=r.choice([0, 0, 1])),
                                                0xac: handler(log, 0xac, 1, eax=r.getrandbits(32))})
    cb = c.emu.stub_fn('refcb', handler(log, 0xcb, 0, eax=r.getrandbits(32)))
    c.emu.w32(t + 8, r.choice([0, cb]))
    c.emu.w32(t + 0xc, r.choice([0, 0x20000000, 0x7fffffff]))
    c.emu.w32(t + 0x10, r.choice([0, 0x7fffffff, 0x20000000]))
    c.emu.w32(0x70038c, t)


def _init(c):
    r = c.rng
    log = Log(c)
    _reftab(c, log)
    c.emu.hook(0x4dc630, handler(log, 0x4dc630, 2, eax=r.getrandbits(32)))

    def new(e, res):
        n = e.arg32(0)
        log.put(0x41e290, n)
        p = 0
        if r.random() < 0.9:
            pre = c.emu.alloc(n + 8, 4)
            c.emu.w32(pre + 4, r.choice([0, r.getrandbits(32)]))
            p = pre + 8
        e.ret(eax=p)
    c.emu.hook(0x41e290, new)
    lst = c.emu.fake_object('zlist', 0x20, slots={0x154: handler(log, 0x154, 0), 0x124: handler(log, 0x124, 4),
                                                 0x21c: handler(log, 0x21c, 1)})
    c.emu.w32(lst + 8, rnd(c, 0x40))
    world = c.emu.fake_object('world', 0x10, slots={0x25c: handler(log, 0x25c, 2, eax=r.choice([0, lst])),
                                                   0x294: handler(log, 0x294, 4, eax=lst)})
    s = sys_with_mgr(c, 0x100)
    m = c.emu.fake_object('mgr', 0xb00, slots={0x4c: handler(log, 0x4c, 1, eax=r.getrandbits(32))})
    c.emu.w32(m + 0xadc, world)
    c.emu.w32(s + 0x9b, m)
    return [rnd(c, 0x60)]


S(0x5c7db0, 'CCameraBox::Init', 'thiscall', gen=_init)


def _cmd(c):
    r = c.rng
    log = Log(c)

    def q(e, res):
        log.put(0x98, e.reg('ecx'))
        e.ret(st0=f32(c))
    cam = c.emu.fake_object('cam', 0x60, slots={0x98: q, 0x9c: handler(log, 0x9c, 1), 0xa0: handler(log, 0xa0, 0),
                                               0xa4: handler(log, 0xa4, 1), 0xa8: handler(log, 0xa8, 0)})
    ids = [r.getrandbits(16) for _ in range(6)]
    for off, v in zip((0x48, 0x4c, 0x4e, 0x50, 0x52, 0x58), ids):
        c.emu.w16(cam + off, v)
    cmd = r.choice(ids + [r.getrandbits(16)]) | (r.getrandbits(16) << 16)
    return [cam, cmd, rnd(c, 8)]


S(0x4fb260, 'ZBaseCamera::Command', 'thiscall', ret='eax', gen=_cmd)


def _room_geom(c, log):
    r = c.rng
    rl = rnd(c, 0x20)
    c.emu.w8(rl + 0x1c, r.choice([0, 1]))
    x = rnd(c, 0x10)
    c.emu.w32(x + 8, r.choice([0, rnd(c, 0x20)]))
    c.emu.hook(0x4db550, handler(log, 0x4db550, 0, eax=r.choice([0, rl])))
    g = c.emu.fake_object('ctlgeom', 0x10, slots={0x1e0: handler(log, 0x1e0, 1, eax=r.choice([0, 1, 0x100])),
                                                 0x20: handler(log, 0x20, 0, eax=x),
                                                 0x84: handler2(c, log, 0x84, 'v', eax=0)})
    return g


def _cam_with_ctl(c, log, slots=None):
    r = c.rng
    cam = c.emu.fake_object('cam', 0x60, slots=slots or {})
    ctl = rnd(c, 0x50)
    c.emu.w32(cam + 0x5c, ctl if r.random() < 0.9 else 0)
    c.emu.w32(cam + 0x44, c.emu.fake_object('zcam', 0x10, slots={0x284: handler(log, 0x284, 1)}))
    return cam


def _rh1(c):
    log = Log(c)
    g = _room_geom(c, log)
    s = sys_with_mgr(c, 0x100)
    m = c.emu.fake_object('mgr', 0x40, slots={0x58: handler(log, 0x58, 1, eax=g)})
    c.emu.w32(s + 0x9b, m)
    cam = _cam_with_ctl(c, log)
    c.emu.w32(cam + 0x5c, rnd(c, 0x50))  # a null control would make the original call through 0
    return [cam]


S(0x4fb610, 'ZBaseCamera room hint 1st person (unnamed)', 'thiscall', gen=_rh1)


def _rh3(c):
    r = c.rng
    log = Log(c)
    g = _room_geom(c, log)
    c.emu.hook(0x4dc130, handler(log, 0x4dc130, 0, eax=r.choice([0, r.getrandbits(32)])))
    x = c.emu.fake_object('x', 0x10, slots={0x14: handler(log, 0x14, 0, eax=r.choice([0, 1])),
                                           0x30: handler(log, 0x30, 1, eax=r.getrandbits(32))})
    b = c.emu.fake_object('b', 0x10, slots={0x234: handler(log, 0x234, 0, eax=r.choice([0, 1])),
                                           0x230: handler(log, 0x230, 0, eax=r.choice([0, x]))})
    obj = rnd(c, 0x60)
    c.emu.w32(obj + 0x54, b)

    def ray(e, res):
        rec = e.arg32(0)
        log.put(0x30, e.r32(rec), e.arg32(1), e.r32(e.arg32(2)), e.r32(e.arg32(3)), *[e.arg32(i) for i in range(4, 8)])
        hit = r.choice([0, 1, 0x100])
        e.w32(rec + 0x10, r.choice([0, obj]))
        e.ret(eax=hit, argbytes=32)
    coll = c.emu.fake_object('coll', 0x40, slots={0x30: ray})
    s = sys_with_mgr(c, 0x1b00)
    holder = rnd(c, 0x20)
    c.emu.w32(holder + 0x1c, coll)
    c.emu.w32(s + 0x1aa3, holder)
    z = rnd(c, 0x10) if r.random() < 0.8 else 0
    m = c.emu.fake_object('mgr', 0x60, slots={0x58: handler(log, 0x58, 1, eax=g), 0x54: handler(log, 0x54, 1, eax=z)})
    c.emu.w32(s + 0x9b, m)
    cam = _cam_with_ctl(c, log, {0x8c: handler2(c, log, 0x8c, 'v'), 0x90: handler2(c, log, 0x90, 'v'),
                                 0x94: handler2(c, log, 0x94, 'F')})
    c.emu.w32(cam + 0x5c, rnd(c, 0x50))
    return [cam]


S(0x4fb680, 'ZBaseCamera::CalcCameraRoomHint3rdPerson', 'thiscall', gen=_rh3)
