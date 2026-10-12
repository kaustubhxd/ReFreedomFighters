"""specs_s343.py - gap band, batch 343: 0x604170 (thiscall, one argument, returns this). The allocator global 0x70038c is the batch 332 fake
(slot 8 allocates). The object and the argument are random."""
from pilot import S


def _fill(em, n):
    # the fake allocator returns memory full of 0xA5, so the zeroing of the caller is visible
    p = em.alloc(n, 16)
    em.wbytes(p, b'\xa5' * n)
    return p


def _gen(c):
    e = c.emu
    rng = c.rng
    alloc_obj = e.alloc(0x10, 4)
    e.w32(alloc_obj, e.fake_vtable('allocator343', 0x20, {
        0x8: lambda em, r: em.ret(eax=_fill(em, max(em.arg32(0), 4)), argbytes=4),
        0x10: lambda em, r: em.ret(eax=0, argbytes=4)}))
    e.w32(0x70038c, alloc_obj)
    self_ = e.alloc(0x40, 4)
    e.wbytes(self_, rng.randbytes(0x40))
    return [self_, rng.getrandbits(32)]


S(0x604170, 'ctor604170 (GUESS)', 'thiscall', None, ret='eax', gen=_gen, note='batch343; ret 4; allocator fake at 0x70038c')
