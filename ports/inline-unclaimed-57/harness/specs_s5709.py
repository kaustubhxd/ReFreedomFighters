"""specs_s5709.py - unclaimed-57, batch 9: six call-free leaves from the full function list (names GUESS). No stubs.
0x410100 is cdecl (argument: pointer to a pointer; returns al); 0x4e7c40, 0x4fa700, 0x5eebc0, 0x650dc0 are thiscall (one argument,
callee pops); 0x63ea80 is stdcall (one argument, returns eax). The objects are random 0x800-byte blocks, and the pointer cell for
0x410100 points at one of them."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _thiscall_one(c):
    return [_rnd(c, 0x800), c.rng.getrandbits(32)]


def _ptrptr(c):
    obj = _rnd(c, 0x800)
    cell = _rnd(c, 8)
    c.emu.w32(cell, obj)
    return [cell]


def _stdcall_ptr(c):
    return [_rnd(c, 0x800)]


S(0x410100, 'unnamed_410100 (GUESS) cdecl', 'cdecl', None, ret='al', gen=_ptrptr,
  note='unclaimed-57 batch 9; leaf; al = byte at (*arg)+4')
S(0x4e7c40, 'unnamed_4e7c40 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_thiscall_one,
  note='unclaimed-57 batch 9; leaf; dword this+9 = arg')
S(0x4fa700, 'unnamed_4fa700 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_thiscall_one,
  note='unclaimed-57 batch 9; leaf; dword this+0x68 = arg')
S(0x5eebc0, 'unnamed_5eebc0 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_thiscall_one,
  note='unclaimed-57 batch 9; leaf; dword this+0x73 = arg')
S(0x650dc0, 'unnamed_650dc0 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_thiscall_one,
  note='unclaimed-57 batch 9; leaf; dword this+0xc = arg')
S(0x63ea80, 'unnamed_63ea80 (GUESS) stdcall', 'stdcall', None, ret='eax', gen=_stdcall_ptr,
  note='unclaimed-57 batch 9; leaf; returns dword at arg+4')
