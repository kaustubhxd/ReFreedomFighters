"""specs_c1020.py - camera batch 1020: UpdateFocusAngleOni, SetPointerOnScreenOni."""
import struct
from pilot import S
from camgen import rnd, fbits, f32, Log, handler, handler2, sys_with_mgr


def _fl(c, lo, hi, p=0.85):
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(lo, hi)))[0] if c.rng.random() < p else fbits(c)


def _dbg(c, log):
    def cdecl(e, res):
        log.put(0x2c, e.arg32(0), e.arg32(1), e.arg32(2), e.arg32(3))
        e.ret(eax=0x1234)
    stream = c.emu.fake_object('stream', 0x10, slots={0x2c: cdecl})
    c.emu.w32(0x700390, c.emu.fake_object('dbg', 0x10, slots={0x20: handler(log, 0x20, 2, eax=stream)}))


def _helper(c, slots=None):
    r = c.rng
    h = c.emu.fake_object('helper', 0xe40, slots=slots or {})
    c.emu.wbytes(h + 4, bytes(r.getrandbits(8) for _ in range(0xe3c)))
    for off in (0xa54, 0xae9, 0xa5c, 0xaed, 0xa60, 0xa64):
        c.emu.w32(h + off, _fl(c, -3.3, 3.3))
    c.emu.w32(h + 0xaf9, r.choice([0, 0x3e860a92, _fl(c, -0.1, 0.5)]))
    c.emu.w32(h + 0xafd, r.choice([0, 0x3dfa35dd, _fl(c, -0.1, 0.5)]))
    c.emu.w32(h + 0xb01, r.choice([0x3e99999a, 0x3f800000]))
    c.emu.w32(h + 0xadd, r.choice([0x3f800000, 0x3e800000, 0x3dcccccd]))
    c.emu.w32(h + 0xa96, r.choice([0xbf9c61aa, 0xbfa78d36]))
    c.emu.w32(h + 0xa9a, r.choice([0x3f860a92, 0x3fa78d36]))
    c.emu.w8(h + 0xb45, r.choice([0, 1]))
    c.emu.w32(h + 0xdfd, _fl(c, 0, 25000))
    s = sys_with_mgr(c, 0x100)
    c.emu.w32(s + 0x48, _fl(c, 0, 0.1))
    return h


def _ufo(c):
    log = Log(c)
    _dbg(c, log)
    return [_helper(c)]


S(0x5d2ab0, 'ZCamHelper::UpdateFocusAngleOni', 'thiscall', gen=_ufo)


def _spo(c):
    r = c.rng
    log = Log(c)
    _dbg(c, log)
    c.emu.hook(0x5ceed0, handler(log, 0x5ceed0, 6, eax=r.getrandbits(32)))
    c.emu.hook(0x5cefc0, handler(log, 0x5cefc0, 4, eax=r.getrandbits(32)))
    c.emu.hook(0x5cf300, handler2(c, log, 0x5cf300, '2w', eax=r.getrandbits(32)))
    c.emu.hook(0x5a7500, handler(log, 0x5a7500, 2, eax=r.getrandbits(32)))
    h = _helper(c, {0x88: handler2(c, log, 0x88, 'F', eax=r.getrandbits(32))})

    def ac(e, res):
        log.put(0xac, e.reg('ecx'))
        e.ret(st0=r.uniform(0, 600) if r.random() < 0.9 else f32(c))
    c.emu.w32(h + 0xb54, c.emu.fake_object('cam', 0x10, slots={0xac: ac}))
    c.emu.w32(h + 0xe18, r.choice([0, r.getrandbits(32)]))
    return [h]


S(0x5d2280, 'ZCamHelper::SetPointerOnScreenOni', 'thiscall', gen=_spo)
