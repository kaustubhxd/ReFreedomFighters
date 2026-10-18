"""specs_s213129.py - batch 213129: option-change handler (jump table over the entry kind, printf-style vcalls with a double), Sonnet-w3b."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g57b0d0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rb = lambda: r.getrandbits(32)

    def w32u(addr, v):
        e.wbytes(addr, struct.pack('<I', v & 0xffffffff))

    def lg(emu, name, addr, n):
        emu.calllog.append((name, bytes(emu.rbytes(addr, n))))

    def instack(v):
        return 0x0fe00000 <= v < 0x0ff00000
    kind = r.randrange(1, 13) if r.random() < 0.94 else r.choice([0, 13, 40])
    small = kind in (1, 2, 3, 4, 5, 8, 9, 10, 11)
    if small:
        b = r.randrange(0, 4)
    elif kind == 7:
        b = r.choice([0, 1, 2, 3, 5, 8, 31, 32, 33, 0xffffffff, rb(), rb() & 0xff])
    elif kind == 12:
        b = r.choice([1000, 1000, 999, 1001, 0, 1, 7, 100, 0x7fffffff, 0x80000000, 0xffffffff, rb(), rb() & 0xffff])
    else:
        b = r.choice([0, 1, 7, 100, 1000, 0x7fffffff, 0x80000000, 0xffffffff, rb(), rb() & 0xffff])
    # the exe tables indexed by the value are filled at run time (zero in the image): give them random contents
    e.wbytes(0x6ecc60, bytes(r.getrandbits(8) for _ in range(0xb0)))
    # printf-style object P: slot 0x198 is cdecl (P, buf, fmt, args...) with ecx = P's vtable
    def pfmt(em, res_):
        P_, buf, fm = em.arg32(0), em.arg32(1), em.arg32(2)
        a3, a4 = em.arg32(3), em.arg32(4)
        em.calllog.append(('fmt', em.reg('ecx'), P_, fm, a3, a4 if fm == 0x6aa320 else 0))
        em.wbytes(buf, b'T%08x' % ((a3 ^ (a4 if fm == 0x6aa320 else 0)) & 0xffffffff) + b'\0')
        em.ret(eax=0, argbytes=0)
    pcode = e.stub_fn('printf-like', pfmt)
    Pv = obj(c, 0x40, {0x198: pcode}, nslots=0x80)
    # R and Q
    def h378(emu, res_):
        v = emu.arg32(0)
        if instack(v):
            emu.calllog.append(('txt', emu.reg('ecx'), bytes(emu.rbytes(v, 16)).split(b'\0')[0]))
        else:
            emu.calllog.append(('txt', emu.reg('ecx'), v))
        emu.ret(eax=0, argbytes=4)
    Rv = obj(c, 0x100, {0x310: pystub(c, 0, this=True, ret=kind),
                        0x378: e.stub_fn('settext', h378)}, nslots=0x100)
    w32u(Rv + 0x70, 0x20 if r.random() < 0.15 else r.choice([0, 1, 0x21, rb()]))
    Qv = obj(c, 0x40, {0x128: pystub(c, 1, this=True)}, nslots=0x60)
    cnt = [0]

    def t58(emu, k):
        cnt[0] += 1
        if cnt[0] == 1:
            return Rv
        return Qv if r.random() < 0.8 else 0
    Tv = obj(c, 0x40, {0x58: pystub(c, 1, this=True, ret=t58),
                       0x138: pystub(c, 0, this=True, ret=lambda emu, k: rb()),
                       0x114: pystub(c, 6, this=True, ret=lambda emu, k: rb())}, nslots=0x60)
    Cv = obj(c, 0x40, {0x64: pystub(c, 2, this=True), 0x68: pystub(c, 2, this=True), 0x6c: pystub(c, 1, this=True)}, nslots=0x40)

    def h1d0(emu, res_):
        a0, a1 = emu.arg32(0), emu.arg32(1)
        if instack(a1):
            emu.calllog.append(('u1d0', emu.reg('ecx'), a0, 'ptr', bytes(emu.rbytes(a1, 4))))
        else:
            emu.calllog.append(('u1d0', emu.reg('ecx'), a0, a1))
        emu.ret(eax=0, argbytes=8)

    def s1cc(emu, k):
        emu.wbytes(emu.arg32(0), struct.pack('<II', rb(), r.choice([0, 0xffffffff, 0x55555555, 0xaaaaaaaa, rb()])))
    Uv = obj(c, 0x40, {0x1d0: e.stub_fn('u1d0', h1d0),
                       0x1cc: pystub(c, 1, this=True, stackmark=(0,), side=s1cc)}, nslots=0x80)
    E = obj(c, 0x2000, {0xbc: pystub(c, 0, this=True, ret=Cv), 0x190: pystub(c, 0, this=True, ret=Pv)}, nslots=0x80)
    w32u(E + 0x9b, Tv)
    w32u(E + 0x190f, Uv)
    e.w32(0x70039c, E)
    hook_rec(c, 0x431410, 2, pop=8, this=True)
    hook_rec(c, 0x4314c0, 2, pop=8, this=True)
    hook_rec(c, 0x431580, 2, pop=8, this=True)
    hook_rec(c, 0x48aad0, 0, pop=0, this='mark', ret=lambda emu, k: rb(), side=lambda emu, k: lg(emu, 'pair', emu.reg('ecx'), 8))
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)
    return [rb(), b]


S(0x57b0d0, 'option_change', 'stdcall', None, ret=None, gen=g57b0d0)
