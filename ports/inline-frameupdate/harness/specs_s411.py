"""specs_s411.py - batch 411: ZBaseGeom::GetRoomList, ZBaseGeom::GetCen, MYSTR::c_str (inference)."""
from pilot import S
import fu_kit as K


def _rl(c):
    r = c.rng
    e = c.emu
    K.hooks(c, {})
    rmo = K.obj(c, 0x40, {0x5c: K.fn(c, 'rmo.roomlist', 1, ret=K.rnd(c, 0x20))}, 'rmo')
    rm = K.rnd(c, 0x40)
    e.w32(rm + 8, rmo)
    so = K.rnd(c, 0x100)
    e.w32(so + 0x9b, rm)
    e.w32(0x70039c, so)
    g = K.rnd(c, 0x80)
    e.w16(g + 0x5c, r.choice([0, 0, 1, 2, 7, 0xffff, r.getrandbits(16)]))
    return [g]


def _cen(c):
    return [K.rnd(c, 0x60), K.vec(c, 3, -100, 100, pad=0)]


def _cstr(c):
    s = K.rnd(c, 0x10)
    return [s]


S(0x4db550, 'ZBaseGeom::GetRoomList', 'thiscall', None, ret='eax', gen=_rl, note='batch411')
S(0x4daf90, 'ZBaseGeom::GetCen', 'thiscall', None, ret=None, gen=_cen, note='batch411')
S(0x4cc1d0, 'MYSTR::c_str (inference)', 'thiscall', None, ret='eax', gen=_cstr, note='batch411')
