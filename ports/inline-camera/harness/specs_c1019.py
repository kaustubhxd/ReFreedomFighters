"""specs_c1019.py - camera batch 1019: gamepad pointer."""
import struct
from pilot import S
from camgen import rnd, fbits, Log, handler, sys_with_mgr, pow_stub


def _fl(c, lo, hi, p=0.85):
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(lo, hi)))[0] if c.rng.random() < p else fbits(c)


def _stick(c):
    return c.rng.choice([0, 0, 0x80000000, _fl(c, -1, 1), _fl(c, -1, 1)])


def _helper(c):
    r = c.rng
    h = rnd(c, 0xe40)
    for off in range(0xa40, 0xe20, 4):
        c.emu.w32(h + off, _fl(c, -3, 3, 0.7))
    for off in (0xb1f, 0xb23, 0xb27, 0xb2b):
        c.emu.w32(h + off, _stick(c))
    c.emu.w32(h + 0xa9e, r.choice([0xbf9c61aa, 0xbfa78d36]))
    c.emu.w32(h + 0xaa2, r.choice([0x3f860a92, 0x3fa78d36]))
    c.emu.w32(h + 0xadd, r.choice([0x3f800000, 0x3e800000, 0x3dcccccd]))
    for off in (0xa70, 0xa71, 0xb45, 0xab6, 0xad4, 0xb19):
        c.emu.w8(h + off, r.choice([0, 0, 1]))
    c.emu.w32(h + 0xad5, r.choice([5, 1, 4]))
    c.emu.w32(h + 0xe1c, r.choice([0, 1, 2]))
    s = sys_with_mgr(c, 0x100)
    c.emu.w32(s + 0x48, _fl(c, 0, 0.1))
    return h


def _oni(c):
    c.emu.stub_import('_libm_sse2_pow_precise', pow_stub)
    return [_helper(c)]


S(0x5d0f10, 'ZCamHelper::MovePointerOni', 'thiscall', gen=_oni)
S(0x5d0c90, 'ZCamHelper::MovePointerA', 'thiscall', gen=lambda c: [_helper(c)])


def _reset(c):
    r = c.rng
    log = Log(c)
    for a in (0x662b70, 0x662b00, 0x6627c0):
        c.emu.hook(a, handler(log, a, 1, eax=r.getrandbits(32)))
    h = _helper(c)
    c.emu.w8(h + 0xab6, r.choice([0, 0, 0, 1]))
    c.emu.w8(h + 0xb45, r.choice([0, 0, 0, 1]))
    c.emu.w8(h + 0xad4, r.choice([1, 1, 1, 0]))
    c.emu.w32(h + 0xb05, _fl(c, -0.05, 0.1))
    return [h]


S(0x5cd890, 'ZCamHelper::CheckResetPointerAndFocusOni', 'thiscall', gen=_reset)
