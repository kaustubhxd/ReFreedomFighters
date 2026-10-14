"""specs_s978.py - area 56 band, claim A44 (0x534510).

this is a 0x1100-byte object of random bytes. [this+8] is a random heap pointer or zero. [this] is a fake object (its first dword a
fake vtable whose slot 0 is a GUESS recording stub, thiscall, one argument) in about four cases in five, else zero. [this+4] is a
random heap pointer or zero. 0x634273 is hooked (recording, plain ret, the cdecl caller pops). ret=None (void)."""
from pilot import S


def _gen(c):
    e = c.emu
    rng = c.rng

    def h0(e2, r):
        e2.calllog.append(('V0', e2.reg('ecx'), e2.arg32(0)))
        e2.ret(argbytes=4)

    def hfree(e2, r):
        e2.calllog.append(('Free634273', e2.arg32(0), e2.arg32(1)))
        e2.ret(argbytes=0)

    e.hook(0x634273, hfree)
    vt = e.fake_vtable('vt534510', 0x40, {0: h0})
    p = 0
    if rng.random() < 0.8:
        p = e.alloc(0x40, 4)
        e.wbytes(p, bytes(rng.getrandbits(8) for _ in range(0x40)))
        e.w32(p, vt)
    this = e.alloc(0x1100, 4)
    e.wbytes(this, bytes(rng.getrandbits(8) for _ in range(0x1100)))
    e.w32(this, p)
    e.w32(this + 4, 0 if rng.random() < 0.3 else e.alloc(0x20, 4))
    e.w32(this + 8, 0 if rng.random() < 0.3 else e.alloc(0x20, 4))
    return [this]


S(0x534510, 'unnamed 0x534510 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-56 A44; vt slot 0 is a GUESS recording stub; 0x634273 hooked')
