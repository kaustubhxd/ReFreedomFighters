"""specs_s6361.py - unclaimed-63 batch 61: 0x5d3740 (ZShakeCamera::Save; thiscall, one stack argument s, ret 4, returns true in al).
Fakes per case (the image is restored between runs): s is a fake save object whose vtable slot +0x64 (thiscall, one argument, ret 4)
records ECX and its argument; this is a 0x100-byte block with random bytes (so the unaligned dwords at +0x55..+0x64 and the flag bit 0x40
at +4 vary), and the save calls record the four values."""
from pilot import S


def _gen_3740(c):
    e = c.emu
    s = e.alloc(0x40, 4)
    e.wbytes(s, bytes(0x40))
    e.w32(s, e.fake_vtable('save', 0x400 // 4, {0x64: lambda em, a: (em.calllog.append(('save.64', 0x64, em.reg('ecx'), (em.arg32(0),))),
                                                                       em.ret(eax=0, argbytes=4))}))
    this = e.alloc(0x100, 4)
    e.wbytes(this, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    e.mu.ctl_flush_tb()
    return [this, s]


S(0x5d3740, 'ZShakeCamera::Save thiscall', 'thiscall', None, ret='al', gen=_gen_3740,
  note='unclaimed-63 batch 61; camera area had 300-case results only')
