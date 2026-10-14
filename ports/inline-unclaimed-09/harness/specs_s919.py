"""specs_s919.py - unclaimed-09 batch 11 (docs/20-unclaimed-09.md, claim 11): ZAnimSequence::Save(ZSaveGame*).

The object is 0x100 random bytes. The save object comes from serial_stubs.save_obj with logged rec stubs on the three
save slots (0x54, 0x60, 0x6c). rec logs its first argument, a value, so the logs are the saved values. The return is
the bool in al."""
from pilot import S
from serial_stubs import save_obj, rec


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    sg = save_obj(c, {0x54: rec(c, 1), 0x60: rec(c, 1), 0x6c: rec(c, 1)})
    return [_rnd(c, 0x100), sg]


S(0x4c4f80, 'ZAnimSequence::Save (unknown) thiscall', 'thiscall', None, ret='al', gen=_gen,
  note='unclaimed-09 b11; save slots 0x54/0x60/0x6c logged (unverified callees)')
