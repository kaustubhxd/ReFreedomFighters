"""specs_c1021.py - camera batch 1021: Find3DPointerShadowPos, StartRaisingFlag, Command, ActionInputs."""
import struct
from pilot import S
from camgen import rnd, fbits, Log, handler, handler2, sys_with_mgr


def _fl(c, lo, hi, p=0.85):
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(lo, hi)))[0] if c.rng.random() < p else fbits(c)


def _helper(c, slots=None, size=0xe40):
    r = c.rng
    h = c.emu.fake_object('helper', size, slots=slots or {})
    c.emu.wbytes(h + 4, bytes(r.getrandbits(8) for _ in range(size - 4)))
    return h


def _vec(c):
    v = c.emu.alloc(16, 4)
    for i in range(3):
        c.emu.w32(v + 4 * i, _fl(c, -500, 500))
    return v


def _shadow(c):
    r = c.rng
    log = Log(c)
    s = sys_with_mgr(c, 0x100)
    world = c.emu.fake_object('world', 0x10, slots={0x2e0: handler(log, 0x2e0, 6, eax=lambda e: r.getrandbits(32))})
    m = rnd(c, 0xb00)
    c.emu.w32(m + 0xadc, world)
    c.emu.w32(s + 0x9b, m)
    from pe_emu import F
    return [_helper(c), _vec(c), _vec(c), F(r.uniform(0, 100)), r.getrandbits(32)]


S(0x5cefc0, 'ZCamHelper::Find3DPointerShadowPos', 'thiscall', gen=_shadow)


def _flag(c):
    r = c.rng
    log = Log(c)
    c.emu.hook(0x5cd7f0, handler2(c, log, 0x5cd7f0, 'vvww', eax=r.getrandbits(32)))
    s = sys_with_mgr(c, 0x1c00)
    c.emu.w32(s + 0x1b5d, r.choice([0, 0, 1, 2]))
    h = _helper(c, {0x90: handler2(c, log, 0x90, 'OF', eax=r.getrandbits(32))})
    cam = rnd(c, 0x500)
    c.emu.w32(cam + 0x479, _fl(c, 0, 600))
    c.emu.w32(h + 0xb54, cam)
    flag = rnd(c, 0x120)
    pole = c.emu.fake_object('pole', 0x10, slots={0x80: handler2(c, log, 0x80, 'OF', eax=r.getrandbits(32))}) if r.random() < 0.7 else 0
    c.emu.w32(flag + 0x119, pole)
    return [h, flag]


S(0x5d26c0, 'ZCamHelper::StartRaisingFlag', 'thiscall', gen=_flag)


def _cmd(c):
    r = c.rng
    log = Log(c)
    h = _helper(c, size=0xe40)
    msg = r.getrandbits(16)
    c.emu.w16(h + 0xb59, msg)
    c.emu.w32(h - 4, r.choice([0, r.getrandbits(32)])) if False else None
    t = c.emu.fake_object('reftab', 0x20, slots={0x20: handler(log, 0x20, 1, eax=r.choice([0, 0, 1])),
                                                0xac: handler(log, 0xac, 1, eax=r.getrandbits(32))})
    cb = c.emu.stub_fn('refcb', handler(log, 0xcb, 0, eax=r.getrandbits(32)))
    c.emu.w32(t + 8, r.choice([0, cb]))
    lo = h - r.choice([0, 0x10, 0x1000])
    c.emu.w32(t + 0xc, lo if r.random() < 0.7 else h + 1)
    c.emu.w32(t + 0x10, h + r.choice([1, 0x100, 0]))
    c.emu.w32(0x70038c, t)
    data = rnd(c, 8)
    cmd = (r.getrandbits(16) << 16 | msg) if r.random() < 0.7 else r.getrandbits(32)
    return [h, cmd, data]


def _cmd_with_prefix(c):
    # the helper is preceded by a word (this-4) the command reads and writes
    pre = rnd(c, 4)
    c.emu.w32(pre, c.rng.choice([0, c.rng.getrandbits(32)]))
    return _cmd(c)


S(0x5cd9c0, 'ZCamHelper::Command', 'thiscall', ret='eax', gen=_cmd_with_prefix)


def _ai(c):
    r = c.rng
    h = _helper(c)
    for off in (0xb1f, 0xb23, 0xb27, 0xb2b):
        c.emu.w32(h + off, fbits(c))
    for off in (0xb2f, 0xb30, 0xb33, 0xb34, 0xdd8):
        c.emu.w8(h + off, r.choice([0, 1, 1]))
    return [h]


S(0x5cd5c0, 'ZCamHelper::ActionInputs', 'thiscall', gen=_ai)
