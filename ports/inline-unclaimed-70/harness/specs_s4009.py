"""specs_s4009.py - area 70 batch 4009: 0x4408d0. The exe helpers 0x45e900 and 0x4daed0 run as exe code. 0x4daed0 calls
through the global pointer at 0x7003b0 when a node's +0x54 is zero, so the spec sets that global to a stub (GUESS).
The list nodes have +0x54 random (zero half the time) and +0x60 as the next pointer."""
from pilot import S, F


def _vt(c, name, slots, nslots):
    e = c.emu
    hs = {}
    for off, (nargs, fn) in slots.items():
        def h(em, rr, off=off, nargs=nargs, fn=fn):
            args = [em.arg32(k) for k in range(nargs)]
            eax, logged = fn(em, args)
            em.calllog.append((name, off, em.reg('ecx'), logged))
            em.ret(eax=eax, argbytes=4 * nargs)
        hs[off] = h
    return e.fake_vtable(name, nslots, hs)


def _walk(c):
    e, r = c.emu, c.rng
    # the global function pointer used by 0x4daed0 (a stub; it logs and returns 0)
    def gstub(em, rr):
        em.calllog.append(('gstub',))
        em.ret(eax=0, argbytes=0)   # a stub_fn handler returns through ret itself
    gfn = e.stub_fn('gfn7003b0', gstub)
    e.w32(0x7003b0, gfn)
    e._image_dirty = True
    self_ = e.alloc(0x100, 4)
    e.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x100)))
    flag = r.getrandbits(32) if r.random() < 0.5 else r.getrandbits(8) & 1
    nodes = [e.alloc(0x80, 4) for _ in range(r.choice([0, 1, 2, 3]))]
    def s_c8(em, a):
        em.calllog.append(('sc8', a[0]))
        return 0, ()
    for i, n in enumerate(nodes):
        e.wbytes(n, bytes(r.getrandbits(8) for _ in range(0x80)))
        e.w32(n + 0x60, nodes[i + 1] if i + 1 < len(nodes) else 0)
        # with a non-zero flag the exe dereferences +0x54 after its global call without a null check (it reads address 0
        # when +0x54 is zero), so +0x54 is kept non-null for flag != 0; zero is used only on the flag == 0 path.
        if (flag & 0xff) == 0 and r.random() < 0.5:
            e.w32(n + 0x54, 0)
        else:
            # the bound object: a fake with slot 0xc8 (1 stack arg, the tail-called virtual of 0x4daed0; GUESS stub)
            bo = e.alloc(0x20, 4)
            e.w32(bo, _vt(c, 'bound_c8', {0xc8: (1, s_c8)}, 0xcc // 4))
            e.w32(n + 0x54, bo)
    e.w32(self_ + 0x50, nodes[0] if nodes else 0)
    return [self_, flag]


S(0x4408d0, 'flag setter then per-node call (name GUESS)', 'thiscall', None, gen=_walk, note='batch4009')
