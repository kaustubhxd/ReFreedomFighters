"""specs_s90000.py - 0x44b740 ZSoundObject::~ZSoundObject: SEH frame (fs:[0] chain pushed/restored), global 0x70039c -> +0x1a9f (unaligned) sound object, vtable slot 0x118 called with the stack arg."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x7003b0, 0, ret=r.getrandbits(32))
    so = sysobj(c)
    k = r.random()
    if k < 0.25:
        snd = 0
    else:
        stub = pystub(c, 1, ret=r.getrandbits(32), this=True)
        snd = obj(c, 0x40, {0x118: stub}, nslots=0x60)
    c.emu.wbytes(so + 0x1a9f, snd.to_bytes(4, 'little'))
    return [r.getrandbits(32)]


S(0x44b740, 'ZSoundObject::~ZSoundObject', 'cdecl', None, ret='eax', gen=_g)
