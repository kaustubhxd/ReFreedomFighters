"""specs_s1979.py - slice-5 batch 112 (GUESS name): 0x500190

THISCALL(this, arg), ret 4: calls vtable slot 0x2c of arg with array size,
then iterates through array at [this..[this+4]), calling 0x5f95a0(element, arg) for each.

0x5f95a0 is a GUESS stub hooked by address: visitor function called for each array element.
arg has a vtable with slot 0x2c."""
from pilot import S


def _gen(c):
    # Create an array with random elements
    num_elements = c.rng.randint(1, 10)
    array_ptr = c.emu.alloc(num_elements * 4, 4)

    # Fill array with random element pointers
    elements = []
    for i in range(num_elements):
        elem = c.emu.alloc(0x20, 4)
        c.emu.wbytes(elem, bytes(c.rng.getrandbits(8) for _ in range(0x20)))
        elements.append(elem)
        c.emu.w32(array_ptr + i * 4, elem)

    # Hook 0x5f95a0 visitor function (thiscall with element in ECX, arg on stack)
    def h5f95a0(e, r):
        element = e.reg('ecx')
        arg = e.arg32(0)
        e.calllog.append(('0x5f95a0 (visitor)', 0x5f95a0, 0, (element, arg)))
        e.ret(eax=0, argbytes=4)
    c.emu.hook(0x5f95a0, h5f95a0)

    # Create arg object with vtable
    def hslot2c(e, r):
        size = e.arg32(0)
        e.calllog.append(('arg vtable +0x2c (stub)', 0x2c, e.reg('ecx'), (size,)))
        e.ret(eax=0, argbytes=4)

    vt = c.emu.fake_vtable('batch112 arg', 0x2c // 4 + 1, slots={0x2c: hslot2c})
    arg = c.emu.fake_object('batch112 arg', 0x40, vtable=vt)

    # Create this object with array pointers
    this = c.emu.alloc(8, 4)
    c.emu.w32(this, array_ptr)
    c.emu.w32(this + 4, array_ptr + num_elements * 4)

    return [this, arg]


S(0x500190, 'GUESS FUN_00500190 (array iterator with visitor)', 'thiscall', None, ret=None,
  gen=_gen, note='slice-5 batch 1979 (112); 0x5f95a0 visitor stub; arg vtable slot 0x2c stubbed')
