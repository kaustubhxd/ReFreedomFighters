"""specs_f0119.py - fresh-01 batch 19 (docs/20-fresh-01.md)."""
from pilot import S
from helpers01 import rnd, hk, obj


def _handler(c):
    def hnd(e, r):
        e.calllog.append(('handler',))
        e.ret(eax=0xbad)
    c.emu.w32(0x7003b0, c.emu.stub_fn('handler', hnd))


def _logmgr(c, n):
    def s2c(e, r):
        e.calllog.append(('log',) + tuple(e.arg32(k) for k in range(n)))
        e.ret(eax=0x10910000)
    o = rnd(c, 0x20)
    c.emu.w32(o, c.emu.fake_vtable('logger', 0x10, {0x2c: s2c}))
    c.emu.w32(0x700390, obj(c, 0x20, 'mgr', 0x10, {0x20: lambda e, a: (o, None)}, {0x20: 2}))


def _memcpy(c):
    def mc(e, r):
        d, s_, n = e.arg32(0), e.arg32(1), e.arg32(2)
        e.calllog.append(('memcpy', d, s_, n))
        e.wbytes(d, e.rbytes(s_, n))
        e.ret(eax=d)
    c.emu.stub_import('VCRUNTIME140.dll!memcpy', mc)


def _flush(c):
    _memcpy(c)
    win = rnd(c, 0x100)
    end = win + c.rng.choice([0x40, 0x80, 0x100])
    rd = win + c.rng.randint(0, end - win)
    wr = c.rng.choice([win + c.rng.randint(0, end - win), end, rd])
    s = rnd(c, 0x40)
    for o, v in ((0x28, win), (0x2c, end), (0x30, rd), (0x34, wr)):
        c.emu.w32(s + o, v)
    if c.rng.random() < 0.5:
        c.emu.w32(s + 0x38, 0)
    else:
        def ck(e, r):
            a, q, n = e.arg32(0), e.arg32(1), e.arg32(2)
            e.calllog.append(('check', a, q, n))
            e.ret(eax=(a * 31 + n + (q & 0xffff)) & 0xffffffff, argbytes=12)   # stdcall (adler32)
        c.emu.w32(s + 0x38, c.emu.stub_fn('checkfn', ck))
    z = rnd(c, 0x38)
    out = rnd(c, 0x200)
    c.emu.w32(z + 0xc, out)
    c.emu.w32(z + 0x10, c.rng.choice([0, 1, 0x10, 0x40, 0x200]))
    return [s, z, c.rng.choice([-5 & 0xffffffff, 0, 1, -3 & 0xffffffff])]


def _geom(c):
    self_ = rnd(c, 0x50)
    cnt = c.rng.choice([0, 1, 3, 6])
    tbl = rnd(c, 12 * cnt + 4)
    subs = rnd(c, 8 * 24)
    keys = [c.rng.getrandbits(32) for _ in range(cnt)]
    for k in range(cnt):
        c.emu.w32(tbl + 12 * k, keys[k])
        c.emu.w32(tbl + 12 * k + 4, c.rng.randint(0, 20))
        c.emu.w32(tbl + 12 * k + 8, c.rng.randint(0, 4))
    skeys = [c.rng.getrandbits(32) for _ in range(5)]
    for k in range(24):
        c.emu.w32(subs + 8 * k, c.rng.choice(skeys))
        c.emu.w32(subs + 8 * k + 4, c.rng.choice([0, 1, 3]))
    c.emu.w32(self_ + 0x40, tbl)
    c.emu.w32(self_ + 0x44, subs)
    c.emu.w32(self_ + 0x48, cnt)
    g = rnd(c, 0x60)
    c.emu.w32(self_, c.emu.logging_vtable('gb', 8, {0xc: lambda e, a: (g, None)}, {0: 3}))
    _logmgr(c, 4)
    a = c.rng.choice(keys + [c.rng.getrandbits(32)]) if keys else c.rng.getrandbits(32)
    return [self_, c.rng.getrandbits(32), a, c.rng.choice(skeys)]


def _str(c):
    self_ = rnd(c, 0x1b60)
    pool = c.emu.alloc(0xa020, 4) + 0x10        # room in front: a failed Alloc (-1, -2) still writes at pool + off
    if c.rng.random() < 0.4:
        c.emu.w32(self_ + 0x1b55, 0)
    else:
        c.emu.w32(self_ + 0x1b55, pool)
        c.emu.w32(self_ + 0x1b51, rnd(c, 0x10))
    oa = rnd(c, 0x10)
    newp = 0 if c.rng.random() < 0.1 else rnd(c, 0x10)
    hk(c, 0x41e290, 'new', 1, eax=lambda e: pool if e.arg32(0) == 0xa000 else newp, regs=(), pop=False)

    def ms(e, r):
        d, v, n = e.arg32(0), e.arg32(1), e.arg32(2)
        e.calllog.append(('memset', d, v, n))
        e.wbytes(d, bytes([v & 0xff]) * n)
        e.ret(eax=d)
    c.emu.stub_import('VCRUNTIME140.dll!memset', ms)
    hk(c, 0x4ccdd0, 'ZOffsetAlloc ctor', 3, eax=oa)
    off = c.rng.choice([0, 0x10, 0x800, 0x9000, -1 & 0xffffffff, -2 & 0xffffffff])
    hk(c, 0x4cd9b0, 'Alloc', 2, eax=off)
    _logmgr(c, 2)
    _handler(c)
    ln = c.rng.choice([0, 1, 2, 7, 100, 0xfffc, 0x1234fff, c.rng.getrandbits(32)])
    if (off >= 0x9000 or off >= 0x80000000) and (ln + 4) & 0xfffe > 0x1000:
        ln = 100
    return [self_, ln]


S(0x6331d0, 'inflate_flush', 'cdecl', None, ret='eax', gen=_flush)
S(0x495fd0, 'ZGeomBuffer::AllocResourceGeom', 'thiscall', None, ret='eax', gen=_geom)
S(0x42bf90, 'ZSysInterface::AllocString', 'thiscall', None, ret='eax', gen=_str)
