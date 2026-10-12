"""specs_s324.py - decomp area 64 (docs/20-unclaimed-64.md): 0x5c2630 keyed flag setter with three stubbed virtual calls."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


# The three compare words are runtime globals (zero in the image), so the spec sets them. The values are the ones the
# shipped image's startup data holds at these addresses, so each key is distinct.
KEYS = (0x3b4b, 0x3baa, 0x3c07)


def _flag(c):
    e = c.emu
    keys = list(KEYS)
    e.w16(0x71432c, keys[0])
    e.w16(0x714330, keys[1])
    e.w16(0x714334, keys[2])
    r = c.rng.random()
    if r < 0.8:
        a16 = keys[min(int(r / 0.8 * 3), 2)]         # one of the three keys
    else:
        a16 = c.rng.getrandbits(16)                  # a random 16-bit key
    # The stack word has random upper bits: the exe compares only the low 16 bits (cmp ax).
    word = (c.rng.getrandbits(16) << 16) | a16

    # Object returned by slot 0x58: its slot 0x12c takes one word and returns nothing.
    e_obj_vt = e.logging_vtable('obj5c26', 0x80, argwords={0x12c: 1})
    e_obj = _rnd(c, 0x40)
    e.w32(e_obj, e_obj_vt)
    e_ptr = e_obj if c.rng.random() < 0.8 else 0

    # Child on the global at 0x70039c (+0x9b): slot 0x58 takes one word and returns the object; slot 0x114 takes six
    # words and returns a 16-bit value. Both pop their own words (thiscall).
    res = c.rng.getrandbits(16)
    child_vt = e.logging_vtable('child5c26', 0x80,
                                impl={0x58: lambda em, a: (e_ptr, None), 0x114: lambda em, a: (res, None)},
                                argwords={0x58: 1, 0x114: 6})
    child = _rnd(c, 0x40)
    e.w32(child, child_vt)
    sys_ = _rnd(c, 0x1000)
    e.w32(sys_ + 0x9b, child)
    e.w32(0x70039c, sys_)

    self_ = _rnd(c, 0x300)
    e.w32(self_ + 0x50, c.rng.getrandbits(32))
    return [self_, word, c.rng.getrandbits(32)]


S(0x5c2630, 'flagByKey (GUESS)', 'thiscall', None, ret='eax', gen=_flag,
  note='batch324; key word in a stack arg (low 16 bits); ret 8; slots 0x58 (1 arg), 0x114 (6 args), 0x12c (1 arg) stubbed')
