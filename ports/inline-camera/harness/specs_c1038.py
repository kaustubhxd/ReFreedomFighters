"""specs_c1038.py - camera batch 1038: ZCAMERA activate/deactivate, room accessors, always-draw list."""
from pilot import S
from camgen import rnd, Log, handler, sys_with_mgr


def _env(c, log):
    r = c.rng
    s = sys_with_mgr(c, 0x1a00)
    lst = c.emu.fake_object('camlist', 0x20, slots={0x2c: handler(log, 0x2c, 0)})
    c.emu.w32(s + 0x190f, lst if r.random() < 0.85 else 0)
    world = c.emu.fake_object('world', 0x10, slots={})
    m = c.emu.fake_object('mgr', 0x1000, slots={})
    c.emu.w32(m + 0xadc, world)
    c.emu.w32(s + 0x9b, m)
    return world


def _cam(c, flags=None):
    r = c.rng
    cam = rnd(c, 0x200)
    c.emu.w32(cam + 0x48, flags if flags is not None else r.getrandbits(32))
    c.emu.w32(cam + 0x18, r.choice([0, r.getrandbits(32)]))
    c.emu.w32(cam + 0x2c, r.randint(0, 2))
    return cam


def _act(c):
    log = Log(c, 256)
    _env(c, log)
    return [_cam(c)]


S(0x445390, 'ZCAMERA::ActivateCam', 'thiscall', gen=_act)
S(0x445c70, 'ZCAMERA::DeactivateCam', 'thiscall', gen=_act)
S(0x445c50, 'ZCAMERA::CurrentRoom', 'thiscall', ret='eax', gen=lambda c: [_cam(c)])
S(0x445e70, 'ZCAMERA::GetCurrentRoomHint', 'thiscall', ret='eax', gen=lambda c: [_cam(c)])
S(0x446d70, 'ZCAMERA::SetCurrentRoomHint', 'thiscall', gen=lambda c: [_cam(c), c.rng.getrandbits(32)])


def _add(c):
    r = c.rng
    log = Log(c, 256)
    c.emu.hook(0x7003b0, handler(log, 0x7003b0, 0))
    c.emu.w32(0x7003b0, c.emu.stub_fn('hook', handler(log, 0x7003b1, 0)) if r.random() < 0.8 else 0)
    return [_cam(c, flags=0), r.getrandbits(32)]


S(0x4454a0, 'ZCAMERA::AddAlwaysDrawGeom', 'thiscall', gen=_add)


def _rem(c):
    r = c.rng
    cam = _cam(c)
    n = c.emu.r32(cam + 0x2c)
    c.emu.w32(cam + 0x2c, r.randint(0, 2))  # two entries at +0x24 and +0x28; a third would overlay the count
    n = c.emu.r32(cam + 0x2c)
    for i in range(n):
        c.emu.w32(cam + 0x24 + 4 * i, r.getrandbits(32))
    target = c.emu.r32(cam + 0x24 + 4 * (r.randint(0, n - 1))) if n and r.random() < 0.7 else r.getrandbits(32)
    return [cam, target]


S(0x4464a0, 'ZCAMERA::RemoveAlwaysDrawGeom', 'thiscall', ret='al', gen=_rem)
