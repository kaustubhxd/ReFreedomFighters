"""specs_s5827.py - residue 9, 0x4b8a10 (ZRelayMessageList::Load(ZLoadGame*), gc name map), thiscall, one stack argument, ret 4, returns al = 1. The argument
object L has a fake vtable with slot +0x50 (one arg: logs the address as an offset from this; writes nothing)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d4b8a10(c):
    e = c.emu
    self_obj = _rnd(c, 0x100)
    L = _rnd(c, 0x40)

    def h50(em, r):
        p = em.arg32(0)
        off = p - (self_obj + 0x54) if self_obj + 0x54 <= p < self_obj + 0x60 else 'other'
        em.calllog.append(('L50', 'self+0x54' if off == 0 else off, None, ()))
        em.ret(eax=0, argbytes=4)

    vt = e.fake_vtable('d4b8a10_L', 200, {0x50: h50})
    e.w32(L, vt)
    return [self_obj, L]


S(0x4b8a10, 'ZRelayMessageList::Load(ZLoadGame*) (gc map) thiscall', 'thiscall', None, ret='al', gen=_d4b8a10,
  note='residue 9; L slot +0x50 fake (logs the pointer as an offset from this+0x54)')
