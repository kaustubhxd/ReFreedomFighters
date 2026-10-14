"""specs_s35052.py - 0x4d5e80 (thiscall(a) ret 4, ret='al'). 0x4d6520 hooked (thiscall, logs this, a and the string; writes random dwords through its two out pointers; AL true in 3/4, random upper bytes);
0x4d61e0 hooked (thiscall, no args); the vector header at this+0x5e (capacity, size 0..5, data pointer; unaligned) with a data block of 0x80 bytes; [this+0x6a] (unaligned) null in 1/3, else an object whose slot 0xc
records the C string it receives (read up to 64 bytes); 0x4d7130 runs as exe code on a string with backslashes."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g4d5e80(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4d61e0, 0, this=True)
    okv = (r.getrandbits(24) << 8) | (1 if r.random() < 0.75 else 0)
    w20, w24 = r.getrandbits(32), r.getrandbits(32)

    def h6520(em, rr):
        a = em.arg32(0)
        s = b''
        while len(s) < 64:
            ch = bytes(em.rbytes(a + len(s), 1))
            if ch == b'\0':
                break
            s += ch
        em.calllog.append(('4d6520', em.reg('ecx'), a, s))
        em.w32(em.arg32(1), w20)
        em.w32(em.arg32(2), w24)
        em.ret(eax=okv, argbytes=12)
    e.hook(0x4d6520, h6520)

    def rec(em, k):
        buf = em.arg32(0)
        s = b''
        while len(s) < 64:
            ch = bytes(em.rbytes(buf + len(s), 1))
            if ch == b'\0':
                break
            s += ch
        em.calllog.append(('slotc', s))
    from recruits_util import _recorder  # noqa: F401  (not needed; the stub below is a plain logger)

    def logger(em, rr):
        rec(em, 0)
        em.ret(argbytes=4)
    me = rnd(c, 0x80)

    def w(off, v):
        e.wbytes(me + off, (v & 0xffffffff).to_bytes(4, 'little'))
    w(0x5e, r.randint(0, 6))
    w(0x62, r.randint(0, 5))
    w(0x66, rnd(c, 0x80))
    if r.random() < 1 / 3:
        w(0x6a, 0)
    else:
        w(0x6a, obj(c, 0x20, {0xc: e.stub_fn('slotc', logger)}, nslots=4))
    a = rnd(c, 0x40)
    s = bytes(r.choice(b'ab\\\\/cd.') for _ in range(r.randint(0, 20))) + b'\0'
    e.wbytes(a, s)
    return [me, a]


S(0x4d5e80, 'GUESS parse path, remember id, notify listener', 'thiscall', None, ret='al', gen=_g4d5e80, note='batch35052')
