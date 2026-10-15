"""specs_c1015.py - camera batch 1015: GetPolarAngles, Get2DProjection, GetFireAimPos, SetSlowPointer, DoChangeFocus."""
import struct
from pilot import S
from camgen import rnd, fbits, f32, Log, handler, handler2, sys_with_mgr


def _fl(c, lo, hi, p=0.85):
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(lo, hi)))[0] if c.rng.random() < p else fbits(c)


def _helper(c):
    h = rnd(c, 0xe40)
    for off in range(0xa40, 0xe20, 4):
        c.emu.w32(h + off, _fl(c, -500, 500, 0.6))
    return h


def _gpa(c):
    r = c.rng
    v = c.emu.alloc(16, 4)
    for i in range(3):
        x = r.random()
        c.emu.w32(v + 4 * i, 0 if x < 0.15 else (r.choice([0x39000000, 0xb9000000, 0x39800000]) if x < 0.25 else _fl(c, -2, 2)))
    return [_helper(c), rnd(c, 4), rnd(c, 4), v]


S(0x5cf820, 'ZCamHelper::GetPolarAngles', 'thiscall', gen=_gpa)


def _g2d(c):
    r = c.rng
    log = Log(c)
    c.emu.hook(0x446320, handler2(c, log, 0x446320, 'wv', eax=r.getrandbits(32)))
    g = c.emu.fake_object('zcam', 0x10, slots={0x8c: handler2(c, log, 0x8c, 'v', eax=r.getrandbits(32))}) if r.random() < 0.85 else 0
    s = sys_with_mgr(c, 0x100)
    m = c.emu.fake_object('mgr', 0x40, slots={0x58: handler(log, 0x58, 1, eax=g)})
    c.emu.w32(s + 0x9b, m)
    out = c.emu.alloc(8, 4)

    def proj(e, res):  # Proj2D(out, v): log v, write a plausible screen position
        a0, a1 = e.arg32(0), e.arg32(1)
        log.put(0x446320, e.reg('ecx'), a0, e.r32(a1), e.r32(a1 + 4), e.r32(a1 + 8))
        for k in range(2):
            e.w32(a0 + 4 * k, _fl(c, -0.6, 0.6))
        e.ret(eax=0, argbytes=8)
    c.emu.hook(0x446320, proj)
    p = c.emu.alloc(16, 4)
    for i in range(3):
        c.emu.w32(p + 4 * i, fbits(c))
    return [_helper(c), out, p]


S(0x5cf300, 'ZCamHelper::Get2DProjection', 'thiscall', gen=_g2d)


def _camac(c, log):
    def h(e, res):
        log.put(0xac, e.reg('ecx'))
        e.ret(st0=c.rng.uniform(0, 600) if c.rng.random() < 0.9 else f32(c))
    return c.emu.fake_object('cam', 0x500, slots={0xac: h})


def _fap(c):
    r = c.rng
    log = Log(c)
    c.emu.hook(0x5cf110, handler(log, 0x5cf110, 0, eax=r.getrandbits(32)))
    c.emu.hook(0x5d2630, handler(log, 0x5d2630, 1, eax=r.getrandbits(32)))
    c.emu.hook(0x5cf420, handler2(c, log, 0x5cf420, 'F', eax=r.getrandbits(32)))
    c.emu.hook(0x5ceed0, handler2(c, log, 0x5ceed0, 'wvvwww', eax=r.getrandbits(32)))
    h = _helper(c)
    hero = rnd(c, 0x60)
    c.emu.w32(hero + 0x54, rnd(c, 0x20))
    c.emu.w32(h + 0x44, hero)
    c.emu.w32(h + 0xb54, _camac(c, log))
    c.emu.w8(h + 0xd32, r.choice([0, 1]))
    c.emu.w8(h + 0xd33, r.choice([0, 0, 1]))
    c.emu.w8(h + 0xb45, r.choice([0, 1]))
    c.emu.w32(h + 0xad5, r.choice([4, 4, 1]))
    c.emu.w32(h + 0xa4c, r.choice([0, 1, 2]))
    return [h, rnd(c, 16)]


S(0x5cf690, 'ZCamHelper::GetFireAimPos', 'thiscall', gen=_fap)


def _ssp(c):
    r = c.rng
    log = Log(c)
    c.emu.hook(0x5ceed0, handler2(c, log, 0x5ceed0, 'wwwwww', eax=r.getrandbits(32)))
    c.emu.hook(0x5d0bd0, handler(log, 0x5d0bd0, 3, eax=r.getrandbits(32)))
    h = _helper(c)
    c.emu.w32(h + 0xb54, _camac(c, log))
    c.emu.w8(h + 0xb45, r.choice([0, 1]))
    c.emu.w8(h + 0xb46, r.choice([0, 0, 1]))
    s = sys_with_mgr(c, 0x100)
    c.emu.w8(s + 0x6c, r.choice([0, 1]))
    return [h, r.choice([0, 1, 0x100, 0x101, r.getrandbits(32)])]


S(0x5d24c0, 'ZCamHelper::SetSlowPointer', 'thiscall', gen=_ssp)


def _dcf(c):
    r = c.rng
    log = Log(c)
    c.emu.hook(0x662c50, handler2(c, log, 0x662c50, 'w', eax=r.getrandbits(32)))
    c.emu.hook(0x662f40, handler2(c, log, 0x662f40, 'w', eax=r.getrandbits(32)))
    h = _helper(c)
    for off in range(0xd8b, 0xd97, 4):
        c.emu.w32(h + off, _fl(c, -1, 1))
    c.emu.w32(h + 0xd36, c.emu.fake_vtable('ease1', 1, {0: handler(log, 0xe1, 0, eax=r.getrandbits(32))}))
    c.emu.w32(h + 0xd87, c.emu.fake_vtable('ease2', 1, {0: handler(log, 0xe2, 0, eax=r.getrandbits(32))}))
    return [h]


S(0x5cebc0, 'ZCamHelper::DoChangeFocus (inferred)', 'thiscall', gen=_dcf)
