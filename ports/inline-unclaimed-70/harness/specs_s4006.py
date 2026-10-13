"""specs_s4006.py - area 70 batch 4006: 0x4cdb90, list walk. The list nodes are 0x20-byte records with next at +4; the
owner's slot 0x7c is a GUESS stub that logs the node it is given and returns 0."""
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
    self_ = e.alloc(0x40, 4)
    e.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x40)))
    nodes = [e.alloc(0x20, 4) for _ in range(r.choice([0, 1, 2, 4]))]
    for i, n in enumerate(nodes):
        e.wbytes(n, bytes(r.getrandbits(8) for _ in range(0x20)))
        e.w32(n + 4, nodes[i + 1] if i + 1 < len(nodes) else 0)
    e.w32(self_ + 4, nodes[0] if nodes else 0)
    def s7c(em, a):
        em.calllog.append(('s7c', a[0] - nodes[0] if nodes else 0))
        em.w32(a[0] + 4, 0)   # the callee clears the node's next: a walk that reads next after the call stops early
        return 0, ()
    e.w32(self_, _vt(c, 'owner7c', {0x7c: (1, s7c)}, 0x80 // 4))
    return [self_]


S(0x4cdb90, 'clear node list (name GUESS)', 'thiscall', None, gen=_walk, note='batch4006')
