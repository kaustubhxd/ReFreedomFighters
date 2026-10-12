"""specs_s6590.py - unclaimed-68 batch 59 (claim 60): CExplodeMolotov::ReadInput(DBREAD&) (0x584bc0), thiscall, one stack arg, ret 4.
The DBREAD operators read the shared cursor (harness/dbread_cursor.py). The stream's first dword points at a peek cell (the byte the
body inspects, not consumed). The render manager (engine+0x9b) slot +0x114 takes four stack arguments and returns a word (logged)."""
from pilot import S
from engine_stubs import zero_obj, logged_obj, set_global
import dbread_cursor


def _setup(c):
    vals = [c.rng.getrandbits(32) for _ in range(12)]
    dbread_cursor.install(c, vals)


def _gen(c):
    peek = c.emu.alloc(4, 4)
    r = c.rng.random()
    byte = 0xff if r < 0.25 else (0x43 if r < 0.5 else c.rng.getrandbits(8))   # 0xff; (x & 0x3f) == 3; otherwise any
    c.emu.wbytes(peek, bytes([byte, 0, 0, 0]))
    stream = zero_obj(c, 0x40)
    c.emu.w32(stream, peek)
    o = zero_obj(c, 0x100)
    mgr = logged_obj(c, 'ZMolotovMgr', 0x200, impl={0x114: (lambda v: (lambda e, a: (v, None)))(c.rng.getrandbits(32))},
                     argwords={0x114: 4})
    eng = zero_obj(c, 0x400)
    c.emu.w32(eng + 0x9b, mgr)
    set_global(c, 0x70039c, eng)
    return [o, stream]


S(0x584bc0, 'CExplodeMolotov::ReadInput (high) thiscall', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='unclaimed-68 batch 59; shared DBREAD cursor; peek at [[stream]]; render manager slot +0x114 with four arguments')
