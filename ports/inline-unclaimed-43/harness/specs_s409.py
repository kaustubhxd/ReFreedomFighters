"""specs_s409.py - residue 2 row 0x5f98a0 (thiscall, no arguments). Member p = [this+4] is a zeroed block or NULL (1 in 3). The
callee 0x5f97e0 is hooked by address and logged (GUESS: body not ported); the delete helper 0x634273 is hooked and logged as
in batch 381. The object's first dword is random before the vtable store, so the store shows in the heap compare."""
from pilot import S
import engine_stubs as E


def _setup(c):
    c.emu.hook(0x5f97e0, lambda em, r: (em.calllog.append(('clean5f97e0', 0, em.reg('ecx') & 0xffffffff, ())),
                                        em.ret(eax=0, argbytes=0)))
    c.emu.hook(0x634273, lambda em, r: (em.calllog.append(('delete', 0, 0, (em.arg32(0), em.arg32(1)))),
                                        em.ret(eax=0, argbytes=0)))


def _gen(c):
    r = c.rng
    o = E.zero_obj(c, 0x20)
    c.emu.wbytes(o, bytes(r.getrandbits(8) for _ in range(0x20)))
    p = 0 if r.random() < 0.33 else E.zero_obj(c, 0x40)
    c.emu.w32(o + 4, p)
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x5f98a0, 'vtable store, clean and free member (residue 2) thiscall', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='residue 2 batch 409; callees 0x5f97e0 hooked (GUESS) and delete 0x634273 hooked')
