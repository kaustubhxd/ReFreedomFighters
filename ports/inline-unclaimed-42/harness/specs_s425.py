"""specs_s425.py - unclaimed-42 batch 5 (claim 5): CTargetObtained::SendNotiFyMesssageToGeomsList (0x5c5810), thiscall.
Engine (global 0x70039c, +0x9b): EN answers slot +0x58 with X for the id argument and with a message object M for any
other argument. X answers +0x1e0 (flag) and holds the list at +0x18. The list writes its validity flag through the pointer
argument of slots +0x4c and +0x5c; slot +0x5c returns the next item while the count lasts. M logs slot +0x128."""
import struct
from pilot import S
from engine_stubs import zero_obj, logged_obj, set_global


def _notify(c):
    self_ = zero_obj(c, 0x400)
    ident = c.rng.getrandbits(32) | 1
    c.emu.w32(self_ + 0x14e, ident)
    c.emu.wbytes(self_ + 0x14a, struct.pack('<H', c.rng.getrandbits(16)))
    count = [c.rng.randrange(0, 4)]
    item = zero_obj(c, 0x100)
    msg = logged_obj(c, 'ZObtainedMsg', 0x140, impl={}, argwords={0x128: 3})

    def list_flag(e, a):
        e.w32(a[0], 1 if count[0] > 0 else 0)
        return (None, None)

    def list_next(e, a):
        if count[0] > 0:
            count[0] -= 1
        e.w32(a[0], 1 if count[0] > 0 else 0)
        return (item, None)

    lst = logged_obj(c, 'ZObtainedList', 0x80, impl={0x4c: list_flag, 0x5c: list_next},
                     argwords={0x4c: 1, 0x5c: 1})
    x = logged_obj(c, 'ZObtainedX', 0x80, impl={0x1e0: lambda e, a: (c.rng.choice([0, 1]), None)}, argwords={0x1e0: 1, 0x128: 3})
    c.emu.w32(x + 0x18, lst)

    def en_58(e, a):
        if a[0] == ident:
            return (x, None)
        return (msg, None)

    en = logged_obj(c, 'ZObtainedEngine', 0x80, impl={0x58: en_58}, argwords={0x58: 1})
    eng = zero_obj(c, 0x400)
    c.emu.w32(eng + 0x9b, en)
    set_global(c, 0x70039c, eng)
    return [self_]


S(0x5c5810, 'CTargetObtained::SendNotiFyMesssageToGeomsList (unknown) thiscall', 'thiscall', None, ret=None,
  gen=_notify, note='unclaimed-42 batch 5; list walk with flag via +0x4c/+0x5c; engine +0x58; message +0x128')
