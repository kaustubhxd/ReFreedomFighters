"""specs_c1011.py - camera batch 1011: ZCamHelper mouse aim."""
import struct
from pilot import S
from camgen import rnd, fbits, Log, handler


def _fl(c, lo, hi, p=0.85):
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(lo, hi)))[0] if c.rng.random() < p else fbits(c)


def _mpm(c):
    r = c.rng
    log = Log(c)
    c.emu.hook(0x591b20, handler(log, 0x591b20, 0, eax=r.choice([9, 9, 1, 0x109, r.getrandbits(32)])))
    h = rnd(c, 0xe40)
    c.emu.w32(h + 0xadd, r.choice([0x3e800000, 0x3f800000, 0x3dcccccd, _fl(c, 0, 2)]))
    c.emu.w32(h + 0xe0f, _fl(c, -4, 4) if r.random() < 0.3 else _fl(c, -0.2, 0.2))
    c.emu.w32(h + 0xe13, _fl(c, -4, 4) if r.random() < 0.3 else _fl(c, -0.2, 0.2))
    c.emu.w32(h + 0xa54, _fl(c, -3.3, 3.3))
    c.emu.w32(h + 0xa5c, _fl(c, -1.4, 1.2))
    return [h]


S(0x5d0df0, 'ZCamHelper::MovePointerMouse', 'thiscall', gen=_mpm)


def _upm(c):
    r = c.rng
    log = Log(c)
    from camgen import sys_with_mgr
    c.emu.hook(0x5a7530, handler(log, 0x5a7530, 1, eax=r.getrandbits(32)))

    def closeup(e, res):  # SetCloseUp(bool): the original pushes a byte local, so only the low byte is defined
        log.put(0x5cc880, e.reg('ecx'), e.arg32(0) & 0xff)
        e.ret(eax=0x5555, argbytes=4)
    c.emu.hook(0x5cc880, closeup)
    c.emu.hook(0x591b20, handler(log, 0x591b20, 0, eax=r.choice([0xb, 1, 9, r.getrandbits(32)])))
    c.emu.hook(0x5d11c0, handler(log, 0x5d11c0, 0, eax=r.getrandbits(32)))

    def cdecl(tag):
        def h(e, res):
            log.put(tag, e.arg32(0), e.arg32(1))
            e.ret(eax=0x1234)
        return h
    stream = c.emu.fake_object('stream', 0x10, slots={0x2c: cdecl(0x2c), 0x30: cdecl(0x30)})
    dbg = c.emu.fake_object('dbg', 0x10, slots={0x20: handler(log, 0x20, 2, eax=stream)})
    c.emu.w32(0x700390, dbg)
    c.emu.w32(0x7003b0, c.emu.stub_fn('fail', handler(log, 0x7003b0, 0)) if r.random() < 0.8 else 0)
    s = sys_with_mgr(c, 0x100)
    m = c.emu.fake_object('mgr', 0x40, slots={0x58: handler(log, 0x58, 1, eax=r.getrandbits(32))})
    c.emu.w32(s + 0x9b, m)
    h = rnd(c, 0xe40)
    hero = rnd(c, 0x900)
    c.emu.w8(hero + 0x67a, r.choice([0, 1]))
    if r.random() < 0.3:
        c.emu.w32(h + 0xe18, 0)
        if r.random() < 0.5:
            c.emu.w32(hero + 0x852, 0)
        else:
            q = rnd(c, 0x1d20)
            c.emu.w32(q + 0x1d0f, r.choice([0, r.getrandbits(32)]))
            c.emu.w32(hero + 0x852, q)
    c.emu.w32(h + 0x44, hero)
    c.emu.w32(h + 0xb54, rnd(c, 0x500))
    c.emu.w32(h + 0xad5, r.choice(list(range(14)) + [r.getrandbits(32)]))
    c.emu.w8(h + 0xb45, r.choice([0, 1]))
    c.emu.w32(h + 0xa4c, r.choice([0, 1, 2]))
    c.emu.w32(h + 0xe1c, r.choice([0, 3, 3, 1]))
    return [h]


S(0x5d2eb0, 'ZCamHelper::UpdatePointerMode', 'thiscall', gen=_upm)
