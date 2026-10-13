"""specs_s1204.py - fresh slice 12, batch 4 (9 functions). Exe callees hooked by address and logged. Calls that take a
pointer to a stack local log the pointed-to value, never the stack address. CRT ceil (0x634da6) and memset
(0x634d10) are hooked with Python versions (memset writes the bytes, so its effect is compared)."""
import math
import struct
from pilot import S
from engine_stubs import zero_obj, logged_obj, set_global
from helpers12 import rand_obj, rand_fast, hk, hk_cdecl, done, com_obj, fail_stub


def vt_obj(c, name, slots, size=0x40, nslots=0x100):
    """Object with a fake vtable; slots maps byte offset -> handler(em, r) that must call em.ret itself."""
    o = zero_obj(c, size)
    c.emu.w32(o, c.emu.fake_vtable(name, nslots, slots))
    return o


def _g5bc680(c):
    idv = c.rng.getrandbits(32)

    def s88(em, r):
        p = em.arg32(1)
        em.calllog.append(('M', 0x88, em.reg('ecx'), (em.arg32(0), em.r32(p))))
        em.w32(p, idv)
        em.ret(eax=0x88, argbytes=8)
    m = vt_obj(c, 'M', {0x88: s88})
    h = c.rng.getrandbits(32)
    en = logged_obj(c, 'Eng', 0x60, impl={0x138: lambda e, a: (m, None), 0x58: lambda e, a: (h ^ a[0], None)},
                    argwords={0x58: 1})
    eng = zero_obj(c, 0x100)
    c.emu.w32(eng + 0x9b, en)
    set_global(c, 0x70039c, eng)
    return done(c, [rand_obj(c, 0x60)])


S(0x5bc680, 'FUN_005bc680 look up id 0x6ac89c and store handle', 'thiscall', None, ret='eax', gen=_g5bc680)


def _memset(em, r):
    p, v, n = em.arg32(0), em.arg32(1), em.arg32(2)
    em.calllog.append(('memset', 0, 0, (p, v, n)))
    if n:
        em.wbytes(p, bytes([v & 0xff]) * n)
    em.ret(eax=p, argbytes=0)


def _g655c40(c):
    c.emu.hook(0x634d10, _memset)
    n = c.rng.choice([0, 0, 1, 2, 5, 16])
    buf = rand_obj(c, 8 * 16 + 8)
    a = logged_obj(c, 'Alloc', 0x10, impl={0x14: lambda e, ar: (buf, None)}, argwords={0x14: 1})
    h = logged_obj(c, 'Heap', 0x10, impl={0x20: lambda e, ar: (a, None)})
    eng = zero_obj(c, 0x1a00)
    c.emu.w32(eng + 0x190f, h)
    set_global(c, 0x70039c, eng)
    return done(c, [rand_obj(c, 0x10), n | (c.rng.choice([0, 0x20000000, 0x40000000]) if n == 0 else 0)])


S(0x655c40, 'FUN_00655c40 alloc n*8 zeroed', 'thiscall', None, ret='eax', gen=_g655c40)


def _g560380(c):
    fail_stub(c, c.rng.getrandbits(32))
    cnt = c.rng.choice([0, 1, 4, 8])
    c.emu.w32(0x714198, cnt)
    for i in range(8):
        def hh(em, r, i=i):
            em.calllog.append(('handler', i, em.reg('ecx'), (em.arg32(0),)))
            em.ret(eax=0x4400 + i, argbytes=4)
        c.emu.w32(0x7141a0 + 4 * i, c.emu.stub_fn('h%d' % i, hh))
    pr = com_obj(c, 'Printer', 0x10, argwords={0x2c: 3}, callee_pops=False)
    log = logged_obj(c, 'Log', 0x10, impl={0x20: lambda e, a: (pr, None)}, argwords={0x20: 2})
    set_global(c, 0x700390, log)
    msg = rand_obj(c, 0x20)
    c.emu.wbytes(msg + 0x10, struct.pack('<H', c.rng.choice([0, 1, 3, 7, 8, 0xffff])))
    return done(c, [rand_obj(c, 0x10), msg])


S(0x560380, 'FUN_00560380 message dispatch through table 0x7141a0', 'thiscall', None, ret='eax', gen=_g560380)


def _s4f4400(c):
    c.emu.hook(0x634273, hk_cdecl(0x634273, 'delete_sized', 2))
    c.emu.hook(0x45c510, hk_cdecl(0x45c510, 'delete_wrap', 1))
    c.emu.hook(0x4690b0, hk_cdecl(0x4690b0, 'delete_sized2', 2))
    c.emu.hook(0x4ee440, hk(0x4ee440, 'base_dtor', 0))


def _g4f4400(c):
    o = rand_obj(c, 0xb4)
    if c.rng.random() < 0.3:
        c.emu.w32(o + 0xac, 0)
    return done(c, [o, c.rng.getrandbits(32)])


