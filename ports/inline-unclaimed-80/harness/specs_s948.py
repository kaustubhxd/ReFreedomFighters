"""specs_s948.py - unclaimed-80 gap band (docs/20-unclaimed-80.md): 0x437670. The argument points to a holder whose first dword is a
NUL-terminated random string (1..24 bytes). The object at self+0xd has a logging vtable whose slot +4 takes one argument (the copy,
callee-cleaned). The allocator 0x41e290 is hooked: it logs its size and returns one fixed non-null block (the same on both sides)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _fn(c):
    k = c.rng.randint(1, 24)
    s = c.emu.alloc(k + 1, 4)
    c.emu.wbytes(s, bytes([c.rng.randint(1, 255) for _ in range(k)]) + b'\x00')
    holder = _rnd(c, 0x40)
    c.emu.w32(holder, s)
    vobj = _rnd(c, 0x40)
    c.emu.w32(vobj, c.emu.logging_vtable('ZGroupCopyDst', 2, argwords={4: 1}))
    self_o = _rnd(c, 0x40)
    c.emu.w32(self_o + 0xd, vobj)
    blk = _rnd(c, 0x40)

    def h_new(em, r):
        size = em.arg32(0)
        c.emu.calllog.append(('heap', 0x41e290, None, (size,)))
        em.ret(eax=blk, argbytes=0)     # cdecl: the caller pops the argument; the same block on both sides (never null here)

    c.emu.hook(0x41e290, h_new)
    return [self_o, holder]


S(0x437670, 'string copy into a new buffer (unknown) thiscall', 'thiscall', None, ret=None, gen=_fn,
  note='unclaimed-80 gap band; strlen, alloc via 0x41e290, copy through NUL, vslot +4 of the object at self+0xd')
