"""specs_s1043.py - unclaimed-04 batch 43 (docs/20-unclaimed-04.md): 0x6128b0 (thiscall, no arguments, plain ret).
0x634cf2 (stdcall, two arguments: the value at this+4, then &out) is hooked by address: it writes the case's out value and
returns the case's r. 0x634ce0 (stdcall, one argument = 0x10) is hooked: it returns a fresh zeroed block, or 0 in some cases."""
from pilot import S


def _setup(c):
    out_val = c.rng.choice([0, 0x1234, c.rng.getrandbits(32)])
    r_val = c.rng.choice([0, 0, c.rng.getrandbits(32)])
    alloc_null = c.rng.random() < 0.2

    def h634cf2(em, r):
        em.calllog.append(('634cf2', 0, 0, (em.arg32(0),)))
        em.w32(em.arg32(1), out_val)
        em.ret(eax=r_val, argbytes=8)

    def h634ce0(em, r):
        size = em.arg32(0)
        em.calllog.append(('634ce0', 0, 0, (size,)))
        if alloc_null:
            em.ret(eax=0, argbytes=4)
            return
        p = em.alloc(max(size, 4), 4)
        em.wbytes(p, bytes(max(size, 4)))
        em.ret(eax=p, argbytes=4)

    c.emu.hook(0x634cf2, h634cf2)
    c.emu.hook(0x634ce0, h634ce0)


def _args(c):
    o = c.emu.alloc(0x100, 4)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    return [o]


S(0x6128b0, 'unknown::query_then_record (unknown) thiscall', 'thiscall', None, ret=None, gen=_args, setup=_setup,
  note='unclaimed-04 batch 43; 0x634cf2 and 0x634ce0 hooked by address (GUESS)')
