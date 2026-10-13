"""specs_f15b007.py - fresh slice 15 batch 7 (see src/f15b007.cpp)."""
import struct
from pilot import S, F
from sthelp import rnd, obj, stub, Seq, clear_hooks, hook, HOOKED
from f15help import phook, codeaddr, loghook, crt


def _r(c):
    return c.rng.getrandbits(32)


def _sys(c, db=None, extra=None, size=0x1a00):
    s = rnd(c, size)
    if db is not None:
        c.emu.w32(s + 0x9b, db)
    for k, v in (extra or {}).items():
        c.emu.w32(s + k, v)
    c.emu.w32(0x70039c, s)
    return s


def _cap(c, n):
    """A logging area plus an act that copies n bytes behind the pointer arg idx into it."""
    log = c.emu.alloc(n * 4 + 8, 4)
    k = [0]

    def mk(idx, m=n):
        def act(e, args):
            e.wbytes(log + (k[0] % 4) * n, bytes(e.rbytes(args[idx], m)))
            k[0] += 1
        return act
    return mk


def _578(c):
    seq = Seq(c); clear_hooks(c)
    r = c.rng
    txt = bytes(r.choice(b'abcdef') for _ in range(r.randint(0, 40))) + b'\0'

    def fmt(e, args):
        e.wbytes(args[1], txt)
    a198 = codeaddr(c)
    phook(c, seq, a198, 4, act=fmt)             # cdecl: caller pops
    a = obj(c, 0x200, {0x198: a198})
    sysv = obj(c, 0x200, {0x190: stub(c, seq, 0, ret=a)})
    flagv = r.choice([0, 1, 0x80, 0xff])
    mk = _cap(c, 0x30)
    cp = mk(0)

    def look(e, args):
        cp(e, args)
        if flagv:
            e.w8(args[1], flagv)
    a90 = codeaddr(c)
    phook(c, seq, a90, 2, this=True, pop=True, act=look)
    o = obj(c, 0x100, {0x90: a90})
    d = obj(c, 0x140, {0x134: stub(c, seq, 0, ret=o)})
    c.emu.w32(sysv + 0x9b, d)
    c.emu.w32(0x70039c, sysv)
    return [rnd(c, 0x200)]


def _655(c):
    seq = Seq(c); clear_hooks(c)
    r = c.rng
    vals = {k: r.choice([0, 1, 0x8000, 0x8001, 0xffff, r.getrandbits(16)]) for k in (0x10, 0x11, 0x12)}
    klog = c.emu.alloc(16, 4)
    kn = [0]

    def key(e, rr):
        k = e.arg32(0)
        e.w32(klog + 4 * (kn[0] % 4), k); kn[0] += 1
        e.ret(eax=(r_hi << 16) | vals.get(k, 0), argbytes=4)
    r_hi = r.getrandbits(16)
    c.emu.stub_import('GetAsyncKeyState', key)
    caplog = c.emu.alloc(8, 4)

    def cap(e, rr):
        e.w32(caplog, e.arg32(0)); e.w32(caplog + 4, e.r32(caplog + 4) + 1)
        e.ret(eax=_rv, argbytes=4)
    _rv = _r(c)
    c.emu.stub_import('SetCapture', cap)
    _sys(c)
    me = rnd(c, 0x1190)
    c.emu.w32(me + 0x137, r.choice([0, 1, 0x100, _r(c)]))
    return [me]


def _5ac(c):
    seq = Seq(c); clear_hooks(c); crt(c)
    r = c.rng
    n = r.choice([0, 1, 5, 40, 0x3ff, r.randint(0, 0x3ff)])
    src = rnd(c, n + 8)
    mk = _cap(c, 0x48)
    a1, a2 = mk(0), mk(0)
    loghook  # noqa
    hk1 = phook(c, seq, 0x5abf00, 1, this=True, pop=True, act=a1)
    hk2 = phook(c, seq, 0x5ac140, 1, this=True, pop=True, act=a2)
    me = rnd(c, 0x80)
    c.emu.w32(me + 0x6a, r.choice([0, 1, 0x100, _r(c)]))
    return [me, src, n]


