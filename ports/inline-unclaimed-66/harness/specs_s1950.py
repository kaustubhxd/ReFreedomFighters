"""specs_s1950.py - unclaimed-66 batches 53 to 55 (gap band, GUESS names).

0x5003d0 (ret 4, index argument; ECX = holder) is a recording GUESS stub hooked by address: index 0 returns p0, index 1 returns p1 (random
contents). The ZSysInterface child's vtable slot +0x60 (one argument, ret 4) returns v (or 0) and logs its argument; v is a 0x100-byte object
for the two stores (+0xc and +0x88). The ZSysInterface child slot +0x4c (one argument, ret 4) returns a random value for 0x514270, whose
slot +0x12c takes three arguments (ret 12)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _sys_child(c, slots):
    vt = c.emu.fake_vtable('batch53 child', 0x60 // 4 + 1, slots=slots)
    child = c.emu.fake_object('batch53 child', 0x40, vtable=vt)
    sys_ = _rnd(c, 0x1a00)
    c.emu.w32(sys_ + 0x9b, child)
    c.emu.w32(0x70039c, sys_)


def _gap_chunk(c):
    holder = _rnd(c, 0x40)
    x = _rnd(c, 0x40)
    c.emu.w32(x + 4, holder)
    p0 = _rnd(c, 0x40)
    p1 = _rnd(c, 0x40)

    def h3d0(e, r):
        e.calllog.append(('0x5003d0 (GUESS stub)', 0x5003d0, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=p0 if e.arg32(0) == 0 else p1, argbytes=4)
    c.emu.hook(0x5003d0, h3d0)

    v_none = c.rng.random() < 0.3
    v = 0 if v_none else _rnd(c, 0x100)

    def h60(e, r):
        e.calllog.append(('sys child vtable +0x60 (stub)', 0x60, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=v, argbytes=4)
    _sys_child(c, {0x60: h60})
    return [x]


S(0x511380, 'GUESS FUN_00511380 (0x5003d0 index 0, child vtable +0x60, then store at [v+0xc])', 'stdcall', None, ret=None,
  gen=_gap_chunk, note='unclaimed-66 batch 1950; gap band; 0x5003d0 GUESS stub by address')
S(0x5113c0, 'GUESS FUN_005113c0 (0x5003d0 index 0, child vtable +0x60, then float store at [v+0x88])', 'stdcall', None, ret=None,
  gen=_gap_chunk, note='unclaimed-66 batch 1950; gap band; 0x5003d0 GUESS stub by address')


def _gap514(c):
    self = _rnd(c, 0x400)
    def h12c(e, r):
        e.calllog.append(('this vtable +0x12c (stub)', 0x12c, e.reg('ecx'), (e.arg32(0), e.arg32(1), (e.r32(e.arg32(2)), e.r32(e.arg32(2) + 4)))))
        e.ret(eax=0, argbytes=12)
    vt = c.emu.fake_vtable('batch55 self', 0x12c // 4 + 1, slots={0x12c: h12c})
    c.emu.w32(self, vt)
    rv4c = c.rng.getrandbits(32)

    def h4c(e, r):
        e.calllog.append(('sys child vtable +0x4c (stub)', 0x4c, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=rv4c, argbytes=4)
    _sys_child(c, {0x4c: h4c})
    a = c.rng.getrandbits(32)
    b = c.rng.getrandbits(32)
    return [self, a, b]


S(0x514270, 'GUESS FUN_00514270 (child vtable +0x4c with this, then vtable +0x12c of this with (a, word, &tmp))', 'thiscall', None, ret=None,
  gen=_gap514, note='unclaimed-66 batch 1950; gap band')
