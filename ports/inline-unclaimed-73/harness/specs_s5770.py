"""specs_s5770.py - area 73 batch 57 (gap band, GUESS names). FUN_4e7d90: plain constructor (vtable 0x6975e4, list head
self-links, returns this). FUN_4e6830: vtable 0x697510, frees this+4 with the delete helper 0x634273 (size 4), and frees this
(size 0x18) when the argument's low bit is set; returns this. FUN_4f4ec0: base 0x4ee240(this,a,b,c) (hooked, logged), then
vtable 0x699f78 and dword +0xb7 = 8; returns this. FUN_4f0420: when +0x36 is non-null, calls vtable +0xc on the object at
g_sys+0x1aa3+0x18 with element arg of the +0x36 array, and returns the word at +4 of that result; otherwise returns 0."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen_4e7d90(c):
    return [_rnd(c, 0x40)]


def _gen_4e6830(c):
    e = c.emu
    o = _rnd(c, 0x40)
    e.w32(o + 4, _rnd(c, 0x20))

    def h(em, r):
        em.calllog.append(('delete634273', 0, None, (em.arg32(0), em.arg32(1))))
        em.ret(argbytes=0)
    c.emu.hook(0x634273, h)
    return [o, c.rng.getrandbits(32)]


def _gen_4f4ec0(c):
    def h(em, r):
        em.calllog.append(('4ee240', 0, em.reg('ecx'), (em.arg32(0), em.arg32(1), em.arg32(2))))
        em.ret(eax=0, argbytes=12)
    c.emu.hook(0x4ee240, h)
    return [_rnd(c, 0x100), c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _gen_4f0420(c):
    e = c.emu
    self_o = _rnd(c, 0x100)
    if c.rng.random() < 0.8:
        arr = _rnd(c, 0x40)
        e.w32(self_o + 0x36, arr)
    else:
        e.w32(self_o + 0x36, 0)
    res = _rnd(c, 0x20)
    e.w32(res, 0)
    e.wbytes(res + 4, bytes([c.rng.getrandbits(8), c.rng.getrandbits(8)]))
    b = _rnd(c, 0x40)
    e.w32(b, e.logging_vtable('b4f0420', 0x20 // 4, impl={0xc: (lambda v: (lambda em, a: (v, None)))(res)},
                              argwords={0xc: 1}))
    a = _rnd(c, 0x40)
    e.w32(a + 0x18, b)
    sys = _rnd(c, 0x2000)
    e.w32(sys + 0x1aa3, a)
    e.w32(0x70039c, sys)
    return [self_o, c.rng.choice([0, 1, 7, c.rng.getrandbits(8)])]


S(0x4e7d90, 'GUESS FUN_4e7d90 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen_4e7d90,
  note='area 73 batch 57; ctor: vt 0x6975e4, list head self-links, +0x1c/+0x18/+0x10/+0x14 = 0, returns this')
S(0x4e6830, 'GUESS FUN_4e6830 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen_4e6830,
  note='area 73 batch 57; vt 0x697510; delete(this+4, 4); if arg&1 delete(this, 0x18); returns this')
S(0x4f4ec0, 'GUESS FUN_4f4ec0 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen_4f4ec0,
  note='area 73 batch 57; base 0x4ee240(this,a,b,c); vt 0x699f78; [this+0xb7] = 8; returns this')
S(0x4f0420, 'GUESS FUN_4f0420 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen_4f0420,
  note='area 73 batch 57; +0x36 array[arg] -> g_sys+0x1aa3 -> +0x18 object vt+0xc(elem); returns word at +4')
