"""specs_c1016.py - camera batch 1016: ZCamHelper targeting."""
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


def _cam(c, log):
    r = c.rng

    def ac(e, res):
        log.put(0xac, e.reg('ecx'))
        e.ret(st0=r.uniform(0, 600) if r.random() < 0.9 else f32(c))
    return c.emu.fake_object('cam', 0x500, slots={0xac: ac, 0x94: handler2(c, log, 0x94, 'F', eax=r.getrandbits(32))})


def _bone_obj(c, log, extra=None):
    r = c.rng
    slots = {0x3a8: handler2(c, log, 0x3a8, 'F', eax=r.getrandbits(32)), 0x398: handler(log, 0x398, 1, eax=r.getrandbits(32)),
             0x84: handler2(c, log, 0x84, 'v', eax=r.getrandbits(32))}
    slots.update(extra or {})
    return c.emu.fake_object('obj', 0x60, slots=slots)


def _origin(c):
    r = c.rng
    log = Log(c)
    h = _helper(c)
    c.emu.w32(h + 0xb54, _cam(c, log))
    c.emu.w32(h + 0x44, _bone_obj(c, log))
    c.emu.w32(h + 0xad5, r.choice([5, 5, 1, 4]))
    c.emu.w32(h + 0xa4c, r.choice([0, 1, 1, 2]))
    return [h, rnd(c, 16)]


S(0x5cf420, 'ZCamHelper GetAimOrigin (unnamed)', 'thiscall', gen=_origin)


def _world_lists(c, log):
    r = c.rng
    na, nb = r.randint(0, 4), r.randint(0, 4)
    w = rnd(c, 0x4b4 + 4 * na + 0x10)
    c.emu.w32(w + 0x4b0, na)
    c.emu.w32(w + 0x408, nb)
    for i in range(na):
        if r.random() < 0.2:
            c.emu.w32(w + 0x4b4 + 4 * i, 0)
        else:
            ent = rnd(c, 8)
            c.emu.w32(ent + 4, _bone_obj(c, log))
            c.emu.w32(w + 0x4b4 + 4 * i, ent)
    for i in range(nb):
        c.emu.w32(w + 0x40c + 4 * i, 0 if r.random() < 0.2 else _bone_obj(c, log))
    c.emu.w32(0x7003b8, w)


def _pick_env(c, log):
    r = c.rng
    c.emu.hook(0x5d0490, handler(log, 0x5d0490, 1, eax=lambda e: r.choice([0, 1, 1, 0x101])))
    _world_lists(c, log)


def _mgr(c, log, s, g=None, extra=None):
    r = c.rng
    slots = {0x58: handler(log, 0x58, 1, eax=g if g is not None else 0), 0x4c: handler(log, 0x4c, 1, eax=r.getrandbits(32))}
    slots.update(extra or {})
    m = c.emu.fake_object('mgr', 0xb00, slots=slots)
    c.emu.w32(s + 0x9b, m)
    return m


def _pick(c):
    log = Log(c)
    _pick_env(c, log)
    s = sys_with_mgr(c, 0x100)
    _mgr(c, log, s)
    return [_helper(c)]


S(0x5cf110, 'ZCamHelper PickTarget (unnamed)', 'thiscall', ret='al', gen=_pick)


def _kind_geom(c, log, team=None):
    r = c.rng
    g = _bone_obj(c, log, {0x1e0: handler(log, 0x1e0, 1, eax=r.choice([0, 1, 0x100, 0x201]))})
    t = rnd(c, 0x10)
    c.emu.w32(t + 4, r.randint(0, 40))
    c.emu.w32(g + 0x54, t)
    return g


def _lock(c):
    r = c.rng
    log = Log(c)
    s = sys_with_mgr(c, 0x100)
    _mgr(c, log, s, _kind_geom(c, log) if r.random() < 0.85 else 0)
    return [_helper(c), r.choice([0, r.getrandbits(32)])]


S(0x5d2630, 'ZCamHelper LockTarget (unnamed)', 'thiscall', gen=_lock)


def _hero(c):
    hero = rnd(c, 0x60)
    team = rnd(c, 0x20)
    c.emu.w32(hero + 0x54, team)
    c.emu.w32(hero + 8, rnd(c, 0x40))
    return hero


def _rel(c):
    r = c.rng
    log = Log(c)
    s = sys_with_mgr(c, 0x100)
    _mgr(c, log, s, _kind_geom(c, log) if r.random() < 0.85 else 0)
    h = _helper(c)
    c.emu.w32(h + 0x44, _hero(c))
    return [h, r.getrandbits(32)]


S(0x5d2860, 'ZCamHelper TargetRelation (unnamed)', 'thiscall', ret='eax', gen=_rel)


def _chk(c):
    r = c.rng
    log = Log(c)
    _pick_env(c, log)
    s = sys_with_mgr(c, 0x100)
    world = c.emu.fake_object('world', 0x10, slots={0x2e0: handler(log, 0x2e0, 6, eax=lambda e: r.getrandbits(32))})
    m = _mgr(c, log, s, _kind_geom(c, log) if r.random() < 0.85 else 0)
    c.emu.w32(m + 0xadc, world)
    h = _helper(c)
    c.emu.w32(h + 0x44, _hero(c))
    c.emu.w32(h + 0xb54, _cam(c, log))
    c.emu.w8(h + 0xd32, r.choice([0, 1]))
    c.emu.w32(h + 0xad5, r.choice([9, 1, 4]))
    return [h]


S(0x5d11c0, 'ZCamHelper CheckPointerTarget (unnamed)', 'thiscall', ret='al', gen=_chk)


def _f3d(c):
    r = c.rng
    log = Log(c)
    c.emu.hook(0x4dc630, handler(log, 0x4dc630, 2, eax=r.getrandbits(32)))
    s = sys_with_mgr(c, 0x100)
    world = c.emu.fake_object('world', 0x10, slots={0x2e0: handler(log, 0x2e0, 6, eax=lambda e: r.getrandbits(32))})
    m = _mgr(c, log, s)
    c.emu.w32(m + 0xadc, world)
    h = _helper(c)
    c.emu.w32(h + 0x44, _hero(c))
    o, d = rnd(c, 16), rnd(c, 16)
    for p in (o, d):
        for i in range(3):
            c.emu.w32(p + 4 * i, _fl(c, -500, 500))
    return [h, rnd(c, 16), o, d, r.choice([2, 0x10, r.getrandbits(32)]), r.getrandbits(32), r.getrandbits(32)]


S(0x5ceed0, 'ZCamHelper::Find3DPointerPos', 'thiscall', ret='eax', gen=_f3d)
