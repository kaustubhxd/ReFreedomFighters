"""specs_s2407.py - decomp area 24, batch 2407: CSewerMenu::EnableButtons (0x5706f0), thiscall, void.
The menu's +0x94 pointer leads to a block whose string at +0x48 is compared with three constant strings in the exe
image (0x6a8794, 0x6a7808, 0x6a7810). The spec copies those constants at generation time (they are read from the
emulator's image) and sets the string at +0x48 to one of them, a one-character or prefix near miss, or a random word,
so each compare has an equal and a non-equal outcome. Flags +0x1a0..+0x1a3 start random."""
from pilot import S
from recruits_util import rnd, clear_hooks


CONST_ADDRS = (0x6a8794, 0x6a7808, 0x6a7810)


def _gen(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    consts = []
    for a in CONST_ADDRS:
        raw = e.rbytes(a, 64)
        consts.append(raw.split(b'\0')[0])
    menu = rnd(c, 0x200)
    inner = rnd(c, 0x100)
    g = r.choice(consts)
    kind = r.random()
    if kind < 0.4:
        s = g
    elif kind < 0.55 and len(g) > 0:
        i = r.randrange(len(g))
        s = g[:i] + bytes([(g[i] + 1) & 0x7f or 0x41]) + g[i + 1:]
    elif kind < 0.7 and len(g) > 1:
        s = g[:r.randint(0, len(g) - 1)]
    elif kind < 0.8:
        s = b''
    else:
        s = bytes(r.randint(0x41, 0x5a) for _ in range(r.randint(1, 8)))
    e.wbytes(inner + 0x48, s + b'\0')
    e.w32(menu + 0x94, inner)
    e.w8(menu + 0x1a0, r.randint(0, 255))
    e.w8(menu + 0x1a1, r.randint(0, 255))
    e.w8(menu + 0x1a2, r.randint(0, 255))
    e.w8(menu + 0x1a3, r.choice([0, 1, 1]))
    return [menu]


S(0x5706f0, 'CSewerMenu::EnableButtons', 'thiscall', None, ret=None, gen=_gen, note='batch2407')
