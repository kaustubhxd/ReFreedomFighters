"""specs_s1017.py - unclaimed-07 batch 17: ZItemTemplateWeapon::ModifyState (0x46f930).
The argument com is a logging vtable: slot +0x88 (name, out pointer) writes a value through the out pointer (a stack
address, so it is not logged; the name is logged). The engine control object at g_sys+0x9b has slot +0x58 (logged).
The local helper's constructor (0x4d2280) and destructor (0x4d2330) are hooked to logging stubs (no arguments)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _modify(c):
    e = c.emu
    self_o = _rnd(c, 0x100)
    com = _rnd(c, 0x100)
    vals = [c.rng.getrandbits(32) for _ in range(3)]

    def slot88(em, r):
        name = em.arg32(0)
        out = em.arg32(1)
        em.calllog.append(('com', 0x88, em.reg('ecx'), (name,)))
        v = vals[0] if name == 0x68884c else (vals[1] if name == 0x688a30 else vals[2])
        em.w32(out, v)
        em.ret(eax=0, argbytes=8)

    e.w32(com, e.fake_vtable('com', 0x90 // 4, {0x88: slot88}))

    ctl = _rnd(c, 0x100)
    e.w32(ctl, e.logging_vtable('ctl', 0x60 // 4, impl={0x58: lambda em, a: (0, None)}, argwords={0x58: 1}))
    sys = _rnd(c, 0x200)
    e.w32(sys + 0x9b, ctl)
    e.w32(0x70039c, sys)

    def ctor(em, r):
        em.calllog.append(('ctor4d2280', 0, None, ()))   # ECX is the local object's stack address
        em.ret()

    def dtor(em, r):
        em.calllog.append(('dtor4d2330', 0, None, ()))
        em.ret()

    e.hook(0x4d2280, ctor)
    e.hook(0x4d2330, dtor)
    return [self_o, com]


S(0x46f930, 'ZItemTemplateWeapon::ModifyState (unknown) thiscall', 'thiscall', None, ret='al', gen=_modify,
  note='unclaimed-07 batch 17; com slot +0x88 x3; ctl slot +0x58(out2); ctor/dtor 0x4d2280/0x4d2330')
