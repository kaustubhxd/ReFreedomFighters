"""specs_s5706.py - unclaimed-57, batch 6: ZPlayer::CreateMovements (0x482ac0). Thiscall, no arguments. Stubs: the object's vtable
(logging; slots +0x624 and +0x644 take one argument; +0x62c, +0x630, +0x634, +0x638, +0x63c take none and return fixed values);
the array entries (count 0 to 3) have a logging vtable with slot +4 (one argument). The fill 0x634d10 (cdecl ptr, value, size) is
hooked to write the same bytes in both runs (the port calls the same address, so the hook serves both)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _create(c):
    e = c.emu

    def fill(em, r):
        p, v, n = em.arg32(0), em.arg32(1), em.arg32(2)
        em.wbytes(p, bytes([v & 0xff]) * n)
        em.ret(eax=p, argbytes=0)
    e.hook(0x634d10, fill)
    vt_obj = e.logging_vtable('zplayer', 410,
                              impl={0x63c: lambda em, a: (0x1111, None), 0x62c: lambda em, a: (0x2222, None),
                                    0x630: lambda em, a: (0x3333, None), 0x634: lambda em, a: (0x4444, None),
                                    0x638: lambda em, a: (0x5555, None)},
                              argwords={0x624: 1, 0x644: 1})
    vt_elem = e.logging_vtable('zplayer_elem', 8, argwords={4: 1})
    obj = _rnd(c, 0x800)
    e.w32(obj, vt_obj)
    k = c.rng.choice([0, 1, 2, 3])
    e.w32(obj + 0x459, k)
    for i in range(k):
        if c.rng.random() < 0.3:
            e.w32(obj + 0x45d + 4 * i, 0)
        else:
            el = _rnd(c, 0x40)
            e.w32(el, vt_elem)
            e.w32(obj + 0x45d + 4 * i, el)
    return [obj]


S(0x482ac0, 'ZPlayer::CreateMovements (unknown) thiscall', 'thiscall', None, ret=None, gen=_create,
  note='unclaimed-57 batch 6; this slots stubbed; element slot +4 stubbed; fill 0x634d10 hooked (memset semantics)')
