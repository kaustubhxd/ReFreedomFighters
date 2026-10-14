"""specs_s210.py - ladder thread batch 210: ZT1GuideController (CopyEventDataBlock, Init, Command, Save, Load)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
from pe_emu import f32
import ladder_kit as K


def _db(c, extra=None):
    e, r = c.emu, c.rng
    eng = K.engine(c)
    d = K.rnd(c, 0xb00)
    e.w32(eng + 0x9b, d)
    msgid = r.getrandbits(32)
    cam = K.rnd(c, 0x10)
    e.w32(cam, K.vt(c, 'campl', {0xbc: (1, lambda e2, a: (0, None, None))}, nslots=0x40))
    camp = cam if r.random() < 0.7 else 0
    slots = {0x114: (4, lambda e2, a: (msgid, None, None)), 0x58: (1, lambda e2, a: (camp, None, None))}
    e.w32(d, K.vt(c, 'database', slots, nslots=0x50))
    return eng, d


def _copy(c):
    e, r = c.emu, c.rng
    v = r.getrandbits(32)

    def fl(e2, res):
        e2.calllog.append(('DBREAD float', e2.reg('ecx')))
        e2.ret(st0=f32(r.uniform(-10, 10)))

    def ui(e2, res):
        e2.calllog.append(('DBREAD uint', e2.reg('ecx')))
        e2.ret(eax=v)
    e.hook(0x4e5e80, fl)
    e.hook(0x4e5e60, ui)
    return [K.rnd(c, 0x60), K.rnd(c, 0x10)]


def _init(c):
    e, r = c.emu, c.rng
    eng, d = _db(c)
    lst = K.rnd(c, 0x10)
    e.w32(lst, K.vt(c, 'list', {0x218: (1, lambda e2, a: (0, None, None))}, nslots=0x90))
    found = lst if r.random() < 0.6 else 0
    holder = K.rnd(c, 0x10)
    e.w32(holder, K.vt(c, 'lists', {0x25c: (2, lambda e2, a: (found, None, None)),
                                     0x294: (4, lambda e2, a: (lst, None, None))}, nslots=0xb0))
    e.w32(d + 0xadc, holder)
    self_ = K.rnd(c, 0x60)
    g = K.rnd(c, 0x40)
    g8 = K.rnd(c, 0x40)
    e.w32(g + 8, g8)
    e.w32(g, K.vt(c, 'ctlgeom', {0x70: (1, lambda e2, a: (0, None, K.bits3(e2, a[0]))),
                                 0xbc: (1, lambda e2, a: (0, None, None))}, nslots=0x40))
    e.w32(self_ + 0x44, g)
    return [self_]


def _cmd(c):
    r = c.rng
    s = K.rnd(c, 0x60)
    idv = r.choice([0, r.getrandbits(16), 0x1234])
    c.emu.w16(s + 0x48, idv)
    msg = idv if r.random() < 0.6 else r.getrandbits(16)
    msg |= r.getrandbits(16) << 16 if r.random() < 0.3 else 0
    data = 0 if r.random() < 0.2 else K.rnd(c, 8)
    return [s, msg, data]


def _save(c):
    sg = K.rnd(c, 0x10)
    c.emu.w32(sg, K.vt(c, 'save', {0x3c: (1, lambda e2, a: (0, None, None))}, nslots=0x20))
    return [K.rnd(c, 0x60), sg]


def _load(c):
    e, r = c.emu, c.rng
    _db(c)
    lg = K.rnd(c, 0x10)
    v = r.getrandbits(32)

    def rd(e2, a):
        e2.w32(a[0], v)
        return 0, None, None
    e.w32(lg, K.vt(c, 'load', {0x40: (1, rd)}, nslots=0x20))
    return [K.rnd(c, 0x60), lg]


S(0x4c61a0, 'ZT1GuideController::CopyEventDataBlock', 'thiscall', None, ret=None, gen=_copy, note='batch210')
S(0x4c61c0, 'ZT1GuideController::Init', 'thiscall', None, ret=None, gen=_init, note='batch210')
S(0x4c62c0, 'ZT1GuideController::Command', 'thiscall', None, ret='eax', gen=_cmd, note='batch210')
S(0x4c62f0, 'ZT1GuideController::Save', 'thiscall', None, ret='al', gen=_save, note='batch210')
S(0x4c6310, 'ZT1GuideController::Load', 'thiscall', None, ret='al', gen=_load, note='batch210')
