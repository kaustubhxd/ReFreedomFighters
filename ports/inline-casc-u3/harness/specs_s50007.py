"""specs_s50007.py - u3 (Sonnet) batch 50007, tier H. 0x56f590: the engine table (unaligned pointer [sys+0x9b]) answers slot 0x58(id) from an id -> widget map built from the ten id fields of this (widgets for
+0x1b1 and +0x1b9 are always present, +0x1a5 sometimes missing), slot 0x138 (R with slot 0x60) and slot 0x4c; widgets have slots 0x248, 0x258 (the float pair is recorded through deref) and 0xbc;
0x562440 / 0x563510 / 0x563610 / 0x56f2d0 hooked; the object is random-filled so every unaligned store is observable."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

IDS = (0x1a1, 0x1a9, 0x199, 0x1ad, 0x1b1, 0x1b5, 0x1bd, 0x1c5, 0x1b9, 0x1a5)


def _g56f590(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x562440, 0, this=True, ret=r.getrandbits(32))
    hook_rec(c, 0x563510, 1, this=True, pop=4, ret=r.getrandbits(32))
    hook_rec(c, 0x563610, 1, this=True, pop=4, ret=r.getrandbits(32))
    hook_rec(c, 0x56f2d0, 0, this=True, ret=r.getrandbits(32))
    me = rnd(c, 0x600)
    ids = {}
    for off in IDS:
        v = r.getrandbits(32)
        e.wbytes(me + off, v.to_bytes(4, 'little'))
        ids[off] = v
    widgets = {}
    for off in IDS:
        if off == 0x1a5 and r.random() < 0.3:
            continue
        if r.random() < 0.12 and off not in (0x1b1, 0x1b9):
            continue
        widgets[ids[off]] = obj(c, 0x20, {0x248: pystub(c, 1, this=True), 0x258: pystub(c, 2, this=True, deref={0: 2}), 0xbc: pystub(c, 1, this=True)},
                                nslots=0x25c // 4)
    R = obj(c, 0x20, {0x60: pystub(c, 2, this=True)}, nslots=0x64 // 4)
    so = sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: widgets.get(em.arg32(0), 0)),
                                0x138: pystub(c, 0, this=True, ret=R), 0x4c: pystub(c, 2, this=True, ret=lambda em, k: r.getrandbits(32))})
    return [me]


S(0x56f590, 'GUESS set up panel widgets by stored ids', 'thiscall', None, ret=None, gen=_g56f590, note='batch50007')
