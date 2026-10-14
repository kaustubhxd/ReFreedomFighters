"""specs_s37066.py - cascade s6 batch 37066 (0x407d80, record serialiser). The writer 0x410bf0 is a recording hook that logs every (value, nbytes) call into the call log, so the
full output sequence is compared. Counts are kept small so the arrays (0x404..0x484, up to 16 entries) stay inside the block; a0+4 is the list length."""
from pilot import S
from recruits_util import clear_hooks, hook_rec


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g407d80(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x410bf0, 3, pop=0, side=lambda em, k: em.calllog.append(('w', em.arg32(1), em.arg32(2))))
    a1 = e.alloc(0xa00, 4)
    e.wbytes(a1, bytes(r.getrandbits(8) for _ in range(0xa00)))
    n = r.choice([0, 1, 2, 3, 5, 16, 0x80000000, 0xffffffff])
    if n in (0x80000000, 0xffffffff):
        n = r.choice([0, 1, 2, 7, 16])
    m = r.choice([0, 1, 2, 3, 8, 0x100, 0xffffffff, 0x80000000])
    if m == 0x100:
        m = r.choice([5, 17, 30])
    _w(c, a1, n)
    _w(c, a1 + 0x4cc, m)
    a0 = e.alloc(0x10, 4)
    e.wbytes(a0, bytes(r.getrandbits(8) for _ in range(0x10)))
    ln = r.choice([0, 1, 2, 3, 4, 5, 8, 15, 16, 17, 31, 64, 100, 0x7fffffff, 0xffffffff, 0x80000000, 0x80000001])
    if ln & 0x80000000:
        ln = ln
    elif ln > 100:
        ln = r.choice([0, 3, 9])
    _w(c, a0 + 4, ln)
    w = e.alloc(0x40, 4)
    return [a0, a1, w]


S(0x407d80, 'GUESS serialise_record', 'cdecl', None, ret=None, gen=_g407d80, note='batch37066')
