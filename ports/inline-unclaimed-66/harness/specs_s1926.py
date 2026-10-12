"""specs_s1926.py - unclaimed-66 batch 1926: three GUESS release-global functions (0x50b4b0, 0x510b70, 0x511700), no arguments.

Each global is set to a fake object (70%) or left 0 (30%). The object's vtable +4 is a logging stub with one argument (the callee
pops it). The globals are compared as .data by the checker."""
from pilot import S


def _slot(name, off, nargs):
    def h(e, r):
        args = [e.arg32(k) for k in range(nargs)]
        e.calllog.append((name, off, e.reg('ecx'), tuple(args)))
        e.ret(eax=0, argbytes=4 * nargs)
    return h


def _rel(addr):
    def gen(c):
        if c.rng.random() < 0.7:
            vt = c.emu.fake_vtable('release obj', 0x8 // 4 + 1, slots={
                0x4: _slot('release obj +4 (stub)', 0x4, 1)})
            obj = c.emu.fake_object('release obj', 0x40, vtable=vt)
            c.emu.w32(addr, obj)
        else:
            c.emu.w32(addr, 0)
        return [c.emu.alloc(0x40, 4)]     # thiscall: the function does not read its this
    return gen


S(0x50b4b0, 'GUESS FUN_0050b4b0 (release global 0x7011fc)', 'thiscall', None, ret=None, gen=_rel(0x7011fc),
  note='unclaimed-66 batch 1926; gap band; vtable +4 stubbed')
S(0x510b70, 'GUESS FUN_00510b70 (release global 0x70139c)', 'thiscall', None, ret=None, gen=_rel(0x70139c),
  note='unclaimed-66 batch 1926; gap band; vtable +4 stubbed')
S(0x511700, 'GUESS FUN_00511700 (release global 0x7014b4)', 'thiscall', None, ret=None, gen=_rel(0x7014b4),
  note='unclaimed-66 batch 1926; gap band; vtable +4 stubbed')
