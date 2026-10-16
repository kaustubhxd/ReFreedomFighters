"""specs_s841.py - area 50, batch 841: MapIconClear, CActionController::Command, GUESS FUN_4778e0. Callees hooked/logged;
icon objects are fake objects with a logged vt +8; the arguments of the GUESS entry include floats."""
import struct
from pilot import S, F
from anim_common import only_hooks, logged_fn, rnd, vt_object, vslot


def _icons(c):
    e, r = c.emu, c.rng
    only_hooks(c, {})
    self = vt_object(c, 0x800, {}, nslots=0x10, name='osd')
    for i in range(0x18):
        ic = vt_object(c, 0x40, {8: vslot('icon.clear', 0)}, nslots=0x10, name='icon%d' % i)
        e.w8(ic + 0x35, r.getrandbits(8))
        e.w32(self + 0x4cc + 4 * i, ic)
    e.w32(self + 0x69d, r.getrandbits(32))
    return [self]


def _cmd(c):
    e, r = c.emu, c.rng
    only_hooks(c, {0x49fa80: logged_fn('AddEvaluator', 1), 0x4a1850: logged_fn('RemoveEvaluator', 1)})
    self = rnd(c, 0x900)
    add, rem = r.getrandbits(16), r.getrandbits(16)
    e.w16(self + 0x8b0, add)
    e.w16(self + 0x8b2, rem)
    cmd = r.choice([add, rem, r.getrandbits(16)])
    return [self, cmd, r.getrandbits(32)]


def _guess(c):
    e, r = c.emu, c.rng
    only_hooks(c, {0x465a80: logged_fn('ZIK465a80', 7)})
    self = rnd(c, 0x900)
    e.w8(self + 0x726, r.choice([0, 1]))
    e.w32(self + 0x64c, r.choice([10, 3]))
    return [self, r.getrandbits(32), F(c.fv(-9, 9)), F(c.fv(-9, 9)), r.getrandbits(32), r.getrandbits(32),
            F(c.fv(-9, 9)), F(c.fv(-9, 9))]


S(0x5aa6e0, 'ZOnScreenDisplay::MapIconClear', 'thiscall', None, gen=_icons, note='area50 batch841')
S(0x49ff20, 'CActionController::Command', 'thiscall', None, ret='eax', gen=_cmd, note='area50 batch841')
S(0x4778e0, 'GUESS FUN_4778e0', 'thiscall', None, gen=_guess, note='area50 batch841 GUESS name')
