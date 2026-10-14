"""specs_s37071.py - cascade s6 batch 37071 (0x57e040, thiscall(msg) ret 4). Engine object (sysobj) with +0x1907 -> block with +0x131c source pointer and +0x190b -> block with +0x10
(base 0, so the byte store lands inside the capture buffer); table object slots 0x4c / 0x58 are recording stubs; memcpy/memset thunks are hooks that really copy/fill."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g57e040(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    vals = [0, 0, 0x1234, 0x5678, r.getrandbits(32)]
    so = sysobj(c, table_slots={0x4c: pystub(c, 1, this=True, ret=lambda em, k: r.choice(vals)),
                                0x58: pystub(c, 1, this=True, ret=lambda em, k: r.choice(vals))}, table_size=0x60)
    n = r.choice([0, 1, 5, 6, 7, 12, 16])
    buf = e.alloc(0x40, 4)
    ref = e.alloc(0x40, 4)
    src = e.alloc(0x40, 4)
    e.wbytes(buf, bytes(r.getrandbits(8) for _ in range(0x40)))
    sb = bytes(0 if r.random() < 0.3 else r.getrandbits(8) for _ in range(0x40))
    e.wbytes(src, sb)
    e.wbytes(ref, bytes(b if r.random() < 0.6 else r.getrandbits(8) for b in sb))
    A = rnd(c, 0x140)
    _w(c, A + 0x131c, src)
    B = rnd(c, 0x40)
    _w(c, B + 0x10, 0)
    _w(c, so + 0x1907, A)
    _w(c, so + 0x190b, B)

    def cp(em, k):
        d, s_, m = em.arg32(0), em.arg32(1), em.arg32(2)
        if m:
            em.wbytes(d, em.rbytes(s_, m))

    def ms(em, k):
        d, v, m = em.arg32(0), em.arg32(1), em.arg32(2)
        if m:
            em.wbytes(d, bytes([v & 0xff]) * m)
    hook_rec(c, 0x634d22, 3, pop=0, side=cp)
    hook_rec(c, 0x634d10, 3, pop=0, side=ms)
    owner = obj(c, 0x20, {0x2f0: pystub(c, 0, this=True, ret=lambda em, k: r.choice(vals)),
                          0x2ec: pystub(c, 1, this=True)})
    t = obj(c, 0x380, {0x84: pystub(c, 0, this=True, ret=owner)})
    fl = r.random() < 0.55
    _w(c, t + 0x33c, r.choice([1, 5, 0x100]) if fl else 0)
    e.wbytes(t + 0x34a, bytes([1 if r.random() < 0.2 else 0]))
    e.wbytes(t + 0x349, bytes([r.getrandbits(1)]))
    _w(c, t + 0x338, n)
    _w(c, t + 0x330, buf)
    _w(c, t + 0x32c, ref)
    _w(c, t + 0x340, r.choice(vals))
    _w(c, t + 0x344, r.choice(vals))
    for off, slot, code in ((0x190, 4, pystub(c, 1, this=True)), (0x264, 0x2c, pystub(c, 1, this=True, ret=lambda em, k: r.getrandbits(1)))):
        vt = e.alloc(0x40, 4)
        _w(c, vt + slot, code)
        _w(c, t + off, vt)
    msg = r.choice([0x2710, 0x2711, 0x2712, 9, 9, 9, 0, 5, 0x2710, 0x2711])
    return [t, msg]


S(0x57e040, 'GUESS capture_message', 'thiscall', None, ret='al', gen=_g57e040, note='batch37071')
