"""specs_s1961.py - unclaimed-66 batch 75 (gap band, GUESS name). THISCALL(this), one stack argument x, ret 4.

The logger at [0x700390] is a logging object whose +0x20 slot (two arguments, ret 8) returns obj. obj's vtable +0x2c is a caller-cleaned
stub (ECX = its vtable; three stack arguments; plain ret, logs ECX and the arguments). [0x7003b0] is a stub function (the exe's pointer is always set; a zero pointer would run into int3 padding)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    def h2c(e, r):
        e.calllog.append(('obj vtable +0x2c (caller-cleaned stub)', 0x2c, e.reg('ecx'), (e.arg32(0), e.arg32(1), e.arg32(2))))
        e.ret(eax=0, argbytes=0)
    vt_o = c.emu.fake_vtable('batch75 obj', 0x2c // 4 + 1, slots={0x2c: h2c})
    obj = c.emu.fake_object('batch75 obj', 0x40, vtable=vt_o)

    def h20(e, r):
        e.calllog.append(('logger vtable +0x20 (stub)', 0x20, e.reg('ecx'), (e.arg32(0), e.arg32(1))))
        e.ret(eax=obj, argbytes=8)
    vt_l = c.emu.fake_vtable('batch75 logger', 0x20 // 4 + 1, slots={0x20: h20})
    logger = c.emu.fake_object('batch75 logger', 0x40, vtable=vt_l)
    c.emu.w32(0x700390, logger)
    def hfp(e, r):
        e.calllog.append(('0x7003b0 pointer target (stub)', 0, e.reg('ecx'), ()))
        e.ret(eax=0, argbytes=0)
    c.emu.w32(0x7003b0, c.emu.stub_fn('batch75 fp', hfp))

    self = _rnd(c, 0x40)
    c.emu.w8(self + 4, c.rng.choice([0, 1, 2, 5, 255]))
    x = _rnd(c, 0x40)
    return [self, x]


S(0x50d7b0, 'GUESS FUN_0050d7b0 (store-once; logger error path with caller-cleaned slot +0x2c)', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-66 batch 1961; gap band; logger stubs; caller-cleaned call via vcall_cc.h')
