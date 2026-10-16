"""specs_s379.py - area 76, residue 17, batch 379 (thiscall; GUESS). 0x562e90 (stdcall, two words, ret 8) and 0x4eb350 (thiscall, one word, ret 4)
are hooked by address and log their arguments (writing nothing). 0x57aa50's vtable slot 0x64 (thiscall, one word) is stubbed. 0x650dd0's old
object (this+0x8c, null sometimes) has a slot 0 (thiscall, one word) stub that logs."""
from pilot import S


def _gen_57a(c):
    e = c.emu
    rng = c.rng

    def h562(em, r):
        em.calllog.append(('h562e90', 0x562e90, None, (em.arg32(0), em.arg32(1))))
        em.ret(eax=0, argbytes=8)

    e.hook(0x562e90, h562)
    vt = e.fake_vtable('o57a', 0x80 // 4 * 4, {0x64: lambda em, r: (em.calllog.append(('o64', 0x64, em.reg('ecx'), (em.arg32(0),))), em.ret(eax=0, argbytes=4))})
    this = e.alloc(0x40, 4)
    e.w32(this, vt)
    return [this, rng.getrandbits(32), rng.getrandbits(32)]


def _gen_661(c):
    e = c.emu
    rng = c.rng

    def h4eb(em, r):
        em.calllog.append(('h4eb350', 0x4eb350, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    e.hook(0x4eb350, h4eb)
    this = e.alloc(0x40, 4)
    e.wbytes(this, rng.randbytes(0x40))
    return [this, rng.getrandbits(32)]


def _gen_650(c):
    e = c.emu
    rng = c.rng

    def h0(em, r):
        em.calllog.append(('old0', 0, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    old_vt = e.fake_vtable('old650', 0x40 // 4 * 4, {0: h0})
    old = e.alloc(0x40, 4)
    e.w32(old, old_vt)
    this = e.alloc(0x100, 4)
    e.wbytes(this, rng.randbytes(0x100))
    e.w32(this + 0x8c, old if rng.random() < 0.7 else 0)
    return [this, rng.getrandbits(32)]


S(0x57aa50, 'check57aa50 (GUESS)', 'thiscall', None, ret='al', gen=_gen_57a, note='area 76 batch 379; residue 17; 0x562e90 hooked')
S(0x661310, 'init661310 (GUESS)', 'thiscall', None, ret='eax', gen=_gen_661, note='area 76 batch 379; residue 17; 0x4eb350 hooked')
S(0x650dd0, 'swap650dd0 (GUESS)', 'thiscall', None, ret=None, gen=_gen_650, note='area 76 batch 379; residue 17')
