"""specs_s6360.py - unclaimed-63 batch 60: 0x577e20 (ZObjectives::OnKeyPress; thiscall, one stack argument key, ret 4).
Fakes per case (the image is restored between runs; hooks set in gen):
  * this: a fake vtable with slot +0x84 (thiscall, no arguments, returns O) that records ECX;
  * O: a fake vtable with slot +0x300 (thiscall, no arguments, plain ret) that records ECX;
  * 0x574250 (thiscall, one argument, ret 4; other area's code): a hook that records ECX and its argument.
The key is 0x102 or 0x103 in half the cases (the first path), else a random dword (the tail path)."""
from pilot import S


def _gen_e20(c):
    e = c.emu
    this = e.alloc(0x100, 4)
    e.wbytes(this, bytes(0x100))
    O = e.alloc(0x40, 4)
    e.wbytes(O, bytes(0x40))
    e.w32(O, e.fake_vtable('O', 0x400 // 4, {0x300: lambda em, a: (em.calllog.append(('O.300', 0x300, em.reg('ecx'), ())), em.ret(eax=0, argbytes=0))}))
    e.w32(this, e.fake_vtable('this', 0x400 // 4, {0x84: lambda em, a: (em.calllog.append(('this.84', 0x84, em.reg('ecx'), ())), em.ret(eax=O, argbytes=0))}))
    e.hook(0x574250, lambda em, a: (em.calllog.append(('h.574250', None, em.reg('ecx'), (em.arg32(0),))), em.ret(eax=0, argbytes=4)))
    e.mu.ctl_flush_tb()
    key = c.rng.choice([0x102, 0x103]) if c.rng.random() < 0.5 else c.rng.getrandbits(32)
    return [this, key]


S(0x577e20, 'ZObjectives::OnKeyPress thiscall', 'thiscall', None, ret=None, gen=_gen_e20,
  note='unclaimed-63 batch 60; 0x574250 hooked (tail target)')
