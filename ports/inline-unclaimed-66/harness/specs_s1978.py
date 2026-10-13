"""specs_s1978.py - slice-5 batch 111 (GUESS name): 0x4d50d0

THISCALL(this, p), ret 4: if p == this+4, free [this+4] via 0x634273 (cdecl, hooked) when non-null,
clear +8/+0xc, return 0; else call [0x7003b0] (function pointer stubbed) and return -1.

0x634273 is the CRT free function, hooked by address.
0x7003b0 is a global function pointer, stubbed with c.emu.stub_fn."""
from pilot import S


def _gen(c):
    # Path selection: 50% p == this+4, 50% p != this+4
    use_equal = c.rng.random() < 0.5

    # Hook CRT free 0x634273
    def h634273(e, r):
        ptr = e.arg32(0)
        size = e.arg32(1)
        e.calllog.append(('0x634273 (CRT free)', 0x634273, 0, (ptr, size)))
        e.ret(eax=0, argbytes=8)
    c.emu.hook(0x634273, h634273)

    # Create the object
    this = c.emu.alloc(0x40, 4)
    c.emu.wbytes(this, bytes(c.rng.getrandbits(8) for _ in range(0x40)))

    if use_equal:
        # p == this+4: set up pointer at this+4
        p = this + 4
        # Set [this+4] to be non-null 70% of the time
        if c.rng.random() < 0.7:
            ptr_to_free = c.emu.alloc(0x40, 4)
            c.emu.w32(this + 4, ptr_to_free)
        else:
            c.emu.w32(this + 4, 0)
    else:
        # p != this+4: use a different pointer
        p = c.emu.alloc(0x40, 4)
        # Set up the function pointer at 0x7003b0
        # Use stub_fn which logs the call but takes no arguments
        def hstub(e, r):
            e.calllog.append(('0x7003b0 (stub_fn)', 0x7003b0, 0, ()))
            e.ret(eax=0, argbytes=0)
        stub_addr = c.emu.stub_fn('0x7003b0 (stub_fn)', hstub)
        c.emu.w32(0x7003b0, stub_addr)

    return [this, p]


S(0x4d50d0, 'GUESS FUN_004d50d0 (pointer equal/free path)', 'thiscall', None, ret=None,
  gen=_gen, note='slice-5 batch 1978 (111); 0x634273 CRT free hooked; 0x7003b0 function pointer stubbed')
