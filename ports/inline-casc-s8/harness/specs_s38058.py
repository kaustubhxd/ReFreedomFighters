"""specs_s38058.py - cascade s8 batch 38058. A vector of u32 {first, last, cap end} with 0..6 elements and spare capacity chosen so that the shift-up case (tail > n), the append case (tail <= n) and the
reallocating case all occur; pos anywhere in [first, last]; n 0..5 (zero 8%); value pointer to a random dword. The four helpers 0x606a30 / 0x6069f0 / 0x6014a0 / 0x54f870 are logged hooks with real effects (the
copy / fill helpers do what their callers expect: copy [ecx, ecx + k) to the destination, resp. fill the range with *value), so the final element contents are in the heap compare."""
import struct
from pilot import S
from recruits_util import clear_hooks


def _g606ee0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    size = r.randrange(0, 7)
    n = 0 if r.random() < 0.08 else r.randrange(1, 6)
    mode = r.choice(['room', 'tight', 'exact'])
    if mode == 'room':
        free = n + r.randrange(0, 3)
    elif mode == 'tight':
        free = r.randrange(0, n) if n else 0
    else:
        free = n
    cap = size + free
    buf = e.alloc(4 * (cap + 8), 4)
    e.wbytes(buf, r.randbytes(4 * (cap + 8)))
    vec = e.alloc(16, 4)
    e.wbytes(vec, struct.pack('<III', buf, buf + 4 * size, buf + 4 * cap) + bytes(4))
    pos = buf + 4 * r.randrange(0, size + 1)
    val = e.alloc(4, 4)
    e.w32(val, r.getrandbits(32))

    def copy606(em, res_):
        src, dst, end = em.reg('ecx'), em.reg('edx'), em.arg32(0)
        em.calllog.append(('copy', src, dst, end))
        # uninitialized copy of the range [src, dst) to end - (dst - src) (the callers pass the destination end)
        k = (dst - src) // 4 if dst >= src else 0
        if 0 < k < 64:
            em.wbytes(end - 4 * k if end >= 4 * k else end, em.rbytes(src, 4 * k))
        em.ret(eax=0, argbytes=4)

    def fill69(em, res_):
        first, last, vp = em.reg('ecx'), em.reg('edx'), em.arg32(0)
        em.calllog.append(('fill', first, last, em.r32(vp)))
        k = (last - first) // 4 if last >= first else 0
        if 0 < k < 64:
            em.wbytes(first, em.rbytes(vp, 4) * k)
        em.ret(eax=0, argbytes=4)

    def alloc(em, res_):
        b = em.arg32(0)
        em.calllog.append(('alloc', em.reg('ecx'), b))
        p = em.alloc(b + 0x20, 4)
        em.wbytes(p, r.randbytes(b + 0x20))
        em.ret(eax=p, argbytes=4)

    def free(em, res_):
        em.calllog.append(('free', em.reg('ecx'), em.arg32(0), em.arg32(1)))
        em.ret(eax=0, argbytes=8)
    e.hook(0x606a30, copy606)
    e.hook(0x6069f0, fill69)
    e.hook(0x6014a0, alloc)
    e.hook(0x54f870, free)
    return [vec, pos, n, val]


S(0x606ee0, 'GUESS vector insert n copies', 'thiscall', None, ret=None, gen=_g606ee0, note='batch38058')
