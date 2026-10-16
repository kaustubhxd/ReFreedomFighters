"""specs_c1026.py - camera batch 1026: ZBaseCamera Save, Load, RegisterMessages, Init."""
from pilot import S
from camgen import rnd, fbits, Log, handler, handler2, sys_with_mgr


def _save(c):
    r = c.rng
    log = Log(c)
    sg = c.emu.fake_object('sg', 0x10, slots={0x60: handler(log, 0x60, 1), 0x3c: handler(log, 0x3c, 1)})
    cam = rnd(c, 0x60)
    c.emu.w32(cam + 0x5c, r.choice([0, rnd(c, 0x40)]))
    s = sys_with_mgr(c, 0x100)
    c.emu.w32(s + 0x9b, c.emu.fake_object('mgr', 0x60, slots={0x4c: handler(log, 0x4c, 1, eax=r.getrandbits(32))}))
    return [cam, sg]


S(0x4fb2f0, 'ZBaseCamera::Save', 'thiscall', ret='al', gen=_save)


def _load(c):
    r = c.rng
    log = Log(c)

    def rb(e, res):
        a = e.arg32(0)
        log.put(0x68, a)
        e.w8(a, r.getrandbits(8))
        e.ret(argbytes=4)
    lg = c.emu.fake_object('lg', 0x10, slots={0x68: rb, 0x40: handler2(c, log, 0x40, 'W')})
    cam = c.emu.fake_object('cam', 0x60, slots={0x84: handler(log, 0x84, 0)})
    c.emu.wbytes(cam + 4, bytes(r.getrandbits(8) for _ in range(0x5c)))
    g = c.emu.fake_object('g', 0x10, slots={0x100: handler(log, 0x100, 1, eax=r.getrandbits(32))})
    s = sys_with_mgr(c, 0x100)
    c.emu.w32(s + 0x9b, c.emu.fake_object('mgr', 0x60, slots={0x58: handler(log, 0x58, 1, eax=g)}))
    return [cam, lg]


S(0x4fb360, 'ZBaseCamera::Load', 'thiscall', ret='al', gen=_load)


def _reg(c):
    r = c.rng
    log = Log(c)
    s = sys_with_mgr(c, 0x100)
    c.emu.w32(s + 0x9b, c.emu.fake_object('mgr', 0x120, slots={0x114: handler(log, 0x114, 4, eax=lambda e: r.getrandbits(32))}))
    return [rnd(c, 0x60)]


S(0x4fb3e0, 'ZBaseCamera::RegisterMessages', 'thiscall', gen=_reg)


def _init(c):
    r = c.rng
    log = Log(c)

    def pf(e, res):  # obj slot 0x84(index, float* out)
        log.put(0x84, e.reg('ecx'), e.arg32(0))
        e.w32(e.arg32(1), fbits(c))
        e.ret(argbytes=8)
    colors = c.emu.alloc(16, 4)
    for i in range(3):
        c.emu.w32(colors + 4 * i, r.choice([0, 255, r.getrandbits(32)]))
    obj = c.emu.fake_object('propobj', 0x10, slots={0x84: pf, 0x9c: handler(log, 0x9c, 2, eax=colors)})

    def pair(e, res):  # props slot 0x94(tmp*, name) -> tmp filled {obj, index}, returns tmp
        t = e.arg32(0)
        log.put(0x94, e.arg32(1))
        e.w32(t, obj)
        e.w32(t + 4, r.getrandbits(8))
        e.ret(eax=t, argbytes=8)
    props = c.emu.fake_object('props', 0x10, slots={0xa4: handler(log, 0xa4, 2, eax=lambda e: r.choice([0, 1, 0x100])),
                                                   0x94: pair})
    s = sys_with_mgr(c, 0x100)
    c.emu.w32(s + 0x9b, c.emu.fake_object('mgr', 0x140, slots={0x138: handler(log, 0x138, 0, eax=props)}))
    zc = c.emu.fake_object('zcam', 0x40, slots={k: handler(log, k, 1) for k in (0x214, 0x218, 0x21c, 0x220, 0x224)})
    cam = c.emu.fake_object('cam', 0x60, slots={0x84: handler(log, 0x84a, 0)})
    c.emu.w32(cam + 0x44, zc)
    return [cam]


S(0x4fb040, 'ZBaseCamera::Init', 'thiscall', gen=_init)
