"""specs_s34137.py - 0x53b710: five unaligned pointer fields, each zero or a block; 0x634273 a cdecl recorder (2 args); dwords prefilled with random values.
0x53c210 (ecx, edx, stack n): packed table of "string\\0"+dword entries, name equal (up to case) to an entry in half the cases; n at, below and above the table size and non-positive; _stricmp stubbed in Python.
0x54de40: unaligned fields +0x8031/+0x802d (pointer or 0), count +0x805d (0..3, also negative), array +0x803d of objects with slots 0x24 and 0x40, +0x8061 object with slot 0x14 or 0."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _g53b710(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x634273, 2, pop=0)
    me = rnd(c, 0x1220)
    for off in (0x11f9, 0x11fd, 0x1201, 0x1205, 4):
        c.emu.wbytes(me + off, (0 if r.random() < 0.4 else rnd(c, 0x10)).to_bytes(4, 'little'))
    return [me]


def _g53c210(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    names = [b'Alpha', b'beta', b'GAMMA', b'', b'x', b'Delta1']
    ents = [(r.choice(names), r.getrandbits(32)) for _ in range(r.choice([0, 1, 2, 3, 4]))]
    data = b''.join(s + b'\0' + v.to_bytes(4, 'little') for s, v in ents)
    base = rnd(c, 0x100)
    e.wbytes(base, data + bytes(0x100 - len(data)))
    if ents and r.random() < 0.6:
        s = r.choice(ents)[0]
        key = bytes(ch ^ 0x20 if (65 <= ch <= 90 or 97 <= ch <= 122) and r.random() < 0.5 else ch for ch in s)
    else:
        key = r.choice(names + [b'zzz'])
    k = rnd(c, 0x10)
    e.wbytes(k, key + b'\0')
    n = r.choice([len(data), len(data), len(data) + 3, max(len(data) - 1, 0), 0, r.getrandbits(31) * -1 & 0xffffffff, r.randrange(0x40)])

    def cstr(em, p):
        out = b''
        while True:
            b = bytes(em.rbytes(p, 1))
            if b == b'\0':
                return out
            out += b
            p += 1

    def sti(em, res_):
        a, b = cstr(em, em.arg32(0)), cstr(em, em.arg32(1))
        em.calllog.append(('_stricmp', a, b))
        em.ret(eax=0 if a.lower() == b.lower() else r.choice([1, 0xffffffff]), argbytes=0)
    e.stub_import('_stricmp', sti)
    return [k, base, n]


def _g54de40(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x634273, 2, pop=0)
    me = rnd(c, 0x8080)
    n = r.choice([0, 1, 2, 3, -1])
    objs = [obj(c, 0x30, {0x24: pystub(c, 0, this=True), 0x40: pystub(c, 0, this=True)}, nslots=0x44 // 4) for _ in range(max(n, 0))]
    arr = rnd(c, 0x20)
    for i, o in enumerate(objs):
        e.w32(arr + 4 * i, o)
    def w(off, v):
        e.wbytes(me + off, (v & 0xffffffff).to_bytes(4, 'little'))
    w(0x8031, 0 if r.random() < 0.4 else rnd(c, 0x10))
    w(0x802d, 0 if r.random() < 0.4 else rnd(c, 0x10))
    w(0x805d, n)
    w(0x803d, arr)
    w(0x8061, 0 if r.random() < 0.4 else obj(c, 0x20, {0x14: pystub(c, 0, this=True)}, nslots=0x18 // 4))
    return [me]


S(0x53b710, 'GUESS free four buffers', 'thiscall', None, ret=None, gen=_g53b710, note='batch34137')
S(0x53c210, 'GUESS find a name in a packed table', ('regs', ['ecx', 'edx', 's']), None, ret='eax', gen=_g53c210, note='batch34137')
S(0x54de40, 'GUESS reset a list', 'thiscall', None, ret=None, gen=_g54de40, note='batch34137')
