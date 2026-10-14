"""specs_s5826.py - unclaimed-57, batch 126: 0x5d4b80 (CBoxAutoFire::Init2, GUESS name), thiscall, no args, plain ret. this+0x58 is a key (0 in about one case in five,
which takes the early exit). The sub-object (engine +0x9b) has slot +0x58 (one arg, logged; returns object A), slot +0x4c (no args, returns a per-case dword), and a
dword at +0xadc (random). A has slot +0x2c4 (two args, logged; returns object B). B has slot +0x2c (no args, logged). The assert hook (0x7003b0) is a logging stub
that is always set (the original's null branch is an int3)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d4b80(c):
    e = c.emu
    rnd = c.rng
    key = 0 if rnd.random() < 0.2 else rnd.getrandbits(32)
    r4c = rnd.getrandbits(32)
    log = []

    def hsub58(em, r):
        em.calllog.append(('s58', 0, None, (em.arg32(0),)))
        em.ret(eax=A_obj, argbytes=4)

    def hsub4c(em, r):
        # one stack argument: the object B (the helper pushes esi before the call)
        em.calllog.append(('s4c', 'B' if em.arg32(0) == B_obj else 'other', None, ()))
        em.ret(eax=r4c, argbytes=4)

    def hA2c4(em, r):
        em.calllog.append(('A2c4', 0, None, (em.arg32(0), em.arg32(1))))
        em.ret(eax=B_obj, argbytes=8)

    def hB2c(em, r):
        em.calllog.append(('B2c', 0, None, ()))
        em.ret(eax=0, argbytes=0)

    def assert_fn(em, r):
        em.calllog.append(('assert', 0, None, ()))
        em.ret(eax=0, argbytes=0)

    vt_sub = e.fake_vtable('d4b80_sub', 200, {0x58: hsub58, 0x4c: hsub4c})
    vt_A = e.fake_vtable('d4b80_A', 200, {0x2c4: hA2c4})
    vt_B = e.fake_vtable('d4b80_B', 200, {0x2c: hB2c})
    A_obj = _rnd(c, 0x40)
    e.w32(A_obj, vt_A)
    B_obj = _rnd(c, 0x40)
    e.w32(B_obj, vt_B)
    sub = _rnd(c, 0x1000)
    e.w32(sub, vt_sub)
    e.w32(sub + 0xadc, rnd.getrandbits(32))
    eng = _rnd(c, 0x2000)
    e.w32(eng + 0x9b, sub)
    e.w32(0x70039c, eng)
    e.w32(0x7003b0, e.stub_fn('assert', assert_fn))
    self_obj = _rnd(c, 0x100)
    e.w32(self_obj + 0x58, key)
    e.w32(self_obj + 0x5c, rnd.getrandbits(32))
    return [self_obj]


S(0x5d4b80, 'CBoxAutoFire::Init2 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_d4b80,
  note='unclaimed-57 batch 126; assert hook 0x7003b0 logs; sub slots +0x58, +0x4c; A slot +0x2c4; B slot +0x2c')
