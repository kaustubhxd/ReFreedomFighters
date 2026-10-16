"""specs_s0604.py - fresh-06 batch 4 (docs/20-fresh-06.md). memset/memcpy (VCRUNTIME imports, no pe_emu stub) are
done by logging hooks; stack buffers handed to callees are logged by content (whole buffer) by the receiving stub."""
from pilot import S
from helpers06 import rnd, hk, vt, cvt, obj, seq, rv, eng, logger, handler, zero


def mem_hooks(c):
    def ms(e, a):
        e.wbytes(a[0], bytes([a[1] & 0xff]) * a[2])
        return a[0]

    def mc(e, a):
        e.wbytes(a[0], e.rbytes(a[1], a[2]))
        return a[0]
    hk(c, 0x634d10, 3, pop=0, fn=ms)
    hk(c, 0x634d22, 3, pop=0, fn=mc)


def _scrt(c):
    c.emu.wbytes(0x7254b0, bytes([c.rng.choice([0, 1, 0x80])]))
    hk(c, 0x549de0, 1, pop=0)
    return [c.rng.getrandbits(32), c.rng.choice([0, 1, 0x100, 0x1ff, c.rng.getrandbits(32)])]


def _recycle(c):
    hk(c, 0x5fd240, 1, ecx=True, ret=c.rng.choice([0, 1, 0x100, 0xff]))
    host = obj(c, 0x10, vt(c, 'host', {0x24: (1, 0)}))
    c.emu.w32(0x724270, host)
    hk(c, 0x5fd2a0, 1, ecx=True)
    hk(c, 0x5f3b00, 0, ecx=True)
    hk(c, 0x634273, 2, pop=0)
    return [rnd(c, 0x40), c.rng.choice([0, rnd(c, 0x10)])]


def _matpos(c):
    hk(c, 0x610100, 1, ecx=True)
    m = bytes(c.rng.getrandbits(8) for _ in range(0x24))
    p = bytes(c.rng.getrandbits(8) for _ in range(12))

    def gmp(e, a, m=m, p=p):
        e.wbytes(a[0], m)
        e.wbytes(a[1], p)
    hk(c, 0x4db2c0, 2, ecx=True, fn=gmp)

    def s12c(e, a):
        e.calllog.append(('12c-data', e.rbytes(a[0], 0x24).hex(), e.rbytes(a[1], 12).hex()))
        return 0
    this = obj(c, 0x200, vt(c, 'self', {0x12c: (3, s12c)}))
    c.emu.w32(this + 0x137, c.rng.choice([0, 1, c.rng.getrandbits(32)]))
    return [this, rnd(c, 0x80)]


def _rle(c):
    total = c.rng.choice([0, 1, 5, 40, 200])
    src = b''
    left = total
    while left:
        n = c.rng.randrange(1, min(left, 60) + 1)
        if c.rng.random() < 0.5:
            src += n.to_bytes(2, 'little', signed=True) + bytes([c.rng.getrandbits(8)])
        else:
            src += (-n).to_bytes(2, 'little', signed=True) + bytes(c.rng.getrandbits(8) for _ in range(n))
        left -= n
    sa = c.emu.alloc(len(src) + 16, 4)
    c.emu.wbytes(sa, src + bytes(c.rng.getrandbits(8) for _ in range(16)))
    dst = rnd(c, total + 16)
    mem_hooks(c)
    return [dst, dst + total, sa, c.rng.getrandbits(32)]


def _allocblk(c):
    n = c.rng.choice([0, 1, 2, 3])
    raw = c.emu.alloc((n << 12) + 0x1010 + 0x20, c.rng.choice([4, 16, 0x1000]))
    al = obj(c, 0x10, vt(c, 'al', {0: (1, c.rng.choice([0, raw, raw]))}))
    this = rnd(c, 0x40)
    c.emu.w32(this + 0x14, al)
    c.emu.w32(this + 0x1c, n)
    return [this]


def _factory(ctor):
    def g(c):
        al = obj(c, 0x10, vt(c, 'al', {0x44: (1, c.rng.choice([0, rnd(c, 0x40)]))}))
        rm = rnd(c, 0x20)
        c.emu.w32(rm + 8, al)
        eng(c, {0x9b: rm})
        hk(c, ctor, 0, ecx=True, ret=c.rng.getrandbits(32))
        return [c.rng.getrandbits(32)]
    return g


def _holder(c):
    hk(c, 0x41e290, 1, pop=0, ret=c.rng.choice([0, rnd(c, 0x28)]))
    hk(c, 0x4e7dd0, 1, ecx=True, ret=c.rng.getrandbits(32))
    return [rnd(c, 0x10), c.rng.getrandbits(32)]


def _grid(c):
    d = obj(c, 0x10, cvt(c, 'draw', {0x184: (4, 0)}))
    e = obj(c, 0x2000, vt(c, 'eng', {0x190: (0, d)}))
    c.emu.w32(0x70039c, e)
    this = rnd(c, 0x10)
    c.emu.w32(this + 4, c.rng.choice([0, 1, 2, 3, 4, 7, 13]))
    return [this]


