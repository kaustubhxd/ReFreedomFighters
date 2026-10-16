"""specs_s511.py - weapons batch 511: ForceR/LHandItem and the small hand helpers."""
from pilot import S
from wkit import rnd, stub, obj, b, sysobj, patch_jmp


def _item(c):
    return obj(c, 0x40, {0x2d0: stub(c, 2), 0x2f0: stub(c, 3), 0x210: stub(c, 1)})


def _hands(c, cur_r=None, cur_l=None):
    r = c.rng
    self = obj(c, 0x600, {0x510: stub(c, 0, ret=r.choice((0, 1, 2, 3))), 0x514: stub(c, 0, ret=r.choice((0, 1, 2))),
                          0x520: stub(c, 1), 0x524: stub(c, 1), 0x46c: stub(c, 1), 0x4f4: stub(c, 1),
                          0x548: stub(c, 2), 0x54c: stub(c, 2), 0x504: stub(c, 0, ret=_item(c)),
                          0x500: stub(c, 0, ret=_item(c))})
    for off, cur in ((0x34f, cur_r), (0x2e7, cur_l)):
        vt = c.emu.alloc(0x20, 4)
        c.emu.w32(vt + 0x8, stub(c, 2, rec_ecx=True))
        c.emu.w32(vt + 0xc, stub(c, 1, rec_ecx=True))
        c.emu.w32(vt + 0x10, stub(c, 0, ret=cur if cur is not None else 0))
        c.emu.w32(self + off, vt)
    return self


def _force(c):
    r = c.rng
    patch_jmp(c, 0x467410, stub(c, 6, rec_ecx=True))
    sysobj(c, {0x4c: stub(c, 1, ret=r.getrandbits(32))})
    new = 0 if r.random() < 0.2 else _item(c)
    cur = r.choice((0, _item(c), new))
    self = _hands(c, cur, r.choice((0, _item(c))))
    return [self, new, b(c, 0.6)]


def _plain(c):
    return [_hands(c, _item(c), _item(c))]


def _plain_u(c):
    return [_hands(c, _item(c), _item(c)), c.rng.getrandbits(32)]


S(0x473cd0, 'ZLNKWHANDS::ForceRHandItem', 'thiscall', None, ret=None, gen=_force)
S(0x473b70, 'ZLNKWHANDS::ForceLHandItem', 'thiscall', None, ret=None, gen=_force)
S(0x472420, 'ZLNKWHANDS::AttachRHandItem', 'thiscall', None, ret=None, gen=_plain_u)
S(0x472400, 'ZLNKWHANDS::AttachLHandItem', 'thiscall', None, ret=None, gen=_plain_u)
S(0x475aa0, 'ZLNKWHANDS::SlipLHandItem', 'thiscall', None, ret=None, gen=_plain)
S(0x475ac0, 'ZLNKWHANDS::SlipRHandItem', 'thiscall', None, ret=None, gen=_plain)
S(0x474700, 'ZLNKWHANDS::LetItemFall', 'thiscall', None, ret=None, gen=_plain_u)
S(0x473b20, 'ZLNKWHANDS::EmptyHands', 'thiscall', None, ret=None, gen=_plain)
S(0x473960, 'ZLNKWHANDS::DestroyRHandItem', 'thiscall', None, ret=None, gen=_plain)
S(0x473910, 'ZLNKWHANDS::DestroyLHandItem', 'thiscall', None, ret=None, gen=_plain)
