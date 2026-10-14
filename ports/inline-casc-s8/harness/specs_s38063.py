"""specs_s38063.py - cascade s8 batch 38063. Paths from {the root marker (image string at 0x67cd1c, random case), 'ROOT\\a\\b', 'ROOT\\x', 'a\\b', 'abc', 'zz\\yy\\', 'q', ...}; ctx is given 45% of the time (chain via +0x60)
or not (children chain at this[0x50]). Chain entries have an object (null 10%) with name (null 20% -> default string, otherwise from {a, b, abc, x, q}), a flag block (+0xc -> dword at +0x23, bit
0x100000 set 60%), byte-field +0x30 (0x802 bits set 25%) and slot 0x25c (2 args, returns a result object or 0); the nodes also carry +0x30. The CRT imports 0x676414 (_stricmp), 0x676258 (strrchr),
0x676254 (strchr), 0x67640c (_strnicmp) are logged Python stubs; 0x4cc850 (fastcall name matcher) is a hook returning 0 about 35% of the time; this slot 0x20 returns 0 / 1."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _cstr(em, p):
    out = b''
    while len(out) < 80:
        b = em.rbytes(p, 1)
        if b == b'\0':
            break
        out += b
        p += 1
    return out


def _g440590(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def stricmp(em, res_):
        a, b = _cstr(em, em.arg32(0)).lower(), _cstr(em, em.arg32(1)).lower()
        em.calllog.append(('_stricmp', a, b))
        em.ret(eax=0 if a == b else (1 if a > b else 0xffffffff), argbytes=0)

    def strrchr(em, res_):
        s, ch = em.arg32(0), em.arg32(1)
        t = _cstr(em, s)
        i = t.rfind(bytes([ch & 0xff]))
        em.calllog.append(('strrchr', t, ch))
        em.ret(eax=(s + i) if i >= 0 else 0, argbytes=0)

    def strchr(em, res_):
        s, ch = em.arg32(0), em.arg32(1)
        t = _cstr(em, s)
        i = t.find(bytes([ch & 0xff]))
        em.calllog.append(('strchr', t, ch))
        em.ret(eax=(s + i) if i >= 0 else 0, argbytes=0)

    def strnicmp(em, res_):
        a, b, n = em.arg32(0), em.arg32(1), em.arg32(2)
        sa, sb = _cstr(em, a).lower()[:n], _cstr(em, b).lower()[:n]
        em.calllog.append(('strnicmp', sa, sb, n))
        em.ret(eax=0 if sa == sb else (1 if sa > sb else 0xffffffff), argbytes=0)
    e.w32(0x676414, e.stub_fn('stricmp', stricmp))
    e.w32(0x676258, e.stub_fn('strrchr', strrchr))
    e.w32(0x676254, e.stub_fn('strchr', strchr))
    e.w32(0x67640c, e.stub_fn('strnicmp', strnicmp))
    pm = 0.35

    def h4cc(em, res_):
        a, b = em.reg('ecx'), em.reg('edx')
        em.calllog.append(('4cc850', _cstr(em, a), _cstr(em, b)))
        em.ret(eax=0 if r.random() < pm else 1, argbytes=0)
    e.hook(0x4cc850, h4cc)
    names = [b'a', b'b', b'abc', b'x', b'q', b'zz', b'yy']
    pool = []

    def mkname(nm):
        p = e.alloc(len(nm) + 1, 1)
        e.wbytes(p, nm + b'\0')
        return p

    def mkobj():
        o = obj(c, 0x40, {0x25c: pystub(c, 2, this=True, ret=lambda em, k: (rr if r.random() < 0.5 else 0))})
        blk = rnd(c, 0x40)
        fl = (r.getrandbits(32) & ~0x100000) | (0x100000 if r.random() < 0.85 else 0)
        e.wbytes(blk + 0x23, struct.pack('<I', fl))
        e.w32(o + 0xc, blk)
        e.w32(o + 4, 0 if r.random() < 0.2 else mkname(r.choice(names)))
        e.w32(o + 0x30, r.choice([0x802, 0x800, 0x002, 0x1000, 0, 0x1000, 0x804, r.getrandbits(32) & ~0x802]))
        return o
    rr = rnd(c, 0x20)

    def mkchain():
        nodes = []
        for _ in range(r.choice([0, 1, 2, 3])):
            nd = rnd(c, 0x80)
            e.w32(nd + 0x54, 0 if r.random() < 0.1 else mkobj())
            e.w32(nd + 0x30, r.choice([0x802, 0x800, 0x002, 0x1000, 0, 0x1000, 0x804, r.getrandbits(32) & ~0x802]))
            nodes.append(nd)
        for a, b in zip(nodes, nodes[1:]):
            e.w32(a + 0x60, b)
        if nodes:
            e.w32(nodes[-1] + 0x60, 0)
        return nodes[0] if nodes else 0
    me = obj(c, 0x100, {0x20: pystub(c, 0, this=True, ret=lambda em, k: r.choice([0, 0, 1]))})
    e.w32(me + 0x50, mkchain())
    ctx = 0
    if r.random() < 0.45:
        ctx = rnd(c, 0x80)
        e.w32(ctx + 0x60, mkchain())
    marker = bytes(e.rbytes(0x67cd1c, 24)).split(b'\0')[0]
    marker = bytes(ch ^ 0x20 if (65 <= (ch | 0x20) <= 90 and r.random() < 0.5) else ch for ch in marker)
    pth = r.choice([marker, b'ROOT\\a\\b', b'ROOT\\x', b'a\\b', b'abc', b'zz\\yy\\', b'q', b'ROOT\\', b'ROOT\\abc', b'x\\y', b'a', b'b\\a\\c'])
    return [me, mkname(pth), ctx]


S(0x440590, 'GUESS find named child by path', 'thiscall', None, ret='eax', gen=_g440590, note='batch38063')
