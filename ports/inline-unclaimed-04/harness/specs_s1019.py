"""specs_s1019.py - unclaimed-04 batch 20 (docs/20-unclaimed-04.md): two slice-3 functions (GUESS labels).
0x45b170 calls 0x4db7c0 (original code) with ecx = this+8 and one stack argument this+0x18; the callee copies three dwords
from the object at +0x40, +0x44, +0x48. 0x5f3af0 pushes the dword at this and calls the release helper 0x41e2c0 (cdecl),
which the spec hooks with a logging stub (the same as batch 5)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _copy(c):
    o = _rnd(c, 0x100)
    inner = _rnd(c, 0x100)
    c.emu.w32(o + 8, inner)
    return [o]


def _release_setup(c):
    def release41(em, r):
        em.calllog.append(('41e2c0', 0, 0, (em.arg32(0),)))
        em.ret(eax=0, argbytes=0)

    c.emu.hook(0x41e2c0, release41)


def _rel(c):
    o = _rnd(c, 0x100)
    c.emu.w32(o, c.rng.choice([0, c.rng.getrandbits(32)]))
    return [o]


S(0x45b170, 'unknown::copy_from_8_to_18 (unknown) thiscall', 'thiscall', None, ret=None, gen=_copy,
  note='unclaimed-04 batch 20; calls original 0x4db7c0 (claimed elsewhere)')
S(0x5f3af0, 'unknown::release_first_dword (unknown) thiscall', 'thiscall', None, ret=None, gen=_rel,
  setup=_release_setup, note='unclaimed-04 batch 20; release hook 0x41e2c0 (GUESS)')
