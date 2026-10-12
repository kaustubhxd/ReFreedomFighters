"""specs_s1011.py - unclaimed-07 batch 11 (slice 6): ZItemTemplateWeapon::CopyData (0x46cc20).
The source is a fake object whose slot +0x1e0 gives the type check (true most of the time). Its list at +0xa0 is a
fake list: slot +0x4c is a no-op, slot +0x5c writes 1 or 0 through its pointer argument (a stack address, not logged)
and returns an item for the non-empty cases. The destination list at this+0xa0 logs slot +4. The base copy 0x43f8c0 is
original code (not hooked). Each case has a random source and destination."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _const(v):
    return lambda em, a: (v, None)


def _base_copy(em, r):
    # 0x43f8c0 ends in a tail jump to 0x45d5b0 (the next base-class copy, one argument, thiscall): logged and stubbed
    em.calllog.append(('base45d5b0', 0, em.reg('ecx'), (em.arg32(0),)))
    em.ret(argbytes=4)


def _copydata(c):
    e = c.emu
    e.hook(0x45d5b0, _base_copy)
    dest = _rnd(c, 0x400)
    src = _rnd(c, 0x400)

    check = 1 if c.rng.random() < 0.85 else 0
    e.w32(src, e.logging_vtable('weapon', 0x1e8 // 4, impl={0x1e0: _const(check)}, argwords={0x1e0: 1}))

    # destination list: slot +4 logs its item
    dl = _rnd(c, 0x100)
    e.w32(dl, e.logging_vtable('destlist', 0x20 // 4, impl={0x4: _const(0)}, argwords={0x4: 1}))
    e.w32(dest + 0xa0, dl)

    # source list: 0 to 3 items
    if c.rng.random() < 0.9:
        remaining = [c.rng.randint(0, 3)]
        items = [c.rng.getrandbits(32) | 1 for _ in range(4)]

        def h5c(em, r):
            flag_ptr = em.arg32(0)
            if remaining[0] > 0:
                item = items[remaining[0] % 4]
                remaining[0] -= 1
                em.w32(flag_ptr, 1)
            else:
                item = 0
                em.w32(flag_ptr, 0)
            em.ret(eax=item, argbytes=4)

        def h4c(em, r):
            em.ret(eax=0, argbytes=4)

        sl = _rnd(c, 0x100)
        e.w32(sl, e.fake_vtable('srclist', 0x60 // 4, {0x4c: h4c, 0x5c: h5c}))
        e.w32(src + 0xa0, sl)
    else:
        e.w32(src + 0xa0, 0)
    return [dest, src]


S(0x46cc20, 'ZItemTemplateWeapon::CopyData (unknown) thiscall', 'thiscall', None, ret=None, gen=_copydata,
  note='unclaimed-07 batch 11; ext 0x43f8c0 first; src slot +0x1e0 check; field copies; list loop with +0x4c, +0x5c')
