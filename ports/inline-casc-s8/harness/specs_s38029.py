"""specs_s38029.py - cascade s8 batch 38029. Queue count at 0x7014b0 chosen so that the queue stays below capacity (0x32), overflows at every one of the eight positions, or is already full;
the queue array (0x7014b8..) is filled with random words (the data section is compared). job[0xc] is zero 15% of the time or cleared by the slot 0x44 stub (so the early-exit between
steps runs). The slot 0x44 stub records its argument, the assert hook (0x7003b0) is always set and sometimes changes the queue count."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g511450(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    base = r.choice([0, 5, 0x20, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f, 0x30, 0x31, 0x32, 0x33, 0x40, 0xffffffff])
    e.w32(0x7014b0, base)
    e.wbytes(0x7014b8, r.randbytes(0x32 * 4 + 8))
    job = rnd(c, 0x20)
    e.wbytes(job + 0xc, bytes([0 if r.random() < 0.15 else r.choice([1, 2, 0xff])]))
    clr = r.choice([0.0, 0.3])

    def s44(em, k):
        em.calllog.append(('s44', em.reg('ecx') != 0))
        if r.random() < clr:
            em.wbytes(job + 0xc, b'\0')

    def ah(em, res_):
        em.calllog.append(('assert',))
        if r.random() < 0.3:
            em.w32(0x7014b0, r.choice([0, 0x10, 0x31, 0x32]))
        em.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    me = obj(c, 0x40, {0x44: pystub(c, 1, this=True, side=s44)})
    return [me, job]


S(0x511450, 'GUESS queue pass callbacks', 'thiscall', None, ret=None, gen=_g511450, note='batch38029')
