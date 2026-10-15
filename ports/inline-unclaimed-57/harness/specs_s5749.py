"""specs_s5749.py - unclaimed-57, band batch 49: 0x5c3000 (GUESS). Thiscall, no args. The byte at +0xf4 takes 0, 1, 2 and a fourth value (so all
four branches run). Hook: 0x5c3560 (thiscall, two args, pops 8; logged). Stubs: the object's slot +0x68 (two args) and +0x64 (one arg), logged.
The engine dword at +0x40 is random."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _init(c):
    def h(em, r):
        em.calllog.append(('5c3560', 0, em.reg('ecx'), (em.arg32(0), em.arg32(1))))
        em.ret(eax=0, argbytes=8)
    c.emu.hook(0x5c3560, h)
    vt = c.emu.logging_vtable('band5c3000_obj', 32, argwords={0x64: 1, 0x68: 2})
    obj = _rnd(c, 0x200)
    c.emu.w32(obj, vt)
    c.emu.wbytes(obj + 0xf4, bytes([c.rng.choice([0, 1, 2, 3])]))
    eng = _rnd(c, 0x100)
    c.emu.w32(eng + 0x40, c.rng.getrandbits(32))
    c.emu.w32(0x70039c, eng)
    return [obj]


S(0x5c3000, 'unnamed_5c3000 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_init,
  note='unclaimed-57 band batch 49; 0x5c3560 hooked (logged, pops 8); slots +0x68 and +0x64 stubbed (logged)')
