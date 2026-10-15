"""specs_c1013.py - camera batch 1013: UpdateFocusAngleMouse."""
import struct
from pilot import S
from camgen import rnd, fbits, Log, handler, handler2


def _fl(c, lo, hi, p=0.85):
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(lo, hi)))[0] if c.rng.random() < p else fbits(c)


def _ufa(c):
    r = c.rng
    log = Log(c)
    c.emu.hook(0x5d1ea0, handler(log, 0x5d1ea0, 0, eax=r.getrandbits(32)))
    c.emu.hook(0x5d2630, handler(log, 0x5d2630, 1, eax=r.getrandbits(32)))
    c.emu.hook(0x5cf300, handler2(c, log, 0x5cf300, '2v', eax=r.getrandbits(32)))
    c.emu.hook(0x5a7500, handler(log, 0x5a7500, 2, eax=r.getrandbits(32)))
    h = c.emu.fake_object('helper', 0xe40, slots={0x88: handler2(c, log, 0x88, 'F', eax=r.getrandbits(32))})
    c.emu.wbytes(h + 4, bytes(r.getrandbits(8) for _ in range(0xe3c)))
    for off in (0xa54, 0xa5c, 0xdfd, 0xaf9, 0xafd):
        c.emu.w32(h + off, _fl(c, -3.3, 3.3) if off < 0xdf0 else _fl(c, 0, 3000))
    c.emu.w32(h + 0xaf9, r.choice([0, 0x3e860a92, _fl(c, 0, 0.1)]))
    c.emu.w32(h + 0xafd, r.choice([0, 0x3dfa35dd, _fl(c, 0, 0.1)]))
    c.emu.w8(h + 0xd33, r.choice([0, 1]))
    c.emu.w32(h + 0xe18, r.choice([0, r.getrandbits(32)]))
    return [h]


S(0x5d28c0, 'ZCamHelper::UpdateFocusAngleMouse', 'thiscall', gen=_ufa)
