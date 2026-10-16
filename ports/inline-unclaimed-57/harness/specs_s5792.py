"""specs_s5792.py - unclaimed-57, batch 92: 0x5d3eb0 (GUESS name unnamed_5d3eb0). Thiscall, no stack args, plain ret. The engine (global
0x70039c) sub-object at +0x9b has a fake slot +0x114 (four args, logged) that returns a random dword: the upper 16 bits are random too, so
only the stored low word is checked. The fields are random bytes in this, so the unaligned dword store at +0x85 is checked by the heap."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d3eb0(c):
    e = c.emu
    rv = [c.rng.getrandbits(32) for _ in range(4)]
    idx = [0]

    def h114(em, r):
        k = idx[0]
        idx[0] += 1
        em.calllog.append(('114', 0, None, (em.arg32(0), em.arg32(1), em.arg32(2), em.arg32(3))))
        em.ret(eax=rv[k % 4], argbytes=16)

    vt_sub = e.fake_vtable('d3eb0_sub', 160, {0x114: h114})
    sub = _rnd(c, 0x40)
    e.w32(sub, vt_sub)
    eng = _rnd(c, 0x100)
    e.w32(eng + 0x9b, sub)
    e.w32(0x70039c, eng)
    self_obj = _rnd(c, 0x200)
    return [self_obj]


S(0x5d3eb0, 'unnamed_5d3eb0 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_d3eb0,
  note='unclaimed-57 batch 92; engine sub slot +0x114 fake (four args logged, random dword)')
