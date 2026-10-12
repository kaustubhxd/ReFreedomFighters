"""specs_s6362.py - unclaimed-63 batch 62: 0x51be20 (GUESS FUN_51be20; thiscall, two stack arguments a and b, ret 8, returns eax).
Fakes per case (the image is restored between runs; hooks set in gen):
  * this: a 0x800-byte random block, with its words at +0x207 and +0x5d7 set from a's low word in a third of the cases each (so the
    first and second paths run);
  * this's vtable slot +0x394 (thiscall, one argument, ret 4) records ECX and its argument;
  * b is a random 0x40-byte heap block (its +0x28, +0x2c, +0x30 are the copied values);
  * 0x5122f0 (thiscall, two arguments, ret 8; another area's code): a hook that records ECX and its arguments and returns a random dword."""
from pilot import S


def _gen_be20(c):
    e = c.emu
    this = e.alloc(0x800, 4)
    e.wbytes(this, bytes(c.rng.getrandbits(8) for _ in range(0x800)))
    a_low = c.rng.getrandbits(16)
    r = c.rng.random()
    if r < 1 / 3:
        e.wbytes(this + 0x207, a_low.to_bytes(2, 'little'))
    elif r < 2 / 3:
        e.wbytes(this + 0x5d7, a_low.to_bytes(2, 'little'))
    a = (c.rng.getrandbits(16) << 16) | a_low
    b = e.alloc(0x40, 4)
    e.wbytes(b, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
    vt = e.fake_vtable('this', 0x400 // 4, {0x394: lambda em, x: (em.calllog.append(('this.394', 0x394, em.reg('ecx'), (em.arg32(0),))),
                                                                  em.ret(eax=0, argbytes=4))})
    e.w32(this, vt)
    e.hook(0x5122f0, lambda em, x: (em.calllog.append(('h.5122f0', None, em.reg('ecx'), (em.arg32(0), em.arg32(1)))),
                                     em.ret(eax=c.rng.getrandbits(32), argbytes=8)))
    e.mu.ctl_flush_tb()
    return [this, a, b]


S(0x51be20, 'GUESS FUN_51be20 thiscall', 'thiscall', None, ret='eax', gen=_gen_be20,
  note='unclaimed-63 batch 62; 0x5122f0 hooked')
