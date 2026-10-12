"""specs_s1022.py - unclaimed-04 batch 23 (docs/20-unclaimed-04.md): three slice-3 scalar deleting destructors (GUESS labels).
thiscall, one flag argument (ret 4), returns this. 0x42acf0 stores vtable 0x679754. 0x5f1430 and 0x601470 call the base
destructors 0x6012e0 and 0x6035a0 (original code). Then, when flag bit 0 is set, the free 0x634273 (cdecl, pointer and size)
is called with 0x12, 0x10 and 0x2a. The free is a logging hook (GUESS)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _setup_free(c):
    def free34(em, r):
        em.calllog.append(('634273', 0, 0, (em.arg32(0), em.arg32(1))))
        em.ret(eax=0, argbytes=0)

    def release41(em, r):
        em.calllog.append(('41e2c0', 0, 0, (em.arg32(0),)))
        em.ret(eax=0, argbytes=0)

    c.emu.hook(0x634273, free34)
    c.emu.hook(0x41e2c0, release41)  # the base destructors release through 0x41e2c0 (GUESS)


def _args(c):
    o = _rnd(c, 0x100)
    flags = c.rng.choice([0, 1, 2, 3, c.rng.getrandbits(32)])
    return [o, flags]


S(0x42acf0, 'unknown::dtor_vtable_679754 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_args, setup=_setup_free,
  note='unclaimed-04 batch 23; free 0x634273 hooked (GUESS); size 0x12')
def _args_base(c):
    o = _rnd(c, 0x100)
    if c.rng.random() < 0.5:
        # empty list: null pointer at +0xc, count 0 at +0x14
        c.emu.w32(o + 0xc, 0)
        c.emu.w32(o + 0x14, 0)
    else:
        # one-element list: the sub-destructor (0x603900) walks it; the element is a type-0 entry whose data is a fake
        # object with a recording vtable (slot 0x28, no arguments)
        fvt = c.emu.fake_vtable('list item', 0x28 // 4 + 1,
                                {0x28: lambda em, r: (em.calllog.append(('item.28', 0, em.reg('ecx'), ())), em.ret(eax=0, argbytes=0))})
        item = c.emu.alloc(0x20, 4)
        c.emu.w32(item, fvt)
        node = c.emu.alloc(8, 4)
        c.emu.w32(node, item)
        c.emu.wbytes(node + 4, bytes([0]))
        c.emu.w32(o + 0xc, node)
        c.emu.w32(o + 0x14, 1)
    return [o, c.rng.choice([0, 1, 2, 3, c.rng.getrandbits(32)])]


def _args_5f1430(c):
    # 0x6012e0 keeps a count at +0xc and an array of pointers at +4 (not the layout of 0x603900): an empty count is 0; the
    # one-element case is count 1 with a zero element, so the loop runs and skips the element call
    o = _rnd(c, 0x100)
    if c.rng.random() < 0.5:
        c.emu.w32(o + 0xc, 0)
    else:
        arr = c.emu.alloc(8, 4)
        c.emu.w32(arr, 0)
        c.emu.w32(o + 4, arr)
        c.emu.w32(o + 0xc, 1)
    return [o, c.rng.choice([0, 1, 2, 3, c.rng.getrandbits(32)])]


S(0x5f1430, 'unknown::dtor_base_6012e0 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_args_5f1430, setup=_setup_free,
  note='unclaimed-04 batch 23; base dtor 0x6012e0 original; size 0x10')
S(0x601470, 'unknown::dtor_base_6035a0 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_args_base, setup=_setup_free,
  note='unclaimed-04 batch 23; base dtor 0x6035a0 original; size 0x2a')
