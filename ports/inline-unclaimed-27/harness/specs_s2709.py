"""specs_s2709.py - residue-07 (core-todo) function 0x514cf0: ZVehicle::CheckActorInFront (thiscall, returns al).
Stubs, NOT verified: the object at this+0x2af (A) has a vtable whose slot +0x438 returns a chosen byte; A+8 is B, whose +0x3c
dword is random (bit 10 decides the early return). The callees 0x4e0870 (float in st0), 0x514f60 and 0x514d80 (bytes in al),
and 0x515270 and 0x515100 (void) are replaced per case by hooks that return chosen values and count their calls in a heap
record, so both sides see the same results (the port calls the same addresses)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _cica(c):
    rec = c.emu.alloc(0x40, 4)   # counters: +0 0x515270, +4 0x515100, +8 0x514f60, +0xc 0x514d80, +0x10 0x4e0870
    f = c.rng.choice([100.0, 4000.0, 6000.0, -1.0, float('nan'), c.rng.uniform(-1e4, 1e4)])
    b438 = c.rng.choice([0, 1, 0x80, c.rng.getrandbits(8)])
    r1 = c.rng.choice([0, 1, 0x80])
    r2 = c.rng.choice([0, 1, 0x80])

    def count(k):
        return lambda e, r: e.w32(rec + k, (e.r32(rec + k) + 1) & 0xffffffff)

    def h515270(e, r):
        count(0)(e, r); e.ret(argbytes=0)

    def h515100(e, r):
        count(4)(e, r); e.ret(argbytes=0)

    def h514f60(e, r):
        count(8)(e, r); e.ret(eax=r1, argbytes=0)

    def h514d80(e, r):
        count(0xc)(e, r); e.ret(eax=r2, argbytes=0)

    def h4e0870(e, r):
        count(0x10)(e, r); e.ret(st0=f, argbytes=0)

    c.emu.hook(0x515270, h515270)
    c.emu.hook(0x515100, h515100)
    c.emu.hook(0x514f60, h514f60)
    c.emu.hook(0x514d80, h514d80)
    c.emu.hook(0x4e0870, h4e0870)
    # the object and A
    o = _rnd(c, 0x800)
    if c.rng.random() < 0.2:
        c.emu.w32(o + 0x2af, 0)
    else:
        a = _rnd(c, 0x800)
        avt = c.emu.alloc(0x800, 4)
        code = b'\xb8' + b438.to_bytes(4, 'little') + b'\xc3'            # mov eax, b438; ret
        st = c.emu.alloc(len(code) + 16, 16)
        c.emu.wbytes(st, code)
        c.emu.w32(avt + 0x438, st)
        c.emu.w32(a, avt)
        bobj = _rnd(c, 0x100)
        c.emu.w32(bobj + 0x3c, c.rng.getrandbits(32))
        c.emu.w32(a + 8, bobj)
        c.emu.w32(o + 0x2af, a)
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x514cf0, 'ZVehicle::CheckActorInFront (unknown) thiscall', 'thiscall', None, ret='al', gen=_cica,
  note='residue-07; A slot +0x438 is a stub; callees 0x4e0870 0x514f60 0x514d80 0x515270 0x515100 are hooks (stubs)')
