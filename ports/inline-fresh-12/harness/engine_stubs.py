"""engine_stubs.py - shared helpers for specs that need an engine object model (unclaimed-05, usable by any area).

    zero_obj(c, n)                 zeroed block on the fake heap (random bytes fault in many exe helpers)
    logged_obj(c, name, nslots, impl, argwords)
                                   object whose first word is a logging vtable; impl maps a byte offset to
                                   fn(emu, args) -> (eax, st0); argwords maps the offset to its stack-argument count
    set_global(c, addr, obj)       write obj into a global pointer of the exe image (e.g. 0x70039c)
    fvals(values)                  a closure that returns the given float values in call order (ST0 results)
Keep every helper deterministic: the original and the port must see the same values in the same order.
"""
import struct


def zero_obj(c, n=0x800):
    a = c.emu.alloc(n, 16)
    c.emu.wbytes(a, bytes(n))
    return a


def logged_obj(c, name, nslots, impl=None, argwords=None):
    o = zero_obj(c, 0x400)
    vt = c.emu.logging_vtable(name, nslots, impl=impl or {}, argwords=argwords or {})
    c.emu.w32(o, vt)
    return o


def set_global(c, addr, obj):
    c.emu.w32(addr, obj)


def fvals(values):
    it = iter(values)
    return lambda e, a: (None, next(it))


def pvals(values):
    it = iter(values)
    return lambda e, a: (next(it), None)
