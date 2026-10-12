"""specs_s334.py - gap band, batch 334: 0x602260 (thiscall, one argument) and 0x610170 (stdcall, one byte argument).
602260: the exe allocator 0x41e290 is the fake of batch 332 (global 0x70038c, slot 8 allocates). 610170: the globals 0x72493c (last flag),
0x724a00 (an object whose vtable slot 0xc8 is a thiscall stub with three arguments, recorded) and 0x724944 (result)."""
from pilot import S


def _alloc_fixture(c):
    e = c.emu
    alloc_obj = e.alloc(0x10, 4)
    e.w32(alloc_obj, e.fake_vtable('allocator334', 0x20, {
        0x8: lambda em, r: em.ret(eax=em.alloc(max(em.arg32(0), 4), 16), argbytes=4),
        0x10: lambda em, r: em.ret(eax=0, argbytes=4)}))
    e.w32(0x70038c, alloc_obj)


def _gen602260(c):
    e = c.emu
    rng = c.rng
    _alloc_fixture(c)
    self_ = e.alloc(0x40, 4)
    e.wbytes(self_, rng.randbytes(0x40))
    return [self_, rng.randrange(1, 0x100)]


def _gen610170(c):
    e = c.emu
    rng = c.rng

    def slotc8(em, r):
        a = [em.arg32(k) for k in range(3)]
        em.calllog.append(('slotc8', 0xc8, em.reg('ecx'), tuple(a)))
        em.ret(eax=0, argbytes=12)

    obj = e.alloc(0x40, 4)
    e.w32(obj, e.fake_vtable('obj334', 0x100, {0xc8: slotc8}))
    e.w32(0x724a00, obj)
    e.w32(0x72493c, rng.choice([0, 1, 2, 0x100 + rng.randrange(0, 4)]))
    e.w32(0x724944, rng.getrandbits(32))
    return [rng.choice([0, 1, 2, 0xff, rng.getrandbits(8)]) | (rng.getrandbits(24) << 8)]


S(0x602260, 'set602260 (GUESS)', 'thiscall', None, ret=None, gen=_gen602260, note='batch334; ret 4; allocator fake')
S(0x610170, 'flag610170 (GUESS)', 'stdcall', None, ret=None, gen=_gen610170, note='batch334; ret 4; slot 0xc8 stubbed')
