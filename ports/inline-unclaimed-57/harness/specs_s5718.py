"""specs_s5718.py - unclaimed-57, batch 18: 0x4f1100 (GUESS). Thiscall, one stack argument (a pointer), ret 4. Nine-dword comparison
against this+8's block; on a mismatch the mismatch handler 0x45fc70 (thiscall, one argument) is hooked and logged, and byte +0x90 is
set. The arrays are equal in half the cases, otherwise one dword of a differs (at a random index), so both paths run."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _cmp9(c):
    def mism(em, r):
        em.calllog.append(('45fc70', 0, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)
    c.emu.hook(0x45fc70, mism)
    p = _rnd(c, 0x40)
    q = _rnd(c, 0x40)
    words = [c.rng.getrandbits(32) for _ in range(9)]
    for k, w in enumerate(words):
        c.emu.w32(p + 4 * k, w)
        c.emu.w32(q + 4 * k, w)
    if c.rng.random() < 0.5:
        k = c.rng.randrange(9)
        c.emu.w32(p + 4 * k, (words[k] ^ 0x10000) & 0xffffffff)
    obj = _rnd(c, 0x200)
    c.emu.w32(obj + 8, q)
    c.emu.wbytes(obj + 0x90, bytes([0]))
    return [obj, p]


S(0x4f1100, 'unnamed_4f1100 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_cmp9,
  note='unclaimed-57 batch 18; nine-dword compare; mismatch handler 0x45fc70 hooked and logged')
