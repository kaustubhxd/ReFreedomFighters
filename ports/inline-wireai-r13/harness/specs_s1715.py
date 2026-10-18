"""specs_s1715.py - residue 13 batch 1715: 0x486190 ZActionPushButton::CallBack.
Thiscall, no arguments, plain ret, returns al = 0. Calls vtable slot +0x2d0 of object at this+8,
then helper 0x467410 with specific arguments."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, hook, HOOKED


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)

    # Hook helper 0x467410 (takes six stack args, pops 0x18)
    # The checksum stub only records the call, doesn't model effects
    HOOKED.add(0x467410)
    c.emu.hook(0x467410, lambda e, ret: e.ret(argbytes=0x18))

    # Create vtable slot +0x2d0 as a stub (thiscall, 2 args, ret ignored)
    fn_2d0 = stub(c, seq, 2, ret=r.getrandbits(32))

    # Create the vtable object
    vt = c.emu.alloc(0x400, 4)
    c.emu.w32(vt + 0x2d0, fn_2d0)

    # Create the object at this+8
    obj_8 = rnd(c, 0x100)
    c.emu.w32(obj_8, vt)

    # Create self (the CallBack object)
    self_ = rnd(c, 0x100)
    c.emu.w32(self_ + 8, obj_8)
    c.emu.w32(self_ + 0xc, r.getrandbits(32))

    # Create object at this+0x10
    obj_10 = rnd(c, 0x40)
    c.emu.w32(self_ + 0x10, obj_10)

    return [self_]


S(0x486190, 'ZActionPushButton::CallBack', 'thiscall', None, ret='al', gen=_gen, note='batch1715; vtable slot 0x2d0 and helper 0x467410 hooked')
