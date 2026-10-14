"""specs_u69_11.py - area 69, group 11 (unclaimed-69 thread): ZSysMem::CreateRef."""
from pilot import S
from ckit import obj, rnd, rvt


def _cr(c):
    r = c.rng
    e = c.emu
    buf = rnd(c, 0x100)
    p = buf + 0x40
    e.w32(p - 8, r.choice([0xffffffff, 0x80000000, 0, 5, r.getrandbits(32)]))
    vals = {off: r.getrandbits(32) for off in (0xc, 0x14, 0x18, 0x1c, 0x20)}
    for off, v in vals.items():
        e.w32(p - off, v)
    if r.random() < 0.3:   # make the XOR zero sometimes, so the 'replace with 1' branch runs
        x = e.r32(p - 8)
        for off in (0xc, 0x14, 0x18, 0x1c):
            x ^= e.r32(p - off)
        e.w32(p - 0x20, x)
    sysobj = obj(e, 'sysmem', 0x40, {0xd0: (1, lambda e, t, a: (r.getrandbits(32), None, (a[0] == 0x0,)))}, nslots=0xd4 // 4)
    return [sysobj, p]


S(0x41e710, 'ZSysMem::CreateRef', 'thiscall', None, ret='eax', gen=_cr, note='u69 group 11')
