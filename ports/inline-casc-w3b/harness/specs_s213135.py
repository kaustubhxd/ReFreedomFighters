"""specs_s213135.py - batch 213135: script value-to-string builder (strcmp import stubbed, printf-like log object, realloc of the target buffer), Sonnet-w3b."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g604a60(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rb = lambda: r.getrandbits(32)
    f32 = lambda v: struct.unpack('<f', struct.pack('<f', v))[0]

    def w32u(addr, v):
        e.wbytes(addr, struct.pack('<I', v & 0xffffffff))

    def cstr(addr, n=24):
        return bytes(e.rbytes(addr, n)).split(b'\0')[0]

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=rb())
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))

    def cmpstub(em, res_):
        a, b = em.arg32(0), em.arg32(1)
        sa, sb = cstr(a), cstr(b)
        em.calllog.append(('strcmp', sa, sb))
        em.ret(eax=0 if sa == sb else (1 if sa > sb else 0xffffffff), argbytes=0)
    e.w32(0x676414, e.stub_fn('strcmp', cmpstub))

    def pfmt(em, res_):
        P_, buf, fm = em.arg32(0), em.arg32(1), em.arg32(2)
        a3, a4 = em.arg32(3), em.arg32(4)
        em.calllog.append(('fmt', em.reg('ecx'), P_, fm, a3, a4 if fm == 0x6792bc else 0))
        if fm == 0x677368:
            txt = b'S' + cstr(a3, 10)
        elif fm == 0x69d384:
            txt = b'I%08x' % a3
        else:
            txt = b'D%08x%08x' % (a3, a4)
        em.wbytes(buf, txt + b'\0')
        em.ret(eax=0, argbytes=0)
    Pv = obj(c, 0x40, {0x14: e.stub_fn('printf-like', pfmt)}, nslots=0x20)
    e.w32(0x724270, Pv)
    O2 = obj(c, 0x40, {0x2c: pystub(c, 3, this=True, pop=0)}, nslots=0x40)
    Eo = obj(c, 0x40, {0x20: pystub(c, 2, this=True, ret=O2)}, nslots=0x40)
    e.w32(0x700390, Eo)
    # records
    A4, A8 = rnd(c, 0x10), rnd(c, 0x10)

    def strobj():
        L = r.choice([0, 1, 2, 5, 9, 12, 20])
        sp = e.alloc(0x40, 4)
        e.wbytes(sp, bytes(r.choice(b'abcdefghijklmnopqrstuvwxyz') for _ in range(L)) + b'\0')
        So = rnd(c, 0x20)
        w32u(So + 0xc, sp)
        e.wbytes(So + 0x10, struct.pack('<H', r.choice([0, 1, 5, L, L + 1, L + 2, 30, 0x100])))
        return So
    # types outside {1, 2, 4} take the assert path whose text buffer is never initialised (strlen walks past the 0x68 byte local into the stack cookie): the result depends on the
    # frame layout, so it is not comparable and is left out
    ty = r.choice([1, 1, 2, 2, 4, 4, 4])
    Vrec = e.alloc(8, 4)
    val = {1: rb(), 2: struct.unpack('<I', struct.pack('<f', f32(r.uniform(-9, 9))))[0], 4: strobj()}.get(ty, r.choice([0, rb()]))
    if ty != 4 and r.random() < 0.2:
        val = 0
    w32u(Vrec, val)
    e.wbytes(Vrec + 4, bytes([ty]))
    ty2 = r.choice([0, 4, 4, 1, 3])
    Frel = obj(c, 0x40, {0x28: pystub(c, 0, this=True)}, nslots=0x40)
    V2rec = e.alloc(8, 4)
    w32u(V2rec, Frel if ty2 == 4 else rb())
    e.wbytes(V2rec + 4, bytes([ty2]))
    m = {A4: Vrec, A8: V2rec}
    hook_rec(c, 0x5003d0, 1, pop=4, this=True, ret=lambda emu, k: m[emu.reg('ecx')])
    hook_rec(c, 0x634273, 2, pop=0)
    pool = [e.alloc(0x100, 4) for _ in range(4)]
    cnt = [0]

    def alloc_ret(emu, k):
        cnt[0] += 1
        return pool[(cnt[0] - 1) % 4]
    hook_rec(c, 0x41e290, 1, pop=0, ret=alloc_ret)
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)
    # the object being built
    this = obj(c, 0x40, {0x24: pystub(c, 0, this=True, ret=lambda emu, k: rb())}, nslots=0x40)
    dest = e.alloc(0x100, 4)
    w32u(this + 0xc, dest)
    e.wbytes(this + 0x10, struct.pack('<H', r.choice([0, 1, 2, 5, 6, 10, 11, 12, 19, 20, 0x100])))
    cmd = bytes(e.rbytes(0x6b9c20, 24)).split(b'\0')[0]
    s0 = e.alloc(0x40, 4)
    e.wbytes(s0, (cmd if r.random() < 0.3 else b'other' + bytes([r.randrange(65, 90)])) + b'\0')
    args = e.alloc(16, 4)
    w32u(args, s0)
    w32u(args + 4, A4)
    w32u(args + 8, A8)
    return [this, args]


S(0x604a60, 'script_to_string', 'thiscall', None, ret=None, gen=g604a60)
