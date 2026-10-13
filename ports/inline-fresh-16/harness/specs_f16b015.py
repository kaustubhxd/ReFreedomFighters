"""specs_f16b015.py - fresh slice 16 batch 15 (see src/f16b015.cpp)."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, sysobj
from f16help import phook, codeaddr


def _490(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    tag = r.getrandbits(32)
    rec = c.emu.alloc(4, 4)
    phook(c, seq, 0x48c4b0, 2, this=True, pop=True, act=lambda e, a: e.w32(a[0], tag))
    phook(c, seq, 0x4cc1d0, 0, this=True, ret=lambda e: e.r32(e.reg('ecx')) ^ 0x5a5a5a5a)
    phook(c, seq, 0x4cbec0, 0, this=True, act=lambda e, a: e.w32(rec, e.r32(e.reg('ecx'))))
    o = obj(c, 0x70, {0x60: stub(c, seq, 5, ret=r.getrandbits(32))})
    c.emu.w32(0x700394, o)
    return [rnd(c, 0x40), r.getrandbits(32), r.getrandbits(32)]


def _42f(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    pool = c.emu.alloc(0x400, 4)
    nxt = [pool]
    cap0 = r.randint(1, 6)

    def assign(e, a):
        s = e.reg('ecx')
        b = nxt[0]
        nxt[0] += cap0 + 2
        e.w8(b, 0)
        e.w32(s, b)
        e.w32(s + 4, b)
        e.w32(s + 8, b + cap0)

    def grow(e, a):
        s = e.reg('ecx')
        b0, e0 = e.r32(s), e.r32(s + 4)
        n = a[0] + 1
        b = nxt[0]
        nxt[0] += n + 2
        e.wbytes(b, bytes(e.rbytes(b0, e0 - b0)) + b'\0')
        e.w32(s, b)
        e.w32(s + 4, b + (e0 - b0))
        e.w32(s + 8, b + n)
    phook(c, seq, 0x5f2d60, 2, this=True, pop=True, act=assign)
    phook(c, seq, 0x431270, 1, this=True, pop=True, act=grow)
    alpha = b'abcXYZ019_'
    n = r.randint(0, 20)
    txt = bytes(r.choice(alpha) if r.random() < 0.9 else r.choice(b' -.\x00\xff{') for _ in range(n))
    buf = c.emu.alloc(n + 1, 1)
    c.emu.wbytes(buf, txt + b'\0')
    pp = rnd(c, 4)
    c.emu.w32(pp, buf)
    s = rnd(c, 12)
    return [s, pp, buf + r.randint(0, n)]


def _fac(tag, ctor):
    def g(c):
        seq = Seq(c)
        r = c.rng
        clear_hooks(c)
        phook(c, seq, 0x45c4f0, 2, ret=rnd(c, 0x20) if r.random() < 0.8 else 0)
        phook(c, seq, 0x45c4b0, 1, ret=rnd(c, 0x20) if r.random() < 0.8 else 0)
        phook(c, seq, ctor, 3, this=True, pop=True, ret=r.getrandbits(32))
        return [r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), r.choice([0, r.getrandbits(32)])]
    return g


S(0x490bc0, 'ZEngineDataBase::GetRoomInsideTreeData', 'thiscall', None, ret=None, gen=_490, note='f16b015; MYSTR calls hooked; SEH/cookie not reproduced')
S(0x42f780, 'ZSysInterface::ReadVarToken', 'stdcall', None, ret=None, gen=_42f, note='f16b015; assign and grow hooked (Python string)')
S(0x4555c0, 'FUN_4555c0 (alloc 0x827 + ctor 0x455200)', 'fastcall', None, ret='eax', gen=_fac(0x827, 0x455200), note='f16b015; SEH not reproduced')
S(0x45b740, 'FUN_45b740 (alloc 0x6480 + ctor 0x45b2f0)', 'fastcall', None, ret='eax', gen=_fac(0x6480, 0x45b2f0), note='f16b015; SEH not reproduced')
