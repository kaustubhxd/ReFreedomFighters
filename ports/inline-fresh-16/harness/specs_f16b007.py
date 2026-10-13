"""specs_f16b007.py - fresh slice 16 batch 7 (see src/f16b007.cpp)."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, sysobj
from f16help import phook, codeaddr, crt, reporter, fval, floorstub


def _vobj(c, seq, slots):
    """Object whose vtable slots are Python hooks: slots = {off: (nargs, ret, act)} (thiscall, callee pops)."""
    vt = c.emu.alloc(max(slots) + 4, 4)
    for off, (n, ret, act) in slots.items():
        f = codeaddr(c)
        phook(c, seq, f, n, ret=ret, this=True, pop=True, act=act)
        c.emu.w32(vt + off, f)
    o = rnd(c, 0x20)
    c.emu.w32(o, vt)
    return o


def _5b7(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    vals = [r.getrandbits(32) for _ in range(4)]
    k = [0]

    def wr(e, a):
        if r.random() < 0.8:
            e.w32(a[0], vals[k[0] % 4])
        k[0] += 1
    rd = _vobj(c, seq, {0x40: (1, 0, wr), 0x50: (1, 0, wr)})
    db = _vobj(c, seq, {0x58: (1, lambda e: r.getrandbits(32), None)})
    sysobj(c, db=db)
    return [rnd(c, 0x10), rd]


def _433(c):
    clear_hooks(c)
    return [rnd(c, 0x110)]


def _4f0(c):
    r = c.rng
    clear_hooks(c)
    floorstub(c)
    v = rnd(c, 8)
    c.emu.w32(v + 4, fval(c) if r.random() < 0.3 else __import__('struct').unpack('<I', __import__('struct').pack('<f', r.uniform(-500, 500)))[0])
    g = rnd(c, 0x50)
    c.emu.wf32(g + 0x44, r.uniform(0, 300)) if r.random() < 0.8 else c.emu.w32(g + 0x44, fval(c))
    me = rnd(c, 0x50)
    c.emu.w8(me + 0x20, r.getrandbits(8))
    c.emu.w32(me + 8, g)
    return [me, v]


def _570(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    vals = [r.getrandbits(32) for _ in range(5)] + [r.choice([0, 1, r.getrandbits(32)])]
    k = [0]

    def nxt(e):
        v = vals[k[0] % 6]
        k[0] += 1
        return v
    phook(c, seq, 0x4e5e60, 0, ret=nxt, this=True)
    return [rnd(c, 0x1c0), rnd(c, 0x10)]


def _57c(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    phook(c, seq, 0x561020, 0, this=True)
    a = obj(c, 0x50, {0x44: stub(c, seq, 1, ret=rnd(c, 0x40) if r.random() < 0.8 else 0)})
    db = rnd(c, 0x20)
    c.emu.w32(db + 8, a)
    sysobj(c, db=db)
    return [rnd(c, 0x20)]


def _421(c):
    clear_hooks(c)
    crt(c)
    return [rnd(c, 0x1910)]


S(0x5b7e40, 'FUN_5b7e40 (read 2 handles + 2 words)', 'thiscall', None, ret=None, gen=_5b7, note='f16b007')
S(0x433ec0, 'FUN_433ec0 (ctor, vtable 0x67a3b0)', 'thiscall', None, ret='eax', gen=_433, note='f16b007; MYSTR ctor runs real; SEH not reproduced')
S(0x4f0840, 'ZWINOBJ::MakeVerticalAlignment', 'thiscall', None, ret=None, gen=_4f0, note='f16b007; floor stubbed (same stub both sides)')
S(0x570680, 'CSewerMenu::CopyEventDataBlock', 'thiscall', None, ret=None, gen=_570, note='f16b007')
S(0x57c480, 'FUN_57c480 (create CBaseWindow 0x6aa7b4)', 'thiscall', None, ret='eax', gen=_57c, note='f16b007; SEH not reproduced')
S(0x421680, 'ZSysInterfaceGC::InitKeyMap', 'thiscall', None, ret=None, gen=_421, note='f16b007; memset stubbed')
