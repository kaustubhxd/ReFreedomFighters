"""specs_s972.py - area 56 band, claim A38 (0x526ff0).

this is a 0x40-byte object of random bytes whose first dword is a fake vtable; the dword at +0x19 is 2 in about half the cases.
The vtable slots 0x30, 0x28 and 0x24 are GUESS recording stubs (thiscall, no arguments; each logs ecx). out is a 4-byte random
buffer. ret='al'."""
from pilot import S


def _gen(c):
    e = c.emu
    rng = c.rng

    def hcall(name):
        def h(e2, r):
            e2.calllog.append((name, e2.reg('ecx')))
            e2.ret(argbytes=0)
        return h

    vt = e.fake_vtable('vt526ff0', 0x80,
                       {0x30: hcall('V30'), 0x28: hcall('V28'), 0x24: hcall('V24')})
    this = e.alloc(0x40, 4)
    e.wbytes(this, bytes(rng.getrandbits(8) for _ in range(0x40)))
    e.w32(this, vt)
    if rng.random() < 0.5:
        e.w32(this + 0x19, 2)
    out = e.alloc(4, 4)
    e.w32(out, rng.getrandbits(32))
    return [this, out]


S(0x526ff0, 'unnamed 0x526ff0 (unknown) thiscall', 'thiscall', None, ret='al', gen=_gen,
  note='unclaimed-56 A38; vt slots 0x30/0x28/0x24 are GUESS recording stubs')
