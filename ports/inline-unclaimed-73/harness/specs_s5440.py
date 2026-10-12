"""specs_s5440.py - area 73 batch 54 (gap band, GUESS names).
FUN_4f4080, FUN_4f5960, FUN_4f6250, FUN_4fac70: each calls a base constructor as a thiscall with three arguments (the base
cleans them), then stores its vtable word and returns this. The base constructors 0x4ee240, 0x4ee210 and 0x4fac70 are hooked
by address and logged. FUN_4f4cd0 (tail-jump row): when dword +0x8f == 1 or +0x70 is 0x20 or 2 it returns; otherwise it
tail-jumps to 0x4fa2f0 with its one stack argument (hooked and logged). Its eax on the early-return path is whatever the
caller left, so the spec does not compare eax (ret None)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _hook_base(c, addr, name):
    def h(em, r):
        em.calllog.append((name, 0, em.reg('ecx'), (em.arg32(0), em.arg32(1), em.arg32(2))))
        em.ret(eax=0, argbytes=12)
    c.emu.hook(addr, h)


def _ctor3(base, name):
    def gen(c):
        _hook_base(c, base, name)
        return [_rnd(c, 0x100), c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]
    return gen


def _gen_4f4cd0(c):
    e = c.emu
    o = _rnd(c, 0x100)
    e.w32(o + 0x8f, c.rng.choice([1, c.rng.getrandbits(32)]))
    e.w32(o + 0x70, c.rng.choice([0x20, 2, c.rng.getrandbits(32)]))

    def h(em, r):
        em.calllog.append(('4fa2f0', 0, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)
    c.emu.hook(0x4fa2f0, h)
    return [o, c.rng.getrandbits(32)]


S(0x4f4080, 'GUESS FUN_4f4080 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_ctor3(0x4ee240, '4ee240'),
  note='area 73 batch 54; base 0x4ee240(this, a, b, c), then [this] = 0x6993dc, returns this')
S(0x4f5960, 'GUESS FUN_4f5960 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_ctor3(0x4ee210, '4ee210'),
  note='area 73 batch 54; base 0x4ee210(this, a, b, c), then [this] = 0x69a370, returns this')
S(0x4f6250, 'GUESS FUN_4f6250 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_ctor3(0x4fac70, '4fac70'),
  note='area 73 batch 54; base 0x4fac70(this, a, b, c), then [this] = 0x69a694, returns this')
S(0x4fac70, 'GUESS FUN_4fac70 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_ctor3(0x4ee240, '4ee240b'),
  note='area 73 batch 54; base 0x4ee240(this, a, b, c), then [this] = 0x69be1c, returns this')
S(0x4f4cd0, 'GUESS FUN_4f4cd0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen_4f4cd0,
  note='area 73 batch 54; tail-jump row: early return on dword +0x8f == 1 or +0x70 in {0x20, 2}; else jmp 0x4fa2f0; eax not compared')
