"""specs_s66065.py - cascade s4 batch 66065: 0x569ca0 (copy an object's settings, duplicating its two strings)."""
from pilot import S
from recruits_util import clear_hooks


def _g569ca0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def alloc(em, rr):
        em.calllog.append(('alloc', em.arg32(0)))
        em.ret(eax=e.alloc(max(em.arg32(0), 8), 8), argbytes=0)
    e.hook(0x41e290, alloc)
    s = e.alloc(0x200, 8)
    e.wbytes(s, bytes(r.getrandbits(8) for _ in range(0x200)))
    t = e.alloc(0x200, 8)
    e.wbytes(t, bytes(r.getrandbits(8) for _ in range(0x200)))
    for off in (0x1bd, 0x1c1):
        if r.random() < 0.7:
            st = e.alloc(0x20, 8)
            e.wbytes(st, bytes(r.randrange(1, 255) for _ in range(r.choice([0, 1, 5, 11]))) + b'\0')
            e.w32(s + off, st)
        else:
            e.w32(s + off, 0)
    return [t, s]


S(0x569ca0, 'GUESS copy an object settings and duplicate its strings', 'thiscall', None, ret=None, gen=_g569ca0, note='batch66065')
