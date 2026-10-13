"""serial_stubs.py - shared harness module for the serialisation functions (save, load, ReadInput and
CopyEventDataBlock). Used by any harness spec that calls ZSaveGame / ZLoadGame / DBREAD code.

What it gives a spec:
- mkobj(c, slots): an object whose vtable holds the given stub addresses (like pilot's _obj).
- rec(c, nargs, ret=0): a thiscall stub that counts its calls and returns ret.
- seqr(c, nargs, rets): a thiscall stub that returns the next value of rets each call (wraps around).
- wr(c, nargs, idx, width, imm): a thiscall stub that writes imm (width 1 or 4) through the pointer argument idx.
- save_obj(c, slots) / load_obj(c, slots): ZSaveGame / ZLoadGame stand-ins. The save side is rec stubs; the load
  side is wr stubs, so a load writes a fixed value into the field the exe asks for.
- patch(c, addr, stub): replace an exe function at addr with a jump to stub (marks the image dirty).
- dbread_patch(c, rets_u32, rets_u16, counts): DBREAD::operator unsigned int (0x4e5e60), operator unsigned short
  (0x4e5e40), REFTAB::Count (0x4cdd40), DBREAD::GetRefTab (0x4e6330) and ZEventBase::GetInput (0x6352f0) patched.
- rm_object(c, ...): the render manager object used by CCheckInside (global 0x70039c, +0x9b object, slot 0x138 gives
  an object whose slot 0x88 writes through its second argument).

Stack layout reminder: for a thiscall stub, arg i is at [esp + 4 + 4*i] on entry (ecx holds this). All stubs here
are thiscall; ret is 4*nargs unless said otherwise.
"""
import struct

P = lambda v: struct.pack('<I', v & 0xffffffff)

# Exe addresses used by the save/load and DBREAD code (PC build).
DBREAD_U32 = 0x4e5e60      # DBREAD::operator unsigned int()
DBREAD_U16 = 0x4e5e40      # DBREAD::operator unsigned short()
DBREAD_GETREFTAB = 0x4e6330  # DBREAD::GetRefTab(REFTAB*)
REFTAB_COUNT = 0x4cdd40    # REFTAB::Count() const
GETINPUT = 0x6352f0        # ZEventBase::GetInput(DBREAD&)
RM_GLOBAL = 0x70039c       # render manager pointer


HEAP_BASE, HEAP_SIZE = 0x20000000, 0x01000000  # pe_emu.py: the heap that stubs are written into


def flush_cache(c):
    """Drops Unicorn's cached translations of the heap and the exe image. A stub or a patch written from the host
    after a translation exists runs stale code, so a mutant of a shared callee can survive in a multi-spec process.
    Call after every host-side write that is code (code() and patch() do)."""
    mu = c.emu.mu
    mu.ctl_remove_cache(HEAP_BASE, HEAP_BASE + HEAP_SIZE)
    mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def code(c, b):
    a = c.emu.alloc(len(b) + 16, 16)
    c.emu.wbytes(a, b)
    flush_cache(c)
    return a


def rec(c, nargs, ret=0, log=True):
    """Counts calls, logs the first argument of each call in a ring of eight dwords, and returns ret. Thiscall with
    nargs stack arguments. The ring lives in the image (heap), so a different argument shows in the memory compare.
    Pass log=False when the argument is a stack address (GetInput, GetRefTab): the exe and the port have different
    stack addresses, so logging it would show a false mismatch."""
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    ring = c.emu.alloc(32, 4)
    c.emu.wbytes(ring, bytes(32))
    b = b'\xa1' + P(cnt) + b'\x83\xe0\x07\xc1\xe0\x02\x05' + P(ring)
    if nargs >= 1 and log:
        b += b'\x8b\x54\x24\x04\x89\x10'      # mov edx, [esp+4]; mov [eax], edx
    b += b'\xb8' + P(ret) + b'\xff\x05' + P(cnt) + b'\xc2' + struct.pack('<H', 4 * nargs)
    return code(c, b)


