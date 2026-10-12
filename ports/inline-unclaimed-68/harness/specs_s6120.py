"""specs_s6120.py - unclaimed-68 batch 13 (claim 12): ZOffsetAlloc::Reset (0x4cee30). The entries array is a zeroed block; the
hook at 0x7003b0 is a stub that logs its call (non-null, as the original requires). a and b are random in 0..1000, so both
branches of the comparison run."""
from pilot import S
from engine_stubs import zero_obj, set_global


def _reset(c):
    o = zero_obj(c, 0x40)
    arr = zero_obj(c, 0x800)
    c.emu.w32(o + 4, arr)
    c.emu.w32(o + 8, c.rng.randrange(0, 50))
    hook = c.emu.stub_fn('ZOffsetAlloc hook', lambda em, r: (em.calllog.append(('hook', 0, em.reg('ecx'), ())), em.ret(eax=0, argbytes=0)))
    set_global(c, 0x7003b0, hook)
    return [o, c.rng.randrange(0, 1000), c.rng.randrange(0, 1000)]


S(0x4cee30, 'ZOffsetAlloc::Reset (unknown) thiscall', 'thiscall', None, ret=None, gen=_reset,
  note='unclaimed-68 batch 13; hook 0x7003b0 stubbed (logs); entries (a, b-a)')
