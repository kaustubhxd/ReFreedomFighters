"""specs_s962.py - area 56 band, claim A25 (0x537880).

this (0x5400 random bytes): +0x52fa is a fake object pointer in about 4 cases in 5 (else zero). 0x4690b0 is hooked (emu.hook):
it logs ecx and returns with a plain ret. vt slot 0x194 is a GUESS recording stub (thiscall, no arguments; returns a random dword).
ret='eax' (the tail target's eax)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    e = c.emu
    rng = c.rng

    def h4690(e2, r):
        e2.calllog.append(('H4690b0', e2.reg('ecx')))
        e2.ret(argbytes=0)

    def h194(e2, r):
        e2.calllog.append(('V194', e2.reg('ecx')))
        e2.ret(eax=rv, argbytes=0)

    c.emu.hook(0x4690b0, h4690)
    rv = rng.getrandbits(32)
    vt = e.fake_vtable('vt537880', 0x200, {0x194: h194})
    this = _rnd(c, 0x5400)
    e.w32(this, vt)
    fld = _rnd(c, 0x40) if rng.random() < 0.8 else 0
    e.w32(this + 0x52fa, fld)
    return [this]


S(0x537880, 'unnamed 0x537880 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-56 A25; 0x4690b0 hooked; vt slot 0x194 is a GUESS recording stub')
