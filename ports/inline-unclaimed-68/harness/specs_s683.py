"""specs_s683.py - unclaimed-68 batch 3 (claim 3): ZGROUP::FindMasterGeom (0x4408b0). The object's slot +0x2c0 is a logging
slot that takes (name, 2) and returns a value fixed by the gen, so the original and the port return the same dword."""
from pilot import S
from engine_stubs import zero_obj, logged_obj


def _find(c):
    ret = c.rng.getrandbits(32)
    name = c.emu.alloc(16, 4)
    c.emu.wbytes(name, bytes(c.rng.getrandbits(8) for _ in range(16)))
    o = logged_obj(c, 'ZGroupObj', 0x100, impl={0x2c0: lambda e, a: (ret, None)}, argwords={0x2c0: 2})
    return [o, name]


S(0x4408b0, 'ZGROUP::FindMasterGeom (unknown) thiscall const', 'thiscall', None, ret='eax', gen=_find,
  note='unclaimed-68 batch 3; forwards (name, 2) to slot +0x2c0 and returns its EAX')
