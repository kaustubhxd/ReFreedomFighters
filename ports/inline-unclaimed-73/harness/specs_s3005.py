"""specs_s3005.py - area 73 batch 5 (residue 12): ZKillBox::~ZKillBox (0x5b1a00). The render control (g_sys+0x9b) has a
logging slot +0x34 (one argument). The assert pointer at 0x7003b0 is a logging stub (no arguments); 0x4690b0 (bare ret,
cdecl, two arguments) is hooked and logged. Flags cover 0, 1, 4, 5 and random words."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _dtor(c):
    e = c.emu
    self_o = _rnd(c, 0x100)
    ctl = _rnd(c, 0x100)
    e.w32(ctl, e.logging_vtable('rendctl34', 0x38 // 4, impl={0x34: lambda em, a: (0, None)}, argwords={0x34: 1}))
    sys = _rnd(c, 0x200)
    e.w32(sys + 0x9b, ctl)
    e.w32(0x70039c, sys)

    def assert_fn(em, r):
        em.calllog.append(('assert7003b0', 0, None, ()))
        em.ret(eax=0, argbytes=0)

    e.w32(0x7003b0, e.stub_fn('assert', assert_fn))

    def h4690b0(em, r):
        em.calllog.append(('4690b0', 0, None, (em.arg32(0), em.arg32(1))))
        em.ret(argbytes=0)

    e.hook(0x4690b0, h4690b0)
    flags = c.rng.choice([0, 1, 4, 5, 3, c.rng.getrandbits(32)])
    return [self_o, flags]


S(0x5b1a00, 'ZKillBox::~ZKillBox (unknown) thiscall', 'thiscall', None, ret='eax', gen=_dtor,
  note='area 73 batch 5; vtable 0x686874; ctl slot +0x34(this); assert or 0x4690b0(this, 0x8d)')