def _enumkeys(c):
    recs = b''
    for _ in range(c.rng.randrange(0, 6)):
        nl = c.rng.choice([0, 1, 5, 12])
        body = bytes([c.rng.choice([0, 1, 0x80])]) + nl.to_bytes(4, 'little') + bytes(8) + \
            bytes(c.rng.getrandbits(8) for _ in range(nl))
        sz = 4 + len(body) + c.rng.choice([0, 3])
        recs += sz.to_bytes(4, 'little') + body + bytes(sz - 4 - len(body))
    base = rnd(c, len(recs) + 0x40)
    c.emu.wbytes(base, recs)
    this = rnd(c, 0x20)
    c.emu.w32(this + 8, base)
    c.emu.w32(this + 0xc, len(recs))
    handler(c)
    mem_hooks(c)
    return [this, rnd(c, 0x20), c.rng.choice([0, 1, 5, 13, 0x40, -1 & 0xffffffff]), c.rng.choice([0, 1, 2, 3, 5])]


def _setmult(slot_get, slot_set, size):
    def g(c):
        rec = bytes(c.rng.getrandbits(8) for _ in range(size))

        def gt(e, a, rec=rec):
            e.wbytes(a[1], rec)

        def st(e, a):
            e.calllog.append(('set-data', e.rbytes(a[1], size).hex()))
        ls = obj(c, 0x10, vt(c, 'ls', {slot_get: (2, gt), slot_set: (2, st)}))
        l1 = rnd(c, 0x20)
        c.emu.w32(l1 + 0x18, ls)
        eng(c, {0x1aa3: l1})
        this = obj(c, 0x40, vt(c, 'self', {0x238: (0, 0), 0x220: (1, 0)}))
        c.emu.w32(this + 8, rnd(c, 0x80))
        return [this, c.rng.getrandbits(32)]
    return g


def _matcopy(c):
    hk(c, 0x43f8c0, 1, ecx=True)
    items = rv(c, c.rng.randrange(0, 4))
    st = [0]

    def begin(e, a):
        e.w32(a[0], 1 if items else 0)

    def nxt(e, a):
        i = st[0]
        st[0] += 1
        e.w32(a[0], 1 if i < len(items) else 0)
        return items[i] if i < len(items) else 0
    src = rnd(c, 0x80)
    t = rnd(c, 0x40)
    c.emu.w32(t + 0x23, c.rng.choice([0x1000f0, 0x1000f0, 0x1000f1]))
    c.emu.w32(src + 0xc, t)
    c.emu.w32(src + 0x5c, c.rng.choice([0, obj(c, 0x10, vt(c, 'sl', {0x4c: (1, begin), 0x5c: (1, nxt)}))]))
    this = rnd(c, 0x80)
    c.emu.w32(this + 0x5c, obj(c, 0x10, vt(c, 'dl', {0xc: (0, 0), 4: (1, 0)})))
    return [this, src]


def _dtor(c):
    hk(c, 0x634273, 2, pop=0)
    eng(c, {0x9b: obj(c, 0x10, vt(c, 'rm', {0x34: (1, 0)}))})
    return [rnd(c, 0x80)]


S(0x633eac, '___scrt_uninitialize_crt cdecl', 'cdecl', None, ret='al', gen=_scrt)
S(0x5fd120, 'ScriptEngine_t::recycle(Process_t*) thiscall', 'thiscall', None, gen=_recycle)
S(0x658ca0, 'prim CopyDataBlock with GetMatPos (GUESS) thiscall', 'thiscall', None, gen=_matpos)
S(0x4247e0, 'RLE decode (GUESS) stdcall', 'stdcall', None, ret='eax', gen=_rle)
S(0x63b6a0, 'ZDrawArrayBlocks<ZArrayBlock>::AllocBlock thiscall', 'thiscall', None, ret='eax', gen=_allocblk)
S(0x4be8e0, 'factory ZMusicControl (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_factory(0x4bdaf0))
S(0x4c4ba0, 'factory 0x4c4930 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_factory(0x4c4930))
S(0x4c5460, 'factory 0x4c52f0 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_factory(0x4c52f0))
S(0x4d8ce0, 'holder ctor (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_holder)
S(0x48f9a0, '3-column grid layout (GUESS) thiscall', 'thiscall', None, gen=_grid)
S(0x4d2a20, 'CGlobalCom::EnumKeys thiscall', 'thiscall', None, ret='al', gen=_enumkeys)
S(0x449ae0, 'ZOMNILIGHT::SetMultiplier(float) thiscall', 'thiscall', None, gen=_setmult(0x80, 0x98, 0x24))
S(0x452e60, 'ZENVIRONMENT::SetMultiplier(float) thiscall', 'thiscall', None, gen=_setmult(0x8c, 0xac, 0x1c))
S(0x454da0, 'ZMaterialDescGroup::CopyData thiscall', 'thiscall', None, gen=_matcopy)
S(0x4a3360, 'dtor vtables 0x68fadc/0x686874 (GUESS) thiscall', 'thiscall', None, gen=_dtor)
