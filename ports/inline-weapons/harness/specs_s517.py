"""specs_s517.py - weapons batch 517: hero weapon switch and helpers."""
from pilot import S
from wkit import rnd, stub, obj, b, sysobj, patch_jmp, seq_stub


def _item(c):
    r = c.rng
    t = obj(c, 0x40, {0x308: stub(c, 0, ret=r.choice((0, 1, 2)))})
    it = obj(c, 0x40, {0x2d0: stub(c, 2), 0x2e8: stub(c, 0, ret=t)})
    c.emu.w32(it + 8, rnd(c, 0x40))
    return it


def _use(c):
    r = c.rng
    a, bb = _item(c), _item(c)
    nw = r.choice((0, a, bb))
    cur = r.choice((0, a, bb))
    back = r.choice((0, a, bb, nw))
    sysobj(c, {0x58: seq_stub(c, 1, [nw, back]), 0x4c: stub(c, 1, ret=r.getrandbits(32))})
    self = obj(c, 0xa00, {0x504: stub(c, 0, ret=cur), 0x3ec: stub(c, 1, ret=r.getrandbits(32)),
                          0x3d8: stub(c, 1), 0x45c: stub(c, 2)})
    return [self, r.getrandbits(32)]


def _drop(c):
    r = c.rng
    patch_jmp(c, 0x4748b0, stub(c, 1, rec_ecx=True))
    patch_jmp(c, 0x5e9300, stub(c, 1, rec_ecx=True))
    src = c.emu.alloc(4, 4)
    c.emu.w32(src, rnd(c, 0x460))
    x = obj(c, 0x100, {0x88: stub(c, 2, skip=(1,), ofills=((1, 0, src, 1),))})
    sysobj(c, {0x138: stub(c, 0, ret=x)})
    h = rnd(c, 0xa00)
    c.emu.w8(h + 0x9e7, 0 if r.random() < 0.3 else 1)
    return [h, r.getrandbits(32)]


def _back(c):
    r = c.rng
    patch_jmp(c, 0x4dcbb0, stub(c, 1, rec_ecx=True))
    sysobj(c, {0x58: stub(c, 1, ret=_item(c))})
    h = obj(c, 0xa00, {0x294: stub(c, 2)})
    return [h]


def _type(c):
    r = c.rng
    patch_jmp(c, 0x5aeff0, stub(c, 1, rec_ecx=True, ret=r.getrandbits(32)))
    cur = r.choice((0, r.getrandbits(32)))
    h = obj(c, 0xa00, {0x504: stub(c, 0, ret=cur), 0x438: stub(c, 0, ret=b(c, 0.8))})
    c.emu.w32(h + 0x417, r.getrandbits(32) & ~0x2000000 if r.random() < 0.7 else 0x2000000)
    c.emu.w8(h + 0x65c, r.choice((0, 0, 1)))
    if r.random() < 0.5:
        c.emu.w32(h + 0x658, cur)
    return [h]


def _restore(c):
    r = c.rng
    h = obj(c, 0xa00, {0x504: stub(c, 0, ret=r.choice((0, r.getrandbits(32)))), 0x3dc: stub(c, 0), 0x480: stub(c, 1)})
    c.emu.w32(h + 0x836, r.getrandbits(32))
    c.emu.w32(h + 0x832, 0 if r.random() < 0.4 else r.getrandbits(32))
    return [h]


S(0x590140, 'ZFFHERO::ControlUseOneAlone', 'thiscall', None, ret=None, gen=_use)
S(0x593ee0, 'ZFFHERO::PerformDrop', 'thiscall', None, ret=None, gen=_drop)
S(0x591f00, 'ZFFHERO::GetItemBack', 'thiscall', None, ret='eax', gen=_back)
S(0x591080, 'ZFFHERO::DetachItemBack', 'thiscall', None, ret='eax', gen=_back)
S(0x591b20, 'ZFFHERO::GetFFItemType', 'thiscall', None, ret='eax', gen=_type)
S(0x594590, 'ZFFHERO::RestoreItem', 'thiscall', None, ret=None, gen=_restore)
