"""specs_s328.py - gap band, batch 328: 0x605380 (thiscall, one argument, returns bool) and 0x6132f0 (thiscall, two arguments).
605380: the object's +0xc is a NUL-terminated name; the helper 0x5f2d60 is hooked (recorded, its arguments logged).
6132f0: a large random table (this); the pointer at this+4*t has a +0x3c object whose dwords are small indices (so the reads stay inside
the table)."""
from pilot import S


def _rec(em, r):
    # 0x5f2d60 (thiscall with ECX = arg; two stack words; the callee pops them): recorded by address
    em.calllog.append(('h5f2d60', 0, em.reg('ecx'), (em.arg32(0), em.arg32(1))))
    em.ret(eax=0, argbytes=8)


def _name(c):
    e = c.emu
    rng = c.rng
    e.hook(0x5f2d60, _rec)
    name = ''.join(rng.choice('abcdefgh') for _ in range(rng.randrange(0, 12)))
    nb = e.alloc(len(name) + 1 + 8, 4)
    e.wbytes(nb, name.encode() + b'\0' + rng.randbytes(8))
    obj = e.alloc(0x40, 4)
    e.wbytes(obj, rng.randbytes(0x40))
    e.w32(obj + 0xc, nb)
    return [obj, rng.getrandbits(32)]


def _index(c):
    e = c.emu
    rng = c.rng
    size = 0x40000
    this = e.alloc(size, 4)
    e.wbytes(this, rng.randbytes(size))
    a = rng.choice([rng.randrange(0, 0x100), rng.randrange(0x800, 0x900), rng.randrange(0, 0x40)])
    b = rng.randrange(0, 4)
    t = (a * 16 + (1 if a < 0x800 else 0xffff7801) + a) & 0xffffffff
    ptr = this + 4 * t
    if rng.random() < 0.7:
        obj = e.alloc(0x100, 4)
        e.wbytes(obj, bytes(0x100))
        for k in range(1, 0x40):
            e.w32(obj + 4 * k, rng.randrange(0, 0x100))
        e.w32(ptr + 0x3c, obj)
    else:
        e.w32(ptr + 0x3c, 0)
    return [this, a, b]


S(0x605380, 'checkName605380 (GUESS)', 'thiscall', None, ret='al', gen=_name, note='batch328; ret 4; helper 0x5f2d60 hooked')
S(0x6132f0, 'slotIndex6132f0 (GUESS)', 'thiscall', None, ret='eax', gen=_index, note='batch328; ret 8')
