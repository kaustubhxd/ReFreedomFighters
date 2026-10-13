"""fr13.py - helpers for the fresh-13 specs: a per-call sequence log (every call into a logged stub or hook appends
(id, ecx, args...) to one heap log, so order, count and arguments of every call are compared)."""
import struct
from sthelp import rnd, HOOKED, clear_hooks  # noqa: F401


class Log:
    def __init__(self, c, cap=256, width=6):
        self.c, self.width, self.cap = c, width, cap
        self.base = c.emu.alloc(4 + 4 * width * cap, 4)
        c.emu.wbytes(self.base, bytes(4 + 4 * width * cap))

    def put(self, e, vals):
        n = e.r32(self.base)
        if n < self.cap:
            for i, v in enumerate(vals[:self.width]):
                e.w32(self.base + 4 + 4 * (self.width * n + i), v & 0xffffffff)
        e.w32(self.base, n + 1)


def loghook(c, log, addr, nargs, tag, ret=0, this=True, pop=True, deref=None):
    """Replace exe code at `addr` with a Python recorder that logs (tag, ecx, args) and pops nargs dwords.
    deref = {argidx: nwords}: that argument is a pointer (often to the caller's stack); the words it points at are
    logged in its place (so stack addresses never reach the log)."""
    def h(e, r):
        sp = e.reg('esp')
        vals = [tag, e.reg('ecx') if this else 0]
        for i in range(nargs):
            v = e.r32(sp + 4 + 4 * i)
            if deref and i in deref:
                vals += [e.r32(v + 4 * k) for k in range(deref[i])]
            else:
                vals.append(v)
        log.put(e, vals)
        e.ret(eax=ret(e) if callable(ret) else ret, argbytes=4 * nargs if pop else 0)
    HOOKED.add(addr)
    c.emu.hook(addr, h)


def logstub(c, log, nargs, tag, ret=0, this=True, pop=True, deref=None):
    """A heap address (for a vtable slot or a global function pointer) whose code is hooked to log like loghook."""
    a = c.emu.alloc(16, 16)
    c.emu.wbytes(a, b'\xc3' * 16)
    loghook(c, log, a, nargs, tag, ret=ret, this=this, pop=pop, deref=deref)
    return a


def flush(c):
    c.emu.mu.ctl_flush_tb()


def vobj(c, size, slots):
    """Random object of `size` bytes with a fresh vtable; slots = {offset: code address}."""
    o = rnd(c, size)
    vt = c.emu.alloc(max(list(slots) + [0]) + 8, 4)
    for off, a in slots.items():
        c.emu.w32(vt + off, a)
    c.emu.w32(o, vt)
    return o


def crt_memset(c):
    """The CRT memset import (VCRUNTIME140) as a real memset (cdecl, returns dest)."""
    def h(e, r):
        sp = e.reg('esp')
        d, v, n = e.r32(sp + 4), e.r32(sp + 8) & 0xff, e.r32(sp + 12)
        if n:
            e.wbytes(d, bytes([v]) * n)
        e.ret(eax=d)
    c.emu.stub_import('memset', h)


def crt_memmove(c):
    """The CRT memmove import as a real memmove (cdecl, returns dest)."""
    def h(e, r):
        sp = e.reg('esp')
        d, s, n = e.r32(sp + 4), e.r32(sp + 8), e.r32(sp + 12)
        if n:
            e.wbytes(d, bytes(e.mu.mem_read(s, n)))
        e.ret(eax=d)
    c.emu.stub_import('memmove', h)
