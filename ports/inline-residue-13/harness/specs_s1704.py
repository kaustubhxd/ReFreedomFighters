"""specs_s1704.py - residue 13 batch 1704: 0x476a60. The callees are hooked by address (CopyDataBlock 0x43f900, DBLK::Get 0x4e11e0,
0x4e11d0 (the thunk, hooked as a whole), 0x4e12e0 (writes its output word, a stack pointer or this+0x73), DBLK::GetType 0x4e1600
(two random types), DBLK::NextBlock 0x4e1b30). The stack-pointer output is followed through the hook so the value is compared."""
from pilot import S
from sthelp import rnd, Seq, clear_hooks, hook, HOOKED


def _get2(c):
    rec = c.emu.alloc(12, 4)

    def h(e, r):
        sp = e.reg('esp')
        out = e.r32(sp + 4)
        e.w32(out, e.r32(out) ^ 0x5a5a5a5a)      # a value the port must reproduce through its own read
        e.w32(rec + 4, e.r32(sp + 8))   # arg 0 is a stack pointer: not recorded
        e.ret(eax=0, argbytes=8)
    HOOKED.add(0x4e12e0)
    c.emu.hook(0x4e12e0, h)


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    hook(c, seq, 0x43f900, 1, ret=0, this=True, pop=True)
    for addr in (0x4e11e0, 0x4e11d0):
        hook(c, seq, addr, 2, ret=0, this=True, pop=True)
    _get2(c)
    types = [r.choice([3, 8, 1, 0]), r.choice([8, 3, 0])]
    cnt = c.emu.alloc(4, 4)

    def gt(e, rr):
        i = e.r32(cnt)
        e.w32(cnt, i + 1)
        e.ret(eax=types[i % 2], argbytes=0)
    HOOKED.add(0x4e1600)
    c.emu.hook(0x4e1600, gt)
    hook(c, seq, 0x4e1b30, 0, ret=r.getrandbits(32), this=True, pop=True)
    me = rnd(c, 0x100)
    src = rnd(c, 0x80)
    return [me, src]


S(0x476a60, 'GUESS FUN_476a60', 'thiscall', None, ret='eax', gen=_gen, note='batch1704; DBLK callees hooked; thunk 0x4e11d0 hooked as a whole')
