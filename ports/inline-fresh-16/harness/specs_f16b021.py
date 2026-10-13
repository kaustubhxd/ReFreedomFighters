"""specs_f16b021.py - fresh slice 16 batch 21 (see src/f16b021.cpp)."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, sysobj
from f16help import phook, codeaddr, fval


def _5fc(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    phook(c, seq, 0x5fc590, 3, this=True, pop=True, ret=rnd(c, 0x60))
    phook(c, seq, 0x41e290, 1, ret=rnd(c, 0x20) if r.random() < 0.85 else 0)
    phook(c, seq, 0x5f3480, 3, this=True, pop=True, ret=r.getrandbits(32))
    phook(c, seq, 0x5fcd70, 3, this=True, pop=True)
    me = rnd(c, 0x20)
    c.emu.w8(me, r.choice([0, 0, 0, 1, 0x80]))
    return [me, r.getrandbits(32), r.choice([0, rnd(c, 8)]), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


def _45a(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    phook(c, seq, 0x45ace0, 2, pop=True, ret=r.getrandbits(32),
          act=lambda e, a: e.w32(rec, e.reg('ecx')) or e.w32(rec + 4, e.reg('edx')) or None)
    rec = c.emu.alloc(8, 4)
    phook(c, seq, 0x45c4b0, 1, ret=rnd(c, 0x30) if r.random() < 0.8 else 0)
    phook(c, seq, 0x43de40, 3, this=True, pop=True, ret=r.getrandbits(32))
    phook(c, seq, 0x4dcdf0, 1, this=True, pop=True)
    return [r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), r.choice([0, r.getrandbits(32)])]


def _5b8(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    phook(c, seq, 0x469870, 0, this=True)
    db = obj(c, 0x200, {0x114: stub(c, seq, 4, ret=r.getrandbits(32))})
    sysobj(c, db=db)
    return [rnd(c, 0xf0)]


def _43e(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    rec = c.emu.alloc(12, 4)
    ca = codeaddr(c)

    def cp(e, a):
        if 0x0fe00000 <= a[2] < 0x0ff00000:
            e.wbytes(rec, bytes(e.rbytes(a[2], 12)))
    phook(c, seq, ca, 3, this=True, pop=True, act=cp)
    buf = obj(c, 0x100, {0x80: stub(c, seq, 3), 0x88: stub(c, seq, 3), 0xdc: ca})
    me = rnd(c, 0x40)
    c.emu.w32(me + 0x34, fval(c))
    return [me, buf, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x5fcb80, 'PPOLibrary_t::loadProcess', 'thiscall', None, ret='eax', gen=_5fc, note='f16b021; SEH not reproduced')
S(0x45ae80, 'FUN_45ae80 (construct ZSTDOBJ, tag 0x24, vtable 0x683e50)', 'fastcall', None, ret='eax', gen=_45a, note='f16b021; SEH not reproduced')
S(0x5b8340, 'ZFFSimpleTrain2::ZFFSimpleTrain2', 'thiscall', None, ret='eax', gen=_5b8, note='f16b021; SEH not reproduced')
S(0x43e640, 'ZHELPER::Draw', 'thiscall', None, ret=None, gen=_43e, note='f16b021; cookie not reproduced')
