"""specs_s867.py - area 50, batch 867: 0x4d2910 (name GUESS), thiscall, one stack arg, ret 4, no result.
Stood in: the allocator 0x4cd9b0 (returns sequential offsets into the base buffer, logged), the memcpy import (stub, logged),
the source iterator (vt +0x4c and +0x5c: the next record and its flag; records are small blocks with the size words at +0 and +8),
and the destination object (vt +0x4, logged). The base buffer at this+0x4004 is a 0x800-byte block."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object, install_memset


def _gen(c):
    e, r = c.emu, c.rng
    only_hooks(c, {})
    install_memset(c)

    def mv(e, rr):
        d, s, n = e.arg32(0), e.arg32(1), e.arg32(2)
        e.calllog.append(('memcpy', d, n))
        if n:
            e.wbytes(d, e.rbytes(s, n))
        e.ret(eax=d, argbytes=0)

    st = {'off': 0}

    def alloc(e, rr):
        size, flag = e.arg32(0), e.arg32(1)
        o = st['off']
        st['off'] += 0x40
        e.calllog.append(('alloc', size, flag))
        e.ret(eax=o, argbytes=8)

    e.stub_import('memcpy', mv)
    only_hooks(c, {0x4cd9b0: alloc})

    recs = []
    for _ in range(r.randint(0, 4)):
        rec = rnd(c, 0x40)
        e.w32(rec + 0, r.randint(0, 8))
        e.w32(rec + 8, r.randint(0, 8))
        recs.append(rec)
    ptr = {'i': 0}

    def it4c(e, rr):
        ptr['i'] = 0
        e.calllog.append(('it.4c',))
        e.ret(eax=0, argbytes=4)

    def it5c(e, rr):
        p = e.arg32(0)
        if ptr['i'] < len(recs):
            v = recs[ptr['i']]
            ptr['i'] += 1
            e.w32(p, 1)
            e.calllog.append(('it.5c', 1))
            e.ret(eax=v, argbytes=4)
        else:
            e.w32(p, 0)
            e.calllog.append(('it.5c', 0))
            e.ret(eax=0, argbytes=4)

    def dst4(e, rr):
        e.calllog.append(('dst.4', e.arg32(0)))
        e.ret(eax=0, argbytes=4)

    # the iterator and the destination objects live at +0x4008 of the source and the destination (their vtables are set there)
    src = rnd(c, 0x4100)
    it = vt_object(c, 0x40, {0x4c: it4c, 0x5c: it5c}, nslots=0x100, name='it')
    e.w32(src + 0x4008, e.r32(it))
    self = rnd(c, 0x4100)
    base = rnd(c, 0x800)
    e.w32(self + 0x4004, base)
    dst = vt_object(c, 0x40, {0x4: dst4}, nslots=0x20, name='dst')
    e.w32(self + 0x4008, e.r32(dst))
    return [self, src]


S(0x4d2910, 'Fn4d2910 (GUESS name)', 'thiscall', None, gen=_gen, note='area50 batch867')
