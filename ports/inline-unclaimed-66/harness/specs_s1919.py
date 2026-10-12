"""specs_s1919.py - unclaimed-66 batch 1919: GUESS FUN_004a35d0, thiscall with two stack arguments (ret 8), void.

The DBREAD dword reader 0x4e5e60 is a STUB (a hook: logs ECX and returns a random dword). The object is 0x80 random bytes."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _read(c):
    def h(e, r):
        e.calllog.append(('DBREAD dword (stub)', 0x4e5e60, e.reg('ecx'), ()))
        e.ret(eax=c.rng.getrandbits(32), argbytes=0)
    c.emu.hook(0x4e5e60, h)
    return [_rnd(c, 0x80), c.rng.getrandbits(32), _rnd(c, 0x40)]


S(0x4a35d0, 'GUESS FUN_004a35d0 (DBREAD dword into +0x50)', 'thiscall', None, ret=None, gen=_read,
  note='unclaimed-66 batch 1919; slice-5 (GUESS); DBREAD reader 0x4e5e60 STUBBED')
