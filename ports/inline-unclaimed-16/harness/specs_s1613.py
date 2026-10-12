"""specs_s1613.py - unclaimed-16 batch 13 (docs/20-unclaimed-16.md): ZFFActor::GetCloseCombatStrength. Returns AX only,
so this spec uses ret='ax', which needs the opt-in patch (inline-unclaimed-16/pilot-ax-return.patch). With the
unpatched shared pilot.py an 'ax' return is not compared, so this row is run with a patched COPY of the harness
(see docs/20-unclaimed-16.md)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


S(0x59fcf0, 'ZFFActor::GetCloseCombatStrength (unknown) thiscall', 'thiscall', None, ret='ax',
  gen=lambda c: [_rnd(c, 0x1000)], note='unclaimed-16 b13; word at +0x7a4 in AX (patched harness only)')
