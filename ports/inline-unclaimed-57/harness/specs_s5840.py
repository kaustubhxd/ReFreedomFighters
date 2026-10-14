"""specs_s5840.py - residue 9, 0x5e4790 (ZFFHeroMovementStand::GetAnims(), gc name map), thiscall, no args, plain ret. The object's vtable slots +0x58 (one arg: the
key; returns a per-key dword) and +0x54 (one arg, logged; the argument's offset from this is logged). The embedded objects at +0x10d, +0x13d, +0x155 and +0x16d
each have a vtable with slot +8 (three args: the pointer as an offset from this, 0, and the float bits; logged)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d4790(c):
    e = c.emu
    rnd = c.rng
    keyv = {k: rnd.getrandbits(32) for k in (0x68d1ac, 0x68acf8, 0x68d1cc, 0x68d1e0, 0x6b7a38, 0x6b7a44, 0x6b7a50)}
    self_obj = _rnd(c, 0x400)

    def rel(p):
        return ('self', p - self_obj) if self_obj <= p < self_obj + 0x400 else ('other', p)

    def h58(em, r):
        k = em.arg32(0)
        em.calllog.append(('58', k, None, ()))
        em.ret(eax=keyv.get(k, 0), argbytes=4)

    def h54(em, r):
        em.calllog.append(('54', rel(em.arg32(0)), None, ()))
        em.ret(eax=0, argbytes=4)

    def h8(em, r):
        em.calllog.append(('8', rel(em.arg32(0)), em.arg32(1), em.arg32(2)))
        em.ret(eax=0, argbytes=12)

    vt_self = e.fake_vtable('d4790_self', 200, {0x58: h58, 0x54: h54})
    vt_emb = e.fake_vtable('d4790_emb', 200, {0x8: h8})
    e.w32(self_obj, vt_self)
    for off in (0x10d, 0x13d, 0x155, 0x16d):
        e.w32(self_obj + off, vt_emb)
    return [self_obj]


S(0x5e4790, 'ZFFHeroMovementStand::GetAnims (gc map) thiscall', 'thiscall', None, ret=None, gen=_d4790,
  note='residue 9; this vt slots +0x58 and +0x54 fake; embedded objects +0x10d, +0x13d, +0x155, +0x16d fake slot +8 (logged)')
