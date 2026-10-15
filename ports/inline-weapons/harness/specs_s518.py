"""specs_s518.py - weapons batch 518: ZFFHERO::ControlDrop and AttachItemBack."""
from pilot import S
from wkit import rnd, stub, obj, b, sysobj, patch_jmp


def _drop(c):
    r = c.rng
    patch_jmp(c, 0x473000, stub(c, 1, rec_ecx=True))
    rm = sysobj(c, {0x4c: stub(c, 1, ret=r.getrandbits(32))})
    c.emu.w32(rm + 0xadc, r.getrandbits(32))
    nw = obj(c, 0x40, {0x2f0: stub(c, 3), 0x2d0: stub(c, 2)})
    t = obj(c, 0x40, {0x330: stub(c, 0, ret=r.choice((0xb, 0xc, 0xc, 3))), 0x2c4: stub(c, 2, ret=nw)})
    amm = obj(c, 0x40, {0x2f0: stub(c, 3), 0x320: stub(c, 0, ret=r.randint(0, 9)), 0x324: stub(c, 1)})
    at = obj(c, 0x40, {0x2c4: stub(c, 1, ret=amm)})
    item = obj(c, 0x80, {0x1e0: stub(c, 1, ret=b(c, 0.2)), 0x2e8: stub(c, 0, ret=t),
                         0x35c: stub(c, 0, ret=r.choice((0, 1, 2, 5, -1 & 0xffffffff))), 0x328: stub(c, 0, ret=at),
                         0x360: stub(c, 1)})
    h = obj(c, 0xa00, {0x55c: stub(c, 1, ret=0 if r.random() < 0.5 else amm), 0x20: stub(c, 1, ret=r.getrandbits(32))})
    return [h, item]


def _back(c):
    r = c.rng
    patch_jmp(c, 0x4dcbb0, stub(c, 1, rec_ecx=True))
    sysobj(c, {0x4c: stub(c, 1, ret=r.getrandbits(32))})
    t = rnd(c, 0x40)
    nm = r.choice((b'Rpg7V\0', b'Rpg7\0', b'Rpg7VX\0', b'AK47\0', None))
    if nm is None:
        c.emu.w32(t + 4, 0)
    else:
        s = c.emu.alloc(len(nm), 1)
        c.emu.wbytes(s, nm)
        c.emu.w32(t + 4, s)
    item = obj(c, 0x40, {0x2e8: stub(c, 0, ret=t)})
    h = obj(c, 0xf00, {0x290: stub(c, 4, skip=(2, 3), lcopy=((2, 9), (3, 3)))})
    c.emu.w8(h + 0xeec, r.choice((0, 1)))
    return [h, item]


S(0x58eb50, 'ZFFHERO::ControlDrop', 'thiscall', None, ret=None, gen=_drop)
S(0x58bc60, 'ZFFHERO::AttachItemBack', 'thiscall', None, ret=None, gen=_back)
