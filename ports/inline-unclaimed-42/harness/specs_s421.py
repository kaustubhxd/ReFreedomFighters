"""specs_s421.py - unclaimed-42 batch 1 (claim 1): ZFFPRIVATESTDOBJ scalar deleting destructor (0x5a5650). The base
destructor (0x43de70) runs original code on a zeroed object; the two delete paths (0x45c510, 0x4690b0) are hooked and logged,
not run (the fake heap has no free)."""
from pilot import S
from engine_stubs import zero_obj, logged_obj, set_global


def _hook_deletes(c):
    c.emu.hook(0x45c510, lambda em, r: (em.calllog.append(('delete_wrap', 0, 0, (em.arg32(0),))), em.ret(eax=0, argbytes=0)))
    c.emu.hook(0x4690b0, lambda em, r: (em.calllog.append(('delete_sized', 0, 0, (em.arg32(0), em.arg32(1)))), em.ret(eax=0, argbytes=0)))


def _gen(c):
    o = zero_obj(c, 0x800)
    en = logged_obj(c, 'ZEngineObj', 0x140, impl={}, argwords={0x130: 1})
    eng = zero_obj(c, 0x400)
    c.emu.w32(eng + 0x9b, en)
    set_global(c, 0x70039c, eng)
    c.emu.w32(o + 8, zero_obj(c, 0x100))   # the base destructor reads the owner at +8
    flags = c.rng.getrandbits(32)
    if c.rng.random() < 0.7:
        flags |= 1
    return [o, flags]


S(0x5a5650, 'ZFFPRIVATESTDOBJ::~ZFFPRIVATESTDOBJ (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  setup=_hook_deletes, note='unclaimed-42 batch 1; base dtor 0x43de70 original; deletes hooked (0x45c510, 0x4690b0)')
