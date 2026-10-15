"""specs_s2904.py - area 73 batch 4 (residue 12): CEnemyFlag::Init2 (0x5c17c0).
Objects per case: this (the enemy flag), the render control ctl at g_sys+0x9b (slot +0x58 is called twice, +0x114 with six
arguments whose fifth is a stack out pointer that the stub fills, +0x138 twice), the holder at ctl+0xadc (slot +0x25c, returns r
or 0), r (slot +0x100), this+0x44 (slot +0x84, logged), b and c (slot +0x88 fills the stack out pointer), b2 (slot +0x128).
The helper 0x5c21e0 is hooked (logged). Null paths are drawn (r null 15%, b2 null 25%, local_c zero 30%)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _const(v):
    return lambda em, a: (v, None)


def _init2(c):
    e = c.emu
    self_o = _rnd(c, 0x200)
    holder_val = c.rng.random()

    # r: slot +0x100 gives w; returned by the holder's slot +0x25c
    r = None
    if holder_val >= 0.15:
        r = _rnd(c, 0x40)
        e.w32(r, e.logging_vtable('flag_r', 0x108 // 4, impl={0x100: _const(c.rng.getrandbits(32))},
                                  argwords={0x100: 1}))
    holder = _rnd(c, 0x40)
    e.w32(holder, e.logging_vtable('flag_holder', 0x260 // 4, impl={0x25c: _const(r or 0)}, argwords={0x25c: 2}))

    # this+0x44: slot +0x84 (logged)
    o44 = _rnd(c, 0x40)
    e.w32(o44, e.logging_vtable('flag_44', 0x88 // 4, impl={0x84: _const(0)}, argwords={0x84: 1}))
    e.w32(self_o + 0x44, o44)

    # b and c: slot +0x88 writes a value through the stack out pointer
    vb = c.rng.getrandbits(32)
    vc = c.rng.getrandbits(32)

    def fill88(v):
        def h(em, rr):
            em.calllog.append(('88', 0, em.reg('ecx'), (em.arg32(0),)))
            em.w32(em.arg32(1), v)
            em.ret(eax=0, argbytes=8)
        return h

    b = _rnd(c, 0x40)
    e.w32(b, e.fake_vtable('flag_b', 0x90 // 4, {0x88: fill88(vb)}))
    cobj = _rnd(c, 0x40)
    e.w32(cobj, e.fake_vtable('flag_c', 0x90 // 4, {0x88: fill88(vc)}))

    # b2: slot +0x128 (logged), reached when the second +0x58 result is non-null
    b2_present = c.rng.random() >= 0.25
    b2 = _rnd(c, 0x40)
    e.w32(b2, e.logging_vtable('flag_b2', 0x130 // 4, impl={0x128: _const(0)}, argwords={0x128: 1}))

    # the render control: ctl+0xadc is the holder; slot +0x58 is called twice (first result is stored, second gives b2);
    # +0x114 writes the out pointer (fifth argument) and returns a dword; +0x138 returns b then c
    ret114 = c.rng.getrandbits(32)
    local_c_val = 0 if c.rng.random() < 0.3 else c.rng.getrandbits(32) | 1
    seq58 = [c.rng.getrandbits(32), b2 if b2_present else 0]
    seq138 = [b, cobj]

    def h58(em, a):
        return (seq58.pop(0) if seq58 else 0, None)

    def h138(em, a):
        return (seq138.pop(0) if seq138 else 0, None)

    def h114(em, rr):
        out = em.arg32(4)
        em.calllog.append(('ctl114', 0x114, em.reg('ecx'), (em.arg32(0), em.arg32(1), em.arg32(2), em.arg32(3), em.arg32(5))))
        em.w32(out, local_c_val)
        em.ret(eax=ret114, argbytes=24)

    ctl = _rnd(c, 0x200)
    e.w32(ctl, e.fake_vtable('ctl', 0x140 // 4, {0x58: _logged_stub('ctl58', 0x58, 1, h58),
                                              0x114: h114,
                                              0x138: _logged_stub('ctl138', 0x138, 0, h138)}))
    e.w32(ctl + 0xadc, holder)
    sys = _rnd(c, 0x200)
    e.w32(sys + 0x9b, ctl)
    e.w32(0x70039c, sys)

    # b2 receives the slot +0x128 call; the helper 0x5c21e0 is logged
    def h5c21e0(em, rr):
        em.calllog.append(('5c21e0', 0, em.reg('ecx'), (em.arg32(0),)))
        em.ret(argbytes=4)

    e.hook(0x5c21e0, h5c21e0)
    e.w32(self_o + 0x50, 0)
    return [self_o]


def _logged_stub(name, off, nargs, fn):
    def h(em, rr):
        args = tuple(em.arg32(k) for k in range(nargs))
        em.calllog.append((name, off, em.reg('ecx'), args))
        val, _ = fn(em, args)
        em.ret(eax=val, argbytes=4 * nargs)
    return h


S(0x5c17c0, 'CEnemyFlag::Init2 (unknown) thiscall', 'thiscall', None, ret=None, gen=_init2,
  note='area 73 batch 4; holder +0x25c, r +0x100, this+0x44 +0x84, b/c +0x88, ctl +0x58 x2, +0x114 (six args), +0x138 x2, b2 +0x128')
