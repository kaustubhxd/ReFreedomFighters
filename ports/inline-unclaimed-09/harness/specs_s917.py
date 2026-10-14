"""specs_s917.py - unclaimed-09 batch 9 (docs/20-unclaimed-09.md, claim 9): ZFFHeroIf::~ZFFHeroIf.

Object: 0x100 random bytes. Flags: random 32-bit, so bit 0 is set in about half the cases.
Hooks (emu.hook, both unverified callees, both log their object pointer, which is a heap value):
- 0x504870 (base destructor, thiscall): writes 0x69cc88 at the object and returns (the real one tail-jumps further);
- 0x634273 (cdecl free): returns with a plain ret; the caller pops the two arguments."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _base(e2, r):
    this = e2.reg('ecx')
    e2.calllog.append(('Base504870', this))
    e2.w32(this, 0x69cc88)
    e2.ret(argbytes=0)


def _free(e2, r):
    e2.calllog.append(('Free634273', e2.arg32(0), e2.arg32(1)))
    e2.ret(argbytes=0)


def _gen(c):
    c.emu.hook(0x504870, _base)
    c.emu.hook(0x634273, _free)
    return [_rnd(c, 0x100), c.rng.getrandbits(32)]


S(0x55ee00, 'ZFFHeroIf::~ZFFHeroIf (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-09 b9; base dtor 0x504870 and free 0x634273 hooked (unverified callees)')
