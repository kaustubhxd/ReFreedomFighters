"""specs_c1014.py - camera batch 1014: ZCamHelper focus control."""
import struct
from pilot import S as _S


def S(a, n, abi, ret=None, gen=None, **k):  # the camera thread's S(addr, name, abi, ret=, gen=) on the strict pilot's Spec
    _S(a, n, abi, None, ret=ret, gen=gen, note='wire-render; camera batch1014', **k)
from camgen import rnd, fbits, Log, handler, handler2, sys_with_mgr


def _fl(c, lo, hi, p=0.85):
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(lo, hi)))[0] if c.rng.random() < p else fbits(c)


def _helper(c):
    h = rnd(c, 0xe40)
    for off in range(0xa40, 0xe20, 4):
        c.emu.w32(h + off, _fl(c, -500, 500, 0.6))
    return h


def _reset(c):
    r = c.rng
    log = Log(c)
    c.emu.hook(0x5cf820, handler2(c, log, 0x5cf820, 'wwv', eax=r.getrandbits(32)))
    for a in (0x5d2080, 0x5cdb70, 0x5cc560):
        c.emu.hook(a, handler(log, a, 0, eax=r.getrandbits(32)))
    h = _helper(c)
    c.emu.w32(h + 0xa4c, r.choice([0, 1, 2]))
    c.emu.w32(h + 0x44, c.emu.fake_object('hero', 0x40, slots={0x80: handler2(c, log, 0x80, 'Oq', eax=r.getrandbits(32))}))
    return [h]


S(0x5d1440, 'ZCamHelper::ResetFocus', 'thiscall', gen=_reset)


def _mf(c):
    from pe_emu import F
    s = sys_with_mgr(c, 0x100)
    return [_helper(c), rnd(c, 16), F(struct.unpack('<f', struct.pack('<I', fbits(c)))[0]), c.rng.getrandbits(32)]


S(0x5d0bd0, 'ZCamHelper::MoveFocus', 'thiscall', gen=_mf)


def _dmf(c):
    r = c.rng
    log = Log(c)
    c.emu.hook(0x5cf820, handler2(c, log, 0x5cf820, 'wwv', eax=r.getrandbits(32)))
    h = _helper(c)
    c.emu.w8(h + 0xab6, r.choice([0, 1, 1, 1]))
    c.emu.w8(h + 0xabb, r.choice([0, 1]))
    c.emu.w32(h + 0xa4c, r.choice([0, 1, 2]))
    for off in range(0xc89, 0xcad, 4):
        c.emu.w32(h + off, _fl(c, -1, 1))
    c.emu.w32(h + 0xab2, _fl(c, 0, 20))
    for off in (0xb1f, 0xb23, 0xb27, 0xb2b):
        c.emu.w32(h + off, r.choice([0, 0, 0, 0x80000000, _fl(c, -1, 1)]))
    if r.random() < 0.15:
        for off in (0xabc, 0xac0, 0xac4):
            c.emu.w32(h + off, c.emu.r32(h + off - 0xabc + 0xc71))
    cam = c.emu.fake_object('cam', 0x10, slots={0x94: handler2(c, log, 0x94, 'F', eax=r.getrandbits(32))})
    c.emu.w32(h + 0xb54, cam)
    s = sys_with_mgr(c, 0x100)
    now = r.getrandbits(31)
    c.emu.w32(s + 0x40, now)
    c.emu.w32(h + 0xab7, (now - r.randint(0, 400)) & 0xffffffff)
    c.emu.w32(s + 0x48, _fl(c, 0, 0.1))
    return [h]


S(0x5cecd0, 'ZCamHelper::DoMoveFocus', 'thiscall', gen=_dmf)


def _cf(c):
    r = c.rng
    log = Log(c)
    for a in (0x662dd0, 0x662e20, 0x662e70, 0x662fd0, 0x663060, 0x6630f0):
        c.emu.hook(a, handler(log, a, 1, eax=r.getrandbits(32)))
    from pe_emu import F
    t = struct.unpack('<f', struct.pack('<I', _fl(c, 0, 5)))[0]
    return [_helper(c), rnd(c, 16), rnd(c, 0x24), F(t), r.getrandbits(32)]


S(0x5cd7f0, 'ZCamHelper::ChangeFocus', 'thiscall', gen=_cf)


def _ufs(c):
    r = c.rng
    log = Log(c)
    for a in (0x5cebc0, 0x5d2080, 0x5d1ea0):
        c.emu.hook(a, handler(log, a, 0, eax=r.getrandbits(32)))
    h = _helper(c)
    c.emu.w8(h + 0xd35, r.choice([0, 0, 1]))
    c.emu.w8(h + 0xdd8, r.choice([0, 0, 1]))
    c.emu.w32(h + 0xe1c, r.choice([0, 1, 2, 3, 3, 4, r.getrandbits(32)]))
    return [h]


S(0x5d2e60, 'ZCamHelper::UpdateFocusSystem', 'thiscall', gen=_ufs)
