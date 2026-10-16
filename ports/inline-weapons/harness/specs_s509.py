"""specs_s509.py - weapons batch 509: item wheel selection (ZGameOSD)."""
from pilot import S
from wkit import rnd, stub, patch_jmp


def _osd(c):
    r = c.rng
    patch_jmp(c, 0x4f9680, stub(c, 1, rec_ecx=True, ret=r.getrandbits(32)))
    patch_jmp(c, 0x5ab230, stub(c, 1, rec_ecx=True))
    patch_jmp(c, 0x5ab2a0, stub(c, 1, rec_ecx=True))
    patch_jmp(c, 0x5ab130, stub(c, 1, rec_ecx=True))
    osd = rnd(c, 0x400)
    for off in (0x00, 0x04, 0x08, 0x0c, 0x15, 0x19, 0x25, 0x29, 0x2d, 0x31, 0x35, 0x39, 0x3d, 0x41):
        if r.random() < 0.3:
            c.emu.w32(osd + 0x37d + off, 0)
    c.emu.w32(osd + 0x37d + 0x1d, r.choice((0, 1, 2, 2)))
    sel = r.choice(list(range(9)) + [9, 0xffffffff])
    c.emu.w32(osd + 0x3c2, sel)
    c.emu.w8(osd + 0x3c6, 0 if r.random() < 0.2 else 1)
    g = rnd(c, 0x1e00)
    c.emu.w32(g + 0x1d0f, osd if r.random() < 0.95 else 0)
    c.emu.w32(g + 0x1d47, sel if r.random() < 0.3 else r.choice((0, 3, 8)))
    return g


def _get(c):
    g = _osd(c)
    if c.emu.r32(g + 0x1d0f) == 0:
        c.emu.w32(g + 0x1d0f, rnd(c, 0x400))
    return [g]


def _cmd(c):
    return [_osd(c), c.rng.getrandbits(32)]


S(0x5e9b70, 'ZGameOSD::WheelInventoryGetItem', 'thiscall', None, ret='eax', gen=_get)
S(0x5e9b40, 'ZGameOSD::WheelInventoryCommand', 'thiscall', None, ret=None, gen=_cmd)
