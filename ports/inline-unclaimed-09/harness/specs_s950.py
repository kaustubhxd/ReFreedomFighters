"""specs_s950.py - area 56, claim A9: ZItemTemplate::GetAvailableStates() const (0x46e470). SEH frame not reproduced.

The allocator (0x41e290) returns a heap object in about 80% of cases, else 0; when it returns 0 the list at this+0x70 is null
(the original would fault on a non-null list with a null result). The result object (from 0x4ccbe0) has a vt+4 that logs its
argument. The list is a fake object: vt+0x4c logs; vt+0x5c hands out ids from a short sequence with repeats (so the bitmask
skip runs) and writes the flag. The local struct's constructor and destructor are GUESS recording stubs that write nothing."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    e = c.emu
    rng = c.rng
    alloc_ok = rng.random() < 0.8
    ids = [rng.randrange(0, 40) for _ in range(rng.randint(0, 5))]
    ids = ids + ids[:1] if ids and rng.random() < 0.5 else ids
    seq = {'i': 0}
    res = e.fake_object('gas_result', 0x40, slots={4: None})

    def h4(e2, r):
        e2.calllog.append(('Res4', e2.arg32(0)))
        e2.ret(argbytes=4)

    res = e.fake_object('gas_result', 0x40, slots={4: h4})

    def h4c(e2, r):
        e2.calllog.append(('L4c',))
        e2.ret(eax=0, argbytes=4)

    def h5c(e2, r):
        flagp = e2.arg32(0)
        i = seq['i']
        seq['i'] = i + 1
        if i < len(ids):
            e2.w32(flagp, 1)
            e2.calllog.append(('L5c', ids[i]))
            e2.ret(eax=ids[i], argbytes=4)
        else:
            e2.w32(flagp, 0)
            e2.calllog.append(('L5c', 'end'))
            e2.ret(eax=0, argbytes=4)

    def hctor(e2, r):
        e2.calllog.append(('Ctor4cbeb0',))
        e2.ret(argbytes=0)

    def hdtor(e2, r):
        e2.calllog.append(('Dtor4cbec0',))
        e2.ret(argbytes=0)

    def halloc(e2, r):
        e2.calllog.append(('Alloc41e290', e2.arg32(0)))
        e2.ret(eax=(allocp if alloc_ok else 0), argbytes=0)

    def h4ccb(e2, r):
        e2.calllog.append(('Make4ccbe0', e2.arg32(0), e2.arg32(1)))
        e2.ret(eax=res, argbytes=8)

    lst = e.fake_object('gas_list', 0x40, slots={0x4c: h4c, 0x5c: h5c})
    allocp = _rnd(c, 0x20)
    e.hook(0x4cbeb0, hctor)
    e.hook(0x4cbec0, hdtor)
    e.hook(0x41e290, halloc)
    e.hook(0x4ccbe0, h4ccb)
    this = _rnd(c, 0x100)
    e.w32(this + 0x70, lst if (alloc_ok and rng.random() < 0.8) else 0)
    return [this]


S(0x46e470, 'ZItemTemplate::GetAvailableStates (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-56 A9; SEH frame not reproduced; ctor/dtor/alloc/make and list stubs are GUESS recording stubs')
