"""specs_s49000.py - cascade u2 batch 49000: 0x5f0af0 (insert into a vector of 12-byte elements). The vector object {first, last, cap end} holds
0..5 random elements with spare room (shift path, 50%) or none (growth path); the value is a random 12-byte block (sometimes inside the vector);
0x6014a0 (allocate) returns a random-filled block and 0x54f870 (free) is logged, both with their arguments."""
from pilot import S
from recruits_util import rnd, clear_hooks


def _g5f0af0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.randrange(0, 6)
    room = r.choice([0, 0, 1, 2, 3]) if r.random() < 0.6 else 0
    if n == 0 and room == 0 and r.random() < 0.5:
        room = 0
    total = (n + room) * 12
    base = e.alloc(total + 0x60, 4)
    e.wbytes(base, bytes(r.getrandbits(8) for _ in range(total + 0x60)))
    buf = base + 0x20
    v = e.alloc(0x20, 4)
    e.w32(v, buf)
    e.w32(v + 4, buf + n * 12)
    e.w32(v + 8, buf + total)
    if r.random() < 0.08:
        e.w32(v, 0)
        e.w32(v + 4, 0)
        e.w32(v + 8, 0)
        n = 0
        buf = 0
    pos = buf + 12 * r.randrange(0, n + 1)
    if buf and n and r.random() < 0.15:
        val = buf + 12 * r.randrange(0, n)
    else:
        val = e.alloc(0x10, 4)
        e.wbytes(val, bytes(r.getrandbits(8) for _ in range(0x10)))

    def alloc(em, res_):
        k = em.arg32(0)
        em.calllog.append(('alloc', em.reg('ecx'), k))
        p2 = em.alloc(k + 0x20, 4)
        em.wbytes(p2, bytes(r.getrandbits(8) for _ in range(k + 0x20)))
        em.ret(eax=p2, argbytes=4)

    def free(em, res_):
        em.calllog.append(('free', em.reg('ecx'), em.arg32(0), em.arg32(1)))
        em.ret(eax=0, argbytes=8)
    e.hook(0x6014a0, alloc)
    e.hook(0x54f870, free)
    return [v, pos, val]


S(0x5f0af0, 'GUESS vector of 12-byte elements insert at pos', 'thiscall', None, ret=None, gen=_g5f0af0, note='batch49000')
