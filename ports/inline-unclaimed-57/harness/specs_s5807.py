"""specs_s5807.py - unclaimed-57, batch 107: 0x5d7e00 (GUESS name unnamed_5d7e00). Thiscall, no stack args, plain ret. The engine (global 0x70039c)
sub-object at +0x9b has its own fake vtable (slot +0x58: one argument, logged, returns a per-case object U) and, at +0x1c inside it, an object S with
a fake vtable: slot +0x54 (one arg, unused result) and +0x74 (one arg: returns a flag, from a per-case sequence of 0 to 3 ones then zero, so the
repeat loop runs 0 to 3 times). this+0x14e is an object T (null in about one case in five) with fake slots +0x4c (one arg, writes 0) and +0x5c
(one arg: writes a flag from a sequence ending in zero, returns a handle). U has fake slot +0x100 (one arg, logged). Callee 0x5d7bc0 (area 49's
function) is a logging stub with ECX; it writes nothing. The engine dword at +0x40 is random and this+0x1c4 is set to a random dword, so the
conditional copy is checked by the heap."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d7e00(c):
    e = c.emu
    seqA = [1] * c.rng.randrange(0, 4) + [0]
    r0 = 0 if c.rng.random() < 0.4 else 1
    seqB = [1] * c.rng.randrange(0, 4) + [0]
    hB = [c.rng.getrandbits(32) for _ in range(4)]
    ca = [0]
    cb = [0]
    cu = [0]

    def hS74(em, r):
        em.calllog.append(('S74', 0, None, (em.arg32(0) != 0,)))
        if ca[0] == 0:
            v = r0
        else:
            v = seqA[ca[0] - 1] if ca[0] - 1 < len(seqA) else 0
        ca[0] += 1
        em.ret(eax=v, argbytes=4)

    def hS54(em, r):
        em.calllog.append(('S54', 0, None, ()))
        em.ret(eax=0, argbytes=4)

    def h58(em, r):
        em.calllog.append(('58', 0, None, (em.arg32(0),)))
        em.ret(eax=U_obj, argbytes=4)

    def hT4c(em, r):
        em.calllog.append(('T4c', 0, None, ()))
        em.w32(em.arg32(0), 0)
        em.ret(eax=0, argbytes=4)

    def hT5c(em, r):
        i = cb[0]
        cb[0] += 1
        flag = seqB[i] if i < len(seqB) else 0
        em.calllog.append(('T5c', 0, None, (flag,)))
        em.w32(em.arg32(0), flag)
        em.ret(eax=hB[i % 4], argbytes=4)

    def hU100(em, r):
        em.calllog.append(('U100', 0, None, (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    def h5d7bc0(em, r):
        em.calllog.append(('5d7bc0', 0, 'S' if em.reg('ecx') == self_obj else 'other', ()))
        em.ret(eax=0, argbytes=0)
    e.hook(0x5d7bc0, h5d7bc0)

    vt_S = e.fake_vtable('d7e00_S', 200, {0x54: hS54, 0x74: hS74})
    vt_sub = e.fake_vtable('d7e00_sub', 200, {0x58: h58})
    vt_T = e.fake_vtable('d7e00_T', 200, {0x4c: hT4c, 0x5c: hT5c})
    vt_U = e.fake_vtable('d7e00_U', 200, {0x100: hU100})
    U_obj = _rnd(c, 0x40)
    e.w32(U_obj, vt_U)
    sub = _rnd(c, 0x100)
    e.w32(sub, vt_sub)
    e.w32(sub + 0x1c, vt_S)
    eng = _rnd(c, 0x2000)
    e.w32(eng + 0x9b, sub)
    e.w32(eng + 0x40, c.rng.getrandbits(32))
    e.w32(0x70039c, eng)
    T = _rnd(c, 0x40)
    e.w32(T, vt_T)
    self_obj = _rnd(c, 0x300)
    e.w32(self_obj + 0x14e, 0 if c.rng.random() < 0.2 else T)
    e.w32(self_obj + 0x1c4, c.rng.getrandbits(32))
    return [self_obj]


S(0x5d7e00, 'unnamed_5d7e00 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_d7e00,
  note='unclaimed-57 batch 107; S (sub+0x1c) and T fake slots; U slot +0x100; callee 0x5d7bc0 (area 49) hooked, logs')
