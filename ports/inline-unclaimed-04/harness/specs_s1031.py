"""specs_s1031.py - unclaimed-04 batch 31 (docs/20-unclaimed-04.md): two slice-3 functions (GUESS labels).
0x651970 (thiscall, one flag, ret 4, returns this): base 0x64f530 (hooked by address), then free 0x634273 with size 0xa5 when
flag bit 0 is set. 0x42cc30 (thiscall, no arguments): when this+0x1907 is non-null, calls 0x436f60 (hooked by address) with
ecx = the pointer, frees the pointer with size 0x134c, and clears +0x1907. The objects are zeroed 0x2000-byte blocks."""
from pilot import S


def _setup_common(c):
    def base64(em, r):
        em.calllog.append(('64f530', 0, em.reg('ecx'), ()))
        em.ret(eax=0, argbytes=0)

    def free34(em, r):
        em.calllog.append(('634273', 0, 0, (em.arg32(0), em.arg32(1))))
        em.ret(eax=0, argbytes=0)

    def h436f60(em, r):
        em.calllog.append(('436f60', 0, em.reg('ecx'), ()))
        em.ret(eax=0, argbytes=0)

    c.emu.hook(0x64f530, base64)
    c.emu.hook(0x634273, free34)
    c.emu.hook(0x436f60, h436f60)


def _obj_flag(c):
    o = c.emu.alloc(0x2000, 4)
    c.emu.wbytes(o, bytes(0x2000))
    return [o, c.rng.choice([0, 1, 2, 3, c.rng.getrandbits(32)])]


def _obj(c):
    o = c.emu.alloc(0x2000, 4)
    c.emu.wbytes(o, bytes(0x2000))
    if c.rng.random() < 0.6:
        c.emu.w32(o + 0x1907, c.emu.alloc(0x40, 4))
    return [o]


S(0x651970, 'unknown::dtor_base_64f530_free_a5 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj_flag,
  setup=_setup_common, note='unclaimed-04 batch 31; base 0x64f530 hooked (GUESS); free 0xa5 hooked')
S(0x42cc30, 'unknown::release_1907_free_134c (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj,
  setup=_setup_common, note='unclaimed-04 batch 31; 0x436f60 hooked (GUESS); free 0x134c hooked')
