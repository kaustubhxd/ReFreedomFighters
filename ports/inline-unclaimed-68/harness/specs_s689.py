"""specs_s689.py - unclaimed-68 batch 9 (claim 8): REFTAB32::DeleteBlock (0x4cdf30). The sized delete (0x634273) is hooked and
logged, not run. The block is the inline one (this+0x1c) in about half the cases, otherwise a separate block."""
from pilot import S
from engine_stubs import zero_obj


def _hook(c):
    c.emu.hook(0x634273, lambda em, r: (em.calllog.append(('delete_sized', 0, 0, (em.arg32(0), em.arg32(1)))), em.ret(eax=0, argbytes=0)))


def _gen(c):
    o = zero_obj(c, 0x80)
    if c.rng.random() < 0.5:
        blk = o + 0x1c
    else:
        blk = zero_obj(c, 0x40)
    return [o, blk]


S(0x4cdf30, 'REFTAB32::DeleteBlock (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen, setup=_hook,
  note='unclaimed-68 batch 9; sized delete 0x634273 hooked; inline block at +0x1c is not freed')
