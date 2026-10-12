"""specs_s5660.py - area 73 batch 56 (gap band, GUESS names).
FUN_4f5920 (ret 8): when [this+0xbb] == a and [this+0xbf] == b it returns; otherwise it stores both and calls vtable +0x27c.
FUN_4f3c00 (ret 0xc, returns this): base 0x4ee210(this, a, b, c) (hooked, logged), then [this] = 0x69909c and [this+0x60] = 0.
FUN_4e8bd0 (plain ret, returns this): clears +0x14, +0xa4 (word), +0x60, +0x64, +0xc, +0x10.
FUN_4f4d30 (tail-jump row, ret 4 on its early path): when the argument is 1 and [this+0x70] == 2 it calls vtable +0x2ec(1)
and returns 1; otherwise it tail-jumps to 0x560360 (hooked and logged, arity 1)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen_4f5920(c):
    e = c.emu
    o = _rnd(c, 0x100)
    a, b = c.rng.getrandbits(32), c.rng.getrandbits(32)
    if c.rng.random() < 0.4:
        e.w32(o + 0xbb, a)
        e.w32(o + 0xbf, b)
    else:
        e.w32(o + 0xbb, c.rng.choice([a, c.rng.getrandbits(32)]))
        e.w32(o + 0xbf, c.rng.choice([b, c.rng.getrandbits(32)]))
    e.w32(o, e.logging_vtable('f5920', 0x280 // 4, impl={0x27c: lambda em, x: (0, None)}, argwords={0x27c: 0}))
    return [o, a, b]


def _gen_4f3c00(c):
    def h(em, r):
        em.calllog.append(('4ee210', 0, em.reg('ecx'), (em.arg32(0), em.arg32(1), em.arg32(2))))
        em.ret(eax=0, argbytes=12)
    c.emu.hook(0x4ee210, h)
    return [_rnd(c, 0x100), c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _gen_4e8bd0(c):
    return [_rnd(c, 0x100)]


def _gen_4f4d30(c):
    e = c.emu
    o = _rnd(c, 0x100)
    e.w32(o + 0x70, c.rng.choice([2, c.rng.getrandbits(32)]))
    e.w32(o, e.logging_vtable('f4d30', 0x2f0 // 4, impl={0x2ec: lambda em, x: (0, None)}, argwords={0x2ec: 1}))

    def h(em, r):
        em.calllog.append(('560360', 0, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=0x100 | (em.arg32(0) & 1), argbytes=4)
    e.hook(0x560360, h)
    arg = c.rng.choice([1, c.rng.getrandbits(32)])
    return [o, arg]


S(0x4f5920, 'GUESS FUN_4f5920 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen_4f5920,
  note='area 73 batch 56; if [+0xbb]==a and [+0xbf]==b return; else store both, vt+0x27c()')
S(0x4f3c00, 'GUESS FUN_4f3c00 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen_4f3c00,
  note='area 73 batch 56; base 0x4ee210(this,a,b,c), [this]=0x69909c, [this+0x60]=0, returns this')
S(0x4e8bd0, 'GUESS FUN_4e8bd0 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen_4e8bd0,
  note='area 73 batch 56; clears +0x14, +0xa4(word), +0x60, +0x64, +0xc, +0x10; returns this')
S(0x4f4d30, 'GUESS FUN_4f4d30 (unknown) thiscall', 'thiscall', None, ret='al', gen=_gen_4f4d30,
  note='area 73 batch 56; tail-jump row: arg 1 and +0x70==2 -> vt+0x2ec(1), return 1; else jmp 0x560360 (hooked)')