def seqr(c, nargs, rets):
    """Returns the next value of rets (eax) on each call, wrapping after eight."""
    rets = list(rets)[:8]
    rets = rets + [rets[-1]] * (8 - len(rets))
    tab = c.emu.alloc(32, 4)
    c.emu.wbytes(tab, b''.join(P(v) for v in rets))
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    b = (b'\xa1' + P(cnt) + b'\x83\xe0\x07\x8b\x04\x85' + P(tab) + b'\xff\x05' + P(cnt)
         + b'\xc2' + struct.pack('<H', 4 * nargs))
    return code(c, b)


def wr(c, nargs, idx, width, imm):
    """Writes imm (width 1 or 4 bytes) through pointer argument idx, then returns 0."""
    off = 4 + 4 * idx
    if width == 1:
        store = b'\xc6\x00' + bytes([imm & 0xff])
    else:
        store = b'\xc7\x00' + P(imm)
    b = b'\x8b\x44\x24' + bytes([off]) + store + b'\x31\xc0' + b'\xc2' + struct.pack('<H', 4 * nargs)
    return code(c, b)


def mkobj(c, slots, size=0x40):
    """An object with random bytes whose first dword is a vtable holding slots (offset -> stub address)."""
    o = c.emu.alloc(size, 4)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(size)))
    vt = c.emu.alloc(max(list(slots) + [0]) + 4, 4)
    for off, stub in slots.items():
        c.emu.w32(vt + off, stub)
    c.emu.w32(o, vt)
    return o


def save_obj(c, slots):
    """A ZSaveGame stand-in: slots maps the vtable offset to a stub (use rec)."""
    return mkobj(c, slots)


def load_obj(c, slots):
    """A ZLoadGame stand-in: slots maps the vtable offset to a stub (use wr)."""
    return mkobj(c, slots)


def name_out(c, imm):
    """Writes (name + imm) through the second argument (out pointer): the name argument is observed too."""
    b = b'\x8b\x44\x24\x04' + b'\x05' + P(imm) + b'\x8b\x4c\x24\x08\x89\x01' + b'\x31\xc0' + b'\xc2\x08\x00'
    return code(c, b)


def patch(c, addr, stub):
    c.emu.wbytes(addr, b'\xb8' + P(stub) + b'\xff\xe0')
    c.emu._image_dirty = True
    flush_cache(c)


def dbread_patch(c, rets_u32, rets_u16, counts):
    """Patches the DBREAD operators, GetRefTab, REFTAB::Count and GetInput for one run. rets_u32 and rets_u16 are the
    sequences the two operators return; counts is the sequence REFTAB::Count returns."""
    patch(c, DBREAD_U32, seqr(c, 0, rets_u32))
    patch(c, DBREAD_U16, seqr(c, 0, rets_u16))
    patch(c, REFTAB_COUNT, seqr(c, 0, counts))
    patch(c, DBREAD_GETREFTAB, rec(c, 1, log=False))
    patch(c, GETINPUT, rec(c, 1, log=False))


def rm_object(c, name_out_imm):
    """The render manager for CCheckInside::ReadInput: [RM_GLOBAL] = rm, rm+0x9b = o, o slot 0x138 returns obj,
    obj slot 0x88(name, out) writes name_out_imm through out. Returns obj (for checks)."""
    obj = mkobj(c, {0x88: name_out(c, name_out_imm)})
    o = mkobj(c, {0x138: code(c, b'\xb8' + P(obj) + b'\xc3')})
    rm = c.emu.alloc(0x200, 4)
    c.emu.wbytes(rm, bytes(c.rng.getrandbits(8) for _ in range(0x200)))
    c.emu.w32(rm + 0x9b, o)
    c.emu.w32(RM_GLOBAL, rm)
    c.emu._image_dirty = True
    return obj
