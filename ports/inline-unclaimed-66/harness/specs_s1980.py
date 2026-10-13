"""specs_s1980.py - slice-5 batch 114 (GUESS name): 0x4b0cd0

THISCALL(this, dbread), ret 4: reads 5 dwords from dbread and stores at this+0x48, +0x54, +0x58, +0x5c, +0x64.
Also clears this+0x50.

0x4e5e60 is the DBREAD dword reader stub (THISCALL, takes dbread, returns u32)."""
from pilot import S


def _gen(c):
    # Create a DBREAD-like object (just enough for the stub to work)
    dbread = c.emu.alloc(0x100, 4)
    c.emu.wbytes(dbread, bytes(c.rng.getrandbits(8) for _ in range(0x100)))

    # Hook 0x4e5e60: DBREAD dword reader
    def h4e5e60(e, r):
        dbread_obj = e.reg('ecx')
        val = c.rng.randint(0, 0xffffffff)
        e.calllog.append(('0x4e5e60 (dword reader)', 0x4e5e60, dbread_obj, ()))
        e.ret(eax=val, argbytes=0)
    c.emu.hook(0x4e5e60, h4e5e60)

    # Create the this object
    this = c.emu.alloc(0x80, 4)
    c.emu.wbytes(this, bytes(c.rng.getrandbits(8) for _ in range(0x80)))

    return [this, dbread]


S(0x4b0cd0, 'GUESS FUN_004b0cd0 (DBREAD reader loop)', 'thiscall', None, ret=None,
  gen=_gen, note='slice-5 batch 1980 (114); 0x4e5e60 DBREAD dword reader stub')
