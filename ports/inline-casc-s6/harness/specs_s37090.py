"""specs_s37090.py - cascade s6 batch 37090 (0x63e680, thiscall(a) ret 4, returns bool). Entry list with offsets relative to a base (engine object +0x1aa3 -> +0x20), entries
with active word, 0x800000 mark, kind word and +0x1c value; occasionally 258 qualifying entries to hit the 0x100 limit. this slot 0x20 (alloc: returns a spec buffer or 0), slot 0x58;
0x4db9a0 / 0x658d50 hooks; 0x634d22 / 0x634d10 really copy / fill."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g63e680(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    so = sysobj(c)
    Z = rnd(c, 0x40)
    base = e.alloc(0x40 * 270 + 0x80, 4)
    _w(c, Z + 0x20, base)
    _w(c, so + 0x1aa3, Z)
    big = r.random() < 0.06
    cnt = 258 if big else r.choice([0, 0, 1, 2, 3, 5, 8])
    offs = [0x40 * (i + 1) for i in range(cnt)]
    for i, o in enumerate(offs):
        nd = base + o
        e.wbytes(nd, bytes(r.getrandbits(8) for _ in range(0x30)))
        _w(c, nd + 8, offs[i + 1] if i + 1 < cnt else 0)
        if big:
            _w(c, nd + 0xe, 1, 2)
            _w(c, nd + 0x20, 0)
            _w(c, nd + 2, r.choice([0, 1, 3, 4]), 2)
        else:
            _w(c, nd + 0xe, r.choice([0, 1, 5, 0x100]), 2)
            _w(c, nd + 0x20, r.choice([0, 0x800000, 0x1, 0x7fffff, 0xff800000]))
            _w(c, nd + 2, r.choice([0, 1, 2, 3, 4, 5, 0x10001]) & 0xffff, 2)
        _w(c, nd + 0x1c, r.choice([0, 0, 7]))
    L = rnd(c, 0x80)
    _w(c, L + 0x6c, offs[0] if offs else 0)
    X = obj(c, 0x40, {0x2fc: pystub(c, 0, this=True, ret=lambda em, k: r.choice([0, 1, 0x100]))})
    _w(c, X + 0x20, r.choice([0, 0, 5, 0x1ff]))
    _w(c, L + 0x54, X)
    a = rnd(c, 0x60)
    _w(c, a + 0x38, L)
    pool = [e.alloc(0x900, 4) for _ in range(6)]
    for p in pool:
        e.wbytes(p, bytes(r.getrandbits(8) for _ in range(0x900)))
    this = obj(c, 0x40, {0x20: pystub(c, 1, this=True, ret=lambda em, k: pool[k % 6] if r.random() < 0.85 else 0),
                         0x58: pystub(c, 2, this=True)})

    def cp(em, k):
        d, s_, m = em.arg32(0), em.arg32(1), em.arg32(2)
        if m:
            em.wbytes(d, em.rbytes(s_, m))

    def ms(em, k):
        d, v, m = em.arg32(0), em.arg32(1), em.arg32(2)
        if m:
            em.wbytes(d, bytes([v & 0xff]) * m)
    hook_rec(c, 0x634d22, 3, pop=0, stackmark=(1,), side=cp)
    hook_rec(c, 0x634d10, 3, pop=0, side=ms)
    hook_rec(c, 0x4db9a0, 1, this=True, ret=lambda em, k: r.choice([0, 1, 1, 0x100, 0x101]))
    hook_rec(c, 0x658d50, 0, this=True, ret=lambda em, k: r.choice([0, 1, 8, 0x20, 0x100]))
    return [this, a]


S(0x63e680, 'GUESS collect_entries', 'thiscall', None, ret='al', gen=_g63e680, note='batch37090')
