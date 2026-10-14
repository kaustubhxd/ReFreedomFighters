"""specs_s1703.py - residue 13 batch 1703: 0x47fea0. The three ZBaseGeom callees (0x4dd060, 0x4dce50, 0x4dc600) are hooked by
address (one argument each; the two pointer arguments point at the stack and are not recorded; the float argument is recorded
as bits). The object at +8 is a random pointer."""
from pilot import S
from sthelp import rnd, Seq, clear_hooks, hook, HOOKED


def _rec(c, addr, nargs, skip, deref=0):
    """Records ecx and the arguments; a pointer argument that is not in `skip` is followed for `deref` dwords (the stack
    buffer's contents), so the vectors the port passes are compared, not only their addresses."""
    rec = c.emu.alloc(4 * (nargs + 1) + 4 * deref, 4)

    def h(e, r):
        sp = e.reg('esp')
        e.w32(rec, e.reg('ecx'))
        for i in range(nargs):
            if i not in skip:
                e.w32(rec + 4 + 4 * i, e.r32(sp + 4 + 4 * i))
        if deref:
            ptr = e.r32(sp + 4)
            for k in range(deref):
                e.w32(rec + 4 * (nargs + 1) + 4 * k, e.r32(ptr + 4 * k))
        e.ret(eax=0, argbytes=4 * nargs)
    HOOKED.add(addr)
    c.emu.hook(addr, h)


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    _rec(c, 0x4dd060, 1, skip=(0,), deref=3)
    _rec(c, 0x4dce50, 1, skip=())
    _rec(c, 0x4dc600, 1, skip=(0,), deref=3)
    me = rnd(c, 0x80)
    c.emu.w32(me + 8, rnd(c, 0x40))
    c.emu.wf32(me + 0x1c, r.uniform(-50, 50))
    return [me]


S(0x47fea0, 'GUESS FUN_47fea0', 'thiscall', None, ret=None, gen=_gen, note='batch1703; ZBaseGeom callees hooked by address')
