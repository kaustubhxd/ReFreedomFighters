"""specs_s1013.py - unclaimed-07 batch 13 (slice 6): ZInputAction::DependOnActionsNodes (0x4386a0).
The string is a random heap string over an alphabet of '0', '+', ' ', 'a', 'b' (sometimes null, sometimes empty).
Operator new (0x41e290) is hooked to a fresh non-zero buffer; operator delete (0x634273) and the per-token helper
(0x4385e0, thiscall, token and flag) are hooked to logging stubs, so the token order and contents are compared."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _depend(c):
    e = c.emu
    self_o = _rnd(c, 0x200)
    flag = c.rng.choice([0, 1, c.rng.getrandbits(32)])
    pattern = bytes(c.rng.getrandbits(8) | 1 for _ in range(0x100))

    def new(em, r):
        n = em.arg32(0)
        em.calllog.append(('new', 0, None, (n,)))
        p = em.alloc(n + 16, 4)
        em.wbytes(p, pattern[:n + 16])
        em.ret(eax=p)

    def delete(em, r):
        em.calllog.append(('delete', 0, None, (em.arg32(0), em.arg32(1))))
        em.ret(argbytes=0)

    def token(em, r):
        em.calllog.append(('token', 0, em.reg('ecx'), (em.arg32(0), em.arg32(1))))
        em.ret(argbytes=8)

    e.hook(0x41e290, new)
    e.hook(0x634273, delete)
    e.hook(0x4385e0, token)

    if c.rng.random() < 0.05:
        s = 0
    else:
        n = c.rng.randint(0, 14)
        text = bytes(c.rng.choice(b'0+ ab') for _ in range(n)) + b'\x00'
        s = _rnd(c, len(text) + 4)
        e.wbytes(s, text)
    return [self_o, s, flag]


S(0x4386a0, 'ZInputAction::DependOnActionsNodes (unknown) thiscall', 'thiscall', None, ret=None, gen=_depend,
  note='unclaimed-07 batch 13; token split on +, spaces trimmed; 0x4385e0 per token; new/delete hooked')
