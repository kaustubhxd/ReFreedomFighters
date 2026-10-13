"""specs_s975.py - unclaimed-80 residue-19 batch 53 (docs/20-unclaimed-80.md), see src/batch975.cpp. 0x659000 and 0x612030 are GUESS
helpers (no claim yet), hooked by address with recording thiscall stubs (log ecx and one argument). 0x659000 returns a block whose +0xc
dword is random. The argument's +0x10 dword is zero half the time. self is a 0x182b0-byte zeroed block whose field at +0x182a5 holds a
pointer (random, and zero 20% of the time)."""
from pilot import S


def _gen(c):
    blk = c.emu.alloc(0x20, 4)
    c.emu.wbytes(blk, bytes(0x20))
    c.emu.w32(blk + 0xc, c.rng.getrandbits(32))
    fld = c.emu.alloc(0x40, 4)
    c.emu.wbytes(fld, bytes(0x40))

    def h659(em, r):
        c.emu.calllog.append(('659000', None, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=blk, argbytes=4)

    def h612(em, r):
        c.emu.calllog.append(('612030', None, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    c.emu.hook(0x659000, h659)
    c.emu.hook(0x612030, h612)
    self_o = c.emu.alloc(0x182b0, 4)
    c.emu.wbytes(self_o, bytes(0x182b0))
    c.emu.w32(self_o + 0x182a5, 0 if c.rng.random() < 0.2 else fld)
    a = c.emu.alloc(0x20, 4)
    c.emu.wbytes(a, bytes(0x20))
    c.emu.w32(a + 0x10, 0 if c.rng.random() < 0.5 else c.rng.getrandbits(32))
    return [self_o, a, c.rng.getrandbits(32)]


S(0x6160b0, 'two GUESS helper calls (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-80 residue-19; GUESS helpers 0x659000 and 0x612030 hooked by address; two stack args, ret 8')
