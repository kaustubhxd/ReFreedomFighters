"""specs_s1982.py - 0x438f50 ZInputActions::GetActiveActions(REFTAB*)
THISCALL(this, reftab), ret 4: nested list iteration with iterator protocol."""
from pilot import S
from iter66 import make_list

def _gen(c):
    def h437d60(e, r):
        e.calllog.append(('0x437d60', 0x437d60, e.reg('ecx'), ()))
        e.ret(eax=1, argbytes=0)

    def h438150(e, r):
        e.calllog.append(('0x438150', 0x438150, e.reg('ecx'), ()))
        e.ret(eax=1, argbytes=0)

    # Create nested list structure:
    # - list1 with 1 element
    # - that element has list2 with 1 element at +0x19

    # Inner element for list2 - allocate first (to get lower address)
    inner1 = c.emu.alloc(0x30, 4)

    # Outer element for list1 (has list2 at +0x19)
    outer1 = c.emu.alloc(0x40, 4)

    # list2 containing single inner element
    list2 = make_list(c, [inner1])

    # Set up outer element's nested list
    c.emu.w32(outer1 + 0x19, list2)

    # list1 containing single outer element
    list1 = make_list(c, [outer1])

    # Create this object with list1 at +0x1214
    this = c.emu.alloc(0x1220, 4)
    c.emu.w32(this + 0x1214, list1)

    # Hook the action helpers
    c.emu.hook(0x437d60, h437d60)
    c.emu.hook(0x438150, h438150)

    return [this, c.emu.alloc(0x20, 4)]  # reftab is unused

S(0x438f50, 'ZInputActions::GetActiveActions', 'thiscall', None, ret=None,
  gen=_gen, note='batch1982: nested iterator protocol')
