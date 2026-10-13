"""specs_c124.py - climb thread batch 124: 16-byte vector push_back (0x5acbf0) and insert-with-growth (0x5acad0)."""
import struct
from pilot import S
from ckit import rnd, cstr


def _allocfake(e, r):
    n = e.arg32(0)
    e.calllog.append(('alloc', n))
    e.ret(eax=e.alloc(max(16, n), 16), argbytes=4)   # cdecl-like one-arg, ret 4 (callee pops)


def _dealloc(e, r):
    e.calllog.append(('free', e.arg32(0), e.arg32(1)))
    e.ret(argbytes=8)


def _vec(c, insert):
    r = c.rng
    e = c.emu
    e.hook(0x6014a0, _allocfake)
    e.hook(0x54f870, _dealloc)
    v = rnd(c, 0x20)
    n = r.choice([0, 1, 2, 3, 4])            # elements
    cap_n = n + r.choice([0, 0, 1, 2])       # spare slots
    begin = e.alloc(16 * max(cap_n, 1), 16) if cap_n else 0
    for k in range(n):
        e.wbytes(begin + 16 * k, bytes(r.getrandbits(8) for _ in range(16)))
    e.w32(v, begin)
    e.w32(v + 4, begin + 16 * n if begin else 0)
    e.w32(v + 8, begin + 16 * cap_n if begin else 0)
    if insert:
        pos_idx = r.randint(0, n)
        pos = begin + 16 * pos_idx if begin else 0
        if not begin:
            pos = 0
    else:
        pos = 0
    val = e.alloc(16, 16)
    e.wbytes(val, bytes(r.getrandbits(8) for _ in range(16)))
    return [v, pos, val] if insert else [v, val]


S(0x5acad0, 'vector insert with growth (GUESS, no GC match)', 'thiscall', None, ret=None,
  gen=lambda c: _vec(c, True), note='c124; allocator and free are hooks; the vector shape is a guess from the code')
S(0x5acbf0, 'vector push_back (GUESS, no GC match)', 'thiscall', None, ret=None,
  gen=lambda c: _vec(c, False), note='c124; allocator and free are hooks')
