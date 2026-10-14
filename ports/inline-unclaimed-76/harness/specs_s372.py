"""specs_s372.py - area 76, residue 18, batch 372. 0x64c7e0 (thiscall, one word, ret 4): this+0x10071 -> a table of 4096 dwords (random).
0x658c20 (stdcall, one float, ret 4): the global 0x70039c -> an engine object whose +0x1aa3 -> a record (the float is written at +0x91)."""
from pilot import S, F


def _gen_64(c):
    e = c.emu
    rng = c.rng
    table = e.alloc(0x4000, 4)
    e.wbytes(table, rng.randbytes(0x4000))
    this = e.alloc(0x10100, 4)
    e.wbytes(this, rng.randbytes(0x10100))
    e.w32(this + 0x10071, table)
    return [this, rng.getrandbits(32)]


def _gen_658(c):
    e = c.emu
    rng = c.rng
    rec = e.alloc(0x100, 4)
    e.wbytes(rec, rng.randbytes(0x100))
    eng = e.alloc(0x1b00, 4)
    e.wbytes(eng, rng.randbytes(0x1b00))
    e.w32(eng + 0x1aa3, rec)
    e.w32(0x70039c, eng)
    return [F(rng.uniform(-100.0, 100.0))]


S(0x64c7e0, 'get64c7e0 (GUESS)', 'thiscall', None, ret='eax', gen=_gen_64,
  note='area 76 batch 372; residue 18')
S(0x658c20, 'set658c20 (GUESS)', 'stdcall', None, ret=None, gen=_gen_658,
  note='area 76 batch 372; residue 18; stdcall with one float argument')
