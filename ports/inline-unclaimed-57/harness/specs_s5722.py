"""specs_s5722.py - unclaimed-57, batch 22: 0x49df00 (thiscall, no args, ret) and 0x63a700 (cdecl, one argument, no pop). Both call
operator delete 0x634273 (cdecl, (ptr, size)), which the spec hooks to log its arguments only. 0x49df00's pointer at +4 is set in half
the cases; 0x63a700's argument points 4 bytes into a block whose first dword is the pointer to delete."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _del_hook(c):
    def log(em, r):
        em.calllog.append(('delete', 0, None, (em.arg32(0), em.arg32(1))))
        em.ret(eax=0, argbytes=0)
    c.emu.hook(0x634273, log)


def _df(c):
    _del_hook(c)
    o = _rnd(c, 0x40)
    c.emu.w32(o + 4, 0 if c.rng.random() < 0.5 else c.rng.getrandbits(32))
    return [o]


def _da(c):
    _del_hook(c)
    blk = _rnd(c, 0x40)
    c.emu.w32(blk, c.rng.getrandbits(32))
    return [blk + 4]


S(0x49df00, 'unnamed_49df00 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_df,
  note='unclaimed-57 batch 22; sets vtable 0x68f008; delete(+4, 1) when non-zero (delete logged)')
S(0x63a700, 'unnamed_63a700 (GUESS) cdecl', 'cdecl', None, ret=None, gen=_da,
  note='unclaimed-57 batch 22; delete(dword at arg-4, 1) (delete logged)')
