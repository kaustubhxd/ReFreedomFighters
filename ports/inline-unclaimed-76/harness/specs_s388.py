"""specs_s388.py - area 76, residue 17, batch 388 (thiscall, one word, ret 4; GUESS), see batch388.cpp.
0x663250: this+0x121b4 holds a short string (0-40 characters); the argument is another short string (0-40 characters).
[0x700394] -> an object whose slot 0x5c (one word, returns a per-run value) logs the string it is given (the pointer itself is a
stack address, so only the contents are compared)."""
from pilot import S

_CH = b'abcdefghijklmnopqrstuvwxyz0123456789._-\\/'


def _s(rng):
    return bytes(rng.choice(_CH) for _ in range(rng.randrange(41)))


def _gen_6632(c):
    e = c.emu
    rng = c.rng
    rv = rng.getrandbits(32)

    def h5c(em, r):
        p = em.arg32(0)
        raw = em.rbytes(p, 0x84)
        em.calllog.append(('g', 0x5c, em.reg('ecx'), (raw.split(b'\0')[0],)))
        em.ret(eax=rv, argbytes=4)

    g = e.alloc(0x40, 4)
    e.w32(g, e.fake_vtable('g6632', 0x20, {0x5c: h5c}))
    e.w32(0x700394, g)
    this = e.alloc(0x12200, 4)
    e.wbytes(this + 0x121b4, _s(rng) + b'\0' + rng.randbytes(8))
    arg = e.alloc(0x40, 4)
    e.wbytes(arg, _s(rng) + b'\0')
    return [this, arg]


S(0x663250, 'path663250 (GUESS)', 'thiscall', None, ret='eax', gen=_gen_6632, note='area 76 batch 388; residue 17; /GS cookie')
