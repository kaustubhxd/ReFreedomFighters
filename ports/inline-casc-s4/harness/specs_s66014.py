"""specs_s66014.py - cascade s4 batch 66014: 0x499e60 (write a byte range into a chain of 0x1388-byte chunks, growing the chain)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec


def _g499e60(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    ctx = e.alloc(0x20, 8)
    withpool = r.random() < 0.5
    e.w32(ctx + 4, e.alloc(0x20, 8) if withpool else 0)
    nchain = r.choice([1, 1, 2, 3])
    chain = [e.alloc(0x1400, 8) for _ in range(nchain)]
    for i, ch in enumerate(chain):
        e.w32(ch, chain[i + 1] if i + 1 < nchain else 0)
        e.w32(ch + 4, ctx)
    st = {'k': 0}

    def a2(em, rr):                       # 0x4cd9b0: thiscall (size, flag) ret 8
        em.calllog.append(('alloc2', em.reg('ecx'), em.arg32(0), em.arg32(1)))
        em.ret(eax=e.alloc(0x1400, 8), argbytes=8)

    def a1(em, rr):                       # 0x41e290: cdecl (size)
        em.calllog.append(('alloc1', em.arg32(0)))
        em.ret(eax=e.alloc(0x1400, 8), argbytes=0)

    def mc(em, rr):
        d, s_, n = em.arg32(0), em.arg32(1), em.arg32(2)
        em.calllog.append(('memcpy', d, s_, n))
        if n:
            em.wbytes(d, bytes(em.rbytes(s_, n)))
        em.ret(eax=d, argbytes=0)
    e.hook(0x4cd9b0, a2)
    e.hook(0x41e290, a1)
    e.hook(0x634d22, mc)
    off = r.choice([0, 0, 5, 0x1387, 0x1388, 0x1389, 0x2710, 0x2711, 0x1000])
    rem = 0x1388 - (off % 0x1388)
    ln = r.choice([0, 1, 7, rem - 1, rem, rem + 1, rem + 0x1388, 0x40, 0x1388])
    ln = max(ln, 0)
    src = e.alloc(0x4000, 8)
    e.wbytes(src, bytes(r.getrandbits(8) for _ in range(0x300)) * 20)
    return [chain[0], off, src, ln]


S(0x499e60, 'GUESS write bytes into a chain of fixed-size chunks', 'thiscall', None, ret=None, gen=_g499e60, note='batch66014')
