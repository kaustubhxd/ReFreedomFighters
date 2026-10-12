"""specs_s1009.py - unclaimed-04 batch 9 (docs/20-unclaimed-04.md): CMsgForward::Command (0x49efb0, high name).
thiscall, two stack arguments (ret 8): msg (dword; only its low 16 bits are compared) and data (pointer).
The global at 0x70039c points to a manager object P; P+0x9b is the manager M. The forwarder calls M's vtable slot 0x58
with this+0x48, gets a target (or null), and sends msg and data on to the destination (this+0x44) through its vtable slot
0x130 as (target, msg, data), provided the destination is not the target and the filter word (this+0x4c, 0 means any)
is 0 or equals msg's low 16 bits. The forwarder's own flag byte (+4, bit 0) stops it at once.
Stubs (unverified, GUESS: manager lookup and the forwarded-to slot): both are logging vtables. The global is written in
setup (the image is restored between runs)."""
from pilot import S


def _setup(c):
    e = c.emu
    P = e.alloc(0x100, 4)
    # the manager M: slot 0x58 returns a target chosen in the gen step (stored on the emu for this case)
    M_vt = e.logging_vtable('manager', 0x5c // 4 + 1,
                            impl={0x58: lambda em, a: (getattr(em, 'msg_target', 0), None)},
                            argwords={0x58: 1})
    M = e.alloc(0x100, 4)
    e.w32(M, M_vt)
    e.w32(P + 0x9b, M)
    e.w32(0x70039c, P)


def _args(c):
    e = c.emu
    dest_vt = e.logging_vtable('dest', 0x134 // 4 + 1, argwords={0x130: 3})
    dest = e.alloc(0x100, 4)
    e.w32(dest, dest_vt)
    target = e.alloc(0x100, 4)
    e.w32(target, dest_vt)
    choice = c.rng.random()
    e.msg_target = 0 if choice < 0.2 else (dest if choice < 0.35 else target)

    fwd = e.alloc(0x100, 4)
    e.wbytes(fwd, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    flags = c.rng.getrandbits(8)
    e.wbytes(fwd + 4, bytes([flags]))
    # the destination is always set: a null one dereferences null in the exe too, so the spec does not generate it
    e.w32(fwd + 0x44, dest)
    e.w32(fwd + 0x48, c.rng.getrandbits(32))
    msg = c.rng.getrandbits(32)
    filt = c.rng.choice([0, msg & 0xffff, (msg & 0xffff) ^ 1, c.rng.getrandbits(16)])
    e.wbytes(fwd + 0x4c, filt.to_bytes(2, 'little'))
    data = c.rng.getrandbits(32)
    return [fwd, msg, data]


S(0x49efb0, 'CMsgForward::Command (high) thiscall', 'thiscall', None, ret='eax', gen=_args, setup=_setup,
  note='unclaimed-04 batch 9; manager slot 0x58 and destination slot 0x130 are logging stubs (GUESS)')
