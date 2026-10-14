"""specs_s942.py - area 56 residue 15 (docs/20-unclaimed-56.md, claim A1): ZCarIf and ZFFActorIf scalar deleting destructors.

Unverified callees (GUESS recording stubs): the base destructors 0x51aa60 and 0x506360 log their object pointer and write
nothing; the free 0x634273 (cdecl) logs its two arguments and returns with a plain ret (the caller pops them). The object is
0x100 random bytes; the flags argument is random, so bit 0 is set in about half the cases."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _hook(name):
    def h(e2, r):
        e2.calllog.append((name, e2.reg('ecx')))
        e2.ret(argbytes=0)
    return h


def _free(e2, r):
    e2.calllog.append(('Free634273', e2.arg32(0), e2.arg32(1)))
    e2.ret(argbytes=0)


def _gen(c):
    c.emu.hook(0x51aa60, _hook('Base51aa60'))
    c.emu.hook(0x506360, _hook('Base506360'))
    c.emu.hook(0x634273, _free)
    return [_rnd(c, 0x100), c.rng.getrandbits(32)]


S(0x51b030, 'ZCarIf::~ZCarIf (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-56 A1; base 0x51aa60 and free 0x634273 stubbed (unverified callees)')
S(0x557b70, 'ZFFActorIf::~ZFFActorIf (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-56 A1; base 0x506360 and free 0x634273 stubbed (unverified callees)')
