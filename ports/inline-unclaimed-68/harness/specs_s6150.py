"""specs_s6150.py - unclaimed-68 batch 16 (claim 15): ZSoundAnimation scalar deleting destructor (0x4be2c0), same shape as 0x4be200. Engine object at
0x70039c with +0x9b to a logging object whose slot +0x34 logs; the hook at 0x7003b0 is a logging stub (non-null, as the original
requires); the no-op delete 0x4690b0 is left as is. The flag is random (bit 0 set in most cases)."""
from pilot import S
from engine_stubs import zero_obj, logged_obj, set_global


def _setup(c):
    en = logged_obj(c, 'ZCheckEngine', 0x80, impl={}, argwords={0x34: 1})
    eng = zero_obj(c, 0x400)
    c.emu.w32(eng + 0x9b, en)
    set_global(c, 0x70039c, eng)
    hook = c.emu.stub_fn('CheckInside hook', lambda em, r: (em.calllog.append(('hook', 0, 0, ())), em.ret(eax=0, argbytes=0)))
    set_global(c, 0x7003b0, hook)


def _gen(c):
    o = zero_obj(c, 0x100)
    flags = c.rng.getrandbits(32)
    if c.rng.random() < 0.7:
        flags |= 1
    return [o, flags]


S(0x4be2c0, 'ZSoundAnimation::~ZSoundAnimation (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  setup=_setup, note='unclaimed-68 batch 16; engine slot +0x34; hook 0x7003b0 stubbed; 0x4690b0 no-op')
