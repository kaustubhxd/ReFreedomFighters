"""specs_s706.py - soldier AI batch 706: CCheckVisible::FrameUpdate (0x4a9fe0).
World: engine with a logging vtable (profiling timer 0x1c8 returning edx:eax, begin 0x178 / end 0x17c), tick, geom
database (every lookup builds a fresh fake geom: +8 info block whose +0x3c bit 10 is the 'inactive' flag, CheckSight
0x690 and ReducedSight 0x444 random, bone/position slots from specs_s705), scene object at db+0xadc (0x218 debug line
-> handle, 0x220 remove line, 0x2e0 ray test logging the COLI fields that are set), the debug-line list at +0x15e5c
(iterator protocol 0x4c/0x5c, clear 0x0c, add 0x04). Stack buffers passed to stubs are logged by content only."""
import math
import struct
from pilot import S, f32
from specs_s701 import _rnd
from specs_s702 import _inv
from specs_s705 import geom_fake, _bool

CV_SIZE = 0x16000


def _f(v):
    return struct.pack('<f', f32(v))


def _world706(c):
    e = c.emu
    rd = lambda a, n: tuple(struct.unpack('<%dI' % n, e.rbytes(a, 4 * n)))
    log = lambda name, off, args: e.calllog.append((name, off, e.reg('ecx'), args))
    now = c.rng.choice([c.rng.randint(0, 2000000), c.rng.randint(-2**31, 2**31 - 1), 100000])

    def timer(em, r):
        log('engine', 0x1c8, (em.arg32(0), em.arg32(1)))
        em.mu.reg_write(pe_edx(), c.rng.getrandbits(32))
        em.ret(eax=c.rng.getrandbits(32), argbytes=8)

    def prof(off):
        def h(em, r):
            log('engine', off, (em.arg32(0), em.arg32(1), em.arg32(2)))
            em.ret(eax=0, argbytes=12)
        return h
    eng = _rnd(c, 0xa00)
    e.w32(eng, e.fake_vtable('engine', 0x80, {0x1c8: timer, 0x178: prof(0x178), 0x17c: prof(0x17c)}))
    e.w32(eng + 0x40, now)
    prof_on = c.rng.random() < 0.3
    e.wbytes(eng + 0x9c3, _f(c.rng.choice([1.0, 0.5]) if prof_on else c.rng.choice([0.0, 1.0])))
    e.wbytes(eng + 0x9c7, _f(c.rng.choice([1.0, math.nan]) if prof_on else 0.0))
    e.w32(0x70039c, eng)

    p_inactive = c.rng.choice([0.0, 0.1, 0.5])
    vtcache = []

    def lookup(em, r):
        ref = em.arg32(0)
        log('geomdb', 0x58, (ref,))
        info = _rnd(c, 0x40)
        w = struct.unpack('<I', em.rbytes(info + 0x3c, 4))[0] & ~0x400
        if c.rng.random() < p_inactive:
            w |= 0x400
        em.w32(info + 0x3c, w)

        def cs(em2, r2):
            log('geom', 0x690, ())
            em2.ret(eax=_bool(c), argbytes=0)

        def rs(em2, r2):
            log('geom', 0x444, (em2.arg32(0),))
            em2.ret(eax=_bool(c), argbytes=4)
        if not vtcache:
            g = geom_fake(c, {0x690: cs, 0x444: rs})
            vtcache.append(em.r32(g))
        else:
            g = _rnd(c, 64)
            em.w32(g, vtcache[0])
        em.w32(g + 8, info)
        em.ret(eax=g, argbytes=4)
    db = _rnd(c, 0xb00)
    e.w32(db, e.fake_vtable('geomdb', 32, {0x58: lookup}))
    e.wbytes(eng + 0x9b, struct.pack('<I', db))

    def line(em, r):
        a, b, col = em.arg32(0), em.arg32(1), em.arg32(2)
        log('scene', 0x218, rd(a, 3) + rd(b, 3) + (col,))
        em.ret(eax=c.rng.getrandbits(32), argbytes=12)

    def unline(em, r):
        log('scene', 0x220, (em.arg32(0),))
        em.ret(eax=0, argbytes=4)

    def ray(em, r):
        p = em.arg32(0)
        args = tuple(em.arg32(k) for k in range(1, 6))
        log('scene', 0x2e0, rd(p, 6) + rd(p + 0x34, 1) + rd(p + 0x44, 1) + (em.r8(p + 0x6c),) + args)
        em.ret(eax=_bool(c), argbytes=24)
    sc = _rnd(c, 32)
    e.w32(sc, e.fake_vtable('scene', 0xc0, {0x218: line, 0x220: unline, 0x2e0: ray}))
    e.wbytes(db + 0xadc, struct.pack('<I', sc))

    # debug logger (update-took warning: cdecl (log, fmt, int))
    logobj = _rnd(c, 16)

    def printf(em, r):
        em.calllog.append(('log.printf', 0x2c, None, tuple(em.arg32(k) for k in range(3))))
        em.ret(eax=0, argbytes=0)
    e.w32(logobj, e.fake_vtable('log', 16, {0x2c: printf}))
    lg = _rnd(c, 16)
    e.w32(lg, e.logging_vtable('logger', 16, impl={0x20: lambda em, a: (logobj, None)}, argwords={0x20: 2}))
    e.w32(0x700390, lg)
    c.rng.random()   # inline-wireai 2026-10-13: the hook is always set (a null hook makes both builds stop at int3: faulting cases)
    e.w32(0x7003b0, e.stub_fn('assert', lambda em, r: (em.calllog.append(('assert', 0, None, ())), em.ret(eax=0))))
    e.w32(0x700330, (now - c.rng.choice([0, 0x800, 0x801, 5000, c.rng.randint(0, 0x1000)])) & 0xffffffff)
    e.wbytes(0x700328, _f(c.rng.choice([0.0, 1.0, 1.0, math.nan])))
    _inv(c)
    return now


