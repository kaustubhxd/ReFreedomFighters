"""specs_s8827.py - hitreact batch 8827: ZFFActorActionCloseCombat::CallBack 0x5eaf80. The attacker (+8) has recording stubs at slots
0x704 (1 argument) and 0x128 (3 arguments); the render manager [[0x70039c] + 0x9b] slot 0x114 (4 arguments) returns a dword whose low word is the
message id (upper bits garbage: the caller zero-extends)."""
from pilot import S
from wkit import rnd, stub, obj


def _gen(c):
    r = c.rng
    at = obj(c, 0x40, {0x704: stub(c, 1), 0x128: stub(c, 3)})
    rm = obj(c, 0x40, {0x114: stub(c, 4, ret=r.getrandbits(32))})
    eng = rnd(c, 0xa0)
    c.emu.w32(eng + 0x9b, rm)
    c.emu.w32(0x70039c, eng)
    self = rnd(c, 0x40)
    c.emu.w32(self + 8, at)
    c.emu.mu.ctl_flush_tb()
    return [self]


S(0x5eaf80, 'ZFFActorActionCloseCombat::CallBack', 'thiscall', ret='al', gen=_gen)
