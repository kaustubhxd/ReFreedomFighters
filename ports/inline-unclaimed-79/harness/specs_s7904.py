"""specs_s7904.py - unclaimed-79 batch 4 (docs/20-unclaimed-79.md): ZMatPosAnim::RegisterMessages (0x4a5c20). The system interface
global 0x70039c points at a fake object whose +0x9b is a logging fake with slot +0x114 (four arguments, returns a random dword).
No arguments; the nine stored words (0x7002fc..0x70031c) are compared as globals. The gen sets the global words to random values
first so a missing store shows up."""
from pilot import S
from helpers_trial import logged_slot


def _rnd(c, n):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _reg(c):
    for addr in (0x7002fc, 0x700300, 0x700304, 0x700308, 0x70030c, 0x700310, 0x700314, 0x700318, 0x70031c):
        c.emu.w16(addr, c.rng.getrandbits(16))
    vt = c.emu.fake_vtable('ZEngineDataBase-reg', 0x50, {
        0x114: logged_slot('ZEngineDataBase::RegisterZMsg', eax=c.rng.getrandbits(32), argbytes=16),
    })
    t = _rnd(c, 0x100)
    c.emu.w32(t, vt)
    sys_ = _rnd(c, 0x100)
    c.emu.w32(sys_ + 0x9b, t)
    c.emu.w32(0x70039c, sys_)
    return []


S(0x4a5c20, 'ZMatPosAnim::RegisterMessages() cdecl', 'cdecl', None, ret=None, gen=_reg,
  note='unclaimed-79 batch 4; nine slot 0x114 registrations (four args each) stored as words at 0x7002fc..0x70031c')
