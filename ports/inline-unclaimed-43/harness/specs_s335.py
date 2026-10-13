"""specs_s335.py - area 71 batch 335: scalar deleting destructor (0x5ed4e0), thiscall, one stack argument (flags), ret 4.
Vtable 0x6b813c at [this]; the base destructor 0x5ec7e0 is hooked and logged (its body is another function); flags bit 0
gives __builtin_delete(this, 0xf7) (hooked and logged)."""
from pilot import S
import engine_stubs as E


def _hook(c):
    c.emu.hook(0x5ec7e0, lambda em, r: (em.calllog.append(('base_dtor', 0, em.reg('ecx'), ())), em.ret(eax=0, argbytes=0)))
    c.emu.hook(0x634273, lambda em, r: (em.calllog.append(('builtin_delete', 0, 0, (em.arg32(0), em.arg32(1)))),
                                        em.ret(eax=0, argbytes=0)))


def _gen(c):
    o = E.zero_obj(c, 0x100)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    flags = c.rng.getrandbits(32)
    c.emu.mu.ctl_flush_tb()
    return [o, flags]


S(0x5ed4e0, 'scalar deleting destructor with base (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen, setup=_hook,
  note='area 71 batch 335 (leaf, residue 10); base dtor 0x5ec7e0 and __builtin_delete hooked')
