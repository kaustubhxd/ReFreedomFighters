"""iter66.py - shared list iterator stub (area 66), for specs whose exe code walks a list with the iterator protocol.

Protocol (read from GetActiveActions, 0x438f50, and PositionAllTrains, 0x5b9050; the loop back edge calls the same slot
again and tests the flag):
  - vtable +0x4c(flag*): begin. Resets the cursor to the first element. Writes the flag to 1 when the list is non-empty.
    Returns 0 in EAX (the caller does not use it).
  - vtable +0x5c(flag*): next. Returns the next element in EAX and writes the flag: 1 when an element was returned, 0 when
    the list is exhausted (EAX = 0).
The list object: dword 0 = vtable, +4 = cursor, +8 = count, +0xc = pointer to the element array (dwords).
Stubs log (name, slot, list address, value written to the flag). The flag itself is a stack address, so it is not logged.

Stubs (unverified against the list class itself): this file is the harness model of the protocol. Use make_list() for the
list objects and a spec's own stubs for the element bodies.
"""
import struct


def _slot(name, off, impl):
    def h(e, r):
        obj = e.reg('ecx')
        flag = e.arg32(0)
        eax, flagval = impl(e, obj, flag)
        e.calllog.append((name, off, obj, (flagval,)))
        e.ret(eax=eax, argbytes=4)
    return h


def _begin(e, obj, flag):
    n = e.r32(obj + 8)
    e.w32(obj + 4, 0)
    v = 1 if n > 0 else 0
    e.w32(flag, v)
    return 0, v


def _next(e, obj, flag):
    idx = e.r32(obj + 4)
    n = e.r32(obj + 8)
    if idx < n:
        arr = e.r32(obj + 0xc)
        elem = e.r32(arr + 4 * idx)
        e.w32(obj + 4, idx + 1)
        e.w32(flag, 1)
        return elem, 1
    e.w32(flag, 0)
    return 0, 0


def make_list(c, elems):
    """A list object (vtable with the two protocol slots) holding the given element pointers. Returns its address."""
    e = c.emu
    n = len(elems)
    arr = e.alloc(4 * max(n, 1) + 4, 4)
    for i, p in enumerate(elems):
        e.w32(arr + 4 * i, p)
    vt = e.fake_vtable('iter list', 0x60 // 4 + 1, slots={
        0x4c: _slot('list begin (iter stub)', 0x4c, _begin),
        0x5c: _slot('list next (iter stub)', 0x5c, _next)})
    obj = e.alloc(0x40, 4)
    e.w32(obj, vt)
    e.w32(obj + 4, 0)
    e.w32(obj + 8, n)
    e.w32(obj + 0xc, arr)
    return obj
