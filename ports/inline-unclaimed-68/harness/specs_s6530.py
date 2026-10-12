"""specs_s6530.py - unclaimed-68 batch 53 (claim 53): CAction::Init2 (0x4a1130, GUESS name), thiscall, no arguments, plain ret.
It tail-jumps to 0x4a1270 (a checksum stub with no stack arguments, GUESS), which is hooked here: it logs its ecx and returns eax 0."""
from pilot import S
from engine_stubs import zero_obj


def _setup(c):
    c.emu.hook(0x4a1270, lambda em, r: (em.calllog.append(('4a1270', em.reg('ecx'))), em.ret(eax=0, argbytes=0)))


def _init2(c):
    o = zero_obj(c, 0x200)
    c.emu.wbytes(o + 0x63, bytes([c.rng.randrange(2)]))
    return [o]


S(0x4a1130, 'CAction::Init2 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_init2, setup=_setup,
  note='unclaimed-68 batch 53; tail jump to 0x4a1270 (hooked, logged) when this+0x63 is zero')
