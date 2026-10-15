"""specs_s522.py - weapons batch 522: ZLNKWHANDS ControlDrop / ControlUseOneAlone, ZItemWeapon::PlaySound."""
from pilot import S
from wkit import rnd, stub, obj, b, sysobj, patch_jmp, vec, seq_stub


def _logger(c):
    s = obj(c, 0x40, {0x2c: stub(c, 2, cdecl=True)})
    l = obj(c, 0x10, {0x20: stub(c, 2, ret=s)})
    c.emu.w32(0x700390, l)


def _drop(c):
    r = c.rng
    _logger(c)
    sysobj(c, {0x4c: stub(c, 1, ret=r.getrandbits(32))})
    a, bb = r.getrandbits(32), r.getrandbits(32)
    s = obj(c, 0x600, {0x500: stub(c, 0, ret=r.choice((0, a, bb))), 0x504: stub(c, 0, ret=r.choice((0, a, bb))),
                       0x3f0: stub(c, 0, ret=r.choice((0, 9, 0xa))), 0x45c: stub(c, 2)})
    return [s, r.choice((0, a, bb, r.getrandbits(32)))]


def _item(c):
    r = c.rng
    t = obj(c, 0x40, {0x308: stub(c, 0, ret=r.choice((0, 1, 2))), 0x300: stub(c, 0, ret=r.choice((0, 1, 2)))})
    return obj(c, 0x40, {0x2e8: stub(c, 0, ret=t)})


def _use(c):
    r = c.rng
    i1, i2 = _item(c), _item(c)
    nw = r.choice((0, i1, i2, r.getrandbits(32)))
    sysobj(c, {0x58: stub(c, 1, ret=nw)})
    s = obj(c, 0x600, {0x504: stub(c, 0, ret=r.choice((0, i1, nw))), 0x500: stub(c, 0, ret=r.choice((0, i2, nw))),
                       0x45c: stub(c, 2)})
    return [s, 0 if r.random() < 0.15 else r.getrandbits(32)]


def _psnd(c):
    r = c.rng
    patch_jmp(c, 0x43ec00, stub(c, 6, rec_ecx=True, skip=(0, 1), lcopy=((0, 9), (1, 3)), ret=r.getrandbits(32)))
    room = r.getrandbits(32)
    patch_jmp(c, 0x4db3b0, stub(c, 0, rec_ecx=True, ret=r.choice((0, room, r.getrandbits(32)))))
    so = obj(c, 0x200, {0x1c0: stub(c, 2, fldv=r.choice((0.0, 0.5, 0.99, r.random())))})
    sound = rnd(c, 0x100)
    g2 = rnd(c, 0x20)
    rm = obj(c, 0xb00, {0x4c: stub(c, 1, ret=r.getrandbits(32)), 0x60: stub(c, 1, ret=sound if r.random() < 0.8 else 0),
                        0x58: stub(c, 1, ret=g2 if r.random() < 0.8 else 0)})
    c.emu.w32(rm + 0xadc, room)
    c.emu.w32(so + 0x9b, rm)
    c.emu.w32(0x70039c, so)
    grp = obj(c, 0x40, {0x94: stub(c, 2, skip=(0, 1), lcopy=((0, 9), (1, 3)))})
    own = obj(c, 0x40, {0x20: stub(c, 0, ret=grp)})
    t = obj(c, 0x40, {0x33c: stub(c, 0, ret=r.choice((0, 1, 5, 20, -3 & 0xffffffff)))})
    w = obj(c, 0x200, {0x2f4: stub(c, 0, ret=own if r.random() < 0.7 else 0), 0x350: stub(c, 0, ret=t),
                       0x2c8: stub(c, 2, skip=(0, 1), fills=((0, vec(c, 9, -1, 1), 9), (1, vec(c, 3, -9, 9), 3))),
                       0x94: stub(c, 2, skip=(0, 1), lcopy=((0, 9), (1, 3)))})
    return [w, 0 if r.random() < 0.1 else r.getrandbits(32)]


S(0x473000, 'ZLNKWHANDS::ControlDrop', 'thiscall', None, ret=None, gen=_drop)
S(0x4732a0, 'ZLNKWHANDS::ControlUseOneAlone', 'thiscall', None, ret=None, gen=_use)
S(0x4700a0, 'ZItemWeapon::PlaySound', 'thiscall', None, ret='eax', gen=_psnd)
