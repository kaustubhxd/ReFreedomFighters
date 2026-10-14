"""specs_s961.py - area 56 band, claim A24 (0x533b80).

The global at 0x70039c is a fake object (0x2000 random bytes) whose +0x1a9f dword points at a second fake object; its vtable
slot 0x160 is a GUESS recording stub (thiscall, one argument; logs ecx and the argument; returns a random dword). ret='eax'."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen_a24(c):
    e = c.emu
    rng = c.rng

    def h160(e2, r):
        e2.calllog.append(('V160', e2.reg('ecx'), e2.arg32(0)))
        e2.ret(eax=rv, argbytes=4)

    rv = rng.getrandbits(32)
    vt = e.fake_vtable('vt533b80', 0x200, {0x160: h160})
    objB = _rnd(c, 0x100)
    e.w32(objB, vt)
    objA = _rnd(c, 0x2000)
    e.w32(objA + 0x1a9f, objB)
    e.w32(0x70039c, objA)
    return []


S(0x533b80, 'unnamed 0x533b80 (unknown) cdecl', 'cdecl', None, ret='eax', gen=_gen_a24,
  note='unclaimed-56 A24; vt slot 0x160 is a GUESS recording stub; global 0x70039c is a fake object')
