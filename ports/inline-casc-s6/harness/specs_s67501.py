"""specs_s67501.py - cascade s6 batch 67501 (0x5c9330, thiscall(target) ret 4). Table slot 0x58 (A for +0x70, B for +0x74) and 0x4c; A's slot 0x2f4 gives the previous object (or
null / the target itself), objects answer slot 0x1e0 and have a slot-0x504 helper (null or an object with slot 0xbc); B's slot 0x84 writes a stack vector that 0x5c82a0 logs by content."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g5c9330(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def mkobj():
        helper = obj(c, 0x20, {0xbc: pystub(c, 1, this=True)}) if r.random() < 0.7 else 0
        return obj(c, 0x930, {0x1e0: pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, 1, 1, 0x100])), 0x504: pystub(c, 0, this=True, ret=helper)})
    target = mkobj() if r.random() < 0.85 else 0
    prev = r.choice([0, 0, target, mkobj(), mkobj()]) if target else r.choice([0, mkobj()])
    A = obj(c, 0x40, {0x2f4: pystub(c, 0, this=True, ret=prev), 0x2f0: pystub(c, 3, this=True), 0x2d0: pystub(c, 2, this=True)})
    B = obj(c, 0x40, {0x84: pystub(c, 1, this=True, stackmark=(0,), side=lambda em, k: em.calllog.append(('84', em.rbytes(em.arg32(0), 12))))})
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: A if k == 0 else B), 0x4c: pystub(c, 1, this=True, ret=lambda em, k: r.getrandbits(32))}, table_size=0x60)
    hook_rec(c, 0x5c82a0, 1, this=True, stackmark=(0,), side=lambda em, k: em.calllog.append(('82a0', em.rbytes(em.arg32(0), 12))))
    t = rnd(c, 0x90)
    _w(c, t + 0x70, r.getrandbits(32))
    _w(c, t + 0x74, r.getrandbits(32))
    _w(c, t + 0x80, r.choice([0, 0, 1]))
    _w(c, t + 0x88, r.getrandbits(32))
    return [t, target]


S(0x5c9330, 'GUESS retarget', 'thiscall', None, ret=None, gen=_g5c9330, note='batch67501')
