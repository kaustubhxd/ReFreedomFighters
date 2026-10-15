"""specs_s37119.py - cascade s6 batch 37119 (0x57d200, fastcall(str, out), returns eax). IAT 0x676254 (strchr) and 0x67640c (_strnicmp) are Python stubs with the real behaviour
(cdecl); the table at [engine+0x190b] has 16-byte group records (+0 base id, +8 pointer to 12-byte {name, ...} entries, zero-terminated) ending with a record whose +8 is 0.
Inputs are comma separated names in mixed case, unknown names, empty tokens and leading commas."""
from pilot import S
from recruits_util import rnd, sysobj, clear_hooks


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _cs(em, a, lim=0x200):
    out = bytearray()
    while len(out) < lim:
        b = em.rbytes(a + len(out), 1)[0]
        if b == 0:
            break
        out.append(b)
    return bytes(out)


def _g57d200(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def strchr(em, res_):
        s = em.arg32(0)
        ch = em.arg32(1) & 0xff
        d = _cs(em, s)
        i = d.find(bytes([ch]))
        em.ret(eax=(s + i) if i >= 0 else 0, argbytes=0)
    e.w32(0x676254, e.stub_fn('strchr', strchr))

    def strnicmp(em, res_):
        a, b, n = _cs(em, em.arg32(0)).lower()[:em.arg32(2)], _cs(em, em.arg32(1)).lower()[:em.arg32(2)], em.arg32(2)
        em.calllog.append(('strnicmp', a, b, n))
        em.ret(eax=0 if a == b else (1 if a > b else 0xffffffff), argbytes=0)
    e.w32(0x67640c, e.stub_fn('_strnicmp', strnicmp))
    so = sysobj(c)
    names_all = []
    ngroups = r.choice([0, 1, 2, 3])
    T = e.alloc(16 * (ngroups + 1) + 8, 4)
    e.wbytes(T, bytes(16 * (ngroups + 1) + 8))
    for g in range(ngroups):
        ne = r.choice([0, 1, 2, 3])
        arr = e.alloc(12 * (ne + 1) + 4, 4)
        e.wbytes(arr, bytes(12 * (ne + 1) + 4))
        for i in range(ne):
            nm = bytes(r.choice(b'abcAB') for _ in range(r.randint(1, 4)))
            a = e.alloc(len(nm) + 8, 1)
            e.wbytes(a, nm + b'\x00' + bytes(r.randrange(1, 255) for _ in range(7)))
            _w(c, arr + 12 * i, a)
            names_all.append(nm)
        _w(c, T + 16 * g, r.choice([0, 0x100, 0x200, 0x40]))
        _w(c, T + 16 * g + 8, arr)
    _w(c, so + 0x190b, T)
    toks = []
    for _ in range(r.choice([0, 1, 2, 3, 4, 5])):
        k = r.random()
        if names_all and k < 0.6:
            t = bytes(ch ^ 0x20 if (65 <= (ch | 0x20) <= 90 and r.random() < 0.5) else ch for ch in r.choice(names_all))
        elif k < 0.8:
            t = bytes(r.choice(b'abxy') for _ in range(r.randint(0, 3)))
        else:
            t = b''
        toks.append(t)
    s = b','.join(toks)
    a = e.alloc(len(s) + 8, 1)
    e.wbytes(a, s + b'\x00' + bytes(r.randrange(1, 255) for _ in range(7)))
    out = e.alloc(0x20, 4)
    e.wbytes(out, bytes(r.getrandbits(8) for _ in range(0x20)))
    return [a, out]


S(0x57d200, 'GUESS parse_name_list', 'fastcall', None, ret='eax', gen=_g57d200, note='batch37119')
