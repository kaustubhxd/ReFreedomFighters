"""specs_s37030.py - cascade s6 batch 37030: 0x4d5c50 (zip central directory scan). The stream at this+0x15 is a scripted Python object: slot 0x14 serves the next signature (4),
header (0x2a, name length at +0x18) or name chunk depending on the requested size, sometimes returning a short count; slot 0x1c reports end-of-stream once the signature
list is used up; slot 0xc returns record offsets (sometimes ones present in the table at this+0x66); the handler's slot 0x8c logs the name it gets."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g4d5c50(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))

    def lg(em, res_):
        em.calllog.append(('log', em.arg32(1)))
        em.ret(eax=0, argbytes=0)
    Lg = obj(c, 0x20, {0x2c: e.stub_fn('log', lg)})
    e.w32(0x700390, obj(c, 0x20, {0x20: pystub(c, 2, this=True, ret=Lg)}))
    nrec = r.choice([0, 1, 2, 3, 4])
    sigs = []
    for i in range(nrec):
        sigs.append(r.choice([0x2014b50, 0x2014b50, 0x2014b50, 0x2014b50, 0x6054b50, 0x52756e65, 0x12345678]))
    names = []
    hdrs = []
    offs = []
    known = [r.randrange(1, 0x1000) for _ in range(3)]
    for i in range(nrec):
        nm = bytes(r.choice(b'abcdefgh/._') for _ in range(r.choice([0, 1, 3, 9, 30])))
        names.append(nm)
        hb = bytearray(r.getrandbits(8) for _ in range(0x2a))
        ln = len(nm) if r.random() < 0.9 else r.choice([0, 2, 5])
        hb[0x18:0x1a] = ln.to_bytes(2, 'little')
        hdrs.append(bytes(hb))
        offs.append(r.choice(known + [r.randrange(0x2000, 0x3000)]))
    st = {'sig': 0, 'hdr': 0, 'name': 0, 'tell': 0}

    def read(em, k):
        buf, n = em.arg32(0), em.arg32(1)
        if n == 4:
            i = st['sig']
            st['sig'] += 1
            data = sigs[i].to_bytes(4, 'little') if i < len(sigs) else bytes(4)
            em.wbytes(buf, data)
            return 4 if r.random() > 0.05 else 3
        if n == 0x2a:
            i = st['hdr']
            st['hdr'] += 1
            em.wbytes(buf, hdrs[i] if i < len(hdrs) else bytes(0x2a))
            return 0x2a if r.random() > 0.05 else 0x29
        i = st['name']
        st['name'] += 1
        data = (names[i] if i < len(names) else b'')[:n].ljust(n, b'x')
        em.wbytes(buf, data)
        return n if r.random() > 0.05 else n - 1

    def eof(em, k):
        return 1 if st['sig'] >= len(sigs) else 0

    def tell(em, k):
        i = st['hdr']
        return offs[i] if i < len(offs) else 0
    handler = obj(c, 0x100, {0x8c: pystub(c, 1, this=True, nullflag=(0,),
                                            side=lambda em, k: em.calllog.append(('name', bytes(_cstr(em, em.arg32(0))))))})
    stream = obj(c, 0x40, {0x10: pystub(c, 3, this=True),
                           0x1c: pystub(c, 1, this=True, ret=eof),
                           0x14: pystub(c, 3, this=True, nullflag=(0,), ret=read),
                           0xc: pystub(c, 1, this=True, ret=tell)})
    me = rnd(c, 0x80)
    e.w32(me + 0x15, stream)
    e.w32(me + 0x11, r.getrandbits(32))
    e.w32(me + 0x3c, r.choice([0, 1]))
    arr = e.alloc(0x40, 4)
    for i, v in enumerate(known):
        e.w32(arr + 4 * i, v)
    e.w32(me + 0x66, arr)
    e.w32(me + 0x62, r.choice([0, 1, 2, 3]))
    return [me, handler]


def _cstr(em, p):
    out = b''
    while len(out) < 80:
        b = em.rbytes(p, 1)
        if b == b'\0':
            break
        out += b
        p += 1
    return out


S(0x4d5c50, 'GUESS zip central directory scan', 'thiscall', None, ret=None, gen=_g4d5c50, note='batch37030')
