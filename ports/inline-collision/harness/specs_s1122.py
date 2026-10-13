"""specs_s1122.py - collision thread batch 1122: 0x4ec660 strip-output callback. The helper (query+0xb0) is a stub
whose slot 0x88 logs its arguments (values only: the pointer arguments are frame-local) and returns end + 0x14."""
from pilot import S, F
from specs_s1110 import _vt


def _sout(c):
    e, r = c.emu, c.rng
    q = e.alloc(0x100, 4)
    e.wbytes(q, bytes(r.getrandbits(8) for _ in range(0x100)))
    base = e.alloc(0x40, 4)
    e.w32(q + 0x5c, base)
    end = e.alloc(0x80, 4)
    e.w32(q + 0x60, end)
    room = r.choice([0, 0x60, 0xe0, 0xe3, 0xe4, 0xe5, 0x100])   # the room test sits on 0xe4
    e.w32(q + 0x64, end + room)
    e.w32(q + 0x68, r.getrandbits(32))
    e.w32(q + 0x6c, r.choice([0, 3]))
    e.w32(q + 0xac, r.getrandbits(32))
    for off in (0x70, 0x94, 0xa0):   # pointer-sized inputs: heap objects, so their values do not depend on the frame
        e.w32(q + off, e.alloc(0x20, 4))
    helper = e.alloc(0x20, 4)
    def slot88(em, a):
        em.calllog.append(('helper', 0x88, tuple(a[1:4]) + (em.r32(a[0] + 0x10), em.r32(a[0] + 0x14))))
        return (end + 0x14 + 0x10) & 0xffffffff, ()
    e.w32(helper, _vt(c, 'helper', {0x88: (6, slot88)}, 0x90 // 4))
    e.w32(q + 0xb0, helper)
    # ECX is a pointer to the ref word (the callee reads it: begin + [ECX]) and stores the pointer itself
    ref = e.alloc(4, 4)
    e.w32(ref, r.choice([0, 0x20, 0x40]))
    return [ref, q]


S(0x4ec660, 'strip output callback (guessed)', 'fastcall', None, ret='al', gen=_sout, note='batch1122')
