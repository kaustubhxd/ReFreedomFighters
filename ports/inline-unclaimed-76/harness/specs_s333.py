"""specs_s333.py - gap band, batch 333: 0x620840 (cdecl, four arguments). The helpers 0x620180 and 0x6206e0 run as exe code. The object's
+0xc cursor points into a writable buffer; +8 is a second pointer; +0x10 a value. The buffer and the object are random."""
from pilot import S


def _rec_180(em, r):
    # 0x620180 (cdecl, four arguments, reads only the first in the exe): recorded by address; returns a per-run value
    em.calllog.append(('h620180', 0, None, tuple(em.arg32(k) for k in range(4))))
    em.ret(eax=RV180, argbytes=0)


def _rec_6e0(em, r):
    # 0x6206e0 (cdecl, one argument): recorded by address; returns a per-run value
    em.calllog.append(('h6206e0', 0, None, (em.arg32(0),)))
    em.ret(eax=RV6E0, argbytes=0)


RV180 = 0
RV6E0 = 0


def _gen(c):
    global RV180, RV6E0
    e = c.emu
    rng = c.rng
    RV180 = rng.choice([0, 1, rng.getrandbits(32)])
    RV6E0 = rng.choice([0, 1])
    e.hook(0x620180, _rec_180)
    e.hook(0x6206e0, _rec_6e0)
    buf = e.alloc(0x100, 4)
    e.wbytes(buf, rng.randbytes(0x100))
    o = e.alloc(0x40, 4)
    e.wbytes(o, rng.randbytes(0x40))
    cur = buf + rng.randrange(0, 0x40)
    e.w32(o + 0xc, cur)
    e.w32(o + 8, cur if rng.random() < 0.4 else buf + rng.randrange(0, 0x40))
    e.w32(o + 0x10, rng.getrandbits(32))
    return [o, rng.getrandbits(32), rng.getrandbits(32), rng.getrandbits(32)]


S(0x620840, 'take620840 (GUESS)', 'cdecl', None, ret='eax', gen=_gen, note='batch333; calls 0x620180 and 0x6206e0 (exe)')
