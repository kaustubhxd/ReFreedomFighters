"""specs_s36080.py - cascade s4 batch 36080: 0x604f50 (copy a name string into a growing buffer and bind a tagged record)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g604f50(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def mkstr(n):
        a = e.alloc(0x40, 4)
        e.wbytes(a, bytes(r.randrange(1, 256) for _ in range(n)) + b'\0')
        return a

    def mkrec(n):
        sp = mkstr(n)
        rec = e.alloc(8, 4)
        e.w32(rec, sp)
        return rec
    lens = [0, 1, 2, 4, 9, 20]
    recs = [mkrec(r.choice(lens)) for _ in range(4)]
    p4 = rnd(c, 0x10)
    p8 = rnd(c, 0x10)
    r8 = e.alloc(8, 4)
    tag = r.choice([0, 0, 4, 4, 4, 1, 7])
    e.w32(r8, obj(c, 0x30, {0x28: pystub(c, 0, this=True)}) if tag == 4 else rnd(c, 8))
    e.wbytes(r8 + 4, bytes([tag]) + b'\0\0\0')

    def sel(em, k):
        return r8 if em.reg('ecx') == p8 else recs[min(k, 3)]
    hook_rec(c, 0x5003d0, 1, this=True, ret=sel)
    hook_rec(c, 0x634273, 2, pop=0)
    hook_rec(c, 0x41e290, 1, pop=0, ret=lambda em, k: e.alloc(0x40, 4))
    d = obj(c, 0x20, {0x24: pystub(c, 0, this=True, ret=r.getrandbits(32))})
    e.w32(d + 0xc, e.alloc(0x40, 4))
    e.wbytes(d + 0x10, (r.choice([0, 1, 2, 3, 5, 10, 21, 0xffff])).to_bytes(2, 'little'))
    pp = e.alloc(0x10, 4)
    e.w32(pp + 4, p4)
    e.w32(pp + 8, p8)
    return [d, pp]


S(0x604f50, 'GUESS copy a name into a growing buffer and bind a tagged record', 'thiscall', None, ret=None, gen=_g604f50, note='batch36080')
