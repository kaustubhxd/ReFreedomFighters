"""specs_f16b012.py - fresh slice 16 batch 12 (see src/f16b012.cpp)."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, sysobj
from f16help import phook, codeaddr


def _handler(c, seq, ret=0):
    h = codeaddr(c)
    phook(c, seq, h, 0, ret=ret)
    c.emu.w32(0x7003b0, h)


def _56a(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    phook(c, seq, 0x469870, 0, this=True)
    a = obj(c, 0x50, {0x44: stub(c, seq, 1, ret=rnd(c, 0x60) if r.random() < 0.8 else 0)})
    db = rnd(c, 0x20)
    c.emu.w32(db + 8, a)
    sysobj(c, db=db)
    return [rnd(c, 0x20)]


def _455(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    _handler(c, seq)
    rec = c.emu.alloc(12, 4)

    def grab(e, a):
        e.wbytes(rec, bytes(e.rbytes(a[2], 12)))
    f = codeaddr(c)
    phook(c, seq, f, 4, this=True, pop=True, act=grab)
    vt = c.emu.alloc(0x21c, 4)
    c.emu.w32(vt + 0x218, f)
    me = rnd(c, 0x830)
    c.emu.w32(me, vt)
    k = r.getrandbits(16)
    c.emu.w16(me + 0x821, k)
    sysobj(c)
    data = rnd(c, 0x20)
    c.emu.w32(data, 0x12345678 if r.random() < 0.8 else r.getrandbits(32))
    cmd = r.choice([k, k, k | 0x10000, (k + 1) & 0xffff, r.getrandbits(32)])
    return [me, cmd, data]


def _560(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    recs = []

    def grabber():
        rec = c.emu.alloc(16, 4)
        recs.append(rec)

        def g(e, a):
            e.wbytes(rec, bytes(e.rbytes(a[0], 16)))
            e.w32(a[0] + 4, e.r32(a[0] + 4) + 0x11)
        return g

    def grab_this(rec):
        def g(e, r_):
            e.wbytes(rec, bytes(e.rbytes(e.reg('ecx'), 16)))
            e.ret(eax=0)
        return g
    phook(c, seq, 0x59a9b0, 1, this=False, pop=True, act=None)
    rec0 = c.emu.alloc(16, 4)
    rec2 = c.emu.alloc(16, 4)
    phook(c, seq, 0x59a9b0, 1, pop=True, act=lambda e, a: e.wbytes(rec0, bytes(e.rbytes(e.reg('ecx'), 16))))
    phook(c, seq, 0x4ff9d0, 0, act=lambda e, a: e.wbytes(rec2, bytes(e.rbytes(e.reg('ecx'), 16))))
    f = codeaddr(c)
    phook(c, seq, f, 1, this=True, pop=True, act=grabber())
    vt = c.emu.alloc(0x20, 4)
    c.emu.w32(vt + 0x1c, f)
    me = rnd(c, 0x10)
    c.emu.w32(me, vt)
    c.emu.w32(0x714198, 0 if r.random() < 0.85 else r.getrandbits(32))
    return [me]


def _576(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    names = [b'', b'a', b'ab', b'abc', b'hero', b'<NONE>', b'heRo']

    def cstr(b):
        a = c.emu.alloc(len(b) + 1, 1)
        c.emu.wbytes(a, b + b'\0')
        return a
    its = []
    for _ in range(r.randint(0, 5)):
        e = rnd(c, 8)
        c.emu.w32(e + 4, cstr(r.choice(names)) if r.random() < 0.85 else 0)
        it = rnd(c, 0x58)
        c.emu.w32(it + 0x54, e)
        its.append(it)

    def adv(e, a):
        cur = e.r32(a[0])
        i = its.index(cur) if cur in its else -1
        e.w32(a[0], its[i + 1] if 0 <= i < len(its) - 1 else 0)
    f = codeaddr(c)
    phook(c, seq, f, 1, this=True, pop=True, act=adv)
    vt = c.emu.alloc(0x54, 4)
    c.emu.w32(vt + 0x50, f)
    lst = rnd(c, 0x10)
    c.emu.w32(lst, vt)
    c.emu.w32(lst + 8, its[0] if its else 0)
    me = rnd(c, 0x1d0)
    c.emu.w32(me + 0x1c8, lst)
    return [me, cstr(r.choice(names))]


S(0x56adc0, 'FUN_56adc0 (create object 0x6a7858)', 'thiscall', None, ret='eax', gen=_56a, note='f16b012; SEH not reproduced')
S(0x455700, 'ZParticleController::ClassCommand', 'thiscall', None, ret='eax', gen=_455, note='f16b012; slot 0x218 records the 12-byte local; cookie not reproduced')
S(0x560280, 'FUN_560280 (local list of 50, slot 0x1c)', 'thiscall', None, ret=None, gen=_560, note='f16b012; callees record the 16-byte local; SEH not reproduced')
S(0x5761c0, 'FUN_5761c0 (find by name)', 'thiscall', None, ret='eax', gen=_576, note='f16b012')
