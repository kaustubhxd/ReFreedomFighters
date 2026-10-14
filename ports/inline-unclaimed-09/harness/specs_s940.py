"""specs_s940.py - unclaimed-09 batch 32 (docs/20-unclaimed-09.md, claim 34): ZFFHeroMovementCloseCombat::GetAnims().

The object is an 0x800 fake object (the fields reach +0x594; the vtable slot 0x58 is the GUESS recording stub): it logs its
constant argument and returns a random dword, zero in about a third of cases (so the fill-if-zero copies run). The object's
other bytes are random, so the copies see both zero and non-zero destinations."""
from pilot import S


def _gen(c):
    rng = c.rng

    def h58(e2, r):
        k = e2.arg32(0)
        v = 0 if rng.random() < 0.33 else rng.getrandbits(32)
        e2.calllog.append(('V58', k, v))
        e2.ret(eax=v, argbytes=4)

    obj = c.emu.fake_object('closecombat_getanims', 0x800, slots={0x58: h58})
    c.emu.wbytes(obj + 4, bytes(rng.getrandbits(8) for _ in range(0x800 - 4)))
    return [obj]


S(0x5e4400, 'ZFFHeroMovementCloseCombat::GetAnims (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-09 b32; this vt+0x58 stubbed (GUESS recording stub)')
