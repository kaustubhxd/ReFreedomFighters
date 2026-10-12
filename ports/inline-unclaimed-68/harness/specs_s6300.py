"""specs_s6300.py - unclaimed-68 batch 29 (claim 29): ZDefaultAcusticEnv::Init2 (0x4bbc20). The sub-object at +0x44 is a logging object
whose slot +0x210 logs its argument (one stack word, callee cleanup); in about one case in four the sub-object is null."""
from pilot import S
from engine_stubs import zero_obj, logged_obj


def _init2(c):
    o = zero_obj(c, 0x100)
    if c.rng.random() < 0.75:
        s = logged_obj(c, 'ZAcousticSub', 0x240, impl={}, argwords={0x210: 1})
        c.emu.w32(o + 0x44, s)
    return [o]


S(0x4bbc20, 'ZDefaultAcusticEnv::Init2 (unknown) thiscall', 'thiscall', None, ret=None, gen=_init2,
  note='unclaimed-68 batch 29; slot +0x210 with argument 1 when the sub-object is not null')
