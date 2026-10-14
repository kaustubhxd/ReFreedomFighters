"""specs_s38039.py - cascade s8 batch 38039. Input: a NUL-terminated string of 0..14 characters from {a, b, space, tab, CR, LF, quote}. The string object (vec: begin, end, cap end) is reset by the
0x5f2d60 hook to an empty buffer of 2..6 bytes (so both growth paths run); 0x431270 (reserve) reallocates to the requested capacity keeping the content, 0x6014a0 (allocate) returns a zeroed block, 0x54f870
(free) is logged. All hooks are logged with their arguments; the content of the final string is in the heap compare."""
from pilot import S
from recruits_util import rnd, clear_hooks


def _g42cce0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    alpha = [ord('a'), ord('b'), ord('a'), 0x20, 9, 0xd, 0xa, 0x22, 0x22, ord('c')]
    s = bytes(r.choice(alpha) for _ in range(r.randrange(0, 15)))
    if r.random() < 0.3:
        s = b'"' + bytes(r.choice(alpha) for _ in range(r.randrange(0, 10)))
    p = e.alloc(len(s) + 8, 1)
    e.wbytes(p, s + b'\0' + bytes(r.choice([ord('a'), 0x22, 0x20]) for _ in range(6)))
    cell = e.alloc(4, 4)
    e.w32(cell, p)
    vec = rnd(c, 0x10)
    cap0 = r.randrange(2, 7)

    def assign(em, res_):
        v = em.reg('ecx')
        em.calllog.append(('assign', em.arg32(0), em.arg32(1)))
        b = em.alloc(cap0 + 0x10, 4)
        em.wbytes(b, bytes(cap0 + 0x10))
        em.w32(v, b)
        em.w32(v + 4, b)
        em.w32(v + 8, b + cap0)
        em.ret(eax=0, argbytes=8)

    def reserve(em, res_):
        v = em.reg('ecx')
        n = em.arg32(0)
        em.calllog.append(('reserve', n))
        bg, en = em.r32(v), em.r32(v + 4)
        size = (en - bg) & 0xffffffff
        nb = em.alloc(n + 0x20, 4)
        em.wbytes(nb, bytes(n + 0x20))
        em.wbytes(nb, em.rbytes(bg, size + 1))
        em.w32(v, nb)
        em.w32(v + 4, nb + size)
        em.w32(v + 8, nb + n)
        em.ret(eax=0, argbytes=4)

    def alloc(em, res_):
        n = em.arg32(0)
        em.calllog.append(('alloc', em.reg('ecx'), n))
        p2 = em.alloc(n + 0x20, 4)
        em.wbytes(p2, bytes(n + 0x20))
        em.ret(eax=p2, argbytes=4)

    def free(em, res_):
        em.calllog.append(('free', em.reg('ecx'), em.arg32(0), em.arg32(1)))
        em.ret(eax=0, argbytes=8)
    e.hook(0x5f2d60, assign)
    e.hook(0x431270, reserve)
    e.hook(0x6014a0, alloc)
    e.hook(0x54f870, free)
    return [cell, vec]


S(0x42cce0, 'GUESS read quoted token into string', 'stdcall', None, ret=None, gen=_g42cce0, note='batch38039')
