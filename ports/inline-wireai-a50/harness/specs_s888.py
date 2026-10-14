"""specs_s888.py - area 50, batch 888: 0x558b50 (GUESS name Query558b50), thiscall (ECX unused), one stack arg (record), ret 4, void.
Stand-ins (hooked, logged by value): the accessor 0x5003d0 (argument = index; returns the address of a float of the object, one per
index), the helper 0x4de7a0 (ECX = the local object; it writes a fixed pattern into it). The manager's slot 0x238 (on the object at
mgr+0xadc) logs the local object's first 16 bytes, the vector V, W and its two stack words, by value (not by address; the frames
differ between the two runs)."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen(c):
    e, r = c.emu, c.rng
    fin = lambda x: x if x == x and abs(x) < 1e6 else 0.0
    fl = [fin(r.uniform(-9, 9)) for _ in range(3)]
    slots = {}
    for i in range(3):
        slots[i] = rnd(c, 4)
        e.wf32(slots[i], fl[i])

    def acc(e, rr):
        idx = e.arg32(0)
        e.calllog.append(('acc.5003d0', idx))
        e.ret(eax=slots[idx], argbytes=4)

    def h4de(e, rr):
        e.calllog.append(('h.4de7a0',))
        e.wbytes(e.reg('ecx'), bytes(range(16)))
        e.ret(eax=0, argbytes=0)

    def h238(e, rr):
        L, V, W = e.arg32(0), e.arg32(1), e.arg32(2)
        e.calllog.append(('M.238', e.rbytes(L, 16), tuple(repr(e.rf32(V + 4 * k)) for k in range(3)),
                          tuple(repr(e.rf32(W + 4 * k)) for k in range(3)), e.arg32(3), e.arg32(4)))
        e.ret(eax=0, argbytes=20)

    only_hooks(c, {0x5003d0: acc, 0x4de7a0: h4de})
    Mvt = e.fake_vtable('M', 0x100, {0x238: h238})
    M = rnd(c, 0x40)
    e.w32(M, Mvt)
    mgr = rnd(c, 0x1000)
    e.w32(mgr + 0xadc, M)
    g = rnd(c, 0x1b00)
    e.w32(g + 0x9b, mgr)
    e.w32(0x70039c, g)
    rec = rnd(c, 0x40)
    e.w32(rec + 4, rnd(c, 0x40))
    return [0, rec]


S(0x558b50, 'Query558b50 (GUESS name)', 'thiscall', None, gen=_gen, note='area50 batch888')
