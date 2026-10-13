"""specs_s79.py - unclaimed-68 batch 79 (slice 7). Names GUESS (FUN_addr). Exe callees 0x54dfa0, 0x469870, 0x63a850 (thiscall, no args),
0x5003d0 and 0x5002f0 (thiscall, ret 4) are hooked and logged; the two KERNEL32 imports of 0x426ff0 are logged stubs in the IAT."""
from pilot import S
from engine_stubs import zero_obj


def _rnd(c, n):
    o = zero_obj(c, n)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return o


def _thiscall_log(c, addr, name, nargs, eax):
    c.emu.hook(addr, lambda em, r: (em.calllog.append((name, em.reg('ecx')) + tuple(em.arg32(i) for i in range(nargs))),
                                    em.ret(eax=eax, argbytes=4 * nargs)))


def _g54ab70(c):
    _thiscall_log(c, 0x54dfa0, 'f54dfa0', 0, c.rng.getrandbits(32))
    o = _rnd(c, 0x4100)
    vt = c.emu.logging_vtable('ZSub54ab70', 0x10, impl={0x10: (lambda v: (lambda e, a: (v, None)))(c.rng.getrandbits(32))})
    c.emu.w32(o + 0x40b1, vt)
    return [o]


def _g61aaf0(c):
    dev = zero_obj(c, 0x40)
    vt = c.emu.logging_vtable('ZDev61aaf0', 0x40, impl={}, argwords={0xc8: 3})
    c.emu.w32(dev, vt)
    c.emu.w32(0x724a00, dev)
    v = c.rng.choice([0, 1, c.rng.getrandbits(32)])
    old = v if c.rng.random() < 0.3 else c.rng.choice([0, 1, c.rng.getrandbits(32)])
    c.emu.w32(0x724948, old)
    return [v]


def _g4ae4f0(c):
    _thiscall_log(c, 0x469870, 'ctor469870', 0, c.rng.getrandbits(32))
    return [_rnd(c, 0x60)]


def _g559f30(c):
    _thiscall_log(c, 0x5003d0, 'f5003d0', 1, c.rng.getrandbits(32))
    _thiscall_log(c, 0x5002f0, 'f5002f0', 1, c.rng.getrandbits(32))
    self_o = _rnd(c, 0x40)
    o = zero_obj(c, 0x20)
    vt = c.emu.logging_vtable('ZSlot559f30', 0x1b0, impl={0x6a8: (lambda v: (lambda e, a: (v, None)))(c.rng.getrandbits(32))})
    c.emu.w32(o, vt)
    c.emu.w32(self_o + 0x1c, o)
    arg = _rnd(c, 0x20)
    return [self_o, arg]


def _g426ff0(c):
    k = c.rng.getrandbits(32)

    def lft(em, r):
        p, q = em.arg32(0), em.arg32(1)
        lo, hi = em.r32(p), em.r32(p + 4)
        em.calllog.append(('FileTimeToLocalFileTime', lo, hi))
        em.w32(q, lo ^ k)
        em.w32(q + 4, (hi + k) & 0xffffffff)
        em.ret(eax=1, argbytes=8)
    ret2 = c.rng.choice([0, 1, c.rng.getrandbits(32)])

    def fst(em, r):
        p, q = em.arg32(0), em.arg32(1)
        em.calllog.append(('FileTimeToSystemTime', em.r32(p), em.r32(p + 4), q))
        em.w32(q, em.r32(p) ^ 0x5a5a5a5a)
        em.ret(eax=ret2, argbytes=8)
    c.emu.w32(0x676104, c.emu.stub_fn('FileTimeToLocalFileTime', lft))
    c.emu.w32(0x6760bc, c.emu.stub_fn('FileTimeToSystemTime', fst))
    return [c.rng.getrandbits(32), c.rng.getrandbits(32), zero_obj(c, 0x10)]


def _g659070(c):
    _thiscall_log(c, 0x63a850, 'ctor63a850', 0, c.rng.getrandbits(32))
    g = _rnd(c, 0x1920)
    c.emu.w32(0x70039c, g)
    return [_rnd(c, 0xb9b0)]


S(0x54ab70, 'FUN_54ab70 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_g54ab70,
  note='unclaimed-68 batch 79: 0x54dfa0(this) then tail call [this+0x40b1].slot+0x10')
S(0x61aaf0, 'FUN_61aaf0 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_g61aaf0,
  note='unclaimed-68 batch 79: cached device state 0x89 (D3DRS_LIGHTING, GUESS) via [0x724a00].slot+0xc8')
S(0x4ae4f0, 'FUN_4ae4f0 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_g4ae4f0,
  note='unclaimed-68 batch 79: ctor, base 0x469870, vt 0x690cc0')
S(0x559f30, 'FUN_559f30 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_g559f30,
  note='unclaimed-68 batch 79: 0x5002f0(0x5003d0([arg+8], 0), [this+0x1c].slot+0x6a8())')
S(0x426ff0, 'FUN_426ff0 (GUESS) stdcall', 'stdcall', None, ret='al', gen=_g426ff0,
  note='unclaimed-68 batch 79: FileTimeToLocalFileTime then FileTimeToSystemTime, returns bool')
S(0x659070, 'FUN_659070 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_g659070,
  note='unclaimed-68 batch 79: ctor, base 0x63a850, vt 0x6c4410, +0xb9a4 from [[0x70039c]+0x190f]')
