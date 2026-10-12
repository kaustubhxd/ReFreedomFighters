"""specs_s1925.py - unclaimed-66 batch 1925: two GUESS scalar deleting destructors (thiscall, one flag argument, ret 4, return this).

The flag's bit 0 is random, so the CRT free runs in about half the cases; the free is hooked by address (it records ptr and size). The object is
0x40 random bytes."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _free_hook(c):
    """The CRT free (cdecl free(ptr, size)) at 0x634273 is hooked by address: it records (ptr, size) and does nothing."""
    def h(e, r):
        e.calllog.append(('CRT free 0x634273 (hook)', 0x634273, None, (e.arg32(0), e.arg32(1))))
        e.ret(eax=0, argbytes=0)
    c.emu.hook(0x634273, h)


def _dtor(c):
    _free_hook(c)
    obj = _rnd(c, 0x40)
    return [obj, c.rng.getrandbits(32)]


S(0x608150, 'GUESS FUN_00608150 (scalar deleting dtor, vtable 0x6bc88c)', 'thiscall', None, ret='eax', gen=_dtor,
  note='unclaimed-66 batch 1925; slice-5 (GUESS); CRT free path not run (gap)')
S(0x616b10, 'GUESS FUN_00616b10 (scalar deleting dtor, vtable 0x6bdc38)', 'thiscall', None, ret='eax', gen=_dtor,
  note='unclaimed-66 batch 1925; slice-5 (GUESS); CRT free path not run (gap)')
