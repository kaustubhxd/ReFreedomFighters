"""specs_s2482.py - decomp area 24, batch 2482.
0x454490 ZGATE::Load(ZLoadGame*), thiscall, ret 4, AL: base load 0x45f3c0 (recorder, AL, fixed per case); when set, slot 0x68 of the
load object with this+0x5a (recorder), slot 0x40 with this+0x5c (recorder), AL = 1; otherwise AL is the base result.
0x44a610 ZLIST::RemoveNotifyGeom(unsigned int), thiscall, ret 4: child at +0x1c; slot 0x40 of the child with the argument (recorder,
returns AL, fixed per case); when set, slot 0x14 (recorder, returns a fixed dword); when that is 0, slot 0 with 1 (recorder) if the
child is still set; then the pointer is cleared (kept when the slot 0x14 result is nonzero)."""
from pilot import S
from recruits_util import rnd, pystub, obj, hook_rec, clear_hooks


def _load(c):
    clear_hooks(c)
    r = c.rng
    v = r.choice([0, 1, 0x101])
    hook_rec(c, 0x45f3c0, 1, this=True, ret=v)
    ld = obj(c, 0x40, {0x68: pystub(c, 1), 0x40: pystub(c, 1)})
    return [rnd(c, 0x100), ld]


def _notify(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    a40 = r.choice([0, 1, 0x101])
    a14 = r.choice([0, 0x7f])
    o = rnd(c, 0x100)
    if r.random() < 0.8:
        child = obj(c, 0x40, {0x40: pystub(c, 1, ret=a40), 0x14: pystub(c, 0, ret=a14), 0x0: pystub(c, 1)})
        e.w32(o + 0x1c, child)
    else:
        e.w32(o + 0x1c, 0)
    return [o, r.getrandbits(32)]


S(0x454490, 'ZGATE::Load', 'thiscall', None, ret='al', gen=_load, note='batch2482')
S(0x44a610, 'ZLIST::RemoveNotifyGeom', 'thiscall', None, ret=None, gen=_notify, note='batch2482')
