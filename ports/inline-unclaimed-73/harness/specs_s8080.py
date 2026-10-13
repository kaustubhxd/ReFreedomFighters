"""specs_s8080.py - residue 6 batch 80 (GUESS name). FUN_5f2d60 (thiscall, two stack arguments a, b; ret 8). n = b - a; cap = [this+4] - [this].
If n <= cap (unsigned): 0x634d22([this], a, n) (cdecl, hooked and logged); edi = [this] + n; ebx = [this+4]; when edi != ebx:
memmove(edi, ebx, 1) through the IAT 0x676278 (stubbed, copies the byte) and [this+4] += edi - ebx.
Else: 0x634d22([this], a, cap); 0x5f2c60(this, [this+4] - [this] + a, b) (thiscall, two arguments, hooked and logged).
Returns this."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    e = c.emu

    def cdecl3(name):
        def h(em, r):
            em.calllog.append((name, 0, None, tuple(em.arg32(i) for i in range(3))))
            em.ret(eax=0, argbytes=0)
        return h

    def h_5f2c60(em, r):
        em.calllog.append(('5f2c60', 0, em.reg('ecx'), (em.arg32(0), em.arg32(1))))
        em.ret(eax=0, argbytes=8)

    def mm(em, r):
        d, s_, n = em.arg32(0), em.arg32(1), em.arg32(2)
        if n:
            em.wbytes(d, em.rbytes(s_, n))
        em.ret(eax=d, argbytes=0)
    e.hook(0x634d22, cdecl3('634d22'))
    e.hook(0x5f2c60, h_5f2c60)
    e.stub_import('memmove', mm)

    self_o = _rnd(c, 0x40)
    buf = _rnd(c, 0x100)
    lo = c.rng.randint(0, 0x20)
    hi = lo + c.rng.randint(0, 0x20)
    e.w32(self_o, buf + lo)
    e.w32(self_o + 4, buf + hi)
    a = buf + c.rng.randint(0, 0x30)
    b = a + c.rng.randint(0, 0x30)
    return [self_o, a & 0xffffffff, b & 0xffffffff]


S(0x5f2d60, 'GUESS FUN_005f2d60 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='residue 6 batch 80; n = b-a; n<=cap: 0x634d22(dst, a, n), edi=[this]+n, memmove(edi, ebx, 1) if edi!=ebx, [this+4]+=edi-ebx; else 0x634d22(dst,a,cap), 0x5f2c60(this, end, b)')
