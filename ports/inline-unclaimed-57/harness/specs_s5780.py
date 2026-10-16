"""specs_s5780.py - unclaimed-57, batch 80: 0x5c2d90 (GUESS name unnamed_5c2d90). Thiscall, three stack arguments (a1, out, idx; ret 0xc),
returns al. The original's callees are hooked: 0x5c2ec0, 0x5c2f90 and 0x5c2f30 (other batches of this area) are logging stubs that
write nothing; 0x5c2e10 (one argument a1, logged) returns r or 0 (zero in about three cases in ten); 0x5c2cb0 (ECX = r, logged) returns
x in -1..5. The table at this+14x+8 and this+0 are random data, so the out words and the index are checked by the heap comparison."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _c2d90(c):
    e = c.emu
    r_obj = _rnd(c, 0x40)
    self_obj = _rnd(c, 0x200)
    fail = c.rng.random() < 0.3
    xv = c.rng.choice([-1, 0, 1, 2, 3, 4, 5])
    a1 = 0 if c.rng.random() < 0.1 else c.rng.getrandbits(32)

    def stub(name):
        def h(em, r):
            tag = 'S' if em.reg('ecx') == self_obj else 'other'
            em.calllog.append((name, 0, tag, ()))
            em.ret(eax=0, argbytes=0)
        return h

    def h2e10(em, r):
        em.calllog.append(('2e10', 0, None, (em.arg32(0),)))
        em.ret(eax=0 if fail else r_obj, argbytes=4)

    def h2cb0(em, r):
        tag = 'R' if em.reg('ecx') == r_obj else 'other'
        em.calllog.append(('2cb0', 0, tag, ()))
        em.ret(eax=xv & 0xffffffff, argbytes=0)

    e.hook(0x5c2ec0, stub('2ec0'))
    e.hook(0x5c2f90, stub('2f90'))
    e.hook(0x5c2f30, stub('2f30'))
    e.hook(0x5c2e10, h2e10)
    e.hook(0x5c2cb0, h2cb0)
    out = _rnd(c, 8)
    idx = _rnd(c, 4)
    return [self_obj, a1, out, idx]


S(0x5c2d90, 'unnamed_5c2d90 (GUESS) thiscall', 'thiscall', None, ret='al', gen=_c2d90,
  note='unclaimed-57 batch 80; callees 0x5c2ec0, 0x5c2f90, 0x5c2f30 stubbed (log); 0x5c2e10 and 0x5c2cb0 hooked (log, fixed results)')
