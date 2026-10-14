"""specs_s37042.py - cascade s6 batch 37042: 0x4d79d0. Stream at this+0x15 slot 0x18 (write: 3 args, returns the byte count or a short one); logger at 0x700390 slot 0x34
(cdecl, 2 args, fn from the vtable); zlib calls (0x62f120 / 0x62ebc0 / 0x62ee40) hooked on the caller's z_stream (deflate writes random bytes, returns 1 after a few calls);
hdr/data are spec blocks."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g4d79d0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))

    def lg(em, res_):
        em.calllog.append(('log', em.arg32(1)))
        em.ret(eax=0, argbytes=0)
    e.w32(0x700390, obj(c, 0x40, {0x34: e.stub_fn('log', lg)}))
    ln = r.choice([0, 1, 5, 40, 200])
    data = rnd(c, ln + 8)
    hdr = rnd(c, 0x30)
    e.wbytes(hdr + 6, (r.choice([0, 0, 8, 8, 8, 5])).to_bytes(2, 'little'))
    e.w32(hdr + 0x14, ln)
    e.w32(hdr + 0x10, r.getrandbits(16))
    fail = r.random() < 0.08
    ncalls = r.choice([1, 1, 2, 3])

    def init_side(em, k):
        z = em.arg32(0)
        em.calllog.append(('z', em.r32(z), em.r32(z + 4), em.r32(z + 0x20), em.r32(z + 0x24)))
    hook_rec(c, 0x62f120, 4, nullflag=(0,), pop=0x10, ret=(1 if fail else 0), side=init_side)

    def defl(em, k):
        z = em.arg32(0)
        nxt, avail = em.r32(z + 0xc), em.r32(z + 0x10)
        n = r.choice([2, 3, 6, 15, 60, 200]) if k == 0 else r.choice([0, 1, 5, 30])
        n = min(n, avail)
        em.wbytes(nxt, bytes(r.getrandbits(8) for _ in range(n)))
        em.w32(z + 0x10, avail - n)
        em.calllog.append(('defl', em.r32(z), em.r32(z + 4), em.arg32(1)))
    hook_rec(c, 0x62ebc0, 2, nullflag=(0,), pop=8, side=defl, ret=lambda em, k: 1 if k >= ncalls - 1 else 0)
    hook_rec(c, 0x62ee40, 1, nullflag=(0,), pop=4)
    written = []

    def wr(em, k):
        n = em.arg32(1)
        em.calllog.append(('wr', n, bytes(em.rbytes(em.arg32(0), min(n, 16)))))
        return n if r.random() > 0.15 else max(n - 1, 0)
    stream = obj(c, 0x40, {0x18: pystub(c, 3, this=True, stackmark=(0,), ret=wr)})
    me = rnd(c, 0x80)
    e.w32(me + 0x15, stream)
    e.w32(me + 0x11, r.getrandbits(32))
    e.w32(me + 0x1d, r.choice([1, 6, 9]))
    e.wbytes(me + 0x6e, bytes([0]))
    return [me, hdr, data]


S(0x4d79d0, 'GUESS write entry stored or deflated', 'thiscall', None, ret=None, gen=_g4d79d0, note='batch37042')
