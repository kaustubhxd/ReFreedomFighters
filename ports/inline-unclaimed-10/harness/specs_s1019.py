"""specs_s1019.py - unclaimed-10, batch 15: CMsgForward::CopyEventDataBlock (0x49eed0). Thiscall, one argument (DBREAD),
ret 4. The two DBREAD readers (0x4e5e60, 0x4e5e40; ecx = DBREAD, no stack arguments) are hooked with fixed results chosen in
gen, so both runs see the same values. The engine object (global 0x70039c, field +0x9b) has a logging vtable; its slot +0x58
(one argument) is stubbed."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _ev(c):
    e = c.emu
    v1 = c.rng.getrandbits(32)
    v2 = c.rng.getrandbits(32)
    e.hook(0x4e5e60, lambda em, r: em.ret(eax=v1, argbytes=0))
    e.hook(0x4e5e40, lambda em, r: em.ret(eax=v2, argbytes=0))
    vt_eng = e.logging_vtable('engmsg', 32, argwords={0x58: 1})
    eng_obj = _rnd(c, 0x40)
    e.w32(eng_obj, vt_eng)
    eng = _rnd(c, 0x100)
    e.w32(eng + 0x9b, eng_obj)
    e.w32(0x70039c, eng)
    return [_rnd(c, 0x800), _rnd(c, 0x40)]


S(0x49eed0, 'CMsgForward::CopyEventDataBlock (unknown) thiscall', 'thiscall', None, ret=None, gen=_ev,
  note='unclaimed-10 batch 15; readers 0x4e5e60/0x4e5e40 hooked (fixed results); engine slot +0x58 stubbed')