S(0x4f4400, 'FUN_004f4400 deleting dtor (vt 0x699664, size 0xb4)', 'thiscall', None, ret='eax', setup=_s4f4400,
  gen=_g4f4400)


def _ceil(em, r):
    lo, hi = em.arg32(0), em.arg32(1)
    x = struct.unpack('<d', struct.pack('<II', lo, hi))[0]
    em.calllog.append(('ceil', 0, 0, (lo, hi)))
    try:
        y = float(math.ceil(x))
    except (ValueError, OverflowError):
        y = x
    if y == 0.0 and math.copysign(1.0, x) < 0:
        y = -0.0
    em.ret(st0=y, argbytes=0)


def _g4f74c0(c):
    c.emu.hook(0x634da6, _ceil)
    o = logged_obj(c, 'Obj', 0x100, argwords={0x358: 1})
    x = c.fv(-50.0, 50.0)
    old = c.rng.choice([float(math.ceil(x)) if math.isfinite(x) else 0.0, c.fv(-50.0, 50.0), float('nan')])
    c.emu.wbytes(o + 0xa3, struct.pack('<f', old))
    return done(c, [o, struct.unpack('<I', struct.pack('<f', x))[0], c.rng.getrandbits(32)])


S(0x4f74c0, 'FUN_004f74c0 set ceil(x) and notify slot 0x358 on change', 'thiscall', None, ret=None, gen=_g4f74c0,
  note='ceil hooked (Python math.ceil)')


def _g4ee640(c):
    o = rand_obj(c, 0x24)
    c.emu.w8(o + 0x20, c.rng.choice([0, 1, 2, 4, 6, 8, 0xc, 0x10, c.rng.getrandbits(8)]))
    n = c.rng.choice([0, 1, 2, 3, 5])
    base = rand_fast(c, 40 * 6)
    for k in range(6):
        c.emu.wbytes(base + 40 * k, struct.pack('<f', c.fv(-100.0, 100.0)))
    p = base + 40 * n
    x = c.rng.choice([c.rng.randrange(-100, 100), c.rng.getrandbits(32)])
    return done(c, [o, x & 0xffffffff, n, p])


S(0x4ee640, 'FUN_004ee640 shift n records before p by x', 'thiscall', None, ret=None, gen=_g4ee640)


def _g5fb600(c):
    c.emu.hook(0x54f870, hk(0x54f870, 'free_node', 2))
    o = rand_obj(c, 0x14)
    nb = c.rng.choice([0, 1, 3, 5])
    arr = zero_obj(c, 4 * nb + 4)
    for b in range(nb):
        prev = 0
        for k in range(c.rng.choice([0, 1, 2, 3])):
            n = rand_obj(c, 8)
            c.emu.w32(n, prev)
            prev = n
        c.emu.w32(arr + 4 * b, prev)
    c.emu.w32(o + 3, arr)
    c.emu.w32(o + 7, arr + 4 * nb)
    return done(c, [o])


S(0x5fb600, 'FUN_005fb600 clear hash buckets', 'thiscall', None, ret=None, gen=_g5fb600)


def _g499c80(c):
    def s10(em, r):
        p, n = em.arg32(0), em.arg32(1)
        em.calllog.append(('Stream', 0x10, em.reg('ecx'), (n, bytes(em.rbytes(p, min(n, 64))))))
        em.ret(eax=n, argbytes=8)
    o = vt_obj(c, 'Stream', {0x10: s10})
    if c.rng.random() < 0.25:
        s = 0
    else:
        L = c.rng.choice([0, 1, 5, 20])
        s = c.emu.alloc(L + 1, 1)
        c.emu.wbytes(s, bytes(c.rng.randrange(1, 256) for _ in range(L)) + b'\0')
    return done(c, [o, s])


S(0x499c80, 'FUN_00499c80 write length-prefixed string', 'thiscall', None, ret='eax', gen=_g499c80)


def _g64c780(c):
    fail_stub(c, c.rng.getrandbits(32))
    x = c.rng.choice([0, 1, 0x7ff, 0x800, 0x801, 0x1234, c.rng.getrandbits(32)])
    y = x if x < 0x800 else (x - 0x800) & 0xffffffff
    cell = zero_obj(c, 4)
    c.emu.wbytes(cell, struct.pack('<H', (y if c.rng.random() < 0.5 else c.rng.getrandbits(16)) & 0xffff))
    mgr = logged_obj(c, 'Mgr', 0x40, impl={0x80: lambda e, a: (cell if a[0] == x else 0x8080 ^ a[0], None)},
                     argwords={0x80: 1})
    eng = zero_obj(c, 0x1b00)
    c.emu.w32(eng + 0x1aa3, mgr)
    set_global(c, 0x70039c, eng)
    return done(c, [rand_obj(c, 0x10), x])


S(0x64c780, 'FUN_0064c780 check id then mgr slot 0x80', 'thiscall', None, ret='eax', gen=_g64c780)
