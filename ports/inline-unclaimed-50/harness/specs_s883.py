"""specs_s883.py - area 50, batch 883: 0x482a50 (GUESS name Make482a50), thiscall, no stack args, void. SEH frame not reproduced.
Stand-ins (hooked, logged): the allocator 0x41e290 (cdecl, one arg, returns a block chosen at generation time, or 0) and the
constructor-like routine 0x487820 (thiscall, two args, ret 8; logs the object identity by comparing with the block and its args)."""
from pilot import S
from anim_common import only_hooks, rnd


def _gen(c):
    e, r = c.emu, c.rng
    blk = rnd(c, 0x130)
    use_null = r.random() < 0.2

    def alloc(e, rr):
        e.calllog.append(('new.41e290', e.arg32(0)))
        e.ret(eax=0 if use_null else blk, argbytes=0)    # cdecl: the caller pops the argument

    def ctor(e, rr):
        e.calllog.append(('ctor.487820', e.reg('ecx') == blk, e.arg32(0), e.arg32(1)))
        e.ret(eax=0, argbytes=8)

    only_hooks(c, {0x41e290: alloc, 0x487820: ctor})
    self = rnd(c, 0x40)
    return [self]


S(0x482a50, 'Make482a50 (GUESS name; SEH frame not reproduced)', 'thiscall', None, gen=_gen, note='area50 batch883')
