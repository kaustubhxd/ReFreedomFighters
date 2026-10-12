"""specs_s6358.py - unclaimed-63 batch 58: 0x478aa0 (ZActor::GetAnimHeader; stdcall, one stack argument x, ret 4).
Fakes per case: the engine 0x70039c (heap) has the db at +0x9b; db+0x44 is a random base. x is zero in a quarter of the cases,
else a random dword (the sum wraps, which is fine for both sides)."""
from pilot import S


def _gen_8aa0(c):
    e = c.emu
    eng = e.alloc(0x200, 4)
    e.wbytes(eng, bytes(0x200))
    db = e.alloc(0x100, 4)
    e.wbytes(db, bytes(0x100))
    e.w32(db + 0x44, c.rng.getrandbits(32))
    e.w32(eng + 0x9b, db)
    e.w32(0x70039c, eng)
    e.mu.ctl_flush_tb()
    x = 0 if c.rng.random() < 0.25 else c.rng.getrandbits(32)
    return [x]


S(0x478aa0, 'ZActor::GetAnimHeader stdcall', 'stdcall', None, ret='eax', gen=_gen_8aa0,
  note='unclaimed-63 batch 58')
