"""specs_s8787.py - residue 6 batch 87 (GUESS names). Callees hooked by address and logged:
FUN_004cd160 (thiscall, plain ret): [this] = 0x695b40; 0x634273([this+4], 4) (cdecl).
FUN_0042f820 (stdcall, ret 4): returns al of 0x4d3810 on ecx=0x6ff938 with (a, 0) (thiscall, ret 8).
FUN_0048cf20 (thiscall, ret 4): q = [this+8]; null -> al 0, else tail to 0x496330 on q with a (thiscall, ret 4).
FUN_004c91a0 (thiscall, ret 8): [this+0x48] = 0x4e5e60 on ecx=b (thiscall, no arguments); returns it."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen_d160(c):
    e = c.emu

    v = c.rng.getrandbits(32)

    def h(em, r):
        em.calllog.append(('634273', 0, None, (em.arg32(0), em.arg32(1))))
        em.ret(eax=v, argbytes=0)
    e.hook(0x634273, h)
    return [_rnd(c, 0x20)]


def _gen_f820(c):
    e = c.emu

    v = c.rng.getrandbits(32)

    def h(em, r):
        em.calllog.append(('4d3810', 0, em.reg('ecx'), (em.arg32(0), em.arg32(1))))
        em.ret(eax=v, argbytes=8)
    e.hook(0x4d3810, h)
    return [c.rng.getrandbits(32)]


def _gen_cf20(c):
    e = c.emu

    v = c.rng.getrandbits(32)

    def h(em, r):
        em.calllog.append(('496330', 0, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=v, argbytes=4)
    e.hook(0x496330, h)
    o = _rnd(c, 0x20)
    if c.rng.random() < 0.3:
        e.w32(o + 8, 0)
    return [o, c.rng.getrandbits(32)]


def _gen_91a0(c):
    e = c.emu

    v = c.rng.getrandbits(32)

    def h(em, r):
        em.calllog.append(('4e5e60', 0, em.reg('ecx'), ()))
        em.ret(eax=v, argbytes=0)
    e.hook(0x4e5e60, h)
    return [_rnd(c, 0x60), c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x4cd160, 'GUESS FUN_004cd160 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen_d160,
  note='residue 6 batch 87; [this]=0x695b40; 0x634273([this+4], 4)')
S(0x42f820, 'GUESS FUN_0042f820 (unknown) stdcall', 'stdcall', None, ret='al', gen=_gen_f820,
  note='residue 6 batch 87; return 0x4d3810(ecx=0x6ff938; a, 0)')
S(0x48cf20, 'GUESS FUN_0048cf20 (unknown) thiscall', 'thiscall', None, ret='al', gen=_gen_cf20,
  note='residue 6 batch 87; q=[this+8]; q ? tail 0x496330(q; a) : 0')
S(0x4c91a0, 'GUESS FUN_004c91a0 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen_91a0,
  note='residue 6 batch 87; [this+0x48] = 0x4e5e60(ecx=b); returns it')
