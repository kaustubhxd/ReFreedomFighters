"""specs_s37085.py - cascade s6 batch 37085 (0x615860, thiscall(out, unused) ret 8, 64 KB stack matrix). Circular node list under this+8; slot 0x28 returns the element count n;
elements are 0x30 bytes from node+0x10 with a forward-only chain index in their first word; the memset thunk 0x634d10 is a hook (its stack address is recorded as a marker)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g615860(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))

    def ms(em, k):
        d, v, m = em.arg32(0), em.arg32(1), em.arg32(2)
        if m:
            em.wbytes(d, bytes([v & 0xff]) * m)
        em.calllog.append(('memset', v, m))
    hook_rec(c, 0x634d10, 3, pop=0, stackmark=(0,), side=ms)
    n = r.choice([0, 1, 2, 3, 5, 8])
    k = r.choice([0, 1, 1, 2, 3, 4, 6])
    nodes = [e.alloc(0x10 + 0x30 * max(n, 1) + 8, 4) for _ in range(k)]
    for nd in nodes:
        e.wbytes(nd, bytes(r.getrandbits(8) for _ in range(0x10 + 0x30 * max(n, 1) + 8)))
    for i, nd in enumerate(nodes):
        _w(c, nd + 8, nodes[(i + 1) % k] if (k and r.random() < 0.97) else 0)
        if n and r.random() < 0.8:
            _w(c, nd + 2, r.randrange(n), 2)
        else:
            _w(c, nd + 2, 0xffff, 2)
        for j in range(n):
            nxt = r.randrange(j + 1, n) if (j + 1 < n and r.random() < 0.6) else 0xffff
            _w(c, nd + 0x10 + 0x30 * j, nxt, 2)
    this = obj(c, 0x20, {0x28: pystub(c, 0, this=True, ret=n)})
    _w(c, this + 8, nodes[0] if nodes else 0)
    out = e.alloc(0x400, 4)
    e.wbytes(out, bytes(r.getrandbits(8) for _ in range(0x400)))
    return [this, out, r.getrandbits(32)]


S(0x615860, 'GUESS unreached_elements', 'thiscall', None, ret=None, gen=_g615860, note='batch37085')