def _cmm(flag):
    def g(c):
        seq = Seq(c); clear_hooks(c)
        r = c.rng
        c.emu.w32(flag, r.choice([0, 0, 1, _r(c)]))
        mk = _cap(c, 13)
        phook(c, seq, 0x59a9b0, 1, this=False, pop=True, act=lambda e, a: (mk(0)(e, [e.reg('ecx')]), None)[1])
        phook(c, seq, 0x4ff9d0, 0, this=False, pop=True, act=lambda e, a: (mk(0)(e, [e.reg('ecx')]), None)[1])
        a1c = codeaddr(c)
        phook(c, seq, a1c, 1, this=True, pop=True, act=lambda e, a: (mk(0)(e, a), None)[1])
        return [obj(c, 0x40, {0x1c: a1c})]
    return g


def _5ed(c):
    seq = Seq(c); clear_hooks(c)
    r = c.rng
    hook(c, seq, 0x5ebe00, 5, ret=_r(c))
    blocks = [rnd(c, 0x10) for _ in range(6)]
    k = [0]

    zlog = c.emu.alloc(4 * 8 * 4, 4)
    c.emu.mu.mem_write(0, bytes(16))      # same null-page start on both sides

    def nw(e):          # also snapshot the null page (a write through a null vector end must not happen)
        e.wbytes(zlog + 16 * (k[0] % 8), bytes(e.rbytes(0, 16)))
        b = blocks[k[0] % 6]; k[0] += 1
        return b
    loghook(c, seq, 0x41e290, 1, ret=nw)
    plog = c.emu.alloc(32, 4)
    pk = [0]

    def ins(e, args):
        e.w32(plog + 4 * (pk[0] % 8), e.r32(args[1])); pk[0] += 1
    phook(c, seq, 0x5fe3b0, 2, this=True, pop=True, act=ins)
    me = rnd(c, 0xe0)
    n = r.choice([0, 1, 2, 3, 4, 4])
    c.emu.w32(me + 0x3e, n)
    vec = rnd(c, 0x20)
    room = r.choice([0, 1, 2, 8])
    endp = r.choice([vec, vec, 0])
    c.emu.w32(me + 0xcf, endp)
    c.emu.w32(me + 0xd3, (endp + 4 * room) & 0xffffffff)
    return [me, _r(c), _r(c), _r(c), _r(c), _r(c)]


def _613(c):
    seq = Seq(c); clear_hooks(c)
    r = c.rng
    s = rnd(c, 0x10)
    lockv = (_r(c), _r(c))

    def lock(e, args):
        e.w32(args[2], lockv[0]); e.w32(args[2] + 4, lockv[1])
    a40, a44 = codeaddr(c), codeaddr(c)
    phook(c, seq, a40, 5, pop=True, act=lock)
    loghook(c, seq, a44, 2, pop=True)
    surf = obj(c, 0x10, {0x40: a40, 0x44: a44})
    desc = rnd(c, 0x40); c.emu.w32(desc + 0x38, surf)
    log = c.emu.alloc(0x40, 4)

    def take(e, args):   # copy every defined word of the descriptor (bytes 0x29..0x2b are never written)
        d = bytes(e.rbytes(args[0], 0x30))
        e.wbytes(log, d[:0x29] + d[0x2c:])
    a14 = codeaddr(c)
    phook(c, seq, a14, 2, this=True, pop=True, act=take)
    tex = obj(c, 0x40, {0x38: stub(c, seq, 1, ret=s), 0x14: a14})
    return [rnd(c, 0x10), tex, desc]


N = 'f15b007'
S(0x578eb0, 'FUN_578eb0 (format + db slot 0x134 query)', 'thiscall', None, ret='al', gen=_578, note=N + '; buffer slots Python, cookie exe code')
S(0x655270, 'FUN_655270 (modifier keys + SetCapture)', 'thiscall', None, ret=None, gen=_655, note=N + '; GetAsyncKeyState/SetCapture Python')
S(0x5aca30, 'CMessageBasics::SetTextLen', 'thiscall', None, ret=None, gen=_5ac, note=N + '; Reformat* hooked, memcpy Python, n >= 0x400 not run')
S(0x51b530, 'FUN_51b530 (build list via slot 0x1c)', 'thiscall', None, ret=None, gen=_cmm(0x701800), note=N + '; vector reserve/dtor hooked')
S(0x55f870, 'ZFFHeroIf::buildCMM', 'thiscall', None, ret=None, gen=_cmm(0x7140c8), note=N + '; vector reserve/dtor hooked')
S(0x5ed030, 'CSprite2D::Init', 'thiscall', None, ret=None, gen=_5ed, note=N + '; CSprite3D::Init, new, insert hooked')
S(0x613870, 'ZTextureManagerGC::InstallTextureBuffer', 'thiscall', None, ret=None, gen=_613, note=N + '; COM surface Python')
