"""specs_s248005.py - Sonnet-w4e hand spec."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, seh_record, seh_chain

def g663a40(c):
    clear_hooks(c)
    r = c.rng; em = c.emu
    R = lambda emu, k: r.getrandbits(32)
    def rs(n):
        return bytes(r.choice([r.randrange(1, 256), r.randrange(0x41, 0x5b)]) for _ in range(n))
    T = rnd(c, 0x12400)
    OBJ = rnd(c, 0x40); em.w32(T + 0x12104, OBJ)
    em.wbytes(T + 0x121b4, rs(r.choice([0, 1, 4, 17, 40, r.randrange(0, 56)])) + b'\0')
    S2 = rnd(c, 0x100)
    em.wbytes(S2, rs(r.choice([0, 1, 3, 9, 40, r.randrange(0, 56)])) + b'\0')
    def h5a0(emu, k):
        a = emu.arg32(0)
        emu.wbytes(a, bytes(r.getrandbits(8) for _ in range(16)))
        emu.calllog.append(('h5a0', emu.reg('ecx'), emu.arg32(1), bytes(emu.rbytes(a, 16)).hex()))
    hook_rec(c, 0x5ae5a0, 2, ret=R, pop=8, this=True, stackmark=(0,), side=h5a0)
    hook_rec(c, 0x5adea0, 0, ret=S2, pop=0, this=True, side=lambda emu, k: emu.calllog.append(('hea0', emu.reg('ecx'))))
    I = rnd(c, 0x40); VI = rnd(c, 0x400); em.w32(I, VI); em.w32(0x700394, I)
    def s14(emu, k):
        a = emu.arg32(0); out = bytearray()
        for i in range(0x90):
            b = emu.rbytes(a + i, 1)[0]
            if b == 0: break
            out.append(b)
        emu.calllog.append(('s14', emu.reg('ecx'), bytes(out).hex(), bytes(emu.rbytes(a + len(out) + 1, 8)).hex()))
    H = r.choice([0, 0, 1, 0x1234, r.getrandbits(32) | 1])
    em.w32(VI + 0x14, pystub(c, 1, ret=H, pop=4, this=True, stackmark=(0,), side=s14))
    A = r.choice([0, 1, 1, 0x100, 0x80, 0x180, 0x7f, r.getrandbits(32), r.getrandbits(32) & ~0xff])
    em.w32(VI + 0x38, pystub(c, 3, ret=A, pop=12, this=True, stackmark=(1,), side=lambda emu, k: emu.calllog.append(('s38', emu.reg('ecx'), emu.arg32(0), emu.arg32(2)))))
    em.w32(VI + 0x1c, pystub(c, 1, ret=R, pop=4, this=True, side=lambda emu, k: emu.calllog.append(('s1c', emu.reg('ecx'), emu.arg32(0)))))
    return [T, rnd(c, 0x10)]


S(0x663a40, 'save-file reader 0x663a40', 'thiscall', None, ret='eax', gen=g663a40, note='batch248005')
