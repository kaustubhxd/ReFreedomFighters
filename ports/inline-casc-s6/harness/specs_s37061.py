"""specs_s37061.py - cascade s6 batch 37061 (0x62f1e0, zlib fill_window). Window and hash tables are spec heap blocks; the checksum update 0x6316e0 is a recording hook, 0x634d22 a real
copy. States are built so the loop terminates: when more == 0 with data, strstart is at least the slide threshold."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g62f1e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def cp(em, k):
        d, s_, n = em.arg32(0), em.arg32(1), em.arg32(2)
        if n < 0x2000:
            em.wbytes(d, em.rbytes(s_, n))
    hook_rec(c, 0x634d22, 3, pop=0, side=cp)
    hook_rec(c, 0x6316e0, 3, pop=12, ret=lambda em, k: r.getrandbits(32))
    wsize = r.choice([0x200, 0x400])
    thr = 2 * wsize - 0x106
    ws = 2 * wsize
    look = r.choice([0, 1, 2, 3, 0x50, 0x105, 0x106, 0x120])
    mode = r.choice(['fresh', 'mid', 'slide', 'slide', 'full', 'zero', 'over', 'tight', 'tight', 'zl'])
    if mode == 'fresh':
        strstart, look = 0, 0
    elif mode == 'zero':
        strstart, look, ws = 0, 0, 0
    elif mode == 'zl':
        strstart, look = 0, r.choice([0x106, 0x120])
        ws = look
    elif mode == 'over':
        look = r.choice([0, 3, 0x20])
        strstart = ws + 1 - look
    elif mode == 'tight':
        strstart = r.randint(1, 100)
        look = 0x105
        ws = strstart + look + 1
    elif mode == 'mid':
        strstart = r.randint(1, thr - 1)
    elif mode == 'slide':
        strstart = r.randint(thr, ws - look) if ws - look >= thr else thr
    else:
        strstart = max(ws - look, 0)
    more = (ws - strstart - look) & 0xffffffff
    if more == 0 and strstart != 0 and strstart < thr:
        ws += 1
    window = e.alloc(4 * wsize + 0x800, 4)
    e.wbytes(window, bytes(r.getrandbits(8) for _ in range(min(4 * wsize, 0x400))))
    hsize = r.choice([0x20, 0x40])
    head = e.alloc(2 * hsize + 8, 2)
    prev = e.alloc(2 * wsize + 8, 2)
    for i in range(hsize):
        _w(c, head + 2 * i, r.choice([0, wsize - 1, wsize, wsize + 3, r.getrandbits(16)]), 2)
    for i in range(wsize):
        _w(c, prev + 2 * i, r.choice([0, wsize - 1, wsize, wsize + 3, r.getrandbits(16)]), 2)
    avail = r.choice([0, 1, 2, 3, 5, 0x100, 0x500, 0x1000])
    if mode == 'tight':
        avail = r.choice([2, 3, 5])
    nin = e.alloc(avail + 16, 4)
    e.wbytes(nin, bytes(r.getrandbits(8) for _ in range(avail + 16)))
    state = rnd(c, 0x40)
    _w(c, state + 0x18, r.choice([0, 0, 1, 2]))
    strm = rnd(c, 0x40)
    _w(c, strm, nin)
    _w(c, strm + 4, avail)
    _w(c, strm + 0x1c, state)
    s = rnd(c, 0x90)
    for off, v in ((0, strm), (0x24, wsize), (0x30, window), (0x34, ws), (0x38, prev), (0x3c, head), (0x44, hsize),
                   (0x4c, hsize - 1), (0x50, r.choice([0, 3, 5])), (0x54, r.randint(0, 3 * wsize)), (0x64, strstart),
                   (0x68, r.randint(0, 3 * wsize)), (0x6c, look)):
        _w(c, s + off, v)
    return [s]


S(0x62f1e0, 'GUESS zlib fill_window', 'cdecl', None, ret=None, gen=_g62f1e0, note='batch37061')
