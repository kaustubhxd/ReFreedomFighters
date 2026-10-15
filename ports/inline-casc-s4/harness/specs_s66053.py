"""specs_s66053.py - cascade s4 batch 66053: 0x5ffc10 (find a named entry in a packed string-indexed table)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, logger


def _g5ffc10(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    logger(c, 3)

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    e._image_dirty = True

    def sc(em, res):
        a = bytes(em.rbytes(em.arg32(0), 8)).split(b'\0')[0].lower()
        b = bytes(em.rbytes(em.arg32(1), 8)).split(b'\0')[0].lower()
        em.calllog.append(('cmp', a, b))
        em.ret(eax=0 if a == b else (1 if a > b else 0xffffffff), argbytes=0)
    e.stub_import('_stricmp', sc)
    words = [b'abc', b'ABC', b'xyz', b'q', b'']
    pool = e.alloc(0x100, 4)
    offs = {}
    pos = 0
    for w in words:
        offs[w] = pos
        e.wbytes(pool + pos, w + b'\0')
        pos += len(w) + 1
    name = e.alloc(0x10, 4)
    nm = r.choice(words)
    e.wbytes(name, nm + b'\0')
    cnt = r.choice([0, 1, 2, 3])
    base = r.choice([0, 3, 10])
    idxs = [r.choice([1, 3, 5, 12, 14, 20]) for _ in range(cnt)]
    idxarr = e.alloc(0x20, 4)
    valarr = e.alloc(0x20, 4)
    for i in range(cnt):
        e.wbytes(idxarr + 2 * i, idxs[i].to_bytes(2, 'little'))
        e.w32(valarr + 4 * i, 0x1000 + i)
    n8 = r.choice([0, 3, 8])
    offtab = e.alloc(0x40, 4)
    for j in range(8):
        e.w32(offtab + 4 * j, offs[r.choice(words)])

    def s5ffb00(em, rr):
        em.calllog.append(('fb', em.arg32(0)))
        em.ret(eax=pool + offs[words[em.arg32(0) % len(words)]], argbytes=4)
    cx = e.alloc(0x20, 4)
    ctx = e.alloc(0xc0, 8)
    e.wbytes(ctx, bytes(r.getrandbits(8) for _ in range(0xc0)))
    e.w32(ctx + 0xa0, base)
    e.w32(ctx + 0xa8, n8)
    e.w32(ctx + 0xac, offtab)
    e.w32(ctx + 0xb0, pool)
    e.w32(ctx + 0x9c, r.choice([0, cx]))
    e.hook(0x5ffb00, s5ffb00)
    t = e.alloc(0x20, 8)
    e.wbytes(t + 4, cnt.to_bytes(2, 'little'))
    e.w32(t + 6, idxarr)
    e.w32(t + 0xa, valarr)
    e.w32(t + 0xe, ctx)
    return [t, name]


S(0x5ffc10, 'GUESS find a named entry in a packed table', 'thiscall', None, ret='eax', gen=_g5ffc10, note='batch66053')
