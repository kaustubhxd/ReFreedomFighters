"""specs_s1972.py - slice-5 batches 101 to 103 (GUESS names).
0x5f20d0: the logger [0x700390] (vtable +0x20: two arguments, ret 8) returns obj; obj's +0x2c is caller-cleaned (plain ret). [0x7003b0] is a stub.
0x5f1810: [this+0xc] is a child with +4 = t (the tail target's ECX) and +0x94 = q or 0. The sys object's +0x1a8 slot (one argument) and q's slot 0
(one argument, ret 4) log. 0x5fb5a0 (THISCALL, no arguments) is a GUESS stub returning a fixed eax.
0x557ad0: the global count at 0x713e2c is random (0..0x40); [0x7003b0] is a stub; this's vtable +0x44 (one argument, ret 4) logs."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _fp(c, name):
    def h(e, r):
        e.calllog.append((name + ' (stub)', 0, e.reg('ecx'), ()))
        e.ret(eax=0, argbytes=0)
    return c.emu.stub_fn(name, h)


def _gen_5f20d0(c):
    def h2c(e, r):
        e.calllog.append(('obj vtable +0x2c (caller-cleaned stub)', 0x2c, e.reg('ecx'), (e.arg32(0), e.arg32(1), e.arg32(2))))
        e.ret(eax=0, argbytes=0)
    vt_o = c.emu.fake_vtable('batch101 obj', 0x2c // 4 + 1, slots={0x2c: h2c})
    obj = c.emu.fake_object('batch101 obj', 0x40, vtable=vt_o)

    def h20(e, r):
        e.calllog.append(('logger vtable +0x20 (stub)', 0x20, e.reg('ecx'), (e.arg32(0), e.arg32(1))))
        e.ret(eax=obj, argbytes=8)
    vt_l = c.emu.fake_vtable('batch101 logger', 0x20 // 4 + 1, slots={0x20: h20})
    logger = c.emu.fake_object('batch101 logger', 0x40, vtable=vt_l)
    c.emu.w32(0x700390, logger)
    c.emu.w32(0x7003b0, _fp(c, 'batch101 fp'))
    return []


def _gen_5f1810(c):
    def h5fb(e, r):
        e.calllog.append(('0x5fb5a0 (GUESS stub)', 0x5fb5a0, e.reg('ecx'), ()))
        e.ret(eax=rv, argbytes=0)
    rv = c.rng.getrandbits(32)
    c.emu.hook(0x5fb5a0, h5fb)

    def h1a8(e, r):
        e.calllog.append(('sys vtable +0x1a8 (stub)', 0x1a8, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=0, argbytes=4)
    vt_s = c.emu.fake_vtable('batch102 sys', 0x1a8 // 4 + 1, slots={0x1a8: h1a8})
    sys_ = _rnd(c, 0x1a00)
    c.emu.w32(sys_, vt_s)
    c.emu.w32(0x70039c, sys_)

    def h0(e, r):
        e.calllog.append(('q vtable +0 (stub)', 0, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=0, argbytes=4)
    vt_q = c.emu.fake_vtable('batch102 q', 1, slots={0: h0})
    q = c.emu.fake_object('batch102 q', 0x40, vtable=vt_q)
    t = _rnd(c, 0x40)
    cc = _rnd(c, 0x100)
    c.emu.w32(cc + 4, t)
    c.emu.w32(cc + 0x94, 0 if c.rng.random() < 0.3 else q)
    self = _rnd(c, 0x40)
    c.emu.w32(self + 0xc, cc)
    return [self]


def _gen_557ad0(c):
    n = c.rng.randrange(0, 0x40)
    c.emu.w32(0x713e2c, n)
    def h44(e, r):
        e.calllog.append(('this vtable +0x44 (stub)', 0x44, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=0, argbytes=4)
    vt = c.emu.fake_vtable('batch103 self', 0x44 // 4 + 1, slots={0x44: h44})
    self = _rnd(c, 0x40)
    c.emu.w32(self, vt)
    c.emu.w32(0x7003b0, _fp(c, 'batch103 fp'))
    return [self, c.rng.getrandbits(32)]


S(0x5f20d0, 'GUESS FUN_005f20d0 (logger +0x20, caller-cleaned +0x2c, function pointer; returns -1)', 'cdecl', None, ret='eax',
  gen=_gen_5f20d0, note='slice-5 batch 1972 (101)')
S(0x5f1810, 'GUESS FUN_005f1810 (sys +0x1a8, q slot 0, then tail to 0x5fb5a0)', 'thiscall', None, ret='eax', gen=_gen_5f1810,
  note='slice-5 batch 1972 (102); 0x5fb5a0 GUESS stub')
S(0x557ad0, 'GUESS FUN_00557ad0 (bounded append to 0x713e30; overflow path calls vtable +0x44)', 'thiscall', None, ret=None,
  gen=_gen_557ad0, note='slice-5 batch 1972 (103)')
