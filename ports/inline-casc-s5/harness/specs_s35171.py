"""specs_s35171.py - 0x428100 (thiscall(a, b, c, d) ret 0x10, ret='al'). this: object with slot 0x144 (3 args; the stack buffer, arg 0, is recorded as flag and its 0x400 bytes are overwritten with random bytes) and dword +0xc random.
Object at 0x700394 with slots 0x4c (1 arg recorded), 0x64 (4 args; the buffer, arg 0, recorded as its first 16 dwords), 0x30 (2 args; the buffer recorded as 16 dwords; returns b in 1/3, else random incl. values differing only in upper bytes)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g428100(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    b = r.getrandbits(32)

    def fill(em, k):
        em.wbytes(em.arg32(0), bytes(r.getrandbits(8) for _ in range(0x400)))
    ch = r.random()
    ret = b if ch < 1 / 3 else (b ^ (1 << r.randint(0, 31)) if ch < 2 / 3 else r.getrandbits(32))
    L = obj(c, 0x20, {0x4c: pystub(c, 1, this=True), 0x64: pystub(c, 4, this=True, deref={0: 16}),
                      0x30: pystub(c, 2, this=True, deref={0: 16}, ret=ret)}, nslots=0x1a)
    e.w32(0x700394, L)
    me = obj(c, 0x20, {0x144: pystub(c, 3, this=True, nullflag=(0,), side=fill)}, nslots=0x52)
    return [me, r.getrandbits(32), b, r.getrandbits(32), r.getrandbits(32)]


S(0x428100, 'GUESS format message into local buffer via console and compare result', 'thiscall', None, ret='al', gen=_g428100, note='batch35171')
