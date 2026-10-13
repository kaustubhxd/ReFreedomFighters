"""specs_s5828.py - residue 9, 0x479810 (ZActor::OnPathCanceled(PATH_CANCEL_REASONS), gc name map), thiscall, one stack argument, ret 4. The object's own
vtable slot +0x128 (three args: the word at 0x6ffa2c, the argument, 0) is a logging stub that writes nothing; the word at 0x6ffa2c is a per-case value."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d9810(c):
    e = c.emu
    rnd = c.rng
    word = rnd.getrandbits(16)
    e.wbytes(0x6ffa2c, word.to_bytes(2, 'little'))

    def h128(em, r):
        em.calllog.append(('128', 0, None, (em.arg32(0), em.arg32(1), em.arg32(2))))
        em.ret(eax=0, argbytes=12)

    vt = e.fake_vtable('d9810_self', 200, {0x128: h128})
    self_obj = _rnd(c, 0x800)
    e.w32(self_obj, vt)
    e.w32(self_obj + 0x6ba, rnd.getrandbits(32))
    e.wbytes(self_obj + 0x6be, bytes([rnd.getrandbits(8)]))
    return [self_obj, rnd.getrandbits(32)]


S(0x479810, 'ZActor::OnPathCanceled (gc map) thiscall', 'thiscall', None, ret=None, gen=_d9810,
  note='residue 9; own vtable slot +0x128 fake (three args logged); word at 0x6ffa2c random')
