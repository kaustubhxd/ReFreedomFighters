"""specs_s339.py - gap band, batch 339: two thiscall members with two stack arguments. The helpers 0x603c80 and 0x604030 are hooked (recorded).
The object's vtable: slots 0x50 (returns a per-run value and logs), 0x54 (a value). The argument's vtable: slots 0x50 and 0x44 (log their
arguments, return per-run values)."""
from pilot import S


def _gen(helper_addr):
    def gen(c):
        e = c.emu
        rng = c.rng
        r50 = rng.getrandbits(32)
        r54 = rng.getrandbits(32)
        r44 = rng.getrandbits(32)

        def rec(em, r):
            em.calllog.append(('helper', helper_addr, em.reg('ecx'), (em.arg32(0), em.arg32(1))))
            em.ret(eax=0, argbytes=8)

        e.hook(helper_addr, rec)

        def this50(em, r):
            em.calllog.append(('this50', 0x50, em.reg('ecx'), (em.arg32(0),)))
            em.ret(eax=r50, argbytes=4)

        def this54(em, r):
            em.calllog.append(('this54', 0x54, em.reg('ecx'), ()))
            em.ret(eax=r54, argbytes=0)

        def a50(em, r):
            a = em.arg32(0)
            em.calllog.append(('a50', 0x50, em.reg('ecx'), (('p', struct_u32(em, a)),)))
            em.ret(eax=0x1234, argbytes=4)

        def a44(em, r):
            em.calllog.append(('a44', 0x44, em.reg('ecx'), (em.arg32(0),)))
            em.ret(eax=r44, argbytes=4)

        this = e.alloc(0x40, 4)
        e.w32(this, e.fake_vtable('this339', 0x100, {0x50: this50, 0x54: this54}))
        arg = e.alloc(0x40, 4)
        e.w32(arg, e.fake_vtable('arg339', 0x100, {0x50: a50, 0x44: a44}))
        return [this, arg, rng.getrandbits(32)]
    return gen


def struct_u32(em, a):
    import struct
    return struct.unpack('<I', bytes(em.mu.mem_read(a, 4)))[0]


S(0x604340, 'link604340 (GUESS)', 'thiscall', None, ret='eax', gen=_gen(0x603c80), note='batch339; ret 8; helper 0x603c80 hooked')
S(0x604510, 'link604510 (GUESS)', 'thiscall', None, ret='eax', gen=_gen(0x604030), note='batch339; ret 8; helper 0x604030 hooked')
