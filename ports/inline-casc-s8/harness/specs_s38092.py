"""specs_s38092.py - cascade s8 batch 38092. thiscall(id, mode, src, n) ret 0x10. The object's slot 0xc (logging stub) resolves id -> buffer descriptor B (word +2 nonzero 10%, word +0xe * dword +0x50 = capacity,
usually >= n, sometimes smaller: assert hook) and B[0x14] -> the vertex array (random bytes, 0x24 bytes per vertex, 12 vertices of room). mode 1 / 2 / 4 / other (0, 3, 5), n 0..10, src random dwords."""
import struct
from pilot import S
from recruits_util import rnd, clear_hooks


def _g6579a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))
    n = r.randrange(0, 11)
    key = r.getrandbits(32) | 1
    ident = r.getrandbits(32) | 2
    B = rnd(c, 0x60)
    e.wbytes(B + 2, struct.pack('<H', 0 if r.random() > 0.1 else r.choice([1, 0x100])))
    cap_n = r.choice([n, n + 3, max(n - 1, 0), 100])
    e.wbytes(B + 0xe, struct.pack('<H', 1))
    e.w32(B + 0x50, cap_n)
    e.w32(B + 0x14, key)
    V = rnd(c, 0x24 * 12 + 64)

    def s0c(em, res_):
        a = em.arg32(0)
        em.calllog.append(('s0c', a))
        em.ret(eax=(B if a == ident else V), argbytes=4)
    from recruits_util import obj
    this = obj(c, 0x40, {0xc: e.stub_fn('s0c', s0c)})
    src = rnd(c, 12 * 12 + 16)
    return [this, ident, r.choice([1, 2, 4, 0, 3, 5, 1, 2, 4]), src, n]


S(0x6579a0, 'GUESS fill vertex attribute', 'thiscall', None, ret=None, gen=_g6579a0, note='batch38092')
