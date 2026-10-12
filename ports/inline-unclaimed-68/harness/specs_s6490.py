"""specs_s6490.py - unclaimed-68 batch 49 (claim 49): ZSIGTE::GetpCUI (0x4a8d20). The engine object has slot +0x138 (answers a result object R),
slot +0x58 (returns a value of its argument). R's slot +0x88 writes a random dword (zero in about one case in four) through its out pointer.
The cache at this+0xc9 is zero in about half the cases."""
from pilot import S
from engine_stubs import zero_obj, logged_obj, set_global


def _cui(c):
    o = zero_obj(c, 0x100)
    if c.rng.random() < 0.5:
        c.emu.w32(o + 0xc9, c.rng.getrandbits(32))
    val = 0 if c.rng.random() < 0.25 else c.rng.getrandbits(32)
    # the slot +0x88 writes through its out pointer: a handler that writes the value
    def fill(e, a, v=val):
        e.w32(a[1], v)
        return (None, None)
    R2 = logged_obj(c, 'ZSIGTEResult', 0x80, impl={0x88: fill}, argwords={0x88: 2})
    r58 = c.rng.getrandbits(32)  # drawn at gen time so the handler is deterministic across the two runs
    en = logged_obj(c, 'ZSIGTEEngine2', 0x200, impl={0x138: (lambda rr: (lambda e, a: (rr, None)))(R2),
                                                       0x58: (lambda v: (lambda e, a: (v, None)))(r58)},
                    argwords={0x138: 0, 0x58: 1})
    eng = zero_obj(c, 0x400)
    c.emu.w32(eng + 0x9b, en)
    set_global(c, 0x70039c, eng)
    return [o]


S(0x4a8d20, 'ZSIGTE::GetpCUI (unknown) thiscall', 'thiscall', None, ret='eax', gen=_cui,
  note='unclaimed-68 batch 49; engine +0x138 -> result +0x88 fills the cache; engine +0x58 on the cache')
