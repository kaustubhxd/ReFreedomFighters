"""specs_s1981.py - slice-5 batch 117 (GUESS name): 0x493090
CDECL(array_arg), ret 4: sys+0x9b vtable checks and array iteration."""
from pilot import S

def _gen(c):
    def hvt_2c(e, r):
        e.calllog.append(('sys_child +0x2c', 0x2c, e.reg('ecx'), ()))
        e.ret(eax=0, argbytes=0)
    def hvt_54(e, r):
        e.calllog.append(('sys_child +0x54', 0x54, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=c.emu.alloc(0x40, 4), argbytes=4)
    def h4dbe30(e, r):
        e.calllog.append(('0x4dbe30', 0x4dbe30, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=0, argbytes=4)

    sys_vt = c.emu.fake_vtable('batch117', 0x54//4+1, slots={0x2c: hvt_2c, 0x54: hvt_54})
    sys_obj = c.emu.fake_object('batch117', 0x100, vtable=sys_vt)
    c.emu.w32(0x70039c, sys_obj)
    c.emu.hook(0x4dbe30, h4dbe30)

    array = c.emu.alloc(0x20, 4)
    c.emu.w32(array, 1)
    c.emu.w32(array+4, c.emu.alloc(0x40, 4))
    return [array]

S(0x493090, 'GUESS FUN_00493090', 'cdecl', None, ret=None, gen=_gen, note='batch1981: cdecl ret 4 test')
