"""f16help.py - extra input builders for the fresh slice 16 specs."""
import struct
from sthelp import rnd, obj, stub, Seq, clear_hooks, sysobj, HOOKED, hook


def phook(c, seq, addr, nargs, ret=0, this=False, pop=False, act=None):
    """Python recorder at exe or heap address `addr`: records ECX (if this), args, count, sequence number on the heap.
    act(e, args) may write through pointer args (and returns an optional override for eax)."""
    rec = c.emu.alloc(4 * (nargs + 3), 4)

    def h(e, r):
        sp = e.reg('esp')
        args = [e.r32(sp + 4 + 4 * i) for i in range(nargs)]
        if this:
            e.w32(rec, e.reg('ecx'))
        for i, v in enumerate(args):
            # stack addresses differ between the two sides: record a marker instead
            e.w32(rec + 4 + 4 * i, 0x5c5c0000 if 0x0fe00000 <= v < 0x0ff00000 else v)
        e.w32(rec + 4 + 4 * nargs, e.r32(rec + 4 + 4 * nargs) + 1)
        n = e.r32(seq.addr) + 1
        e.w32(seq.addr, n)
        e.w32(rec + 8 + 4 * nargs, n)
        rv = ret(e) if callable(ret) else ret
        if act:
            o = act(e, args)
            if o is not None:
                rv = o
        e.ret(eax=rv, argbytes=4 * nargs if pop else 0)
    HOOKED.add(addr)
    c.emu.hook(addr, h)
    return rec


def codeaddr(c):
    """A heap address holding `ret` that can carry a Python hook (a fake function pointer)."""
    a = c.emu.alloc(16, 16)
    c.emu.wbytes(a, b'\xc3' * 16)
    return a


def crt(c):
    """Python memset/memcpy/memmove for the VCRUNTIME imports (cdecl, return dest)."""
    e0 = c.emu

    def ms(e, r):
        d, v, n = e.arg32(0), e.arg32(1), e.arg32(2)
        if n:
            e.wbytes(d, bytes([v & 0xff]) * n)
        e.ret(eax=d)

    def mc(e, r):
        d, s, n = e.arg32(0), e.arg32(1), e.arg32(2)
        if n:
            e.wbytes(d, bytes(e.rbytes(s, n)))
        e.ret(eax=d)
    for nm, h in (('memset', ms), ('memcpy', mc), ('memmove', mc)):
        try:
            e0.stub_import(nm, h)
        except KeyError:
            pass


def reporter(c, seq):
    """[0x700390] error-report object: slot 0x20(file, line) thiscall pop 8 returns t; t slot 0x2c(t, msg) cdecl."""
    t = obj(c, 0x40, {0x2c: stub(c, seq, 2, pop=False)})
    o = obj(c, 0x40, {0x20: stub(c, seq, 2, ret=t)})
    c.emu.w32(0x700390, o)
    return o


def fval(c):
    r = c.rng
    k = r.random()
    if k < 0.15:
        return r.choice([0, 0x80000000, 0x7fc00000, 0x3f800000, 0xff800000])
    return r.getrandbits(32)


def loghook(c, seq, addr, nargs, ret=0, this=False, pop=False, calls=6):
    """Python recorder that logs EVERY call in its own slot (ECX if this, args, sequence number), so a callee called
    several times is compared call by call. Stack addresses are replaced by a marker."""
    rec = c.emu.alloc(4 * (nargs + 2) * calls + 4, 4)
    cnt = [0]

    def h(e, r):
        sp = e.reg('esp')
        k = cnt[0]
        cnt[0] += 1
        e.w32(rec, cnt[0])
        if k < calls:
            base = rec + 4 + 4 * (nargs + 2) * k
            if this:
                e.w32(base, e.reg('ecx'))
            for i in range(nargs):
                v = e.r32(sp + 4 + 4 * i)
                e.w32(base + 4 + 4 * i, 0x5c5c0000 if 0x0fe00000 <= v < 0x0ff00000 else v)
            n = e.r32(seq.addr) + 1
            e.w32(seq.addr, n)
            e.w32(base + 4 + 4 * nargs, n)
        rv = ret(e) if callable(ret) else ret
        e.ret(eax=rv, argbytes=4 * nargs if pop else 0)
    HOOKED.add(addr)
    c.emu.hook(addr, h)
    return rec
