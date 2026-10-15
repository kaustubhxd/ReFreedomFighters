"""specs_s67570.py - cascade s6 batch 67570 (0x6000b0, thiscall(key) ret 4, returns eax). Objects chain through this[0x9c] (up to 3 levels, each with its own table: this[0xa8] entries at +0xac, offset
base +0xb0, id base +0xa0; and this[0xc4] (id, value) word pairs at +0xc8); the compare function at 0x676414 is a cdecl recorder answering from a random sequence (zero sometimes); 0x5fefb0 / 0x5ffb00 /
0x5ffe20 are hooks; the logger at 0x700390 and the assert hook 0x7003b0 are set; the flag byte 0x724690 varies."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g6000b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))

    def lg2c(em, res_):
        em.calllog.append(('log', em.arg32(1), em.arg32(2)))
        em.ret(eax=0, argbytes=0)
    from recruits_util import pystub
    x = obj(c, 0x20, {0x2c: e.stub_fn('recorder', lg2c)})
    e.w32(0x700390, obj(c, 0x20, {0x20: pystub(c, 2, this=True, ret=x)}))

    def cmpf(em, res_):
        em.calllog.append(('cmp', em.arg32(0), em.arg32(1)))
        em.ret(eax=r.choice([0, 1, 1, 1, 5]), argbytes=0)
    e.w32(0x676414, e.stub_fn('recorder', cmpf))
    e.wbytes(0x724690, bytes([r.choice([0, 1])]))
    hook_rec(c, 0x5fefb0, 0, this=True)
    hook_rec(c, 0x5ffb00, 1, this=True, ret=lambda em, k: 0x6000 + 16 * k)
    hook_rec(c, 0x5ffe20, 1, this=True, ret=lambda em, k: r.getrandbits(32))

    def mk(depth):
        o = rnd(c, 0x100)
        base = r.choice([0, 0x10, 0x20])
        n_tab = r.choice([0, 1, 2, 3])
        tab = e.alloc(16, 4)
        for i in range(4):
            e.w32(tab + 4 * i, r.getrandbits(16))
        cnt = r.choice([0, 1, 2, 3])
        arr = e.alloc(4 * 4 + 4, 4)
        e.wbytes(arr, bytes(20))
        for i in range(cnt):
            idv = base + r.choice([0, 1, 2, 3, 4, 0x1f, 0xffff - 1]) if r.random() < 0.8 else r.randrange(0, base + 1)
            _w(c, arr + 4 * i, idv & 0xffff, 2)
            _w(c, arr + 4 * i + 2, r.getrandbits(16), 2)
        _w(c, o + 0xa0, base)
        _w(c, o + 0xa8, n_tab)
        _w(c, o + 0xac, tab)
        _w(c, o + 0xb0, r.getrandbits(32))
        _w(c, o + 0xc4, cnt)
        _w(c, o + 0xc8, arr)
        _w(c, o + 0x9c, mk(depth + 1) if depth < 2 and r.random() < 0.6 else 0)
        return o
    t = mk(0)
    return [t, r.getrandbits(32)]


S(0x6000b0, 'GUESS lookup_id_chain', 'thiscall', None, ret='eax', gen=_g6000b0, note='batch67570')
