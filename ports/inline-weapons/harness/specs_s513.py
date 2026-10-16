"""specs_s513.py - weapons batch 513: SetAmmoFor, Check/GetRHandFireTarget."""
from pilot import S
from wkit import rnd, stub, obj, b, sysobj, patch_jmp, vec, fedge
from specs_s504 import _tgt


def _setammo(c):
    r = c.rng
    patch_jmp(c, 0x4cc1d0, stub(c, 0, rec_ecx=True, ret=c.emu.alloc(8, 4)))
    patch_jmp(c, 0x4cbec0, stub(c, 0))
    s = obj(c, 0x40, {0x2c: stub(c, 3, cdecl=True)})
    l = obj(c, 0x10, {0x20: stub(c, 2, ret=s)})
    c.emu.w32(0x700390, l)
    w = obj(c, 0x40, {0x1d8: stub(c, 2, skip=(0,), ret=r.getrandbits(32))})
    a = obj(c, 0x40, {0x324: stub(c, 1)})
    self = obj(c, 0x600, {0x55c: stub(c, 1, ret=a if r.random() < 0.8 else 0)})
    return [self, w, r.choice((0, 5, -1 & 0xffffffff, -30 & 0xffffffff, r.getrandbits(32)))]


def _world(c, hit):
    r = c.rng
    hv = c.emu.alloc(4, 4)
    c.emu.w32(hv, hit)
    w = obj(c, 0x40, {0x2e0: stub(c, 6, skip=(0,), lcopy=((0, 6), (0, 1, 0x34)), ofills=((0, 0x44, hv, 1),),
                                  ret=b(c, 0.4))})
    return w


def _fire(c):
    r = c.rng
    geom = r.getrandbits(32)
    g = obj(c, 0x40, {0x84: stub(c, 1, skip=(0,), adds=((0, vec(c, 3, -50, 50), 3),))})
    rm = sysobj(c, {0x58: stub(c, 1, ret=g if r.random() < 0.8 else 0)})
    c.emu.w32(rm + 0xadc, _world(c, geom if r.random() < 0.5 else r.getrandbits(32)))
    gg = rnd(c, 0x40)
    for j in range(3):
        c.emu.wf32(gg + 0x24 + 4 * j, r.uniform(-100, 100))
    m = rnd(c, 0x20)
    c.emu.w32(m + 8, gg)
    w = obj(c, 0x400, {0x348: stub(c, 0, ret=m if r.random() < 0.85 else 0),
                       0x84: stub(c, 1, skip=(0,), adds=((0, vec(c, 3, -5, 5), 3),)),
                       0x32c: stub(c, 1, skip=(0,), lcopy=((0, 3),))})
    self = obj(c, 0x600, {0x50c: stub(c, 0, ret=w if r.random() < 0.9 else 0),
                          0x84: stub(c, 1, skip=(0,), adds=((0, vec(c, 3, -5, 5), 3),))})
    _tgt(c, self, 0x26a)
    c.emu.w32(self + 0x26a + 0x39, geom)
    c.emu.w8(self + 0x3a4, 0 if r.random() < 0.15 else 1)
    return [self]


S(0x475740, 'ZLNKWHANDS::SetAmmoFor', 'thiscall', None, ret=None, gen=_setammo)
S(0x472930, 'ZLNKWHANDS::CheckRHandFireTarget', 'thiscall', None, ret='al', gen=_fire)
S(0x4744f0, 'ZLNKWHANDS::GetRHandFireTarget', 'thiscall', None, ret='eax', gen=_fire)
