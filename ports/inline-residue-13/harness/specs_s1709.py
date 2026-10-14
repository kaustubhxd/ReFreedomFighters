"""specs_s1709.py - residue 13 batch 1709: 0x4d3ad0. CSharedCom::AddValOfType (0x4d2700) is hooked by address with five stack
arguments (thiscall, callee pops 20); the pointer argument is a stack slot and is not recorded; its random eax is returned."""
from pilot import S
from sthelp import rnd, Seq, clear_hooks, HOOKED


def _addval(c, seq, ret):
    rec = c.emu.alloc(4 * 7, 4)

    def h(e, rr):
        sp = e.reg('esp')
        e.w32(rec, e.reg('ecx'))
        for i in (0, 1, 2, 4):                 # arg 3 is a pointer into the stack: not recorded
            e.w32(rec + 4 + 4 * i, e.r32(sp + 4 + 4 * i))
        n = e.r32(seq.addr) + 1
        e.w32(seq.addr, n)
        e.ret(eax=ret, argbytes=20)
    HOOKED.add(0x4d2700)
    c.emu.hook(0x4d2700, h)


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    _addval(c, seq, r.getrandbits(32))
    me = rnd(c, 0x100)
    return [me, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x4d3ad0, 'GUESS FUN_4d3ad0', 'thiscall', None, ret='eax', gen=_gen, note='batch1709; AddValOfType hooked; ret 0xc')
