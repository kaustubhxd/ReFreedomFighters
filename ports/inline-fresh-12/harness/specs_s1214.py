"""specs_s1214.py - fresh slice 12, batch 14."""
import struct
from pilot import S
from engine_stubs import zero_obj, logged_obj, set_global
from helpers12 import rand_obj, rand_fast, hk, hk_cdecl, done


def _cstr(em, a):
    out = b''
    while True:
        ch = bytes(em.mu.mem_read(a + len(out), 1))
        if ch == b'\0':
            return out
        out += ch


def g_51b640(c):
    o = c.rng.choice([0, rand_obj(c, 0x20)])
    c.emu.hook(0x41e290, hk_cdecl(0x41e290, 'alloc', 1, lambda em: o))
    c.emu.hook(0x51a9f0, hk(0x51a9f0, 'base', 1))
    c.emu.hook(0x51b530, hk(0x51b530, 'init', 0))
    c.emu.w32(0x701800, c.rng.choice([0, 0, 1, 0x100, 0x10000, c.rng.getrandbits(32)]))
    c.emu.w32(0x6f5630, c.rng.getrandbits(32))
    return done(c, [rand_obj(c, 0x40)])


def g_4934c0(c):
    def ms(em, r):
        p, v, n = em.arg32(0), em.arg32(1), em.arg32(2)
        em.calllog.append(('memset', 0, 0, (p, v, n)))
        em.wbytes(p, bytes([v & 0xff]) * n)
        em.ret(eax=p, argbytes=0)
    c.emu.hook(0x634d10, ms)

    def sc(em, r):
        p, ch = em.arg32(0), em.arg32(1) & 0xff
        em.calllog.append(('strchr', 0, 0, (p, ch)))
        s = _cstr(em, p)
        k = s.find(bytes([ch])) if ch else len(s)
        em.ret(eax=(p + k) if k >= 0 else 0, argbytes=0)
    c.emu.w32(0x676254, c.emu.stub_fn('strchr', sc))
    buf = rand_fast(c, 0x1160)
    self_ = rand_obj(c, 0xc00)
    c.emu.w32(self_ + 0x1c, c.emu.logging_vtable('Alloc', 0x40, impl={0x84: lambda e, a: (buf, None)}, argwords={0x84: 1}))
    k = c.rng.randrange(6)
    if k == 0:
        name = 0
    else:
        parts = [b'data', b'levels', b'C01A', b'x', b'Sound', b'a.wav', b'', b'..']
        sep = [b'/', b'\\', b'/']
        s = b'' if k == 1 else b''.join(c.rng.choice(parts) + c.rng.choice(sep) for _ in range(c.rng.randrange(1, 8)))
        if k == 2:
            s = bytes(c.rng.choice(b'/ab\\') for _ in range(c.rng.randrange(1, 40)))
        name = c.emu.alloc(len(s) + 1, 1)
        c.emu.wbytes(name, s + b'\0')
    return done(c, [self_, name])


def g_64d400(c):
    n = c.rng.choice([0, rand_obj(c, 0x10)])
    pool = logged_obj(c, 'Pool', 0x10, impl={8: lambda e, a: (n, None)}, argwords={0xc: 1})
    ok = c.rng.choice([0, 1, 0x100, 0xff, c.rng.getrandbits(32)])
    self_ = rand_fast(c, 0x10200)
    c.emu.w32(self_, c.emu.logging_vtable('Self', 0x20, impl={0x4c: lambda e, a: (ok, None)}, argwords={0x4c: 1}))
    tbl = zero_obj(c, 0x4000)
    e = rand_obj(c, 0x10)
    idx = struct.unpack('<H', bytes(c.emu.mu.mem_read(e + 6, 2)))[0] & 0xfff
    if c.rng.random() < 0.3:
        c.emu.w32(tbl + idx * 4, c.rng.getrandbits(32) | 1)
    r = rand_obj(c, 0x10)
    c.emu.w32(r + 8, e)
    d = rand_obj(c, 0x20)
    c.emu.w32(d + 0x10, r)
    item = rand_obj(c, 0x10)
    c.emu.w32(item + 8, d)
    c.emu.w32(self_ + 0x10071, tbl)
    c.emu.w32(self_ + 0x10161, pool)
    return done(c, [self_, item])


def _f(c):
    k = c.rng.randrange(5)
    if k == 0:
        return c.rng.random()
    if k == 1:
        return c.rng.uniform(-2, 2)
    if k == 2:
        return float(c.rng.randrange(-3, 4)) / 4
    if k == 3:
        return c.rng.uniform(-1e9, 1e9)
    return struct.unpack('<f', struct.pack('<I', c.rng.getrandbits(32)))[0]


def g_650c40(c):
    vals = [c.rng.choice([0, 1, 640, 480, 1024, 768, -5, c.rng.randrange(-4000, 4000)]) & 0xffffffff for _ in range(4)]
    it = {'d8': [vals[0], vals[2]], 'dc': [vals[1], vals[3]]}
    s = logged_obj(c, 'Self', 0x40, impl={0xd8: lambda e, a: (it['d8'].pop(0) if it['d8'] else 0, None), 0xdc: lambda e, a: (it['dc'].pop(0) if it['dc'] else 0, None)})
    v = c.emu.alloc(8, 4)
    c.emu.wbytes(v, struct.pack('<2f', _f(c), _f(c)))
    return done(c, [s, v])


S(0x51b640, 'FUN_0051b640 new child (0x20, vt 0x69f43c), SEH', 'thiscall', None, ret='eax', gen=g_51b640)
S(0x4934c0, 'FUN_004934c0 path record (memset 0x115c, / to \\)', 'thiscall', None, ret='eax', gen=g_4934c0)
S(0x64d400, 'FUN_0064d400 register resource once (table by id & 0xfff)', 'thiscall', None, ret='al', gen=g_64d400)
S(0x650c40, 'FUN_00650c40 snap point to pixel grid', 'thiscall', None, ret=None, gen=g_650c40)
