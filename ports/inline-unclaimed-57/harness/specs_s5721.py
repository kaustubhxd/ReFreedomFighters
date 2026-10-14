"""specs_s5721.py - unclaimed-57, batch 21: 0x6044c0 (GUESS). No arguments, returns eax = 0 (cdecl, no pop). The assert hook 0x7003b0 is
always a logging stub (a zero hook made the original fault in batch 11 and batch 12; the null branch is therefore not exercised)."""
from pilot import S


def _hook(c):
    c.emu.w32(0x7003b0, c.emu.stub_fn('assert', lambda em, r: (em.calllog.append(('assert', 0, None, ())), em.ret(eax=0))))


def _none(c):
    _hook(c)
    return []


S(0x6044c0, 'unnamed_6044c0 (GUESS) cdecl', 'cdecl', None, ret='eax', gen=_none,
  note='unclaimed-57 batch 21; calls the assert hook when non-null; returns 0')
