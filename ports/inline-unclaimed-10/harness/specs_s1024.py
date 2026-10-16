"""specs_s1024.py - unclaimed-10, batch 20: 0x437050 (GUESS: unnamed). Thiscall, one argument, ret 4. The object's vtable slot
+0x58 (one argument) is stubbed: it returns a fixed object pointer chosen in gen, or 0 in about one case in four. The returned
object is a random block whose first dword is zero in half the cases (so both branches run)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _unk(c):
    e = c.emu
    if c.rng.random() < 0.25:
        ret_obj = 0
    else:
        ret_obj = _rnd(c, 0x40)
        e.w32(ret_obj, 0 if c.rng.random() < 0.5 else c.rng.getrandbits(32))
    vt = e.logging_vtable('unk437050', 32, impl={0x58: lambda em, a: (ret_obj, None)}, argwords={0x58: 1})
    obj = _rnd(c, 0x800)
    e.w32(obj, vt)
    return [obj, c.rng.getrandbits(32)]


S(0x437050, 'unnamed_437050 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_unk,
  note='unclaimed-10 batch 20; this slot +0x58 stubbed; returns r (or 0)')
