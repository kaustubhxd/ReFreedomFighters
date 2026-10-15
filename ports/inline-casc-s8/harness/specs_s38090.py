"""specs_s38090.py - cascade s8 batch 38090 (Vorbis codebook unpack). cdecl(bs, book) -> 0 / -1. book = 0x40-byte random block (zeroed by the function). The bit reader 0x410de0 is a scripted Python hook: the first call returns the magic 0x564342
(85%), then dim, entries (0..6, -1 sometimes), the ordered flag (0 / 1 / rarely 2), length fields (5 bits: 0..30, -1 sometimes), ilog-width fields (>= 1, so the ordered loop terminates, -1 sometimes), map type (0 / 1 / 2 / 3), 32-bit
values, value fields (-1 sometimes: error path). 0x405090 (ilog) is the real exe code; 0x634d58 (malloc) returns a heap buffer and logs the size; 0x4053f0 (quantvals) returns 0..5; 0x4055a0 (clear) logs the book contents."""
from pilot import S
from recruits_util import rnd, clear_hooks


def _g405ca0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    st = {'n': 0, 'ent': 0, 'n32': 0, 'after': 0}

    def bits(em, res_):
        bs, nb = em.arg32(0), em.arg32(1)
        i = st['n']
        st['n'] += 1
        if st['n32'] >= 2:
            st['after'] += 1
        if st['n32'] >= 2 and st['after'] > 2:   # the value reads of the lookup table: -1 often (error path of the last value)
            v = 0xffffffff if r.random() < 0.3 else r.getrandbits(4)
        elif i == 0:
            v = 0x564342 if r.random() < 0.85 else r.getrandbits(24)
        elif i == 1:
            v = r.choice([0, 1, 1, 2, 4])
        elif i == 2:
            v = 0xffffffff if r.random() < 0.05 else r.choice([0, 1, 2, 3, 4, 6])
            st['ent'] = v
        elif i == 3:
            v = r.choice([0, 0, 1, 1, 2]) if r.random() > 0.05 else 0xffffffff
        elif nb == 5:
            v = 0xffffffff if r.random() < 0.05 else r.randrange(0, 31)
        elif nb == 1:
            v = r.getrandbits(1)
        elif nb == 4:
            v = r.choice([0, 1, 1, 2, 2, 3, 0xffffffff])
        elif nb == 0x20:
            v = r.getrandbits(32)
            st['n32'] += 1
        elif nb < 8 and nb > 0 and nb != 5:
            v = 0xffffffff if r.random() < 0.1 else r.choice([1, 2, 3, 7])   # ilog widths / small value fields
        else:
            v = 0xffffffff if r.random() < 0.05 else r.getrandbits(8)
        em.calllog.append(('bits', em.arg32(0) != 0, nb, v))
        em.ret(eax=v, argbytes=0)
    e.hook(0x410de0, bits)

    def mal(em, res_):
        n = em.arg32(0)
        em.calllog.append(('malloc', n))
        em.ret(eax=e.alloc(max(n, 16), 4), argbytes=0)
    e.hook(0x634d58, mal)
    e.hook(0x4053f0, lambda em, res_: (em.calllog.append(('4053f0', bytes(em.rbytes(em.arg32(0), 0x34)))), em.ret(eax=r.choice([0, 1, 1, 2, 3, 5]), argbytes=0)))
    e.hook(0x4055a0, lambda em, res_: (em.calllog.append(('4055a0', bytes(em.rbytes(em.arg32(0), 0x34)))), em.ret(eax=0, argbytes=0)))
    bs = rnd(c, 0x40)
    book = rnd(c, 0x40)
    return [bs, book]


S(0x405ca0, 'GUESS vorbis codebook unpack', 'cdecl', None, ret='eax', gen=_g405ca0, note='batch38090')
