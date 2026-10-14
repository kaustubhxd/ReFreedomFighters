"""specs_s944.py - area 56 residue 15, claim A3: ZItemWeapon::~ZItemWeapon() (0x46aaf0).

Object: 0x100 random bytes; flags random (bits 0 and 2 both occur). Callees are GUESS recording stubs: 0x46a5e0 (logs its
object), 0x4690b0 (cdecl; logs its two arguments; plain ret), 0x45c510 (cdecl; logs its argument; plain ret)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    def hb(e2, r):
        e2.calllog.append(('Base46a5e0', e2.reg('ecx')))
        e2.ret(argbytes=0)

    def hfree(e2, r):
        e2.calllog.append(('Free4690b0', e2.arg32(0), e2.arg32(1)))
        e2.ret(argbytes=0)

    def hc510(e2, r):
        e2.calllog.append(('C45c510', e2.arg32(0)))
        e2.ret(argbytes=0)

    c.emu.hook(0x46a5e0, hb)
    c.emu.hook(0x4690b0, hfree)
    c.emu.hook(0x45c510, hc510)
    return [_rnd(c, 0x100), c.rng.getrandbits(32)]


S(0x46aaf0, 'ZItemWeapon::~ZItemWeapon (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-56 A3; base 0x46a5e0 and frees stubbed (GUESS recording stubs)')
