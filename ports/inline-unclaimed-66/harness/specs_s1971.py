"""specs_s1971.py - slice-5 batches 98 to 100 (GUESS names). Callees are GUESS stubs by address or vtable slots (argument values logged).
0x628810 (cdecl, eleven arguments; caller cleans) is a stub by address. 0x495ed0 uses the child's +0x158 (one argument, ret 4) and this's +4
(four arguments, ret 0x10). 0x658f10 uses the sys object's +0x1aa3 object's +0x80 (one argument, ret 4), and the table at o+0x3c."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen_626dd0(c):
    def h(e, r):
        e.calllog.append(('0x628810 (GUESS stub)', 0x628810, None, tuple(e.arg32(i) for i in range(11))))
        e.ret(eax=0, argbytes=0)
    c.emu.hook(0x628810, h)
    return [c.rng.getrandbits(32) for _ in range(11)]


def _gen_495ed0(c):
    rr = c.rng.getrandbits(32)

    def h158(e, r):
        e.calllog.append(('child vtable +0x158 (stub)', 0x158, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=rr, argbytes=4)
    vt_c = c.emu.fake_vtable('batch99 child', 0x158 // 4 + 1, slots={0x158: h158})
    child = c.emu.fake_object('batch99 child', 0x40, vtable=vt_c)
    sys_ = _rnd(c, 0x1b00)
    c.emu.w32(sys_ + 0x9b, child)
    c.emu.w32(0x70039c, sys_)

    def h4(e, r):
        e.calllog.append(('this vtable +4 (stub)', 4, e.reg('ecx'), (e.arg32(0), e.arg32(1), e.arg32(2), e.arg32(3))))
        e.ret(eax=0, argbytes=16)
    vt = c.emu.fake_vtable('batch99 self', 4 // 4 + 1, slots={4: h4})
    self = _rnd(c, 0x100)
    c.emu.w32(self, vt)
    return [self, c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _gen_658f10(c):
    def h80(e, r):
        e.calllog.append(('sys obj vtable +0x80 (stub)', 0x80, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=0, argbytes=4)
    vt = c.emu.fake_vtable('batch100 obj', 0x80 // 4 + 1, slots={0x80: h80})
    obj = c.emu.fake_object('batch100 obj', 0x40, vtable=vt)
    sys_ = _rnd(c, 0x1b00)
    c.emu.w32(sys_ + 0x1aa3, obj)
    c.emu.w32(0x70039c, sys_)
    tbl = _rnd(c, 0x100)
    o = _rnd(c, 0x80)
    c.emu.w32(o + 0x3c, tbl)
    self = _rnd(c, 0x40)
    k = c.rng.random()
    c.emu.w32(self + 0x10, 0 if k < 0.2 else _wrap_o(c, o))
    x = 0 if c.rng.random() < 0.2 else c.rng.randrange(0, 0x20)
    return [self, x]


def _wrap_o(c, o):
    w = _rnd(c, 0x40)
    c.emu.w32(w + 0xc, o)
    return w


S(0x626dd0, 'GUESS FUN_00626dd0 (eleven-argument wrapper around 0x628810 with 0x628b40)', 'cdecl', None, ret=None, gen=_gen_626dd0,
  note='slice-5 batch 1971 (98); 0x628810 GUESS stub')
S(0x495ed0, 'GUESS FUN_00495ed0 (child vtable +0x158 on b; this vtable +4 with (a, r, c, 0))', 'thiscall', None, ret=None, gen=_gen_495ed0,
  note='slice-5 batch 1971 (99)')
S(0x658f10, 'GUESS FUN_00658f10 (table entry x to sys obj vtable +0x80)', 'thiscall', None, ret=None, gen=_gen_658f10,
  note='slice-5 batch 1971 (100)')
