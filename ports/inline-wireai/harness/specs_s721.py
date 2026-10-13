"""specs_s721.py - soldier AI batch 721: CFFCoverList spot-vector insert (0x588750, middle 0x5885c0) and reserve (0x5887e0).
The vector is a 12-byte {begin, end, cap} object on the heap; its records are 0x48-byte random blocks in heap buffers.
Allocation (0x6014a0, thiscall ret 4) and release (0x54f870, thiscall ret 8) are hooked: alloc returns fresh heap memory,
release logs its size. The copy routines 0x5853a0 and 0x5852f0 run as exe code."""
import struct
from pilot import S
from specs_s701 import _rnd
from specs_s709 import _log_world


def _alloc_hooks(c):
    e = c.emu
    e.hook(0x6014a0, lambda em, r: (em.calllog.append(('alloc', 0, None, (em.arg32(0),))), em.ret(eax=_rnd(c, max(em.arg32(0), 16)), argbytes=4)))
    e.hook(0x54f870, lambda em, r: (em.calllog.append(('free', 0, None, (em.arg32(0), em.arg32(1)))), em.ret(eax=0, argbytes=8)))


def _vec(c):
    e = c.emu
    _alloc_hooks(c)
    n = c.rng.choice([0, 1, 2, 3, 6])
    extra = c.rng.choice([0, 0, 1, 2])
    cap = n + extra
    buf = _rnd(c, 0x48 * max(cap, 1) + 0x48)
    e.wbytes(buf, c.rng.randbytes(0x48 * max(cap, 1)))
    v = _rnd(c, 16)
    e.w32(v, buf)
    e.w32(v + 4, buf + 0x48 * n)
    e.w32(v + 8, buf + 0x48 * cap)
    return v, buf, n, cap


def _ins(c):
    _log_world(c)
    v, buf, n, cap = _vec(c)
    k = c.rng.randint(0, n)
    pos = buf + 0x48 * k
    src = _rnd(c, 0x48)
    c.emu.wbytes(src, c.rng.randbytes(0x48))
    if c.rng.random() < 0.2 and n > 0:   # src aliases a stored record
        src = buf + 0x48 * c.rng.randrange(n)
    return [v, pos, src]


def _res(c):
    _log_world(c)
    v, buf, n, cap = _vec(c)
    return [v, c.rng.choice([0, 1, 2, 3, 4, 6, 8])]


S(0x588750, 'CFFCoverList spot insert (fast path)', 'thiscall', None, ret='eax', gen=_ins,
  note='b721; insert middle 0x5885c0 runs as the port; copies, alloc and release hooked')
S(0x5885c0, 'CFFCoverList spot insert (middle)', 'thiscall', None, ret=None, gen=_ins, note='b721; shift by 0x5852f0, realloc path too')
S(0x5887e0, 'CFFCoverList spot reserve', 'thiscall', None, ret=None, gen=_res, note='b721; alloc and release hooked')
