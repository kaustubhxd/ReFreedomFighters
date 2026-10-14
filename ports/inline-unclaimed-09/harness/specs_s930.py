"""specs_s930.py - unclaimed-09 batch 22 (docs/20-unclaimed-09.md, claim 24): CActionController::Save(ZSaveGame*).

The object is 0x900 random bytes (the words at +0x8b0 and +0x8b2 must lie inside it; a 0x100 object missed a mutant). The count at +0x48 is 0 to 3 (the entries at +0x5c, +0x60, +0x64 are pointers to heap
cells holding random dwords, so the loop reads valid memory and never reaches +0x6c). The save object is save_obj with
logged rec stubs on 0x3c, 0x40 and 0x44 (rec logs its first argument, a value)."""
from pilot import S
from serial_stubs import save_obj, rec


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    obj = _rnd(c, 0x900)
    c.emu.w32(obj + 0x48, c.rng.randint(0, 3))
    for i in range(3):
        cell = _rnd(c, 4)
        c.emu.w32(obj + 0x5c + 4 * i, cell)
    sg = save_obj(c, {0x3c: rec(c, 1), 0x40: rec(c, 1), 0x44: rec(c, 1)})
    return [obj, sg]


S(0x4a1bf0, 'CActionController::Save (unknown) thiscall', 'thiscall', None, ret='al', gen=_gen,
  note='unclaimed-09 b22; save slots 0x3c/0x40/0x44 rec (unverified callees)')
