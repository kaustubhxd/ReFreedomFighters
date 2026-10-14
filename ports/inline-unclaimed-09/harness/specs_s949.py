"""specs_s949.py - area 56 residue 15, claim A8: ZSHAPE::CopyData(const ZGEOM*) (0x44aa70).

The source object is a 0x40-byte fake object: its slot 0x1e0 logs its argument and returns a random bool (the low byte is
what the original tests). Its +0x18 pointer takes four choices: null (returns), below the base block (tail), inside the base
block (returns), and past its end (tail); the base is also null in about one case in five (tail). The engine object M
(global+0x9b, 0x2000 random bytes) holds the base at +0x1c5d; the base block has its size header (0x80) at base-8. The copy
helper 0x45d5b0 and the tail target (the object at 0x70038c, slot 0xbc) are GUESS recording stubs (unverified); the tail stub
logs its argument and returns with ret 4. The source's flag and the tail target's log show which branch ran."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    e = c.emu
    rng = c.rng
    flag = 1 if rng.random() < 0.8 else 0

    def h45d5(e2, r):
        e2.calllog.append(('E45d5b0', e2.reg('ecx'), e2.arg32(0)))
        e2.ret(argbytes=4)

    def h1e0(e2, r):
        e2.calllog.append(('Src1e0', e2.arg32(0)))
        e2.ret(eax=flag, argbytes=4)

    def htail(e2, r):
        e2.calllog.append(('Tail0bc', e2.arg32(0)))
        e2.ret(argbytes=4)

    e.hook(0x45d5b0, h45d5)
    region = _rnd(c, 0x108)
    base = region + 8
    # size header at base-8: 0x80 with random flag bits, and bit 28 set in half the cases (the end mask must drop it)
    e.w32(region, 0x80 | (rng.getrandbits(32) & 0xe0000000) | (0x10000000 if rng.random() < 0.5 else 0))
    base_zero = rng.random() < 0.2
    m = _rnd(c, 0x2000)
    e.w32(m + 0x1c5d, 0 if base_zero else base)
    g = _rnd(c, 0x2000)
    e.w32(g + 0x9b, m)
    e.w32(0x70039c, g)
    obj70 = e.fake_object('shape_tail', 0x40, slots={0xbc: htail})
    e.w32(0x70038c, obj70)
    src = e.fake_object('shape_src', 0x40, slots={0x1e0: h1e0})
    choice = rng.randrange(4)
    if choice == 0:
        p = 0
    elif choice == 1:
        p = base - 4
    elif choice == 2:
        p = base + 0x10
    else:
        p = base + 0x100
    e.w32(src + 0x18, p)
    this = _rnd(c, 0x40)
    return [this, src]


S(0x44aa70, 'ZSHAPE::CopyData (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-56 A8; 0x45d5b0 and the tail target are GUESS recording stubs (unverified)')
