"""specs_s2513.py - decomp area 24, batch 2513.
0x491630 (GUESS DBREAD property-list reader): stdcall(names, block), ret 8, SEH frame. names: comma separated list (heap, written in
place by the code), block+4: tag stream. All stream readers (0x4e5ea0, 0x4e5e60, 0x4e6250, 0x4e6180, 0x4e6050, 0x4e6330, 0x4e6420)
and the record ctor/dtor (0x4ccbe0, 0x4ccfe0) are hooked: they advance the cursor (their ECX is the address of the caller's cursor
local, recorded as a marker) by one byte. The three array readers write their random doubles into their buffer argument and return
the count. The database object (system+0x9b slot 0x138) has recorder slots 0x30, 0x34, 0x3c, 0x40, 0x44, 0x60; the array slots also log
their array contents (n dwords) in the call log. strchr (IAT 0x676254) is a Python stub. Unknown tags log through [0x700390]."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _cstr(em, p):
    out = b''
    while True:
        b = bytes(em.rbytes(p, 1))
        if b == b'\0' or len(out) > 4096:
            return out
        out += b
        p += 1


def _dbl(r):
    k = r.random()
    if k < 0.05:
        return 1e300
    if k < 0.08:
        return float('nan')
    if k < 0.12:
        return 0.0
    return r.uniform(-1000, 1000) if k < 0.7 else r.uniform(-1, 1)


def _gen(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def sc(em, rr):
        p, ch = em.arg32(0), em.arg32(1) & 0xff
        em.calllog.append(('strchr', 0, 0, (p, ch)))
        s = _cstr(em, p)
        k = s.find(bytes([ch])) if ch else len(s)
        em.ret(eax=(p + k) if k >= 0 else 0, argbytes=0)
    e.w32(0x676254, e.stub_fn('strchr', sc))

    def adv(em, k):
        cur = em.reg('ecx')
        em.w32(cur, em.r32(cur) + 1)

    counts = [r.choice([0, 1, 2, 3, 4, 7, 12, 40]) for _ in range(8)]

    def mk_arr(em, k):
        buf = em.arg32(0)
        n = counts[k % 8]
        for i in range(n):
            em.wbytes(buf + 8 * i, struct.pack('<d', _dbl(r)))
        adv(em, k)

    def cnt(em, k):
        return counts[k % 8]

    for a in (0x4e5ea0, 0x4e5e60):
        hook_rec(c, a, 0, ret=lambda em, k: r.getrandbits(32), this='mark', side=adv)
    for a in (0x4e6250, 0x4e6180, 0x4e6050):
        hook_rec(c, a, 1, ret=cnt, this='mark', nullflag=(0,), side=mk_arr)
    hook_rec(c, 0x4e6330, 1, this='mark', nullflag=(0,), side=adv)
    hook_rec(c, 0x4e6420, 0, this='mark', side=adv)
    hook_rec(c, 0x4ccbe0, 2, this='mark')
    hook_rec(c, 0x4ccfe0, 0, this='mark')

    def logarr(em, k):
        ptr, n = em.arg32(1), em.arg32(2)
        d = tuple(em.r32(ptr + 4 * i) for i in range(min(n, 64)))
        em.calllog.append(('dbarr', 0, 0, d))

    st = lambda **kw: pystub(c, **kw)
    db = obj(c, 0x20, {0x30: pystub(c, 4, this=True, nullflag=(1,), side=logarr),
                       0x34: pystub(c, 4, this=True, nullflag=(1,), side=logarr),
                       0x3c: pystub(c, 3, this=True), 0x40: pystub(c, 3, this=True),
                       0x44: pystub(c, 3, this=True, nullflag=(1,)), 0x60: pystub(c, 3, this=True)})
    sysobj(c, table_slots={0x138: pystub(c, 0, this=True, ret=db)})
    lobj = obj(c, 0x20, {0x2c: pystub(c, 3, pop=0)})
    lg = obj(c, 0x20, {0x20: pystub(c, 2, this=True, ret=lobj)})
    e.w32(0x700390, lg)

    # tag stream: mostly valid tags
    tags = [1, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12, 6, 0, 13, 0x3f, 0xff, 0x41, 0x84, 0x4d, 0x8d, 0xc0, 0x7f]
    stream = bytes([r.choice(tags)] + [r.getrandbits(8) for _ in range(0x7f)])
    stream = bytes(r.choice(tags) for _ in range(0x80))
    blk = e.alloc(0x90, 4)
    e.wbytes(blk, bytes(4) + stream)
    if r.random() < 0.1:
        names = 0
    else:
        parts = [b'a', b'', b'pos', b'color', b'x', b'Name']
        s = b','.join(r.choice(parts) for _ in range(r.randint(1, 6)))
        names = e.alloc(len(s) + 1, 1)
        e.wbytes(names, s + b'\0')
    return [names, blk]


S(0x491630, 'GUESS DBREAD property-list reader (SEH frame)', 'stdcall', None, ret=None, gen=_gen, note='batch2513')
