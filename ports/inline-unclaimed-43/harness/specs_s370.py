"""specs_s370.py - gap band batch 370: 0x41f650, thiscall, no arguments. A three-node chain (each node's first dword is the next
node, the last is 0). The object's slot 0x10 takes p+0x20 and sets this+0x18 to the first dword of node p = arg-0x20, so the
loop walks the chain three times. The mock is stateless (the next value depends only on the argument), so the original and the
port see the same walk."""
from pilot import S
import engine_stubs as E


def _gen(c):
    n0 = E.zero_obj(c, 0x40)
    n1 = E.zero_obj(c, 0x40)
    n2 = E.zero_obj(c, 0x40)
    c.emu.w32(n0, n1)
    c.emu.w32(n1, n2)
    c.emu.w32(n2, 0)
    slots = {}
    for i in range(0x10 // 4 + 1):
        off = 4 * i

        def h(e, rr, off=off):
            args = [e.arg32(0)] if off == 0x10 else []
            e.calllog.append(('ZWALK', off, e.reg('ecx'), tuple(args)))
            if off == 0x10:
                node = (args[0] - 0x20) & 0xffffffff
                e.w32(e.reg('ecx') + 0x18, e.r32(node))
            e.ret(eax=0, argbytes=4 if off == 0x10 else 0)
        slots[off] = h
    obj = E.zero_obj(c, 0x40)
    c.emu.w32(obj, c.emu.fake_vtable('ZWALK', 0x10 // 4 + 1, slots))
    c.emu.w32(obj + 0x18, n0)
    c.emu.mu.ctl_flush_tb()
    return [obj]


S(0x41f650, 'walk list via slot 0x10 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='gap band batch 370')
