"""specs_c1033.py - camera batch 1033: ZCamHelper::Init2."""
import struct
from pilot import S
from camgen import rnd, fbits, Log, handler, handler2, sys_with_mgr


def _init2(c):
    r = c.rng
    log = Log(c, 512)
    # the exe helpers Init2 calls: hooked so each run sees the same behaviour in both builds
    c.emu.hook(0x5922c0, handler2(c, log, 0x5922c0, 'F', eax=0))
    def mreset(e, res_):  # mreset gets a stack matrix in ECX: log only the tag, not the address
        log.put(0x4de7a0)
        e.ret(argbytes=0)
    c.emu.hook(0x4de7a0, mreset)
    c.emu.hook(0x591ae0, handler(log, 0x591ae0, 0, eax=r.getrandbits(32)))

    def opt90(e, res):  # options slot 0x90(name, bool* out)
        log.put(0x90, e.arg32(0))
        e.wbytes(e.arg32(1), bytes([r.choice([0, 1])]))
        e.ret(argbytes=8)
    opts = c.emu.fake_object('opts', 0x10, slots={0x90: opt90})

    def prop88(e, res):  # props slot 0x88(name, dword* out)
        log.put(0x88, e.arg32(0))
        e.w32(e.arg32(1), r.choice([0, r.getrandbits(32)]))
        e.ret(argbytes=8)
    props = c.emu.fake_object('props', 0x10, slots={0x88: prop88})

    # logger (0x700390): slot 0x20 gives a stream whose slot 0x2c is a cdecl printf (no pop)
    def cdecl(e, res):
        log.put(0x2c, e.arg32(0), e.arg32(1))
        e.ret(argbytes=0)
    stream = c.emu.fake_object('stream', 0x10, slots={0x2c: cdecl})
    dbg = c.emu.fake_object('dbg', 0x10, slots={0x20: handler(log, 0x20, 2, eax=stream)})
    c.emu.w32(0x700390, dbg)

    cam = c.emu.fake_object('camgeom', 0x10, slots={0x80: handler2(c, log, 0x80, 'OV', eax=0)})
    res = cam if r.random() < 0.85 else 0

    def mgr58(e, res_):
        log.put(0x58, e.arg32(0))
        e.ret(eax=res, argbytes=4)
    def mgr134(e, res_):
        log.put(0x134)
        e.ret(eax=opts, argbytes=0)
    def mgr138(e, res_):
        log.put(0x138)
        e.ret(eax=props, argbytes=0)
    s = sys_with_mgr(c, 0x100)
    c.emu.w8(s + 0x6c, r.choice([0, 1]))
    m = c.emu.fake_object('mgr', 0x140, slots={0x134: mgr134, 0x138: mgr138, 0x58: mgr58})
    c.emu.w32(s + 0x9b, m)

    hero = c.emu.fake_object('hero', 0x800, slots={
        0x378: handler2(c, log, 0x378, 'F', eax=0), 0x84: handler2(c, log, 0x84, 'F', eax=0)})
    c.emu.wbytes(hero + 4, bytes(r.getrandbits(8) for _ in range(0x7fc)))
    c.emu.w32(hero + 0x676, r.getrandbits(32))
    c.emu.w32(hero + 0x684, r.choice([0, 1, 2, 3, 4, 5]))
    self_ = rnd(c, 0xf00)
    c.emu.w32(self_ + 0x44, hero)
    return [self_]


S(0x5d00e0, 'ZCamHelper::Init2', 'thiscall', gen=_init2)