def _list(c, lst):
    e = c.emu
    n = [c.rng.choice([0, 0, 1, 3])]

    def first(em, r):
        em.calllog.append(('list', 0x4c, em.reg('ecx'), ()))
        em.wbytes(em.arg32(0), b'\0' * 12)
        em.ret(eax=0, argbytes=4)

    def nxt(em, r):
        it = em.arg32(0)
        if n[0] > 0:
            n[0] -= 1
            em.w32(it, 1)
            em.ret(eax=c.rng.getrandbits(32), argbytes=4)
        else:
            em.w32(it, 0)
            em.ret(eax=c.rng.getrandbits(32), argbytes=4)
    vt = e.logging_vtable('linelist', 0x20, impl={}, argwords={4: 1})
    # replace the iterator slots with ones that write through the iterator pointer
    e.w32(vt + 0x4c, e.stub_fn('list.first', first))
    e.w32(vt + 0x5c, e.stub_fn('list.next', nxt))
    e.w32(lst, vt)


def _fv(c, lo, hi):
    r = c.rng.random()
    if r < 0.05:
        return c.rng.choice([0.0, math.nan, math.inf, -1.0])
    return c.rng.uniform(lo, hi)


def _memset(em, r):     # VCRUNTIME140!memset (cdecl): plain byte fill, returns dst
    dst, val, n = em.arg32(0), em.arg32(1) & 0xff, em.arg32(2)
    em.wbytes(dst, bytes([val]) * n)
    em.ret(eax=dst, argbytes=0)


def _fu(c):
    e = c.emu
    e.stub_import('memset', _memset)
    now = _world706(c)
    cv = _rnd(c, CV_SIZE)
    disp = _rnd(c, 16)
    e.w32(disp, e.logging_vtable('dispatch', 0x50, argwords={0x12c: 3}))
    e.w32(cv + 0x44, disp)
    _list(c, cv + 0x15e5c)
    e.w32(cv + 0x15e58, c.rng.choice([0, 200, 199, 190, c.rng.randrange(201)]))
    e.w32(cv + 0x15e54, c.rng.choice([0, 0, 200, 199, c.rng.randrange(201)]))
    e.wbytes(cv + 0x15e78, _f(c.rng.choice([1.0, 1.0, 0.5, 2.0, _fv(c, 0, 3)])))
    p_empty = c.rng.choice([0.0, 0.3, 0.9])
    tmax = c.rng.choice([3, 60, 0x3fff])
    for k in range(200):
        s = cv + 0x694 + k * 0x1b8
        if c.rng.random() < p_empty:
            e.w32(s, 0)
        e.wbytes(s + 4, _f(_fv(c, 50, 400) if c.rng.random() < 0.98 else -1e7) + _f(_fv(c, -1, 1)))
        e.wbytes(s + 0x1c, struct.pack('<I', c.rng.getrandbits(3)))
        e.w32(s + 0x20, (now - c.rng.choice([0, 1, 17, 18, 100, 5000, c.rng.randint(-100, 3000)])) & 0xffffffff)
        e.wbytes(s + 0x24, _f(c.rng.choice([0.0, 0.5, 0.99, c.rng.random()])))
        words = [(c.rng.choice([0, 0x4000, 0x8000, 0xc000, 0xc000, 0x8000]) | c.rng.randint(0, tmax)) for _ in range(200)]
        e.wbytes(s + 0x28, struct.pack('<200H', *words))
    return [cv]


def pe_edx():
    from unicorn.x86_const import UC_X86_REG_EDX
    return UC_X86_REG_EDX


S(0x4a9fe0, 'CCheckVisible::FrameUpdate', 'thiscall', None, ret=None, gen=_fu,
  note='b706 [high]; helpers 0x4aabe0/0x4aaa50/0x4ab920/0x4ab8e0, vnorm, PSVECSubtract, COLI ctor and memset run as exe code')
