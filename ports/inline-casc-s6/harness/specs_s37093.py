"""specs_s37093.py - cascade s6 batch 37093 (0x603ef0, thiscall(a) ret 4). Hooked 0x5003d0 (first call returns the index node, second the destination node, sometimes the source
entry itself), logger at 0x700390 with a cdecl slot 0x2c, assert hook always set. Entries are 8-byte {value, kind} records with kinds 0..5; kind-4 and destination objects have
slots 0x24 (clone) and 0x28 (release)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g603ef0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))

    def lg(em, res_):
        em.calllog.append(('log', tuple(em.arg32(i) for i in range(3))))
        em.ret(eax=0, argbytes=0)
    Lg = obj(c, 0x20, {0x2c: e.stub_fn('log', lg)})
    e.w32(0x700390, obj(c, 0x20, {0x20: pystub(c, 2, this=True, ret=Lg)}))
    cnt = r.choice([1, 2, 3, 5])
    tbl = e.alloc(8 * 12, 4)
    e.wbytes(tbl, bytes(r.getrandbits(8) for _ in range(8 * 12)))

    def mkobj():
        return obj(c, 0x20, {0x24: pystub(c, 0, this=True, ret=lambda em, k: r.getrandbits(32)), 0x28: pystub(c, 0, this=True)})
    for i in range(12):
        kd = r.choice([0, 1, 2, 4, 4, 4, 3, 5, 0xff])
        _w(c, tbl + 8 * i + 4, kd, 1)
        _w(c, tbl + 8 * i, mkobj() if (kd == 4 or r.random() < 0.5) else r.getrandbits(32))
    this = rnd(c, 0x20)
    _w(c, this + 0xc, tbl)
    _w(c, this + 0x14, cnt)
    idx = r.randrange(0, cnt) if r.random() < 0.85 else r.randrange(cnt, cnt + 3)
    n0 = rnd(c, 0x10)
    _w(c, n0, idx)
    dst = rnd(c, 0x10)
    dk = r.choice([0, 0, 1, 4, 4, 2, 3])
    _w(c, dst, mkobj() if (dk == 4 or r.random() < 0.5) else r.getrandbits(32))
    _w(c, dst + 4, dk, 1)
    srcaddr = tbl + 8 * idx

    def nd(em, k):
        if k == 0:
            return n0
        return srcaddr if r.random() < 0.1 else dst
    hook_rec(c, 0x5003d0, 1, this=True, ret=nd)
    a = rnd(c, 0x10)
    _w(c, a + 4, rnd(c, 0x10))
    _w(c, a + 8, rnd(c, 0x10))
    return [this, a]


S(0x603ef0, 'GUESS copy_value_slot', 'thiscall', None, ret=None, gen=_g603ef0, note='batch37093')
