"""specs_s2101.py - wire-hero-combat batch 2101: 0x4837e0 ZAnimDefsList::GetAnim (2026-10-13)."""
import struct
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _iterlist(c):
    # Node list: slot 0x4c (start) records nothing and returns; slot 0x64 (next) returns the nodes in order, then 0,
    # and counts its calls. Neither records its argument (a pointer into the caller's frame, which differs by build).
    r = c.rng
    ents = []
    for _ in range(r.randint(0, 5)):
        e = c.emu.alloc(8, 4)
        c.emu.w32(e, r.getrandbits(32))
        c.emu.w32(e + 4, r.randint(0, 5))
        ents.append(e)
    ents.append(0)
    tab = c.emu.alloc(4 * 8, 4)
    for i in range(8):
        c.emu.w32(tab + 4 * i, ents[min(i, len(ents) - 1)])
    cnt = c.emu.alloc(4, 4)
    code = (b'\xa1' + struct.pack('<I', cnt) + b'\x83\xe0\x07\x8b\x04\x85' + struct.pack('<I', tab)
            + b'\xff\x05' + struct.pack('<I', cnt) + b'\xc2\x04\x00')
    nxt = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(nxt, code)
    scnt = c.emu.alloc(4, 4)
    start = c.emu.alloc(16, 16)
    c.emu.wbytes(start, b'\xff\x05' + struct.pack('<I', scnt) + b'\xc2\x04\x00')
    vt = c.emu.alloc(0x68, 4)
    c.emu.w32(vt + 0x4c, start)
    c.emu.w32(vt + 0x64, nxt)
    lst = c.emu.alloc(8, 4)
    c.emu.w32(lst, vt)
    return lst


def _ga(c):
    r = c.rng
    obj = _rnd(c, 0x20)
    c.emu.w32(obj + 0x14, _iterlist(c) if r.random() < 0.75 else 0)
    sysobj = _rnd(c, 0x100)
    c.emu.w32(sysobj + 0x40, r.choice((0, 1, -1, 0x7fffffff, -0x80000000, r.getrandbits(32), r.randint(0, 1 << 20))) & 0xffffffff)
    c.emu.w32(0x70039c, sysobj)
    c.emu.mu.ctl_flush_tb()
    return [obj, r.randint(0, 5) if r.random() < 0.9 else r.getrandbits(32)]


S(0x4837e0, 'ZAnimDefsList::GetAnim', 'thiscall', None, ret='eax', gen=_ga, nan_heap=True,
  note='batch2101; node list stubbed (start / next), clock from [0x70039c]+0x40; +0xc is a float')
