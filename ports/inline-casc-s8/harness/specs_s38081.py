"""specs_s38081.py - cascade s8 batch 38081. thiscall(void). this = 0xc0-byte random block: flags word +0xac (usually enters), object array +0x4c / count +0x54 (0..4 objects, room for 8), id translation 0x5ffbc0 (hooked, -1 sometimes) /
+0x8c, range table +0x96 (chain of nodes: start +0x48, size via the real 0x600810 on +0x50 ([+0x58]-[+0x54]), +0x54, next +0x9c, arrays +0x3c / +0x40 indexed by +0x9e), +0x16 compare string, +0x12 result of the hooked 0x5f56f0.
Objects: slots 0x5c (u16 id, 0 sometimes), 0x54 (name text), 0x40 (nonzero mostly), 0x28 (logs; sometimes appends a new object to the queue, up to 4 per case). The assert hook, 0x5f3c90 (logs the stack struct by content),
0x5f56f0 (logs this[0x1a] / [0x1e] / [0xac] / [0xae] / [0xb2], sets this[0x12] to -1 or a value and clobbers [0xa6] / [0xaa]), 0x5f9130 are hooked; _stricmp (IAT 0x676414) logs the strings."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec


def _cstr(em, p, lim=0x40):
    out = b''
    while len(out) < lim:
        b = em.rbytes(p, 1)
        if b == b'\0':
            break
        out += b
        p += 1
    return out


def _g5f4ac0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))
    strs = []
    for s in (b'alpha', b'ALPHA', b'beta'):
        p = e.alloc(0x10, 1)
        e.wbytes(p, s + b'\0')
        strs.append(p)
    this = rnd(c, 0xc0)
    appended = [0]

    def lslot(name, retf=lambda: 0, side=None):
        def h(em, res_):
            em.calllog.append((name, em.reg('ecx')))
            if side:
                side(em)
            em.ret(eax=retf(), argbytes=0)
        return e.stub_fn(name, h)

    def mkobj():
        def add(em):
            n = e.r32(this + 0x54)
            if appended[0] < 4 and n < 8 and r.random() < 0.2:
                appended[0] += 1
                e.w32(e.r32(this + 0x4c) + 4 * n, mkobj())
                e.w32(this + 0x54, n + 1)
        return obj(c, 0x20, {0x5c: lslot('s5c', lambda: r.choice([0, 0, 1, 2, 3, 0x10003]) & 0xffffffff),
                             0x54: lslot('s54', lambda: strs[r.randrange(3)]),
                             0x40: lslot('s40', lambda: r.choice([1, 1, 1, 0])),
                             0x28: lslot('s28', side=add)})
    n = r.choice([0, 1, 2, 3, 4])
    arr = rnd(c, 4 * 8 + 8)
    for i in range(n):
        e.w32(arr + 4 * i, mkobj())
    e.w32(this + 0x4c, arr)
    e.w32(this + 0x54, n)
    low = r.choice([1, 2, 3, 4, 4, 5, 5, 6, 0, 0xf])
    flags = low | (r.getrandbits(16) & 0x7fd0 & ~0xa800 & 0xfff0)
    if r.random() < 0.12:
        flags |= 0xa800 & r.getrandbits(16) | 0x800
    e.wbytes(this + 0xac, struct.pack('<H', flags & 0xffff))
    e.w32(this + 0x8c, r.choice([0xffffffff, 3, 5, 0x11]))
    e.wbytes(this + 0x9e, struct.pack('<I', 4 * r.randrange(0, 4)))
    e.wbytes(this + 0x16, struct.pack('<I', r.choice([0, strs[0], strs[1], strs[2]])))
    for off in (0x12, 0x1a, 0xa6, 0xaa, 0xae, 0xb2, 0xa):
        e.wbytes(this + off, struct.pack('<I', r.getrandbits(32)))
    always_found = r.random() < 0.5   # in this mode every id lies inside the first range, so this[0xa6] is defined and logged (the original reads a stale frame value when no range matches)
    chain = 0
    A_prev = 0
    nodes = []
    for _ in range(r.choice([1, 2, 3])):
        nd = rnd(c, 0xa0)
        e.w32(nd + 0x48, r.randrange(0, 0x20))
        e.w32(nd + 0x54, r.randrange(0, 0x100))
        e.w32(nd + 0x58, e.r32(nd + 0x54) + r.randrange(0, 0x20))
        e.w32(nd + 0x3c, rnd(c, 0x30))
        e.w32(nd + 0x40, rnd(c, 0x30))
        nodes.append(nd)
    if always_found:
        e.w32(nodes[0] + 0x48, 0)
        e.w32(nodes[0] + 0x58, e.r32(nodes[0] + 0x54) + 0x100)
    for a, b in zip(nodes, nodes[1:] + [0]):
        e.w32(a + 0x9c, b)
    e.wbytes(this + 0x96, struct.pack('<I', nodes[0]))

    def xl(em, res_):
        v = r.choice([0xffffffff, 1, 2, 5, 0x10, 0x18, 0x25])
        em.calllog.append(('5ffbc0', em.reg('ecx') != 0, em.arg32(0), v))
        em.ret(eax=v, argbytes=4)
    e.hook(0x5ffbc0, xl)

    def h3c90(em, res_):
        p = em.arg32(0)
        em.calllog.append(('5f3c90', em.reg('ecx') != 0, struct.unpack('<I', em.rbytes(p, 4))[0], struct.unpack('<H', em.rbytes(p + 0xc, 2))[0]))
        em.ret(eax=0, argbytes=4)
    e.hook(0x5f3c90, h3c90)

    def h56f0(em, res_):
        t = em.reg('ecx')
        em.calllog.append(('5f56f0', em.rbytes(t + 0x1a, 6), em.rbytes(t + 0xac, 2), em.rbytes(t + 0xae, 4), em.rbytes(t + 0xb2, 4), em.rbytes(t + 0x12, 4), (em.rbytes(t + 0xa6, 4) if always_found else b'')))
        em.w32(t + 0x12, r.choice([0xffffffff, 0xffffffff, 7, 9]))
        em.w32(t + 0xa6, r.getrandbits(32))
        em.w32(t + 0xaa, r.getrandbits(32))
        em.ret(eax=0, argbytes=0)
    e.hook(0x5f56f0, h56f0)
    hook_rec(c, 0x5f9130, 2, this=True, pop=8)

    def sic(em, res_):
        a, b = _cstr(em, em.arg32(0)).lower(), _cstr(em, em.arg32(1)).lower()
        em.calllog.append(('_stricmp', a, b))
        em.ret(eax=0 if a == b else 1, argbytes=0)
    e.w32(0x676414, e.stub_fn('_stricmp', sic))
    return [this]


S(0x5f4ac0, 'GUESS drain pending object queue', 'thiscall', None, ret=None, gen=_g5f4ac0, note='batch38081')
