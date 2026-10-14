"""specs_s37104.py - cascade s6 batch 37104 (0x4dbbe0, thiscall(stream) ret 4, returns bool). The stream's slot 0x18 (dst, size) is a recorder whose side effect writes scripted
values into stack destinations (the flags dword, the 16-bit index) and random bytes into heap destinations; the table's sub-object (+8 of the table object) has slots 0x5c / 0x4c
(base of 0x70-byte entries); the bound object at +0x54 has slot 0x14; 0x4dc9c0 / 0x4dc630 are recording hooks."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g4dbbe0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    flags = r.choice([0, 0x100000, 0x40000, 0x140000, 0x40000000, 0x1000, r.getrandbits(32)])
    word = r.choice([0xffff, 0, 1, 2, 3, 0xffff])

    def rdside(em, k):
        d, n = em.arg32(0), em.arg32(1)
        em.calllog.append(('rd', d if 0x20000000 <= d < 0x30000000 else 1, n))
        if 0x20000000 <= d < 0x30000000:
            em.wbytes(d, bytes(r.getrandbits(8) for _ in range(n)))
        elif n == 4:
            em.w32(d, flags)
        elif n == 2:
            em.wbytes(d, word.to_bytes(2, 'little'))
    stream = obj(c, 0x20, {0x18: pystub(c, 2, this=True, stackmark=(0,), side=rdside)})
    base = e.alloc(0x70 * 5, 4)
    e.wbytes(base, bytes(r.getrandbits(8) for _ in range(0x70 * 5)))
    sub = obj(c, 0x20, {0x5c: pystub(c, 1, this=True), 0x4c: pystub(c, 0, this=True, ret=base)})
    so = sysobj(c, table_size=0x20)
    tab = int.from_bytes(e.rbytes(so + 0x9b, 4), 'little')
    _w(c, tab + 8, sub)
    hook_rec(c, 0x4dc9c0, 1, this=True)
    hook_rec(c, 0x4dc630, 2, this=True)
    t = rnd(c, 0x80)
    _w(c, t + 0x5c, r.choice([0, 0, 5, 0x1234]), 2)
    if r.random() < 0.6:
        bo = obj(c, 0x20, {0x14: pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, 1, 1, 0x100, 0x101]))})
        _w(c, t + 0x54, bo)
    else:
        _w(c, t + 0x54, 0)
    return [t, stream]


S(0x4dbbe0, 'GUESS load_from_stream', 'thiscall', None, ret='al', gen=_g4dbbe0, note='batch37104')
