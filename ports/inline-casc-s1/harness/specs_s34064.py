"""specs_s34064.py - cascade tier E, batch 34064.
0x455190: hooked 0x441790; [this+0x5c] is a non-null iterator object (the original calls it unconditionally first) with slots 0x14 (returns n), 0x4c and 0x5c (stack iterator, 0..3 ids); s slots 0x44 and 0x64 are recorders.
0x48de00 (stdcall): a is null in half the cases (engine table owner at +0xadc then returns the object through slot 0x294, four stack args); the object's slots 0x74 (logs the pointed-to 9 + 3 dwords) and 0x108 are
recorders; hooked 0x4de7a0 fills the 9-dword matrix with random dwords; the /GS check keeps EAX.
0x4effa0: this slot 0x80 fills A (9) and B (3) with random dwords; b slot 0x94 and this slot 0x224 (five args) log the pointed-to dwords; byte [this+0x8f] random; the /GS check is a zero-argument recorder."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec, sysobj


def _g455190(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x441790, 1, this=True)
    n = r.choice([0, 1, 2, 3])

    def begin(em, k):
        for i in range(3):
            em.w32(em.arg32(0) + 4 * i, r.getrandbits(32))

    def nxt(em, k):
        em.w32(em.arg32(0), 1 if k < n else 0)
    m = obj(c, 0x20, {0x14: pystub(c, 0, ret=r.getrandbits(32), this=True), 0x4c: pystub(c, 1, this=True, side=begin, stackmark=(0,)),
                      0x5c: pystub(c, 1, this=True, side=nxt, stackmark=(0,), ret=lambda em, k: r.getrandbits(32))}, nslots=0x60 // 4)
    s = obj(c, 0x20, {0x44: pystub(c, 1, this=True), 0x64: pystub(c, 1, this=True)}, nslots=0x68 // 4)
    me = rnd(c, 0x80)
    c.emu.w32(me + 0x5c, m)
    return [me, s]


def _g48de00(c):
    clear_hooks(c)
    r = c.rng

    def wM(em, k):
        for i in range(9):
            em.w32(em.reg("ecx") + 4 * i, r.getrandbits(32))
    hook_rec(c, 0x4de7a0, 0, this='mark', pop=0, side=wM)
    hook_rec(c, 0x633654, 0, pop=0, ret=None)
    new = obj(c, 0x60, {0x74: pystub(c, 2, this=True, deref={0: 9, 1: 3}), 0x108: pystub(c, 2, this=True)}, nslots=0x10c // 4)
    own = obj(c, 0x20, {0x294: pystub(c, 4, ret=new, this=True)}, nslots=0x298 // 4)
    so = sysobj(c, table_size=0xb00)
    tbl = c.emu.r32(so + 0x9b)
    c.emu.w32(tbl + 0xadc, own)
    a = 0 if r.random() < 0.5 else obj(c, 0x60, {0x74: pystub(c, 2, this=True, deref={0: 9, 1: 3}), 0x108: pystub(c, 2, this=True)}, nslots=0x10c // 4)
    return [a]


def _g4effa0(c):
    clear_hooks(c)
    r = c.rng

    def wAB(em, k):
        for i in range(9):
            em.w32(em.arg32(0) + 4 * i, r.getrandbits(32))
        for i in range(3):
            em.w32(em.arg32(1) + 4 * i, r.getrandbits(32))
    hook_rec(c, 0x633654, 0, pop=0)
    b = obj(c, 0x20, {0x94: pystub(c, 2, this=True, deref={0: 9, 1: 3})}, nslots=0x98 // 4)
    me = obj(c, 0x90, {0x80: pystub(c, 2, this=True, side=wAB, stackmark=(0, 1)),
                       0x224: pystub(c, 5, this=True, deref={2: 9, 3: 3})}, nslots=0x228 // 4)
    c.emu.wbytes(me + 0x8f, bytes([r.getrandbits(8)]))
    return [me, r.getrandbits(32), b]


S(0x455190, 'GUESS read a count-first record and forward its ids', 'thiscall', None, ret='al', gen=_g455190, note='batch34064')
S(0x48de00, 'GUESS create or take an overlay object and orient it', 'stdcall', None, ret='eax', gen=_g48de00, note='batch34064')
S(0x4effa0, 'GUESS fetch two blocks and dispatch', 'thiscall', None, ret='al', gen=_g4effa0, note='batch34064')
