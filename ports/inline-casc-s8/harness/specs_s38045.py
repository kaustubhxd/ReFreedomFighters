"""specs_s38045.py - cascade s8 batch 38045. Stream with logging read slots 0x6c / 0x50 / 0x68 / 0x58 (1 arg: write a slot-specific width of random bytes through the destination, logged with the destination) and
0x18 (2 args: dst, length: writes 4 random bytes); 0x5c9f80 (header loader, fails 20% of the time, AL only) and 0x6625c0 (embedded record loader, logs its this) are hooks. Return is bool (AL)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec


def _g5cc020(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    widths = {0x6c: 12, 0x50: 4, 0x68: 1, 0x58: 2}

    def rd(slotn, n):
        def h(em, res_):
            dst = em.arg32(0)
            em.calllog.append((slotn, em.reg('ecx'), dst))
            em.wbytes(dst, bytes(r.getrandbits(8) for _ in range(n)))
            em.ret(eax=0, argbytes=4)
        return e.stub_fn('rd%x' % slotn, h)

    def s18(em, res_):
        dst, n = em.arg32(0), em.arg32(1)
        em.calllog.append(('s18', em.reg('ecx'), dst, n))
        em.wbytes(dst, bytes(r.getrandbits(8) for _ in range(4)))
        em.ret(eax=0, argbytes=8)
    slots = {k: rd(k, w) for k, w in widths.items()}
    slots[0x18] = e.stub_fn('s18', s18)
    stream = obj(c, 0x80, slots)
    me = rnd(c, 0x5b0)
    hook_rec(c, 0x5c9f80, 1, this=True, pop=4, ret=lambda em, k: 0 if r.random() < 0.2 else r.choice([1, 0x101, 0xff01]))
    hook_rec(c, 0x6625c0, 1, this=True, pop=4)
    return [me, stream]


S(0x5cc020, 'GUESS load control block from stream', 'thiscall', None, ret='al', gen=_g5cc020, note='batch38045')
