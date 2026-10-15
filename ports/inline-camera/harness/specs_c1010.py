"""specs_c1010.py - camera batch 1010: ZCamHelper small members."""
import struct
from pilot import S
from camgen import rnd, fbits, Log, handler, handler2, sys_with_mgr


def _fl(c, lo, hi, p=0.85):
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(lo, hi)))[0] if c.rng.random() < p else fbits(c)


def _helper(c):
    h = rnd(c, 0xe40)
    for off in range(0xa40, 0xe20, 4):
        c.emu.w32(h + off, _fl(c, -500, 500, 0.6))
    return h


def _abort(c):
    log = Log(c)
    c.emu.hook(0x5cd7f0, handler(log, 0x5cd7f0, 4, eax=c.rng.getrandbits(32)))
    h = _helper(c)
    c.emu.w8(h + 0xdd8, c.rng.choice([0, 1]))
    return [h]


S(0x5cd580, 'ZCamHelper::AbortRaisingFlag', 'thiscall', gen=_abort)


def _clear(c):
    r = c.rng
    log = Log(c)
    world = c.emu.fake_object('world', 0x10, slots={0x2e0: handler2(c, log, 0x2e0, 'Cwwwww', eax=r.choice([0, 1, 0x100, r.getrandbits(32)]))})
    s = sys_with_mgr(c, 0x100)
    m = rnd(c, 0xb00)
    c.emu.w32(m + 0xadc, world)
    c.emu.w32(s + 0x9b, m)
    p = c.emu.alloc(16, 4)
    for i in range(3):
        c.emu.w32(p + 4 * i, _fl(c, -500, 500))
    return [_helper(c), p]


S(0x5cd750, 'ZCamHelper IsClearLine (unnamed)', 'thiscall', ret='eax', gen=_clear)


def _cpe(c):
    r = c.rng
    log = Log(c)
    c.emu.hook(0x5cf110, handler(log, 0x5cf110, 0, eax=r.getrandbits(32)))
    h = _helper(c)
    hero = rnd(c, 0x60)
    team = rnd(c, 0x20)
    c.emu.w32(hero + 0x54, team)
    c.emu.w32(h + 0x44, hero)
    c.emu.w8(h + 0xb45, r.choice([0, 1]))
    return [h]


S(0x5cda40, 'ZCamHelper::CommandPointerAtEnemy', 'thiscall', ret='eax', gen=_cpe)


def _seq(addrs):
    def g(c):
        log = Log(c)
        for a in addrs:
            c.emu.hook(a, handler(log, a, 0, eax=c.rng.getrandbits(32)))
        return [_helper(c)]
    return g


S(0x5ceb30, 'ZCamHelper::ControlMouse', 'thiscall', gen=_seq([0x5d0df0, 0x5d2eb0, 0x5d1530, 0x5d28c0, 0x5ce0b0, 0x5d1ea0]))
S(0x5ceb70, 'ZCamHelper::ControlOni', 'thiscall', gen=_seq([0x5d0f10, 0x5d2eb0, 0x5d2ab0, 0x5d1530, 0x5d2080, 0x5d2280, 0x5cd890, 0x5ce0b0]))


def _3e0(c):
    r = c.rng
    log = Log(c)
    c.emu.hook(0x45bfd0, handler(log, 0x45bfd0, 1, eax=r.getrandbits(32)))
    g = c.emu.fake_object('g', 0x10, slots={0x88: handler(log, 0x88, 1, eax=r.getrandbits(32))}) if r.random() < 0.8 else 0
    s = sys_with_mgr(c, 0x100)
    m = c.emu.fake_object('mgr', 0x40, slots={0x58: handler(log, 0x58, 1, eax=g)})
    c.emu.w32(s + 0x9b, m)
    return [_helper(c), rnd(c, 16)]


S(0x5cf3e0, 'ZCamHelper 5cf3e0 (unnamed)', 'thiscall', gen=_3e0)


def _ang(c):
    r = c.rng
    log = Log(c)
    c.emu.hook(0x5cf420, handler2(c, log, 0x5cf420, 'F', eax=r.getrandbits(32)))
    h = _helper(c)
    c.emu.w32(h + 0xa4c, r.choice([0, 1, 2]))
    p = c.emu.alloc(16, 4)
    for i in range(3):
        c.emu.w32(p + 4 * i, _fl(c, -500, 500))
    return [h, p]


S(0x5cf520, 'ZCamHelper AngleToAim (unnamed)', 'thiscall', ret='st0', gen=_ang)
S(0x5cf5d0, 'ZCamHelper AngleToAimXZ (unnamed)', 'thiscall', ret='st0', gen=_ang)
S(0x5cf7f0, 'ZCamHelper::GetGlobalFocalPoint', 'thiscall', gen=lambda c: [_helper(c), rnd(c, 16)])


def _rsp(c):
    r = c.rng
    log = Log(c)
    c.emu.hook(0x5cfd90, handler(log, 0x5cfd90, 1, eax=r.choice([0, 1, 0x100, r.getrandbits(32)])))
    c.emu.hook(0x5cfb10, handler(log, 0x5cfb10, 1, eax=r.getrandbits(32)))
    return [_helper(c), rnd(c, 16)]


S(0x5cfae0, 'ZCamHelper::GetRecruitScoutPos', 'thiscall', ret='eax', gen=_rsp)
S(0x5cfee0, 'ZCamHelper::GetFocusMatPos', 'thiscall', gen=lambda c: [_helper(c), rnd(c, 0x24), rnd(c, 16)])


def _d0080(c):
    r = c.rng
    log = Log(c)
    c.emu.hook(0x5cc880, handler(log, 0x5cc880, 1, eax=r.getrandbits(32)))
    c.emu.hook(0x5a7530, handler(log, 0x5a7530, 1, eax=r.getrandbits(32)))
    h = _helper(c)
    c.emu.w32(h + 0xe18, r.choice([0, r.getrandbits(32)]))
    return [h]


S(0x5d0080, 'ZCamHelper 5d0080 (unnamed)', 'thiscall', gen=_d0080)


def _init(c):
    r = c.rng
    log = Log(c)
    c.emu.hook(0x5d0310, handler(log, 0x5d0310, 0, eax=r.getrandbits(32)))
    s = sys_with_mgr(c, 0x100)
    m = c.emu.fake_object('mgr', 0x40, slots={0x114: handler(log, 0x114, 4, eax=r.getrandbits(32))})
    c.emu.w32(s + 0x9b, m)
    return [_helper(c)]


S(0x5d02d0, 'ZCamHelper::Init', 'thiscall', gen=_init)


def _load2(c):
    r = c.rng
    log = Log(c)
    c.emu.hook(0x591ae0, handler(log, 0x591ae0, 0, eax=r.getrandbits(32)))
    return [_helper(c)]


S(0x5d05b0, 'ZCamHelper::Load2', 'thiscall', gen=_load2)
