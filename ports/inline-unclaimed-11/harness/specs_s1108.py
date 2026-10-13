"""specs_s1108.py - unclaimed-11 batch 8 (core-todo residue-10): ZActionReloadItem::Save(ZSaveGame&) at 0x487060, thiscall,
ret 4. The body saves a float (this+0x30) through save slot 0x4c; if this+0x2c is nonzero it saves 1 through slot 0x60, asks
this for an id through its own slot 0x28 (argument this+0x2c) and saves that id through slot 0x3c; otherwise it saves 0 through
slot 0x60. The save object and the item object are serial_stubs.mkobj objects whose slots are rec stubs (unverified callees,
stubbed); one rec serves all save slots so the ring logs the order. The item's slot 0x28 returns a random id. The
this+0x2c field is zero in about a third of the cases."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S


def _save(c):
    # this: an item object whose vtable slot 0x28 returns a random id; +0x30 float, +0x2c dword (zero in a third).
    item = ss.mkobj(c, {0x28: ss.rec(c, 1, ret=c.rng.getrandbits(32))}, size=0x40)
    c.emu.w32(item + 0x30, c.rng.getrandbits(32))
    c.emu.w32(item + 0x2c, 0 if c.rng.random() < 0.33 else c.rng.getrandbits(32))
    r = ss.rec(c, 1)
    save = ss.mkobj(c, {0x4c: r, 0x60: r, 0x3c: r}, size=0x40)
    return [item, save]


S(0x487060, 'ZActionReloadItem::Save (unknown) thiscall', 'thiscall', None, ret=None, gen=_save,
  note='unclaimed-11 batch 8 (residue 10); save and item objects stubbed')
