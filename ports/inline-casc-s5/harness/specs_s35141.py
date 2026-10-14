"""specs_s35141.py - 0x5b7660 (thiscall, no args). this: random 0x60 bytes with vtable slot 0x68 (2 args), [+0x50] = P (random 0x860 bytes with [P+8] a heap word, unaligned dword at +0x852, vtable slot 0x84 (1 arg: the 12 bytes behind the pointer compared by content)), [+0x44] = Q (slots 0x8c (1 arg, 12 bytes compared) and 0x180
(2 args: pointer content compared, float bits recorded; AL true in half)); 0x4daf90 hooked in Python (thiscall: logs ecx and fills the 12-byte vector at its argument with fixed random bytes); 0x597fc0 hooked (thiscall, 2 args)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g5b7660(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    data = bytes(r.getrandbits(8) for _ in range(12))

    def h(em, rr):
        em.calllog.append(('4daf90', em.reg('ecx')))
        em.wbytes(em.arg32(0), data)
        em.ret(eax=0, argbytes=4)
    e.hook(0x4daf90, h)
    hook_rec(c, 0x597fc0, 2, this=True)
    al = ((r.getrandbits(24) << 8) | r.choice([1, 2, 0x80])) if r.random() < 0.5 else (r.getrandbits(24) << 8)
    P = obj(c, 0x860, {0x84: pystub(c, 1, deref={0: 3}, this=True)}, nslots=0x22)
    Q = obj(c, 0x20, {0x8c: pystub(c, 1, deref={0: 3}, this=True), 0x180: pystub(c, 2, deref={0: 3}, this=True, ret=al)}, nslots=0x61)
    me = obj(c, 0x60, {0x68: pystub(c, 2, this=True)}, nslots=0x1b)
    e.w32(me + 0x50, P)
    e.w32(me + 0x44, Q)
    return [me]


S(0x5b7660, 'GUESS fetch position and trigger owner on accept', 'thiscall', None, ret=None, gen=_g5b7660, note='batch35141')
