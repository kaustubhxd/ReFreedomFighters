"""specs_s5711.py - unclaimed-57, batch 11: two stdcall helpers that call the assert hook (global 0x7003b0) when it is non-null, then
return al = 0. 0x4ced80 has one stack argument, 0x4d4f00 two. The assert hook is always a logging stub (the null branch is not exercised: a zero hook made the original
run fault). The arguments are random."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _hook(c):
    # Always a logging stub: with a zero hook the original run faulted (see batch 12 in the area 10 doc), so the null branch
    # is not exercised here.
    c.emu.w32(0x7003b0, c.emu.stub_fn('assert', lambda em, r: (em.calllog.append(('assert', 0, None, ())), em.ret(eax=0))))


def _one(c):
    _hook(c)
    return [c.rng.getrandbits(32)]


def _two(c):
    _hook(c)
    return [_rnd(c, 16), _rnd(c, 16)]


S(0x4ced80, 'STATICREFTAB::RemoveIfExists (GUESS) stdcall', 'stdcall', None, ret='al', gen=_one,
  note='unclaimed-57 batch 11; calls the assert hook when non-null; returns 0')
S(0x4d4f00, 'ZBigFile::Add (GUESS) stdcall', 'stdcall', None, ret='al', gen=_two,
  note='unclaimed-57 batch 11; calls the assert hook when non-null; returns 0')
