"""specs_s1020.py - unclaimed-04 batch 21 (docs/20-unclaimed-04.md): two slice-3 functions (GUESS labels).
0x5827b0 (thiscall, one stack argument, ret 4) calls the reader 0x4e5e60 with ecx = that argument and stores the result at
this+0x48. The reader is hooked by address (value chosen per case). 0x5332f0 (no arguments) calls WaitForSingleObject from
the IAT (slot 0x676144, stdcall) with the handle at 0x713d28 and timeout 0, then returns al = (result == 0). The import is
a Python stub that returns 0 or WAIT_TIMEOUT (0x102) per case."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _setup_reader(c):
    val = c.rng.getrandbits(32)

    def reader(em, r):
        em.calllog.append(('4e5e60', 0, em.reg('ecx'), ()))
        em.ret(eax=val, argbytes=0)

    c.emu.hook(0x4e5e60, reader)


def _obj_arg(c):
    return [_rnd(c, 0x100), c.rng.getrandbits(32)]


def _setup_wait(c):
    wait_ret = c.rng.choice([0, 0x102, 0x80])
    handle = c.rng.getrandbits(32)
    c.emu.w32(0x713d28, handle)

    def wait(em, r):
        em.calllog.append(('WaitForSingleObject', 0, 0, (em.arg32(0), em.arg32(1))))
        em.ret(eax=wait_ret, argbytes=8)

    c.emu.stub_import('WaitForSingleObject', wait)


def _none(c):
    return []


def _setup_both(c):
    _setup_reader(c)


S(0x5827b0, 'unknown::read_to_48 (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj_arg, setup=_setup_reader,
  note='unclaimed-04 batch 21; reader 0x4e5e60 hooked (GUESS)')
S(0x5332f0, 'unknown::wait_is_zero (unknown) cdecl', 'cdecl', None, ret='al', gen=_none, setup=_setup_wait,
  note='unclaimed-04 batch 21; WaitForSingleObject import stubbed (GUESS)')
