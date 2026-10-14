"""specs_s36018.py - cascade s4 batch 36018: 0x63fdd0 (init bucket pool and insert), 0x425c60 (log a formatted line), 0x42feb0 (compare two byte ranges), 0x46cb70 (copy selected fields), 0x4584f0 (read colour fields from a stream)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, stub_memset


def _cstr(em, p, limit=0x500):
    s = b''
    while len(s) < limit:
        ch = em.rbytes(p, 1)
        if ch == b'\0':
            break
        s += ch
        p += 1
    return s


def _g63fdd0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    stub_memset(c)
    E = e.alloc(0x3500, 4)
    e.wbytes(E, bytes(r.getrandbits(8) for _ in range(0x400)))
    e.wbytes(E + 0x3400, bytes(r.getrandbits(8) for _ in range(0x20)))
    k = r.choice([0, 1, 2, 5, 7, 8, 9, 12, 16, 20])
    b = (1 << k) + r.choice([0, 0, 1, r.getrandbits(k) if k else 0]) if r.random() < 0.9 else r.choice([0, 1])
    a = r.choice([0, b, b // 2, r.randint(0, b)]) if b else 0
    return [E, a & 0xffffffff, b & 0xffffffff]


def _g425c60(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def vsp(em, rr):
        buf, fmt, ap = em.arg32(0), em.arg32(1), em.arg32(2)
        n = r.choice([0, 0, 1, 5, 40, 0x3fe])
        s = bytes(r.randint(1, 255) if r.random() > 0.05 else 0x41 for _ in range(n))
        if n and r.random() < 0.4:
            s = s[:-1] + b'\n'
        s = s.replace(b'\0', b'A')
        em.wbytes(buf, s + b'\0')
        em.calllog.append(('vsprintf', fmt, em.r32(ap), em.r32(ap + 4)))
        em.ret(eax=len(s), argbytes=0)
    e.hook(0x42abee, vsp)

    def y4(em, rr):
        em.calllog.append(('y4', em.arg32(0), _cstr(em, em.arg32(1))))
        em.ret(eax=0, argbytes=0)
    y = obj(c, 0x20, {4: e.stub_fn('y4', y4)})
    seq = [0 if r.random() < 0.3 else y, y]
    sysobj(c, slots={0x1b0: pystub(c, 0, this=True, ret=lambda em, k: seq[min(k, 1)])})
    if r.random() < 0.1:
        e.w32(0x70039c, 0)
    return [r.getrandbits(32), rnd(c, 0x10), r.getrandbits(32), r.getrandbits(32)]


def _g42feb0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    A = e.alloc(0x40, 4)
    C = e.alloc(0x40, 4)
    data = bytes(r.getrandbits(8) for _ in range(0x40))
    e.wbytes(A, data)
    oa, oc = r.randint(0, 3), r.randint(0, 3)
    l1, l2 = r.choice([0, 1, 3, 4, 5, 8, 12, r.randint(0, 12)]), r.choice([0, 1, 3, 4, 5, 8, 12, r.randint(0, 12)])
    cdata = bytearray(data)
    cdata[oc:oc + 16] = data[oa:oa + 16]
    if r.random() < 0.6:
        pos = r.randrange(0, 16)
        cdata[oc + pos] = (cdata[oc + pos] + r.choice([1, 0xff, 0x80, 0x7f])) & 0xff
    e.wbytes(C, bytes(cdata))
    return [A + oa, A + oa + l1, C + oc, C + oc + l2]


def _g46cb70(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x43f8c0, 1, this=True)
    n = r.choice([0, 1, 2, 3])
    locs = [1] * n + [0]
    rets = [r.getrandbits(32) for _ in range(5)]

    def side(em, k):
        em.w32(em.arg32(0), locs[min(k, len(locs) - 1)])
    lst = obj(c, 0x20, {0x4c: pystub(c, 1, this=True, stackmark=(0,)),
                        0x5c: pystub(c, 1, this=True, stackmark=(0,), ret=lambda em, k: rets[min(k, 4)], side=side)})
    sq = [r.choice([0, 1, 0x100]), r.choice([0, 1, 0x100])]
    s = obj(c, 0x100, {0x1e0: pystub(c, 1, this=True, ret=lambda em, k: sq[min(k, 1)])})
    e.w32(s + 0x7c, 0 if r.random() < 0.2 else lst)
    E = obj(c, 0x100, {})
    ob = obj(c, 0x20, {4: pystub(c, 1, this=True)})
    e.w32(E + 0x7c, ob)
    return [E, s]


def _g4584f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x451d00, 1, this=True)

    def side(em, k):
        em.w32(em.arg32(0), 0 if (k == 0 and r.random() < 0.3) else r.getrandbits(32))
    hook_rec(c, 0x4e12e0, 2, this=True, side=side, stackmark=(0,))
    hook_rec(c, 0x4e1600, 0, this=True, ret=r.choice([3, 3, 0, 1, 0x103]))
    hook_rec(c, 0x4e1b30, 0, this=True)
    hook_rec(c, 0x4587d0, 0, this=True)
    o = 0 if r.random() < 0.2 else obj(c, 0x20, {0x1e0: pystub(c, 1, this=True, ret=r.choice([0, 1, 0x100])), 0xbc: pystub(c, 1, this=True)})
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=o)})
    E = rnd(c, 0x80)
    s = rnd(c, 0x20)
    return [E, s]


S(0x63fdd0, 'GUESS init bucket pool and insert range', 'thiscall', None, ret=None, gen=_g63fdd0, note='batch36018')
S(0x425c60, 'GUESS log a formatted line', 'cdecl', None, ret=None, gen=_g425c60, note='batch36018')
S(0x42feb0, 'GUESS compare two byte ranges', 'fastcall', None, ret='eax', gen=_g42feb0, note='batch36018')
S(0x46cb70, 'GUESS copy selected fields and list', 'thiscall', None, ret=None, gen=_g46cb70, note='batch36018')
S(0x4584f0, 'GUESS read id and colour from stream', 'thiscall', None, ret=None, gen=_g4584f0, note='batch36018')
