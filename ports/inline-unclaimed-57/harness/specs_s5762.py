"""specs_s5762.py - unclaimed-57, batch 62: 0x5c71c0 (GUESS name unnamed_5c71c0). Thiscall, one stack argument (the load
object, ret 4), returns al = 1. Hooked callees: 0x6352f0 writes a fixed dword through its out pointer (logs nothing else); the
readers 0x4e5e60 (two calls) and 0x4e5ea0 each fold in the dword at their DBREAD pointer (the local tmp), so the value 0x6352f0
wrote is observable. The load object's slot +0x68 is a logging stub (argument logged, not the pointer)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _load(c):
    e = c.emu
    v_out = c.rng.getrandbits(32)
    dv = [c.rng.getrandbits(32), c.rng.getrandbits(32)]
    v50 = c.rng.getrandbits(32)
    di = [0]

    def out_fn(em, r):
        em.w32(em.arg32(0), v_out)
        em.ret(eax=0, argbytes=4)
    e.hook(0x6352f0, out_fn)

    def dword_fn(em, r):
        v = dv[di[0] % 2]
        di[0] += 1
        em.ret(eax=v ^ em.r32(em.reg('ecx')), argbytes=0)
    e.hook(0x4e5e60, dword_fn)
    e.hook(0x4e5ea0, lambda em, r: em.ret(eax=v50 ^ em.r32(em.reg('ecx')), argbytes=0))
    vt = e.logging_vtable('load_c71c0', 32, argwords={0x68: 1})
    ld = _rnd(c, 0x40)
    e.w32(ld, vt)
    self_obj = _rnd(c, 0x100)
    return [self_obj, ld]


S(0x5c71c0, 'unnamed_5c71c0 (GUESS) thiscall', 'thiscall', None, ret='al', gen=_load,
  note='unclaimed-57 batch 62; 0x6352f0 and readers 0x4e5e60, 0x4e5ea0 hooked; load slot +0x68 stubbed (logged); returns 1')
