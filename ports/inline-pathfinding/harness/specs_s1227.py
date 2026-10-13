"""specs_s1227.py - pathfinding batch 1227: ZPathfinderControl::CopyData (0x4c5530).

Real exe code: the REFTAB(int, int) constructor (0x4ccbe0) and the allocator. The event's REFTAB and the old REFTAB are
stubs (logged) in both builds; the new REFTAB's Add is the exe's own and writes through each ref, so refs are node
buffers.
"""
from pilot import S
from pfspec import rnd, reporter, allocator, vtable


def _cd(c):
    r = c.rng
    e = c.emu
    reporter(c, 0.0)
    allocator(c)
    e.w32(0x7003b0, e.stub_fn('delete hook', lambda em, rr: em.ret()))
    # the event: four fields and an iterable list of refs
    refs = [e.alloc(16, 4) for _ in range(r.randint(0, 3))]
    st = {'i': 0}
    def begin(em, args):
        st['i'] = 0
        em.w32(args[0], 1)
        return 0
    def nxt(em, args):
        if st['i'] < len(refs):
            em.w32(args[0], 1)
            st['i'] += 1
            return refs[st['i'] - 1]
        em.w32(args[0], 0)
        return 0
    srclist = e.alloc(0x40, 4)
    e.w32(srclist, vtable(c, 'eventlist', 0x80, impl={0x4c: begin, 0x5c: nxt}, argwords={0x4c: 1, 0x5c: 1}))
    src = e.alloc(0x80, 4)
    e.wbytes(src, bytes(0x80))
    for off in (0x4c, 0x4e, 0x50):
        e.w16(src + off, r.getrandbits(16))
    e.w8(src + 0x52, r.getrandbits(8))
    if r.random() < 0.85:
        e.w32(src + 0x48, srclist)
    # the destination: an old list (deleted), fresh fields
    old = e.alloc(0x40, 4)
    e.w32(old, vtable(c, 'oldlist', 0x40, impl={0: lambda em, a: 0}, argwords={0: 1}))
    self_ = e.alloc(0x100, 4)
    e.wbytes(self_, bytes(0x100))
    if r.random() < 0.7:
        e.w32(self_ + 0x48, old)
    return [self_, src]


S(0x4c5530, 'ZPathfinderControl::CopyData', 'thiscall', None, ret='eax', gen=_cd, n=200)
