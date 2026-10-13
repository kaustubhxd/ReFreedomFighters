"""specs_s2753.py - unclaimed-27 batch 53: Virtual call function 0x465a60 (GUESS name).
Loads member at +0x1ce, calls its virtual slot +0xc, returns 1."""
from pilot import S


def _gen(c):
    # Create a virtual method stub for slot +0xc
    vt = c.emu.alloc(0x200, 4)

    # Create a simple stub for slot +0xc (thiscall, no args)
    stub_code = b'\xc3'  # ret
    stub_addr = c.emu.alloc(len(stub_code) + 16, 16)
    c.emu.wbytes(stub_addr, stub_code)

    # Set the stub at vtable[+0xc]
    c.emu.w32(vt + 0xc, stub_addr)

    # Create member object with vtable
    member = c.emu.alloc(0x100, 16)
    c.emu.w32(member, vt)
    c.emu.wbytes(member, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    c.emu.w32(member, vt)  # Restore vtable after random fill

    # Create main object with member at +0x1ce
    obj = c.emu.alloc(0x200, 16)
    c.emu.wbytes(obj, bytes(c.rng.getrandbits(8) for _ in range(0x200)))
    c.emu.w32(obj + 0x1ce, member)

    c.emu.mu.ctl_flush_tb()
    return [obj, c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x465a60, 'FUN_VirtualCallSetOne (GUESS) thiscall', 'thiscall', None, ret='al', gen=_gen,
  note='unclaimed-27 batch 53; virtual method call returning 1')
